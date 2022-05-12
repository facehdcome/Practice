#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("\n**************************\n");
	printf("**** 1. Play   0.exit ****\n");
	printf("**************************\n");
}

//游戏开始
void game()
{
	//返回结果
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化
	InitBoard(board,ROW,COL);
	//打印键盘
	DisplayBoard(board,ROW,COL);
	//开始下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//玩家是否赢
		ret = IsWin(board, ROW,COL);
		if (ret != 'C')
		{
			break;
		}


		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢！\n");
	}
	else
		printf("平局");


}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\n欢迎来到三子棋游戏！\n");
			game();
			break;
		case 0:
			printf("\n游戏已经退出！\n");
			break;
		default:
			printf("\n选择错误，请重新选择！\n");
		}

	} while (input);

}

int main()
{
	test();

	return 0;
}