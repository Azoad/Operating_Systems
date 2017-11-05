#include<stdio.h>
int main()
{
    int r,p;
    printf("Enter the number of resources : ");
    scanf("%d",&r);
    printf("Enter the number of processes : ");
    scanf("%d",&p);
    int E[r],A[r],C[r][p],R[r][p];
    printf("Enter Existing Vector : ");
    for(int i=0; i<r; i++)
    {
        scanf("%d",&E[i]);
    }
    printf("Enter Avialable Vector : ");
    for(int i=0; i<r; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter Current Allocation matrix\n");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            scanf("%d",&C[i][j]);
        }
    }
    printf("Enter Resource Request matrix\n");
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            scanf("%d",&R[i][j]);
        }
    }
}
