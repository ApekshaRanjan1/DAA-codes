#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nEnter value: ");
        scanf("%d", &array[i]);
    }

    printf("\n\nEntered elements in array are: ");
    for(i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }

    InsertionSort(n, array);
}

void InsertionSort(int n, int array[n])
{
    int i, j, key;

    for(i=1; i<n; i++)
    {
        key = array[i];
        j = i-1;

        while(j>=0 && array[j]>key)
        {
            array[j+1] = array[j];
            j=j-1;
        }
        array[j+1] = key;
    }
    printf("\n\nSorted Array is: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }
}
