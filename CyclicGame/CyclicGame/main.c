#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

typedef int Cyclic;

typedef struct LinkNode
{
	Cyclic data;
	struct LinkNode *next;
}LinkNode, *LinkList;

LinkNode *Creat(LinkList *L, int n)
{
	LinkList r, p;
	(*L) = (LinkNode*)malloc(sizeof(LinkNode));
	r = *L;
	int i;
	for (i = 1; i<n + 1; i++)
	{
		p = (LinkNode*)malloc(sizeof(LinkNode));
		p->data = i;
		r->next = p;
		r = p;
	}
	r->next = (*L)->next;
	free(*L);
	return r->next;
}

int main()
{
	int n = 10;
	int k = 3;
	int m;

	LinkList L, temp, p;
	p = Creat(&L, n);
	while (p != p->next)
	{
		for (m = 1; m<k - 1; m++)
		{
			p = p->next;
		}
		printf("%d->", p->next->data);
		temp = p->next;
		p->next = temp->next;
		free(temp);
		p = p->next;

	}
	printf("%d\n", p->next->data);

	system("pause");
	return 0;
}

