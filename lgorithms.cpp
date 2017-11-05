#include <stdio.h>
#include <bits/stdc++.h>
#include <string.h>
#include <conio.h>

struct frame_type
{
    int name;
    int mod;
    int ref;
    int level;
};

frame_type * frame = new frame_type[100];
int page[100];
int num_frame;
int fault;
int num_page;

void input()
{
    printf("Enter the number of pages : ");
    scanf("%d",&num_page);

    printf("Enter the page sequence :");
    for(int i = 0; i < num_page; i++)
        scanf("%d",&page[i]);
    page[num_page] = -1;

    printf("Enter the number of Frame : ");
    scanf("%d",&num_frame);

    for(int i = 0; i < num_frame; i++)
        frame[i].name = -1;
}

void display()
{
    printf("\nframe:" );
    for(int i = 0; i < num_frame; i++)
    {
        if(frame[i].name == -1)
            printf(" ");
        else
            printf(" %d ",frame[i].name);
    }
    printf(" ");
}

int find(int a)
{
    for(int i = 0; i < num_frame; i++)
    {
        if(a == frame[i].name)
            return i;
    }
    return -1;
}

int high_level()
{
    int m;
    m = 0;
    for(int i = 1; i < num_frame; i++)
    {
        if(frame[m].level < frame[i].level)
        {
            m = i;
        }
    }
    return m;
}

int low_priority()
{
    int m;
    m = -1;
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < num_frame; i++)
        {
            if((frame[i].ref * 2 + frame[i].mod) == j)
            {
                m = i;
                break;
            }
        }
        if(m > -1)
            break;
    }
    return m;
}

void NRU()
{
    fault = 0;
    input();
    for(int i = 0; i < num_page; i++)
    {
        if(find(page[i]) == -1)
        {
            fault++;
            int index = find(-1);
            if(index == -1)
            {
                printf("\nFor input reference and modification : ");
                for(int j = 0; j < num_frame; j++)
                {
                    printf("\nReference for %d : ",frame[j].name);
                    scanf("%d",&frame[j].ref);
                    printf("Modification for %d : ",frame[j].name);
                    scanf("%d",&frame[j].mod);
                }
                int r = low_priority();
                frame[r].name = page[i];
            }
            else
            {
                frame[index].name = page[i];
            }
        }
        display();
    }
    printf("\nPage fault is: %d\n",fault);
}

void FIFO()
{
    fault = 0;
    input();
    for(int i = 0; i < num_page; i++)
    {
        if(find(page[i]) == -1)
        {
            fault++;
            int index = find(-1);
            if(index == -1)
            {
                for(int j = 0; j < num_frame-1; j++)
                {
                    frame[j].name = frame[j+1].name;
                }
                frame[num_frame-1].name = page[i];
            }
            else
            {
                frame[index].name = page[i];
            }
        }
        display();
    }
    printf("\nPage fault is: %d\n",fault);
}

int refWise()
{
    int m;
    m = -1;
    for(int j = 0; j < 2; j++)
    {
        for(int i = 0; i < num_frame; i++)
        {
            if(frame[i].ref == 1)
            {
                frame[i].ref = 0;
            }
            else
            {
                m = i;
                break;
            }
        }
        if(m > -1)
            break;
    }
    return m;
}

void SecondChance()
{
    fault = 0;
    input();
    for(int i = 0; i < num_page; i++)
    {
        if(find(page[i]) == -1)
        {
            fault++;
            int index = find(-1);
            if(index == -1)
            {
                printf("\nFor input reference : ");
                for(int j = 0; j < num_frame; j++)
                {
                    printf("\nfor %d : ",frame[j].name);
                    scanf("%d",&frame[j].ref);
                }

                int r = refWise();
                for(int j = r; j < num_frame-1; j++)
                {
                    frame[j].name = frame[j+1].name;
                }
                frame[num_frame-1].name = page[i];
            }
            else
            {
                frame[index].name = page[i];
            }
        }
        display();
    }
    printf("Page fault is: %d",fault);
}

int refWiseClock(int a)
{
    int m;
    m = -1;
    for(int j = 0; j < 2; j++)
    {
        for(int i = a; i < num_frame; i++)
        {
            if(frame[i].ref == 1)
            {
                frame[i].ref = 0;
            }
            else
            {
                m = i;
                break;
            }
        }
        if(m > -1)
            break;
    }
    return m;
}

void ClockPage()
{
    fault = 0;
    input();
    int indicator = 0;
    for(int i = 0; i < num_page; i++)
    {
        if(find(page[i]) == -1)
        {
            fault++;
            int index = find(-1);
            if(index == -1)
            {
                printf("\nFor input reference : ");
                for(int j = 0; j < num_frame; j++)
                {
                    printf("\tfor %d : ",frame[j].name);
                    scanf("%d",&frame[j].ref);
                }
                int r = refWiseClock(indicator);
                frame[r].name = page[i];
                indicator = r;
            }
            else
            {
                frame[index].name = page[i];
                indicator = index;
            }
        }
        display();
    }
    printf("\nPage fault is: %d\n",fault);
}

int main()
{
    int num1;
    while(1)
    {
        printf("1. FIFO page replacement Algorithm\n");
        printf("2. Second Chance page replacement Algorithm\n");
        printf("3. Not Recently Used page replacement Algorithm\n");
        printf("4. Clock Page replacement Algorithm\n");
        printf("Enter the number to select Algorithm : ");
        scanf("%d",&num1);

        if(num1 == 1)
            FIFO();
        else if(num1 == 2)
            SecondChance();
        else if(num1 == 3)
            NRU();
        else if(num1 == 4)
            ClockPage();
        else
            break;
    }
return 0;
}
