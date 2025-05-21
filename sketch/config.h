// sound module type
// uncomment only one line at a time
#define SAM2695
//#define GS
//#define ROLAND
//#define YAMAHA

// Serial1 on NUCLEO32 board reconfigured; D1 (PA_9) for TxD,  D0 (PA_10) for RxD
// uncomment only one line at a time
#define SERIAL_OBJ  Serial1stm
//#define SERIAL_OBJ  Serial1

#if defined(ARDUINO_ARCH_STM32)
//  #warning "ARDUINO_ARCH_STM32 defined"
  HardwareSerial Serial1stm(PA_10, PA_9);
  #define MIDI_CREATE_INSTANCE(obj)  HardwareSerial &MIDI = obj
#else
  #define MIDI_CREATE_INSTANCE(obj)  HardwareSerial &MIDI = obj
#endif

//char Msg1[] = "DUV/1i";
char Msg1[] = "Y.KASUMI";
char Msg2[] = "VVV DE JA1UMI/1 K";
char Msg3[] = "CQ DE AE6TF K";
char *MsgList[] = {Msg1, Msg2, Msg3};

typedef enum  {
  Test = 0,
  Callsign1,
  Callsign2
} msgsel_t;

