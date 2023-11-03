#include <stdio.h>
#include <string.h>
#define max 100

int main()
{
    char x[max], y[max];
    printf("Enter the first string: ");
    scanf("%s", x);
    printf("Enter the second string: ");
    scanf("%s", y);

    int m = strlen(x);
    int n = strlen(y);

    x[m]='\0';
    y[n]='\0';

    lcs(x, y, m, n);
    return 0;
}

int maxx(int a, int b)
{
    return (a>b)?a:b;
    //this above line basically means this
    /*if(a>b)
    {
        return a;
    }
    else{
        return b;
    }*/
}

void printLCS(char b[max][max], char x[max], int i, int j)
{
    if(i==0 || j==0)
    {
        return;
    }

    if(b[i][j]=='D')
    {
        printLCS(b, x, i-1, j-1);
        printf("%c", x[i-1]);
    }
    else if (b[i][j]=='L')
    {
        printLCS(b, x, i-1, j);
    }
    else{
        printLCS(b, x, i, j-1);
    }
}

void lcs(char x[max], char y[max], int m, int n)
{
    int c[max][max];
    char b[max][max];

    for(int i=0; i<=m; i++)
    {
        c[i][0]=0;
    }
    for(int j=0; j<=n; j++)
    {
        c[0][j]=0;
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = 'D';   //D ==> Diagonal Arrow
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 'L';   //L ==> Left Arrow
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 'U';   //U ==> Up Arrow
            }
        }
    }

    printf("\nThe Longest Common Subsequence is: ");
    printLCS(b, x, m, n);
    printf("\n");
}

