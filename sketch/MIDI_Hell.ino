//#define DEBUG

#include "config.h"
#include "MIDI.h"
#include "Hell.h"
#include "fonts_def.h"
#include "font_map.h"
#include <CommandParser.h>

typedef CommandParser<> MyCommandParser;
MyCommandParser parser;

//MIDI_CREATE_INSTANCE(Serial1);
MIDI_CREATE_INSTANCE(SERIAL_OBJ);

//char Msg1[] = "DUV/1i";
//char Msg2[] = "VVV DE JA1UMI/1";
//char *MsgList[] = {Msg1, Msg2};
//
//typedef enum  {
//  Test = 0,
//  Callsign1
//} msgsel_t;
//
void setup() {
//  #if defined(DEBUG)
  Serial.begin(9600);
  while(!Serial) {
    delay(10);
  }
//  #endif
//  parser.registerCommand("TEST", "sdiu", &cmd_test);
//  Serial.println("registered command: TEST <string> <double> <int64> <uint64>");
//  Serial.println("example: TEST \"\\x41bc\\ndef\" -1.234e5 -123 123");
  parser.registerCommand("hell", "ss", &hell);

  MIDI.begin(MIDI_BAUD);
  prepareForHell();
  Serial.println("\n\n== Multi-tone Hellschreiber signal generator ==\n\n");
}

void loop() {
  SendHellMsg(readMode(), readMsgSel());
////  SendHellMsg(SMTHELL, Test);
////  SendHellMsg(CMTHELL, Test);
////  SendHellMsg(CHIRP, Test);
////  SendHellMsg(CHIRP_DBL, Test);
  delay(3 * COL_LEN);
}

//hellmode_t readModeSW() {
//  return (CHIRP);
//}
//
//msgsel_t readMsgSelSW() {
//  return (Test);
//}
//
void SendHellMsg(hellmode_t mode, msgsel_t sel) {
  char *str = MsgList[sel];
  while (*str) {
    commandPolling();
    switch(mode) {
      case CHIRP:
        sendSMTHellChar2(HellFont[toupper(*str) - ' ']);
        break;
      case CHIRP_DBL:
        sendChirpHellChar(HellFont[toupper(*str) - ' '], true);
        break;
      case CMTHELL:
        sendCMTHellChar(HellFont[toupper(*str) - ' ']);
        break;
      case SMTHELL:
        sendSMTHellChar(HellFont[toupper(*str) - ' ']);
        break;
      default:
        break;
    }
    str++;
  }
}

void commandPolling() {
  char line[128];
  char response[MyCommandParser::MAX_RESPONSE_SIZE];
  size_t lineLength;

  if (Serial.available()) {
    lineLength = Serial.readBytesUntil('\n', line, 127);
    line[lineLength] = '\0';
    parser.processCommand(line, response);
    Serial.println(response);
  }
}

void hell(MyCommandParser::Argument *args, char *response) {
  char mode[40], tag[15];
//  Serial.print("string: "); Serial.println(args[0].asString);
//  Serial.print("string: "); Serial.println(args[1].asString);
//  Serial.print("uint64: "); Serial.println((uint32_t)args[1].asUInt64); // NOTE: on older AVR-based boards, Serial doesn't support printing 64-bit values, so we'll cast it down to 32-bit
//  strlcpy(response, "success", MyCommandParser::MAX_RESPONSE_SIZE);
  if (strstr(args[1].asString, "help") != NULL) {
    help();
  } else {
    if (!strcmp(args[0].asString, "mode")) {
      switch(atoi(args[1].asString)) {
        case 0:
          HellMode = CHIRP;
          break;
        case 1:
          HellMode = CHIRP_DBL;
          break;
        case 2:
          HellMode = CMTHELL;
          break;
        case 3:
          HellMode = SMTHELL;
          break;
        default:
          break;
      }
    } else if (!strcmp(args[0].asString, "msg")) {
      switch (atoi(args[1].asString)) {
        case 0:
          MsgSelector = Test;
          break;
        case 1:
          MsgSelector = Callsign1;
          break;
        case 2:
          MsgSelector = Callsign2;
          break;
        default:
          break;
      } // end switch
    } else {
        help();
    } // end else 
  } //end else

  switch(HellMode) {
    case CHIRP:
      strlcpy(mode, "Chirp Hell", 40);
      break;
    case CHIRP_DBL:
      strlcpy(mode, "Chirp Hell (Double-Column mode)", 40);
      break;
    case CMTHELL:
      strlcpy(mode, "Concurrent Multi-Tone Hell", 40);
      break;
    case SMTHELL:
      strlcpy(mode, "Sequential Multi-Tone Hell", 40);
      break;
    default:
      break;
  }
  switch(MsgSelector) {
    case Test:
      strlcpy(tag, "Test", 15);
      break;
    case Callsign1:
      strlcpy(tag, "CallSign1", 15);
      break;
    case Callsign2:
      strlcpy(tag, "CallSign2", 15);
      break;
    default:
      break;
    }
  snprintf(response, MyCommandParser::MAX_RESPONSE_SIZE, "mode %d:%s, msg#%d: %s", HellMode, mode, MsgSelector, tag);
}

void help() {
    Serial.println("hell mode ([0123] | help)");
    Serial.println("=========================");
    Serial.println("0:Chirp, 1:Chirp (double-column), 2: CMT, 3: SMT");
    Serial.println("help: Show this message.\n");
    Serial.println("hell msg ([012] | help)");
    Serial.println("=========================");
    Serial.println("0: Test, 1: Call Sign 1, 2: Call Sign 2");
    Serial.println("help: Show this message.\n");
//    strlcpy(response, "success", MyCommandParser::MAX_RESPONSE_SIZE);
}