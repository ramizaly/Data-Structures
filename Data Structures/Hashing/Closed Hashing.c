#include <stdio.h>
#include <stdlib.h>
int size = 10;
int arr[10];
int flag0 = 0;

int inputArr()
{
    flag0 = 1;
    for (int i = 0; i < size; i++)
    {
        //This loop is for to keep asking values
        int num;
        int mod;
        printf("Enter The element at index number of your array\n");
        scanf("%d" , &num);
        mod = num % size;

      for (int j = 0; j<size; j++)
      {
          //Every time you enter a value this loop will search for the right position
        if(arr[mod] == 0)
        {
            arr[mod] = num;
            break;
        }
        mod = mod + 1;
        if(mod == size)
        {
            mod = 0;
        }
      }
      

    }
}
int printarray()
{
    if(flag0 == 0)
    {
        printf("No elements inserted\n");

    }
    for (int i = 0; i < size; i++)
    {
        printf("%d\n" , arr[i]);
    }
    
}

int main()
{
    
    int choice;
    while(choice!=0)
    {
        printf("Enter\n 1.Input array\n 2.Print array\n 0.Exit\n");
        scanf("%d" , &choice);
        if (choice == 1)
        {
            inputArr();
        }
        if(choice == 2)
        {
            printarray();
        }
    }


}