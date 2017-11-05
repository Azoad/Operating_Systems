#include <stdio.h>

int frame, num = 0;
int page[100];

struct node
{
    int value = -1;
    node *next;
};
node *fptr, *tptr, *nptr, *last = NULL;

void takeInput()
{
    printf("Give Size of page frame: ");
    scanf("%d", &frame);
    printf("Give Number of Pages :");
    scanf("%d", &num);
    printf("Give Pages :");
    for(int i = 0; i<num ; i++)
    {
        scanf("%d", &page[i]);
    }
}

void creatPageFrame()
{
    for(int i = 0; i < frame; i++)
    {
        nptr = new(node);
        nptr -> value = -1;
        nptr -> next = NULL;
        if(fptr == NULL){
            fptr = nptr;
            tptr = nptr;
            last = nptr;
        }
        else
        {
            tptr -> next = nptr;
            tptr = nptr;
            last = nptr;
        }
    }
}

void printPageFrame()
{
    printf("current PageFrame: ");
    tptr = fptr;
    while(1)
    {
        printf("%d ", tptr -> value);
        if(tptr->next != NULL)
            tptr = tptr -> next;
        else
            break;
    }
    printf("\n");
}

void fifo()
{
    int pageFault = 0;
    for(int i = 0; i < num; i++)
    {
        tptr = fptr;
        int flag = 0;
        for(int j = 0; j < frame; j++)
        {
            if(tptr -> value == page[i])
            {
                flag = 1;
                break;
            }
            tptr = tptr->next;
        }
        if(flag == 0){
            node *temp = fptr;
            fptr = fptr -> next; // Deletion of first node cause its FIFO :P
            delete(temp);
            //new node creation
            nptr = new(node);
            nptr->value = page[i];
            nptr->next =NULL;
            // adding new node at the last of the list
            last -> next = nptr;
            last = nptr;

            pageFault++;
            printf("Page Fault Number %d \n", pageFault);
            printPageFrame();

        }
        else
        {
            printf("HIT :D \n");
            printPageFrame();
        }
    }
    printf("Page Fault: %d and Hit: %d", pageFault, num - pageFault);
}

int main()
{
    takeInput();
    creatPageFrame();
    printPageFrame();
    fifo();
}

