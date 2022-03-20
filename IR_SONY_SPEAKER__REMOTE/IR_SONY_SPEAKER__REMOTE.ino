#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
int red_light_pin= 2;
int green_light_pin = 3;
int blue_light_pin = 4;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
//  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
 
//        if (results.value == 0XFFFFFFFF)
//          results.value = key_value;

        switch(results.value){
          case 0x540C:
          Serial.println("0N/OFF");
           RGB_color(255, 0, 0); // Red
           delay(1000);
          break ;
          case 0x4B0D:
          Serial.println("FUNCTION BUTTON");
           RGB_color(0, 255, 0); // Red
  delay(1000);
          break ;
          case 0x5C110:
          Serial.println("USB UP BUTTON");
           RGB_color(0, 0, 255); // Red
  delay(1000);
          break ;
          case 0x640C:
          Serial.println("VOLUME UP");
           RGB_color(255, 255, 0); // Red
  delay(1000);
          break ;
          case 0x240C:
          Serial.println("VOLUME DOWN");
           RGB_color(255, 0, 255); // Red
  delay(1000);
          break ;
        
            
        }
//        key_value = results.value;
        irrecv.resume(); 
  }
}
  void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
