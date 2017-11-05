#include<stdio.h>
int nsequence,nframe;
int pseq[100],pfault=0,p[50];
int hit = 0;
void initialize()
{
    pfault = 0;
    for(int i=0; i<nframe; i++)
    {
        p[i] = 9999;
    }
}
int ishit(int x)
{
    hit = 0;
    for(int i=0; i<nframe; i++)
    {
        if(p[i] == x)
        {
            hit = 1;
        }
    }
    return hit;
}
int hitindex(int x)
{
    int hitindex;
    for(int i=0; i<nframe; i++)
    {
        if(p[i] == x)
        {
            hitindex = i;
            break;
        }
    }
    return hitindex;
}
void displayPages()
{
    for(int i=0; i<nframe; i++)
    {
        if(p[i] != 9999)
        {
            printf(" %d",p[i]);
        }
    }
}
void pageFaultCount()
{
    printf("\nThe Number of total page faults : %d\n\n",pfault);
}
void optimalPRA()
{
    printf("\nOptimal PRA");
    initialize();
    int near[50];
    for(int i=0; i<nsequence; i++)
    {
        printf("\nFor %d : ",pseq[i]);
        if(ishit(pseq[i]) == 0)
        {
            for(int j=0; j<nframe; j++)
            {
                int page = p[j];
                int found = 0;
                for(int k=i; k<nsequence; k++)
                {
                    if(page == pseq[k])
                    {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                    else
                    {
                        found = 0;
                    }
                }
                if(!found)
                {
                    near[j] = 9999;
                }
            }
            int max = -9999;
            int repeatindex;
            for(int j=0; j<nframe; j++)
            {
                if(near[j] > max)
                {
                    max = near[j];
                    repeatindex = j;
                }
            }
            p[repeatindex]=pseq[i];
            pfault++;
            displayPages();
        }
        else
            printf("No page fault");
    }
    pageFaultCount();

}
void FIFOPRA()
{
    printf("\nFiFo PRA");
    initialize();
    int j;
    for(int i=0; i<nsequence; i++)
    {
        printf("\nFor %d : ",pseq[i]);
        if(ishit(pseq[i]) == 0)
        {
            for(j=0; j<nframe-1; j++)
            {
                p[j] = p[j+1];
            }
            p[j] = pseq[i];
            pfault++;
            displayPages();
        }
        else
        {
            printf("No page fault");
        }
    }
    pageFaultCount();
}
void secondchancePRA()
{
    printf("\nSecond Chance PRA");
    int refbit[50];
    int victim=0;
    initialize();
    for(int i=0; i<nframe; i++)
        refbit[i]=0;
    for(int i=0; i<nsequence; i++)
    {
        printf("\nFor %d:",pseq[i]);
        if(ishit(pseq[i]))
        {
            printf("No page fault");
            int hitind=hitindex(pseq[i]);
            if(refbit[hitind]==0)
                refbit[hitind]=1;
        }
        else
        {
            pfault++;
            if(refbit[victim]==1)
            {
                do
                {
                    refbit[victim]=0;
                    victim++;
                    if(victim==nframe)
                        victim=0;
                }
                while(refbit[victim]!=0);
            }
            if(refbit[victim]==0)
            {
                p[victim]=pseq[i];
                refbit[victim]=1;
                victim++;
            }
            displayPages();

        }
        if(victim==nframe)
            victim=0;
    }
    pageFaultCount();
}
void NRUPRA()
{
    printf("\nNot Recently Used PRA");
}
void clockPRA()
{
    printf("Clock PRA");
}
int main()
{
    while(1)
    {
        printf("Enter the page sequence number : ");
        scanf("%d",&nsequence);
        printf("Enter the page sequence : ");
        for(int i=0; i<nsequence; i++)
        {
            scanf("%d",&pseq[i]);
        }
        printf("Enter the page frame number : ");
        scanf("%d",&nframe);

        int choice;
        printf("\nFrame number %d",nframe);
        printf("\n\nThe available algorithms are :\n1.Optimal PRA\n2.First in First out(FIFO) PRA\n3.Second Chance PRA\n4.Not Recently Used(NRU) PRA\n5.Clock PRA");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            optimalPRA();
        }
        else if(choice == 2)
        {
            FIFOPRA();
        }
        else if(choice == 3)
        {
            secondchancePRA();
        }
        else if(choice == 4)
        {
            NRUPRA();
        }
        else if(choice == 5)
        {
            clockPRA();
        }
        else
        {
            printf("Wrong Choice");
            break;
        }
    }
}
