#include "stepper_motor.h"
#include "stdint.h"

/**
 * @brief  引脚初始化
 * @retval 无
 */
void StepperMotor_Init(void)
{
    Motor_EN(OFF);
}

/**
 * @brief  步进电机旋转
 * @param  tim  方波周期 单位MS   周期越短频率越高，转速越快 细分为1时最少10ms
 * @param  angle  需要转动的角度值
 * @param  dir 选择正反转 0:顺时针 1:逆时针
 * @param  subdivide  细分值
 * @note   无
 * @retval 无
 */
void stepper_turn(int tim, float angle, float subdivide, uint8_t dir)
{
    int n, i;
    /*根据细分数求得步距角被分成多少个方波*/
    n = (int)(angle / (1.8 / subdivide));

    /**
     * @brief Set Direction
     *
     */
    if (dir == 0) // 顺时针
    {
        Motor_DIR(Clockwise);
    }
    else if (dir == 1) // 逆时针
    {
        Motor_DIR(Counterclockwise);
    }

    /*开使能*/
    Motor_EN(ON);

    /*模拟方波*/
    for (i = 0; i < n; i++)
    {
        Motor_PLU(ON);
        HAL_Delay(tim / 2);
        Motor_PLU(OFF);
        HAL_Delay(tim / 2);
    }
    /*关使能*/
    Motor_EN(OFF);
}

void StepperMotor_ControlTest2(uint32_t Delay_Time_ms)
{
    uint16_t i;

    for (i = 0; i < 1600; i++)
    {
        Motor_PLU(ON);
        HAL_Delay(Delay_Time_ms);
        Motor_PLU(OFF);
        HAL_Delay(Delay_Time_ms);
    }
}
