// constants
const int switchPin = 2;  // the number of the pushbutton pin
const int ledRed = 13;    // the number of the red LED pin
const int ledYel = 12;    // the number of the yellow LED pin
const int ledGrn = 11;    // the number of the green LED pin

// variables
int switchState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pins as outputs:
  pinMode(ledRed, OUTPUT);
  pinMode(ledYel, OUTPUT);
  pinMode(ledGrn, OUTPUT);
  // initialize the switch pin as an input:
  pinMode(switchPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  switchState = digitalRead(switchPin);

  // check if the switch is on. If it is, the switchState is HIGH:
  if (switchState == HIGH) {
    // turn green LED on and others off:
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYel, LOW);
    digitalWrite(ledGrn, HIGH);
    delay(12000);
    // turn yellow LED on and others off:
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYel, HIGH);
    digitalWrite(ledGrn, LOW);
    delay(4000);
    // turn red LED on and others off:
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledYel, LOW);
    digitalWrite(ledGrn, LOW);
    delay(9000);
  } else {
    // turn LEDs off:
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYel, LOW);
    digitalWrite(ledGrn, LOW);
  }
}
