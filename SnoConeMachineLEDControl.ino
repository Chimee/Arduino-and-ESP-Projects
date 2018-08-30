#include <Adafruit_NeoPixel.h>

//SnoconeMachineLEDControl

//const int pumptest = 52;
#define P1   52

#define P2   50

//Define Pump Pins

//Forward Pin Definitions

#define P1F 23
#define P2F 29 
#define P3F 31 
#define P4F 37 
#define P5F 39 
#define P6F  45 
#define P7F  47 

#define P8F  53 
#define P9F  22 
#define P10F  28 
#define P11F  30 
#define P12F  36 
#define P13F  38 
#define P14F  44 
#define P15F  46 
#define P16F  52 
#define P17F  2 
#define P18F  5

//Reverse Pin Definitions

#define P1R  25 
#define P2R  27 
#define P3R  33 
#define P4R  35 
#define P5R  41 
#define P6R  43 
#define P7R  49 
#define P8R  51 
#define P9R  24 
#define P10R  26 
#define P11R  32 
#define P12R  34 
#define P13R  40 
#define P14R  42 
#define P15R  58 
#define P16R  50 
#define P17R  3 
#define P18R  4

//const int PIXEL_PIN =  22;  

#define PIXEL_PIN    2

#define PIXEL_COUNT 144

int section1CW1 = 8;

int section2CW1 = 15;

int section3CW1 = 22;

int section4CW1 = 29;


Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

bool oldPumpState = HIGH;

bool pumpState = LOW;

bool pump2State = LOW;

void setup() {
  Serial.begin(9600);

  pinMode(PIXEL_PIN, OUTPUT);
 pinMode(P1F, INPUT);
 pinMode(P2F, INPUT);
 pinMode(P3F, INPUT);
 pinMode(P4F, INPUT);
  pinMode(P5F, INPUT);
 pinMode(P6F, INPUT);
 pinMode(P7F, INPUT);
 pinMode(P8F, INPUT);
  pinMode(P9F, INPUT);
 pinMode(P10F, INPUT);
 pinMode(P11F, INPUT);
 pinMode(P12F, INPUT);
  pinMode(P13F, INPUT);
 pinMode(P14F, INPUT);
 pinMode(P15F, INPUT);
 pinMode(P16F, INPUT);
  pinMode(P17F, INPUT);
 pinMode(P18F, INPUT);

 //Set Reverse Pins as Inputs
 pinMode(P1R, INPUT);
 pinMode(P2R, INPUT);
  pinMode(P3R, INPUT);
 pinMode(P4R, INPUT);
  pinMode(P5R, INPUT);
 pinMode(P6R, INPUT);
 pinMode(P7R, INPUT);
 pinMode(P8R, INPUT);
  pinMode(P9R, INPUT);
 pinMode(P10R, INPUT);
 pinMode(P11R, INPUT);
 pinMode(P12R, INPUT);
  pinMode(P13R, INPUT);
 pinMode(P14R, INPUT);
 pinMode(P15R, INPUT);
 pinMode(P16R, INPUT);
  pinMode(P17R, INPUT);
 pinMode(P18R, INPUT);

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}


void loop() {


  // pumpState = digitalRead(P1F);

//if (pumpState == HIGH) {

  Serial.print(" P1 clockwise: ");
  Serial.print(digitalRead(P1F));

  Serial.print(" P1 Reverse: ");
  Serial.print(digitalRead(P1R));

  if ((digitalRead(P1F) == 0 ) && (digitalRead(P1R) == 0 ) && (digitalRead(P2F) == 0 ) && (digitalRead(P2R) == 0 ) && 
      (digitalRead(P3F) == 0 ) && (digitalRead(P3R) == 0 ) && (digitalRead(P4F) == 0 ) && (digitalRead(P4R) == 0 ) &&
      (digitalRead(P5F) == 0 ) && (digitalRead(P5R) == 0 ) && (digitalRead(P6F) == 0 ) && (digitalRead(P6R) == 0 ) &&
      (digitalRead(P7F) == 0 ) && (digitalRead(P7R) == 0 ) && (digitalRead(P8F) == 0 ) && (digitalRead(P8R) == 0 ) &&
      (digitalRead(P9F) == 0 ) && (digitalRead(P9R) == 0 ) && (digitalRead(P10F) == 0 ) && (digitalRead(P10R) == 0 ) &&
      (digitalRead(P11F) == 0 ) && (digitalRead(P11R) == 0 ) && (digitalRead(P12F) == 0 ) && (digitalRead(P12R) == 0 ) &&
      (digitalRead(P13F) == 0 ) && (digitalRead(P13R) == 0 ) && (digitalRead(P14F) == 0 ) && (digitalRead(P14R) == 0 ) &&
      (digitalRead(P15F) == 0 ) && (digitalRead(P15R) == 0 ) && (digitalRead(P16F) == 0 ) && (digitalRead(P16R) == 0 )) &&
       (digitalRead(P17F) == 0 ) && (digitalRead(P17R) == 0 ) && (digitalRead(P18F) == 0 ) && (digitalRead(P18R) == 0 ))
      
      {
          //Play StandBy Animation0
          Serial.print("Stand By Animation Playing")
          standbypattern(1)
        
      }

  if ((digitalRead(P1F) == 1) && (digitalRead(P1R) == 0 )) {

    section1CW(5);
    colorWipe(strip.Color(0, 255, 0), 50);  // Red

    
    
  }


  if ((digitalRead(P1F) == 1) && (digitalRead(P1R) == 1 )) {

    section1CW(5);
    
    section1R(5);

    
    
  }
  
 // section1CW(20);
  
//}



}


/

void standbypattern(uint8_t wait) {


  
}


//P1F Rainbow
void section1F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<8; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P2F Rainbow
void section2F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=8; i<15; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P3F Rainbow
void section3F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section4F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section5F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section6F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section7F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section8F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section9F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section10F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section11F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section12F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section13F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section14F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section15F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section16F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section17F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4F Rainbow
void section18F(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<section1CW1; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 


//////REVERSE PATTERN FUNCTIONS!

//P1R Rainbow
void section1R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P2R Rainbow
void section2R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P3R Rainbow
void section3R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P4R Rainbow
void section4R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P5R Rainbow
void section5R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P6R Rainbow
void section6R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P7R Rainbow
void section7R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P8R Rainbow
void section8R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P9R Rainbow
void section9R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P10R Rainbow
void section10R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P11R Rainbow
void section11R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P12R Rainbow
void section12R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P13R Rainbow
void section13R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P14R Rainbow
void section14R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P15R Rainbow
void section15R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P16R Rainbow
void section16R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P17R Rainbow
void section17R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 

//P18R Rainbow
void section18R(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=15; i<30; i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }

    strip.show();

    
  }
} 




// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=15; i<30; i++) {
    strip.setPixelColor(i, c);

  }

  strip.show();

}


uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
