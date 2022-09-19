#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct node
{
	int data;
	struct node * next;
};

struct node * start = NULL;
int flag2 = 0;

int insert()
{
	printf("\n\n ///INSERTING/// \n\n");
	flag2 =1;
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	int n;
	printf("Enter the number that you want in your list\n");
	scanf("%d" , &n);
	temp -> data = n;
	temp -> next = NULL;
	
	if(start == NULL) 
	{
		start = temp;
	}
	
	else 
	{
		struct node * current = start;
		while(current->next != NULL)
		{
			current = current -> next;
		}
		current -> next = temp;
	}
	
	
}

int print()
{
	if(flag2 == 0)
	{
		printf("Please insert elements in your linked list\n");
		main();
	}
	printf("\n\n ///PRINTING/// \n\n");
	struct node * cuurent = start;
	// printf("%d\n" , cuurent->data);
	while(cuurent != NULL)
	{
		
		printf("%d\n" , cuurent->data);
		cuurent = cuurent -> next;
	}
	printf("\n");
}

int search()
{   
	if(flag2 == 0)
	{
		printf("Please insert elements in your linked list\n");
		main();
	}

	printf("\n\n ///SEARCHING/// \n\n");
	
	int tosearch;
	printf("Enter the number that you want to search\n");
	scanf("%d" , &tosearch);
	int flag = 0;
	struct node * current = start;

	while(current != NULL)
	{
		
		if(current->data == tosearch)
		{
			printf("The number %d has been found\n" , current->data);
			flag = 1;
		}
		current = current->next;
	}
	if(flag==0)
	{
		printf("The number was not present\n");
	}
}



int main() {
	int choice = 6;
	
	while(choice != 0){
		printf("\n");
		printf("Enter\n 1.To Insert\n 2.To Print\n 3.To Search\n  0.Exit\n Your choice : ");
		scanf("%d" , &choice);

		
		if (choice == 1)
		{
			insert();
		}
		if  (choice == 2)
		{
			printf("\n");
			print();
		}
		if (choice == 3)
		{
			search();
		}
		
	}
}