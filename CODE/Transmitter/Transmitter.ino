#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipeOut = 0xE9E8F0F0E1LL ;
RF24 radio( 7 , 8 ) ; 

struct Signal {
  byte throttle ;
  byte pitch ;
  byte roll ;
} ;
Signal data ;

int mapJoystickValues( int val, int lower ,int middle , int upper , bool reverse ) {
  val = constrain( val , lower, upper ) ;
  if (val < middle)
    val = map(val , lower , middle, 0 ,128 ) ;
  else
    val = map(val , middle , upper , 128 , 255 ) ;
  return reverse ? (255 - val) : val ;
}

void setup() {
  Serial.begin( 9600 ) ;

  radio.begin() ;
  radio.openWritingPipe( pipeOut) ;
  radio.setAutoAck(false ) ;            
  radio.setDataRate( RF24_250KBPS ) ;    
  radio.setPALevel(RF24_PA_MAX ) ;      
  radio.stopListening() ;              

  data.throttle = 0 ;
  data.pitch = 127 ;
  data.roll = 127 ;
}

void loop() {
  int throttleRaw = analogRead( A0 ) ;
  int rollRaw  = analogRead( A1 ) ;
  int pitchRaw = analogRead( A2 ) ;

  data.throttle = mapJoystickValues( throttleRaw , 0 , 512 , 1023 , false ) ;
  data.roll = mapJoystickValues( rollRaw , 0 , 512 , 1023 , true ) ;
  data.pitch = mapJoystickValues( pitchRaw , 0 , 512 , 1023 , true ) ;

  radio.write( &data , sizeof( Signal ) ) ;

  delay( 20 ) ;
}