// MultiArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
//  different pins, each strip getting its own CRGB array to be played with

#include "FastLED.h"

#define delayms 300
#define fuseDelay 50
#define bombDelay 60
#define gearDelay 25

//set nubmer of LEDs per strip
#define NUM_LEDS_B_STRIP 23
#define NUM_LEDS_BOMB_STRIP 38 
#define NUM_LEDS_M_STRIP 29
//#define NUM_LEDS_DASH_STRIP 4
#define NUM_LEDS_GEAR_STRIP 21
#define NUM_LEDS_T_STRIP 12
#define NUM_LEDS_Z_STRIP 14
#define NUM_LEDS_BOMBRING1 2
#define NUM_LEDS_BOMBRING2 10
#define NUM_LEDS_BOMBRING3 6
#define NUM_LEDS_BOMBRING4 20

//set data pin for LED strip
#define DATA_PIN_B1 3
#define DATA_PIN_BOMB 4
#define DATA_PIN_M 5
#define DATA_PIN_B2 6
//#define DATA_PIN_DASH 7
#define DATA_PIN_B3 8
#define DATA_PIN_GEAR 9
#define DATA_PIN_T 10
#define DATA_PIN_Z 11

//create arrays of LED strip
CRGB ledsB1[NUM_LEDS_B_STRIP];
CRGB ledsBomb[NUM_LEDS_BOMB_STRIP];
CRGB ledsM[NUM_LEDS_M_STRIP];
CRGB ledsB2[NUM_LEDS_B_STRIP];
//CRGB ledsDash[NUM_LEDS_DASH_STRIP];
CRGB ledsB3[NUM_LEDS_B_STRIP];
CRGB ledsGear[NUM_LEDS_GEAR_STRIP];
CRGB ledsT[NUM_LEDS_T_STRIP];
CRGB ledsZ[NUM_LEDS_Z_STRIP];

//leds for the fuse
uint8_t masterFuse[10] = {0,1,2,3,4,5,8,14,21,22};
uint8_t bombRing1[NUM_LEDS_BOMBRING1] = {21,22};
uint8_t bombRing2[NUM_LEDS_BOMBRING2] = {13,14,15,24,23,20,19,28,29,30};
uint8_t bombRing3[NUM_LEDS_BOMBRING3] = {8,12,16,27,31,35};
uint8_t bombRing4[NUM_LEDS_BOMBRING4] = {0,1,2,3,4,5,6,7,9,10,11,17,18,25,26,32,33,34,36,37};

uint8_t ringVal[NUM_LEDS_BOMB_STRIP];


// just addLeds multiple times, once for each strip
void setup() {
  Serial.begin(9600);

  //loads ring value for ring 1  
  for(uint8_t i = 0; i < NUM_LEDS_BOMBRING1; i++) {
    ringVal[bombRing1[i]] = 1;
   // Serial.println(ringVal[bombRing1[i]]);
  }
  //loads ring value for ring 2
  for(uint8_t i = 0; i < NUM_LEDS_BOMBRING2; i++) {
    ringVal[bombRing2[i]] = 2;
    //Serial.println(ringVal[bombRing2[i]]);
  }
  //loads ring value for ring 3
  for(uint8_t i = 0; i < NUM_LEDS_BOMBRING3; i++) {
    ringVal[bombRing3[i]] = 3;
    //Serial.println(ringVal[bombRing3[i]]);
  }
  //loads ring value for ring 4
  for(uint8_t i = 0; i < NUM_LEDS_BOMBRING4; i++) {
    ringVal[bombRing4[i]] = 4;
   // Serial.println(ringVal[bombRing4[i]]);
  }
  
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_B1
  FastLED.addLeds<NEOPIXEL, DATA_PIN_B1>(ledsB1, NUM_LEDS_B_STRIP);

  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_BOMB
  FastLED.addLeds<NEOPIXEL, DATA_PIN_BOMB>(ledsBomb, NUM_LEDS_BOMB_STRIP);

  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_M
  FastLED.addLeds<NEOPIXEL, DATA_PIN_M>(ledsM, NUM_LEDS_M_STRIP);
  
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_B2
  FastLED.addLeds<NEOPIXEL, DATA_PIN_B2>(ledsB2, NUM_LEDS_B_STRIP);
  
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_DASH
  //FastLED.addLeds<NEOPIXEL, DATA_PIN_DASH>(ledsDash, NUM_LEDS_DASH_STRIP);
  
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_B3
  FastLED.addLeds<NEOPIXEL, DATA_PIN_B3>(ledsB3, NUM_LEDS_B_STRIP);
  
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_GEAR
  FastLED.addLeds<NEOPIXEL, DATA_PIN_GEAR>(ledsGear, NUM_LEDS_GEAR_STRIP);
  
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_T
  FastLED.addLeds<NEOPIXEL, DATA_PIN_T>(ledsT, NUM_LEDS_T_STRIP);
    
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_Z
  FastLED.addLeds<NEOPIXEL, DATA_PIN_Z>(ledsZ, NUM_LEDS_Z_STRIP);

}

void b1Black() {
  for( CRGB &pixel : ledsB1 ) { 
    pixel = CRGB::Black; 
  }
}

void b1White() {
  for( CRGB &pixel : ledsB1 ) { 
    pixel = CRGB::White; 
  }
}

void bombBlack() {
  for( CRGB &pixel : ledsBomb ) { 
    pixel = CRGB::Black; 
  }
}

void bombWhite() {
  for( CRGB &pixel : ledsBomb ) { 
    pixel = CRGB::White; 
  }
}
void mBlack() {
  for( CRGB &pixel : ledsM ) { 
    pixel = CRGB::Black; 
  }
}

void mWhite() {
  for( CRGB &pixel : ledsM ) { 
    pixel = CRGB::White; 
  }
}
void b2Black() {
  for( CRGB &pixel : ledsB2 ) { 
    pixel = CRGB::Black; 
  }
}

void b2White() {
  for( CRGB &pixel : ledsB2 ) { 
    pixel = CRGB::White; 
  }
}
//void dashBlack() {
//  for( CRGB &pixel : ledsDash ) { 
//    pixel = CRGB::Black; 
//  }
//}

//void dashWhite() {
//  for( CRGB &pixel : ledsDash ) { 
//    pixel = CRGB::White; 
//  }
//}
void b3Black() {
  for( CRGB &pixel : ledsB3 ) { 
    pixel = CRGB::Black; 
  }
}

void b3White() {
  for( CRGB &pixel : ledsB3 ) { 
    pixel = CRGB::White; 
  }
}
void gearBlack() {
  for( CRGB &pixel : ledsGear ) { 
    pixel = CRGB::Black; 
  }
}

void gearWhite() {
  for( CRGB &pixel : ledsGear ) { 
    pixel = CRGB::White; 
  }
}
void tBlack() {
  for( CRGB &pixel : ledsT ) { 
    pixel = CRGB::Black; 
  }
}

void tWhite() {
  for( CRGB &pixel : ledsT ) { 
    pixel = CRGB::White; 
  }
}
void zBlack() {
  for( CRGB &pixel : ledsZ ) { 
    pixel = CRGB::Black; 
  }
}

void zWhite() {
  for( CRGB &pixel : ledsZ ) { 
    pixel = CRGB::White; 
  }
}

void allOn(){
  b1White();
  bombWhite();
  mWhite();
  b2White();
//  dashWhite();
  b3White();
  gearWhite();
  tWhite();
  zWhite();
  
}

void allOff(){
  b1Black();
  bombBlack();
  mBlack();
  b2Black();
//  dashBlack();
  b3Black();
  gearBlack();
  tBlack();
  zBlack();

}

void allOnDelay(){
  b1White();
  FastLED.show();
  delay(delayms);
  bombWhite();
  FastLED.show();
  delay(delayms);
  mWhite();
  FastLED.show();
  delay(delayms);
  b2White();
  FastLED.show();
  delay(delayms);
//  dashWhite();
//  FastLED.show();
//  delay(delayms);
  b3White();
  FastLED.show();
  delay(delayms);
  gearWhite();
  FastLED.show();
  delay(delayms);
  tWhite();
  FastLED.show();
  delay(delayms);
  zWhite();
  FastLED.show();
  delay(delayms);
}

void lightFuse() {
  for(uint8_t i = 0; i < 12; i++) {
    if( i < 10 ) {
         ledsBomb[ masterFuse[i] ] = CRGB::Yellow;
    }
    if( i > 0 ) {
         ledsBomb[ masterFuse[i-1] ] = CRGB::Red; 
    }
   if( i > 1 ) {
         ledsBomb[ masterFuse[i-2] ] = CRGB::Black; 
         
   }
  FastLED.show();
  delay(fuseDelay); 
  }
}

void bombExp() {
  bombBlack();
  FastLED.show();
  for( uint8_t x = 1; x <= 6; x++ ) {
    for ( uint8_t i = 0; i < NUM_LEDS_BOMB_STRIP; i++) {
      if( ringVal[i] == x ) {
        ledsBomb[i] = CRGB::Yellow;
      }
      if ( ringVal[i] == (x - 1)) {
        ledsBomb[i] = CRGB::Red; 
      }
      if ( ringVal[i] == (x - 2)) {
        ledsBomb[i] = CRGB::Black; 
      }      
    }
  //gearCylon();
  FastLED.show();
  FastLED.delay(bombDelay);
  }
}

void gearCylon() {
  Serial.println("in gearCylon()");
  gearBlack();
  FastLED.show();
  for( uint8_t j = 0; j < NUM_LEDS_GEAR_STRIP; j++ ) {
    ledsGear[j] = CRGB::PaleTurquoise;
    if(j < NUM_LEDS_GEAR_STRIP) {
     ledsGear[j + 1] = CRGB::Gold;  
    }
    if(j > 0 ) {
      //ledsGear [j - 1] = CRGB::Black;
    }
    FastLED.show();
    FastLED.delay(gearDelay);   
  }
  gearBlack();
  FastLED.show();
  for(int j = (NUM_LEDS_GEAR_STRIP - 1); j >= 0 ; j-- ) {
    //Serial.print("j=");
    //Serial.println(j);
    ledsGear[j] = CRGB::Gold;
    if(j < NUM_LEDS_GEAR_STRIP - 1) {
       ledsGear[j + 1] = CRGB::Gold;

    }
    if(j < NUM_LEDS_GEAR_STRIP - 1 ) {
      ledsGear[j + 1] = CRGB::Red; 
    }
    FastLED.show();
    FastLED.delay(gearDelay);   
  }
  gearBlack();
  FastLED.show();
  Serial.println("exit gearCylon()");
}



/*
void bombExp() {
 for(uint8_t i = 0;i < NUM_LEDS_BOMBRING1;i++) {
   ledsBomb[ bombRing1[i] ] = CRGB::Red;
 }
   FastLED.show();
   delay(fuseDelay); 

   for(uint8_t i = 0;i < NUM_LEDS_BOMBRING2;i++) {
   ledsBomb[ bombRing2[i] ] = CRGB::Red;
  }
   FastLED.show();
   delay(fuseDelay)

    for(uint8_t i = 0;i < NUM_LEDS_BOMBRING3;i++) {
   ledsBomb[ bombRing3[i] ] = CRGB::Red;
  }
   FastLED.show();
   delay(fuseDelay); 

   for(uint8_t i = 0;i < NUM_LEDS_BOMBRING4;i++) {
   ledsBomb[ bombRing4[i] ] = CRGB::Red;
  }
   FastLED.show();
   delay(fuseDelay); 
   
}*/

void loop() {

  //b1Black();
  allOnDelay();

  FastLED.show();
  FastLED.delay(delayms);

  bombBlack();
  FastLED.show();


  lightFuse();
  //FastLED.delay(delayms);
  bombExp();
  FastLED.delay(delayms);

  gearCylon();
  //dfsFastLED.show();
  gearCylon();
 
  allOff();
 // b1White();
  FastLED.show();
  FastLED.delay(delayms);
  
/*  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    // set our current dot to red, green, and blue
    redLeds[i] = CRGB::Red;
    greenLeds[i] = CRGB::Green;
    blueLeds[i] = CRGB::Blue;
    FastLED.show();
    // clear our current dot before we move on
    redLeds[i] = CRGB::Black;
    greenLeds[i] = CRGB::Black;
    blueLeds[i] = CRGB::Blue;
    delay(100);
  }

  for(int i = NUM_LEDS_PER_STRIP-1; i >= 0; i--) {
    // set our current dot to red, green, and blue
    redLeds[i] = CRGB::Red;
    greenLeds[i] = CRGB::Green;
    blueLeds[i] = CRGB::Blue;
    FastLED.show();
    // clear our current dot before we move on
    redLeds[i] = CRGB::Black;
    greenLeds[i] = CRGB::Black;
    blueLeds[i] = CRGB::Blue;
    delay(100);
   
  }  */
}
