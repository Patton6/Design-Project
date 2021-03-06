/*Initial Variable Declarations*/
//Tank Temperature Variables
float TankTemp1 = 0; //initializes temperature variable for tank 1
float TankTemp2 = 0; //initializes temperature variable for tank 2
float TankTemp3 = 0; //initializes temperature variable for tank 3
//Temperature Sensor Pin Variables
int OutPutPin1 = 0; //sets the pin for the output for tank 1 sensor
int OutPutPin2 = 1; //sets the pin for the output for tank 2 sensor
int OutPutPin3 = 2; //sets the pin for the output for tank 3 sensor
//Heating Pad Variables
int HeatElPin1 = 10; //sets the pin for the heating element for tank 1
int HeatElPin2 = 11; //sets the pin for the heating element for tank 2
int HeatElPin3 = 12; //sets the pin for the heating element for tank 3
//Variables for Writing to Storage Device
int IncomingByte = 0; //incoming byte variable
int FileNumber = 1; //file number variable
int NumOfChars; //number of characters variable
long int ValToWrite; //value to write variable
long int X; //variable for counting functions
long int StartLogTime = 0; //varibale to log time since program started 
int var = 1;

int setup() {
  /*Initial Arduino Set Up*/
  Serial.begin(9600); //sets the bit rate to communicate with the computer
  pinMode(HeatElPin1, OUTPUT); //sets up tank 1 heating element's pin to output
  pinMode(HeatElPin2, OUTPUT); //sets up tank 2 heating element's pin to output
  pinMode(HeatElPin3, OUTPUT); //sets up tank 3 heating element's pin to output
  Serial.println("Minute 0"); //set 
  
  /*Primary Heating Test on Startup*/
  //Temperature sensor 1 code (Do not EDIT, comes from Manufacture's Website)
  int rawvoltage1 = analogRead(OutPutPin1);
  float millivolts1 = (rawvoltage1/1024.0) * 5000;
  float fahrenheit1 = millivolts1/10;

  Serial.print(fahrenheit2);
  Serial.println(" degrees Fahrenheit, Tank 2,");
  //Temperature sesnor 3 code (Do not EDIT, comes from Manufacture's Website)
  int rawvoltage3 = analogRead(OutPutPin3);
  float millivolts3 = (rawvoltage3/1024.0) * 5000;
  float fahrenheit3 = millivolts3/10;
  Serial.print(fahrenheit3);
  Serial.println(" degrees Fahrenheit, Tank 3.");
  
  /*Logic Gates for Initial Heating*/
  //Heating for Initial Hatching of the Brine Shrimp
  /*Logic Gates*/
  if (fahrenheit2 <= 68){
      digitalWrite(HeatElPin2, HIGH); //sets the pin for tank 2 heating element to 5V 
  }
  if (fahrenheit2 >= 79) {
      digitalWrite(HeatElPin2,LOW);//turns heating element for tank 2 off
}


void loop() {
  /*Continuous Water Temperature Testing*/
  Serial.println("Temperatures"); //prints "Temperatures" to the serial, will be used for logging into Text File
  Serial.print("Minute "); //prints "Minute ", will be used in conjunction with time variable
  Serial.println(var); //prints the minute variable (is actually the time the loop has continued, while each loop takes 60 seconds)
  
  //Temperature sensor 2 code (Do not EDIT, comes from Manufacture's Website)
  int rawvoltage2 = analogRead(OutPutPin2); 
  float millivolts2 = (rawvoltage2/1024.0) * 5000;
  float fahrenheit2 = millivolts2/10;
  Serial.print(fahrenheit2);
  Serial.println(" degrees Fahrenheit, Tank 2,");

  /*Logic Gates*/
  if (fahrenheit2 <= 68){
      digitalWrite(HeatElPin2, HIGH); //sets the pin for tank 2 heating element to 5V 
  }
  if (fahrenheit2 >= 79) {
      digitalWrite(HeatElPin2,LOW);//turns heating element  for tank 2 off
  }
  delay(60000);
  var= var + 1;
}
