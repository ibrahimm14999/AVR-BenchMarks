void setup()
{
  Serial.begin(9600); 
// setting DDRB as output
DDRB = B00100000;
}
void loop()
{
  // variables for timekeeping:
  float t;
  float t2;
  t=millis(); // get current time 
  //on-------------------------------------------------
  
  PORTB = B00100000; // Turn on LED
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
  PORTB = B00000000; // Turn off LED
  delayMicroseconds(5000);
  t2 = millis()-t; // time for calculations
  // output results:
  Serial.print("time for OFF in us: ");
  Serial.println(t2); 
  delay(10000);                       // wait for 10  second
  // this is actually required or the compiler will reomve the for loops 
  // above as part of the optimization during compiling.
  
}
