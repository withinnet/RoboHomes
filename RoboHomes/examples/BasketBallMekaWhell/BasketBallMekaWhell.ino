 #include "RoboHomes.h"
#include <Servo.h>


#define AIN1 4  //좌상
#define AIN2 8  //우상

#define BIN1 7  //좌하
#define BIN2 12 //우하

#define PWMA1 5 //  выходы arduino
#define PWMA2 6  
#define PWMB1 3 //  выходы arduino
#define PWMB2 11  

#define STBY 2 //stop : LOW, move : HIGH

#define SERVOPIN 13

RoboHomes rh;
Servo servo;

String myString = ""; //받는 문자열
int lS; //loop sound : lS

int normal = 70; 
int minuteness = 20;
int maxVal = 250;

void setup() {
  Serial.begin(38400); //블루투스 통신속도
  lS = 0;
  rh.InitMotor4(AIN1, AIN2, BIN1, BIN2, PWMA1, PWMA2, PWMB1, PWMB2, STBY);  
  
  int rxPin = 10;
  int txPin = 9;
  rh.InitMP3(rxPin, txPin, 9600);
  
  servo.attach(SERVOPIN);
  servo.write(130);
}

void loop() {
  while (Serial.available()) //mySerial에 전송된 값이 있으면
  {
    char myChar = (char)Serial.read();  //mySerial int 값을 char 형식으로 변환
    //myString += myChar; //수신되는 문자를 myString에 모두 붙임 (1바이트씩 전송되는 것을 연결)
    //delay(5);           //수신 문자열 끊김 방지
    myString += myChar;
    delay(5);
    //Serial.println(myString);
    Serial.println("input value: " + myString);
    if (myString.equals("q")) {
      rh.Motor4AllStop();      
    }
    
    else if (myString.equals("b")) {  //좌8
      rh.Motor4AllForward(minuteness);
    }
    else if (myString.equals("d")) {  //좌2
      rh.Motor4AllBackward(minuteness);
    }
    else if (myString.equals("e")) {  //좌4
      rh.Motor4AllLeftTurn(minuteness);
    }
    else if (myString.equals("c")) {  //좌6
      rh.Motor4AllRightTurn(minuteness);
    }

    else if (myString.equals("f")) {  //좌5
      rh.Motor4AllRightTurn(maxVal);
      delay(360);
      rh.Motor4AllStop();
    }

    
    else if (myString.equals("h")) {  //우8
      rh.Motor4AllForward(normal);
    }
    else if (myString.equals("n")) {  //우2
      rh.Motor4AllBackward(normal);
    }
    else if (myString.equals("j")) {  //우4
      rh.Motor4AllLeftMove(minuteness);
    }
    else if (myString.equals("l")) {  //우6
      rh.Motor4AllRightMove(minuteness);
    }

    else if (myString.equals("g")) {  //우7
      rh.Motor4AllLeftMove(normal);
      //rh.Motor4IndiLeftMove(minuteness, minuteness, minuteness, minuteness);
    }
    else if (myString.equals("i")) {  //우9
      rh.Motor4AllRightMove(normal);
      //rh.Motor4IndiRightMove(minuteness, minuteness, minuteness, minuteness);
    }
    else if (myString.equals("m")) {  //우1
      rh.Motor4AllLeftTurn(normal);
    }
    else if (myString.equals("o")) {  //우3
      rh.Motor4AllRightTurn(normal);      
    }
    else if (myString.equals("k")) {  //우5(슛)

      servo.write(20);
      delay(300);
      servo.write(130);
      delay(100);
    }
    myString = "";
  }
}
