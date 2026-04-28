#include<iostream>
#include<conio.h>
#include"pushbox.h"
#include<windows.h>

int map[MAP_ROW][MAP_COL] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,4,0,0,0,0,1},
	{1,0,0,0,3,0,3,0,0,1},
	{1,0,0,0,2,0,0,4,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,3,0,0,0,0,0,0,1},
	{1,0,0,0,4,0,0,3,0,1},
	{1,4,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
//int map[MAP_ROW][MAP_COL] = {
//	{0,0,1,1,1,1,1,1,0,0},
//	{0,0,1,0,0,0,0,1,0,0},
//	{1,1,1,0,3,0,0,1,1,1},
//	{1,4,0,0,0,3,0,0,4,1},
//	{1,0,0,1,0,0,1,0,0,1},
//	{1,0,0,0,2,0,0,0,0,1},
//	{1,1,0,1,3,0,1,0,1,1},
//	{0,1,0,0,0,0,4,0,1,0},
//	{0,1,0,0,1,1,0,0,1,0},
//	{0,1,1,1,1,1,1,1,1,0}
//};

int main() {
	// 关键：强制控制台输入输出都使用 UTF-8 编码
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	drawGame();
	while (1) {
		playGame();
		drawGame();
		if (isLose()) {
			std::cout << "游戏失败" << std::endl;
			break;
		}
		if (isWin()) {
			std::cout << "游戏胜利" << std::endl;
			break;
		}
	}
	system("pause");
	return 0;
}

void drawGame() {
	system("cls");
	for (int i = 0; i < MAP_ROW; ++i) {
		for (int j = 0; j < MAP_COL; ++j) {
			switch (map[i][j]) {
			case map_null:
				std::cout << "  ";
				break;
			case map_wall:
				std::cout << "墙";
				break;
			case map_man:
				std::cout << "人";
				break;
			case map_box:
				std::cout << "箱";
				break;
			case map_destination:
				std::cout << "地";
				break;
			case map_manAnddestination:
				std::cout << "人";
				break;
			case map_boxAnddestination:
				std::cout << "箱";
				break;
			}
		}
		std::cout << std::endl;
	}
}

void playGame() {
	int x, y;   //人的坐标
	for (int i = 0; i < MAP_ROW; ++i) {
		for (int j = 0; j < MAP_COL; ++j) {
			if (map[i][j] == map_man || map[i][j] == map_manAnddestination) {
				x = i;
				y = j;
			}
		}
	}

	switch (_getch()) {
	case up:
		if (map[x - 1][y] == map_null || map[x - 1][y] == map_destination) {
			map[x - 1][y] += 2;
			map[x][y] -= 2;
		}
		else if (map[x - 1][y] == map_box || map[x - 1][y] == map_boxAnddestination) {
			if (map[x - 2][y] == map_null || map[x - 2][y] == map_destination) {
				map[x - 2][y] += 3;
				map[x - 1][y] -= 1;
				map[x][y] -= 2;
			}
		}
		break;

	case down:
		if (map[x + 1][y] == map_null || map[x + 1][y] == map_destination) {
			map[x + 1][y] += 2;
			map[x][y] -= 2;
		}
		else if (map[x + 1][y] == map_box || map[x + 1][y] == map_boxAnddestination) {
			if (map[x + 2][y] == map_null || map[x + 2][y] == map_destination) {
				map[x + 2][y] += 3;
				map[x + 1][y] -= 1;
				map[x][y] -= 2;
			}
		}
		break;

	case left:
		if (map[x][y - 1] == map_null || map[x][y - 1] == map_destination) {
			map[x][y - 1] += 2;
			map[x][y] -= 2;
		}
		else if (map[x][y - 1] == map_box || map[x][y - 1] == map_boxAnddestination) {
			if (map[x][y - 2] == map_null || map[x][y - 2] == map_destination) {
				map[x][y - 2] += 3;
				map[x][y - 1] -= 1;
				map[x][y] -= 2;
			}
		}
		break;

	case right:
		if (map[x][y + 1] == map_null || map[x][y + 1] == map_destination) {
			map[x][y + 1] += 2;
			map[x][y] -= 2;
		}
		else if (map[x][y + 1] == map_box || map[x][y + 1] == map_boxAnddestination) {
			if (map[x][y + 2] == map_null || map[x][y + 2] == map_destination) {
				map[x][y + 2] += 3;
				map[x][y + 1] -= 1;
				map[x][y] -= 2;
			}
		}
		break;
	}
}

bool isWin() {
	for (int i = 0; i < MAP_ROW; ++i) {
		for (int j = 0; j < MAP_COL; ++j) {
			if (map[i][j] == map_box) {
				return false;
			}
		}
	}
	return true;
}

bool isLose() {
	if (map[1][1] == map_box || map[1][MAP_COL - 2] == map_box || map[MAP_ROW - 2][1] == map_box || map[MAP_ROW - 2][MAP_COL - 2] == map_box) {
		return true;
	}
	return false;
}