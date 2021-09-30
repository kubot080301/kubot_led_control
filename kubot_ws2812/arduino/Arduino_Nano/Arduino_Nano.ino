#include <Adafruit_NeoPixel.h>  // Install

#define PIN_1 2 
#define PIN_2 3 
#define PIN_3 4 
#define PIN_4 5 

int num = 10; // number of led units, the no.0 unit is the one closest to the wires
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(num, PIN_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(num, PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3 = Adafruit_NeoPixel(num, PIN_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4 = Adafruit_NeoPixel(num, PIN_4, NEO_GRB + NEO_KHZ800);

//declare the variable, strip 
int i, r, g, b, d, s_pos, e_pos;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Arduino Ready...\n");
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();

  for (int i = 0;i < num;i++)
  {
    strip1.setPixelColor(i, 100, 20, 0); // default amber color
    strip2.setPixelColor(i, 100, 20, 0); // default amber color
    strip3.setPixelColor(i, 100, 20, 0); // default amber color
    strip4.setPixelColor(i, 100, 20, 0); // default amber color
  }
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();

  i = 0;
  r = 0;
  g = 0;
  b = 0;
}

void loop() {
  if (stringComplete) {
    if (inputString.startsWith("i"))
    {
      s_pos = inputString.indexOf('i'); //start position
      e_pos = inputString.indexOf('r'); //end position
      i = inputString.substring(s_pos + 1, e_pos).toInt();

      s_pos = inputString.indexOf('r');
      e_pos = inputString.indexOf('g');
      r = inputString.substring(s_pos + 1, e_pos).toInt();

      s_pos = inputString.indexOf('g');
      e_pos = inputString.indexOf('b');
      g = inputString.substring(s_pos + 1, e_pos).toInt();

      s_pos = inputString.indexOf('b');
      e_pos = inputString.indexOf('\n');
      b = inputString.substring(s_pos + 1, e_pos).toInt();

      strip1.setPixelColor(i, r, g, b);
      strip2.setPixelColor(i, r, g, b);
      strip3.setPixelColor(i, r, g, b);
      strip4.setPixelColor(i, r, g, b);
    }

    else if (inputString.startsWith("show"))
    {
      strip1.show();
      strip2.show();
      strip3.show();
      strip4.show();
    }
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    inputString += inChar;

    if (inputString.endsWith("\n")) {
      stringComplete = true;
    }
  }
}
