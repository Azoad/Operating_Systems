#include <stdio.h>

int frame, num = 0;
int page[100];

struct node
{
    int r = 0;
    int value = -1;
    node *next;
};
node *fptr, *tptr, *nptr, *last = NULL;

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
    for(int i = 0; i < frame; i++)
    {
        nptr = new(node);
        nptr -> value = -1;
        nptr ->r = 0;
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
    node *temp = fptr;
    while(1)
    {
        printf("%d(%d) ", temp -> value, temp -> r);
        if(temp->next != NULL)
            temp = temp -> next;
        else
            break;
    }
    printf("\n");
}

int isEmpty(){
    node *temp = fptr;
    for(int j = 1; j <= frame ; j++){
        if(temp -> value == -1)
        {
            return 1;
        }
        temp = temp -> next;
    }
    return 0;
}

void secondChance()
{
    int pageFault = 0;
    for(int i = 0; i < num; i++)
    {
        tptr = fptr;
        int flag = 0;
        node *temp = fptr;
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

        for(int j = 0; j < frame; j++)
        {
            if(tptr -> value == page[i])
            {
                flag = 1;
                tptr -> r = 1;
                break;
            }
            tptr = tptr->next;
        }
        if(flag == 0){
           node *tem = fptr;
           for(int k = 0; k < frame; k++){
                if(tem -> r != 1)
                {
                    node *temp = fptr;
                    fptr = fptr -> next; // Deletion of first node cause its FIFO :P
                    delete(temp);
                    //new node creation
                    nptr = new(node);
                    nptr->value = page[i];
                    nptr -> r = 0;
                    nptr->next =NULL;
                    // adding new node at the last of the list
                    last -> next = nptr;
                    last = nptr;

                    pageFault++;
                    printf("fault no %d for %d\n", pageFault,page[i]);
                    printPageFrame();
                    break;
                }
                else
                {
                    last -> next = fptr;
                    last = fptr;
                    fptr = fptr -> next;
                    last -> r = 0;
                    last -> next = NULL;
                    tem = fptr;
                    k = -1;
                    printPageFrame();
                }
           }

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
    secondChance();
}
