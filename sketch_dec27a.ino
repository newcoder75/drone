const int forwardPin = 8;
const int forwardPin2 = 9;
const int backwardPin = 12;
const int backwardPin2 = 13;
const int delayTime = 2000;
int state = 0;

void setup(){
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
  pinMode(forwardPin2, OUTPUT);
  pinMode(backwardPin2, OUTPUT);
  Serial.begin(38400);
}

void loop(){
  digitalWrite(forwardPin, HIGH);
  digitalWrite(backwardPin, HIGH);
  digitalWrite(forwardPin2, HIGH);
  digitalWrite(backwardPin2, HIGH);

  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
  } 

  if (state == '1') {
    //stays still
    analogWrite(forwardpin, 100);
    analogWrite(forwardpin2, 100);
    analogWrite(backwardpin, 100);
    analogWrite(backwardpin2, 100);
    state = 0;
  }
  else if (state == '0') {
    //turns on
    analogWrite(forwardpin, 255);
    analogWrite(forwardpin2, 255);
    analogWrite(backwardpin, 255);
    analogWrite(backwardpin2, 255);
    state = 0;
  } 
  else if (state == '2') {
    //moves front
    analogWrite(forwardpin, 100);
    analogWrite(forwardpin2, 100);
    analogWrite(backwardpin, 100);
    analogWrite(backwardpin2, 100);
    state = 0;
  } 
  else if (state == '3') {
    //moves back
    analogWrite(forwardpin, 100);
    analogWrite(forwardpin2, 100);
    analogWrite(backwardpin, 100);
    analogWrite(backwardpin2, 100);
    state = 0;
  } 
  else if (state == '4') {
    //moves left
    analogWrite(forwardpin, 100);
    analogWrite(forwardpin2, 100);
    analogWrite(backwardpin, 100);
    analogWrite(backwardpin2, 100);
    state = 0;
  } 
  else if (state == '5') {
    //moves right
    analogWrite(forwardpin, 100);
    analogWrite(forwardpin2, 100);
    analogWrite(backwardpin, 100);
    analogWrite(backwardpin2, 100);
    state = 0;
  } 
  else if (state == '6') {
    //moves right
    analogWrite(forwardpin, 100);
    analogWrite(forwardpin2, 100);
    analogWrite(backwardpin, 100);
    analogWrite(backwardpin2, 100);
    state = 0;
  } 
}
