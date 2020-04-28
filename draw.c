#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define HEIGHT 46
#define WIDTH 91

#define ASCII_VER 186
#define ASCII_HOR 205
#define ASCII_IRC 188
#define ASCII_ILC 200
#define ASCII_SRC 187
#define ASCII_SLC 201

typedef struct base_data {
  int id;
  int x;
  int y;
  int w;
  int h;
} bd;
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

void createBase(char[HEIGHT][WIDTH], bd);
void basesGeneration(char[HEIGHT][WIDTH]);

void clearMap(char[HEIGHT][WIDTH]);
void printMap(char[HEIGHT][WIDTH]);
//void nameBase(int, int, char, char[HEIGHT][WIDTH]);


int main(){
  char map[HEIGHT][WIDTH];
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
    printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    printf("\033[0m");
    if(getch()==27)
        exit(0);
    system("cls");
}

void basesGeneration(char map[HEIGHT][WIDTH]){
  bd data;
  data.x = 40;
  data.y = 15;
  data.w = 12;
  data.h = 6;
  data.id = 1;
  createBase(map, data);
  data.x = 53;
  data.y = 14;
  data.w = 16;
  data.h = 8;
  data.id = 2;
  createBase(map, data);
  data.x = 70;
  data.y = 13;
  data.w = 20;
  data.h = 10;
  data.id = 3;
  createBase(map, data);

}

void printMap(char map[HEIGHT][WIDTH]){
  basesGeneration(map);
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      printf("%c", map[i][j]);
    }
    printf("\n");
  }
}

void clearMap(char map[HEIGHT][WIDTH]){
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      map[i][j] = 0;
    }
  }
}

void createBase(char map[HEIGHT][WIDTH], bd data) {
  map[data.y][data.x] = ASCII_SLC;
  map[data.y + data.h ][data.x] = ASCII_ILC; //CHECK SIZE
  map[data.y][data.x + data.w] = ASCII_SRC;
  map[data.y + data.h ][data.x + data.w] = ASCII_IRC;

  for (int i = 1; i < data.h; i++) { //CHECK SIZE
    map[data.y + i][data.x] = ASCII_VER;
    map[data.y + i][data.x + data.w] = ASCII_VER; //CHECK SIZE
  }

  for (int i = 1; i < data.w; i++) { //CHECK SIZE
    map[data.y][data.x + i] = ASCII_HOR;
    map[data.y + data.h][data.x + i] = ASCII_HOR; //CHECK SIZE
  }
  //nameBase(0, 24, name, map);
}


void nameBase(int locationY, int locationX, char name, char map[HEIGHT][WIDTH]){
  for (int i = 1; i < 8; i++) {
    switch (i) {
      case 1:
        map[locationY + 1][locationX + i] = 66;
        break;
      case 2:
        map[locationY + 1][locationX + i] = 97;
        break;
      case 3:
        map[locationY + 1][locationX + i] = 115;
        break;
      case 4:
        map[locationY + 1][locationX + i] = 101;
        break;
      case 5:
        map[locationY + 1][locationX + i] = 0;
        break;
      case 6:
        map[locationY + 1][locationX + i] = 35;
        break;
      case 7:
        map[locationY + 1][locationX + i] = name;
        break;
    }
  }
}
