#include <stdio.h>

int main()
{
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);

    int array[n];
    int i;
    for(i=0; i<n; i++)
    {
        printf("\nEnter the %dth value: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nThe array elements you entered are: \n");

    for(i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }

    int min, j, loc, temp;
    min = array[0];

    for(i=0; i<n; i++)
    {
        min = array[i];
        loc = i;
        
        for(j=i+1; j<n; j++)
        {
            if(array[j]<min)
            {
                min = array[j];
                loc = j;
            }
        }

        if(loc!=0)
        {
            temp = array[i];
            array[i] = array[loc];
            array[loc] = temp;
        }
    }

    printf("\nSorted array is: \n");

    for(i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }   
    
    return 0;
}
