#define NOTE_FS6 90
#define NOTE_G6  91

typedef enum {
  Flute = 74,
  Recorder,
  PanFlute,
  BlownBottle,
  Shakuhachi,
  Whistle,
  Ocarina,
  Lead1Square
} instrument_t;

typedef union {
  uint16_t w;
  struct {
    uint8_t lo: 4;
    uint8_t hi: 4;
    uint8_t up: 4;
  } nib;
} nibble_t;

#define MIDI_BAUD 31250
#define MIDI_CMD_NOTE_ON  0x90
#define MIDI_CMD_NOTE_OFF 0x80
#define MIDI_CMD_PROG_CHANGE  0xc0
#define MIDI_CMD_CTRL_CHANGE  0xb0
#define MIDI_CMD_SYS_EX       0xf0
#define MIDI_CMD_SYS_RESET    0xff
#define MIDI_CMD_END_SYS_EX   0xf7
#define MIDI_CTRL_ALL_NOTES_OFF  123
#define MIDI_RPN_MSB      0x65
#define MIDI_RPN_LSB      0x64
#define MIDI_NRPN_MSB     0x63
#define MIDI_NRPN_LSB     0x62
#define MIDI_DE_MSB       0x06
#define MIDI_DE_LSB       0x26
#define MIDI_CC_BANK_MSB  0x0
#define MIDI_CC_BANK_LSB  0x20
#define MIDI_CC_VOL       0x07
#define MIDI_CC_REB_LVL   0x5b
#define MIDI_CC_REB_PROG  0x50
#define MIDI_CC_CHOR_LVL  0x5d
#define MIDI_CC_CHOR_PROG 0x51

// variation # (== (bank # - 1) )
#define N_A             0
#define L1S_SquareWave  0
#define L1S_Square      1
#define L1S_SineWave    8

#define NOTE_ON  0x90

const uint8_t GS_Reset[]  = {0x41, 0x00, 0x42, 0x12,    0x40, 0x00, 0x7f,   0x00,                     0x41};

void sendProgramChange(instrument_t progNum, uint8_t ch = 1);
void sendControlChange(uint8_t ctrlNum, uint8_t ctrlVal, uint8_t ch = 1);
void sendNoteOn(uint8_t noteNum, uint8_t veloc, uint8_t ch = 1);
void sendNoteOff(uint8_t noteNum, uint8_t veloc, uint8_t ch = 1);
void sendSysEx(uint8_t len, const uint8_t* bp, bool wrtBeginEnd = true);
void setAllNotesOff(uint8_t ch = 1);
void beginNRPN(uint16_t nrpn, uint8_t ch = 1);
void endNRPN(uint8_t ch = 1);
void beginRPN(uint16_t rpn, uint8_t ch = 1);
void sendRPNValue (uint8_t msb, uint8_t lsb, uint8_t ch = 1);
void sendRPNValue (uint16_t val, uint8_t ch = 1);
void endRPN(uint8_t ch = 1);
void sendGSReset();
void sendSysReset();
void setTVF(uint8_t cutOff, uint8_t resonance, uint8_t ch = 1);
void setEnvelope(uint8_t attack, uint8_t decay, uint8_t release, uint8_t ch = 1);
void setInstrument(instrument_t inst, uint8_t variation, uint8_t ch = 1);
void setVolume(uint8_t vol, uint8_t ch = 1);
void setTuning(uint16_t fine, uint8_t coarse, uint8_t ch = 1);
void setReverb(uint8_t level, uint8_t program = 4, uint8_t ch = 1);
void setChorus(uint8_t level, uint8_t program = 2, uint8_t ch = 1);