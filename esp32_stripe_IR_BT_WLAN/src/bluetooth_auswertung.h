#pragma once
#include <Arduino.h>
#include "Variablen.h"

struct bta
{
    const String ball            = "ball";
    const String ballstack       = "ballstack";
    const String ballstackcenter = "ballstackcenter";
    const String musik           = "musik";
    const String musikcentre     = "musikcentre";
    const String lavalampemove   = "lavalamp";
    const String movingrainbow   = "movingrainbow";
    const String fillup          = "fillup";
    const String fillup2         = "fillup_zwei";
    const String fillup3         = "fillup_drei";
    const String fillup4         = "fillup_vier";
    const String strobo          = "strobo";

    const String rainbow         = "rainbow";
    const String random          = "random";
    const String usercolor       = "usercolor";
    const String usercolorone    = "usercolorone";
    const String twousercolor    = "twousercolor";
    const String threeusercolor  = "threeusercolor";
    const String randomtwo       = "randomtwo";
    const String randomthree     = "randomthree";

    const String an_static       = "anstatic";
    const String an_effect       = "aneffect";
    const String aus             = "aus";

    const String stripe1aktive   = "stripeinsaktive";
    const String stripe2aktive   = "stripzweiaktive";

    const String FFT             = "FFT";

}bt_value;



void check_bt(){
    
    if(!SerialBT.available()){
        return;
    }

    bt_inc = "";

    while (SerialBT.available()) {
        bt_inc += (char)SerialBT.read();
    };
    //////////////////////////////////////////////////////////////////////////////
    if(debug1){
      Serial.print(" inc = ");Serial.println((String)bt_inc);
    }
    //////////////////////////////////////////////////////////////////////////////
    if(bt_inc == bt_value.FFT){
        p_strip1.FFTAktive = !p_strip1.FFTAktive;
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    if(bt_inc == bt_value.stripe1aktive){
        p_strip1.enable = p_strip1.enable^1;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.stripe2aktive){
        p_strip2.enable = p_strip2.enable^1;
        if(debug1)debugg(p_strip1);
        return;
    }

    
    //////////////////////////////////////////////////////////////////////////////
    //                                 Effecte                                  //
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.ball){
        if(p_strip1.enable)p_strip1.effect            = Effects::Ball;
        if(p_strip2.enable)p_strip2.effect            = Effects::Ball;
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.ballstack){
        if(p_strip1.enable)p_strip1.effect            = Effects::BallStackable;
        if(p_strip2.enable)p_strip2.effect            = Effects::BallStackable;
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.ballstackcenter){
        if(p_strip1.enable)p_strip1.effect            = Effects::BallStackableToCenter;
        if(p_strip2.enable)p_strip2.effect            = Effects::BallStackableToCenter;        
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.movingrainbow){
        if(p_strip1.enable)p_strip1.effect            = Effects::MovingRainbow;
        if(p_strip2.enable)p_strip2.effect            = Effects::MovingRainbow;        
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.musik){
        if(p_strip1.enable)p_strip1.effect            = Effects::Music;
        if(p_strip2.enable)p_strip2.effect            = Effects::Music;        
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.musikcentre){
        if(p_strip1.enable)p_strip1.effect            = Effects::MusicFromCenter;
        if(p_strip2.enable)p_strip2.effect            = Effects::MusicFromCenter;
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.lavalampemove){
        if(p_strip1.enable)p_strip1.effect            = Effects::LavaLamp;
        if(p_strip2.enable)p_strip2.effect            = Effects::LavaLamp;        
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.fillup){
        if(p_strip1.enable)p_strip1.effect            = Effects::FillUp;
        if(p_strip2.enable)p_strip2.effect            = Effects::FillUp;
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;        
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.fillup2){
        if(p_strip1.enable)p_strip1.effect            = Effects::FillUp2;
        if(p_strip2.enable)p_strip2.effect            = Effects::FillUp2;
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;        
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.fillup3){
        if(p_strip1.enable)p_strip1.effect            = Effects::FillUp3;
        if(p_strip2.enable)p_strip2.effect            = Effects::FillUp3;
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;        
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.fillup4){
        if(p_strip1.enable)p_strip1.effect            = Effects::FillUp4;
        if(p_strip2.enable)p_strip2.effect            = Effects::FillUp4;
        if(p_strip1.enable)p_strip1.mode              = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode              = Modes::Effect;        
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.strobo){
        if(p_strip1.enable){
            p_strip1.effect            = Effects::Strobo;
            p_strip1.mode              = Modes::Effect;
            p_strip1.LED_farbe_1       = RgbColor ( 255, 255, 255);
        }
        if(p_strip2.enable){
            p_strip2.effect            = Effects::Strobo;
            p_strip2.mode              = Modes::Effect;
            p_strip2.LED_farbe_1       = RgbColor ( 255, 255, 255);
        }

        if(debug1)debugg(p_strip1);
        return;
    }

    
    //////////////////////////////////////////////////////////////////////////////
    //                                 Farben                                   //
    //////////////////////////////////////////////////////////////////////////////

    else if(bt_inc == bt_value.usercolor){
        if(p_strip1.enable)p_strip1.Licht            = ColorMode::UserColors;
        if(p_strip2.enable)p_strip2.Licht            = ColorMode::UserColors;        
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.rainbow){
        if(p_strip1.enable)p_strip1.Licht            = ColorMode::Rainbow;
        if(p_strip2.enable)p_strip2.Licht            = ColorMode::Rainbow;        
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.random){
        if(p_strip1.enable)p_strip1.Licht            = ColorMode::Random;
        if(p_strip2.enable)p_strip2.Licht            = ColorMode::Random;        
        if(debug1)debugg(p_strip1);
        return;
    }
    
    
    //////////////////////////////////////////////////////////////////////////////
    //                                 Static                                   //
    //////////////////////////////////////////////////////////////////////////////

    else if(bt_inc == bt_value.usercolorone){
        if(p_strip1.enable)p_strip1.Licht            = ColorMode::UserColors;
        if(p_strip2.enable)p_strip2.Licht            = ColorMode::UserColors;
        static int temp = 0;
        if(p_strip1.enable)p_strip1.LED_farbe_1 = ranfarben[temp];
        if(p_strip2.enable)p_strip2.LED_farbe_1 = ranfarben[temp];
        temp++;
        if(temp>anz) temp = 0;        
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////

    else if(bt_inc == bt_value.twousercolor){
        if(p_strip1.enable)p_strip1.Licht            = ColorMode::TwoUsercolors;
        if(p_strip2.enable)p_strip2.Licht            = ColorMode::TwoUsercolors;
        static int temp = 0;
        if(p_strip1.enable)p_strip1.LED_farbe_2 = ranfarben[temp];
        if(p_strip2.enable)p_strip2.LED_farbe_2 = ranfarben[temp];
        temp++;
        if(temp>anz) temp = 0;       
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.threeusercolor){
        if(p_strip1.enable)p_strip1.Licht            = ColorMode::ThreeUserColors;
        if(p_strip2.enable)p_strip2.Licht            = ColorMode::ThreeUserColors;
        static int temp = 0;
        if(p_strip1.enable)p_strip1.LED_farbe_3 = ranfarben[temp];
        if(p_strip2.enable)p_strip2.LED_farbe_3 = ranfarben[temp];
        temp++;
        if(temp>anz) temp = 0;
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.an_static){
        if(p_strip1.enable)p_strip1.mode            = Modes::Static;
        if(p_strip2.enable)p_strip2.mode            = Modes::Static;        
        if(debug1)debugg(p_strip1);
        return;
    }
    //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.an_effect){
        if(p_strip1.enable)p_strip1.mode            = Modes::Effect;
        if(p_strip2.enable)p_strip2.mode            = Modes::Effect;         
        if(debug1)debugg(p_strip1);
        return;
    }
        //////////////////////////////////////////////////////////////////////////////
    else if(bt_inc == bt_value.aus){
        if(p_strip1.enable)p_strip1.mode            = Modes::Off;
        if(p_strip2.enable)p_strip2.mode            = Modes::Off;  
        if(debug1)debugg(p_strip1);
        return;
    }

    else if (bt_inc.indexOf("hell/") != -1) {
      if (debug1 | debug2) Serial.println("Bin in hell");
      char buff[100];
      int temp;
      bt_inc.toCharArray(buff, bt_inc.length());

      // Wenn 11 ein Punkt|Leerzeichen ist value < 10
      if (buff[6] == ' ' || buff[6] == '.') {
        int e = buff[5] - '0';
        temp = e ;
        if (temp < 0)temp = 0;
        if (temp > 9)temp = 9;
        if (p_strip1.enable)p_strip1.Brightness = temp;
        if (p_strip2.enable)p_strip2.Brightness = temp;
      }

      // Wenn 12 ein Punkt|Leerzeichen ist value < 100
      else if (buff[7] == ' ' || buff[7] == '.') {
        int z, e;
        z = buff[5] - '0';
        e = buff[6] - '0';
        temp = 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.Brightness = temp;
        if (p_strip2.enable)p_strip2.Brightness = temp;
      }

      // Wenn 13 ein Punkt|Leerzeichen ist value > 100
      else if (buff[8] == ' ' || buff[8] == '.') {
        int h, z, e;
        h = buff[5] - '0';
        z = buff[6] - '0';
        e = buff[7] - '0';
        temp = 100 * h + 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.Brightness = temp;
        if (p_strip2.enable)p_strip2.Brightness = temp;
      }
      bt_inc = "";
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (bt_inc.indexOf("intensitaet/") != -1) {
      if (debug1 | debug2) Serial.println("Bin in hell");
      char buff[100];
      int temp;
      bt_inc.toCharArray(buff, bt_inc.length());

      // Wenn 18 ein Punkt|Leerzeichen ist value < 10
      if (buff[13] == ' ' || buff[13] == '.') {
        int e = buff[12] - '0';
        temp = e ;
        if (temp < 0)temp = 0;
        if (temp > 9)temp = 9;
        if (p_strip1.enable)p_strip1.Intensity = temp;
        if (p_strip2.enable)p_strip2.Intensity = temp;
      }

      // Wenn 19 ein Punkt|Leerzeichen ist value < 100
      else if (buff[14] == ' ' || buff[14] == '.') {
        int z, e;
        z = buff[12] - '0';
        e = buff[13] - '0';
        temp = 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.Intensity = temp;
        if (p_strip2.enable)p_strip2.Intensity = temp;
      }

      // Wenn 20 ein Punkt|Leerzeichen ist value > 100
      else if (buff[15] == ' ' || buff[15] == '.') {
        int h, z, e;
        h = buff[12] - '0';
        z = buff[13] - '0';
        e = buff[14] - '0';
        temp = 100 * h + 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.Intensity = temp;
        if (p_strip2.enable)p_strip2.Intensity = temp;
      }
      bt_inc = "";
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (bt_inc.indexOf("effectdelay/") != -1) {
      if (debug1 | debug2)Serial.println("Bin in effectdelay");
      char buff[100];
      int temp;
      bt_inc.toCharArray(buff, bt_inc.length());

      // Wenn 18 ein Punkt|Leerzeichen ist value < 10
      if (buff[13] == ' ' || buff[13] == '.') {
        int e = buff[12] - '0';
        temp = e ;
        if (temp < 0)temp = 0;
        if (temp > 9)temp = 9;
        temp = 255 - temp;
        if (p_strip1.enable)p_strip1.EffectDelay = temp;
        if (p_strip2.enable)p_strip2.EffectDelay = temp;
      }

      // Wenn 19 ein Punkt|Leerzeichen ist value < 100
      else if (buff[14] == ' ' || buff[14] == '.') {
        int z, e;
        z = buff[12] - '0';
        e = buff[13] - '0';
        temp = 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        temp = 255 - temp;
        if (p_strip1.enable)p_strip1.EffectDelay = temp;
        if (p_strip2.enable)p_strip2.EffectDelay = temp;
      }

      // Wenn 20 ein Punkt|Leerzeichen ist value > 100
      else if (buff[15] == ' ' || buff[15] == '.') {
        int h, z, e;
        h = buff[12] - '0';
        z = buff[13] - '0';
        e = buff[14] - '0';
        temp = 100 * h + 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        temp = 255 - temp;
        if (p_strip1.enable)p_strip1.EffectDelay = temp;
        if (p_strip2.enable)p_strip2.EffectDelay = temp;
      }
      bt_inc = "";
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }
}
