void sendChirpHellChar(const uint8_t* d, bool dblColEnable) {
  sendSMTHellChar2(d, dblColEnable);
}

void sendSMTHellChar(const uint8_t* d) {
  #if defined(DEBUG)
    char buf[40];
    Serial.println();
  #endif
  while (*d != EOD) {
    #if defined(DEBUG)
        sprintf(buf, "data=0x%0x", *d);
        Serial.println(buf);
    #endif
    switch ( *d ) {
      case SET_DIV:
        *(++d);
        break;
      case BGN_COL:
      case END_COL:
        break;

      case SKIP_COL:
        delay(COL_LEN);
        break;

      default:
        if (*d >= MAX_ROWS)
          break;        // for safety
////        sendSysEx(MIDI_Master_Tune, RowTone[*d]);
        setTuning(ChRowTone[*d], 0x40, (*d)+2);
        sendNoteOn(NOTE_G6, VEL_FAST, (*d)+2);
        delay(COL_LEN / 2);
        sendNoteOff(NOTE_G6, VEL_FULL, (*d)+2);
        #if defined(COL_GAP)
            delay(COL_GAP);           // intentional additional spacing between columns
        #endif
        break;
    }
    d++;
  }
  #if defined(DEBUG)
    Serial.println();
  #endif
  delay(COL_LEN);   // one column space between letters
}   // end of sendSMTHellChar()

void sendSMTHellChar2(const uint8_t* d, bool dblColEnable) {
  uint8_t litPixels = 1, cnt = 1;
  uint32_t duration;
  const uint8_t *saved_ptr;
  #if defined(DEBUG)
    char buf[40];
    Serial.println();
  #endif
  while (*d != EOD) {
    #if defined(DEBUG)
        sprintf(buf, "data=0x%0x, div=%d", *d, litPixels);
        Serial.println(buf);
    #endif
    switch ( *d ) {
      case SET_DIV:
        litPixels = *(++d);
        break;

      case BGN_COL:
        saved_ptr = d + 1;
        cnt = 2;
        break;

      case END_COL:
        if (dblColEnable) {
          if (--cnt)
            d = saved_ptr;
        }
        break;

      case SKIP_COL:
        delay(COL_LEN);
        break;

      default:
        if (*d >= MAX_ROWS)
          break;        // for safety
////        sendSysEx(MIDI_Master_Tune, RowTone[*d]);
        setTuning(ChRowTone[*d], 0x40, (*d)+2);
        sendNoteOn(NOTE_G6, VCV[litPixels - 1], (*d)+2);
        if (litPixels > 1)
          duration = (uint32_t) ((COL_LEN / litPixels) * DCF);
        else
          duration = COL_LEN / litPixels;

        if (dblColEnable) {         // double-column mode
          duration = (uint32_t) (duration * 0.8f);
        }
        delay(duration);
        sendNoteOff(NOTE_G6, VEL_FULL, (*d)+2);
        #if defined(COL_GAP)
            delay(COL_GAP);           // intentional additional spacing between columns
        #endif
        break;
    }
    d++;
  }
  #if defined(DEBUG)
    Serial.println();
  #endif
  delay(COL_LEN);   // one column space between letters
}   // end of sendSMTHellChar2()

void sendCMTHellChar(const uint8_t* d) {
//#if defined(ROLAND)
  uint8_t litPixels = 1;
  uint8_t row;
  #if defined(DEBUG)
    char buf[40];
    Serial.println();
  #endif
  for (row = 0; row < MAX_ROWS; row++) {
    setTuning(ChRowTone[row], 0x40, row+2);
//    setVolume(CMT_VEL, row+2);
  }
  while (*d != EOD) {
    #if defined(DEBUG)
        sprintf(buf, "data=0x%0x", *d);
        Serial.println(buf);
    #endif
    switch ( *d ) {
      case SET_DIV:
        litPixels = *(++d);
        break;

      case BGN_COL:
        break;

      case END_COL:
        delay(COL_LEN);
        for (row = 2; row < (2+MAX_ROWS); row++)
          sendNoteOff(NOTE_G6, VEL_FULL, row);

        #if defined(SAM2695) && defined(COL_GAP)
          delay(COL_GAP);
        #endif

        break;

      case SKIP_COL:
        delay(COL_LEN);
        break;

      default:
        if (*d >= MAX_ROWS)
          break;    // for safety
        sendNoteOn(NOTE_G6, VCV[litPixels - 1], (*d) + 2);
        #if defined(CMT_SUSTAIN)
            delay(CMT_SUSTAIN);
        #endif

        break;
    }
    d++;
  }
  #if defined(DEBUG)
    Serial.println();
  #endif
  delay(COL_LEN);   // one column space between letters
}   // end of sendCMTHellChar

void prepareForHell() {
  uint8_t ch;

  sendSysReset();
  delay(100);
  for (ch = 1; ch < (MAX_ROWS + 2); ch++) {
    #if defined(ROLAND)
      setInstrument(Lead1Square, L1S_SineWave, ch);
    #else
      sendProgramChange(Lead1Square, ch);
      setTVF(-48 + 0x40, -48 + 0x40, ch);
      setEnvelope(4 + 0x40, 63 + 0x40, 4 + 0x40, ch);
      setReverb(80, 4, ch);   // default level = 40
////      setChorus(20, 2, ch);   // default level = 0
      setVolume(110, ch);
    #endif
  }
}
