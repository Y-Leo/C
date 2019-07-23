#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//递归
int Fib1(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return Fib1(n - 1) + Fib1(n - 2);
}

//非递归
int Fib2(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	int i = 0;
	for (i=2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
void main()
{
printf("Please enter a number:");
	int ret = 0;
	scanf("%d", &ret);
	int res1=Fib1(ret);
	int res2=Fib2(ret);
	printf("The result of Fib1=%d...\nThe result of Fib2=%d...\n", res1,res2);
	system("pause");
	return 0;
}
