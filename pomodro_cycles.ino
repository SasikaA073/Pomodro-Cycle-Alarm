#include "game_of_thrones.h"
#include "sweet_child_of_mine.h"
#include "pirates_of_the_carribean.h"
#include "knight_rider.h"

unsigned long studySession = 25UL; // in mins; pomodoro cycle study session
unsigned long interval = 5UL;      // in mins; short interval after a study session

unsigned long pomodoroCycleDuration = studySession + interval;
unsigned long longBreak = pomodoroCycleDuration * 4 - interval; // 4 cycles per a pomodro study Full period

unsigned long nowTime;

unsigned long melody1PlayedTimes = 1UL;
unsigned long melody2PlayedTimes = 1UL;
unsigned long melody3PlayedTimes = 1UL;

bool melody1Played = false; // Sweet child of mine
bool melody2Played = false; // Pirates of the Carribean
bool melody3Played = false; // Game of Thrones

bool melody1PlayingStop = false;
bool melody2PlayingStop = false;
bool melody3PlayingStop = false;

void setup()
{

  Serial.begin(9600);
};

void loop()
{
  // Generally pomodoro cycle runs for 4 cycles and then 15-30 mins long break

  nowTime = millis();

  if (((nowTime) >= (60UL * 1000UL * (pomodoroCycleDuration * (melody1PlayedTimes - 1UL)))) && !melody1PlayingStop) // Melody 1
  {
    Serial.print("Now time is : ");
    Serial.println(millis());

    SweetChildOMine();

    Serial.print("Melody 1 : Sweet Child of Mine played for times >> ");
    Serial.println(melody1PlayedTimes);

    melody1PlayedTimes += 1UL;
    if (melody1PlayedTimes >= 5)
    {
      melody1PlayingStop = true;
    }
  }

  else if ((nowTime) >= (60UL * 1000UL * ((pomodoroCycleDuration * melody2PlayedTimes) - interval)) && !melody2PlayingStop) // Melody 2
  {
    Serial.print("Now time is : ");
    Serial.println(millis());

    PiratesOTheCarribean();

    for (int i = 0; i < 2; i++)
    {
      knightRider(50);
    }

    Serial.print("Melody 1 : Pirate of the Carribean played for times >> ");
    Serial.println(melody2PlayedTimes);

    melody2PlayedTimes += 1UL;
    if (melody2PlayedTimes >= 4)
    {
      melody2PlayingStop = true;
    }
  }

  else if (((nowTime) >= ((60UL * 1000UL * longBreak))) && !melody3PlayingStop) // Melody 3
  {
    Serial.print("Now time is : ");
    Serial.println(millis());

    for (int i = 0; i < 2; i++) // Plays for a long time to force the student to get a long break
    {

      GameOfThrones();
    }

    Serial.print("Melody 3 : Game of Thrones played for times >> ");
    Serial.println(melody3PlayedTimes);
    Serial.println(" ");
    Serial.println("The Pomodoro Study Session is over... ");

    melody3PlayedTimes += 1;
    if (melody3PlayedTimes >= 2)
    {
      melody3PlayingStop = true;
    }
  }
}
