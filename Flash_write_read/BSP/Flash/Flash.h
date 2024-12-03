#ifndef __FLASH_H
#define __FLASH_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>

// W25Q16 ָ���
#define W25Q16_WRITE_ENABLE        0x06
#define W25Q16_WRITE_DISABLE       0x04
#define W25Q16_READ_DATA           0x03
#define W25Q16_PAGE_PROGRAM        0x02
#define W25Q16_SECTOR_ERASE        0x20
#define W25Q16_CHIP_ERASE          0xC7
#define W25Q16_READ_STATUS_REG     0x05
#define W25Q16_READ_DEVICE_ID      0x9F

// FLASH ��ض���
#define MAX_MIDI_FILES 128  // �������洢 128 ���ļ�
#define FLASH_START_ADDRESS 0x000001  // ��������ʹ�ô������ַ��ʼ�� Flash ����
#define FLASH_END_ADDRESS 0x001000
#define FILE_HEADER_SIZE (sizeof(MidiFileHeader)+5)
#define FILE_HEADER_AREA_SIZE (MAX_MIDI_FILES * FILE_HEADER_SIZE)  // �ļ�ͷ�����С
#define FILE_DATA_START_ADDRESS (FLASH_START_ADDRESS + FILE_HEADER_AREA_SIZE)  // ���ݿ�ʼ�ĵ�ַ

#define BUF_SIZE 10
#define FLASH_BASE_ADDRESS 0x000001  // Flash ��ʼ��ַ�������оƬ�������õ���
typedef struct {
    char fileName[32];  // MIDI �ļ��������15�ַ�
    uint32_t fileSize;  // MIDI �ļ���С
    uint32_t fileAddress;  // �ļ��洢�� Flash ����ʼ��ַ
} MidiFileHeader;

// ��������
//void Flash_Init(void);
void ParseReceivedData(uint8_t* buf);
void ReceiveAndStoreMidiFile(const char *fileName);
uint32_t FindFileByName(const char* targetFileName);

uint8_t Flash_ReadDeviceID(void);
void Flash_WriteEnable(void);
void Flash_WriteDisable(void);
void Flash_ReadData(uint32_t address, uint8_t *buffer, uint16_t size);
void Flash_PageProgram(uint32_t address, uint8_t *buffer, uint16_t size);
void Flash_SectorErase(uint32_t address);
uint8_t Flash_ReadStatusRegister(void);

#ifdef __cplusplus
}
#endif

#endif /* __FLASH_H */
