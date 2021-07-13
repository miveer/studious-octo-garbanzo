#pragma once
#include "Variablen.h"
#include "debugg.h"
#include <WiFi.h>
#include <NeoPixelBrightnessBus.h>

WiFiServer server(80);

void ini_wifi(){
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  int i = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void check_Wifi(void) {

  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    String req = client.readStringUntil('\r');
    client.flush();
    if (debug1 | debug2)Serial.println(req);
    //Serial.println(req);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                        Abschalt-Auswertung                                           //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    if (req.indexOf("/aus") != -1) {
      if (debug1 | debug2) Serial.println("Bin in AUS");
      p_strip1.mode = Modes::Off;
      p_strip2.mode = Modes::Off;
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                        Checkbox-Auswertung                                           //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/aktiveLEDeins") != -1) {
      if (debug1 | debug2) Serial.print("Ja bin in einsLED drin en_Streifen 1 hat = "); Serial.println(p_strip1.enable);
      p_strip1.enable ? p_strip1.enable = 0 : p_strip1.enable = 1;
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/zweiLED") != -1) {
      if (debug1 | debug2) Serial.print("Ja bin in einsLED drin en_Streifen 2 hat = "); Serial.println(p_strip2.enable);
      p_strip2.enable ? p_strip2.enable = 0 : p_strip2.enable = 1;
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/FFTan") != -1) {
      p_strip1.FFTAktive ? p_strip1.FFTAktive = 0 : p_strip1.FFTAktive = 1 ;
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/AUX") != -1) {
      p_strip1.IsAux ? p_strip1.IsAux = 0 : p_strip1.IsAux = 1;      
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                          Static-Auswertung                                           //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/mstatic") != -1){
      if (debug1 | debug2) Serial.println("Ja bin in static");
      if (p_strip1.enable){ 
        p_strip1.mode = Modes::Static;
        p_strip1.Licht = ColorMode::UserColors;
      }  
      if (p_strip2.enable){ 
        p_strip2.mode = Modes::Static;
        p_strip2.Licht = ColorMode::UserColors;
      } 
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                          Farben 1 -Auswertung                                        //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/sweiss") != -1) {
      if (debug1 | debug2) Serial.println("Bin in sweiss");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = RgbColor(200, 200, 200);   // weiss
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = RgbColor(200, 200, 200);   // weiss
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/srot") != -1) {
      if (debug1 | debug2) Serial.println("Bin in srot");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = ranfarben[0];     // rot
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = ranfarben[0];     // rot
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/sorange") != -1) {
      if (debug1 | debug2) Serial.println("Bin in sorange");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = ranfarben[6];     // orange
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = ranfarben[6];     // orange
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/spink") != -1) {
      if (debug1 | debug2) Serial.println("Bin in spink");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = ranfarben[4];     // pink
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = ranfarben[4];     // pink
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/slila") != -1) {
      if (debug1 | debug2) Serial.println("Bin in slila");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = ranfarben[8];     // lila
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = ranfarben[8];     // lila
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/steal") != -1) {
      if (debug1 | debug2) Serial.println("Bin in steal");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = ranfarben[7];     // teal
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = ranfarben[7];     // teal
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }


    else if (req.indexOf("/sblau") != -1) {
      if (debug1 | debug2) Serial.println("Bin in sblau");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = ranfarben[2];     // blau
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = ranfarben[2];     // blau
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/sgreen") != -1) {
      if (debug1 | debug2) Serial.println("Bin in sgreen");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = ranfarben[1];     // green
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = ranfarben[1];     // green
     }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/sgelb") != -1) {
      if (debug1 | debug2) Serial.println("Bin in sgelb");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = ranfarben[5];     // green
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = ranfarben[5];     // green
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                          Farben 2 -Auswertung                                        //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/2weiss") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2weiss");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = RgbColor(200, 200, 200);   // weiss
      }

      if (p_strip1.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = RgbColor(200, 200, 200);   // weiss
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/2rot") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2rot");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = ranfarben[0];     // rot
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = ranfarben[0];     // rot
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/2orange") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2orange");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = ranfarben[6];     // orange
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = ranfarben[6];     // orange
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/2pink") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2pink");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = ranfarben[4];     // pink
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = ranfarben[4];     // pink
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/2lila") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2lila");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = ranfarben[8];     // lila
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = ranfarben[8];     // lila
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/2teal") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2teal");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = ranfarben[7];     // teal
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = ranfarben[7];     // teal
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }


    else if (req.indexOf("/2blau") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2blau");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = ranfarben[2];     // blau
        p_strip1.LED_farbe_2 = ranfarben[2];     // blau
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = ranfarben[2];     // blau
        p_strip2.LED_farbe_2 = ranfarben[2];     // blau
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/2green") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2green");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = ranfarben[1];     // green
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = ranfarben[1];     // green
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/2gelb") != -1) {
      if (debug1 | debug2) Serial.println("Bin in 2gelb");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_2 = ranfarben[5];     // green
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_2 = ranfarben[5];     // green
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                          Effect-Auswertung                                           //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/zweifillup") != -1) {
      if (debug1 | debug2) Serial.println("Bin in /zweifillup");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::FillUp2;
        p_strip1.Licht  = ColorMode::Random;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::FillUp2;
        p_strip2.Licht  = ColorMode::Random;
      }
      if (debug1 | debug2) Serial.println("eballstack aufgerufen");
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/upfilldrei") != -1) {
      if (debug1 | debug2) Serial.println("Bin in /zweifillup");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::FillUp3;
        p_strip1.Licht  = ColorMode::Random;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::FillUp3;
        p_strip2.Licht  = ColorMode::Random;
      }
      if (debug1 | debug2) Serial.println("eballstack aufgerufen");
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/vierfillup") != -1) {
      if (debug1 | debug2) Serial.println("Bin in /zweifillup");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::FillUp4;
        p_strip1.Licht  = ColorMode::Random;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::FillUp4;
        p_strip2.Licht  = ColorMode::Random;
      }
      if (debug1 | debug2) Serial.println("eballstack aufgerufen");
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/centrestuck") != -1) {
      if (debug1 | debug2) Serial.println("Bin in eballstack centre");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::BallStackableToCenter;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::BallStackableToCenter;
      }
      if (debug1 | debug2) Serial.println("eballstack aufgerufen");
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/stacknormal") != -1) {
      if (debug1 | debug2) Serial.println("Bin in eballstack");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::BallStackable;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::BallStackable;
      }
      if (debug1 | debug2) Serial.println("eballstack aufgerufen");
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/eball") != -1) {
      if (debug1 | debug2) Serial.println("Ball aufgerufen");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::Ball;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::Ball;
      }
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/centremusik") != -1) {
      if (debug1 | debug2) Serial.println("Ball aufgerufen");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::MusicFromCenter;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::MusicFromCenter;
      }
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/musiknormal") != -1) {
      if (debug1 | debug2) Serial.println("Ball aufgerufen");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::Music;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::Music;
      }
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/lavalampe") != -1) {
      if (debug1 | debug2) Serial.println("lava aufgerufen");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::LavaLamp;
        p_strip1.Licht = ColorMode::UserColors;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::LavaLamp;
        p_strip2.Licht = ColorMode::UserColors;
      }
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/fillup") != -1) {
      if (debug1 | debug2) Serial.println("lava aufgerufen");
      if(p_strip1.enable){
        p_strip1.mode   = Modes::Effect;
        p_strip1.effect = Effects::FillUp;
        p_strip1.Licht = ColorMode::Random;
      }
      if(p_strip2.enable){
        p_strip2.mode   = Modes::Effect;
        p_strip2.effect = Effects::FillUp;
        p_strip2.Licht = ColorMode::Random;
      }
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                       ColorMode-Auswertung                                           //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/mRainbow") != -1) {
      if (debug1 | debug2) Serial.println("mRainbow aufgerufen");
      if (p_strip1.enable)
        p_strip1.Licht = ColorMode::Rainbow;     
      if (p_strip2.enable)
        p_strip2.Licht = ColorMode::Rainbow;
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/mRandom") != -1) {
      if (debug1 | debug2) Serial.println("mRainbow aufgerufen");
      if (p_strip1.enable)
        p_strip1.Licht = ColorMode::Random;     
      if (p_strip2.enable)
        p_strip2.Licht = ColorMode::Random;
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    else if (req.indexOf("/mUserColor") != -1) {
      if (debug1 | debug2) Serial.println("mUserColor aufgerufen");
      if (p_strip1.enable) {
        p_strip1.Licht = ColorMode::UserColors;
        p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      if (p_strip2.enable) {
        p_strip2.Licht = ColorMode::UserColors;
        p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                          ballänge-Auswertung                                           //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////
//noch nicht getestet
    else if (req.indexOf("/laengeball/") != -1) {
      if (debug1 | debug2) Serial.println("Bin in ball lengh");
      char buff[35];
      req.toCharArray(buff, req.length());
      int balllengh_app;

      // Wenn 17 ein Punkt|Leerzeichen ist value < 10
      if (buff[17] == ' ' || buff[13] == '.') {
        int e = buff[16] - '0';
        balllengh_app = e ;
        if (balllengh_app < 0)balllengh_app = 0;
        if (balllengh_app > 9)balllengh_app = 9;
        if (p_strip1.enable | p_strip2.enable)  balllengh_max = balllengh_app;
      }

      // Wenn 18 ein Punkt|Leerzeichen ist value < 100
      else if (buff[18] == ' ' || buff[12] == '.') {
        int z, e;
        z = buff[16] - '0';
        e = buff[17] - '0';
        balllengh_app = 10 * z + e ;
        if (G_red < 0  )G_red = 0;
        if (G_red > 50)G_red = 50;
        if (p_strip1.enable | p_strip2.enable)  balllengh_max = balllengh_app;
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }


    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //                                          Slider-Auswertung                                           //
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/frot/") != -1) {
      if (debug1 | debug2) Serial.println("Bin in frot");
      char buff[35];
      req.toCharArray(buff, req.length());

      // Wenn 11 ein Punkt|Leerzeichen ist value < 10
      if (buff[11] == ' ' || buff[11] == '.') {
        int e = buff[10] - '0';
        G_red = e ;
        if (G_red < 0)G_red = 0;
        if (G_red > 9)G_red = 9;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      // Wenn 12 ein Punkt|Leerzeichen ist value < 100
      else if (buff[12] == ' ' || buff[12] == '.') {
        int z, e;
        z = buff[10] - '0';
        e = buff[11] - '0';
        G_red = 10 * z + e ;
        if (G_red < 0  )G_red = 0;
        if (G_red > 255)G_red = 255;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      // Wenn 13 ein Punkt|Leerzeichen ist value > 10
      else if (buff[13] == ' ' || buff[13] == '.') {
        int h, z, e;
        h = buff[10] - '0';
        z = buff[11] - '0';
        e = buff[12] - '0';
        G_red = 100 * h + 10 * z + e ;
        if (G_red < 0  )G_red = 0;
        if (G_red > 255)G_red = 255;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      if (debug1 | debug2) Serial.print("redValue = "); Serial.println(G_red);
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/fblau/") != -1) {
      if (debug1 | debug2) Serial.println("Bin in flbau");
      char buff[35];
      req.toCharArray(buff, req.length());

      // Wenn 12 ein Punkt|Leerzeichen ist value < 10
      if (buff[12] == ' ' || buff[12] == '.') {
        int e = buff[11] - '0';
        G_blue = e ;
        if (G_blue < 0)G_blue = 0;
        if (G_blue > 9)G_blue = 9;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      // Wenn 13 ein Punkt|Leerzeichen ist value < 100
      else if (buff[13] == ' ' || buff[13] == '.') {
        int z, e;
        z = buff[11] - '0';
        e = buff[12] - '0';
        G_blue = 10 * z + e ;
        if (G_blue < 0  )G_blue = 0;
        if (G_blue > 255)G_blue = 255;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      // Wenn 14 ein Punkt|Leerzeichen ist value > 100
      else if (buff[14] == ' ' || buff[14] == '.') {
        int h, z, e;
        h = buff[11] - '0';
        z = buff[12] - '0';
        e = buff[13] - '0';
        G_blue = 100 * h + 10 * z + e ;
        if (G_blue < 0  )G_blue = 0;
        if (G_blue > 255)G_blue = 255;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }
      if (debug1 | debug2) Serial.print("blueValue = "); Serial.println(G_blue);
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/fgreen/") != -1) {
      if (debug1 | debug2) Serial.println("Bin in fgreen");
      char buff[35];
      int G_green;
      req.toCharArray(buff, req.length());

      // Wenn 13 ein Punkt|Leerzeichen ist value < 10
      if (buff[13] == ' ' || buff[13] == '.') {
        int e = buff[12] - '0';
        G_green = e ;
        if (G_green < 0)G_green = 0;
        if (G_green > 9)G_green = 9;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      // Wenn 14 ein Punkt|Leerzeichen ist value < 100
      else if (buff[14] == ' ' || buff[14] == '.') {
        int z, e;
        z = buff[12] - '0';
        e = buff[13] - '0';
        G_green = 10 * z + e ;
        if (G_green < 0  )G_green = 0;
        if (G_green > 255)G_green = 255;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      // Wenn 14 ein Punkt|Leerzeichen ist value > 100
      else if (buff[15] == ' ' || buff[15] == '.') {
        int h, z, e;
        h = buff[12] - '0';
        z = buff[13] - '0';
        e = buff[14] - '0';
        G_green = 100 * h + 10 * z + e ;
        if (G_green < 0  )G_green = 0;
        if (G_green > 255)G_green = 255;
        if (p_strip1.enable)p_strip1.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
        if (p_strip2.enable)p_strip2.LED_farbe_1 = RgbColor (G_red, G_green, G_blue);
      }

      if (debug1 | debug2) Serial.print("GreenValue = "); Serial.println(G_green);
      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/hell/") != -1) {
      if (debug1 | debug2) Serial.println("Bin in hell");
      char buff[35];
      int temp;
      req.toCharArray(buff, req.length());

      // Wenn 11 ein Punkt|Leerzeichen ist value < 10
      if (buff[11] == ' ' || buff[11] == '.') {
        int e = buff[10] - '0';
        temp = e ;
        if (temp < 0)temp = 0;
        if (temp > 9)temp = 9;
        if (p_strip1.enable)p_strip1.Brightness = temp;
        if (p_strip2.enable)p_strip2.Brightness = temp;
      }

      // Wenn 12 ein Punkt|Leerzeichen ist value < 100
      else if (buff[12] == ' ' || buff[12] == '.') {
        int z, e;
        z = buff[10] - '0';
        e = buff[11] - '0';
        temp = 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.Brightness = temp;
        if (p_strip2.enable)p_strip2.Brightness = temp;
      }

      // Wenn 13 ein Punkt|Leerzeichen ist value > 100
      else if (buff[13] == ' ' || buff[13] == '.') {
        int h, z, e;
        h = buff[10] - '0';
        z = buff[11] - '0';
        e = buff[12] - '0';
        temp = 100 * h + 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.Brightness = temp;
        if (p_strip2.enable)p_strip2.Brightness = temp;
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/intensitaet/") != -1) {
      if (debug1 | debug2) Serial.println("Bin in hell");
      char buff[35];
      int temp;
      req.toCharArray(buff, req.length());

      // Wenn 18 ein Punkt|Leerzeichen ist value < 10
      if (buff[18] == ' ' || buff[18] == '.') {
        int e = buff[17] - '0';
        temp = e ;
        if (temp < 0)temp = 0;
        if (temp > 9)temp = 9;
        if (p_strip1.enable)p_strip1.Intensity = temp;
        if (p_strip2.enable)p_strip2.Intensity = temp;
      }

      // Wenn 19 ein Punkt|Leerzeichen ist value < 100
      else if (buff[19] == ' ' || buff[19] == '.') {
        int z, e;
        z = buff[17] - '0';
        e = buff[18] - '0';
        temp = 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.Intensity = temp;
        if (p_strip2.enable)p_strip2.Intensity = temp;
      }

      // Wenn 20 ein Punkt|Leerzeichen ist value > 100
      else if (buff[20] == ' ' || buff[20] == '.') {
        int h, z, e;
        h = buff[17] - '0';
        z = buff[18] - '0';
        e = buff[19] - '0';
        temp = 100 * h + 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.Intensity = temp;
        if (p_strip2.enable)p_strip2.Intensity = temp;
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (req.indexOf("/effectdelay/")) {
      if (debug1 | debug2)Serial.println("Bin in effectdelay");
      char buff[40];
      int temp;
      req.toCharArray(buff, req.length());

      // Wenn 18 ein Punkt|Leerzeichen ist value < 10
      if (buff[18] == ' ' || buff[18] == '.') {
        int e = buff[17] - '0';
        temp = e ;
        if (temp < 0)temp = 0;
        if (temp > 9)temp = 9;
        if (p_strip1.enable)p_strip1.EffectDelay = temp;
        if (p_strip2.enable)p_strip2.EffectDelay = temp;
      }

      // Wenn 19 ein Punkt|Leerzeichen ist value < 100
      else if (buff[19] == ' ' || buff[19] == '.') {
        int z, e;
        z = buff[17] - '0';
        e = buff[18] - '0';
        temp = 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.EffectDelay = temp;
        if (p_strip2.enable)p_strip2.EffectDelay = temp;
      }

      // Wenn 20 ein Punkt|Leerzeichen ist value > 100
      else if (buff[20] == ' ' || buff[20] == '.') {
        int h, z, e;
        h = buff[17] - '0';
        z = buff[18] - '0';
        e = buff[19] - '0';
        temp = 100 * h + 10 * z + e ;
        if (temp < 0  )temp = 0;
        if (temp > 255)temp = 255;
        if (p_strip1.enable)p_strip1.EffectDelay = temp;
        if (p_strip2.enable)p_strip2.EffectDelay = temp;
      }

      if(debug1)debugg(p_strip1);
      if(debug2)debugg(p_strip2);
      return;
    }
  }
  client.flush();
}