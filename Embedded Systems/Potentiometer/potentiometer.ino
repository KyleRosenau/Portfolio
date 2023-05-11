//Constants
const int LEDoutput = 3;
const int motorOutput = 5;
const int input = A0;


//Variables
int outputVal = 0;

int sensorVal = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  sensorVal = analogRead(input);
  
  outputVal = map(sensorVal, 0, 1023, 0, 255);
  
  analogWrite(LEDoutput, outputVal);
  analogWrite(motorOutput, outputVal);
  
  //Serial.print("\n Sensor = ");
  //Serial.print(sensorVal);
  Serial.print("\n outputs = ");
  Serial.print(outputVal);
  
  delay(2);
  
}