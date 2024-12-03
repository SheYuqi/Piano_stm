#include "PCA9685.h"
#include "math.h"
#include "i2c.h"
/*编号01 begin*/
uint8_t pca_read_1(uint8_t startAddress)
{
    // Send address to start reading from.
    uint8_t tx[1];
    uint8_t buffer[1];
    tx[0] = startAddress;

    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr1, tx, 1, 10000);
    HAL_I2C_Master_Receive(&hi2c2, pca_adrr1, buffer, 1, 10000);
    return buffer[0];
}

void pca_write_1(uint8_t startAddress, uint8_t buffer)
{
    // Send address to start reading from.
    uint8_t tx[2];
    tx[0] = startAddress;
    tx[1] = buffer;
    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr1, tx, 2, 10000);
}
void pca_setpwm_1(uint8_t num, uint32_t on, uint32_t off)
{
    pca_write_1(LED0_ON_L + 4 * num, on);
    pca_write_1(LED0_ON_H + 4 * num, on >> 8);
    pca_write_1(LED0_OFF_L + 4 * num, off);
    pca_write_1(LED0_OFF_H + 4 * num, off >> 8);
}
/*编号01 end*/

/*编号02 begin*/
uint8_t pca_read_2(uint8_t startAddress)
{
    // Send address to start reading from.
    uint8_t tx[1];
    uint8_t buffer[1];
    tx[0] = startAddress;

    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr2, tx, 1, 10000);
    HAL_I2C_Master_Receive(&hi2c2, pca_adrr2, buffer, 1, 10000);
    return buffer[0];
}

void pca_write_2(uint8_t startAddress, uint8_t buffer)
{
    // Send address to start reading from.
    uint8_t tx[2];
    tx[0] = startAddress;
    tx[1] = buffer;
    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr2, tx, 2, 10000);
}

void pca_setpwm_2(uint8_t num, uint32_t on, uint32_t off)
{
    pca_write_2(LED0_ON_L + 4 * num, on);
    pca_write_2(LED0_ON_H + 4 * num, on >> 8);
    pca_write_2(LED0_OFF_L + 4 * num, off);
    pca_write_2(LED0_OFF_H + 4 * num, off >> 8);
}
/*编号02 end*/
/*编号03 begin*/
uint8_t pca_read_3(uint8_t startAddress)
{
    // Send address to start reading from.
    uint8_t tx[1];
    uint8_t buffer[1];
    tx[0] = startAddress;

    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr3, tx, 1, 10000);
    HAL_I2C_Master_Receive(&hi2c2, pca_adrr3, buffer, 1, 10000);
    return buffer[0];
}

void pca_write_3(uint8_t startAddress, uint8_t buffer)
{
    // Send address to start reading from.
    uint8_t tx[2];
    tx[0] = startAddress;
    tx[1] = buffer;
    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr3, tx, 2, 10000);
}

void pca_setpwm_3(uint8_t num, uint32_t on, uint32_t off)
{
    pca_write_3(LED0_ON_L + 4 * num, on);
    pca_write_3(LED0_ON_H + 4 * num, on >> 8);
    pca_write_3(LED0_OFF_L + 4 * num, off);
    pca_write_3(LED0_OFF_H + 4 * num, off >> 8);
}
/*编号03 end*/
/*编号04 begin*/
uint8_t pca_read_4(uint8_t startAddress)
{
    // Send address to start reading from.
    uint8_t tx[1];
    uint8_t buffer[1];
    tx[0] = startAddress;

    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr4, tx, 1, 10000);
    HAL_I2C_Master_Receive(&hi2c2, pca_adrr4, buffer, 1, 10000);
    return buffer[0];
}

void pca_write_4(uint8_t startAddress, uint8_t buffer)
{
    // Send address to start reading from.
    uint8_t tx[2];
    tx[0] = startAddress;
    tx[1] = buffer;
    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr4, tx, 2, 10000);
}

void pca_setpwm_4(uint8_t num, uint32_t on, uint32_t off)
{
    pca_write_4(LED0_ON_L + 4 * num, on);
    pca_write_4(LED0_ON_H + 4 * num, on >> 8);
    pca_write_4(LED0_OFF_L + 4 * num, off);
    pca_write_4(LED0_OFF_H + 4 * num, off >> 8);
}
/*编号04 end*/
/*编号05 begin*/
uint8_t pca_read_5(uint8_t startAddress)
{
    // Send address to start reading from.
    uint8_t tx[1];
    uint8_t buffer[1];
    tx[0] = startAddress;

    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr5, tx, 1, 10000);
    HAL_I2C_Master_Receive(&hi2c2, pca_adrr5, buffer, 1, 10000);
    return buffer[0];
}

void pca_write_5(uint8_t startAddress, uint8_t buffer)
{
    // Send address to start reading from.
    uint8_t tx[2];
    tx[0] = startAddress;
    tx[1] = buffer;
    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr5, tx, 2, 10000);
}

void pca_setpwm_5(uint8_t num, uint32_t on, uint32_t off)
{
    pca_write_5(LED0_ON_L + 4 * num, on);
    pca_write_5(LED0_ON_H + 4 * num, on >> 8);
    pca_write_5(LED0_OFF_L + 4 * num, off);
    pca_write_5(LED0_OFF_H + 4 * num, off >> 8);
}
/*编号05 end*/
/*编号06 begin*/
uint8_t pca_read_6(uint8_t startAddress)
{
    // Send address to start reading from.
    uint8_t tx[1];
    uint8_t buffer[1];
    tx[0] = startAddress;

    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr6, tx, 1, 10000);
    HAL_I2C_Master_Receive(&hi2c2, pca_adrr6, buffer, 1, 10000);
    return buffer[0];
}

void pca_write_6(uint8_t startAddress, uint8_t buffer)
{
    // Send address to start reading from.
    uint8_t tx[2];
    tx[0] = startAddress;
    tx[1] = buffer;
    HAL_I2C_Master_Transmit(&hi2c2, pca_adrr6, tx, 2, 10000);
}

void pca_setpwm_6(uint8_t num, uint32_t on, uint32_t off)
{
    pca_write_6(LED0_ON_L + 4 * num, on);
    pca_write_6(LED0_ON_H + 4 * num, on >> 8);
    pca_write_6(LED0_OFF_L + 4 * num, off);
    pca_write_6(LED0_OFF_H + 4 * num, off >> 8);
}
/*编号06 end*/
/*———————————————————————————————————————————————————————————————————————————————————*/
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
/*通用代码*/
void pca_setfreq(float freq) // 设置PWM频率
{
  uint8_t prescale;  
	uint8_t oldmode1, newmode1,oldmode2, newmode2,oldmode3, newmode3,oldmode4, newmode4,oldmode5, newmode5,oldmode6, newmode6;
    // double prescaleval;
    float prescaleval;
//    freq *= 0.92;
    freq =  freq * 0.92f;
    prescaleval = 25000000;
    prescaleval /= 4096;
    prescaleval /= freq;
    prescaleval -= 1;
    prescale = floor(prescaleval + 0.5f);

    oldmode1 = pca_read_1(pca_mode1);
		oldmode2 = pca_read_2(pca_mode1);
		oldmode3 = pca_read_3(pca_mode1);
		oldmode4 = pca_read_4(pca_mode1);
		oldmode5 = pca_read_5(pca_mode1);
		oldmode6 = pca_read_6(pca_mode1);
	
	//Maybe ?????
    newmode1 = (oldmode1 & 0x7F) | 0x10;
		newmode2 = (oldmode2 & 0x7F) | 0x10;
		newmode3 = (oldmode3 & 0x7F) | 0x10;
		newmode4 = (oldmode4 & 0x7F) | 0x10;
		newmode5 = (oldmode5 & 0x7F) | 0x10;
		newmode6 = (oldmode6 & 0x7F) | 0x10;
		// sleep

    pca_write_1(pca_mode1, newmode1); 
		pca_write_2(pca_mode1, newmode2); 
		pca_write_3(pca_mode1, newmode3);
		pca_write_4(pca_mode1, newmode4);
		pca_write_5(pca_mode1, newmode5);
		pca_write_6(pca_mode1, newmode6);
		// go to sleep

    pca_write_1(pca_pre, prescale); 
		pca_write_2(pca_pre, prescale);
		pca_write_3(pca_pre, prescale);
		pca_write_4(pca_pre, prescale);
		pca_write_5(pca_pre, prescale);
		pca_write_6(pca_pre, prescale);
		// set the prescaler

    pca_write_1(pca_mode1, oldmode1);
		pca_write_2(pca_mode1, oldmode2);
		pca_write_3(pca_mode1, oldmode3);
		pca_write_4(pca_mode1, oldmode4);
		pca_write_5(pca_mode1, oldmode5);
		pca_write_6(pca_mode1, oldmode6);
    HAL_Delay(2);

    pca_write_1(pca_mode1, oldmode1 | 0xa1);
		pca_write_2(pca_mode1, oldmode2 | 0xa1);
		pca_write_3(pca_mode1, oldmode3 | 0xa1);
		pca_write_4(pca_mode1, oldmode4 | 0xa1);
		pca_write_5(pca_mode1, oldmode5 | 0xa1);
		pca_write_6(pca_mode1, oldmode6 | 0xa1);
}
/*num:舵机PWM输出引脚0~15，on:PWM上升计数值0~4096,off:PWM下降计数值0~4096
一个PWM周期分成4096份，由0开始+1计数，计到on时跳变为高电平，继续计数到off时
跳变为低电平，直到计满4096重新开始。所以当on不等于0时可作延时,当on等于0时，
off/4096的值就是PWM的占空比。*/

/*
    函数作用：初始化舵机驱动板
    参数：1.PWM频率
          2.初始化舵机角度
*/
void PCA_MG9XX_Init(float hz, uint8_t angle)
{
    uint32_t off = 0;
    //	IIC_Init();
    pca_write_1(pca_mode1, 0x0);
		pca_write_2(pca_mode1, 0x0);
    pca_setfreq(hz); // 设置PWM频率
    off = (uint32_t)(145 + angle * 2.4);
		for(int i=0;i<16;i++){
			pca_setpwm_1(i, 0, off);
			pca_setpwm_2(i, 0, off);
		}
    HAL_Delay(500);
}

/*
    函数作用：控制舵机转动；
    参数：1.输出端口，可选0~15；
          2.起始角度，可选0~180；
          3.结束角度，可选0~180；
          4.模式选择，0 表示函数内无延时，调用时需要在函数后另外加延时函数，且不可调速，第五个参数可填任意值；
                      1 表示函数内有延时，调用时不需要在函数后另外加延时函数，且不可调速，第五个参数可填任意值；
                      2 表示速度可调，第五个参数表示速度值；
          5.速度，可填大于 0 的任意值，填 1 时速度最快，数值越大，速度越小；
    注意事项：模式 0和1 的速度比模式 2 的最大速度大；
*/
void PCA_MG9XX(uint8_t num, uint8_t end_angle)
{
    uint32_t off = 0;

    off = (uint32_t)(158 + end_angle * 2.2);
    pca_setpwm_1(num, 0, off);
		pca_setpwm_2(num, 0, off);
}
void PCA9685_TurnOffAllChannal(void)
{
    for (uint8_t i = 0; i < 16*6; i++)
    {
        PCA9685_PWM_Set(i, 0);
    }
}
void PCA9685_Init(void)
{
    pca_write_1(pca_mode1, 0x0);
		pca_write_2(pca_mode1, 0x0);
		pca_write_3(pca_mode1, 0x0);
		pca_write_4(pca_mode1, 0x0);
		pca_write_5(pca_mode1, 0x0);
		pca_write_6(pca_mode1, 0x0);
    // pca_setfreq(20000); // 设置PWM频率
    pca_setfreq(2000); // 设置PWM频率  //最大多少？可以测试一下20000是什么效果

    // pca_setpwm(0, 0, 4096 / 2); // Set PWM

    // for (uint8_t i = 0; i < 16; i++)
    // {
    //     PCA9685_PWM_Set(i, 0);
    // }
    PCA9685_TurnOffAllChannal();
}
/**
 * @brief Set PCA9685's PWM
 *
 * @param node  0-15
 * @param Duty  0-1
 */
void PCA9685_PWM_Set(uint8_t node, float Duty)
{
	switch (node/16){
		case 0:
			pca_setpwm_1(node, 0, 4096 * Duty); // Set PWM
			break;
		case 1:
			pca_setpwm_2(node%16, 0, 4096 * Duty); // Set PWM
			break;
		case 2:
			pca_setpwm_3(node%16, 0, 4096 * Duty); // Set PWM
			break;
		case 3:
			pca_setpwm_4(node%16, 0, 4096 * Duty); // Set PWM
			break;
		case 4:
			pca_setpwm_5(node%16, 0, 4096 * Duty); // Set PWM
			break;
		case 5:
			pca_setpwm_6(node%16, 0, 4096 * Duty); // Set PWM
			break;
		default:
			return;
	}
    //pca_setpwm(node, 0, 4096 * Duty); // Set PWM
}
