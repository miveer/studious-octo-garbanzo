#pragma once
#include "Variablen.h"

void ini_io(void) {
  pinMode(32,INPUT_PULLUP);
  pinMode(21, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(MicroEingang, INPUT);
  pinMode(AUX_Eingang  , INPUT);
  pinMode(AUX_EingangRechts, INPUT);
  analogReadResolution(10);
}

