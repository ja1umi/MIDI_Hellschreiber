// column rate (millisenconds per column)
#define COL_LEN   2000
// maximul number of rows
#define MAX_ROWS  7
// delay correction factor
#define DCF       1.5f
// set the gap between columns (milliseconds)
// if column gapping is not necessary, comment it out
#define COL_GAP   10
// set the sustain time (milliseconds)
// for CMT-Hell only
#define CMT_SUSTAIN 5
// additional delay correction factor for double-column mode
#define DCF_DBL   0.8f

// draw commmands
#define SET_DIV   0x80
#define SKIP_COL  0x82
#define BGN_COL   0x83
#define END_COL   0x84
// end of data
#define EOD       0xff

#define VEL_FULL  0x7f
#define VEL_FAST  100
#define VEL_MID   90
#define VEL_SLOW  70

typedef enum {
  CHIRP,
  CHIRP_DBL,
  CMTHELL,
  SMTHELL
} hellmode_t;

#if defined(SAM2695)
  const uint16_t ChRowTone[] = {0x1600, 0x1700, 0x1800, 0x1900, 0x1a00, 0x1b00, 0x1c00};
//  const uint16_t ChRowTone[] = {0x1600, 0x1700, 0x1800, 0x1a00, 0x1b00, 0x1c00, 0x1e00};
#else
  const uint16_t ChRowTone[] = {0x167e, 0x175b, 0x1849, 0x191e, 0x1975, 0x1a52, 0x1b30};
#endif

#define readMode()  (HellMode)
#define readMsgSel()  (MsgSelector)

hellmode_t HellMode = CHIRP;
msgsel_t MsgSelector = Test;

const uint8_t VCV[] = {100, 107, 114, 119, 123, 126, 127};  // Velocity Correction Value (cosine-based)
bool noteOnDetected = false;

void sendChirpHellChar(const uint8_t* d, bool dblColEnable = false);
void sendSMTHellChar(const uint8_t* d);
void sendSMTHellChar2(const uint8_t* d, bool dblColEnable = false);
void sendCMTHellChar(const uint8_t* d);
void prepareForHell();
