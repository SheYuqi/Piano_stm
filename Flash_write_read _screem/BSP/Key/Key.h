#ifndef KEY_H
#define KEY_H

#include "main.h"
#include "spi.h"
#include "fonts.h"
#include "stdio.h"
#include "stdint.h"
#include "app_piano.h"
#include "Flash.h"
#include "ST7735.h"         // 引入屏幕驱动的头文件

// 按键引脚的定义，需根据实际连接的引脚进行修改


// 菜单项结构体定义
typedef struct {
    const char* title;      // 菜单项标题
    void (*action)(void);   // 选择菜单项时执行的函数
} MenuItem;

// 函数声明

void LoadFileHeaders(void);
void DisplayFileHeaders(int selected);
void FileSelect_Menu(void);


/*void DisplayMenu(int selected);        // 显示菜单界面
void Key_Menu_Select(void);            // 主菜单选择功能

// 菜单项功能函数
void MenuAction1(void);  // 菜单项1的功能
void MenuAction2(void);  // 菜单项2的功能*/

#endif /* KEY_H */
