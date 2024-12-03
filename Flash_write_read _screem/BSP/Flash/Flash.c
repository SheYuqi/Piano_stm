#include "Flash.h"

// SPI 句柄
extern SPI_HandleTypeDef hspi1;

extern UART_HandleTypeDef huart1;


uint8_t buffer[BUF_SIZE];
uint32_t flash_write_address = FLASH_BASE_ADDRESS;  // 起始写入地址
uint8_t file_id = 0xFF;  // 当前文件标识符

// Flash 片选引脚
#define FLASH_CS_PIN GPIO_PIN_0
#define FLASH_CS_PORT GPIOB

MidiFileHeader midiHeaders[MAX_MIDI_FILES];
MidiFileHeader midiHeader;


// 初始化 MIDI 文件头区域
void InitMidiHeaders(void)
{
    Flash_ReadData(FLASH_START_ADDRESS, (uint8_t *)midiHeaders, FILE_HEADER_AREA_SIZE);
}

// 在 Flash 中查找可用的存储空间
uint32_t FindFreeFlashAddress(uint32_t fileSize)
{
    uint32_t currentAddress = FILE_DATA_START_ADDRESS;
    for (int i = 0; i < MAX_MIDI_FILES; i++)
    {
        if (midiHeaders[i].fileSize != 0)  // 如果文件存在
        {
            currentAddress = midiHeaders[i].fileAddress + midiHeaders[i].fileSize;
        }
    }
    return currentAddress;
}

// 将 MIDI 文件头信息写入 Flash
void WriteMidiHeader(MidiFileHeader *header, int index)
{
    uint32_t address = FLASH_START_ADDRESS + index * FILE_HEADER_SIZE;
    Flash_PageProgram(address, (uint8_t *)header, FILE_HEADER_SIZE);
}

// 接收 MIDI 文件数据并写入 Flash
void ParseReceivedData(uint8_t* buf) {
    uint8_t msg_type = buf[2];  // note_on or note_off
    uint8_t channel = buf[3];
    uint8_t note = buf[4];
    uint8_t velocity = buf[5];
    uint16_t real_time = buf[6] | (buf[7] << 8);
    uint8_t received_file_id = buf[8];  // 文件标识符
	

    // 根据 file_id 判断是否需要切换存储地址
    /*if (received_file_id != file_id) {
        file_id = received_file_id;
        flash_write_address = FLASH_BASE_ADDRESS + (file_id * 0x10000);  // 每个文件偏移1区块
    }*/
		
    // 打包 MIDI 数据并写入 Flash
    uint8_t midi_data[6] = {msg_type, channel, note, velocity, (uint8_t)(real_time & 0xFF), (uint8_t)((real_time >> 8) & 0xFF)};
    Flash_PageProgram(flash_write_address, midi_data, sizeof(midi_data));
    flash_write_address += sizeof(midi_data);  // 更新 Flash 写入地址

    // 确认数据写入完毕，通过串口返回结果
    uint8_t response[10] = {0x2D, 0x01, msg_type, channel, note, velocity, (uint8_t)(real_time & 0xFF), (uint8_t)((real_time >> 8) & 0xFF), 0x0D, 0x0A};
    HAL_UART_Transmit(&huart1, response, sizeof(response), HAL_MAX_DELAY);
}


uint32_t FindFileByName(const char* targetFileName) {
    uint32_t currentAddr = FLASH_START_ADDRESS;
    while (currentAddr < FLASH_END_ADDRESS) { 
			  Flash_ReadData(currentAddr,(uint8_t *)&midiHeader, sizeof(midiHeader));

        // 如果文件名为空字符，表示到达空闲区域
        if (midiHeader.fileName[0] == '\0') {
            return 0x000FFF;  // 没有找到
        }
        // 检查文件名是否匹配
        if (strcmp(midiHeader.fileName, targetFileName) == 0) {
            return midiHeader.fileAddress;  // 返回找到的文件地址
        }

        // 移动到下一个文件头
        currentAddr += (sizeof(midiHeader)+5);
    }
    return 0xFFFFFFFF;  // 未找到
}



void ReceiveAndStoreMidiFile(const char *fileName)
{
    //uint8_t midiBuffer[1024];  // 假设每次接收 1KB 数据
    uint32_t receivedSize = 0;

    // 查找空闲的文件头位置
    int freeIndex = -1;
    for (int i = 0; i < MAX_MIDI_FILES; i++)
    {
        if (midiHeaders[i].fileSize == 0)
        {
            freeIndex = i;
            break;
        }
    }
    if (freeIndex == -1)
    {
        //printf("Flash is full, cannot store more MIDI files.\n");
        return;
    }
		receivedSize=sizeof(fileName);

    // 查找空闲的 Flash 存储空间
    //flash_write_address = FindFreeFlashAddress(receivedSize);
    //printf("Start receiving MIDI file: %s\n", fileName);

    // 假设我们通过 UART 接收 MIDI 数据，直到结束

    // 保存文件头信息
    strncpy(midiHeaders[freeIndex].fileName, fileName, sizeof(midiHeaders[freeIndex].fileName) - 1);
    midiHeaders[freeIndex].fileSize = receivedSize;
    midiHeaders[freeIndex].fileAddress = flash_write_address;
		flash_write_address +=receivedSize;
    WriteMidiHeader(&midiHeaders[freeIndex], freeIndex);

    //printf("MIDI file %s stored successfully, size: %lu bytes\n", fileName, receivedSize);
}

uint8_t Flash_ReadDeviceID(void)
{
    uint8_t cmd = W25Q16_READ_DEVICE_ID;
    uint8_t id[3] = {0};

    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_RESET);  // 拉低片选信号
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);       // 发送读取ID命令
    HAL_SPI_Receive(&hspi1, id, 3, HAL_MAX_DELAY);          // 接收3字节ID
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_SET);    // 拉高片选信号

    return id[0];  // 返回制造商ID
}

void Flash_WriteEnable(void)
{
    uint8_t cmd = W25Q16_WRITE_ENABLE;
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_RESET);  // 选择 W25Q16
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);       // 发送写使能命令
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_SET);    // 取消选择 W25Q16
}

void Flash_WriteDisable(void)
{
    uint8_t cmd = W25Q16_WRITE_DISABLE;
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_RESET);  // 选择 W25Q16
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);       // 发送写禁用命令
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_SET);    // 取消选择 W25Q16
}

void Flash_ReadData(uint32_t address, uint8_t *buffer, uint16_t size)
{
    uint8_t cmd[4];
    cmd[0] = W25Q16_READ_DATA;
    cmd[1] = (address >> 16) & 0xFF;
    cmd[2] = (address >> 8) & 0xFF;
    cmd[3] = address & 0xFF;

    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_RESET);  // 选择 W25Q16
    HAL_SPI_Transmit(&hspi1, cmd, 4, HAL_MAX_DELAY);        // 发送命令和地址
    HAL_SPI_Receive(&hspi1, buffer, size, HAL_MAX_DELAY);   // 接收数据
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_SET);    // 取消选择 W25Q16
}

void Flash_PageProgram(uint32_t address, uint8_t *buffer, uint16_t size)
{
    uint8_t cmd[4];
    Flash_WriteEnable();  // 使能写操作

    cmd[0] = W25Q16_PAGE_PROGRAM;
    cmd[1] = (address >> 16) & 0xFF;
    cmd[2] = (address >> 8) & 0xFF;
    cmd[3] = address & 0xFF;

    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_RESET);  // 选择 W25Q16
    HAL_SPI_Transmit(&hspi1, cmd, 4, HAL_MAX_DELAY);        // 发送命令和地址
    HAL_SPI_Transmit(&hspi1, buffer, size, HAL_MAX_DELAY);  // 发送数据
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_SET);    // 取消选择 W25Q16
}

void Flash_SectorErase(uint32_t address)
{
    uint8_t cmd[4];
    Flash_WriteEnable();  // 使能写操作

    cmd[0] = W25Q16_SECTOR_ERASE;
    cmd[1] = (address >> 16) & 0xFF;
    cmd[2] = (address >> 8) & 0xFF;
    cmd[3] = address & 0xFF;

    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_RESET);  // 选择 W25Q16
    HAL_SPI_Transmit(&hspi1, cmd, 4, HAL_MAX_DELAY);        // 发送命令和地址
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_SET);    // 取消选择 W25Q16
}

uint8_t Flash_ReadStatusRegister(void)
{
    uint8_t cmd = W25Q16_READ_STATUS_REG;
    uint8_t status = 0;

    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_RESET);  // 选择 W25Q16
    HAL_SPI_Transmit(&hspi1, &cmd, 1, HAL_MAX_DELAY);       // 发送命令
    HAL_SPI_Receive(&hspi1, &status, 1, HAL_MAX_DELAY);     // 读取状态寄存器
    HAL_GPIO_WritePin(FLASH_CS_PORT, FLASH_CS_PIN, GPIO_PIN_SET);    // 取消选择 W25Q16

    return status;
}
