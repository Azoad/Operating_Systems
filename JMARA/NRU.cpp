#include <stdio.h>

int frame, num = 0;
int page[100];

struct node
{
    int r = 0;
    int m = 0;
    int value = -1;
    node *next;
};
node *firstNode, *newNode = NULL;

void takeInput()
{
    printf("Give Size of page frame: ");
    scanf("%d", &frame);

    printf("Give Number of Pages   : ");
    scanf("%d", &num);

    printf("Give Pages             : ");
    for(int i = 0; i<num ; i++)
    {
        scanf("%d", &page[i]);
    }
}

void creatPageFrame()
{
    node *temp;
    for(int i = 0; i < frame; i++)
    {
        newNode = new(node);
        newNode -> value = -1;
        newNode -> r = 0;
        newNode -> m = 0;
        newNode -> next = NULL;
        if(firstNode == NULL){
            firstNode = newNode;
            temp = newNode;
        }
        else
        {
            temp -> next = newNode;
            temp = newNode;
            temp -> next = firstNode;
        }
    }
}

void printPageFrame()
{
    printf("current PageFrame: ");
    node *temp = firstNode;
    for(int i = 0; i < frame; i++)
    {
        printf("%d(%d,%d) ", temp -> value, temp -> r, temp -> m);
        temp = temp->next;
    }
    printf("\n");
}

int rmCount(int r, int m)
{
    int count = 0;
    node *temp = firstNode;
    for(int i = 0; i < frame; i++)
    {
        if(temp -> r == r && temp -> m == m){
            count++;
        }
        temp = temp -> next;
    }
    return count;
}

int isEmpty(){
    node *temp = firstNode;
    for(int j = 1; j <= frame ; j++){
        if(temp -> value == -1)
        {
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}


void nru()
{
    int pageFault = 0;
    for(int i = 0; i < num; i++)
    {
        int valueFlag = 0;
        node *temp = firstNode;
        int a = isEmpty();
        if(a == 0)
        {
            printf("Give Ref & Mod bit for pageframe: ");
            for(int j = 1; j <= frame ; j++)
            {
                scanf("%d %d", &temp -> r, &temp->m);
                temp = temp -> next;
            }
            printPageFrame();
        }
        temp = firstNode;
        for(int j = 0; j < frame; j++){
            if(temp -> value == page[i]){
                valueFlag = 1;
                temp -> r = 1;
                break;
            }
            else
            {
                temp -> r = 0;
            }
            temp = temp -> next;
        }
        if(valueFlag == 0)
        {
            pageFault++;
            temp = firstNode;
            int rm00 = rmCount(0, 0);
            int rm01 = rmCount(0, 1);
            int rm10 = rmCount(1, 0);
            int rm11 = rmCount(1, 1);
            if(rm00 > 0)
            {
                temp = firstNode;
                int flag00 = 0;
                for(int j = 0; j < frame; j++)
                {
                    if(temp -> r == 0 && temp -> m == 0)
                    {
                        if(temp -> value == -1)
                        {
                            flag00 = 1;
                            temp -> value = page[i];
                            printf("fault no %d for %d\n", pageFault,page[i]);
                            printPageFrame();
                            break;
                        }
                    }
                    temp = temp -> next;
                }
                if(flag00 == 0)
                {
                    temp = firstNode;
                    for(int j = 0; j < frame; j++)
                    {
                        if(temp -> r == 0 && temp -> m == 0)
                        {
                            temp -> value = page[i];
                            printf("fault no %d for %d\n", pageFault,page[i]);
                            printPageFrame();
                            break;
                        }
                        temp = temp -> next;
                    }
                }

            }
            else if(rm01 > 0)
            {
                temp = firstNode;
                for(int j = 0; j < frame; j++)
                {
                    if(temp -> r == 0 && temp -> m == 1)
                    {
                        temp -> value = page[i];
                        printf("fault no %d for %d\n", pageFault,page[i]);
                        printPageFrame();
                        break;
                    }
                    temp = temp -> next;
                }
            }
            else if(rm10 > 0)
            {
                temp = firstNode;
                for(int j = 0; j < frame; j++)
                {
                    if(temp -> r == 1 && temp -> m == 0)
                    {
                        temp -> value = page[i];
                        printf("fault no %d for %d\n", pageFault,page[i]);
                        printPageFrame();
                        break;
                    }
                    temp = temp -> next;
                }
            }
            else if(rm11 > 0)
            {
                temp = firstNode;
                for(int j = 0; j < frame; j++)
                {
                    if(temp -> r == 1 && temp -> m == 1)
                    {
                        temp -> value = page[i];
                        printf("fault no %d for %d\n", pageFault,page[i]);
                        printPageFrame();
                        break;
                    }
                    temp = temp -> next;
                }
            }
        }
        else{
            printf("Hit :D           ");
            printPageFrame();
        }
    }
    printf("Page Fault : %d \n", pageFault);
}

int main()
{
    takeInput();
    creatPageFrame();
    printPageFrame();
    nru();

}

