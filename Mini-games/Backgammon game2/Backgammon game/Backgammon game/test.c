
#include "game.h"
//打印菜单
void menu()
{
	printf("\n**************************\n");
	printf("**** 1. Play   0.exit ****\n");
	printf("**************************\n");
}

//开始游戏
int  game()
{
	char ret = 0;//判断输赢的变量
	//定义二维数组
	char board[ROW][COL] = { 0 };
	//第一步：数组初始化棋盘
	InitBoard(board, ROW, COL);
	//第二步：打印棋盘
	PrintBoard(board, ROW, COL);
	//第三部：对弈

	//玩家下棋
	while (1)
	{
		int input = PlayerBoard(board, ROW, COL);
		if (input == 0)
		{
			return 0;
		}
		PrintBoard(board, ROW, COL);

		//判断输赢
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//玩家下完棋打印一下棋盘
		PrintBoard(board, ROW, COL);
		//电脑下棋
		ComputerBoard(board, ROW, COL);
		//同样打印棋盘
		PrintBoard(board, ROW, COL);

		//判断输赢
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
		printf("平局！\n");

}

void test()
{
	//让用户选择游戏
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		int ch = 0;
		menu();
		printf("请选择：\n");
		if (scanf("%d", &input) != 1)
		{
			printf("格式有误，请重新选择!\n");
			while ((ch = getchar()) != '\n')
			{
				;
			}
			input = 3;//继续循环选择
			continue;
		}

		switch (input)
		{
		case 1:
			printf("欢迎来到三子棋游戏！\n");
			input = game();
			if (input == 0)
			{
				printf("游戏已经中断！\n");
			}
			break;
		case 0:
			printf("游戏已经退出！\n");
			break;
		default:
			printf("没有此选项，请重新选择！\n");
			break;
		}

	} while (input != 0);

}

int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}