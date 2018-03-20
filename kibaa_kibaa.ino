#include "Arduino.h"
#include "SoftwareSerial.h" //библиотека для работы с последовательным портом
#include "DFRobotDFPlayerMini.h"  //библиотека для работы с MP3-плеером

SoftwareSerial DFPlayer(8, 9); //порты RX, TX на плате, к которым подключается MP3-плеер
DFRobotDFPlayerMini KibaPlayer; //именуем MP3-плеер

volatile unsigned int Kiba = 1;  //флаг для отслеживания сказанных фраз

void setup()
{
  DFPlayer.begin(9600);
  if (!KibaPlayer.begin(DFPlayer)) {  //включение плеера
    while (true) {
      delay(0);
    }
  }
  KibaPlayer.volume(20);  //громкость звука

  attachInterrupt(1, SayKiba, RISING);  //прерывание по нажатию тревожной кнопки
}

void loop()
{
}

void SayKiba()  //обработчик прерываний с кнопки
{
  KibaPlayer.play(Kiba);  //Kibaaa Kibaaa!
  Kiba++;
  if (Kiba == 6) Kiba = 1;
}

/*void loop()
{
  noInterrupts();
  KibaKiba = Kiba;  //передача данных из обработчика прерываний
  interrupts();

  if (KibaKiba) {
    KibaPlayer.play(kiba);  //Kibaaa Kibaaa!
    delay(2500);
    kiba++;
    KibaKiba = 0;
    Kiba = 0;
    if (kiba == 6) kiba = 1;
  };
}

void SayKiba()  //обработчик прерываний с кнопки
{
  Kiba = 1;
}*/
