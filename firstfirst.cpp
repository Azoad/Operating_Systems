#include<stdio.h>
int main()
{
    int len;
    printf("Enter the length : ");
    scanf("%d",&len);
    int num[len];
    printf("Enter the numbers : ");
    for(int i=0;i<len;i++)
    {
        scanf("%d",&num[i]);
    }
    int nframe;
    printf("Enter the frame number : ");
    scanf("%d",&nframe);
    int numframe[nframe];
    int i,j,k=0,l;
    for(i=0;i<nframe;i++)
    {
        numframe[i] = 0;
    }
    int faultcount=0;
    for(i=0;i<len;i++)
    {
        printf("\nFor %d : ",num[i]);
        int nofault = 0;
        for(j=0;j<nframe;j++)
        {
            if(numframe[j] == 0)
            {
                numframe[j] = num[i];
                faultcount++;
                break;
            }
            else if(num[i] == numframe[j])
            {
                nofault = 1;
                break;
            }
        }
        if(j == nframe)
        {
            for(k=0;k<nframe-1;k++)
            {
                numframe[k] = numframe[k+1];
            }
            numframe[nframe-1] = num[i];
            faultcount++;
        }
        for(l=0;l<nframe;l++)
        {
            if(numframe[l]!=0)
            {
                if(nofault == 1)
                {
                    printf("No Fault");
                    break;
                }
                else
                {
                    printf("%d ",numframe[l]);
                }
            }
        }
        printf("\n");
    }
    printf("\nTotal number of page fault : %d",faultcount);
}
