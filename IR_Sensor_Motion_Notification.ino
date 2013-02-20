// Uses an IR sensor to detect movement, lights up a LED
// For inspired code look here: makeprojects.com/Project/PIR-Sensor-ArduinoAlarm/72/1
// For more info on this project look here: gianlazzarini.tumblr.com & gianlazzarini.com
// Email me, Gian Lazzarini @ gianlazzarini@gmail.com

//based upon: 
// Makeprojects.com's PIR Sensor Arduino Alarm which is based on the PIR sensor tester by Limor Fried of Adafruit

// these constant variables store the pin numbers
const int ledPin = 13;                // choose the pin for the LED 
const int inputPin = 0;               // analog pin used to connect the sharp sensor
// these variables store the values for the input
int val = 0;                    // variable for reading the pin status
int irVal,fadeValue;
int repeat = 0;                // How many times should we loop before stopping? (0 for no stop)

boolean isflashing = false;

void setup() { 
  pinMode(ledPin, OUTPUT);      // declare LED as output 
  pinMode(inputPin, INPUT);     // declare sensor as input
  Serial.begin(9600); 
} 

void loop(){ 
  irVal = analogRead(inputPin);  // read input value
  Serial.println(irVal);            // prints the value of the sensor to the serial monitor
  delay(100);                    // wait for this much time before printing next value 

  // use the input value to fade the led
  if (irVal >= 250) {    // Change this value up to make it less sensitive and down to make it more sensitive use serial moniter to guide you
    isflashing = !isflashing;
    }
    if(isflashing == true){
    digitalWrite(ledPin, irVal);  // turn the LED on HIGH is the voltage level
    delay(1000);                // wait for a second
    digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);     
  }
} 


