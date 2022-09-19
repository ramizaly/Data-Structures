#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

struct node * start = NULL;
struct node * prev = NULL;
int flag = 0;

int insert()
{
    flag = 1;
    printf("///INSERTING///\n");
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    int num;
    printf("Enter the number that you want to add in your list\n");
    scanf("%d" , &num);

    temp->data = num;
    temp->next = NULL;
    temp->prev = NULL;

    if(start==NULL)
    {
        start = temp;
    }
    else
    {
        struct node * current = start;
        while(current->next != NULL )
        {
            current=current->next;
        }
        current->next = temp;
        temp->prev = current;
    }

}

int print()
{
    if(flag == 0)
    {
        printf("Please insert elements in your list first\n");
        main();
    }
    printf("///PRINTING///\n");
    struct node * current = start;
    while(current!=NULL)
    {
        printf("%d\n" , current->data);;
        current = current->next;

    }

    printf("\n");
}

int revprint()
{
    if(flag == 0)
    {
        printf("Please insert elements in your list first\n");
        main();
    }
    printf("///REVERSE PRINT///\n");
    struct node * current = start;
    while(current->next != NULL)
    {
        current = current->next;
    }

    while(current!=NULL)
    {
        printf("%d\n" , current->data);
        current = current->prev;
    }

    printf("\n");

}

int search()
{
    if (flag == 0)
    {
        printf("Please insert elements in your list\n");
        main();
    }

    printf("///SEARCHING///\n");
    int flag2 = 0;
    int tosearch;
    printf("Enter the number that you want to search\n");
    scanf("%d" , &tosearch);
    struct node * current = start;
    while(current!=NULL)
    {
        if(tosearch==current->data)
        {
            flag2 = 1;
            printf("Thw number that you wanted to search has been Found\n");
        }
        current = current->next;
    }
    if(flag2==0)
    {
        printf("The Number is not present in the list\n");
    }

}

int todelete()
{
    
    if(flag==0)
    {
        printf("Please insert elements in your list");
        main();
    }
    printf("///DELETING///\n");
    int flag3 = 0;

    int todel;
    printf("Enter the number that you want to delete\n");
    scanf("%d" , &todel);
    struct node * current = start;
    if(todel==current->data)
    {
        if(current->next==NULL)
        {
            flag = 0;
            free(start);
            start = NULL;
            flag3 = 1;
            printf("The Number has been deleted"); 
            main();
        }
        else
        {
            flag3 = 1;
            start = start->next;
            start->prev = NULL;
            free(current);
            printf("The Number has been deleted"); 
        }
    }

    else
    {
        while(current!=NULL)
        {
           if(todel == current->data)
           {
               if(current->next==NULL)
               {
                   flag3 = 1;
                   current->prev->next = current->next;
                   break;   
               }
               flag3 = 1;
               current->next->prev = current->prev;
               current->prev->next = current->next;
               free(current);
               printf("The Number has been deleted");
               break;
           }
           current = current->next;

        }
    }

    if(flag3 == 0)
    {
        printf("The Number is not present in the list\n");
    }

}

int main()
{
    int choice;
    printf("\n///DOUBLE LINKED LIST///\n");
    while(choice!=0)
    {
        printf("\n");
        printf("Enterr\n 1.To Insert\n 2.To Print\n 3.To Search\n 4.To Delete\n  5.Reverse Print\n 0.Exit\n Your choice : ");
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
        if (choice == 5)
        {
            revprint();
        }
    }
}