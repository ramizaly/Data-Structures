#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * top = NULL;
struct node * start = NULL;

void push()
{
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    int num;
    printf("Enter the number that you want to add in your list\n");
    scanf("%d" , &num);

    temp->data = num;
    temp->next = NULL;

    if(top == NULL)
    {
        top = temp;
        start = temp;
    }
    else
    {
        top->next = temp;
        top = top->next;
    }
}

void pop()
{
    if(top == NULL)
    {
        printf("List Empty\n");
    }
    else if(start->next == NULL)
    {
        free(start);
        free(top);
        start = NULL;
        top = NULL;
    

    }
    else
    {
        struct node * previous = start;
        struct node * current = top;
        while(previous->next != top)
        {
            previous = previous->next;
        }
        free(current);
        top = previous;
        top->next = NULL;
    }
}

void print()
{
    struct node * current = start;
    while(current!=NULL)
    {
        printf("%d\n" , current->data);
        current = current->next;
    }
    main();
}

void main()
{
    
    int choice;
    while(choice!=0)
    {
        printf("\nEnter \n1.Push\n 2.Pop\n 3.print\n 0.Exit\n");
        scanf("%d" , &choice);
        printf("\n");

        if (choice == 1)
        {
            push();
        }
        if (choice == 2)
        {
            pop();
        }
        if (choice==3)
        {
            print();
        }
    }
}