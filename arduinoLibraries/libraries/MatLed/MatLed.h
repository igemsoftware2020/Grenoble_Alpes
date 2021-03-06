#ifndef MatLed_h
#define MatLed_h
#include "Arduino.h"
#include <FastLED.h>

//definition du pin où brancher la matrice de led
#define PIN_MATLED 4

//dimention de la matrice
#define NB_LED_X 16
#define NB_LED_Y 6


//definition de la classe MatLed
class MatLed : public OperatingClass{
  //declaration des prototypes

public:
  /*constructeur initiant les leds et les arguments*/
  MatLed();

  /*affiche les leds dans l etat demande*/
  uint8_t show(uint8_t notuse);

  /*allumer 1 led en position (posX;posY), en RGB par default
  retourne 0 si echec, 1 si réussite*/
  uint8_t RGB_1Led(uint8_t notuse);

  /*etteind 1 led en position (posX;posY)
  retourne 0 si echec, 1 si réussite*/
  uint8_t Black_1Led(uint8_t notuse);


  /*allumer 1 ligne de leds en position (posY), en RGB par default
  retourne 0 si echec, 1 si réussite*/
  uint8_t RGB_ligne(uint8_t notuse);

  /*etteind 1 ligne de leds en position (posY)
  retourne 0 si echec, 1 si réussite*/
  uint8_t Black_ligne(uint8_t notuse);


  /*allumer 1 colonne de leds, en position (posX), en RGB par default
  retourne 0 si echec, 1 si réussite*/
  uint8_t RGB_column(uint8_t notuse);

  /*etteind 1 colonne de leds, en position (posX)
  retourne 0 si echec, 1 si réussite*/
  uint8_t Black_column(uint8_t notuse);


  /*allume toutes les leds, en RGB par defaulte*/
  uint8_t RGB_all(uint8_t notuse);

  /*etteint toutes les leds*/
  uint8_t Black_all(uint8_t notuse);


private:
  /*convertie les coordonnees au numero de la led
  retourne le numero de la led, ou -1 si erreur*/
  uint8_t coord_to_num(uint8_t posX, uint8_t posY);


	void SetNbArgMeth();
	
	void SetArgMeth_inTab();

  void Setup();


  //declaration des arguments
  uint8_t pin;    //pin de la matrice
  uint8_t nbLedx; //nombre de led selon l axe X
  uint8_t nbLedy; //nombre de led selon l axe Y
  uint8_t posX;
  uint8_t posY;
  uint8_t red_default;    //le rouge par default
  uint8_t green_default;  //le vert par default
  uint8_t blue_default;   //le bleu par default
  CRGB Tableds[NB_LED_X*NB_LED_Y];     //le tableau des leds
};

#endif
