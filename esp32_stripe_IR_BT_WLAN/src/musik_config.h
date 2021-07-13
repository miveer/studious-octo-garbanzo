#pragma once
#include "Variablen.h"
#include "arduinoFFT.h"

// Defines für Musik
#define SAMPLES 20     // für min/max Berechnung Musik
#define PEAK_FALL 15   // Gibt geschwindigkeit vom DotFall vor  // könnte man in der UI im Setup einstellbar machen

// Defines für FFT
#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

// Variablen für FFT
arduinoFFT    FFT               = arduinoFFT();     /* Create FFT object */
const int     samples_fft       = 512;    //This value MUST ALWAYS be a power of 2
const double  samplingFrequency = 10000;   // Hz, must be less than 10000 due to ADC  ACHTUNG BEI ÄNDERUNG MUSS Sampledelay angepasst werden
const long    samplingDelay     = 100;   // Zeit in µS          1000 -> 1ms -> 1kHz
double        vReal[samples_fft];         // Speichert Real Anteil
double        vImag[samples_fft];         // Speichert Imag Anteil  z = vReal + vImag
bool          isRdy    = 0;               // Zeigt an wenn Samplephase fertig ist
unsigned long oldtime  = 0;               // Speichert alte Sampezeit
int           idex     = 0;               // Speichert sich Index beim Samplen

// könnte man in der UI im Setup einstellbar machen
int           maxfreq  = 500;             // gibt MaxFreq der FFT Auswertung
int           minfreq  =  30;             // unteres limit für Frequenz zum Scalen in map funktion
int           delayMax =  25;             // Maximale Verzögerung
int           delayMin =   1;             // Minimale Verzögerung

// Analoge Eingeänge für Microfon und AUX
const int MicroEingang      = 34;        // esp32 - Pin 34
const int AUX_EingangRechts = 35;        // esp32 - Pin 35
const int AUX_Eingang       = 25;        // esp32 - Pin 25
int       CHANNEL           = 34;        // Channel für FFT - Defult MircoEingang
int       DC_OFFSET         = 341;       // Offset für Miro bzw Aux -> bedeutet 0 da zum positiven und "negativen" Ausgelenkt werden muss
