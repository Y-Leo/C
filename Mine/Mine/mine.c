#include "mine.h"

int GetRandIndex(int start, int end)
{
	return rand() % (end - start + 1) + start;//��������ȡ������̶���ʽ
}

void SetMine(char mine[][COL], int row, int col)
{
	srand((unsigned long)time(NULL));//��һ�����������
	int count = 0;
	while (count < MINE_NUM)
	{
		int x = GetRandIndex(1, 10);//������������׺�����
		int y = GetRandIndex(1, 10);//������
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count++;
		}
	}
}

void ShowBoard(char board[][COL], int row, int col)  //չʾ����Ϸ���桱
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

void OpenMine(char mine[ROW][COL], char board[ROW][COL], int x, int y)  //չ��ѡ��������Χ�Ŀռ丽���������
{  //��������ʾ��û���׽���ʾ�Ըõ�Ϊ�������ھŹ�����Χ�˸������������
	int num = GetMines(mine, x - 1, y - 1);
	if (mine[x - 1][y - 1] == '0')
	{
		board[x - 1][y - 1] = num;  //����
	}
	if (mine[x - 1][y] == '0')
	{
		board[x - 1][y] = num;  //����
	}
	if (mine[x - 1][y + 1] == '0')
	{
		board[x - 1][y + 1] = num;  //����
	}
	if (mine[x][y - 1] == '0')
	{
		board[x][y - 1] = num;  //����
	}
	if (mine[x][y + 1] == '0')
	{
		board[x][y + 1] = num;  //����
	}
	if (mine[x + 1][y - 1] == '0')
	{
		board[x + 1][y - 1] = num;  //����
	}
	if (mine[x + 1][y] == '0')
	{
		board[x + 1][y] = num;  //����
	}
	if (mine[x + 1][y + 1] == '0')
	{
		board[x + 1][y + 1] = num;  //����
	}
}


void Game()
{
	char mine[ROW][COL];
	char board[ROW][COL];
	memset(mine, '0', sizeof(mine));//��������
	memset(board, '*', sizeof(board));//��ʾ��������

	SetMine(mine, ROW, COL);//����
	int count = TOTAL;
	int x = 0;
	int y = 0;
	while (1)
	{
		ShowBoard(board, ROW, COL);//��ӡ��ʾ����
		printf("Pleasee select pos<x,y>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW - 2 && y >= 1 && y <= ROW - 2)
		{
			if (mine[x][y] == '1' && count == TOTAL)  //�����һ�ξͲ���
			{
				mine[x][y] = '0';  //���õ���Ϊû����
				char num = GetMines(mine, ROW, COL);  //������Χ��������
				board[x][y] = num; 
				OpenMine(mine, board, x, y);  //չ����Χδ���׵�������������
				int set = 1;
				while (set)  //�������пյĵط�����һ����
				{
					int x = GetRandIndex(1, 10);
					int y = GetRandIndex(1, 10);
					if (mine[x][y] == '0')  //�Ҳ����׵ĵط�����
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

