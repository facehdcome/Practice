
#include "game.h"
/*\
* ������Ϸ��״̬
* ���Ӯ ��*��
* ����Ӯ ��#��
* ƽ��      ��Q��
* ����     ��C]��
*/
//��ʼ����������ʵ�֣���ʼ��Ϊ�ո�
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
		printf("\n");
	}
}

//��ӡ���̣�û�����������
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");

		for (j = 0; j < col; j++)
		{
			if (i < row - 1)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//������壨û�����������
int PlayerBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("�����-��ѡ������λ��:\n");
		scanf("%d %d", &x, &y);
		//�����Ǹ��ӵģ���Щ�˻��֣���ϸ�ж����
		//һ�����겻��
		if (x < 1 && x >row && y < 1 && y >col)
		{
			printf("û�д����꣬����������\n");
		}
		//λ��Ϊ��
		else if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else if (x == 0 || y == 0)
		{
			return 0;
		}
		else
		{
			printf("��λ���Ѿ���ռ�ã��������£�\n");
		}

	}
}

//��������
void ComputerBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�\n");

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


//�ж���Ӯ
/** ������Ϸ��״̬
* ���Ӯ ��*��
* ����Ӯ ��#��
* ƽ��      ��Q��
* ����     ��C]��*/
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//������
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//������
	for (j = 0; j < col; j++)
	{
		if (board[j][0] == board[j][1] && board[j][1] == board[j][2] && board[j][1] != ' ')
		{
			return board[j][1];
		}
	}

	//��б��
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//��б��
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}
