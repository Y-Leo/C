#include <stdio.h>
#include <windows.h>
#pragma warning (disable :4996)

int DigitSum1(int n)//迭代，非递归
{
	int a = 0;
	int sum = 0;
	while (n != 0)
	{
		a = n % 10;
		n = n / 10;
		sum += a;
	}
	return sum;
}

/*
int DigitSum2(int n)
{
	if (n < 10)
	{
		return n;
	}
	return n % 10 + DigitSum2(n / 10);
}
*/
int main()
{
	int n = 0;
	int sum = 0;
	printf("请输入一个正整数n: ");
	scanf("%d", &n);
	sum = DigitSum1(n);
	printf("结果为：%d\n", sum);
	system("pause");
	return 0;
}