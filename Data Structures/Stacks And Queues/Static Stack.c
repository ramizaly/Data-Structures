#include <stdio.h>
#include <stdlib.h>



int arr[5];
int top = -1;


int push()
{
    if(top==4)
    {
        printf("OverFlowed\n");
    }
    while(top<4)
    {
        
            int val;
            printf("Enter A value that you want to print\n");
            scanf("%d" , &val);
            printf("\n");
            top++;
            arr[top] = val;

            for (int j = 0; j < 5; j++)
            {
                printf("%d\t\t" , arr[j]);
        
            }
            break;
        
        
    }
   
}

int pop()
{
    if(top==-1)
    {
        printf("UnderFlow\n");
    }
    else
    {
        int f = arr[top];
        printf("The Value popped is %d\n", arr[top]);
        arr[top] = 0;
        top--;
        for (int j = 0; j < 5; j++)
            {
                printf("%d\t\t" , arr[j]);
        
            }
            
    }
}


int main()
{
    

    int choice = 7;
    while(choice!=0)
    {
        printf("\nEnter\n 1.Push\n 2.Pop\n 3.Exit\n");
        printf("\n");
        scanf("%d" , &choice);
        if(choice == 1)
        {
            push();
        }
        if (choice == 2)
        {
            pop();
        }

    }
    
}