/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include <string.h> 

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "MCU_BSP.h"
#include "PCA9685.h"
#include "TASK.h"
#include "app_piano.h"
#include "oled.h"
#include "stepper_motor.h"
#include "Flash.h" 
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern uint8_t midi_Buff[RX_MIDI_LEN];
extern uint8_t flag_data;
extern uint32_t flash_write_address;
extern MidiFileHeader midiHeader;

//extern uint8_t rxIndex ;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void PrintToUART(const char *str)
{
    HAL_UART_Transmit(&huart1, (uint8_t *)str, strlen(str), HAL_MAX_DELAY);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

    //uint8_t flag = 0;
		flag_data = 0;
	uint32_t count=0;
	//uint32_t flashAddress;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  MX_TIM7_Init();
  MX_TIM1_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM8_Init();
  MX_TIM9_Init();
  MX_TIM12_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

    MCU_InternalPeripheral_Init();
    PCA9685_Init();
    LED_Init();
//    OLED_Init();
//    OLED_Clear();
    PianoPlayInit();
//    StepperMotor_Init();

//    printf("MCU Start\r\n");
//    OLED_ShowString(0, 0, (uint8_t *)"MCU Star", 16);
//    OLED_ShowString(0, 2, (uint8_t *)"       ", 16);
//    OLED_ShowString(0, 4, (uint8_t *)"  ", 16);
//    OLED_ShowString(0, 6, (uint8_t *)"  ", 16);

  /* USER CODE END 2 */
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
		/*uint32_t eraseAddress = 0x000000;
		
		//Flash_Sector_Erase(eraseAddress);
		strncpy(midiHeader.fileName,  "Counter.mid", sizeof(midiHeader.fileName));
		midiHeader.fileAddress=FLASH_BASE_ADDRESS;
		midiHeader.fileSize=0x003172;
		WriteMidiHeader(&midiHeader,0);
		HAL_Delay(10);
		
		strncpy(midiHeader.fileName,  "The-Swan.mid", sizeof(midiHeader.fileName));
		midiHeader.fileAddress=FLASH_MIDI_ADDRESS;
		midiHeader.fileSize=0x0056E2;
		WriteMidiHeader(&midiHeader,1);*/
		
		
    /*Flash_Sector_Erase(FLASH_MIDI_ADDRESS);//0x009000����һҳ��0x00A000
		HAL_Delay(400);
		Flash_Sector_Erase(0x00A000);
		HAL_Delay(400);
		Flash_Sector_Erase(0x00B000);
		HAL_Delay(400);
		Flash_Sector_Erase(0x00C000);
		HAL_Delay(400);
		Flash_Sector_Erase(0x00D000);
		HAL_Delay(400);*/
		HAL_UART_Receive_IT(&huart1,midi_buf,10);
		//ReceiveAndStoreMidiFile("Long-Long-ago.mid"); 
		
    while (1)
    {
    /* USER CODE END WHILE */
			 if(flag_data){
				ParseReceivedData(midi_buf);
				HAL_UART_Receive_IT(&huart1,midi_buf,10);
				 flag_data=0;
			 }
			 else
			 {
				 HAL_UART_Receive_IT(&huart1,midi_buf,10);
			 }
			 if(midi_buf[2] == 0xFF&&midi_buf[3] == 0xFF && midi_buf[4] == 0xFF && midi_buf[5] == 0x00 && midi_buf[6] == 0x00 && midi_buf[7] == 0x00)
			 {
				 ParseReceivedData(midi_buf);
				 strncpy(midiHeader.fileName,  "William-Tell.mid", sizeof(midiHeader.fileName));
				 midiHeader.fileAddress=FLASH_MIDI_ADDRESS;
				 midiHeader.fileSize=flash_write_address;
				 //WriteMidiHeader(&midiHeader,3);
				 break;				 
			 }
			 /*Counter-attack*/
    /* USER CODE BEGIN 3 */
    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM6 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM6) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
