#include "Key.h"

MidiFileHeader fileHeaders[MAX_MIDI_FILES]; // ���ڴ洢�ļ�ͷ��Ϣ������
extern  MidiFileHeader midiHeader;
uint8_t midi_buf[6] = {0};
extern uint8_t flag_data;
extern uint32_t flash_write_address ;  // ��ʼд���ַ
int fileCount = 0;                 // �ļ�ͷ����

//��Flash�ж�ȡͷ�ļ�
void LoadFileHeaders(void) {
    for (int i = 0; i < MAX_MIDI_FILES; i++) {
        // �� Flash ��ָ����ַ��ȡ�ļ�ͷ
        uint32_t address = FLASH_BASE_ADDRESS + i * FILE_HEADER_SIZE;
        Flash_ReadData(address, (uint8_t*)&fileHeaders[i], FILE_HEADER_SIZE);
				//ST7735_DrawString(10, 50+10*i, "Playing:222",ST7735_WHITE,ST7735_BLACK, &Font_7x10);
        
        // ����ļ����Ƿ���Ч
        if (fileHeaders[i].fileName[0] != '\0'&& fileHeaders[i].fileName[0] != (char)0xFF) {
            fileCount++;
        } else {
            break;
        }
    }
}

void DisplayFileHeaders(int selected) {

    for (int i = 0; i < fileCount; i++) {
        // ����������ɫ��ѡ����Ϊ��ɫ
        //ST7735_SetTextColor(i == selected ? RED : WHITE);
        ST7735_DrawString(10, 10 + i * 20,fileHeaders[i].fileName,i == selected ? ST7735_RED : ST7735_WHITE,ST7735_BLACK, &Font_7x10);
    }
}

// ���˵�ѡ���ܣ�ͨ�������л���ͬ����Ŀ
void FileSelect_Menu(void) {
    int selected = 0; // ��ǰѡ�е��ļ�ͷ
    DisplayFileHeaders(selected);

    while (1) {
        // ��ȡ����״̬
        if (HAL_GPIO_ReadPin(K1_GPIO_Port, K1_Pin) == GPIO_PIN_RESET) { // ����ѡ��
						selected = (selected - 1 + fileCount) % fileCount;
            DisplayFileHeaders(selected);
            HAL_Delay(200); // �����ӳ�
        }
        
        if (HAL_GPIO_ReadPin(K2_GPIO_Port, K2_Pin) == GPIO_PIN_RESET) { // ����ѡ��
            selected = (selected + 1) % fileCount;
            DisplayFileHeaders(selected);
            HAL_Delay(200);
        }

        if (HAL_GPIO_ReadPin(K3_GPIO_Port, K3_Pin) == GPIO_PIN_RESET) { // ѡ���ļ�ͷ
            // ����ѡ����Ŀ����ϸ��Ϣ��ʼ����
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
								break;  // ��������������ѭ��  13967
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
						sprintf(buffer0, "flash_adress��%d\n",flash_adress);
						PrintToUART(buffer0);
						
						sprintf(buffer0, " fileSize��%d\n",fileHeaders[selected].fileSize);
						PrintToUART(buffer0);
						PrintToUART("Data read from Flash:\n");
						PrintToUART(fileHeaders[selected].fileName);
						PrintToUART("Data read from Flash:\n");
						
						// ��ӡ��ȡ������
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

        if (HAL_GPIO_ReadPin(K4_GPIO_Port, K4_Pin) == GPIO_PIN_RESET) { // ���ز���
            break; // ������һ���˵����˳�
            HAL_Delay(200);
        }
    }
}

/*// �˵��������
void MenuAction1() {
    // �˵���1�Ĺ���
    ST7735_DrawString(10, 50, "Selected Menu Item 1");
}

void MenuAction2() {
    // �˵���2�Ĺ���
    ST7735_DrawString(10, 50, "Selected Menu Item 2");
}

// ����˵���
MenuItem menu[] = {
    {"Menu Item 1", MenuAction1},
    {"Menu Item 2", MenuAction2},
    {"Menu Item 3", NULL}, // û�ж�Ӧ�Ĺ���
    {"Menu Item 4", NULL}
};

#define MENU_LENGTH (sizeof(menu) / sizeof(menu[0]))
	

// ��ʾ�˵�����
void DisplayMenu(int selected) {
    ST7735_FillScreen(ST7735_BLACK); // ����
    for (int i = 0; i < MENU_LENGTH; i++) {
        // ����ѡ�е���ı�������ɫ
        if (i == selected) {
            ST7735_SetTextColor(ST7735_RED); // ѡ����Ϊ��ɫ
        } else {
            ST7735_SetTextColor(ST7735_WHITE); // ������Ϊ��ɫ
        }
        ST7735_DrawString(10, 10 + (i * 10), menu[i].title); // ����ÿ������10������
    }
}

// ���˵�ѡ����
void Key_Menu_Select() {
    static int selected = 0; // ��¼��ǰѡ�еĲ˵���
    DisplayMenu(selected); // ��ʾ�˵�

    while (1) {
        // ��ȡ����״̬
        if (HAL_GPIO_ReadPin(K1_GPIO_Port, K1_Pin) == GPIO_PIN_RESET) { // ����KEY1
            selected = (selected - 1 + MENU_LENGTH) % MENU_LENGTH; // ����ѡ��
            DisplayMenu(selected);
            HAL_Delay(200); // �����ӳ�
        }
        
        if (HAL_GPIO_ReadPin(K2_GPIO_Port, K2_Pin) == GPIO_PIN_RESET) { // ����KEY2
            selected = (selected + 1) % MENU_LENGTH; // ����ѡ��
            DisplayMenu(selected);
            HAL_Delay(200); // �����ӳ�
        }

        if (HAL_GPIO_ReadPin(K3_GPIO_Port, K3_Pin) == GPIO_PIN_RESET) { // ����KEY3
            if (menu[selected].action != NULL) {
                menu[selected].action(); // ���ö�Ӧ����
            }
            HAL_Delay(200); // �����ӳ�
        }

        if (HAL_GPIO_ReadPin(K4_GPIO_Port, K4_Pin) == GPIO_PIN_RESET) { // ����KEY4
            // ����ȡ������������ʵ�ַ�����һ���˵��ȣ�
            HAL_Delay(200); // �����ӳ�
        }
    }
}
*/