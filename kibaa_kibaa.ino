#include "Arduino.h"
#include "SoftwareSerial.h" 
#include "DFRobotDFPlayerMini.h" 

SoftwareSerial DFPlayer(8, 9);
DFRobotDFPlayerMini KibaPlayer;

volatile unsigned int Kiba = 1;

void setup()
{
  DFPlayer.begin(9600);
  if (!KibaPlayer.begin(DFPlayer)) {
    while (true) {
      delay(0);
    }
  }
  KibaPlayer.volume(20); 

  attachInterrupt(1, SayKiba, RISING); 
}

void loop()
{
}

void SayKiba()  
{
  KibaPlayer.play(Kiba);  //Kibaaa Kibaaa!
  Kiba++;
  if (Kiba == 6) Kiba = 1;
}
