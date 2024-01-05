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
    analogWrite(forwardPin, 100);
    analogWrite(forwardPin2, 100);
    analogWrite(backwardPin, 100);
    analogWrite(backwardPin2, 100);
  }
  else if (state == '0') {
    //moves up
    analogWrite(forwardPin, 50);
    analogWrite(forwardPin2, 50);
    analogWrite(backwardPin, 50);
    analogWrite(backwardPin2, 50);
  } 
  else if (state == '2') {
    //moves front
    analogWrite(forwardPin, 150);
    analogWrite(forwardPin2, 150);
    analogWrite(backwardPin, 75);
    analogWrite(backwardPin2, 75);
  } 
  else if (state == '3') {
    //moves back
    analogWrite(forwardPin, 75);
    analogWrite(forwardPin2, 75);
    analogWrite(backwardPin, 150);
    analogWrite(backwardPin2, 150);
  } 
  else if (state == '4') {
    //moves left
    analogWrite(forwardPin, 150);
    analogWrite(forwardPin2, 75);
    analogWrite(backwardPin, 150);
    analogWrite(backwardPin2, 75);
  } 
  else if (state == '5') {
    //moves right
    analogWrite(forwardPin, 75);
    analogWrite(forwardPin2, 150);
    analogWrite(backwardPin, 75);
    analogWrite(backwardPin2, 150);
  } 
  else if (state == '6') {
    //moves down
    analogWrite(forwardPin, 210);
    analogWrite(forwardPin2, 210);
    analogWrite(backwardPin, 210);
    analogWrite(backwardPin2, 210);
  } 
}
