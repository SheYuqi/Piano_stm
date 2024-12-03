#ifndef KEY_H
#define KEY_H

#include "main.h"
#include "spi.h"
#include "fonts.h"
#include "stdio.h"
#include "stdint.h"
#include "app_piano.h"
#include "Flash.h"
#include "ST7735.h"         // ������Ļ������ͷ�ļ�

// �������ŵĶ��壬�����ʵ�����ӵ����Ž����޸�


// �˵���ṹ�嶨��
typedef struct {
    const char* title;      // �˵������
    void (*action)(void);   // ѡ��˵���ʱִ�еĺ���
} MenuItem;

// ��������

void LoadFileHeaders(void);
void DisplayFileHeaders(int selected);
void FileSelect_Menu(void);


/*void DisplayMenu(int selected);        // ��ʾ�˵�����
void Key_Menu_Select(void);            // ���˵�ѡ����

// �˵���ܺ���
void MenuAction1(void);  // �˵���1�Ĺ���
void MenuAction2(void);  // �˵���2�Ĺ���*/

#endif /* KEY_H */
