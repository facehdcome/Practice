#define _CRT_SECURE_NO_WARNINGS 1
//��������Ϸ
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

//�ع˲�������Ϸ
void menu()
{
	printf("\n*****��ӭ������������Ϸ(���ַ�ΧΪ1��10)*****\n");
	printf("********1��������Ϸ*********\n");
	printf("********0���˳���Ϸ*********\n");
	printf("****************************\n");
}
int  game(int c, int level, int times)
{
	int random_num = rand() % (10 - 1 + 1) + 1;
	int count = 1;
	printf("\n********�� %d ��*********\n", level);
	printf("\n���� %d �λ���,���� %d ��\n", c, count);
	while (count <= c)
	{
		int guess = 0;
		printf("���������µ�����:");
		scanf("%d", &guess);

		if (guess < random_num)
		{
			printf("\n��С��\n");
			count++;
			if (count - 1 != c)
				printf("\n���� %d �λ���,���� %d ��\n", c, count);

		}
		else if (guess > random_num)
		{
			printf("\n�´���\n");
			count++;
			if (count - 1 != c)
				printf("\n���� %d �λ���,���� %d ��\n", c, count);
		}
		if (count == c && guess != random_num)
		{
			printf("\n�Բ�����Ĵ��������ꡣ\n");
			return 0;
		}
		if (count <= c && guess == random_num)
		{
			printf("\n�¶��ˣ�\n\n");
			return 1;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int input = 0;                                  //���뿪ʼor������Ϸ
	int c = 10;                                      //�ܹ�������ʾ
	int level = 1;                                  //�ؿ���ʾ
	int times = 1;                                //���ô�����ʾ
	do {
		c = 10;
		level = 1;
		times = 1;
		menu();
		printf("��ѡ��");
		scanf("%d", &input);

		if (input == 1)                             //1 ѡ��ʼ��Ϸ
		{
			int ret = game(c, level, times);
			//return 1 ˵���Ѿ��¶� 6��ѭ��
			while (ret == 1 && c > 5)  //while (ret = 1&& c > 5)
			{
				c--;
				level++;
				times++;
				ret = game(c, level, times);
			}
			if (c == 5 && ret == 1)
				printf("��ϲͨ��!\n");
			else
			{
				printf("\n�����٣�������\n");
				printf("\nע�⣬�����ʼ�µ���Ϸ��\n");
				Sleep(5000);
				system("cls");
			}



		}

		else if (input == 0)
		{
			printf("��Ϸ���˳�\n");
			break;
		}
		else
			printf("����������������ȷѡ��\n");

	} while (input != 0);

	return 0;
}