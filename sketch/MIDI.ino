//#include "MIDI.h"

void sendNoteOn(uint8_t noteNum, uint8_t veloc, uint8_t ch) {
  MIDI.write(MIDI_CMD_NOTE_ON | ((ch - 1) & 0xf) );
  MIDI.write(noteNum & 0x7f);
  MIDI.write(veloc & 0x7f) ;
}

void sendNoteOff(uint8_t noteNum, uint8_t veloc, uint8_t ch) {
  MIDI.write(MIDI_CMD_NOTE_OFF | ((ch - 1) & 0xf) );
  MIDI.write(noteNum & 0x7f);
  MIDI.write(veloc & 0x7f);
}

void sendProgramChange(instrument_t inst, uint8_t ch) {
  MIDI.write(MIDI_CMD_PROG_CHANGE | ((ch - 1) & 0xf) );
  MIDI.write(inst - 1);
}

void sendControlChange(uint8_t ctrlNum, uint8_t ctrlVal, uint8_t ch) {
  MIDI.write(MIDI_CMD_CTRL_CHANGE | ((ch - 1) & 0xf) );
  MIDI.write(ctrlNum);
  MIDI.write(ctrlVal);
}

void sendSysEx(uint8_t len, const uint8_t* bp, bool wrtBeginEnd) {
  if (wrtBeginEnd)
    MIDI.write(MIDI_CMD_SYS_EX);

  MIDI.write(bp, len);

  if (wrtBeginEnd)
    MIDI.write(MIDI_CMD_END_SYS_EX); 
}

void setAllNotesOff(uint8_t ch) {
  sendControlChange(MIDI_CTRL_ALL_NOTES_OFF, 0, ch);  
}

void sendGSReset() {
  sendSysEx(sizeof(GS_Reset), GS_Reset);
  delay(100);
}

void sendSysReset() {
  MIDI.write(MIDI_CMD_SYS_RESET);
}

void beginRPN(uint16_t rpn, uint8_t ch) {
  uint8_t msb = (rpn >> 8) & 0x7f;
  uint8_t lsb = rpn & 0x7f;
  sendControlChange(MIDI_RPN_MSB, msb, ch);
  sendControlChange(MIDI_RPN_LSB, lsb, ch);
}

void beginNRPN(uint16_t nrpn, uint8_t ch) {
  uint8_t msb = (nrpn >> 8) & 0x7f;
  uint8_t lsb = nrpn & 0x7f;
  sendControlChange(MIDI_NRPN_MSB, msb, ch);
  sendControlChange(MIDI_NRPN_LSB, lsb, ch);
}

void sendRPNValue (uint8_t msb, uint8_t lsb, uint8_t ch) {
  sendControlChange(MIDI_DE_MSB, msb, ch);
  sendControlChange(MIDI_DE_LSB, lsb, ch);
}

void sendRPNValue (uint16_t val, uint8_t ch) {
  sendControlChange(MIDI_DE_MSB, (val >> 8) & 0x7f, ch);
  sendControlChange(MIDI_DE_LSB, val & 0x7f, ch);
}

void endRPN(uint8_t ch) {
  sendControlChange(MIDI_RPN_MSB, 0x7f, ch);
  sendControlChange(MIDI_RPN_LSB, 0x7f, ch);
}

void endNRPN(uint8_t ch) {
  sendControlChange(MIDI_NRPN_MSB, 0x7f, ch);
  sendControlChange(MIDI_NRPN_LSB, 0x7f, ch);
}

void setTVF(uint8_t cutOff, uint8_t resonance, uint8_t ch) {
  beginNRPN(0x0120, ch);
  MIDI.write(MIDI_DE_MSB);
  MIDI.write(cutOff & 0x7f);
  beginNRPN(0x0121, ch);
  MIDI.write(MIDI_DE_MSB);
  MIDI.write(resonance & 0x7f);
  endNRPN(ch);
}

void setEnvelope(uint8_t attack, uint8_t decay, uint8_t release, uint8_t ch) {
  beginNRPN(0x0163, ch);
  MIDI.write(MIDI_DE_MSB);
  MIDI.write(attack & 0x7f);
  beginNRPN(0x0164, ch);
  MIDI.write(MIDI_DE_MSB);
  MIDI.write(decay & 0x7f);
  beginNRPN(0x0166, ch);
  MIDI.write(MIDI_DE_MSB);
  MIDI.write(release & 0x7f);
  endNRPN(ch);
}

void setInstrument(instrument_t inst, uint8_t variation, uint8_t ch) {
  // remember that variation number == (bank number - 1)
  sendControlChange(0, variation & 0x7f, ch);
  sendControlChange(0x20, 0, ch);
  sendProgramChange(inst, ch);
}

void setVolume(uint8_t vol, uint8_t ch) {
  sendControlChange(0x07, vol & 0x7f, ch);
}

void setReverb(uint8_t level, uint8_t program, uint8_t ch) {
  #if defined(SAM2695)
    sendControlChange(MIDI_CC_REB_PROG, program & 0x7, ch);
  #endif
  sendControlChange(MIDI_CC_REB_LVL, level & 0x7f, ch);
}

void setChorus(uint8_t level, uint8_t program, uint8_t ch) {
  #if defined(SAM2695)
    sendControlChange(MIDI_CC_CHOR_PROG, program & 0x7, ch);
  #endif
  sendControlChange(MIDI_CC_CHOR_LVL, level & 0x7f, ch);
}

void setTuning(uint16_t fine, uint8_t coarse, uint8_t ch) {
  beginRPN(1, ch);
  sendRPNValue(fine, ch);
  beginRPN(2, ch);
  sendRPNValue(coarse, 0, ch);
  endRPN(ch);
}
