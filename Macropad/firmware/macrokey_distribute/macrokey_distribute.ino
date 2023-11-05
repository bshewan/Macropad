/*
    Toby's Low Cost Macro Keyboard
*/

#ifndef USER_USB_RAM
#error "Require USB RAM. Go Tools > USB Setting and pick the 2nd option in the dropdown list"
#endif

#include "src/userUsbHidMediaKeyboard/USBHIDMediaKeyboard.h"
#include "src/neo.h"
#include "src/system.h"
#include "win-zh_util.h"

////////////// HARDWARE CONFIG //////////

//Button (Mechnical, left to right)
#define BTN_1 11
#define BTN_2 17
#define BTN_3 16
#define BTN_4 33

///////////////// RUNTIME ///////////////
//Previous button states
bool bt1ActiveState = false;
bool bt2ActiveState = false;
bool bt3ActiveState = false;
bool bt4ActiveState = false;

//Current button states
bool bt1Active = false;
bool bt2Active = false;
bool bt3Active = false;
bool bt4Active = false;

void setup() {
  USBInit();
  NEO_init();
  CLK_config();                                   // configure system clock
  DLY_ms(10);                                     // wait for clock to settle
  NEO_clearAll();                                 // clear NeoPixels
  NEO_sendByte(0);
  NEO_sendByte(127);
  NEO_sendByte(0);
  NEO_sendByte(0);
  NEO_sendByte(127);
  NEO_sendByte(0);
  NEO_sendByte(0);
  NEO_sendByte(127);
  NEO_sendByte(0);
}

void loop() {
  //Read the button states, default PULL HIGH (aka LOW Activate)
  bt1Active = !digitalRead(BTN_1);
  bt2Active = !digitalRead(BTN_2);
  bt3Active = !digitalRead(BTN_3);
  bt4Active = !digitalRead(BTN_4);

  //Button 1
  if (bt1ActiveState != bt1Active){
    bt1ActiveState = bt1Active;
    if (bt1Active){
      Keyboard_write('b');
      delay(30);
      Keyboard_write('u');
      delay(30);
      Keyboard_write('t');
      delay(30);
      Keyboard_write('t');
      delay(30);
      Keyboard_write('o');
      delay(30);
      Keyboard_write('n');
      delay(30);
      Keyboard_write(' ');
      delay(30);
      Keyboard_write('1');
      delay(30);
      Keyboard_write(KEY_RETURN);
      delay(30);
    }
  }
  
  //Button 2
  if (bt2ActiveState != bt2Active){
    bt2ActiveState = bt2Active;
    if (bt2Active){
      Keyboard_write('b');
      delay(30);
      Keyboard_write('u');
      delay(30);
      Keyboard_write('t');
      delay(30);
      Keyboard_write('t');
      delay(30);
      Keyboard_write('o');
      delay(30);
      Keyboard_write('n');
      delay(30);
      Keyboard_write(' ');
      delay(30);
      Keyboard_write('2');
      delay(30);
      Keyboard_write(KEY_RETURN);
      delay(30);
    }
  }

  //Button 3
  if (bt3ActiveState != bt3Active){
    bt3ActiveState = bt3Active;
    if (bt3Active){
      Keyboard_write('b');
      delay(30);
      Keyboard_write('u');
      delay(30);
      Keyboard_write('t');
      delay(30);
      Keyboard_write('t');
      delay(30);
      Keyboard_write('o');
      delay(30);
      Keyboard_write('n');
      delay(30);
      Keyboard_write(' ');
      delay(30);
      Keyboard_write('3');
      delay(30);
      Keyboard_write(KEY_RETURN);
      delay(30);
    }
  }

  //Button 4
  if (bt4ActiveState != bt4Active){
    bt4ActiveState = bt4Active;
    if (bt4Active){
      Keyboard_write('b');
      delay(30);
      Keyboard_write('u');
      delay(30);
      Keyboard_write('t');
      delay(30);
      Keyboard_write('t');
      delay(30);
      Keyboard_write('o');
      delay(30);
      Keyboard_write('n');
      delay(30);
      Keyboard_write(' ');
      delay(30);
      Keyboard_write('4');
      delay(30);
      Keyboard_write(KEY_RETURN);
      delay(30);
    }
  }

  // Handle rotary encoder
  // ---------------------
  if(!PIN_read(PIN_ENC_A)) {                    // encoder turned ?
    if(PIN_read(PIN_ENC_B)) {                   // clockwise ?
      Keyboard_write('>');
      DLY_ms(5);                                // debounce
    }
    else {                                      // counter-clockwise ?
      Keyboard_write('<');
      DLY_ms(5);                                // debounce
    }
    while(!PIN_read(PIN_ENC_A));                // wait until next detent
  } 

  delay(5);  //naive debouncing
}
