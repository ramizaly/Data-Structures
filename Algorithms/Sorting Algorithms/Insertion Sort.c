#include <stdio.h>

int main()
{
    printf("////INSERTION SORT////\n");
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

    for(int j=0; j<n-1; j++)
    {
        int key = j+1;
        for (int k = key-1; k>=0 ;k--)
        {
            if(array[k]>array[key] && choice == 1)
            {
                int temp = array[k];
                array[k] = array[key];
                array[key] = temp;
                key = k;
            }
             if(array[k]<array[key] && choice == 0)
            {
                int temp = array[k];
                array[k] = array[key];
                array[key] = temp;
                key = k;
            }
        }
    }
    printf("////THE SORTED ARRAY IS////\n\n");
    for(int l = 0; l<n; l++)
    {
        printf("%d\n" , array[l]);
    }
}