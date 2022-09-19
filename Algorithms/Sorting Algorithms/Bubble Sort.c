#include <stdio.h>

int main()
{
    printf("////BUBBLE SORT////\n");
    int n ,choice, temp;
    printf("Enterr the number of elements that you want in your array\n");
    scanf("%d" , &n);

    int array[n];
    for(int i = 0; i<n; i++)
    {
        printf("Enter the element number %d\n" , i);
        scanf("%d" , &array[i]);
    }

    printf("////ASCENDING OR DESCENDING////\n\n");
    printf("Enter 1 for ascending order and enter 0 for descending order\n");
    scanf("%d" , &choice);

     for(int j = 0; j<n-1; j++)
     {
         for(int l = 0; l<n-1; l++)
         {
            int next = l+1;
             if (array[l]>array[next] && choice == 1)
             {
                 temp = array[l];
                 array[l] = array[next];
                 array[next] = temp;
             }

             if (array[l]<array[next] && choice == 0)
             {
                 temp = array[l];
                 array[l] = array[next];
                 array[next] = temp;
             }
            
         }
     }
    printf("////THE SORTED ARRAY IS////\n\n");
    for(int k = 0; k<n; k++)
    {
        printf("%d\n" , array[k]);
    }
    
}