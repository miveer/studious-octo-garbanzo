#pragma once
#include "Variablen.h"
#include "fernbedienungsbutton.h"
#include "debugg.h"

void check_ir(){

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    
    switch (results.value)
    {
    case Button_8h:
      Serial.println("Button 8h erkannt");

      if(p_strip1.mode == Modes::Static) colorMode_auswahl++;
      if(colorMode_auswahl>3)colorMode_auswahl=0;

      p_strip1.mode = Modes::Static;
      p_strip2.mode = Modes::Static;
      
      if(colorMode_auswahl == 0){
        p_strip1.Licht= ColorMode::UserColors;
        p_strip2.Licht= ColorMode::UserColors;
      }
      if(colorMode_auswahl == 1){
        p_strip1.Licht= ColorMode::TwoUsercolors;
        p_strip2.Licht= ColorMode::TwoUsercolors;
      }
      if(colorMode_auswahl == 2){
        p_strip1.Licht= ColorMode::ThreeUserColors;
        p_strip2.Licht= ColorMode::ThreeUserColors;
      }
      if(colorMode_auswahl == 3){
        p_strip1.Licht= ColorMode::Rainbow;
        p_strip2.Licht= ColorMode::Rainbow;
      }
      /* Rausgenommen da der refresh bei static 100ms beträgt und man dafurch ein farbwechsel hat
      if(colorMode_auswahl == 4){
        p_strip1.Licht= ColorMode::Random;
        p_strip2.Licht= ColorMode::Random;
      }
      */
    break;

    case Button_10h:  // letzten effect aufrufen 
      Serial.println("Button 10h erkannt");
      if(p_strip1.mode == Modes::Effect){
        
        
        effect_auswahl--;
        if(effect_auswahl<0)effect_auswahl=maxeffect;

        if(effect_auswahl==0){
          p_strip1.effect = Effects::LavaLamp;
          p_strip2.effect = Effects::LavaLamp;
        }
        if(effect_auswahl==1){
          p_strip1.effect = Effects::Ball;
          p_strip2.effect = Effects::Ball;
        }
        if(effect_auswahl==2){
          p_strip1.effect = Effects::BallStackable;
          p_strip2.effect = Effects::BallStackable;
        }
        if(effect_auswahl==3){
          p_strip1.effect = Effects::BallStackableToCenter;
          p_strip2.effect = Effects::BallStackableToCenter;
        }
        if(effect_auswahl==4){
          p_strip1.effect = Effects::Music;
          p_strip2.effect = Effects::Music;
        }
        if(effect_auswahl==5){
          p_strip1.effect = Effects::MusicFromCenter;
          p_strip2.effect = Effects::MusicFromCenter;
        }
        if(effect_auswahl==6){
          p_strip1.effect = Effects::MovingRainbow;
          p_strip2.effect = Effects::MovingRainbow;
        }
        if(effect_auswahl==7){
          p_strip1.effect = Effects::FillUp;
          p_strip2.effect = Effects::FillUp;
        }
        if(effect_auswahl==8){
          p_strip1.effect = Effects::FillUp2;
          p_strip2.effect = Effects::FillUp2;
        }
        if(effect_auswahl==9){
          p_strip1.effect = Effects::FillUp3;
          p_strip2.effect = Effects::FillUp3;
        }
        
        if(effect_auswahl==10){
          p_strip1.effect = Effects::FillUp4;
          p_strip2.effect = Effects::FillUp4;
        }

        if(effect_auswahl==11){
          p_strip1.effect = Effects::Strobo;
          p_strip2.effect = Effects::Strobo;
        }

      }
    break;

    case Button_12h:  
        Serial.println("Button 12h erkannt");
      
        if(p_strip1.mode == Modes::Effect){
          effect_farbe++;
        }
        if(effect_farbe>2)effect_farbe=0;

        p_strip1.mode = Modes::Effect;
        p_strip2.mode = Modes::Effect;
              
        if(effect_farbe == 0){
          p_strip1.Licht= ColorMode::UserColors;
          p_strip2.Licht= ColorMode::UserColors;
        }
        if(effect_farbe == 1){
          p_strip1.Licht= ColorMode::Rainbow;
          p_strip2.Licht= ColorMode::Rainbow;
        }
        
        if(effect_farbe == 2){
          p_strip1.Licht= ColorMode::Random;
          p_strip2.Licht= ColorMode::Random;
        }
        
     break;

    case Button_14h:  // nächsten effect aufrufen 
    Serial.println("Button 14h erkannt");
      if(p_strip1.mode == Modes::Effect){
        effect_auswahl++;
        if(effect_auswahl>maxeffect)effect_auswahl=0;

        if(effect_auswahl==0){
          p_strip1.effect = Effects::LavaLamp;
          p_strip2.effect = Effects::LavaLamp;
        }
        if(effect_auswahl==1){
          p_strip1.effect = Effects::Ball;
          p_strip2.effect = Effects::Ball;
        }
        if(effect_auswahl==2){
          p_strip1.effect = Effects::BallStackable;
          p_strip2.effect = Effects::BallStackable;
        }
        if(effect_auswahl==3){
          p_strip1.effect = Effects::BallStackableToCenter;
          p_strip2.effect = Effects::BallStackableToCenter;
        }
        if(effect_auswahl==4){
          p_strip1.effect = Effects::Music;
          p_strip2.effect = Effects::Music;
        }
        if(effect_auswahl==5){
          p_strip1.effect = Effects::MusicFromCenter;
          p_strip2.effect = Effects::MusicFromCenter;
        }
        if(effect_auswahl==6){
          p_strip1.effect = Effects::MovingRainbow;
          p_strip2.effect = Effects::MovingRainbow;
        }
        if(effect_auswahl==7){
          p_strip1.effect = Effects::FillUp;
          p_strip2.effect = Effects::FillUp;
        }
        if(effect_auswahl==8){
          p_strip1.effect = Effects::FillUp2;
          p_strip2.effect = Effects::FillUp2;
        }
        if(effect_auswahl==9){
          p_strip1.effect = Effects::FillUp3;
          p_strip2.effect = Effects::FillUp3;
        }
        
        if(effect_auswahl==10){
          p_strip1.effect = Effects::FillUp4;
          p_strip2.effect = Effects::FillUp4;
        }

        if(effect_auswahl==11){
          p_strip1.effect = Effects::Strobo;
          p_strip2.effect = Effects::Strobo;
        }

        if(effect_auswahl == 12){
          p_strip1.effect = Effects::fillup4tocentre;
          p_strip2.effect = Effects::fillup4tocentre;
        }
      }
      break;

      case Button_on:
      Serial.println("Button ON erkannt");
        p_strip1.mode = Modes::Static;
        p_strip2.mode = Modes::Static;
        p_strip1.Licht= ColorMode::UserColors;
        p_strip2.Licht= ColorMode::UserColors;
        
      break;

      case Button_off:
      Serial.println("Button off erkannt");
        p_strip1.mode = Modes::Off;
        p_strip2.mode = Modes::Off;

      break;

      case Button_play:
      Serial.println("Button play erkannt");
        p_strip1.play = 1;
        p_strip2.play = 1;
      break;

      case Button_stop:
      Serial.println("Button stop erkannt");
        p_strip1.play = 0;
        p_strip2.play = 0;
      break;

      case Button_hell_plus:
      Serial.println("Button Button_hell_plus erkannt");
        p_strip1.Brightness += 10;
        if(p_strip1.Brightness > 255) p_strip1.Brightness = 255;
        p_strip2.Brightness = p_strip1.Brightness;
      break;

      case Button_hell_minus:
       Serial.println("Button Button_hell_minus erkannt");
        p_strip1.Brightness -= 10;
        if(p_strip1.Brightness < 0) p_strip1.Brightness = 0;
        p_strip2.Brightness = p_strip1.Brightness;
      break;

      case Button_delay_minus:
      Serial.println("Button Button_delay_minus erkannt");
        if(p_strip1.effect == Effects::Music || p_strip1.effect == Effects::MusicFromCenter ){
          p_strip1.Intensity-=10;
          if(p_strip1.Intensity<=10)p_strip1.Intensity=10;
          p_strip2.Intensity = p_strip1.Intensity; 
        }else{
          p_strip1.EffectDelay += 5;
          if(p_strip1.EffectDelay > 200) p_strip1.EffectDelay = 200;
          p_strip2.EffectDelay = p_strip1.EffectDelay;
        }
      break;

      case Button_delay_plus:
        Serial.println("Button Button_delay_plus erkannt");
        if(p_strip1.effect == Effects::Music  || p_strip1.effect == Effects::MusicFromCenter ){
          p_strip1.Intensity+=10;
          if(p_strip1.Intensity>400)p_strip1.Intensity=400;
          p_strip2.Intensity = p_strip1.Intensity; 
        }else{
          p_strip1.EffectDelay -= 5;
          if(p_strip1.EffectDelay < 0) p_strip1.EffectDelay = 0;
          p_strip2.EffectDelay = p_strip1.EffectDelay;
        }
      break;

      case Button_rot:
        Serial.println("Button Button_rot erkannt");
        if((p_strip1.mode == Modes::Static && p_strip1.Licht == ColorMode::TwoUsercolors) ||
           (p_strip1.mode == Modes::Static && p_strip1.Licht == ColorMode::ThreeUserColors)){
             static_auswahl2++;
             if(static_auswahl2 > anz-1)static_auswahl2=0;
              p_strip1.LED_farbe_2 = ranfarben[static_auswahl2];
              p_strip2.LED_farbe_2 = ranfarben[static_auswahl2];   
        }else{
          p_strip1.LED_farbe_1 = RgbColor ( 255,   0,  0);
          p_strip2.LED_farbe_1 = RgbColor ( 255,   0,  0);
        }      
      break;

      case Button_gruen:
      Serial.println("Button Button_gruen erkannt");
        if((p_strip1.mode == Modes::Static && p_strip1.Licht == ColorMode::TwoUsercolors) ||
           (p_strip1.mode == Modes::Static && p_strip1.Licht == ColorMode::ThreeUserColors)){
             static_auswahl3++;
             if(static_auswahl3 > anz-1)static_auswahl3=0;
              p_strip1.LED_farbe_3 = ranfarben[static_auswahl3];
              p_strip2.LED_farbe_3 = ranfarben[static_auswahl3];   
        }else{
          p_strip1.LED_farbe_1 = RgbColor (   0, 255,  0);
          p_strip2.LED_farbe_1 = RgbColor (   0, 255,  0);
        }

      break;

      case Button_blau:
        Serial.println("Button Button_blau erkannt");
        satiac_auswahl++;
        if(satiac_auswahl > anz-1)satiac_auswahl=0;
        p_strip1.LED_farbe_1 = ranfarben[satiac_auswahl];
        p_strip2.LED_farbe_1 = ranfarben[satiac_auswahl];
      break;

      case Button_weiss:
      Serial.println("Button Button_weiss erkannt");
        p_strip1.LED_farbe_1 = RgbColor ( 255, 255, 255);
        p_strip2.LED_farbe_1 = RgbColor ( 255, 255, 255);
      break;

      case Button_1:
      Serial.println("Button Button_1 erkannt");
        p_strip1.FFTAktive = p_strip1.FFTAktive^1;
        if(debug2){Serial.print("FFTaktive = ");Serial.println(p_strip1.FFTAktive);}
      break;

      case Button_2:
        Serial.println("Button 2h erkannt");
      
        if(p_strip1.mode == Modes::Effect){
          effect_farbe++;
        }
        if(effect_farbe>2)effect_farbe=0;

        p_strip1.mode = Modes::Effect;
        p_strip2.mode = Modes::Effect;
              
        if(effect_farbe == 0){
          p_strip1.Licht= ColorMode::UserColors;
          p_strip2.Licht= ColorMode::UserColors;
        }
        if(effect_farbe == 1){
          p_strip1.Licht= ColorMode::Rainbow;
          p_strip2.Licht= ColorMode::Rainbow;
        }
        
        if(effect_farbe == 2){
          p_strip1.Licht= ColorMode::Random;
          p_strip2.Licht= ColorMode::Random;
        }
      break;

      case Button_3:
        ESP.restart();
        delay(100);
      break;


      case Button_7: // maxdelay +
        if(p_strip1.FFTAktive){
          delayMax += 1;
          if(delayMax > 100) delayMax = 100;
        }
      break;

      case Button_8: // mindelay +
        if(p_strip1.FFTAktive){
          delayMin += 1;
          if(delayMin > 100) delayMin = 100;
        }
      break;

      case Button_9: // maxfreq +
        if(p_strip1.FFTAktive){
          maxfreq += 50;
          if(maxfreq > 1000) maxfreq = 1000;
        }
      break;

      case Button_10: // maxdelay -
        if(p_strip1.FFTAktive){
          delayMax -= 2;
          if(delayMax > 100) delayMax = 100;
        }
      break;

      case Button_11: // mindelay -
        if(p_strip1.FFTAktive){
          delayMin -= 1;
          if(delayMax < 1) delayMax = 1;
        }
      break;

      case Button_12: // maxfreq -
        if(p_strip1.FFTAktive){
          maxfreq -= 50;
          if(maxfreq < 100) maxfreq = 100;
        }
      break;


      default:
        Serial.println("nichts erkannt");
      break;
    }
    debugg(p_strip1);
    //debugg(p_strip2);
    irrecv.resume();
    
  }
  
}
