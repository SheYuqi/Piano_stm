#include "PCA9685.h"
#include "math.h"
#include "i2c.h"
/*���01 begin*/
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
/*���01 end*/

/*���02 begin*/
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
/*���02 end*/
/*���03 begin*/
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
/*���03 end*/
/*���04 begin*/
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
/*���04 end*/
/*���05 begin*/
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
/*���05 end*/
/*���06 begin*/
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
/*���06 end*/
/*����������������������������������������������������������������������������������������������������������������������������������������������������������������������*/
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
/*ͨ�ô���*/
void pca_setfreq(float freq) // ����PWMƵ��
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
/*num:���PWM�������0~15��on:PWM��������ֵ0~4096,off:PWM�½�����ֵ0~4096
һ��PWM���ڷֳ�4096�ݣ���0��ʼ+1�������Ƶ�onʱ����Ϊ�ߵ�ƽ������������offʱ
����Ϊ�͵�ƽ��ֱ������4096���¿�ʼ�����Ե�on������0ʱ������ʱ,��on����0ʱ��
off/4096��ֵ����PWM��ռ�ձȡ�*/

/*
    �������ã���ʼ�����������
    ������1.PWMƵ��
          2.��ʼ������Ƕ�
*/
void PCA_MG9XX_Init(float hz, uint8_t angle)
{
    uint32_t off = 0;
    //	IIC_Init();
    pca_write_1(pca_mode1, 0x0);
		pca_write_2(pca_mode1, 0x0);
    pca_setfreq(hz); // ����PWMƵ��
    off = (uint32_t)(145 + angle * 2.4);
		for(int i=0;i<16;i++){
			pca_setpwm_1(i, 0, off);
			pca_setpwm_2(i, 0, off);
		}
    HAL_Delay(500);
}

/*
    �������ã����ƶ��ת����
    ������1.����˿ڣ���ѡ0~15��
          2.��ʼ�Ƕȣ���ѡ0~180��
          3.�����Ƕȣ���ѡ0~180��
          4.ģʽѡ��0 ��ʾ����������ʱ������ʱ��Ҫ�ں������������ʱ�������Ҳ��ɵ��٣������������������ֵ��
                      1 ��ʾ����������ʱ������ʱ����Ҫ�ں������������ʱ�������Ҳ��ɵ��٣������������������ֵ��
                      2 ��ʾ�ٶȿɵ��������������ʾ�ٶ�ֵ��
          5.�ٶȣ�������� 0 ������ֵ���� 1 ʱ�ٶ���죬��ֵԽ���ٶ�ԽС��
    ע�����ģʽ 0��1 ���ٶȱ�ģʽ 2 ������ٶȴ�
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
    // pca_setfreq(20000); // ����PWMƵ��
    pca_setfreq(2000); // ����PWMƵ��  //�����٣����Բ���һ��20000��ʲôЧ��

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
