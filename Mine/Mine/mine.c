#include "mine.h"

int GetRandIndex(int start, int end)
{
	return rand() % (end - start + 1) + start;//按照区间取随机数固定公式
}

void SetMine(char mine[][COL], int row, int col)
{
	srand((unsigned long)time(NULL));//种一个随机数种子
	int count = 0;
	while (count < MINE_NUM)
	{
		int x = GetRandIndex(1, 10);//随机数生成埋雷横坐标
		int y = GetRandIndex(1, 10);//纵坐标
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}

void ShowBoard(char board[][COL], int row, int col)  //展示“游戏界面”
	{
		printf("|---|----|----|----|----|----|----|----|----|----|----|\n");
		printf("| 0");
		int i;
		for (i = 1; i <= 10; i++){
			printf(" | %d ", i);
		}
		printf("|\n");
		printf("|---|");
		for (i = 1; i <= 10; i++){
			printf("----|");
		}
		printf("\n");
		for (i = 1; i <= 10; i++){
			if (10 == i)
			{
				printf("|%d", i);
			}
			else{
				printf("| %d", i);
			}
			int j;
			for (j = 1; j <= 10; j++){
				if (10 == j)
				{
					printf(" | %c", board[i][j]);
				}
				else{
					printf(" | %c ", board[i][j]);
				}
			}
			printf("  |\n----|");
			int k;
			for (k = 1; k <= 10; k++){
				if (10 == k)
				{
					printf("----");
				}
				else{
					printf("----|");
				}
			}
			printf("|\n");
		}
}

char GetMines(char mine[][COL], int row, int col)
{
	return mine[row - 1][col - 1] + mine[row - 1][col] + mine[row - 1][col + 1] + mine[row][col - 1] + mine[row][col + 1] + \
		mine[row + 1][col - 1] + mine[row + 1][col] + mine[row + 1][col + 1] - 7 * '0';
}

void OpenMine(char mine[ROW][COL], char board[ROW][COL], int x, int y)  //展开选中坐标周围的空间附近埋雷情况
{  //有雷则不显示，没有雷将显示以该点为中心所在九宫格外围八个点的埋雷总数
	int num = GetMines(mine, x - 1, y - 1);
	if (mine[x - 1][y - 1] == '0')
	{
		board[x - 1][y - 1] = num;  //左上
	}
	if (mine[x - 1][y] == '0')
	{
		board[x - 1][y] = num;  //正上
	}
	if (mine[x - 1][y + 1] == '0')
	{
		board[x - 1][y + 1] = num;  //右上
	}
	if (mine[x][y - 1] == '0')
	{
		board[x][y - 1] = num;  //正左
	}
	if (mine[x][y + 1] == '0')
	{
		board[x][y + 1] = num;  //正右
	}
	if (mine[x + 1][y - 1] == '0')
	{
		board[x + 1][y - 1] = num;  //左下
	}
	if (mine[x + 1][y] == '0')
	{
		board[x + 1][y] = num;  //正下
	}
	if (mine[x + 1][y + 1] == '0')
	{
		board[x + 1][y + 1] = num;  //右下
	}
}


void Game()
{
	char mine[ROW][COL];
	char board[ROW][COL];
	memset(mine, '0', sizeof(mine));//埋雷数组
	memset(board, '*', sizeof(board));//显示雷盘数组

	SetMine(mine, ROW, COL);//埋雷
	int count = TOTAL;
	int x = 0;
	int y = 0;
	while (1)
	{
		ShowBoard(board, ROW, COL);//打印显示雷盘
		printf("Pleasee select pos<x,y>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW - 2 && y >= 1 && y <= ROW - 2)
		{
			if (mine[x][y] == '1' && count == TOTAL)  //如果第一次就踩雷
			{
				mine[x][y] = '0';  //将该点置为没有雷
				char num = GetMines(mine, ROW, COL);  //计算周围埋雷总数
				board[x][y] = num; 
				OpenMine(mine, board, x, y);  //展开周围未埋雷的坐标的埋雷情况
				int set = 1;
				while (set)  //在其余有空的地方设置一个雷
				{
					int x = GetRandIndex(1, 10);
					int y = GetRandIndex(1, 10);
					if (mine[x][y] == '0')  //找不是雷的地方布雷
					{
						mine[x][y] = '1';
						set = 0;
						break;
					}
				}
				break;
			}
			if (mine[x][y] == '0')
			{
				char num = GetMines(mine, x, y);
				board[x][y] = num;
				OpenMine(mine, board, x, y);
				count--;
				if (count <= 20)
				{
					printf("You win!\n");
					break;
				}
			}
			else{
				printf("Sorry,you are blown up!\n");
				Sleep(2000);
				ShowBoard(mine, ROW, COL);
				system(2000);
				system("cls");
				break;
			}
		}
		else{
			printf("Enter error,try again!\n");
		}
	}
}

