#include "TASK.h"
#include "PCA9685.h"
#include "oled.h"

void Hand_Test(void)
{
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 50; i++)
        {

            PCA9685_PWM_Set(j, i * (1.0 / 50));
            HAL_Delay(100);
        }
    }
}
/**
 * @brief 50Hz Time:20ms
 * High----duty
 * 0.5ms --- 0.025 --- -90
 * 1ms --- 0.05 ----- -45
 * 1.5ms----0.075 ---  0
 * 2ms --- 0.1 --- 45
 * 2.5ms --- 0.125 --- 90
 */
void Hand_Test2(void)
{
    float PWM_Duty = 0.025;
    uint16_t Count = 20;

    sprintf(MCU_BSP_g_stringTemp, "PWM_Duty:%0.2f    ", PWM_Duty);
    OLED_ShowString(0, 2, (uint8_t *)MCU_BSP_g_stringTemp, 16);

    for (int i = 0; i < Count; i++)
    {
        PWM_Duty = 0.025 + i * (0.125 - 0.025) / (Count - 1);

        for (int j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                // if (i == Count - 1)
                // {
                //     PCA9685_PWM_Set(j, 0.05);
                // }
                // else
                // {
                PCA9685_PWM_Set(j, 0.125 - PWM_Duty);
                // }
            }
            else
            {
                PCA9685_PWM_Set(j, PWM_Duty);
            }
            HAL_Delay(100);
        }
        // HAL_Delay(20);
    }

    HAL_Delay(2000);
    for (int j = 0; j < 5; j++)
    {
        if (j == 0)
        {
            PCA9685_PWM_Set(j, 0.125);
        }
        else
        {
            PCA9685_PWM_Set(j, 0.025);
        }

        HAL_Delay(1000);
    }
}

/**
 * @brief 50Hz Time:20ms
 * High----duty
 * 0.5ms --- 0.025 --- -90
 * 1ms --- 0.05 ----- -45
 * 1.5ms----0.075 ---  0
 * 2ms --- 0.1 --- 45
 * 2.5ms --- 0.125 --- 90
 */
void Hand_Test3(void)
{
    float PWM_Duty = 0.025;
    uint16_t Count = 20;

    sprintf(MCU_BSP_g_stringTemp, "PWM_Duty:%0.2f    ", PWM_Duty);
    OLED_ShowString(0, 2, (uint8_t *)MCU_BSP_g_stringTemp, 16);

    for (int j = 0; j < 5; j++)
    {
        if (j == 0)
        {
            PCA9685_PWM_Set(j, 0.025);
        }
        else
        {
            PCA9685_PWM_Set(j, 0.125);
        }
        // HAL_Delay(100);
    }

    HAL_Delay(5000);
    for (int j = 0; j < 5; j++)
    {
        if (j == 0)
        {
            PCA9685_PWM_Set(j, 0.125);
        }
        else
        {
            PCA9685_PWM_Set(j, 0.025);
        }

        // HAL_Delay(100);
    }

    HAL_Delay(5000);
}

void Hand_Catch(void)
{
    for (int j = 0; j < 5; j++)
    {
        if (j == 0)
        {
            PCA9685_PWM_Set(j, 0.025);
        }
        else
        {
            PCA9685_PWM_Set(j, 0.125);
        }
        // HAL_Delay(100);
    }
}
void Hand_Release(void)
{
    for (int j = 0; j < 5; j++)
    {
        if (j == 0)
        {
            PCA9685_PWM_Set(j, 0.125);
        }
        else
        {
            PCA9685_PWM_Set(j, 0.025);
        }
    }
}