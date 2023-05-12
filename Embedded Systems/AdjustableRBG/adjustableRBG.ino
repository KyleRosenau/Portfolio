//constants
const int rInPin = A0;
const int bInPin = A1;
const int gInPin = A2;

const int rOutPin = 3;
const int bOutPin = 6;
const int gOutPin = 9;

//variables
int rInput = 0;
int bInput = 0;
int gInput = 0;

int rOutput = 0;
int bOutput = 0;
int gOutput = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  rInput = analogRead(rInPin);
  bInput = analogRead(bInPin);
  gInput = analogRead(gInPin);
  
  rOutput = map(rInput, 0, 1023, 0, 255);
  bOutput = map(bInput, 0, 1023, 0, 255);
  gOutput = map(gInput, 0, 1023, 0, 255);
  
  analogWrite(rOutPin, rOutput);
  analogWrite(bOutPin, bOutput);
  analogWrite(gOutPin, gOutput);
  
  Serial.print("\nRed = ");

  Serial.print(rOutput);
  
    
  Serial.print("\tBlue = ");

  Serial.print(bOutput);
  
    
  Serial.print("\tGreen = ");

  Serial.print(gOutput);
  
  delay(2);

}