
#ifndef APP_PIANO_H_
#define APP_PIANO_H_

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#include "main.h"
#include "MCU_BSP.h"
#include "app_piano_cmd.h"

/**
 * @brief typedef
 * 
 */

typedef struct
{
    uint16_t track;
    uint8_t note_type;
    uint8_t channel;
    uint8_t note;
    uint8_t velocity;
    float time;
} midiMsg_t;

/**
 * @brief variable extern
 * 
 */

extern midiMsg_t midiMsg_lingya[101];

/**
 * @brief function declare
 * 
 */

void PianoPlayInit(void);
void PianoPlayTest(void);
void PianoMidiPlay(midiMsg_t *midiMsg,uint16_t tracks_len);
void PianoMidiTeaching(midiMsg_t *midiMsg,uint16_t tracks_len);
void PianoPlayTest_DB(uint32_t PeriodTimems,uint8_t Times);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif

