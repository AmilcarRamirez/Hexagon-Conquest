#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "string.h"

#define HEIGHT 46
#define WIDTH 91
#define DEPTH 10

#define ASCII_VER 186
#define ASCII_HOR 205
#define ASCII_IRC 188
#define ASCII_ILC 200
#define ASCII_SRC 187
#define ASCII_SLC 201

#define ASCII_BMAYUS 66
#define ASCII_A 97
#define ASCII_S 115
#define ASCII_E 101
#define ASCII_NUM 35



typedef struct base_data {
  char id;
  int x;
  int y;
  int w;
  int h;
} bd;

typedef struct play_data{
  int turn;
} pd;
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


void startUpText();
void colors();

void createBase(char[HEIGHT][WIDTH][DEPTH], bd);
void basesGeneration(char[HEIGHT][WIDTH][DEPTH]);

void clearMap(char[HEIGHT][WIDTH][DEPTH]);
void printMap(char[HEIGHT][WIDTH][DEPTH]);
void nameBase(bd, char[HEIGHT][WIDTH][DEPTH]);


int main(){
  char map[HEIGHT][WIDTH][DEPTH];
  startUpText();
  clearMap(map);
  printMap(map);
  return 0;
}

void startUpText(){
    system("cls");
    printf("\033[1;34m");
    printf("\tWelcome to Hexagon Conquest.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\tGame instructions:\n");
    printf("\n-> Press a number in your keyboard between 1, 2 and 3.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    printf("\033[0m");
    if(getch()==27)
        exit(0);
    system("cls");
}

void basesGeneration(char map[HEIGHT][WIDTH][DEPTH]){
  bd data;
  data.x = 25;
  data.y = 1;
  data.w = 12;
  data.h = 6;
  data.id = '1';
  createBase(map, data);
  data.x = 55;
  data.y = 1;
  data.w = 12;
  data.h = 6;
  data.id = '2';
  createBase(map, data);
  data.x = 79;
  data.y = 12;
  data.w = 12;
  data.h = 6;
  data.id = '3';
  createBase(map, data);
  data.x = 79;
  data.y = 27;
  data.w = 12;
  data.h = 6;
  data.id = '4';
  createBase(map, data);
  data.x = 55;
  data.y = 39;
  data.w = 12;
  data.h = 6;
  data.id = '5';
  createBase(map, data);
  data.x = 25;
  data.y = 39;
  data.w = 12;
  data.h = 6;
  data.id = '6';
  createBase(map, data);
  data.x = 1;
  data.y = 27;
  data.w = 12;
  data.h = 6;
  data.id = '7';
  createBase(map, data);
  data.x = 1;
  data.y = 12;
  data.w = 12;
  data.h = 6;
  data.id = '8';
  createBase(map, data);
}

void printMap(char map[HEIGHT][WIDTH][DEPTH]){
  basesGeneration(map);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%s", map[i][j]);
    }
    printf("\n");
  }
}

void clearMap(char map[HEIGHT][WIDTH][DEPTH]){
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      for (int k = 0; k < DEPTH; k++) {
        map[i][j][k] = 42;
      }
    }
  }
}

void createBase(char map[HEIGHT][WIDTH][DEPTH], bd data) {
  char color[9];
  if (data.id == 51) {
    strcpy (color, "\033[0;31m");
  }else{
    strcpy (color, "\033[0;34m");
  }

  //strcat(color, "\201");
  strcpy(map[data.y - 1][data.x - 1], color);
  map[data.y][data.x][0] = ASCII_SLC;
  map[data.y + data.h ][data.x][0] = ASCII_ILC; //CHECK SIZE
  map[data.y][data.x + data.w][0] = ASCII_SRC;
  map[data.y + data.h ][data.x + data.w][0] = ASCII_IRC;

  for (int i = 1; i < data.h; i++) { //CHECK SIZE
    map[data.y + i][data.x][0] = ASCII_VER;

    map[data.y + i][data.x + data.w][0] = ASCII_VER; //CHECK SIZE
  }

  for (int i = 1; i < data.w; i++) { //CHECK SIZE
    map[data.y][data.x + i][0] = ASCII_HOR;
    map[data.y + data.h][data.x + i][0] = ASCII_HOR; //CHECK SIZE
  }
  nameBase(data, map);

}


void nameBase(bd data, char map[HEIGHT][WIDTH][DEPTH]){
  for (int i = 1; i < 8; i++) {
    switch (i) {
      case 1:
        map[data.y + 1][data.x + i][0] = ASCII_BMAYUS;
        break;
      case 2:
        map[data.y + 1][data.x + i][0] = ASCII_A;
        break;
      case 3:
        map[data.y + 1][data.x + i][0] = ASCII_S;
        break;
      case 4:
        map[data.y + 1][data.x + i][0] = ASCII_E;
        break;
      case 5:
        map[data.y + 1][data.x + i][0] = 42;
        break;
      case 6:
        map[data.y + 1][data.x + i][0] = ASCII_NUM;
        break;
      case 7:
        map[data.y + 1][data.x + i][0] = data.id;
        break;
    }
  }
}
