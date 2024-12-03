#ifndef __PCA9685_H
#define __PCA9685_H	

//#include "stm32f10x.h"
// #include "stm32f1xx_hal.h"
#include "main.h"
#include "MCU_BSP.h"

#define pca_adrr1 0x80
#define pca_adrr2 0x82
#define pca_adrr3 0x84
#define pca_adrr4 0x86
#define pca_adrr5 0x88
#define pca_adrr6 0x90

#define pca_mode1 0x0
#define pca_pre 0xFE

#define LED0_ON_L 0x6
#define LED0_ON_H 0x7
#define LED0_OFF_L 0x8
#define LED0_OFF_H 0x9

#define jdMIN  115 // minimum
#define jdMAX  590 // maximum
#define jd000  130 //0�ȶ�Ӧ4096����������ֵ
#define jd180  520 //180�ȶ�Ӧ4096����������ֵ


void pca_write_1(uint8_t adrr,uint8_t data);
uint8_t pca_read_1(uint8_t adrr);
void pca_setpwm_1(uint8_t num, uint32_t on, uint32_t off);

void pca_write_2(uint8_t adrr,uint8_t data);
uint8_t pca_read_2(uint8_t adrr);
void pca_setpwm_2(uint8_t num, uint32_t on, uint32_t off);

void pca_write_3(uint8_t adrr,uint8_t data);
uint8_t pca_read_3(uint8_t adrr);
void pca_setpwm_3(uint8_t num, uint32_t on, uint32_t off);

void pca_write_4(uint8_t adrr,uint8_t data);
uint8_t pca_read_4(uint8_t adrr);
void pca_setpwm_4(uint8_t num, uint32_t on, uint32_t off);

void pca_write_5(uint8_t adrr,uint8_t data);
uint8_t pca_read_5(uint8_t adrr);
void pca_setpwm_5(uint8_t num, uint32_t on, uint32_t off);

void pca_write_6(uint8_t adrr,uint8_t data);
uint8_t pca_read_6(uint8_t adrr);
void pca_setpwm_6(uint8_t num, uint32_t on, uint32_t off);

void pca_setfreq(float freq);
void PCA_MG9XX_Init(float hz,uint8_t angle);
void PCA_MG9XX(uint8_t num,uint8_t end_angle);
void PCA9685_Init(void);
void PCA9685_PWM_Set(uint8_t node,float Duty);
void PCA9685_TurnOffAllChannal(void);


#endif




