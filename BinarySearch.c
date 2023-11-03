#include <stdio.h>

int main()
{
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d", &n);
    int array[n];
    
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter %dth element in the array: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nElements you entered are: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", array[i]);
    }

//if want to input unsorted array then uncomment this below part
    
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
    printf("\n\nSorted Array is:\n\n");
    for (i=0;i<n;i++)
    {
        printf("%d\t", array[i]);
    }

    int key;
    printf("\nEnter the number to be seacrhed in the array: ");
    scanf("%d", &key);

    int start, end;
    start = 0;
    end = n-1;
    bSearch(start, end, array, key);

    return 0;
}

void bSearch(int start, int end, int array[], int key)
{
    if(end>=start){
        int mid = (start+end)/2;

        if(array[mid] == key)
        {
            printf("%d found at %dth position", key, mid+1);
            return;
        }
        else if(key>array[mid])
        {
            bSearch(mid+1, end, array, key);
        }
        else if(key<array[mid])
        {
            bSearch(start, mid-1, array, key);
        }
        return;
    }
    
    printf("%d not found!", key);
}
