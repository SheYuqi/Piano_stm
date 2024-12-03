
#ifndef APP_PIANO_H_
#define APP_PIANO_H_

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#include "main.h"
#include "MCU_BSP.h"
#include "app_piano_cmd.h"
#include "usart.h"
#define RX_MIDI_LEN 6
#define NOTE_TYPE 0
#define CHANNEL 1
#define NOTE 2
#define VELOCITY 3
#define TIME_LOW 4
#define TIME_HIGH 5
#define START_NOTE 21
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
extern uint8_t midi_buf[RX_MIDI_LEN]; 
/**
 * @brief function declare
 * 
 */
void processReceivedData();

void PianoPlayInit(void);
void PianoPlayTest(void);
void PianoMidiPlay(midiMsg_t *midiMsg,uint16_t tracks_len);
void PianoMidiTeaching(midiMsg_t *midiMsg,uint16_t tracks_len);
void PianoPlayTest_DB(uint32_t PeriodTimems,uint8_t Times);

uint32_t HexToDec(uint8_t a);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif

