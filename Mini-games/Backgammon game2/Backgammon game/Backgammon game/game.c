
#include "game.h"
/*\
* 四种游戏的状态
* 玩家赢 ‘*’
* 电脑赢 ‘#’
* 平局      ‘Q’
* 继续     ‘C]’
*/
//初始化棋盘任务实现（初始化为空格）
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

//打印棋盘（没有完整打出）
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

//玩家下棋（没有完整打出）
int PlayerBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家走-请选择坐标位置:\n");
		scanf("%d %d", &x, &y);
		//人类是复杂的，有些人会搞怪，仔细判断情况
		//一：坐标不对
		if (x < 1 && x >row && y < 1 && y >col)
		{
			printf("没有此坐标，请重新下棋\n");
		}
		//位置为空
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
			printf("此位置已经被占用，请重新下：\n");
		}

	}
}

//电脑下棋
void ComputerBoard(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑走！\n");

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


//判断输赢
/** 四种游戏的状态
* 玩家赢 ‘*’
* 电脑赢 ‘#’
* 平局      ‘Q’
* 继续     ‘C]’*/
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
	//竖三列
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}

	//横三行
	for (j = 0; j < col; j++)
	{
		if (board[j][0] == board[j][1] && board[j][1] == board[j][2] && board[j][1] != ' ')
		{
			return board[j][1];
		}
	}

	//左斜角
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//右斜角
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
