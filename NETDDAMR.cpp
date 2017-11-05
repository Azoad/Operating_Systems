#include<stdio.h>
#include<conio.h>
int main()
{
    int found,flag,l,p[3][4],tp,c[3][4],i,j,k=1,m[4],r[4],a[4],temp[4],sum=0;
    printf("enter total no of processes");
    scanf("%d",&tp);
    printf("enter clain matrix");
    for(i=1; i<=3; i++)
        for(j=1; j<=4; j++)
        {
            scanf("%d",&c[i][j]);
        }
    printf("enter allocation matrix");
    for(i=1; i<=3; i++)
        for(j=1; j<=4; j++)
        {
            scanf("%d",&p[i][j]);
        }
    printf("enter resource vector:\n");
    for(i=1; i<=4; i++)
    {
        scanf("%d",&r[i]);
    }
    printf("enter availability vector:\n");
    for(i=1; i<=4; i++)
    {
        scanf("%d",&a[i]);
        temp[i]=a[i];
    }
    for(i=1; i<=3; i++)
    {
        sum=0;
        for(j=1; j<=4; j++)
        {
            sum+=p[i][j];
        }
        if(sum==0)
        {
            m[k]=i;
            k++;
        }
    }
    for(i=1; i<=3; i++)
    {
        for(l=1; l<k; l++)
            if(i!=m[l])
            {
                flag=1;
                for(j=1; j<=4; j++)
                    if(c[i][j]>temp[j])
                    {
                        flag=0;
                        break;
                    }
            }
        if(flag==1)
        {
            m[k]=i;
            k++;
            for(j=1; j<=4; j++)
                temp[j]+=p[i][j];
        }
    }
    printf("deadlock causing processes are:");
    for(j=1; j<=tp; j++)
    {
        found=0;
        for(i=1; i<k; i++)
        {
            if(j==m[i])
                found=1;
        }
        if(found==0)
            printf("%d\t",j);
    }
    getch();
}
