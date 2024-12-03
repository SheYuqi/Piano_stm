/**
 * @file stepper_motor.h
 * @author sfc
 * @brief Stepper motor control, common cathode
 * @version 0.1
 * @date 2024-06-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef __STEPPER_MOTOR_H
#define __STEPPER_MOTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

// 引脚定义
#define ON GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

#define Clockwise GPIO_PIN_RESET
#define Counterclockwise GPIO_PIN_SET

#define Motor_EN(x) HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, x)
#define Motor_DIR(x) HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, x)
#define Motor_PLU(x) HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, x)

    void StepperMotor_Init(void);
    void stepper_turn(int tim, float angle, float subdivide, uint8_t dir);
    void StepperMotor_ControlTest2(uint32_t Delay_Time_ms);

#ifdef __cplusplus
}
#endif

#endif /* __STEPPER_MOTOR_H */
