void setup() {
  Serial.begin(9600); 
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  // variables for timekeeping:
  float t;
  float t2;
  t=millis(); // get current time 
  //on-------------------------------------------------
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(5000);
  t2 = millis()-t; // time for calculations
  // output results:
  Serial.print("time for  ON  in us: ");
  Serial.println(t2 ); 
  delay(10000);                       // wait for 10  second  
  // this is actually required or the compiler will reomve the for loops 
  // above as part of the optimization during compiling.
  
  //off---------------------------------------
  t=millis(); // get current time 
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(5000);
  t2 = millis()-t; // time for calculations
  // output results:
  Serial.print("time for OFF in us: ");
  Serial.println(t2); 
  delay(10000);                       // wait for 10  second
  // this is actually required or the compiler will reomve the for loops 
  // above as part of the optimization during compiling.
  
}
