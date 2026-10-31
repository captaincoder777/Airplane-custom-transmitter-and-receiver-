#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>


Servo throttleESC ; 
Servo pitchServo ;  
Servo rollServo ;   


struct Signal {
  byte throttle ; 
  byte pitch ;    
  byte roll ;     
} ;
Signal data ;


const uint64_t pipeIn = 0xE9E8F0F0E1LL ;
RF24 radio( 7 , 8 ) ; 

unsigned long lastRecvTime = 0 ;


void ResetData() {
  data.throttle = 0 ;   
  data.pitch = 127 ;    
  data.roll = 127 ;     
}

void setup() {
  Serial.begin( 9600 ) ;


  rollServo.attach( 2 ) ;     
  pitchServo.attach( 4 ) ;     
  throttleESC.attach( 5 , 1000 , 2000 ) ; 

  ResetData() ;


  radio.begin() ;
  radio.openReadingPipe( 1 , pipeIn ) ;
  radio.setAutoAck( false ) ;            
  radio.setDataRate( RF24_250KBPS ) ;    
  radio.setPALevel( RF24_PA_MAX ) ;      
  radio.startListening() ;             
}

void recvData() {
  while ( radio.available() ) {
    radio.read( &data , sizeof( Signal ) ) ;
    lastRecvTime = millis() ; 
  }
}

void loop() {
  recvData() ;


  if ( millis() - lastRecvTime > 1000 ) {
    ResetData() ;
  }


  int pwmThrottle = constrain( map( data.throttle , 0 , 255 , 1000 , 2000 ) , 1000 , 2000 ) ;
  int pwmPitch    = constrain( map( data.pitch , 0 , 255 , 1000 , 2000 ) , 1000 , 2000 ) ;
  int pwmRoll     = constrain( map( data.roll , 0 , 255 , 1000 , 2000 ) , 1000 , 2000 ) ;


  throttleESC.writeMicroseconds( pwmThrottle ) ;
  pitchServo.writeMicroseconds( pwmPitch ) ;
  rollServo.writeMicroseconds( pwmRoll ) ;
}