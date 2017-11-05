#include <stdio.h>

int frame, num;
int page[100];

struct node
{
    int r = 0;
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
        printf("%d(%d) ", temp -> value, temp -> r);
        temp = temp->next;
    }
    printf("\n");
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

void clock()
{
    int pageFault = 0;
    for(int i = 0; i < num; i++)
    {
        int flag = 0;
        node *temp = firstNode;
        int a = isEmpty();
        if(a == 0)
        {
            printf("Give Ref bit for pageframe: ");
            for(int j = 1; j <= frame ; j++)
            {
                scanf("%d", &temp -> r);
                temp = temp -> next;
            }
            printPageFrame();
        }
        temp = firstNode;
        for(int j = 0; j < frame; j++)
        {
            if(temp -> value == page[i]){
                flag = 1;
                temp -> r = 1;
                break;
            }
            temp = temp -> next;
        }

        if(flag == 0)
        {
            pageFault++;
            temp = firstNode;
            for(int j = 0; j < frame; j++)
            {
                if(temp -> r == 0)
                {
                    temp -> value = page[i];
                    temp -> r = 0;
                    temp = temp -> next;
                    firstNode = temp;
                    printf("fault no %d for %d\n", pageFault,page[i]);
                    printPageFrame();
                    break;
                }
                else
                {
                    temp -> r = 0;
                    temp = temp -> next;
                    firstNode = temp;
                    j = -1;
                    printPageFrame();
                }
            }
        }
        else
        {
            printf("HIT :D\n");
            printPageFrame();
        }
    }
    printf("PageFault: %d and Hit: %d", pageFault, num - pageFault);
}

int main()
{
    takeInput();
    creatPageFrame();
    printPageFrame();
    clock();
}
