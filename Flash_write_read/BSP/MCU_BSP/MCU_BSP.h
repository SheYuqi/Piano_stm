#ifndef __MCU_BSP
#define __MCU_BSP

#include "main.h"
#include "stdint.h"
#include "stdio.h"
#include "rtCtrBoard_define.h"


#define MCU_BSP_g_stringTempMAXLen 100 

#ifdef __cplusplus
extern "C"
{
#endif

#define DEBUG_DISABLE 0

#ifndef DEBUG_DISABLE
// #define UART_IT_RX_DEBUG 1
#endif



#define LED_D2_On HAL_GPIO_WritePin(LED_D2_GPIO_Port,LED_D2_Pin,GPIO_PIN_RESET)
#define LED_D2_Off HAL_GPIO_WritePin(LED_D2_GPIO_Port,LED_D2_Pin,GPIO_PIN_SET)
#define LED_D2_Toggle HAL_GPIO_TogglePin(LED_D2_GPIO_Port, LED_D2_Pin)

#define LED_D3_On  HAL_GPIO_WritePin(LED_D3_GPIO_Port,LED_D3_Pin,GPIO_PIN_RESET)
#define LED_D3_Off HAL_GPIO_WritePin(LED_D3_GPIO_Port,LED_D3_Pin,GPIO_PIN_SET)
#define LED_D3_Toggle HAL_GPIO_TogglePin(LED_D3_GPIO_Port, LED_D3_Pin)


extern char MCU_BSP_g_stringTemp[MCU_BSP_g_stringTempMAXLen];

int fputc(int ch, FILE *f);
void MCU_InternalPeripheral_Init(void);
void MCU_Date_Init(void);
void LED_D2_TIM3_CH1_Beathe(void);
void TIM_CH_Test(TIM_HandleTypeDef *htim,uint32_t TIM_CHANNEL);
void TIM_CH_Test_Control(TIM_HandleTypeDef *htim,uint32_t TIM_CHANNEL);
void LED_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __MCU_BSP */
