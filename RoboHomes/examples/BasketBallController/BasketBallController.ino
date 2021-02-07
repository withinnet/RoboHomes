#include "RoboHomes.h"

RoboHomes rh;

int rxPin=3;   //Tx (보내는핀 설정)
int txPin=2;   //Rx (받는핀 설정)

char base_data = 'y';

char move_data1 = 'b';           //상하좌우
char move_data2 = 'd';
char move_data3 = 'e';
char move_data4 = 'c';

char move_data5 = 'j';         //좌우이동
char move_data6 = 'l';

char move_data7 = 'g';
char move_data8 = 'i';
char move_data9 = 'm';
char move_data10 = 'o';

char kick_data = 'k';
char move_stop_data = 'q' ; 

char rotation_data = 'f';

char sound_data0 = '0';
char sound_data1 = '1';
char sound_data2 = '2';
char sound_data3 = '3';
char sound_data4 = '4';
char sound_data5 = '5';
char sound_data6 = '6';
char sound_data7 = '7';
char sound_data8 = '8';
char sound_data9 = '9';


char customKey;

void KeyPress();

void setup() {
  Serial.begin(9600);
  rh.InitMySoftwareSerial(rxPin, txPin, 38400); //rxPin, txPin, 통신속도
  rh.InitKeyPad();
  rh.InitOLED();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  KeyPress();
}


void KeyPress() {
  customKey = rh.KeyPadGetKey(); 

  //Serial.println(customKey);
  if(customKey){ //키 입력 신호가 있을때만 작동 
    
    Serial.println(customKey);
    rh.OLEDDisplay02(1, customKey);
    
    if(customKey == 'b') {  //좌8
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'd') { //좌2
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'e') { //좌4
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'c') { //좌6
      rh.SendMsgMove(customKey, move_stop_data);
    }

    else if(customKey == 'f') { //좌5
      rh.SendMsg(customKey);
    }

    else if(customKey == 'h') { //우8
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'n') { //우2
      rh.SendMsgMove(customKey, move_stop_data);
    }
        
    else if(customKey == 'j') { //우4
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'l') { //우6
      rh.SendMsgMove(customKey, move_stop_data);
    }

    else if(customKey == 'g') { //우7
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'i') { //우9
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'm') { //우1
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'o') { //우3
      rh.SendMsgMove(customKey, move_stop_data);
    }
    else if(customKey == 'k') { //우5
      rh.SendMsg(kick_data);
    }

    else if(customKey == '0') {
      rh.SendMsg(sound_data0);
    }
    else if(customKey == '1') {
      rh.SendMsg(sound_data1);
    }
    else if(customKey == '2') {
      rh.SendMsg(sound_data2);
    }
    else if(customKey == '3') {
      rh.SendMsg(sound_data3);
    }
    else if(customKey == '4') {
      rh.SendMsg(sound_data4);
    }
    else if(customKey == '5') {
      rh.SendMsg(sound_data5);
    }
    else if(customKey == '6') {
      rh.SendMsg(sound_data6);
    }
    else if(customKey == '7') {
      rh.SendMsg(sound_data7);
    }
    else if(customKey == '8') {
      rh.SendMsg(sound_data8);
    }
    else if(customKey == '9') {
      rh.SendMsg(sound_data9);
    }
    
    delay(1);
    rh.ClearOLEDDisplay();
    
  }
}
