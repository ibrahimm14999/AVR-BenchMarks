#define DELAY_VALUE     5
  
void setup() {
  Serial.begin(9600);
  asm volatile (
    "sbi %0, %1 \n" //pinMode(13, OUTPUT);
    : : "I" (_SFR_IO_ADDR(DDRB)), "I" (DDB5)
  );
}
  
void loop() {
  float t,t2;
  t=millis();
  asm volatile (
    "mov r18, %D2 \n" //save for second delay iteration
    "mov r20, %C2 \n"
    "mov r21, %B2 \n"
  
    "sbi %0, %1   \n" //turn LED on
  
  "1:             \n" //delay ~1 second
    "subi %A2, 1  \n"
    "sbci %B2, 0  \n"
    "sbci %C2, 0  \n"
    "brcc 1b      \n"
   
    : : "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB5), "r" (DELAY_VALUE) : "r18", "r19", "r20"
    
  );
 t2 = millis()-t; // time for calculations
 Serial.print("Time ON  in  us:");
 Serial.println(t2);
 delay(10000);
 t=millis();
 asm volatile(
   "cbi %0, %1   \n" //turn LED off
    
  "2:             \n" //delay ~1 second
    "subi r18, 1  \n"
    "sbci r19, 0  \n"
    "sbci r20, 0  \n"
    "brcc 2b      \n"
    
    : : "I" (_SFR_IO_ADDR(PORTB)), "I" (PORTB5), "r" (DELAY_VALUE) : "r18", "r19", "r20"
  );
  t2 = millis()-t; // time for calculations
  Serial.print("Time OFF  in  us:");
  Serial.println(t2);
  delay(10000);
}
