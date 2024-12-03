#include "app_piano.h"
#include "PCA9685.h"
#include "oled.h"

/**
    @filename:AnalyzingMIDI\midi\lingya.mid
    @Total time:13.714288s
    @Total tracks_len:100
    @Total notes:13 contains [57, 58, 60, 62, 64, 65, 69, 72, 74, 76, 77, 79, 81]
    @format:Track, note_type channel note(21, 108) velocity(1-127) time(s)
*/
midiMsg_t midiMsg_lingya[101] =
    {
        {0, 0, 0, 0, 0, 0.0}, // no used
        {1, 1, 0, 62, 75, 0.0},
        {2, 1, 0, 69, 74, 0.0},
        {3, 1, 0, 74, 109, 0.0},
        {4, 0, 0, 74, 0, 0.4285715},
        {5, 1, 0, 81, 119, 0.0},
        {6, 0, 0, 81, 0, 0.321428625},
        {7, 1, 0, 81, 97, 0.0},
        {8, 0, 0, 62, 0, 0.107142875},
        {9, 0, 0, 69, 0, 0.0},
        {10, 0, 0, 81, 0, 0.0},
        {11, 1, 0, 60, 78, 0.0},
        {12, 1, 0, 69, 68, 0.0},
        {13, 1, 0, 77, 107, 0.0},
        {14, 0, 0, 77, 0, 0.107142875},
        {15, 1, 0, 76, 93, 0.0},
        {16, 0, 0, 76, 0, 0.107142875},
        {17, 1, 0, 74, 98, 0.0},
        {18, 0, 0, 74, 0, 0.21428575},
        {19, 1, 0, 72, 117, 0.0},
        {20, 0, 0, 60, 0, 0.21428575},
        {21, 0, 0, 69, 0, 0.0},
        {22, 0, 0, 72, 0, 0.0},
        {23, 1, 0, 69, 99, 0.0},
        {24, 0, 0, 69, 0, 0.107142875},
        {25, 1, 0, 72, 115, 0.0},
        {26, 0, 0, 72, 0, 0.107142875},
        {27, 1, 0, 58, 72, 0.0},
        {28, 1, 0, 65, 66, 0.0},
        {29, 1, 0, 74, 92, 0.0},
        {30, 0, 0, 74, 0, 0.21428575},
        {31, 1, 0, 76, 97, 0.0},
        {32, 1, 0, 77, 101, 0.107142875},
        {33, 0, 0, 76, 0, 0.0107142875},
        {34, 0, 0, 77, 0, 0.0964285875},
        {35, 1, 0, 79, 87, 0.0},
        {36, 0, 0, 79, 0, 0.107142875},
        {37, 1, 0, 77, 107, 0.0},
        {38, 0, 0, 77, 0, 0.107142875},
        {39, 1, 0, 76, 101, 0.0},
        {40, 0, 0, 76, 0, 0.21250003541666668},
        {41, 0, 0, 58, 0, 0.0017857145833333333},
        {42, 0, 0, 65, 0, 0.0},
        {43, 1, 0, 57, 64, 0.0},
        {44, 1, 0, 64, 66, 0.0},
        {45, 1, 0, 72, 109, 0.0},
        {46, 0, 0, 57, 0, 0.857143},
        {47, 0, 0, 72, 0, 0.0},
        {48, 1, 0, 62, 77, 0.0},
        {49, 1, 0, 69, 73, 0.0},
        {50, 1, 0, 74, 105, 0.0},
        {51, 0, 0, 64, 0, 0.013392859375},
        {52, 0, 0, 74, 0, 0.41250006875},
        {53, 1, 0, 81, 105, 0.002678571875},
        {54, 0, 0, 81, 0, 0.321428625},
        {55, 1, 0, 81, 98, 0.0},
        {56, 0, 0, 62, 0, 0.107142875},
        {57, 0, 0, 69, 0, 0.0},
        {58, 1, 0, 60, 68, 0.0},
        {59, 1, 0, 69, 60, 0.0},
        {60, 1, 0, 77, 98, 0.0},
        {61, 0, 0, 81, 0, 0.016964288541666667},
        {62, 0, 0, 77, 0, 0.09017858645833333},
        {63, 1, 0, 76, 94, 0.0},
        {64, 1, 0, 74, 86, 0.107142875},
        {65, 0, 0, 76, 0, 0.015178573958333334},
        {66, 0, 0, 74, 0, 0.19910717604166667},
        {67, 1, 0, 72, 101, 0.0},
        {68, 0, 0, 72, 0, 0.20535717708333334},
        {69, 0, 0, 60, 0, 0.008928572916666667},
        {70, 0, 0, 69, 0, 0.0},
        {71, 1, 0, 69, 88, 0.0},
        {72, 1, 0, 72, 106, 0.107142875},
        {73, 0, 0, 69, 0, 0.0017857145833333333},
        {74, 1, 0, 58, 85, 0.10535716041666666},
        {75, 1, 0, 65, 75, 0.0},
        {76, 1, 0, 74, 104, 0.0},
        {77, 0, 0, 72, 0, 0.039285720833333336},
        {78, 0, 0, 74, 0, 0.17500002916666665},
        {79, 1, 0, 76, 100, 0.0},
        {80, 1, 0, 77, 109, 0.107142875},
        {81, 0, 0, 76, 0, 0.002678571875},
        {82, 0, 0, 58, 0, 0.104464303125},
        {83, 0, 0, 65, 0, 0.0},
        {84, 0, 0, 77, 0, 0.0},
        {85, 1, 0, 57, 70, 0.0},
        {86, 1, 0, 64, 72, 0.0},
        {87, 1, 0, 79, 95, 0.0},
        {88, 1, 0, 77, 109, 0.107142875},
        {89, 0, 0, 79, 0, 0.023214289583333332},
        {90, 0, 0, 77, 0, 0.08392858541666667},
        {91, 1, 0, 76, 94, 0.0},
        {92, 0, 0, 64, 0, 0.20892860625},
        {93, 0, 0, 57, 0, 0.00535714375},
        {94, 0, 0, 76, 0, 0.0},
        {95, 1, 0, 62, 96, 0.0},
        {96, 1, 0, 69, 77, 0.0},
        {97, 1, 0, 74, 106, 0.0},
        {98, 0, 0, 62, 0, 0.857143},
        {99, 0, 0, 69, 0, 0.0},
        {100, 0, 0, 74, 0, 0.0}};

/**
 * @brief Piano Initial
 *
 */
void PianoPlayInit(void)
{
    /**
     * @brief Turn off piano
     *
     */
    uint8_t i;
    for (i = 0; i < 16; i++)
    {
        PCA9685_PWM_Set(i, 0);
        HAL_Delay(200);
    }
}
/**
 * @brief Piano test
 * Click the 16 keys of the piano by turn
 *
 */
void PianoPlayTest(void)
{
    uint8_t i;

    for (i = 0; i < 16; i++)
    {
        PCA9685_PWM_Set(i, 0.95);
        HAL_Delay(1100);
        PCA9685_PWM_Set(i, 0);
    }
}

void PianoPlayTest_DB(uint32_t PeriodTimems,uint8_t Times)
{
    uint8_t i;

    OLED_ShowString(0, 0, (uint8_t *)"PianoPlayTest_DB", 16);
    OLED_ShowString(0, 2, (uint8_t *)"                ", 16);
    OLED_ShowString(0, 4, (uint8_t *)"                ", 16);
    OLED_ShowString(0, 6, (uint8_t *)"                ", 16);

    for (i = 1; i <= Times; i++)
    {
        PCA9685_PWM_Set(15, 0.95);
        HAL_Delay(300);
        PCA9685_PWM_Set(15, 0);

        // sprintf(MCU_BSP_g_stringTemp, "Turn:%2d    ", i);
        // OLED_ShowString(0, 2, (uint8_t *)MCU_BSP_g_stringTemp, 16);
        HAL_Delay(PeriodTimems);
    }

    HAL_Delay(10000);// Finish 
}

/**
 * @brief Piano play midi just for lingya
 * @Total notes:13 contains
 * [57, 58, 60, 62, 64, 65, 69, 72, 74, 76, 77, 79, 81]
 * @param midiMsg
 * @param tracks_len
 */
void PianoMidiPlay(midiMsg_t *midiMsg, uint16_t tracks_len)
{
    uint16_t i = 0;
    float PWM_Duty = 0;
    uint8_t PWM_Chanal = 0;
    float PlaySpeed = 0.5;

    OLED_ShowString(0, 0, (uint8_t *)"Piano Play Start", 16);
    sprintf(MCU_BSP_g_stringTemp, "Speed:%0.2f    ", PlaySpeed);
    OLED_ShowString(0, 6, (uint8_t *)MCU_BSP_g_stringTemp, 16);

    midiMsg++;
    for (i = 1; i <= tracks_len; i++)
    {
        HAL_Delay((uint32_t)(midiMsg->time * 1000 / PlaySpeed));

        // PWM_Duty = midiMsg->velocity / 127       //????

        switch (midiMsg->note)
        {
        case 57:
            PWM_Chanal = 0;
            break;
        case 58:
            PWM_Chanal = 1;
            break;
        case 60:
            PWM_Chanal = 3;
            break;
        case 62:
            PWM_Chanal = 4;
            break;
        case 64:
            PWM_Chanal = 5;
            break;
        case 65:
            PWM_Chanal = 6;
            break;
        case 69:
            PWM_Chanal = 8;
            break;
        case 72:
            PWM_Chanal = 10;
            break;
        case 74:
            PWM_Chanal = 11;
            break;
        case 76:
            PWM_Chanal = 12;
            break;
        case 77:
            PWM_Chanal = 13;
            break;
        case 79:
            PWM_Chanal = 14;
            break;
        case 81:
            PWM_Chanal = 15;
            break;

        default:
            printf("[ERRO][f:PianoMidiPlay]PWM_Chanal Not defined\r\n");
            PWM_Chanal = 0;
            break;
        }

        if ((midiMsg->note_type) == 1)
        {
            PWM_Duty = 0.95; // 1 cannot
        }
        else
        {
            PWM_Duty = 0;
        }

        PCA9685_PWM_Set(PWM_Chanal, PWM_Duty);

        // HAL_Delay(1000);

        // printf("[INFO][PianoMidiPlay]i:%d PWM_Chanal:%d PWM_Duty:%.1f\r\n",i,PWM_Chanal,PWM_Duty);

        // printf("[INFO][PianoMidiPlay] i:%3d note:%d PWM_NUM:%d note_type:%d  PWM_Duty:%.1f \r\n",
        //        i, midiMsg->note, PWM_Chanal, midiMsg->note_type, PWM_Duty);

        midiMsg++; // may across side
    }
    OLED_ShowString(0, 0, (uint8_t *)"Piano Play End   ", 16);
}
/**
 * @brief Piano teach midi just for lingya
 * @Total notes:13 contains
 * [57, 58, 60, 62, 64, 65, 69, 72, 74, 76, 77, 79, 81]
 * @param midiMsg
 * @param tracks_len
 */
void PianoMidiTeaching(midiMsg_t *midiMsg, uint16_t tracks_len)
{
    uint16_t i = 0;
    float PWM_Duty = 0;
    uint8_t PWM_Chanal = 0;
    float PlaySpeed = 0.1;
    uint32_t DalayTrackTime;

    OLED_ShowString(0, 0, (uint8_t *)"Piano Tech Start", 16);
    OLED_ShowString(0, 2, (uint8_t *)"Song:lingya", 16);
    OLED_ShowString(0, 4, (uint8_t *)"Key:", 16);
    OLED_ShowString(0, 6, (uint8_t *)"Time:", 16);

    // first play once
    PianoMidiPlay(midiMsg, tracks_len);
    PCA9685_TurnOffAllChannal();
    OLED_ShowString(0, 0, (uint8_t *)"Piano Tech Start", 16);

    HAL_Delay(2000);
    // second teach once
    midiMsg++;
    for (i = 1; i <= tracks_len; i++)
    {
        DalayTrackTime = (uint32_t)(midiMsg->time * 1000 / PlaySpeed);
        HAL_Delay(DalayTrackTime);

        // PWM_Duty = midiMsg->velocity / 127

        switch (midiMsg->note)
        {
        case 57:
            PWM_Chanal = 0;
            break;
        case 58:
            PWM_Chanal = 1;
            break;
        case 60:
            PWM_Chanal = 3;
            break;
        case 62:
            PWM_Chanal = 4;
            break;
        case 64:
            PWM_Chanal = 5;
            break;
        case 65:
            PWM_Chanal = 6;
            break;
        case 69:
            PWM_Chanal = 8;
            break;
        case 72:
            PWM_Chanal = 10;
            break;
        case 74:
            PWM_Chanal = 11;
            break;
        case 76:
            PWM_Chanal = 12;
            break;
        case 77:
            PWM_Chanal = 13;
            break;
        case 79:
            PWM_Chanal = 14;
            break;
        case 81:
            PWM_Chanal = 15;
            break;

        default:
            printf("[ERRO][f:PianoMidiPlay]PWM_Chanal Not defined\r\n");
            PWM_Chanal = 0;
            break;
        }

        if (midiMsg->note_type == 1)
        {
            PWM_Duty = 0.95; // 1 cannot
        }
        else
        {
            PWM_Duty = 0;
        }

        // PCA9685_PWM_Set(PWM_Chanal, PWM_Duty);
        sprintf(MCU_BSP_g_stringTemp, "Track:%2d       ", i);
        OLED_ShowString(0, 2, (uint8_t *)MCU_BSP_g_stringTemp, 16);

        sprintf(MCU_BSP_g_stringTemp, "Key:%2d sta:%d  ", PWM_Chanal, midiMsg->note_type);
        OLED_ShowString(0, 4, (uint8_t *)MCU_BSP_g_stringTemp, 16);
        sprintf(MCU_BSP_g_stringTemp, "Time:%.2f    ", (float)DalayTrackTime / 1000);
        OLED_ShowString(0, 6, (uint8_t *)MCU_BSP_g_stringTemp, 16);

        HAL_Delay(10000);

        midiMsg++; // may across side
    }

    OLED_ShowString(0, 0, (uint8_t *)"Piano Tech End", 16);
}
