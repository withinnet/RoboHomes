#include "Arduino.h"
#include "RoboHomes.h"

RoboHomes::RoboHomes()
{
    
}

//motor function
void RoboHomes::InitMotor4(int ain1, int ain2, int bin1, int bin2, int pwmA1, int pwmA2, int pwmB1, int pwmB2, int _stby) {
    ains[0] = ain1;
    ains[1] = ain2;
    bins[0] = bin1;
    bins[1] = bin2;
    pwms[0] = pwmA1;
    pwms[1] = pwmA2;
    pwms[2] = pwmB1;
    pwms[3] = pwmB2;
    stby = _stby;

    pinMode(pwms[0], OUTPUT);  
    pinMode(pwms[1], OUTPUT);  
    pinMode(pwms[2], OUTPUT);  
    pinMode(pwms[3], OUTPUT);  
    pinMode(ains[0], OUTPUT);  
    pinMode(bins[0], OUTPUT);  
    pinMode(ains[1], OUTPUT);  
    pinMode(bins[1], OUTPUT); 
    pinMode(stby, OUTPUT);  
    
    digitalWrite(stby, HIGH); 
    delay(1000);
}
void RoboHomes::Motor4AllStop() {
  analogWrite(pwms[0], 0);  
  analogWrite(pwms[1], 0);  
  analogWrite(pwms[2], 0);  
  analogWrite(pwms[3], 0); 
  delay(30);
  //digitalWrite(STBY, LOW);
}

void RoboHomes::Motor4AllForward(int _motorSpeed) {
  digitalWrite(ains[0], LOW);      // крутим моторы в одну сторону  
  digitalWrite(bins[0], LOW);  
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], HIGH); 
  analogWrite(pwms[0], _motorSpeed);  
  analogWrite(pwms[1], _motorSpeed);  
  analogWrite(pwms[2], _motorSpeed);  
  analogWrite(pwms[3], _motorSpeed); 
}

void RoboHomes::Motor4AllBackward(int _motorSpeed) {
  digitalWrite(ains[0], HIGH);  
  digitalWrite(bins[0], HIGH);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], LOW); 
  analogWrite(pwms[0], _motorSpeed);   
  analogWrite(pwms[1], _motorSpeed); 
  analogWrite(pwms[2], _motorSpeed);  
  analogWrite(pwms[3], _motorSpeed); 
}

void RoboHomes::Motor4AllLeftMove(int _motorSpeed) {
  digitalWrite(ains[0], HIGH);  
  digitalWrite(bins[0], LOW);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], LOW); 
  analogWrite(pwms[0], _motorSpeed);   
  analogWrite(pwms[1], _motorSpeed); 
  analogWrite(pwms[2], _motorSpeed);  
  analogWrite(pwms[3], _motorSpeed); 
}
void RoboHomes::Motor4AllRightMove(int _motorSpeed){
  digitalWrite(ains[0], LOW);  
  digitalWrite(bins[0], HIGH);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], HIGH); 
  analogWrite(pwms[0], _motorSpeed);   
  analogWrite(pwms[1], _motorSpeed); 
  analogWrite(pwms[2], _motorSpeed);  
  analogWrite(pwms[3], _motorSpeed); 
}
void RoboHomes::Motor4AllLeftTurn(int _motorSpeed){
  digitalWrite(ains[0], HIGH);  
  digitalWrite(bins[0], HIGH);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], HIGH); 
  analogWrite(pwms[0], _motorSpeed);   
  analogWrite(pwms[1], _motorSpeed); 
  analogWrite(pwms[2], _motorSpeed);  
  analogWrite(pwms[3], _motorSpeed); 
}
void RoboHomes::Motor4AllRightTurn(int _motorSpeed){
  digitalWrite(ains[0], LOW);  
  digitalWrite(bins[0], LOW);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], LOW); 
  analogWrite(pwms[0], _motorSpeed);   
  analogWrite(pwms[1], _motorSpeed); 
  analogWrite(pwms[2], _motorSpeed);  
  analogWrite(pwms[3], _motorSpeed); 
  
}

//좌상단 대각선
void RoboHomes::Motor4AllLeftUpMove(int _motorSpeed){
  digitalWrite(ains[0], LOW);  //stop  
  digitalWrite(bins[0], LOW);  
  digitalWrite(ains[1], HIGH);    
  digitalWrite(bins[1], LOW);  //stop
  analogWrite(pwms[0], 0);   
  analogWrite(pwms[1], _motorSpeed); 
  analogWrite(pwms[2], _motorSpeed);  
  analogWrite(pwms[3], 0); 
}
//우상단 대각선
void RoboHomes::Motor4AllRightUpMove(int _motorSpeed){
  digitalWrite(ains[0], LOW);    
  digitalWrite(bins[0], LOW);  //stop
  digitalWrite(ains[1], HIGH); //stop   
  digitalWrite(bins[1], HIGH);  
  analogWrite(pwms[0], _motorSpeed);   
  analogWrite(pwms[1], 0); 
  analogWrite(pwms[2], 0);  
  analogWrite(pwms[3], _motorSpeed); 
}
//좌하단 대각선
void RoboHomes::Motor4AllLeftDownMove(int _motorSpeed){
  digitalWrite(ains[0], HIGH);    
  digitalWrite(bins[0], LOW);  //stop
  digitalWrite(ains[1], HIGH); //stop   
  digitalWrite(bins[1], LOW);  
  analogWrite(pwms[0], _motorSpeed);   
  analogWrite(pwms[1], 0); 
  analogWrite(pwms[2], 0);  
  analogWrite(pwms[3], _motorSpeed);
}
//우하단 대각선
void RoboHomes::Motor4AllRightDownMove(int _motorSpeed){
  digitalWrite(ains[0], LOW);  //stop  
  digitalWrite(bins[0], HIGH);  
  digitalWrite(ains[1], LOW);    
  digitalWrite(bins[1], LOW);  //stop
  analogWrite(pwms[0], 0);   
  analogWrite(pwms[1], _motorSpeed); 
  analogWrite(pwms[2], _motorSpeed);  
  analogWrite(pwms[3], 0); 
}

void RoboHomes::Motor4IndiForward(int a1Speed, int a2Speed, int b1Speed, int b2Speed) {
  digitalWrite(ains[0], LOW);      // крутим моторы в одну сторону  
  digitalWrite(bins[0], LOW);  
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], HIGH); 
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], b2Speed); 
}

void RoboHomes::Motor4IndiBackward(int a1Speed, int a2Speed, int b1Speed, int b2Speed) {
  digitalWrite(ains[0], HIGH);  
  digitalWrite(bins[0], HIGH);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], LOW); 
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], b2Speed); 
}

void RoboHomes::Motor4IndiLeftMove(int a1Speed, int a2Speed, int b1Speed, int b2Speed) {
  digitalWrite(ains[0], HIGH);  
  digitalWrite(bins[0], LOW);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], LOW); 
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], b2Speed); 
}
void RoboHomes::Motor4IndiRightMove(int a1Speed, int a2Speed, int b1Speed, int b2Speed){
  digitalWrite(ains[0], LOW);  
  digitalWrite(bins[0], HIGH);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], HIGH); 
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], b2Speed); 
}
void RoboHomes::Motor4IndiLeftTurn(int a1Speed, int a2Speed, int b1Speed, int b2Speed){
  digitalWrite(ains[0], HIGH);  
  digitalWrite(bins[0], HIGH);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], HIGH); 
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], b2Speed); 
}
void RoboHomes::Motor4IndiRightTurn(int a1Speed, int a2Speed, int b1Speed, int b2Speed){
  digitalWrite(ains[0], LOW);  
  digitalWrite(bins[0], LOW);    // крутим моторы в противоположную сторону
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  digitalWrite(bins[1], LOW); 
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], b2Speed); 
  
}

//좌상단 대각선
void RoboHomes::Motor4IndiLeftUpMove(int a2Speed, int b1Speed){
  digitalWrite(ains[0], LOW);  //stop  
  digitalWrite(bins[0], LOW);  
  digitalWrite(ains[1], HIGH);    
  digitalWrite(bins[1], LOW);  //stop
  analogWrite(pwms[0], 0);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], 0); 
}
//우상단 대각선
void RoboHomes::Motor4IndiRightUpMove(int a1Speed, int b2Speed){
  digitalWrite(ains[0], LOW);    
  digitalWrite(bins[0], LOW);  //stop
  digitalWrite(ains[1], HIGH); //stop   
  digitalWrite(bins[1], HIGH);  
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], 0);  
  analogWrite(pwms[2], 0);  
  analogWrite(pwms[3], b2Speed);
}
//좌하단 대각선
void RoboHomes::Motor4IndiLeftDownMove(int a1Speed, int b2Speed){
  digitalWrite(ains[0], HIGH);    
  digitalWrite(bins[0], LOW);  //stop
  digitalWrite(ains[1], HIGH); //stop   
  digitalWrite(bins[1], LOW);  
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], 0);  
  analogWrite(pwms[2], 0);  
  analogWrite(pwms[3], b2Speed);
}
//우하단 대각선
void RoboHomes::Motor4IndiRightDownMove(int a2Speed, int b1Speed){
  digitalWrite(ains[0], LOW);  //stop  
  digitalWrite(bins[0], HIGH);  
  digitalWrite(ains[1], LOW);    
  digitalWrite(bins[1], LOW);  //stop
  analogWrite(pwms[0], 0);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], 0); 
}
void RoboHomes::Motor4CustomMove(int a1Rotation, int a2Rotation, int b1Rotation, int b2Rotation, int a1Speed, int a2Speed, int b1Speed, int b2Speed) {
  digitalWrite(ains[0], a1Rotation);    
  digitalWrite(bins[0], b1Rotation);  //stop
  digitalWrite(ains[1], a2Rotation); //stop   
  digitalWrite(bins[1], b2Rotation);  
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], b1Speed);  
  analogWrite(pwms[2], a2Speed);  
  analogWrite(pwms[3], b2Speed);
}

void RoboHomes::InitMotor2(int ain1, int ain2, int pwmA1, int pwmA2, int _stby) {
    ains[0] = ain1;
    ains[1] = ain2;
    pwms[0] = pwmA1;
    pwms[1] = pwmA2;
    stby = _stby;

    pinMode(pwms[0], OUTPUT);  
    pinMode(pwms[1], OUTPUT);  
    pinMode(ains[0], OUTPUT);  
    pinMode(ains[1], OUTPUT);  
    pinMode(stby, OUTPUT);  
    
    digitalWrite(stby, HIGH); 
    delay(1000);
}
    
void RoboHomes::Motor2AllStop() {
  analogWrite(pwms[0], 0);  
  analogWrite(pwms[1], 0);
  
}

void RoboHomes::Motor2AllForward(int _motorSpeed) {
  digitalWrite(ains[0], LOW);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], _motorSpeed);  
  analogWrite(pwms[1], _motorSpeed);
}
void RoboHomes::Motor2AllBackward(int _motorSpeed) {
  digitalWrite(ains[0], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], _motorSpeed);  
  analogWrite(pwms[1], _motorSpeed);
}
void RoboHomes::Motor2AllLeftTurn(int _motorSpeed) {
  digitalWrite(ains[0], LOW);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], _motorSpeed);  
  analogWrite(pwms[1], _motorSpeed);
}
void RoboHomes::Motor2AllRightTurn(int _motorSpeed) {
  digitalWrite(ains[0], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], _motorSpeed);  
  analogWrite(pwms[1], _motorSpeed);
}

void RoboHomes::Motor2IndiForward(int a1Speed, int a2Speed) {
  digitalWrite(ains[0], LOW);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], a2Speed);
}
void RoboHomes::Motor2IndiBackward(int a1Speed, int a2Speed) {
  digitalWrite(ains[0], LOW);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], a2Speed);
}
void RoboHomes::Motor2IndiLeftTurn(int a1Speed, int a2Speed) {
  digitalWrite(ains[0], LOW);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], a2Speed);
}
void RoboHomes::Motor2IndiRightTurn(int a1Speed, int a2Speed) {
  digitalWrite(ains[0], HIGH);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], LOW);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], a2Speed);
}

void RoboHomes::Motor2SlowLeftTurn(int a1Speed) {
  digitalWrite(ains[0], LOW);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], a1Speed);
  analogWrite(pwms[1], 0);  
}
void RoboHomes::Motor2SlowRightTurn(int a2Speed) {
  digitalWrite(ains[1], HIGH);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], 0);
  analogWrite(pwms[1], a2Speed);
}

void RoboHomes::Motor2CustomMove(int a1Rotation, int a2Rotation, int a1Speed, int a2Speed) {
  digitalWrite(ains[0], a1Rotation);      // крутим моторы в одну сторону  
  digitalWrite(ains[1], a2Rotation);      // крутим моторы в одну сторону  
  analogWrite(pwms[0], a1Speed);  
  analogWrite(pwms[1], a2Speed);
}


//SoftwareSerial function
void RoboHomes::InitMySoftwareSerial(int rxPin, int txPin, long rate) {
  mySoftwareSerial = new SoftwareSerial(rxPin, txPin);  //시리얼 통신을 위한 객체선언
  mySoftwareSerial->begin(rate);
}

//mp3 function
void RoboHomes::InitMP3(int rxPin, int txPin, long rate){     //need SoftwareSerial
  this->InitMySoftwareSerial(rxPin, txPin, rate);
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(*mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.setTimeOut(500); //Set serial communictaion time out 500ms
  
  //----Set volume----
  myDFPlayer.volume(30);  //Set volume value (0~30).

  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);

  //myDFPlayer.loop(1);
}     
void RoboHomes::MP3Sound(int index) {
  myDFPlayer.play(index);
}
void RoboHomes::MP3SoundDelay(int index, int delayTime) {
  myDFPlayer.play(index);
  delay(delayTime);
}
void RoboHomes::MP3LoopSound(int index) {
  myDFPlayer.loop(index);
}
void RoboHomes::MP3Stop() {
   myDFPlayer.pause();
}

//OLED function
void RoboHomes::InitOLED() {
  display = Adafruit_SSD1306(128, 32, &Wire);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  
  
  Serial.println("OLED FeatherWing test");
  Serial.println("OLED begun");

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();

  Serial.println("IO test");


  // text display tests
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.print("Company\n'WITHINNET':");
  display.print("3DSSS");
  display.println("Remote control");
  display.println("walking robot");
  display.setCursor(0,0);
  display.display(); // actually display all of the above
  delay(1000);
  display.clearDisplay ();
  display.display();

}
void RoboHomes::OLEDDisplay(String printType, String data) {
  if( printType.equals("rC") == 1) {
    display.setTextSize(4);
    display.setCursor(50,0);
    display.println(data);
    display.display();
  }
  else if( printType.equals("nT1") == 1) {
    display.setTextSize(2);
    display.setCursor(25,6);
    display.println (data);
    display.display();
  }
  else if( printType.equals("nT2") == 1) {
    display.setTextSize(2);
    display.setCursor(25,6);
    display.println (data);
    display.display();
  }
}
void RoboHomes::OLEDDisplay02(int printType, char data) {
  if (printType == 1) {
    display.setTextSize(4);
    display.setCursor(50,0);
    display.println(data);
    display.display();
  }   
}
void RoboHomes::ClearOLEDDisplay() {
  display.clearDisplay();
  display.display();
}

//keypad function
void RoboHomes::InitKeyPad() {
  const byte ROWS = 5; 
  const byte COLS = 5;
  char hexaKeys[ROWS][COLS] = {
    {'0','1','2','3','4'},
    {'5','6','7','8','9'}, 
    {'a','b','c','d','e'}, 
    {'f','g','h','i','j'}, 
    {'k','l','m','n','o'} 
  };

  byte rowPins[ROWS] = { 9,10,11,12,13}; 
  byte colPins[COLS] = {4,5,6,7,8};

  customKeypad = new Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
  Serial.begin(9600);
  //mySoftwareSerial = new SoftwareSerial(3, 2);  //시리얼 통신을 위한 객체선언
}
char RoboHomes::KeyPadGetKey() {
  return customKeypad->getKey();
}
void RoboHomes::SendMsg(char data) {
  mySoftwareSerial->print(data);
  Serial.print(data);
}
void RoboHomes::SendMsgMove(char data, char move_stop_data) {
  this->SendMsg(data); 
  while (customKeypad->getState() == 1 || customKeypad->getState() == 2)
  {
    customKeypad->getKey();
  }
  this->SendMsg(move_stop_data);
}
void RoboHomes::SendMsgTransMove(char data) {
  while (customKeypad->getState() == 1 || customKeypad->getState() == 2)
  {
    this->SendMsg(data);
    customKeypad->getKey();
  }
}

//Temperature function
void RoboHomes::InitTemperature() {
  mlx = Adafruit_MLX90614();
}
float RoboHomes::GetTemperature() {
  return mlx.readObjectTempC();
}

//ultrasound function
void RoboHomes::InitUltraSound(int _trigPin, int _echoPin) {    //need trig / echo pin
  trigPin = _trigPin;
  echoPin = _echoPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
float RoboHomes::GetDistance() {
  digitalWrite(trigPin, LOW);
  digitalWrite(echoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  unsigned long duration = pulseIn(echoPin, HIGH);
 
  // 초음파의 속도는 초당 340미터를 이동하거나, 29마이크로초 당 1센치를 이동합니다.
  // 따라서, 초음파의 이동 거리 = duration(왕복에 걸린시간) / 29 / 2 입니다.
  float distance = duration / 29.0 / 2.0;
 
  // 측정된 거리 값를 시리얼 모니터에 출력합니다.
  
  return distance;   
}