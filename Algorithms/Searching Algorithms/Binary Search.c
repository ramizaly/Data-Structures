#include <stdio.h>


int binarysearch(int array[], int l , int r , int x)
{
    

    int mid = (r+l)/2;
    if(l>r)
    {
        return -1;
    }
    if(array[mid] == x)
    {
    return mid;
    }

    if(array[mid]>x)
    {
        return binarysearch(array,  l , mid-1 , x);
    }
        
    if(array[mid]<x)
    {
        return binarysearch(array,  mid+1 , r , x);
    }
        

}

int binarysearch(int array[], int l , int r , int x);

int main()
{
    printf("////RECURSIVEE BINARY SEARCH////\n");
    int n;
    printf("Enterr the number of elements that you want in your array\n");
    scanf("%d" , &n);
    
    int arr[n];
    for(int i = 0; i<n; i++)
    {
        printf("Enter the element number %d\n" , i);
        scanf("%d" , &arr[i]);
    }
    int tosearch;
    printf("ENTER THE NUMBER THAT YOU WANT TO SEARCH\n");
    scanf("%d" , &tosearch);

    int result = binarysearch(arr , 0 , n-1 , tosearch);

    
    if(result == -1)
    {
        printf("Number not found");
    }
    else{
        printf("Number found at index %d" , result);
    }
    



}
