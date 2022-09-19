#include <stdio.h>

int main()
{
    printf("////SELECTION SORT////\n");
    int n ,choice, temp, sindex;
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
        sindex = j;
        for(int l = j+1 ; l<n ; l++)
        {
            if(array[sindex]> array[l] && choice ==1)
            {
                sindex=l;
            }
            if(array[sindex]< array[l] && choice ==0)
            {
                sindex=l;
            }
            
        }
        temp = array[j];
        array[j] = array[sindex];
        array[sindex] = temp;
    }
    printf("////THE SORTED ARRAY IS////\n\n");
    for(int k = 0; k<n; k++)
    {
        printf("%d\n" , array[k]);
    }
    
}