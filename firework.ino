/*
################################################################################
# File Name:             MAX7219_5.ino                                             
# Board:                 Arduino UNO         
# Programming Language:	 Wiring / C /Processing /Fritzing / Arduino IDE          
#						
# Objective:             Scrolling LED dot Matrix
#										  
# Operation:	         Scrolls a message over a 16x8 LED dot matrix
#			
# Author:                Marcelo Moraes 
# Date:                  July 9th, 2013	
# Place:                 Sorocaba - SP - Brazil	
#					
################################################################################
 
 This code is a public example.
 */



//******************************************************************************
// visit this web page for further information about MaxMatrix library
// https://code.google.com/p/arudino-maxmatrix-library/
//******************************************************************************


#include <MaxMatrix.h>
#include <avr/pgmspace.h>

#define CH_SIZE 10

PROGMEM prog_uchar CH[] = {
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10101010,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01010101,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10101010,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01010101,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10101010,B01010101,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01010101,B10101010,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B10101010,B01010101,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B01010101,B10101010,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00010000,B11111111,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00010000,B00000000,B11111111,
8,8,B00000000,B00000000,B00000000,B00000000,B00010000,B00000000,B00000000,B11111111,
8,8,B00000000,B00000000,B00000000,B00010000,B00000000,B00000000,B00000000,B11111111,
8,8,B00000000,B00000000,B00010000,B00101000,B00010000,B00000000,B00000000,B11111111,
8,8,B00000000,B00000000,B00101000,B00010000,B00101000,B00000000,B00000000,B11111111,
8,8,B00000000,B00010000,B01010100,B00101000,B01010100,B00010000,B00000000,B11111111,
8,8,B00000000,B00010000,B01000100,B00000000,B01000100,B00010000,B00000000,B11111111,
8,8,B00000000,B00010000,B01000000,B00000000,B00000100,B00010000,B00000000,B11111111,
8,8,B00000000,B00010000,B00000000,B00000000,B00000100,B00000000,B00000000,B11111111,
8,8,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B11111111,
};

int data = 8;    // DIN pin of MAX7219 module
int load = 9;    // CS pin of MAX7219 module
int clock = 10;  // CLK pin of MAX7219 module
int maxInUse = 1;    //change this variable to set how many MAX7219's you'll use

MaxMatrix m(data, load, clock, maxInUse); // define module

byte buffer[CH_SIZE];

void setup(){
  m.init(); // module initialize
  m.setIntensity(0); // dot matix intensity 0-15
}

void loop(){

  for (int c=0; c<sizeof(CH)/CH_SIZE; c++)
  {
    memcpy_P(buffer, CH + CH_SIZE*c, CH_SIZE);
    m.writeSprite(0, 0, buffer);
    m.setColumn(0 + buffer[0], 0);
    delay(1000);
  }
}

