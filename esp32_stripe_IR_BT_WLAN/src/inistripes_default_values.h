#pragma once
#include "Variablen.h"


void inistripes_default_values() {

  p_strip1.StripeIndex       = 0;
  p_strip1.mode              = Modes::Static;
  p_strip1.effect            = Effects::LavaLamp;
  p_strip1.effectDirection   = EffectDirection::Left;
  p_strip1.Licht             = ColorMode::UserColors;
  p_strip1.Brightness        = 120;
  p_strip1.FlashPerSeconds   = 30;
  p_strip1.EffectDelay       = 80;
  p_strip1.Intensity         = 100.0;
  p_strip1.LED_farbe_1       = RgbColor(200, 200, 200);
  p_strip1.LED_farbe_2       = RgbColor(255,   0,   0);
  p_strip1.LED_farbe_3       = RgbColor(  0, 255,   0);
  p_strip1.LED_farbe_4       = RgbColor(  0,   0, 255);
  p_strip1.enable            = 1;
  p_strip1.IsAux             = 0;
  p_strip1.FFTAktive         = 0;
  p_strip1.play              = 1;

  p_strip2.StripeIndex       = 1;
  p_strip2.mode              = Modes::Static;
  p_strip2.effect            = Effects::LavaLamp;
  p_strip2.effectDirection   = EffectDirection::Left;
  p_strip2.Licht             = ColorMode::UserColors;
  p_strip2.Brightness        = 120;
  p_strip2.FlashPerSeconds   = 35;
  p_strip2.EffectDelay       = 80;
  p_strip2.Intensity         = 100.0;
  p_strip2.LED_farbe_1       = RgbColor(200, 200, 200);
  p_strip2.LED_farbe_2       = RgbColor(255,   0,   0);
  p_strip2.LED_farbe_3       = RgbColor(  0, 255,   0);
  p_strip2.LED_farbe_4       = RgbColor(  0,   0, 255);
  p_strip2.enable            = 1;
  p_strip2.IsAux             = 0;
  p_strip2.FFTAktive         = 0;
  p_strip2.play              = 1;

}
