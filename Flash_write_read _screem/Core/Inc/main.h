/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEY1_Pin GPIO_PIN_3
#define KEY1_GPIO_Port GPIOE
#define KEY0_Pin GPIO_PIN_4
#define KEY0_GPIO_Port GPIOE
#define TFT_DC_Pin GPIO_PIN_0
#define TFT_DC_GPIO_Port GPIOC
#define TFT_RST_Pin GPIO_PIN_1
#define TFT_RST_GPIO_Port GPIOC
#define LED_D2_Pin GPIO_PIN_6
#define LED_D2_GPIO_Port GPIOA
#define LED_D3_Pin GPIO_PIN_7
#define LED_D3_GPIO_Port GPIOA
#define TFT_CS_Pin GPIO_PIN_1
#define TFT_CS_GPIO_Port GPIOB
#define TFT_BLK_Pin GPIO_PIN_2
#define TFT_BLK_GPIO_Port GPIOB
#define Motor1_DIR_Backward_Pin GPIO_PIN_8
#define Motor1_DIR_Backward_GPIO_Port GPIOD
#define Motor1_DIR_Forward_Pin GPIO_PIN_10
#define Motor1_DIR_Forward_GPIO_Port GPIOD
#define Motor1_PUL_Backward_Pin GPIO_PIN_12
#define Motor1_PUL_Backward_GPIO_Port GPIOD
#define Motor1_PUL_Forward_Pin GPIO_PIN_14
#define Motor1_PUL_Forward_GPIO_Port GPIOD
#define K1_Pin GPIO_PIN_0
#define K1_GPIO_Port GPIOD
#define K2_Pin GPIO_PIN_1
#define K2_GPIO_Port GPIOD
#define K3_Pin GPIO_PIN_2
#define K3_GPIO_Port GPIOD
#define K4_Pin GPIO_PIN_3
#define K4_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */
void PrintToUART(const char *str);
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
