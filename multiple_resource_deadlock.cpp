#include<stdio.h>
int main()
{
    int E[10], A[10], C[100][100], R[100][100],count=0,flag=0,flag2=0;
    int e,a,p,r;

    printf("Enter the existing vector: ");
    scanf("%d",&e);

    printf("\nEnter the available vector: ");
    scanf("%d",&a);

    printf("Enter the values of existing vector:");
    for(int i=0; i<e; i++)
    {
        scanf("%d",&E[i]);
    }
    printf("\nEnter the values of available vector:");
    for(int i=0; i<a; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("\nEnter the number of process");
    scanf("%d",&p);

    printf("\nEnter the number of resource");
    scanf("%d",&r);

    printf("\nEnter the Current allocation matrix: ");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            scanf("%d",&C[i][j]);
        }
    }
    printf("\nEnter the Resource matrix: ");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            scanf("%d",&R[i][j]);
        }
    }
    for(int k=1; k<=p+1; k++)
    {
        for(int i=0; i<p; i++)
        {
            for(int j=0; j<r; j++)
            {
                if(R[i][j] <= A[j])
                {
                    flag2++;
                    //printf("Flag = %d",flag2);
                }
                else
                {
                    flag2=0;
                    //printf("Flag = %d",flag2);
                }
            }
            if(flag2 == r)
            {
                printf("Available matrix:");
                for(int k=0; k<r; k++)
                {
                    A[k] = A[k]+C[i][k];
                    C[i][k] = 0;
                    printf(" %d ",A[k]);
                }
                flag2=0;
                printf("\n");
            }
            else
            {
                flag2=0;
            }
        }
    }
    printf("Current Allocation Matrix:\n");
    for (int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            printf("%d ",C[i][j]);
            if(C[i][j] != 0)
            {
                count++;
            }
        }
        printf("\n");
    }
    if(count>0)
    {
        printf("not deadlocked");
    }
    else
    {
        printf("deadlocked");
    }
}


