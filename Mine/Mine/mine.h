#ifndef _MINE_H_
#define _MINE_H_

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#pragma warning (disable: 4996)

#define ROW 12//10+2
#define COL 12
#define TOTAL 10*10  //雷盘格子总数
#define MINE_NUM 20 //雷数量


void Game();
void SetMine(char mine[][COL], int row, int col);
void ShowBoard(char mine[][COL], int row, int col);
char GetMines(char mine[][COL], int row, int col);
void OpenMine(char mine[ROW][COL], char board[ROW][COL], int row, int col);


#endif