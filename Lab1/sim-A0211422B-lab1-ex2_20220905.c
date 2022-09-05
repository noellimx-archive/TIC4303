#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};

void do_reverse(void)
{
	int i, c;

	struct Node *head;
	head = NULL;

	for (i = 0; (c = getchar()) != '\n'; i++)
	{

		struct Node *newNode;
		newNode = (struct Node *)malloc(sizeof(struct Node));
		newNode->data = c;
		newNode->next = head;
		head = newNode;
	}

	while (head != NULL)
	{
		struct Node *temp;
		putchar(head->data);
		temp = head;
		head = head->next;
		free(temp);
	}
	putchar('\n');
}
