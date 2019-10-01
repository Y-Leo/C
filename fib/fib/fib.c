#include <stdio.h>
#pragma warning (disable : 4996)
#include <windows.h>

int fib1(int n)//递归
{
	if (n <= 2)
	{
		return 1;
	}
	return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n)//迭代，非递归
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

int main()
{
	int n = 0;
	printf("请输入要查询的数:");
	scanf("%d", &n);
	int num = fib2(n);
	printf("结果是：%d\n",num);
	system("pause");
	return 0;
}