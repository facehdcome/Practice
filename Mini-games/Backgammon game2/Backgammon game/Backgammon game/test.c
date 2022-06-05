
#include "game.h"
//��ӡ�˵�
void menu()
{
	printf("\n**************************\n");
	printf("**** 1. Play   0.exit ****\n");
	printf("**************************\n");
}

//��ʼ��Ϸ
int  game()
{
	char ret = 0;//�ж���Ӯ�ı���
	//�����ά����
	char board[ROW][COL] = { 0 };
	//��һ���������ʼ������
	InitBoard(board, ROW, COL);
	//�ڶ�������ӡ����
	PrintBoard(board, ROW, COL);
	//������������

	//�������
	while (1)
	{
		int input = PlayerBoard(board, ROW, COL);
		if (input == 0)
		{
			return 0;
		}
		PrintBoard(board, ROW, COL);

		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//����������ӡһ������
		PrintBoard(board, ROW, COL);
		//��������
		ComputerBoard(board, ROW, COL);
		//ͬ����ӡ����
		PrintBoard(board, ROW, COL);

		//�ж���Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
		printf("ƽ�֣�\n");

}

void test()
{
	//���û�ѡ����Ϸ
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		int ch = 0;
		menu();
		printf("��ѡ��\n");
		if (scanf("%d", &input) != 1)
		{
			printf("��ʽ����������ѡ��!\n");
			while ((ch = getchar()) != '\n')
			{
				;
			}
			input = 3;//����ѭ��ѡ��
			continue;
		}

		switch (input)
		{
		case 1:
			printf("��ӭ������������Ϸ��\n");
			input = game();
			if (input == 0)
			{
				printf("��Ϸ�Ѿ��жϣ�\n");
			}
			break;
		case 0:
			printf("��Ϸ�Ѿ��˳���\n");
			break;
		default:
			printf("û�д�ѡ�������ѡ��\n");
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