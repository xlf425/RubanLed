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

void winner(int player)
{
if (player = 0){
  static int state = 0;

    if (state == 0)
    {
      for (int i = 0; i < NUM_LEDS - 1; i++)
      {
        leds[i] = CRGB::Green;
        leds2[i] = CRGB::Red;
      }
    }
    else
    {
      for (int i = 0; i < NUM_LEDS - 1; i++)
      {
        leds[i] = CRGB::Black;
      }
    }
    state = !state;

    FastLED.show();
    delay(300);
    FastLED.clear();
}
if (player = 1){
  static int state = 0;

    if (state == 0)
    {
      for (int i = 0; i < NUM_LEDS - 1; i++)
      {
        leds2[i] = CRGB::Green;
        leds[i] = CRGB::Red;
      }
    }
    else
    {
      for (int i = 0; i < NUM_LEDS - 1; i++)
      {
        leds2[i] = CRGB::Black;
      }
    }
    state = !state;

    FastLED.show();
    delay(300);
    FastLED.clear();
}
}

void setup()
{
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2813, LED_PIN2, GRB>(leds2, NUM_LEDS);
  FastLED.setBrightness(10);
}

void loop()
{
  static int i = 105;

  if (i == 119)
  {
    
  }
  else
  {
    int currentState = digitalRead(2);
    static int previousState = HIGH;

    if (currentState == LOW)
    {
      if (previousState == HIGH)
      {
        i++;
      }
    }
    previousState = currentState;
    Serial.println(i);
    leds[i] = CRGB::Red;
    FastLED.show();
    leds[i] = CRGB::Black;
    winner(0);
    FastLED.show();


    /*
    static int movement = 0;
    static int brightness = 0;
    if (movement == 0 && brightness < 254)
    {
      brightness++;
    }
    else if (movement == 1 && brightness > 0)
    {
      brightness--;
    }
    else if (brightness > 254 || brightness < 0)
    {
      movement = !movement;
    }
    delay(50);
    FastLED.setBrightness(brightness);
    */
  }

  // leds2[i] = CRGB::DarkCyan;
  // FastLED.delay(33);
  // leds[i] = CRGB::Black;
  // leds2[i] = CRGB::Black;
}
