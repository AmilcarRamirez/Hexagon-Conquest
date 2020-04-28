#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 46
#define SIZETWO 91

void Print();

void baseOne(char array[SIZE][SIZETWO]);
void baseTwo(char array[SIZE][SIZETWO]);
void baseThree(char array[SIZE][SIZETWO]);
void baseFour(char array[SIZE][SIZETWO]);
void baseFive(char array[SIZE][SIZETWO]);
void baseSix(char array[SIZE][SIZETWO]);
void baseSeven(char array[SIZE][SIZETWO]);
void baseEight(char array[SIZE][SIZETWO]);

void clearMap(char array[SIZE][SIZETWO]);
void printMap(char array[SIZE][SIZETWO]);
void nameBase(int, int, char array[SIZE][SIZETWO]);




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
    printf("\033[1;34m");
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
  map[0][24] = supLeftCorner;
  for (int i = 25; i <= 35; i++) {
    map[0][i] = hor;
  }
  map[0][36] = supRightCorner;

  for (int i = 1; i <= 5; i++) {
    map[i][24] = ver;
    map[i][36] = ver;
  }

  map[6][24] = infLeftCorner;
  for (int i = 25; i <= 35; i++) {
    map[6][i] = hor;
  }
  map[6][36] = infRightCorner;
}

void baseTwo(char map[SIZE][SIZETWO]) {
  char ver = 186, hor = 205, infRightCorner = 188, infLeftCorner = 200, supRightCorner = 187, supLeftCorner = 201;
  map[0][54] = supLeftCorner;

  for (int i = 55; i <= 65; i++) {
    map[0][i] = hor;
  }
  map[0][66] = supRightCorner;

  for (int i = 1; i <= 5; i++) {
    map[i][54] = ver;
    map[i][66] = ver;
  }
  map[6][54] = infLeftCorner;
  for (int i = 55; i <= 65; i++) {
    map[6][i] = hor;
  }
  map[6][66] = infRightCorner;
}

void baseThree(char map[SIZE][SIZETWO]) {
  char ver = 186, hor = 205, infRightCorner = 188, infLeftCorner = 200, supRightCorner = 187, supLeftCorner = 201;
  map[12][78] = supLeftCorner;

  for (int i = 79; i <= 89; i++) {
    map[12][i] = hor;
  }
  map[12][90] = supRightCorner;

  for (int i = 13; i <= 17; i++) {
    map[i][78] = ver;
    map[i][90] = ver;
  }
  map[18][78] = infLeftCorner;
  for (int i = 79; i <= 89; i++) {
    map[18][i] = hor;
  }
  map[18][90] = infRightCorner;
}

void baseFour(char map[SIZE][SIZETWO]) {
  char ver = 186, hor = 205, infRightCorner = 188, infLeftCorner = 200, supRightCorner = 187, supLeftCorner = 201;
  map[27][78] = supLeftCorner;

  for (int i = 79; i <= 89; i++) {
    map[27][i] = hor;
  }
  map[27][90] = supRightCorner;

  for (int i = 28; i <= 32; i++) {
    map[i][78] = ver;
    map[i][90] = ver;
  }
  map[33][78] = infLeftCorner;
  for (int i = 79; i <= 89; i++) {
    map[33][i] = hor;
  }
  map[33][90] = infRightCorner;
}

void baseFive(char map[SIZE][SIZETWO]) {
  char ver = 186, hor = 205, infRightCorner = 188, infLeftCorner = 200, supRightCorner = 187, supLeftCorner = 201;
  map[39][24] = supLeftCorner;
  for (int i = 25; i <= 35; i++) {
    map[39][i] = hor;
  }
  map[39][36] = supRightCorner;

  for (int i = 40; i <= 44; i++) {
    map[i][24] = ver;
    map[i][36] = ver;
  }

  map[45][24] = infLeftCorner;
  for (int i = 25; i <= 35; i++) {
    map[45][i] = hor;
  }
  map[45][36] = infRightCorner;
}

void baseSix(char map[SIZE][SIZETWO]) {
  char ver = 186, hor = 205, infRightCorner = 188, infLeftCorner = 200, supRightCorner = 187, supLeftCorner = 201;
  map[39][54] = supLeftCorner;

  for (int i = 55; i <= 65; i++) {
    map[39][i] = hor;
  }
  map[39][66] = supRightCorner;

  for (int i = 40; i <= 44; i++) {
    map[i][54] = ver;
    map[i][66] = ver;
  }
  map[45][54] = infLeftCorner;
  for (int i = 55; i <= 65; i++) {
    map[45][i] = hor;
  }
  map[45][66] = infRightCorner;
}

void baseSeven(char map[SIZE][SIZETWO]) {
  char ver = 186, hor = 205, infRightCorner = 188, infLeftCorner = 200, supRightCorner = 187, supLeftCorner = 201;
  map[27][0] = supLeftCorner;

  for (int i = 1; i <= 11; i++) {
    map[27][i] = hor;
  }
  map[27][12] = supRightCorner;

  for (int i = 28; i <= 32; i++) {
    map[i][0] = ver;
    map[i][12] = ver;
  }
  map[33][0] = infLeftCorner;
  for (int i = 1; i <= 11; i++) {
    map[33][i] = hor;
  }
  map[33][12] = infRightCorner;
}

void baseEight(char map[SIZE][SIZETWO]) {
  char ver = 186, hor = 205, infRightCorner = 188, infLeftCorner = 200, supRightCorner = 187, supLeftCorner = 201;
  map[12][0] = supLeftCorner;

  for (int i = 1; i <= 11; i++) {
    map[12][i] = hor;
  }
  map[12][12] = supRightCorner;

  for (int i = 13; i <= 17; i++) {
    map[i][0] = ver;
    map[i][12] = ver;
  }
  map[18][0] = infLeftCorner;
  for (int i = 1; i <= 11; i++) {
    map[18][i] = hor;
  }
  map[18][12] = infRightCorner;
}

void nameBase(int locationX, int locationY, char map[SIZE][SIZETWO]){
  for (int i = locationX; i < (locationX + 8); i++) {
    switch (i) {
      case 1:
        break;
    }
  }
}

void printMap(char map[SIZE][SIZETWO]){
  baseOne(map);
  baseTwo(map);
  baseThree(map);
  baseFour(map);
  baseFive(map);
  baseSix(map);
  baseSeven(map);
  baseEight(map);
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
