#ifndef __FLASH_H
#define __FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>

// W25Q16 指令定义
#define W25Q16_WRITE_ENABLE        0x06
#define W25Q16_WRITE_DISABLE       0x04
#define W25Q16_READ_DATA           0x03
#define W25Q16_PAGE_PROGRAM        0x02
#define W25Q16_SECTOR_ERASE        0x20
#define W25Q16_CHIP_ERASE          0xC7
#define W25Q16_READ_STATUS_REG     0x05
#define W25Q16_READ_DEVICE_ID      0x9F
#define W25Q16_BLOCK_ERASE         0x52

// FLASH 相关定义
#define MAX_MIDI_FILES 128  // 假设最多存储 128 个文件
#define FLASH_START_ADDRESS 0x000001  // 假设我们使用从这个地址开始的 Flash 区域
#define FILE_HEADER_SIZE (sizeof(MidiFileHeader)+5)
#define FILE_HEADER_AREA_SIZE (MAX_MIDI_FILES * FILE_HEADER_SIZE)  // 文件头区域大小
#define FILE_DATA_START_ADDRESS (FLASH_START_ADDRESS + FILE_HEADER_AREA_SIZE)  // 数据开始的地址

#define BUF_SIZE 10
#define FLASH_BASE_ADDRESS 0x001000  // 设定从第二扇开始写midi
#define FLASH_MIDI_ADDRESS 0x009000
#define PAGE_SIZE 256

//三个地方需要改：1、FLASH_BASE_ADDRESS*2 2、index需要改 3、需要设定好擦除
typedef struct {
    char fileName[32];  // MIDI 文件名，最大15字符
    uint32_t fileSize;  // MIDI 文件大小
    uint32_t fileAddress;  // 文件存储在 Flash 的起始地址
} MidiFileHeader;

// 函数声明
//void Flash_Init(void);
void ParseReceivedData(uint8_t* buf);
void WriteMidiHeader(MidiFileHeader *header, int index);

uint8_t Flash_ReadDeviceID(void);
void Flash_WriteEnable(void);
void Flash_WriteDisable(void);
void Flash_ReadData(uint32_t address, uint8_t *buffer, uint16_t size);
void Flash_PageProgram(uint32_t address, uint8_t *buffer, uint16_t size);
void Flash_Block_Erase(uint32_t address);
void Flash_Sector_Erase(uint32_t address);
void Flash_Chip_Erase(uint32_t address);
uint8_t Flash_ReadStatusRegister(void);

#ifdef __cplusplus
}
#endif

#endif /* __FLASH_H */
