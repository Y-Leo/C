#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

#define ROW 4
#define COL 4

int	Findnum(int arr[ROW][COL], int row, int col, int key)
{
	int left = 0;
	int right = COL - 1;
	while ((left >= 0&&left<ROW) && (right>=0&&right < COL))
	{
		if (arr[left][right] < key)
		{
			left++;
		}
		if (arr[left][right] > key)
		{
			right--;
		}
		if (arr[left][right] == key)
		{
			printf("Find it!   ...and it is array[%d][%d]...\n",left,right);
			return 0;
		}
	}
	printf("Do not find it!\n");
}
void main()
{
int array[ROW][COL] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	printf("Please enter a number which you want to search:");
	int key = 0;
	scanf("%d", &key);
	Findnum(array, ROW, COL, key);
	system("pause");
	return 0;
}
