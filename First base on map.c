#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 90
#define SIZETWO 180

void Print();

void baseOne(char array[SIZE][SIZETWO]);
void baseTwo(char array[SIZE][SIZETWO]);
void baseThree(char array[SIZE][SIZETWO]);
void baseFour(char array[SIZE][SIZETWO]);
void baseFive(char array[SIZE][SIZETWO]);
void baseSix(char array[SIZE][SIZETWO]);

void clearMap(char array[SIZE][SIZETWO]);
void printMap(char array[SIZE][SIZETWO]);




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


int main()
{
  char map[SIZE][SIZETWO];
  Print();
  clearMap(map);
  printMap(map);
  return 0;
}

void Print(){
    system("cls");
    printf("\033[1;31m");
    printf("\tWelcome to Hexagon Conquest.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\tGame instructions:\n");
    printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    printf("\033[0m");
    if(getch()==27)
        exit(0);
    system("cls");
}

void baseOne(char map[SIZE][SIZETWO]) {
  char ver = 186, hor = 205, infRightCorner = 188, infLeftCorner = 200, supRightCorner = 187, supLeftCorner = 201;
  char figure[] = {186, 205, 188, 200, 187, 201};
  map[0][48] = supLeftCorner;
  printf("%c\n", map[0][48]);
  for (int i = 49; i <= 59; i++) {
    map[0][i] = hor;
  }
  map[0][60] = supRightCorner;

  for (int i = 1; i <= 5; i++) {
    map[i][48] = ver;
    map[i][60] = ver;
  }

  map[6][48] = infLeftCorner;
  for (int i = 49; i <= 59; i++) {
    map[6][i] = hor;
  }
  map[6][60] = infRightCorner;
}

void printMap(char map[SIZE][SIZETWO]){
  baseOne(map);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZETWO; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

void clearMap(char map[SIZE][SIZETWO]){
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZETWO; j++) {
      map[i][j] = 0;
    }
  }
}
