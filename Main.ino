//Tank Temperature Variables
float TankTemp1 = 0; //initializes temperature variable for tank 1
float TankTemp2 = 0; //initializes temperature variable for tank 2
float TankTemp3 = 0; //initializes temperature variable for tank 3
//Temperature Sensor Pin Variables
int OutPutPin1 = 0; //sets the pin for the output for tank 1 sensor
int OutPutPin2 = 1; //sets the pin for the output for tank 2 sensor
int OutPutPin3 = 2; //sets the pin for the output for tank 3 sensor

void setup() {
  Serial.begin(9600); //sets the bit rate to communicate with the computer
}

void loop() {
  //Temperature sensor 1 code
  int rawvoltage1 = analogRead(OutPutPin1);
  float millivolts1 = (rawvoltage1/1024.0) * 5000;
  float fahrenheit1 = millivolts1/10;
  Serial.print(fahrenheit1);
  Serial.println(" degrees Fahrenheit, ");
  //Temperature sensor 2 code
  int rawvoltage1 = analogRead(OutPutPin1);
  float millivolts1 = (rawvoltage1/1024.0) * 5000;
  float fahrenheit1 = millivolts1/10;
  Serial.print(fahrenheit1);
  Serial.println(" degrees Fahrenheit, Sesnor 2");
  //Temperature sesnor 3 code
  int rawvoltage3 = analogRead(OutPutPin3);
  float millivolts3 = (rawvoltage3/1024.0) * 5000;
  float fahrenheit3 = millivolts3/10;
  Serial.print(fahrenheit3);
  Serial.println(" degrees Fahrenheit, ");
  
  delay(10000);
}
