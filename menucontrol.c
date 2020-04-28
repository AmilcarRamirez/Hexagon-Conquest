#include "stdio.h"
#include "conio.h"
#include "windows.h"
#include "stdlib.h"
#include "time.h"

#define TURNSIZE 3

void firstTurn(char, int*, int playerTurn[TURNSIZE]);
void clearTurn(int array[TURNSIZE]);
void turn();

void NPCaction();

void menu();

/*[0;31m	Red
[1;31m	Bold Red
[0;32m	Green
[1;32m	Bold Green
[0;33m	Yellow
[01;33m	Bold Yellow
[0;34m	Blue
[1;34m	Bold Blue
[0;35m	Magenta
[1;35m	Bold Magenta
[0;36m	Cyan
[1;36m	Bold Cyan
[0m	Reset */

int main(int argc, char const *argv[]) {
  menu();
  return 0;
}

void clearMap(int playerTurn[TURNSIZE]){
  for (int i = 0; i < TURNSIZE; i++) {
      playerTurn[i] = 0;
    }
}

void firstTurn(char input, int *playerTurnChoice, int playerTurn[TURNSIZE]){
  int curntPlaTurn;
  srand (time(NULL));
  curntPlaTurn = (rand() % (3)) + 1;
  switch (input) {
    case 49:
      *playerTurnChoice = 1;
      break;
    case 50:
      *playerTurnChoice = 2;
      break;
    case 51:
      *playerTurnChoice = 3;
      break;
  }
  playerTurn[curntPlaTurn] = *playerTurnChoice;
}

void turn(){
  for (int i = 0; i < 2; i++) {
    /* code */
  }
}

void menu(){
  int playerTurn[TURNSIZE], playerTurnChoice;
  char input;
  printf("Please, press a number between 1, 2 and 3\n");
  input = getch();
  firstTurn(input, &playerTurnChoice, playerTurn);

}
