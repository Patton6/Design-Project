/*Initial Variable Declarations*/
//Tank Temperature Variables
float TankTemp1 = 0; //initializes temperature variable for tank 1
//Temperature Sensor Pin Variables
int OutPutPin1 = 0; //sets the pin for the output for tank 1 sensor
//Heating Pad Variables
int HeatElPin1 = 10; //sets the pin for the heating element for tank 1
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
  Serial.println("Minute 0"); //set 
  
  /*Primary Heating Test on Startup*/
  //Temperature sensor 1 code (Do not EDIT, comes from Manufacture's Website)
  int rawvoltage1 = analogRead(OutPutPin1);
  float millivolts1 = (rawvoltage1/1024.0) * 5000;
  float fahrenheit1 = millivolts1/10;
  Serial.print(fahrenheit1);
  Serial.println(" degrees Fahrenheit, Tank 1,");
  
  /*Logic Gates for Initial Heating*/
  //Heating for Initial Hatching of the Brine Shrimp
  /*Logic Gates*/
  if (fahrenheit1 <= 68){
      digitalWrite(HeatElPin1, HIGH); //sets the pin for tank 1 heating element to 5V 
  }
  if (fahrenheit1 >= 79) {
      digitalWrite(HeatElPin1, LOW); //turns heating element for tank 1 off
  }
}


void loop() {
  /*Continuous Water Temperature Testing*/
  Serial.println("Temperatures"); //prints "Temperatures" to the serial, will be used for logging into Text File
  Serial.print("Minute "); //prints "Minute ", will be used in conjunction with time variable
  Serial.println(var); //prints the minute variable (is actually the time the loop has continued, while each loop takes 60 seconds)
  //Temperature sensor 1 code (Do not EDIT, comes from Manufacture's Website)
  int rawvoltage1 = analogRead(OutPutPin1);
  float millivolts1 = (rawvoltage1/1024.0) * 5000;
  float fahrenheit1 = millivolts1/10;
  Serial.print(fahrenheit1);
  Serial.println(" degrees Fahrenheit, Tank 1,");
  /*Logic Gates*/
  if (fahrenheit1 <= 68){
      digitalWrite(HeatElPin1, HIGH); //sets the pin for tank 1 heating element to 5V 
  }
  if (fahrenheit1 >= 79) {
      digitalWrite(HeatElPin1, LOW); //turns heating element for tank 1 off
  }
  delay(60000);
  var= var + 1;
}
