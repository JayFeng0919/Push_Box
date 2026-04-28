#pragma once
#define MAP_ROW 10
#define MAP_COL 10

enum { map_null = 0, map_wall = 1, map_man = 2, map_box = 3, map_destination = 4, map_manAnddestination = 6, map_boxAnddestination = 7 };
enum { up = 'w', down = 's', left = 'a', right = 'd' };

void drawGame();
void playGame();
bool isWin();
bool isLose();

extern int map[MAP_ROW][MAP_COL];