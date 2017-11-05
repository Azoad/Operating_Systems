#include<stdio.h>
int main()
{
    int p,r,count_1=0;
    printf("Enter the number of resource: ");
    scanf("%d",&r);
    printf("Enter the number of process: ");
    scanf("%d",&p);
    int E[r], A[r], C[p][r], R[p][r],count=0,flag,flag2[100];
    printf("Enter the values of existing vector:");
    for(int i=0; i<r; i++)
    {
        scanf("%d",&E[i]);
    }

    printf("Enter the Current Allocation Matrix: \n");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            scanf("%d",&C[i][j]);
        }
    }
    printf("Enter the Resource Request Matrix: \n");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            scanf("%d",&R[i][j]);
        }
    }
    for (int i=0; i<r; i++)
    {
        int temp=0;
        for(int j=0; j<p; j++)
        {
            temp = temp + C[j][i];
        }

        A[i]=E[i]-temp;
    }

    for(int i=0; i<p; i++)
    {
        flag2[i]=0;
    }

    for(int i=0; i<p; i++)
    {
        if(flag2[i]==0)
        {
            flag=0;
            for(int j=0; j<r; j++)
            {
                if(R[i][j] > A[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag == 0)
            {
                for(int j=0; j<r; j++)
                {
                    A[j]=C[i][j]+A[j];
                }
                flag2[i]=1;
            }
        }
    }

    for(int i=0; i<p; i++)
    {
        if(flag2[i]==0)
        {
            count_1++;
        }
    }
    if(count_1 == 1)
    {
        printf("No Process is  in Deadlock");
    }
    else
    {
        for(int i=0; i<p; i++)
        {
            if(flag2[i]==1)
            {
                count++;
                if(count==p)
                    printf("No Process is  in Deadlock");
            }
            else if(flag2[i]==0)
            {
                printf("Process p%d is in Deadlock\n",i+1);
            }
        }
    }
}
