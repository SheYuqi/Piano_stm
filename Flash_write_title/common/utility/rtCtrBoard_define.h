#ifndef RTCTRBOARD_DEFINE_H_
#define RTCTRBOARD_DEFINE_H_
#include <stdint.h>

/********************system define*****************************/
#define DEBUG_USART huart1 // µ÷ÊÔ´®¿Ú
#define HOST_USART huart2  // host

enum ctrBoardModuleId
{
    kModule_host = 0x01,
    kModulePiano = 0x21
};

enum boardId
{
    kHostBoardId = 0x01,
    kCtrBoardId = 0x02,
};

/******************************************************************************
********************************** ota        **********************************
******************************************************************************/

// enum{
//     IN_BOOT = 0,
//     IN_APP1,
//     IN_APP2
// }OtaLocal;

typedef struct
{
    uint8_t local;
    uint8_t flag;
    uint8_t status;
    uint8_t error_code;
} __attribute__((packed)) OtaStatus;

/******************************************************************************
**********************************hw manager   **********************************
`******************************************************************************/
typedef struct
{
    uint8_t soft_key;
    uint8_t hard_key;
} __attribute__((packed)) PowerKeyStatus;
typedef struct
{
    uint8_t work_status;
    uint8_t has_cup;
} __attribute__((packed)) CleanerStatus;

typedef struct
{
    uint8_t work_status;
    uint8_t has_cup;
} __attribute__((packed)) PickerStatus;

typedef struct
{
    uint8_t has_rubbish;
    uint8_t has_cup;
} __attribute__((packed)) DetectorStatus;

#endif // SENSORBOARD_DEFINE_H
