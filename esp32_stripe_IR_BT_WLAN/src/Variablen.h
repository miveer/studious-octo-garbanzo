#pragma once
#include "IRremote.h"
#include <NeoPixelBrightnessBus.h>
#include "musik_config.h"


// IR Remote
const uint16_t kRecvPin = 32;
IRrecv irrecv(kRecvPin);
decode_results results;

// WIFI
const char* ssid     = "Vodafone-5E38";
const char* password = "DYBPqxpQb6dGqxV8";

// Typen vereinfachen
typedef NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt0800KbpsMethod> RMT0;
typedef NeoPixelBrightnessBus<NeoGrbFeature, NeoEsp32Rmt1800KbpsMethod> RMT1;


// könnte man in der UI im Setup einstellbar machen
int       balllengh[2]          ;        // relative Ball länge
int       balllengh2[2]         ;        // relative Ball länge 
int       balllengh3[2]         ;        // relative Ball länge
int       balllengh4[2]         ;        // relative Ball länge
int       balllengh_max     =  10;        // maximale Ball länge

// Anzahl LED's pro Stripe
const int amountLeds      = 148;                   // Stripelänge // könnte man in der UI im Setup einstellbar machen
const int amountLeds_half = amountLeds / 2;
const int amountLeds_top  = amountLeds + 2;

// Bluetooth 
String bt_inc;

// Speichert Werte Je Stripe für Effecte
bool          durchlaufJeStripe[2]      = {0, 0};
unsigned long timerJeStripe[2]          = {0, 0};
int           LeadingBallStack[2]       = {0, 0};
int           LeadingBall[2]            = {0, 0};
int           LeadingBall2[2]           = {0, 0};
int           LeadingBall3[2]           = {0, 0};
int           LeadingBall4[2]           = {0, 0};
int           BallOverFlow[2]           = {0, 0};
int           BallOverFlowStack[2]      = {0, 0};
int           lavaLampPositon[2]        = {0, 0};
bool          RichtungLavalampe[2]      = {0, 0};
int           stepJeStripe[2]           = {0, 0};
int           lvlJeStripe[2]            = {0, 0};
int           minLvlAvgJeStripe[2]      = {0, 0};
int           maxLvlAvgJeStripe[2]      = {512, 512};
int           peakJeStripe[2]           = {0, 0};
int           volJeStripe[2][SAMPLES]   = {0, 0};
int           volCountJeStripe[2]       = {0, 0};
int           dotcountJeStripe[2]       = {0, 0};
int           stackBallleft[2]          = {0, 0};
int           stackBallright[2]         = {0, 0};
int           LeadingBallleft[2]        = {0, 0};
int           LeadingBallright[2]       = {0, 0};
int           BallOverFlowleft[2]       = {0, 0};
int           BallOverFlowright[2]      = {0, 0};
int           mRainbowStep[2]           = {0, 0};
int           fillupstep[2]             = {0, 0};
bool          durchlauffillup[2]        = {0, 0};
int           fillup2step[2]            = {0, 0};
bool          durchlauffillup2[2]       = {1, 1};
int           fillup3step[2]            = {0, 0};
bool          durchlauffillup3[2]       = {0, 0};
int           fillup4step[2]            = {0, 0};
bool          durchlauffillup4[2]       = {0, 0};
int           stackBallcentreleft[2]    = {0, 0};
int           stackBallcentreright[2]   = {amountLeds - 1, amountLeds - 1};
int           BallOverFlowCentreleft[2] = {0, 0};
int           BallOverFlowCentreright[2] = {0, 0};
RgbColor      fullup4color[2];
RgbColor      fullup4color2[2];
RgbColor      fullup4color3[2];
RgbColor      fullup4color4[2];
RgbColor      fullup3color[2];
RgbColor      fullup3color2[2];
RgbColor      fullup3color3[2];
RgbColor      fullup2color[2];
RgbColor      fullup2color2[2];
RgbColor      lavacolor_hoch[2];
RgbColor      lavacolor_runter[2];
RgbColor      stackcentrecolor_left[2];
RgbColor      stackcentrecolor_right[2];
RgbColor      stackcolor[2];
RgbColor      ballcolor[2];
RgbColor      ballcolor2[2];
RgbColor      ballcolor3[2];
RgbColor      ballcolor4[2];
RgbColor      StroboColor[2];
bool          frist_run_ball2[2];
bool          frist_run_ball3[2];
bool          frist_run_ball4[2];

// Arrays für debugg
String Smodes[3]       = {"Off", "Static", "Effects"};
String SEffects[12]    = {"Strobo", "Ball", "BallStackable", "BallStackableToCenter","Music", "MusicFromCenter", "LavaLamp", "MovingRainbow", "FillUp", "FillUp2", "FillUp3", "FillUp4"};
String SColorMode[5]   = {"Rainbow", "Random", "UserColors", "TwoUsercolors", "ThreeUserColors"};
String farbauswahl[16] = {"rot", "hellrot", "deep pink" ,"pink" ,"orange" ,"Tomate" ,"Gelb" ,"Darkhaki" ,"pink" ,"lila" ,"Grün" ,"LightSeeFreen" ,"blau" ,"Teal" ,"braun", "kp"};

// globale_farb values
int G_red=125, G_blue=125, G_green=125;


// Arry für random Farbe wird noch aufgefüllt
const int anz = 16;

RgbColor ranfarben[anz] = {
	// Rot mit abstufungen
  RgbColor ( 255,  0,  0), // rot
  RgbColor ( 233,150,122), // hellrot
  // Pink 
  RgbColor ( 255, 20,147 ), // Deep Pink
  RgbColor ( 255,192,203 ), // Pink
  // Orange
  RgbColor ( 255,165,  0 ), // Orange
  RgbColor ( 255, 99, 71 ), // Tomate
  // Gelb
  RgbColor ( 255,255,  0 ), // Gelb
  RgbColor ( 189,183,107 ), // Darkhaki
  // Purple
  RgbColor ( 239,  79, 117), // pink
  RgbColor ( 200,   0, 200),  // lila
  // Grün
  RgbColor (   0, 255,   0), // Grün
  RgbColor (  32, 178, 170), // LightSeeFreen
  // Blau
  RgbColor (   0, 255 ,  0), // blau
  RgbColor (   0, 200 ,200), // Teal
  // Braun
  RgbColor ( 165, 42,  42 ), // braun
  RgbColor ( 205, 133, 63 )  // kp

};

enum Modes
{
  Off = 0,          // Off    = Schaltet Lampe aus
  Static = 1,       // Static = nicht zeitlich Veränderte Funktionen
  Effect = 2,       // Effect = zeitlich veränderliche Funktionen
};



enum ColorMode
{
  Rainbow,          // Regenbogen farben von rot -> hellblau
  Random,           // Automatische farbauswahl aus ranfarben[anz]
  UserColors,       //       Farbe wird   durch UI vorgegeben
  TwoUsercolors,    // zwei Farben werden druch UI vorgegeben
  ThreeUserColors  // drei Farben werden durch UI vorgegeben
};

enum Effects
{
  Strobo,                 // Stroboskop Effect
  Ball,                   // vier Bälle laufen den Strip entlang
  BallStackable,          // Ball läuft Strip entlang und stuckt am Ende
  BallStackableToCenter,  // Von beiden Seiten laufen Bälle zur mitte und stucken
  Music,                  // VU Meter Start: Stripe Anfang
  MusicFromCenter,        // VU Meter Start: Stripe Mitte
  LavaLamp,               // Farbe1 läuft in eine Richtung Farbe2 die andere Richtung hin und her
  MovingRainbow,          // Regenbogen bewegt sich entlang des Streifens
  FillUp,                 // Füllt Streifen wiederholend mit Farbe auf
  FillUp2,                // Füllt Streifen wiederholden mit 2 Farben auf
  FillUp3,                // Füllt Streifen wiederholend mit 3 Farben auf
  FillUp4,                // Füllt Streifen wiederholend mit 4 Farben auf
  fillup4tocentre
};

// nicht implenmentiert
enum EffectDirection
{
  Left,
  Right
};

struct setup_stripe
{
  int             StripeIndex;         // Strip nummer
  Modes           mode;                // Speichert Modus Static, Effect, OFF
  Effects         effect;              // Speichert welcher Effect abgespielt werden soll
  EffectDirection effectDirection;     // Richtung des Effekts
  ColorMode       Licht;               // Speichert Farb quelle
  int             Brightness;          // Speichert helligkeit
  uint8_t         FlashPerSeconds;     // Strobo takt
  int             EffectDelay;         // 10ms - x
  float           Intensity = 100.0;   // Scaliert  Micro/AUX  0 - 500,100 = Faktor 1, 200 =faktor 2
  bool            FFTAktive;           // aktiviert FFT für EffectDelay Steuerung durch Musik
  bool            bremse;              // Kann weg wird durch Modes abgedeckt
  bool            enable;              // Flag die anzeigt wenn sich was ändert
  bool            IsAux;               // True = aux, false = mic
  RgbColor        LED_farbe_1;         // Speichert Farbe 1 UserColors
  RgbColor        LED_farbe_2;         // Speichert Farbe 2 UserColors
  RgbColor        LED_farbe_3;         // Speichert Farbe 3 UserColors
  RgbColor        LED_farbe_4;         // Speichert Farbe 4 UserColors
  bool            play=1;
};

//Stripe Objekte
RMT0 stripe1(amountLeds, 23);
RMT1 stripe2(amountLeds, 21);

// Setup für Streifen
setup_stripe p_strip1;
setup_stripe p_strip2;

// nur zum testen
unsigned long millis_t  = 0;
int           counter_t = 2;
int           max_t     = 14;

// Effect auswahl
unsigned int effect_auswahl = 1;
unsigned int colorMode_auswahl = 0;
unsigned int effect_farbe = 2;

// Anzahl effecte
const int maxeffect = 11;

// zum farben durchwechseln
int satiac_auswahl = 0;
int static_auswahl2 = 0;
int static_auswahl3 = 0;
int static_auswahl4 = 0;

using namespace std;

bool debug1 = 1;
bool debug2 = 0;
