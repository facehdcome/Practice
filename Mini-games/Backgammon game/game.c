#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//��������Ϊ�ո�
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ������ķָ���
	for (j = 0; j < col; j++)
	{
		
			if (j < col - 1)
				printf("----");
			else
				printf("-----");
	}
	printf("\n");

	//��ӡһ�е�����
	for (i = 0; i < row; i++)
	{
		//��ӡ���е�����
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf("|");
			printf(" %c ", board[i][j]);
		}
		printf("|");
		printf("\n");

		//��ӡ���еķָ���
		if (i < row - 1)
		{
			for (j = 0; j < col;j++)
			{
				printf("|");
				printf("---");
			}
			printf("|");
			printf("\n");
		}
		
	}
	//��ӡ������ָ���
	for (j = 0; j < col; j++)
	{
		if (j < col - 1)
			printf("----");
		else
			printf("-----");
	}
	printf("\n");
}


//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����\n");
	while (1)
	{
		printf("������Ҫ�µ�����:\n");
		scanf("%d %d", &x, &y);

		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//�ж����̵������Ƿ�ռλ
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("�����걻ռ��!\n");
		}
		else
			printf("����Ƿ�������������:\n");
	}
}

//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������:\n");


	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//û��
			}
		}
	}
	return 1;
}


//�ж�˭Ӯ
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//������
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//�����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];

	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}