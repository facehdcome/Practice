
#include "game.h"
void menu()
{
	printf("\n**************************\n");
	printf("**** 1. Play   0.exit ****\n");
	printf("**************************\n");
}

//开始游戏
void  game()
{
	//1.雷的信息存储
	char mine[ROWS][COLS] = { 0 };
	//2.排查出雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	/*DisplayBoard(mine, ROW, COL);*/

	//找雷
	FindMine(mine, show, ROW, COL);
}

void test()
{
	//让用户选择游戏
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("欢迎来到三子棋游戏！\n");
			game();
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