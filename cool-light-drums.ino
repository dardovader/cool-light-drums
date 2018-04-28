#include <Button.h>
#include<FastLED.h>



// Pines digitales
const int BOTON_PIN_1 = 3;
const int LED_PIN_1 = 5;
const int LED_PIN_2 = 7;


// Entrada analógicas
#define PIN_PIEZO_1 A0
#define  PIN_PIEZO_2 A1
#define PIN_UMBRAL_P1 A2
#define PIN_UMBRAL_P2 A3

// Número de leds de cada tira
const int NUM_LEDS_1=29;
const int NUM_LEDS_2 =29;

#define USAR_POTES false

// Sensibilidad de cada piezo
const int default_umbral_1 = 500;
const int default_umbral_2 = 600;

int umbral_1 = default_umbral_1;
int umbral_2 = default_umbral_2;

// Tonos color
const byte MAGENTA=214;
const byte VERDE=96;

const byte brillo = 128;


int modo = 0;

CRGB leds1[NUM_LEDS_1];
CRGB leds2[NUM_LEDS_2];

int lectura_1;
int lectura_2;

Button boton_1(BOTON_PIN_1);

void setup() {
  Serial.begin(115200);
  LEDS.addLeds<WS2812B,LED_PIN_1,GRB>(leds1,NUM_LEDS_1);
  LEDS.addLeds<WS2812B,LED_PIN_2,GRB>(leds2,NUM_LEDS_2);
  boton_1.begin();
  delay(2000);
  Serial.println("It's showtime!");
  umbral_1=default_umbral_1;
  umbral_2=default_umbral_2;
}

void loop() {
  static int pom1 = 0;
  static int pom2 = 0;

  if (USAR_POTES) 
  {
    umbral_1 = analogRead(PIN_UMBRAL_P1);
    umbral_2 = analogRead(PIN_UMBRAL_P2);
  }
  
  fadeall();
  lectura_1 = analogRead(PIN_PIEZO_1);
  lectura_2 = analogRead(PIN_PIEZO_2);
  //Serial.println(lectura_2);
  if (boton_1.released())
  {
    Serial.println("Botonazo");
    if (modo==0)
    {
      modo=1;
    }
    else 
    {
      modo=0;
    }
    Serial.print("Modo ");
    Serial.println(modo);
  }

  
  if (lectura_1 > umbral_1)
  {
    pom1++;
    Serial.print("¡POM 1! ");  Serial.print(lectura_1); Serial.print(" ");Serial.println(pom1);
    
    if (modo==0)
    {
      modo0_pintarLeds_1(); 
    }
    else 
    {
      modo1_pintarLeds_1();
    }

  }

  if (lectura_2 > umbral_2)
  {
    pom2++;
    Serial.print("¡POM 2! ");  Serial.print(lectura_2); Serial.print(" ");Serial.println(pom2);
    if (modo==0)
    {
      modo0_pintarLeds_2(); 
    }
    else 
    {
      modo1_pintarLeds_2();
    }
  }
  
  FastLED.show(brillo); 
 // FastLED.delay(1000/60);
}


void modo0_pintarLeds_1() 
{
  for (int i ; i< NUM_LEDS_1; i++)
  {
   leds1[i]=CRGB(255,255,255);
  }
}


void modo0_pintarLeds_2() 
{
  for (int i ; i< NUM_LEDS_1; i++)
  {
    leds2[i]=CRGB(255,255,255);
   //leds2[i]=CHSV(i+128,255,255);
  }
}

void modo1_pintarLeds_1() 
{
  for (int i ; i< NUM_LEDS_1; i++)
  {
   leds1[i]=CHSV(MAGENTA,255,255);
  }
}


void modo1_pintarLeds_2() 
{
  for (int i ; i< NUM_LEDS_1; i++)
  {
   leds2[i]=CHSV(96,255,255);
  }
}


void fadeall()
{
  for(int i = 0; i < NUM_LEDS_1; i++)
  {
    leds1[i].nscale8(128);
  }
    for(int i = 0; i < NUM_LEDS_2; i++)
  {
    leds2[i].nscale8(128);
  }
}



