#include<stdio.h>
int main()
{
    int E[10], A[10], C[100][100], R[100][100],count=0,flag,flag2[100],temp_vect[10];
    int e,a,p,r;

    printf("Enter the existing vector: ");
    scanf("%d",&e);

    /*printf("\nEnter the available vector: ");
    scanf("%d",&a);*/

    printf("Enter the values of existing vector:");
    for(int i=0; i<e; i++)
    {
        scanf("%d",&E[i]);
    }
    /*printf("\nEnter the values of available vector:");
    for(int i=0; i<a; i++)
    {
        scanf("%d",&A[i]);
    }*/
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
    ///available vector
    for (int i=0; i<r; i++)
    {
        int temp=0;
        for(int j=0; j<p; j++)
        {
            temp = temp + C[j][i];
        }

        A[i]=E[i]-temp;
    }

    printf("Available Vector:");
    for(int i=0; i<e; i++)
    {
        printf("%d ",A[i]);
    }
    for(int i=0; i<p; i++)
    {
        flag2[i]=0;
    }

    ///output

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
    printf("\nOutput of Available Vector After Processing: ");
    for(int j=0; j<r; j++)
    {
        printf("%d ",A[j]);
    }
    printf("\n");
    for(int i=0; i<p; i++)
    {
        if(flag2[i]==1)
        {
            count++;
            if(count==p)
                printf("Any process is not in dead lock");
        }
        else if(flag2[i]==0)
        {
            printf("Process %d is in dead lock\n",i+1);
        }
    }
}
