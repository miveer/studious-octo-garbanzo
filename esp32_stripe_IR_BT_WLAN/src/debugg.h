#pragma once
#include "Variablen.h"
#include "Funktionen.h"

void debugg(setup_stripe value) {

  Serial.print("StripeIndex = "); Serial.println(value.StripeIndex);
  Serial.print("Modes       = "); Serial.println(Smodes[value.mode]);
  Serial.print("Effects     = "); Serial.println(SEffects[value.effect]);
  Serial.print("ColorMode   = "); Serial.println(SColorMode[value.Licht]);
  Serial.print("Brightness  = "); Serial.println(value.Brightness);
  Serial.print("EffectDelay = "); Serial.println(value.EffectDelay);
  Serial.print("Intensitaet = "); Serial.println(value.Intensity);
  Serial.print("FlashperSec = "); Serial.println(value.FlashPerSeconds);
  Serial.print("FFTAktive   = "); Serial.println(value.FFTAktive);
  Serial.print("enable      = "); Serial.println(value.enable);
  Serial.print("IsAux       = "); Serial.println(value.IsAux);
  Serial.print("Ball laenge = "); Serial.println(balllengh_max);
  Serial.print("Mic offset  = "); Serial.println(check_micro());
  Serial.print("play        = "); Serial.println(value.play);
  Serial.print("debug1      = "); Serial.println(debug1);
  Serial.print("debug2      = "); Serial.println(debug2);  
  Serial.println("----------");
}
