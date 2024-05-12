#include<stdio.h>
void main()
{
    int den[]={1,4,6};
    int N=8;
    int n=sizeof(den)/sizeof(den[0]);
    int i,j,sn;
    int k=0;
    int C[n+1][N+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=N;j++)
        {
            if(i==0 || j==0)
            {
                C[i][j]=0;
            }
            else if(i==1)
            {
                C[i][j]=1+C[i][j-den[i-1]];
            }
            else if(j<den[i-1])
            {
                C[i][j]=C[i-1][j];
            }
            else
            {
                if(C[i-1][j]<=1+C[i][j-den[i-1]])
                {
                    C[i][j]=C[i-1][j];
                }
                else
                {
                    C[i][j]=1+C[i][j-den[i-1]];
                }
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=N;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    sn=C[n][N];
    printf("\nNo of coins: %d\n",sn);
    int sol[sn];
    for(i=n;i>=0;i--)
    {
        for(j=N;j>=0;j--)
        {
            if(C[i][j]==C[i-1][j])
            {
                i--;
            }
            else
            {
                j=j-den[i-1];
            }
            sol[k++]=den[i-1];
        }
    }
    for(i=0;i<sn;i++)
    {
        printf("%d ",sol[i]);
    }
}