#include "Key.h"

MidiFileHeader fileHeaders[MAX_MIDI_FILES]; // 用于存储文件头信息的数组
extern  MidiFileHeader midiHeader;
uint8_t midi_buf[6] = {0};
extern uint8_t flag_data;
extern uint32_t flash_write_address ;  // 起始写入地址
int fileCount = 0;                 // 文件头数量

//从Flash中读取头文件
void LoadFileHeaders(void) {
    for (int i = 0; i < MAX_MIDI_FILES; i++) {
        // 从 Flash 的指定地址读取文件头
        uint32_t address = FLASH_BASE_ADDRESS + i * FILE_HEADER_SIZE;
        Flash_ReadData(address, (uint8_t*)&fileHeaders[i], FILE_HEADER_SIZE);
				//ST7735_DrawString(10, 50+10*i, "Playing:222",ST7735_WHITE,ST7735_BLACK, &Font_7x10);
        
        // 检查文件名是否有效
        if (fileHeaders[i].fileName[0] != '\0'&& fileHeaders[i].fileName[0] != (char)0xFF) {
            fileCount++;
        } else {
            break;
        }
    }
}

void DisplayFileHeaders(int selected) {

    for (int i = 0; i < fileCount; i++) {
        // 设置字体颜色，选中项为红色
        //ST7735_SetTextColor(i == selected ? RED : WHITE);
        ST7735_DrawString(10, 10 + i * 20,fileHeaders[i].fileName,i == selected ? ST7735_RED : ST7735_WHITE,ST7735_BLACK, &Font_7x10);
    }
}

// 主菜单选择功能，通过按键切换不同的曲目
void FileSelect_Menu(void) {
    int selected = 0; // 当前选中的文件头
    DisplayFileHeaders(selected);

    while (1) {
        // 读取按键状态
        if (HAL_GPIO_ReadPin(K1_GPIO_Port, K1_Pin) == GPIO_PIN_RESET) { // 向上选择
						selected = (selected - 1 + fileCount) % fileCount;
            DisplayFileHeaders(selected);
            HAL_Delay(200); // 消抖延迟
        }
        
        if (HAL_GPIO_ReadPin(K2_GPIO_Port, K2_Pin) == GPIO_PIN_RESET) { // 向下选择
            selected = (selected + 1) % fileCount;
            DisplayFileHeaders(selected);
            HAL_Delay(200);
        }

        if (HAL_GPIO_ReadPin(K3_GPIO_Port, K3_Pin) == GPIO_PIN_RESET) { // 选中文件头
            // 加载选中曲目的详细信息或开始播放
            ST7735_FillScreen(ST7735_BLACK);				
            ST7735_DrawString(10, 50, "Playing:",ST7735_WHITE,ST7735_BLACK, &Font_7x10);
            ST7735_DrawString(10, 60, fileHeaders[selected].fileName,ST7735_WHITE,ST7735_BLACK, &Font_7x10);
            HAL_Delay(200);
						uint32_t flash_address = FLASH_BASE_ADDRESS;
						flash_address=fileHeaders[selected].fileAddress;
						while(1){
							if (midi_buf[0] == 0xFF && midi_buf[1] == 0xFF && midi_buf[2] == 0xFF&&midi_buf[3] == 0x00&&midi_buf[4] == 0x00&&midi_buf[5] == 0x00) {
								char buffer0[32];
								sprintf(buffer0, "flash_adress:%d\n",flash_address);
								ST7735_DrawString(10, 80, buffer0,ST7735_WHITE,ST7735_BLACK, &Font_7x10);
								break;  // 满足条件，跳出循环  13967
							}
							if (midi_buf[0] == 0xFF && midi_buf[1] == 0xFF && midi_buf[2] == 0xFF&&midi_buf[3] == 0xFF&&midi_buf[4] == 0xFF&&midi_buf[5] == 0xFF)
							{
								flash_address +=sizeof(midi_buf);
								continue;
							}
		
							Flash_ReadData(flash_address, midi_buf, sizeof(midi_buf));
							processReceivedData();
							flash_address +=sizeof(midi_buf);
							
							char buffer0[32];
								sprintf(buffer0, "flash_adress:%d\n",flash_address);
								ST7735_DrawString(10, 80, buffer0,ST7735_WHITE,ST7735_BLACK, &Font_7x10);
							
						}
						/*
						uint8_t dataRead[3000];
						uint32_t flash_adress = FLASH_BASE_ADDRESS;
						flash_adress=fileHeaders[selected].fileAddress;//Counter-attack    The-Swan
						Flash_ReadData(flash_adress, dataRead, sizeof(dataRead));
						
						char buffer0[32];
						sprintf(buffer0, "flash_adress：%d\n",flash_adress);
						PrintToUART(buffer0);
						
						sprintf(buffer0, " fileSize：%d\n",fileHeaders[selected].fileSize);
						PrintToUART(buffer0);
						PrintToUART("Data read from Flash:\n");
						PrintToUART(fileHeaders[selected].fileName);
						PrintToUART("Data read from Flash:\n");
						
						// 打印读取的数据
						char buffer[50];
						for(int i=0;i<500;i++){
							for(int j=0;j<6;j++)
							{
								sprintf(buffer, " %d\n",dataRead[6*i+j]);
								PrintToUART(buffer);
							}
						}
						flash_adress+=sizeof(dataRead);
						HAL_Delay(10);
							//HAL_UART_Transmit(&huart1,dataRead,6,1);
						Flash_ReadData(flash_adress, dataRead, sizeof(dataRead));
						for(int i=0;i<500;i++){
							for(int j=0;j<6;j++)
							{
								sprintf(buffer, " %d\n",dataRead[6*i+j]);
								PrintToUART(buffer);
							}
						}
						flash_adress+=sizeof(dataRead);
						HAL_Delay(10);
							//HAL_UART_Transmit(&huart1,dataRead,6,1);
						Flash_ReadData(flash_adress, dataRead, sizeof(dataRead));
						for(int i=0;i<500;i++){
							for(int j=0;j<6;j++)
							{
								sprintf(buffer, " %d\n",dataRead[6*i+j]);
								PrintToUART(buffer);
							}
						}*/
						
        }

        if (HAL_GPIO_ReadPin(K4_GPIO_Port, K4_Pin) == GPIO_PIN_RESET) { // 返回操作
            break; // 返回上一级菜单或退出
            HAL_Delay(200);
        }
    }
}

/*// 菜单项函数定义
void MenuAction1() {
    // 菜单项1的功能
    ST7735_DrawString(10, 50, "Selected Menu Item 1");
}

void MenuAction2() {
    // 菜单项2的功能
    ST7735_DrawString(10, 50, "Selected Menu Item 2");
}

// 定义菜单项
MenuItem menu[] = {
    {"Menu Item 1", MenuAction1},
    {"Menu Item 2", MenuAction2},
    {"Menu Item 3", NULL}, // 没有对应的功能
    {"Menu Item 4", NULL}
};

#define MENU_LENGTH (sizeof(menu) / sizeof(menu[0]))
	

// 显示菜单函数
void DisplayMenu(int selected) {
    ST7735_FillScreen(ST7735_BLACK); // 清屏
    for (int i = 0; i < MENU_LENGTH; i++) {
        // 根据选中的项改变字体颜色
        if (i == selected) {
            ST7735_SetTextColor(ST7735_RED); // 选中项为红色
        } else {
            ST7735_SetTextColor(ST7735_WHITE); // 其他项为白色
        }
        ST7735_DrawString(10, 10 + (i * 10), menu[i].title); // 假设每个项间隔10个像素
    }
}

// 主菜单选择函数
void Key_Menu_Select() {
    static int selected = 0; // 记录当前选中的菜单项
    DisplayMenu(selected); // 显示菜单

    while (1) {
        // 读取按键状态
        if (HAL_GPIO_ReadPin(K1_GPIO_Port, K1_Pin) == GPIO_PIN_RESET) { // 按下KEY1
            selected = (selected - 1 + MENU_LENGTH) % MENU_LENGTH; // 向上选择
            DisplayMenu(selected);
            HAL_Delay(200); // 消抖延迟
        }
        
        if (HAL_GPIO_ReadPin(K2_GPIO_Port, K2_Pin) == GPIO_PIN_RESET) { // 按下KEY2
            selected = (selected + 1) % MENU_LENGTH; // 向下选择
            DisplayMenu(selected);
            HAL_Delay(200); // 消抖延迟
        }

        if (HAL_GPIO_ReadPin(K3_GPIO_Port, K3_Pin) == GPIO_PIN_RESET) { // 按下KEY3
            if (menu[selected].action != NULL) {
                menu[selected].action(); // 调用对应功能
            }
            HAL_Delay(200); // 消抖延迟
        }

        if (HAL_GPIO_ReadPin(K4_GPIO_Port, K4_Pin) == GPIO_PIN_RESET) { // 按下KEY4
            // 处理取消操作（可以实现返回上一级菜单等）
            HAL_Delay(200); // 消抖延迟
        }
    }
}
*/