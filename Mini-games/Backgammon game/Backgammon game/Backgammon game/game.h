#define _CRT_SECURE_NO_WARNINGS 1
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define ROW 3
#define COL  3

//初始化棋盘，将棋盘设置为空格
void InitBoard(char board[ROW][COL], int row, int col);

//布置棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断谁赢
char IsWin(char board[ROW][COL], int row, int col);