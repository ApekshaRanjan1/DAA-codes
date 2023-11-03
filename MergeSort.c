#include <stdio.h>

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int array[n];

    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter element at position %d: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("\nEntered array is: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }

    int low = 0;
    int high = n-1;
    MergeSort(array, low, high);

    printf("\nSorted array is: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}

void MergeSort(int array[], int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        MergeSort(array, low, mid);
        MergeSort(array, mid+1, high);
        Combine(array, low, mid, high);
    }
}

void Combine(int array[], int low, int mid, int high)
{
    int temp[100];
    int k = low;
    int i = low;
    int j = mid+1;

    while(i<=mid && j<=high)
    {
        if(array[i]<=array[j])
        {
            temp[k] = array[i];
            i++;
            k++;
        }
        else{
            temp[k] = array[j];
            j++;
            k++;
        }    
    }

    while(i<=mid)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while(j<=high)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++) {
        array[i] = temp[i];
    }
}
