#include<stdio.h>
#include<conio.h>

int main()
{
    int n,N,k=0;
    printf("Enter no. of denominations : ");
    scanf("%d",&n);
    int den[n];

    printf("enter the denominations  : ");
    for(int i =0;i<n;i++)
    {
        scanf("%d",&den[i]);
    }
    printf("Enter value N : ");
    scanf("%d",&N);
    int C[n+1][N+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=N;j++)
        {
            if(i==0 || j==0)
            {
                C[i][j]=0;
            }
            else if(i==1)
            {
                C[i][j] = (j<den[i-1])?0:(1+C[i][j-den[i-1]]);
            }
            else if(j<den[i-1])
            {
                C[i][j]=C[i-1][j];
            }
            else{
                C[i][j] = (C[i-1][j] <= 1 + C[i][j-den[i-1]]) ? C[i-1][j] : 1 + C[i][j-den[i-1]];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=N;j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    int sn=C[n][N];
    int j=N;
    int sol[sn];
    int i=n;
    while(i>0 && sn>0)
    {
        if(i==1 || C[i][j] != C[i-1][j])
        {
            sol[k++]=den[i-1];
            sn--;
            j-=den[i-1];
        }
        else i--;
    }
    // printing the solution array in reverse order
   printf("Coins used: ");
    for (i = 0; i < k; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");

    return 0;


}