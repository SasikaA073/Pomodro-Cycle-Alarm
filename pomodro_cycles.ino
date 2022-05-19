#include "game_of_thrones.h"
#include "sweer_child_of_mine.h"
#include "pirates_of_the_carribean.h"
#include "knight_rider.h"

int pomodroCycleDuration = 25 * 60 * 1000;  // 25 mins
int intervalDuration = 5 * 60 * 1000;       // 5 mins
int longBreakDuration = 30 * 60 * 1000;



void pomodroCycle(int cycleDuration,int interval){
  // Start of the pomodro cycle - plays melody 1, knightrider light pattern
  
  SweetChildOMine();
  for (int i = 0;i<3;i++)
  {
    knightRider(50);
  }
  
  // Wait for the cycle to end for 25 mins
  delay(cycleDuration);
  
  // End of the pomodro cycle - plays melody 2 , for two times 
  for (int i = 0;i<2;i++)
  {
  PiratesOTheCarribean();
  }
  
  // Start of the interval period
  delay(interval);
  
}
void setup() {
  // put your setup code here, to run once:
  
//GameOfThrones();  
//SweetChildOMine();
//PiratesOTheCarribean();


}

void loop() {
  // Generally pomodro cycle runs for 4 cycles and then 15-30 mins long break

  // 4 Pomodro Cycles
  for (int i = 0;i<4;i++){
    pomodroCycle(pomodroCycleDuration,intervalDuration);
  }

  // At the end plays melody 3
  // 30 mins break 
  GameOfThrones();
  delay(longBreakDuration);
  
}
