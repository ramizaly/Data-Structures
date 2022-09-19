#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #define Size 10

struct priority
{
    int priority;
    char task;
};
int Size = 7;
struct priority* arr[7];
int index=0;

void insert()
{
    while(index<Size)
    {
     struct priority * temp = (struct priority*)malloc(sizeof(struct priority));
     int priorityy;
     char task;
    printf("\n");
    printf("Enter the element you want in your heap\n");
    scanf("%d" , &priorityy);
    printf("Enter the Task Name(one alphabet only)\n");
    scanf("%C",&task);
    // gets(task);
    
    temp->priority = priorityy;
    // temp->task = task;
    if(index!=Size)
    {
        arr[index++] = temp;
        int lastUpdated = (arr[index-1])->priority;
        struct priority* lastUpdatedd = (arr[index-1]);
        int i = index-1;
        while(lastUpdated>((arr[(int) floor((i-1)/2)])->priority))
        {
            struct priority* swap = arr[ (int) floor((i-1)/2)];
            arr[i] = swap;
            // arr[ (int) floor((i-1)/2)]->priority = lastUpdated;
            arr[ (int) floor((i-1)/2)] = lastUpdatedd;
            i = floor((i-1)/2);

        }
    }
    else
    {
        printf("Array Full");
    }

    for (int i = 0; i < Size; i++)
    {
        if(arr[i] != NULL){
        printf("%d\t" , arr[i]->priority);
        }
    }
    }
    
}

struct priority** heapify(struct priority* arr[Size], int src)
{
    int flag=0;
    int childRight = (2*src)+2;
    int childLeft = (2*src) +1;
    while(src<Size)
    {
        struct priority* swap = NULL;
        if(childLeft<Size && arr[src]->priority < arr[childLeft]->priority )
        {
            swap = arr[src];
            arr[src] = arr[childLeft];
            arr[childLeft] = swap;
            // src = childLeft;
            if(childRight<Size && arr[src]->priority < arr[childRight]->priority)
            {
                flag = 1;
                swap = arr[src];
                arr[src] = arr[childRight];
                arr[childRight] = swap;
                src = childRight;
            }
            if(flag == 0)
            {
            src = childLeft;}
        }
        else if(childRight<Size && arr[src]->priority < arr[childRight]->priority)
        {
                swap = arr[src];
                arr[src] = arr[childRight];
                arr[childRight] = swap;
                src = childRight;
        }
        else 
        {
            src = childLeft;
        }
        
        childRight = (2*src)+2;
        childLeft = (2*src) +1;
    }
    return arr;
}
void delete()
{
  
    
    int todel;
    printf("Enter the element that you want to delete\n");
    scanf("%d" , &todel);
    for (int i = 0; i < Size; i++)
    {
        if(arr[i]->priority == todel)
        {
            if(i==Size-1)
            {
                Size = Size-1;
                printf("The task is %c and it's priotiy is %d " , arr[i]->task , arr[i]->priority);
                break;
            }
            struct priorty* swap = arr[i];
            arr[i] = arr[Size-1];
            Size = Size - 1;
             printf("The task is %c and it's priotiy is %d " , arr[i]->task , arr[i]->priority);
            heapify(arr , i);
            break;
        }
    }
    
    

}

int main(int argc, char const *argv[])
{

      for (int i = 0; i < Size; i++)
    {
        arr[i] = NULL;
    }
    
    int choice=10;
    while(choice!=0)
    {
        printf("Enter \n1.To Add a task \n2.To get the most important task \n0.To Exit\n");
        scanf("%d" , &choice);
        if(choice == 1)
        {
            insert();
        }
        if(choice == 2)
        {
            delete();
        }
    }
}
