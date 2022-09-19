#include <stdio.h>
#include <stdlib.h>


/*/ run this program using the console pauser or add your own getch, system("pause") or input loop */

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
	temp -> next = start;
	
	if(start == NULL)
	{
		start = temp;
		temp -> next = start;
	}
	
	else
	{
		struct node * current = start;
		while(current->next != start)
		{
			current = current -> next;
		}
		current -> next = temp;
		temp-> next= start;

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
	struct node * thisnode = start;


    printf("%d\n" , cuurent);   
	do
	{
		printf("%d\n" , cuurent->data);
        printf("The address is %d\n" , cuurent->next);
        cuurent = cuurent -> next;
	}while(cuurent!=thisnode);
    
	
	printf("\n");
}

int todelete()
{
	int todel;
	int flag=0;
	printf("Enter the data that you want to delete");
	scanf("%d" , &todel);
	struct node * curr = start;
	struct node * prev = start;
	struct node * thisnode = start;

    if(start->next == start)
    {
        if (todel == start->data)
        {
            free(start);
            start = NULL;
            flag = 1;
            flag2 = 0;
            main();
            
        }
        
    }
	if(todel == start ->data)
	{
		start = start->next;
        curr = curr->next;
        while(curr->next!=prev)
        {
            curr = curr->next;
        }
        curr->next = start;
		free(prev);
		flag=1;
		printf("The Number has been Deleted\n");
	}
	else
	{
		curr =start->next;
		prev = start;
		while(curr != thisnode)
		{
			if(todel == curr->data)
			{
				prev->next = curr->next;
				free(curr);
				flag = 1;
				printf("The Number has been Deleted\n");
				break;
			}
		
			prev = prev-> next;
			curr = curr-> next;
		}
	}
	if(flag==0)
	{
		printf("The Number that you want to delete is not present\n");
	}
	
}


int search()
{
    if(flag2==0)
    {
        printf("Please insert the elements in your list");
        main();
    }
    int flag = 0;

    printf("///SEARCHING///\n");
    int tosearch;
    printf("Enter the number that you want to search\n");
    scanf("%d" ,&tosearch);

    struct node * cuurent = start;
    struct node * thisnode = start;

    do
    {
        if(cuurent->data == tosearch)
        {
            printf("The number is present");
            flag = 1;
            break;
        }
        cuurent = cuurent->next;
    }while(cuurent!=thisnode);
    
    if(flag==0)
    {
        printf("The Number has not been found");
    }
}
int main() {
	int choice = 6;
	
	while(choice != 0){
		printf("\n");
		printf("Enterr\n 1.To Insert\n 2.To Print\n 3.To Search\n 4.To Delete\n  0.Exit\n Your choice : ");
		scanf("%d" , &choice);

		
		if (choice == 1)
		{
			insert();
		}
		if (choice == 2)
		{
			print();
		}
        if (choice == 3)
        {
            search();
        }
        if (choice == 4)
        {
            todelete();
        }
	}
}