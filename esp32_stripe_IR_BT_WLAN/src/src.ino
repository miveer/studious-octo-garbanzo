#include "Variablen.h"
#include "ini_funktionen.h"
#include "inistripes_default_values.h"
#include "fernbedienungsbutton.h"
#include "musik_config.h"
#include "IR_auswertung.h"
#include "Funktionen.h"
#include "debugg.h"
//#include "OTA.h"
#include <NeoPixelBrightnessBus.h>
#include "arduinoFFT.h"
//#include "MITapp_WiFi.h"
#include "IRremote.h"
#include "bluetooth_setup.h"
#include "bluetooth_auswertung.h"


// To-Do
// Colors pro Animation anpassen

TaskHandle_t Task1;

void setup()
{
  Serial.begin(115200);
  //Serial.println("Setup start");
  ini_io();

  // Startet Bluetooth mit Name
  SerialBT.begin("Stripetastic"); //Bluetooth device name
  Serial.println("Bluetooth gestartet.");
  
  //irrecv.enableIRIn(); // Start the receiver
  stripe1.Begin();
  stripe2.Begin();

  inistripes_default_values();
 

  xTaskCreatePinnedToCore(Task1code,"Task2",20000,NULL,1,&Task1,1);
  
  //ini_wifi();  
  //server.begin();

  //handle_OTA();

  //Serial.println("Setup done.");
}

void loop() {

  //ArduinoOTA.handle();


  //check_Wifi();    
  check_bt();
  
 //check_ir();


}

//Task1code: 
void Task1code( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    programm(&stripe1, p_strip1); // Hier stripe 1 eintragen
    programm(&stripe2, p_strip2); // Hier stripe 2 eintragen
    if(p_strip1.FFTAktive){
      prozzesFFT();
    }
  } 
}
