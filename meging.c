#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct NODE
{
    char name[100];
    int ph;
    struct NODE *ptr;
};
void print();
struct NODE *start = NULL, *temp, *newnode, *prev, *head[25], *tail[25];
int main()
{
    int i, n;
    printf("\nENTER NO OF LISTS TO BE MERGED : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int n, choice;
        char ch;
        printf("\nDATA ENTRY OF list : %d\n", i + 1);
        printf("\nENTER NO OF NODES FOR LIST %d: ",i+1);
        scanf("%d", &n);

        for (int j = 0; j < n; j++)
        {
            newnode = (struct NODE *)malloc(sizeof(struct NODE));
            newnode->ptr = NULL;
            printf("ENTER THE DATA FOR %d NODE : ", j + 1);
            scanf("%d", &newnode->ph);

            if (start == NULL)
            {
                head[i] = start = temp = newnode;
            }
            else
            {
                temp->ptr = newnode;
                temp = newnode;
            }
        }

        tail[i] = temp;

        start = NULL;
    }

    for (i = 0; i < n - 1; i++)
    {
        tail[i]->ptr = head[i + 1];
    }

    print();
}
void print()
{
    int i = 1;
    temp = head[0];
    printf("\n\nELEMENTS OF THE MERGED LINKED LIST : \n\n");
    if (temp == NULL)
    {
        printf("LINKED LIST IS EMPTY ");
    }
    while (temp != NULL)
    {
        printf("NODE %d DATA IS : %d\n", i++, temp->ph);
        temp = temp->ptr;
    }
    printf("\n");
}