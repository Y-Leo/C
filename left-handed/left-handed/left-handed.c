#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int left_handed(char a[], int len)
{
	int i = 0;
	int n = 0;
	printf("Enter a number (number<=6) :");
	scanf("%d",&n);
	for (i; i < len-n; i++)
	{
		printf("%c", a[n+i]);	
	}
	for (i = 0; i < n; i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");

}

void main()
{
	char arr[6] = "ABCDEF";
	int len = sizeof(arr) / sizeof(arr[0]);
	left_handed(arr, len);
	system("pause");
	return 0;
}