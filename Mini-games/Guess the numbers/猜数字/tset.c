#define _CRT_SECURE_NO_WARNINGS 1
//猜数字游戏
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

//回顾猜数字游戏
void menu()
{
	printf("\n*****欢迎来到猜数字游戏(数字范围为1到10)*****\n");
	printf("********1：进入游戏*********\n");
	printf("********0：退出游戏*********\n");
	printf("****************************\n");
}
int  game(int c, int level, int times)
{
	int random_num = rand() % (10 - 1 + 1) + 1;
	int count = 1;
	printf("\n********第 %d 关*********\n", level);
	printf("\n你有 %d 次机会,已用 %d 次\n", c, count);
	while (count <= c)
	{
		int guess = 0;
		printf("请输入您猜的数字:");
		scanf("%d", &guess);

		if (guess < random_num)
		{
			printf("\n猜小了\n");
			count++;
			if (count - 1 != c)
				printf("\n你有 %d 次机会,已用 %d 次\n", c, count);

		}
		else if (guess > random_num)
		{
			printf("\n猜大了\n");
			count++;
			if (count - 1 != c)
				printf("\n你有 %d 次机会,已用 %d 次\n", c, count);
		}
		if (count == c && guess != random_num)
		{
			printf("\n对不起，你的次数已用完。\n");
			return 0;
		}
		if (count <= c && guess == random_num)
		{
			printf("\n猜对了！\n\n");
			return 1;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;                                  //输入开始or结束游戏
	int c = 10;                                      //总共次数显示
	int level = 1;                                  //关卡显示
	int times = 1;                                //已用次数显示
	do {
		c = 10;
		level = 1;
		times = 1;
		menu();
		printf("请选择：");
		scanf("%d", &input);

		if (input == 1)                             //1 选择开始游戏
		{
			int ret = game(c, level, times);
			//return 1 说明已经猜对 6次循环
			while (ret == 1 && c > 5)  //while (ret = 1&& c > 5)
			{
				c--;
				level++;
				times++;
				ret = game(c, level, times);
			}
			if (c == 5 && ret == 1)
				printf("恭喜通关!\n");
			else
			{
				printf("\n别气馁，再来！\n");
				printf("\n注意，五秒候开始新的游戏。\n");
				Sleep(5000);
				system("cls");
			}



		}

		else if (input == 0)
		{
			printf("游戏已退出\n");
			break;
		}
		else
			printf("输入有误，请输入正确选项\n");

	} while (input != 0);

	return 0;
}