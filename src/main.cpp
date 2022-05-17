#include <Arduino.h>
#include <FastLED.h>

/*
//Constants
#define NUM_STRIPS 1
#define NUM_LEDS 120
#define BRIGHTNESS 50
#define LED_TYPE WS2812
#define COLOR_ORDER BRG//RGB
#define FASTLED_ALLOW_INTERRUPTS 0
#define FASTLED_INTERRUPT_RETRY_COUNT 1
#define FRAMES_PER_SECOND 120
#define COOLING 255
#define SPARKING 120

//Parameters
const int stripPin  = 7;
const int stripPin1  = 8;

//Variables
bool gReverseDirection  = true;

//Objects
CRGB leds[NUM_LEDS];
CRGB leds1[NUM_LEDS];

void ledScenario(void ) {  //function ledScenario
  ////LEDS Strip scenario
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Goldenrod;
    leds[i].setRGB(255, 0, 255);
    leds[i + 3].setRGB(255, 0, 255);
    FastLED.show();
    delay(50);
    leds[i] = CRGB::BlanchedAlmond;
    leds[i-1] = CRGB::DarkRed;
    FastLED.show();
    delay(50);
  }
}



void setup() {
  //Init Serial USB
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
  //Init led strips
  FastLED.addLeds<LED_TYPE, stripPin, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.addLeds<LED_TYPE, stripPin1, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  ledScenario();
}

*/

#define LED_PIN 7
#define LED_PIN2 8
#define PLAYER_1 2
#define PLAYER_2 3
#define NUM_LEDS 120

CRGB leds[NUM_LEDS];
CRGB leds2[NUM_LEDS];

int posPlayer1()
{
  int x = 0;
  if (digitalRead(2) == LOW)
  {
    Serial.println("boup");
    x++;
    return x;
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2813, LED_PIN2, GRB>(leds2, NUM_LEDS);
  FastLED.setBrightness(100);
}

void loop()
{

  static int i = 0;
  if (digitalRead(2) == LOW)
  {
    Serial.print("boup/");
    i++;
  }
  Serial.println(i);
  leds[i] = CRGB::Red;
  FastLED.show();
  leds[i] = CRGB::Black;
  FastLED.show();
  if ( i == 119){
    i = 0;
  }

  

  

  // leds2[i] = CRGB::DarkCyan;
  // FastLED.delay(33);
  // leds[i] = CRGB::Black;
  // leds2[i] = CRGB::Black;
}
