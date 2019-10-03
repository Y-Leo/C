#include "mine.h"

void ShowMenu()
{
	printf("######### ¡¶É¨À×Ð¡ÓÎÏ·¡· ##########\n");
	printf("#################################\n");
	printf("########## 1. Play  #############\n");
	printf("########## 2. Exit  #############\n");
	printf("#################################\n");
	printf("Please Select: ");
}

int main()
{
	int quit = 0;
	int select = 0;
	while (!quit)
	{
		ShowMenu();
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Game();
			break;
		case 2:
			printf("Bye-Bye!\n");
			quit = 1;
			break;
		default:
			printf("Enter error,try again!\n");
			break;
		}
	}
	system("pause");
	return 0;
}