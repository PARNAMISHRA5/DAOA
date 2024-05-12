#include<stdio.h>
void main()
{
    int i,j,temp;
    int job[][3]={ { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
    int n=sizeof(job)/sizeof(job[0]);
    int profit=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(job[i][2]<job[j][2])
            {
                temp=job[i][2];
                job[i][2]=job[j][2];
                job[j][2]=temp;

                temp=job[i][1];
                job[i][1]=job[j][1];
                job[j][1]=temp;

                temp=job[i][0];
                job[i][0]=job[j][0];
                job[j][0]=temp;

            }
        }
    }
    int a[n];     
    for(i=0;i<n;i++){
        a[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>=0;j--)
        {
            if(a[j]==0 && job[i][1]>=j+1)
            {        
                a[j] = job[i][0];
                profit =profit+ job[i][2];
                break;                    
            }
        }
    }
    printf("Profit: %d\n",profit);
    for(i=0;i<n;i++)
    {
        printf("%c ",a[i]);
    }
}