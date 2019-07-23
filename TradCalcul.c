#include <stdio.h>
#include <windows.h>
#pragma warning (disable:4996)
 
int _add(int x, int y)
{
	return x + y;
}
 
int _sub(int x, int y)
{
	return x - y;
}
 
int _mul(int x, int y)
{
	return x * y;
}
 
int _div(int x, int y)
{
	if (!y)
	{
		printf("div  zero!\n");
		return -1;
	}
	return x / y;
}
 
int _mod(int x, int y)
{
	if (!y)
	{
		printf("mod  zero!\n");
		return -1;
	}
	return x % y;
}
 
void Showmemu()
{
	printf("########################################\n");
	printf("## 1、ADD        2、SUB       3、MUL  ##\n");
	printf("## 4、DIV        5、MOD       0、EXIT ##\n");
	printf("########################################\n");
	printf("Please Select :");
}
 
int main()
{
	int x, y;
	int input = 1;
	int result = 0;
	
	while (input)
	{
		Showmemu();
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("Exit!\n");
			system("pause");
			return 0;
		case 1:
			printf("Enter <x,y> :");
			scanf("%d %d", &x, &y);
			result = _add(x, y);
			break;
		case 2:
			printf("Enter <x,y> :");
			scanf("%d %d", &x, &y);
			result = _sub(x, y);
			break;
		case 3:
			printf("Enter <x,y> :");
			scanf("%d %d", &x, &y);
			result = _mul(x, y);
			break;
		case 4:
			printf("Enter <x,y> :");
			scanf("%d %d", &x, &y);
			result = _div(x, y);
			break;
		case 5:
			printf("Enter <x,y> :");
			scanf("%d %d", &x, &y);
			result = _mod(x, y);
			break;
		default:
			printf("Enter eror !\n");
			break;
		}
		system("cls");//清屏操作
		if (result == -1){
			printf("mod or div zero!\n");
			continue;
		}
		printf("result = %d\n", result);
	}
	system("pause");
	return 0;
}

