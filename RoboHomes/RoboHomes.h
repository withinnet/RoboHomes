#ifndef RoboHomes_h
#define RoboHomes_h

//base include
#include "Arduino.h"

//SoftwareSerial include
#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출

//servo include
/*
#include <Servo.h>
#include "ServoTimer2.h"
*/
//OLED include
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//keypad include
#include <Keypad.h>

//mp3 include
#include "DFRobotDFPlayerMini.h"

//Temperature include
#include <Adafruit_MLX90614.h>

//mp3 struct
typedef struct {
  int soundFileName;
  int delayTime;
} SoundFileSet;

class RoboHomes
{
  public:    
    RoboHomes();

    /*
    //servo function
    void InitServo(int servoNum, int pin);
    void InitServoTimer2(int servoNum, int pin);

    void servoWrite(int servoNum, int deg);
    void servoTimer2Write(int servoNum, int deg);

    //servo value
    Servo servos[5];
    ServoTimer2 servo[5];
    */
    
    //motor function
    void InitMotor4(int ain1, int ain2, int bin1, int bin2, int pwmA1, int pwmA2, int pwmB1, int pwmB2, int _stby);
    
    void Motor4AllStop();
    
    void Motor4AllForward(int _motorSpeed);
    void Motor4AllBackward(int _motorSpeed);
    void Motor4AllLeftMove(int _motorSpeed);
    void Motor4AllRightMove(int _motorSpeed);
    void Motor4AllLeftTurn(int _motorSpeed);
    void Motor4AllRightTurn(int _motorSpeed);

    void Motor4AllLeftUpMove(int _motorSpeed);//좌상단 대각선
    void Motor4AllRightUpMove(int _motorSpeed);//우상단 대각선
    void Motor4AllLeftDownMove(int _motorSpeed);//좌하단 대각선
    void Motor4AllRightDownMove(int _motorSpeed);//우하단 대각선

    void Motor4IndiForward(int a1Speed, int a2Speed, int b1Speed, int b2Speed);    //Indi : Individual의 약어
    void Motor4IndiBackward(int a1Speed, int a2Speed, int b1Speed, int b2Speed);
    void Motor4IndiLeftMove(int a1Speed, int a2Speed, int b1Speed, int b2Speed);
    void Motor4IndiRightMove(int a1Speed, int a2Speed, int b1Speed, int b2Speed);
    void Motor4IndiLeftTurn(int a1Speed, int a2Speed, int b1Speed, int b2Speed);
    void Motor4IndiRightTurn(int a1Speed, int a2Speed, int b1Speed, int b2Speed);

    void Motor4IndiLeftUpMove(int a2Speed, int b1Speed);//좌상단 대각선
    void Motor4IndiRightUpMove(int a1Speed, int b2Speed);//우상단 대각선
    void Motor4IndiLeftDownMove(int a1Speed, int b2Speed);//좌하단 대각선
    void Motor4IndiRightDownMove(int a2Speed, int b1Speed);//우하단 대각선

    void Motor4CustomMove(int a1Rotation, int a2Rotation, int b1Rotation, int b2Rotation, int a1Speed, int a2Speed, int b1Speed, int b2Speed);

    void InitMotor2(int ain1, int ain2, int pwmA1, int pwmA2, int _stby);
    
    void Motor2AllStop();
    
    void Motor2AllForward(int _motorSpeed);
    void Motor2AllBackward(int _motorSpeed);
    void Motor2AllLeftTurn(int _motorSpeed);
    void Motor2AllRightTurn(int _motorSpeed);

    void Motor2IndiForward(int a1Speed, int a2Speed);
    void Motor2IndiBackward(int a1Speed, int a2Speed);
    void Motor2IndiLeftTurn(int a1Speed, int a2Speed);
    void Motor2IndiRightTurn(int a1Speed, int a2Speed);

    void Motor2SlowLeftTurn(int a1Speed);
    void Motor2SlowRightTurn(int a2Speed);

    void Motor2CustomMove(int a1Rotation, int a2Rotation, int a1Speed, int a2Speed);

    //motor value
    int ains[2];
    int bins[2];
    int pwms[4];
    int stby;

    //SoftwareSerial function
    void InitMySoftwareSerial(int rxPin, int txPin, long rate);

    //mp3 function
    void InitMP3(int rxPin, int txPin, long rate);     //need SoftwareSerial
    void MP3Sound(int index);
    void MP3SoundDelay(int index, int delayTime);
    void MP3LoopSound(int index);
    void MP3Stop();

    //mp3 value
    DFRobotDFPlayerMini myDFPlayer;     //need SoftwareSerial

    //OLED function
    void InitOLED();
    void OLEDDisplay(String printType, String data);
    void OLEDDisplay02(int printType, char data);
    void ClearOLEDDisplay();
    
    //keypad function
    void InitKeyPad();
    char KeyPadGetKey();
    
    void SendMsg(char data);
    void SendMsgMove(char data, char move_stop_data);
    void SendMsgTransMove(char data);

    //Temperature function
    void InitTemperature();
    float GetTemperature();

    //Temperature value
    Adafruit_MLX90614 mlx;

    //ultrasound function
    void InitUltraSound(int _trigPin, int _echoPin);    //need trig / echo pin
    float GetDistance();

    //ultrasound value
    int trigPin;
    int echoPin;

  private:
    Stream& _serial;

    //keypad value
    char customKey;
    Keypad *customKeypad;

    //SoftwareSerial value
    SoftwareSerial *mySoftwareSerial;

    //OLED value
    Adafruit_SSD1306 display;
};

#endif