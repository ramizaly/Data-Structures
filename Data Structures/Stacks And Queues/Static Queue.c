#include <stdio.h>
#include <stdlib.h>

int queue[5];
int rear,rearcount = 0;
int front,frontcount = 0;

int enqueue()
{
    int val;
    printf("Enter The value that you want to enqueue\n");
    scanf("%d" , &val);

    if(rear==front && rearcount!=frontcount)
    {
        printf("\nQueue Full\n");

    }
    else
    {
        queue[rear++] = val;
        // rear++;
        rearcount++;
        
        if(rear==5)
        {
            rear = 0;
        }

        for (int i = 0; i < 5; i++)
        {
            printf("%d\t" , queue[i]);
        }
    }
}

int dequeue()
{
    int popped;

    if(rear==front && rearcount==frontcount)
    {
        printf("\nQueue Empty\n");
    }
    else
    {
        popped = queue[front++];
        queue[front] = 0;
        // front++;
        frontcount++;
        if (front == 5)
        {
            front = 0;
        }

        printf("\nThe value popped is %d\n" , popped);

        for (int i = 0; i < 5; i++)
        {
            printf("%d\t" , queue[i]);
        }
        
    }
}





int main()
{
    int choice;
    while(choice!=0)
    {
        printf("\nEnter\n 1.To Enqueue\n 2.To Dequeue\n 0.To Exit\n");
        scanf("%d" , &choice);

        if (choice == 1)
        {
            enqueue();
        }
        if(choice == 2)
        {
            dequeue();
        }
    }
}