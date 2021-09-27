// Define pin connections & motor's steps per revolution
const int aDirPin = 5;
const int aStepPin = 2;
const int bDirPin = 6;
const int bStepPin = 3;
const int cDirPin = 7;
const int cStepPin = 4;

const int aLimitPin = 9;
const int bLimitPin = 10;
const int cLimitPin = 11;


const int stepsPerRevolution = 50;

bool step(int dirPin, bool dir, int stepPin, int delayMicroS){
  digitalWrite(dirPin, dir);
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(delayMicroS);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(delayMicroS);
  return(HIGH);
}

void setup()
{
  // Declare limit switch pins as inputs
  pinMode(aLimitPin, INPUT);
  //others
  
   
  // Declare stepping pins as Outputs
  pinMode(aStepPin, OUTPUT);
  pinMode(aDirPin, OUTPUT);
  pinMode(bStepPin, OUTPUT);
  pinMode(bDirPin, OUTPUT);
  pinMode(cStepPin, OUTPUT);
  pinMode(cDirPin, OUTPUT);

  while(!digitalRead(cLimitPin)){//||!digitalRead(bLimitPin)||!digitalRead(cLimitPin)){
    if(!digitalRead(cLimitPin))
      step(cDirPin, LOW, cStepPin, 6000);
  }
  delay(2000);
  for(int x = 0; x < 50; x++){
    step(cDirPin, HIGH, cStepPin, 500);
  }
  delay(2000);
  while(!digitalRead(cLimitPin)){//||!digitalRead(bLimitPin)||!digitalRead(cLimitPin)){
    if(!digitalRead(cLimitPin))
      step(cDirPin, LOW, cStepPin, 60000);
  }
  delay(2000);

  
  
  
  


  
}
void loop()
{}


/*
  // Set motor direction clockwise
  digitalWrite(aDirPin, HIGH);
  digitalWrite(bDirPin, HIGH);
  digitalWrite(cDirPin, HIGH);
  
  // Spin motor slowly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(aStepPin, HIGH);
    digitalWrite(bStepPin, HIGH);
    digitalWrite(cStepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(aStepPin, LOW);
    digitalWrite(bStepPin, LOW);
    digitalWrite(cStepPin, LOW);
    delayMicroseconds(2000);
  }
  delay(1000); // Wait a second
  
  // Set motor direction counterclockwise
  digitalWrite(aDirPin, LOW);
  digitalWrite(bDirPin, LOW);
  digitalWrite(cDirPin, LOW);

  // Spin motor quickly
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(aStepPin, HIGH);
    digitalWrite(bStepPin, HIGH);
    digitalWrite(cStepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(aStepPin, LOW);
    digitalWrite(bStepPin, LOW);
    digitalWrite(cStepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000); // Wait a second
}*/
