#include <stdio.h>
#include <windows.h>
#include <string.h>

int compare(char str1[], char str2[])
{
	int i = 0;
	int j = 0;
	int length = strlen(str1);
	for (j = 1; j <= length; j++)
	{
			int tmp = str1[0];
			for (i = 0; i < length - 1; i++)
			{
				str1[i] = str1[i + 1];
			}
			str1[length - 1] = tmp;
		if (0 == strcmp(str1, str2))
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	char s1[10] = "ABCDEFGH";
	char s2[10] = "EFGHABCD";
	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	if (1 == compare(s1,s2))
	{
		printf("s1为s2旋转后的字符串!\n");
	}
	else
	{
		printf("s1不是s2旋转后的字符串!\n");
	}
	system("pause");
	return 0;
}

