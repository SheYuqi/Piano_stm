#include "MCU_BSP.h"
#include "tim.h"
#include "usart.h"


char MCU_BSP_g_stringTemp[MCU_BSP_g_stringTempMAXLen];

/**
 * @brief printf重定向
 * 
 * @param ch 
 * @param f 
 * @return int 
 */
int fputc(int ch, FILE *f)
{
    //	#ifndef PRINT_ERR
    //		Queue_Put(Uart_Tx_Queue, &ch);
    //	#else
    while (HAL_UART_Transmit(&DEBUG_USART, (uint8_t *)&ch, 1, 100) == HAL_BUSY)
        ;
    //	#endif
    return (ch);
}

void MCU_InternalPeripheral_Init(void)
{
    MCU_Date_Init();

    // TIM
    /**
     * @brief Construct a new hal tim base start object
     * @polarity High
     * @frequency 20kH
     * @Counter Period: 4200-1
     */
    HAL_TIM_Base_Start(&htim1);
    HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
    __HAL_TIM_SetCompare(&htim1, TIM_CHANNEL_1, 0);

    // HAL_TIM_Base_Start(&htim3);
    // HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    // __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, 0);
    // HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    // __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, 0); // turn off LED D3

    // TIM1->CCER = 0x1111;
    // HAL_TIM_Base_Start(&htim2);
    // TIM2->CCER = 0x1111;
    // HAL_TIM_Base_Start(&htim3);
    // TIM3->CCER = 0x1111;
    // HAL_TIM_Base_Start(&htim4);
    // TIM4->CCER = 0x1111;
    // HAL_TIM_Base_Start(&htim5);
    // TIM5->CCER = 0x1111;
    // HAL_TIM_Base_Start(&htim8);
    // TIM8->CCER = 0x1111;
    // HAL_TIM_Base_Start(&htim9);
    // TIM9->CCER = 0x1111;
    // HAL_TIM_Base_Start(&htim12);
    // TIM12->CCER = 0x1111;

    // UART
}

void MCU_Date_Init(void)
{
}
void LED_D2_TIM3_CH1_Beathe(void)
{
    for (int16_t i = 0; i < 4200; i += 100)
    {
        __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, i);
        HAL_Delay(1);
    }

    for (int16_t i = 4200; i > 0; i -= 100)
    {
        __HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, i);
        HAL_Delay(1);
    }
}
void TIM_CH_Test(TIM_HandleTypeDef *htim, uint32_t TIM_CHANNEL)
{
    for (int16_t i = 0; i < 4200; i += 5)
    {
        __HAL_TIM_SetCompare(htim, TIM_CHANNEL, i);
        HAL_Delay(1);
    }

    for (int16_t i = 4200; i > 0; i -= 5)
    {
        __HAL_TIM_SetCompare(htim, TIM_CHANNEL, i);
        HAL_Delay(1);
    }
}
void TIM_CH_Test_Control(TIM_HandleTypeDef *htim, uint32_t TIM_CHANNEL)
{
    float Down_percent = 0.65;
    float Up_percent = 0.0;

    __HAL_TIM_SetCompare(htim, TIM_CHANNEL, 4200*Down_percent);
    HAL_Delay(300);
    __HAL_TIM_SetCompare(htim, TIM_CHANNEL, 4200*Up_percent);
    HAL_Delay(300);

//    for (int16_t i = 4200*Down_percent; i > 4200*Up_percent; i -= 1000)
//    {
//        __HAL_TIM_SetCompare(htim, TIM_CHANNEL, i);
//        HAL_Delay(1);
//    }
}
/**
 * @brief Init LED
 * 
 */
void LED_Init(void)
{
    LED_D2_Off;
    LED_D3_Off;
}
