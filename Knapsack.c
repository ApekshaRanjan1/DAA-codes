#include <stdio.h>
//if you dont wanna calculate the time complexity simply remove all lines with counter
int main()
{
    int n;
    printf("\nEnter the number of objects: ");
    scanf("%d", &n);
    int counter = 0;
    float selected[n], w[n], p[n];
    float ratio[n];

    int W;
    printf("\nEnter the maximum weight of the bag: ");
    scanf("%d", &W);
    printf("\n-------------------------------------------------");
    
    
    int i, j;
    printf("\n\nEnter the weights of individual objects: ");
    for(i=0; i<n; i++)
    {
        printf("\nEnter the weight of object %d: ", i+1);
        scanf("%f", &w[i]);
    }
    printf("\n-------------------------------------------------");
    
    
    printf("\n\nEnter the profits of individual objects: ");
    for(i=0; i<n; i++)
    {
        printf("\nEnter the profit of object %d: ", i+1);
        scanf("%f", &p[i]);
    }
    printf("\n-------------------------------------------------");
    
    
    printf("\n\nWeight\tProfit\tRatio");
    for(i=0; i<n; i++)
    {
        ratio[i] = p[i]/w[i];

        printf("\n%.2f\t%.2f\t%.2f", w[i], p[i], ratio[i]);
        counter++;
    }
    printf("\n-------------------------------------------------");

    //sorting the table according to ratio...in descending order

    float temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp = ratio[i];
               ratio[i] = ratio[j];
               ratio[j] = temp;

               temp = p[i];
               p[i] = p[j];
               p[j] = temp;

               temp = w[i];
               w[i] = w[j];
               w[j] = temp;
            }
            counter++;
        }
    }

    printf("\nSorted table is: ");
    printf("\n\nWeight\tProfit\tRatio");
    for(i=0; i<n; i++)
    {

        printf("\n%.2f\t%.2f\t%.2f", w[i], p[i], ratio[i]);
    }
    printf("\n-------------------------------------------------");

    float weight=0, profit=0;

    for(i=0; i<n; i++)
    {
        if(weight+w[i]<=W)
        {
            selected[i] = 1;
            weight = weight + w[i];
            profit = profit + p[i];
        }
        else{
            float frac = (W-weight)/w[i];
            selected[i] = frac;
            weight = W;
            profit = profit + (p[i]*frac); 
        }
        counter++;
    }

    printf("\n\nFinal Result: ");
    printf("\n\nWeight\tProfit\tRatio\tSelected");
    for(i=0; i<n; i++)
    {

        printf("\n%.2f\t%.2f\t%.2f\t%.2f", w[i], p[i], ratio[i], selected[i]);
    }
    printf("\n\nTotal Weight: %.2f", weight);
    printf("\nTotal Profit: %.2f", profit);
    printf("\nTime Complexity: %d", counter);

    return 0;

}
