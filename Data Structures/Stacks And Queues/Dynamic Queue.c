#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * rare = NULL;
struct node * front = NULL;

int Enqueue()
{
    printf("///Enqueue///\n");
    struct node * temp = (struct node*)malloc(sizeof(struct node));
    int num;
    printf("Enter the number that you want to add in your list\n");
    scanf("%d" , &num);

    temp->data = num;
    temp->next = NULL;

    if(rare==NULL)
    {
        rare = temp;
        front = temp;
    }
    else
    {
        rare->next = temp;
        rare = rare->next;
    }

    
}

int Dequeue()
{
    if (front == NULL)
    {
        printf("Empty Queue\n");

    }
    else
    {
        struct node * current = front;
        front = front->next;
        free(current);
    }
}

int print()
{
    struct node * current = front;
    while(current!=NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
    }
}

main()
{
    int choice;
    while(choice!=0)
    {
        printf("\nEnter \n1.Enqueue\n 2.Dequeue\n 3.print\n 0.Exit\n");
        scanf("%d" , &choice);
        printf("\n");

        if (choice == 1)
        {
            Enqueue();
        }
        if (choice == 2)
        {
            Dequeue();
        }
        if (choice==3)
        {
            print();
        }
    }
}