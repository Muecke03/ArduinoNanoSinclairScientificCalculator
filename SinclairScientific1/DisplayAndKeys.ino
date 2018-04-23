// Arduino Port of
//
// TI calculator simulator
// Ken Shirriff, http://righto.com/ti
// Based on patent US3934233
//
// The goal of this project is to run the following simulator: http://righto.com/sinclair
// on an arduino nano powered custom pcb resembling the original Sinclair Scientific Calculator
// @arduinoenigma 2018
//
// tedious but fast, most lines compile to 1 instruction.
// this whole file compiles to less than 1KB of code
//

GPIO<BOARD::D14> KeyRowB;
GPIO<BOARD::D15> KeyRowC;
GPIO<BOARD::D16> KeyRowA;

GPIO<BOARD::D2> SegmentA;
GPIO<BOARD::D5> SegmentB;
GPIO<BOARD::D9> SegmentC;
GPIO<BOARD::D7> SegmentD;
GPIO<BOARD::D4> SegmentE;
GPIO<BOARD::D3> SegmentF;
GPIO<BOARD::D8> SegmentG;
GPIO<BOARD::D6> SegmentDP;

GPIO<BOARD::D1>  Digit1;
GPIO<BOARD::D0>  Digit2;
GPIO<BOARD::D19> Digit3;
GPIO<BOARD::D18> Digit4;
GPIO<BOARD::D17> Digit5;
GPIO<BOARD::D13> Digit6;
GPIO<BOARD::D10> Digit7;
GPIO<BOARD::D11> Digit8;
GPIO<BOARD::D12> Digit9;

void allSegmentOutput() {
  SegmentA.output();
  SegmentB.output();
  SegmentC.output();
  SegmentD.output();
  SegmentE.output();
  SegmentF.output();
  SegmentG.output();
  SegmentDP.output();
}

void allSegmentOff() {
  SegmentA.high();
  SegmentB.high();
  SegmentC.high();
  SegmentD.high();
  SegmentE.high();
  SegmentF.high();
  SegmentG.high();
  SegmentDP.high();
}

void allSegmentInput() {
  SegmentA.input();
  SegmentB.input();
  SegmentC.input();
  SegmentD.input();
  SegmentE.input();
  SegmentF.input();
  SegmentG.input();
  SegmentDP.input();

  SegmentA.high();
  SegmentB.high();
  SegmentC.high();
  SegmentD.high();
  SegmentE.high();
  SegmentF.high();
  SegmentG.high();
  SegmentDP.high();
}

void allDigitOutput() {
  Digit1.output();
  Digit2.output();
  Digit3.output();
  Digit4.output();
  Digit5.output();
  Digit6.output();
  Digit7.output();
  Digit8.output();
  Digit9.output();
}

void allDigitOff() {
  Digit1.low();
  Digit2.low();
  Digit3.low();
  Digit4.low();
  Digit5.low();
  Digit6.low();
  Digit7.low();
  Digit8.low();
  Digit9.low();
}

void allKeyRowOff() {
  KeyRowA.input();
  KeyRowB.input();
  KeyRowC.input();

  KeyRowA.low();
  KeyRowB.low();
  KeyRowC.low();
}

void allKeyRowIdle() {
  KeyRowA.output();
  KeyRowB.output();
  KeyRowC.output();

  KeyRowA.high();
  KeyRowB.high();
  KeyRowC.high();
}

byte outputDigit(signed char digit, bool decimalpoint = false) {

  byte segmentslit = 0;

  allDigitOff();

  if (decimalpoint)
  {
    segmentslit++;
    SegmentDP.low();
  }
  else
  {
    SegmentDP.high();
  }

  switch (digit) {
    case 0:
      SegmentA.low();
      SegmentB.low();
      SegmentC.low();
      SegmentD.low();
      SegmentE.low();
      SegmentF.low();
      SegmentG.high();
      segmentslit += 6;
      break;
    case 1:
      SegmentA.high();
      SegmentB.low();
      SegmentC.low();
      SegmentD.high();
      SegmentE.high();
      SegmentF.high();
      SegmentG.high();
      segmentslit += 2;
      break;
    case 2:
      SegmentA.low();
      SegmentB.low();
      SegmentC.high();
      SegmentD.low();
      SegmentE.low();
      SegmentF.high();
      SegmentG.low();
      segmentslit += 5;
      break;
    case 3:
      SegmentA.low();
      SegmentB.low();
      SegmentC.low();
      SegmentD.low();
      SegmentE.high();
      SegmentF.high();
      SegmentG.low();
      segmentslit += 5;
      break;
    case 4:
      SegmentA.high();
      SegmentB.low();
      SegmentC.low();
      SegmentD.high();
      SegmentE.high();
      SegmentF.low();
      SegmentG.low();
      segmentslit += 4;
      break;
    case 5:
      SegmentA.low();
      SegmentB.high();
      SegmentC.low();
      SegmentD.low();
      SegmentE.high();
      SegmentF.low();
      SegmentG.low();
      segmentslit += 5;
      break;
    case 6:
      SegmentA.low();
      SegmentB.high();
      SegmentC.low();
      SegmentD.low();
      SegmentE.low();
      SegmentF.low();
      SegmentG.low();
      segmentslit += 6;
      break;
    case 7:
      SegmentA.low();
      SegmentB.low();
      SegmentC.low();
      SegmentD.high();
      SegmentE.high();
      SegmentF.high();
      SegmentG.high();
      segmentslit += 3;
      break;
    case 8:
      SegmentA.low();
      SegmentB.low();
      SegmentC.low();
      SegmentD.low();
      SegmentE.low();
      SegmentF.low();
      SegmentG.low();
      segmentslit += 7;
      break;
    case 9:
      SegmentA.low();
      SegmentB.low();
      SegmentC.low();
      SegmentD.high();
      SegmentE.high();
      SegmentF.low();
      SegmentG.low();
      break;
      segmentslit += 5;
    case 10:
      SegmentA.high();
      SegmentB.high();
      SegmentC.high();
      SegmentD.high();
      SegmentE.high();
      SegmentF.high();
      SegmentG.low();
      segmentslit += 1;
      break;
    case 99:
      SegmentA.high();
      SegmentB.high();
      SegmentC.high();
      SegmentD.high();
      SegmentE.high();
      SegmentF.high();
      SegmentG.high();
      break;
    default:
      allSegmentOff();
      break;
  }

  return segmentslit;
}

void selectDigit(byte digit) {

  allDigitOff();

  switch (digit) {
    case 0:
      Digit1.high();
      break;
    case 1:
      Digit2.high();
      break;
    case 2:
      Digit3.high();
      break;
    case 3:
      Digit4.high();
      break;
    case 4:
      Digit5.high();
      break;
    case 5:
      Digit6.high();
      break;
    case 6:
      Digit7.high();
      break;
    case 7:
      Digit8.high();
      break;
    case 8:
      Digit9.high();
      break;
  }
}

// this function is called by the display routines to show a digit for 2ms before moving to the next one.
// can do useful work here... instead of delay();

void backgroundWork() {

}

void display() {

  bool dp = false;

  for (byte i = 0; i < 9; i++) {

    //SINCLAIR behavior: turn decimal point on automatically at fixed position
    if (i == 1) {
      dp = true;
    }
    else
    {
      dp = false;
    }

    outputDigit(digits[i], dp);
    selectDigit(i);

    backgroundWork();
  }
}


void displaySelfTest(bool longtest = false) {

  char c = 0;

  //kitt stuff
  byte pos = 0;
  byte p1 = 0;
  byte p2 = 0;
  char sign = 0;

  bool kitt = false;

  // show 8.8.8.8.8.8.8.8.8.
  for (byte t = 0; t < 75; t++) {
    for (byte j = 0; j < 9; j++) {
      c = readKey();
      if (c == '8') {
        longtest = true;
      }
      if ((longtest == true ) && (c == '2')) {
        kitt = true;
      }
      if (c == 'C') {
        goto exitfn;
      }
      outputDigit(8, true);
      selectDigit(j);
      delay(2);
    }
  }

  if (kitt) {
    goto kitt;
  }

  if (!longtest) {
    goto exitfn;
  }

  // cycle through 0..9 - on all digits at the same time
  for (byte i = 0; i < 12; i++) {
    for (byte t = 0; t < 100; t++) {
      for (byte j = 0; j < 9; j++) {
        if (readKey() == 'C') {
          goto exitfn;
        }
        outputDigit((i != 11) ? i : 99, (i == 11));
        selectDigit(j);
        delay(2);
      }
    }
  }

  // show 12345678
  for (byte t = 0; t < 100; t++) {
    for (byte j = 0; j < 9; j++) {
      if (readKey() == 'C') {
        goto exitfn;
      }
      outputDigit(j, false);
      selectDigit(j);
      delay(2);
    }
  }

  // move the dot from left to right on 12345678
  for (byte i = 0; i < 9; i++) {
    for (byte t = 0; t < 100; t++) {
      for (byte j = 0; j < 9; j++) {
        if (readKey() == 'C') {
          goto exitfn;
        }
        outputDigit(j, i == j);
        selectDigit(j);
        delay(2);
      }
    }
  }

  // move dot from right to left on blank display
  for (byte j = 9; j > 0; j--) {
    for (byte t = 0; t < 100; t++) {
      for (byte i = 0; i < 9; i++) {
        if (readKey() == 'C') {
          goto exitfn;
        }
        outputDigit(99, i == (j - 1));
        selectDigit(i);
        delay(2);
      }
    }
  }

  // cycle through 0..9 - on each digit individually
  for (byte j = 0; j < 9; j++) {
    for (byte i = 0; i < 12; i++) {
      for (byte t = 0; t < 20; t++) {
        for (byte k = 0; k < 9; k++) {
          if (readKey() == 'C') {
            goto exitfn;
          }
          outputDigit( ((k == j) && (i != 11)) ? i : 99, ((k == j) && (i == 11)));
          selectDigit(k);
          delay(2);
        }
      }
    }
  }

  goto exitfn;

kitt:

  for (byte i = 0; i < 249; i++)
  {
    p2 = p1;
    p1 = pos;
    pos += sign;

    if (pos == 0) {
      sign = 1;
    }

    if (pos == 8) {
      sign = -1;
    }

    for (byte t = 0; t < 25; t++) {
      for (byte j = 0; j < 9; j++) {
        c = readKey();
        if (c == 'C') {
          goto exitfn;
        }
        outputDigit(10, false);
        selectDigit(j);
        if (j == pos)
        {
          delayMicroseconds(1000);
        } else if (j == p1)
        {
          delayMicroseconds(500);
        } else if (j == p2)
        {
          delayMicroseconds(100);
        } else
          delayMicroseconds(20);
      }
    }
  }

exitfn:
  allSegmentOff();
  allDigitOff();
}


const char PrintableKeys[19] = "12+E0v-378X654/9^C";

byte readKey() {

  byte key = 0;

  allDigitOff();
  allSegmentInput();

  for (byte i = 0; i < 3; i++)
  {
    allKeyRowIdle();
    switch (i) {
      case 0:
        KeyRowA.low();
        delayMicroseconds(2); //for reliability on first read instruction, allow for .low on line before to settle
        if (!SegmentA.read()) key = 1;
        if (!SegmentB.read()) key = 2;
        if (!SegmentC.read()) key = 3;
        if (!SegmentD.read()) key = 4;
        if (!SegmentE.read()) key = 5;
        if (!SegmentF.read()) key = 6;
        if (!SegmentG.read()) key = 7;
        if (!SegmentDP.read()) key = 8;
        break;
      case 1:
        KeyRowB.low();
        delayMicroseconds(2);
        if (!SegmentA.read()) key = 9;
        if (!SegmentB.read()) key = 10;
        if (!SegmentC.read()) key = 11;
        if (!SegmentD.read()) key = 12;
        if (!SegmentE.read()) key = 13;
        if (!SegmentF.read()) key = 14;
        if (!SegmentG.read()) key = 15;
        if (!SegmentDP.read()) key = 16;
        break;
      case 2:
        KeyRowC.low();
        delayMicroseconds(2);
        if (!SegmentA.read()) key = 17;
        if (!SegmentB.read()) key = 18;
        break;
    }
  }

  allKeyRowOff();
  allSegmentOutput();

  if (key)
  {
    key = PrintableKeys[key - 1];
  }

  return key;
}
