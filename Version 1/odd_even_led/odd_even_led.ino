// Project done with
// QUEK HUI XIN A0077319X
// YU QING A0104694A
// WONG DING CHUEN U097830N
//17/9/2012


//control the led's on/off by the odd/even number on the remote control

#include <IRremote.h>
 
int RECV_PIN = 11;
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //初始化红外遥控
  pinMode(12,1);
}
 
void loop() {
  if (irrecv.decode(&results)) {
 if(results.value % 2 == 1) //odd number
  {
  digitalWrite(12,1);                
   Serial.println(results.value); 
   }
  else if(results.value % 2 == 0) //even number
  {
   digitalWrite(12,0);           
    Serial.println(results.value);   
  }
    irrecv.resume();
  
}
}
