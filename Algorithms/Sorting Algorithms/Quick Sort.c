#include <stdio.h>
#include <stdlib.h>
int size = 10;
int arr[10];
int quicksort(L,R)
{
    int pi = setpivot(L,R);
    if(L<R)
    {
        quicksort(L,pi-1);
        quicksort(pi+1,R);
    }
}

int setpivot(L,R)
{
    int pivindex = (L+R)/2;
    int piv = arr[pivindex];
    while(L<=R)
    {
        for(int i = R; R>pivindex;)
        {
            if(piv>=arr[R])
            {
                int temp = arr[R];
                arr[pivindex] = temp;
                arr[R] = piv; 
                pivindex = R;
                R = R-1;
                break;
            }
            else
            {
                if(R>=pivindex)
                {
                    R=R-1;
                }
            }
        }
        for(int j = L; L<=pivindex;)
        {
            if(piv<arr[L])
            {
                int temp = arr[L];
                arr[pivindex] = temp;
                arr[L] = piv;
                pivindex = L;
                L++;
                break;
            }
            else
            {
                if(L<=pivindex)
                {
                    L++;
                }
            }
        }  
    }
    return pivindex; 

}

void printarray()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n" , arr[i]);
    }
    
}

int main()
{
   
    for (int i = 0; i < size; i++)
    {
        printf("Enter The element\n");
        scanf("%d" , &arr[i]);
    }
    int left = 0;
    int right = size-1;
    printf("\n////Unsorted Array////\n");
    printarray();
    quicksort(left,right);
    printf("\n////Sorted Array////\n");
    printarray();

    

    
}