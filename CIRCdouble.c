#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    int data;
    struct NODE *lptr, *rptr;
};

void create();
void print();
void insert_pos();
void insert_val();
void delete_pos();
void delete_val();
void reverse();
void create2();
void merge();
struct NODE *start = NULL, *temp, *newnode, *prev, *next, *start2 = NULL;
int n;
int main()

{
    create();
}
void create()
{
    int choice;
    char ch;

    printf("\n\nENTER NO OF NODES : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        newnode = (struct NODE *)malloc(sizeof(struct NODE));
        newnode->rptr = NULL;
        newnode->lptr = NULL;
        printf("ENTER THE DATA FOR %d NODE : ", i);
        scanf("%d", &newnode->data);

        if (start == NULL)
        {
            start = temp = newnode;
            start->rptr = start->lptr = start;
        }
        else
        {
            newnode->lptr = temp;
            newnode->rptr = temp->rptr;
            temp->rptr = newnode;
            temp = newnode;
        }
    }
    do
    {
        printf("----------------------------------------------------------------");
        printf("\n\n------MENU------\n1. INSERT BY VALUE\n2. INSERT BY POSITION\n3. DELETE BY POSITION\n4. DELETE BY VALUE\n5. MERGE 2 LISTS\n\nCHOOSE AN OPTION(1-5) : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_val();
            break;
        case 2:
            insert_pos();
            break;
        case 3:
            delete_pos();
            break;
        case 4:
            delete_val();
            break;
        case 5:
            create2();
            break;
        case 6:
            print();
            break;
        case 7:
            reverse();
            break;

        default:
            printf("INVALID OPTINO CHOOSEN!!");
        }
        printf("\n\nWOULD YOU LIKE TO CONTINUE (Y for YES , N for NO ) :\n\n");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void print()
{
    int i = 1;
    temp = start;
    printf("\n\nELEMENTS OF THE LINKED LIST : \n\n");
    if (start == NULL)
    {
        printf("LINKED LIST IS EMPTY ");
    }

    do
    {  
        printf("NODE %d DATA IS : %d\n", i++, temp->data);
        temp = temp->rptr;
    } while (temp ->rptr!= start);
    printf("\n");
}
void insert_pos()
{
    int pos, val;
    temp = start;
    printf("ENTER THE POSITION TO INSERT A NODE : ");
    scanf("%d", &pos);
    printf("ENTER THE  DATA TO  NODE TO BE INSERTED : ");
    scanf("%d", &val);
    newnode = (struct NODE *)malloc(sizeof(struct NODE));
    newnode->data = val;
    newnode->rptr = NULL;
    newnode->lptr = NULL;
    if (start == NULL)
    {
        start = newnode;
        start->lptr = start->rptr = start;
    }
    else
    {
        if (pos == 1)
        {
            start->lptr = newnode;
            newnode->rptr = start;
            newnode->lptr = start->lptr;
            start = newnode;
            while (temp->rptr != start)
            {
                temp = temp->rptr;
            }
            temp->rptr = newnode;
        }
        else
        {
            if (pos > n)
            {
                while (temp->rptr != start)
                {
                    temp = temp->rptr;
                }
                newnode->lptr = temp;
                newnode->rptr = temp->rptr;
                temp->rptr = newnode;
                start->lptr = newnode;
            }
            else
            {
                int i = 2;
                while (i++ < pos && temp->rptr != NULL)
                {
                    temp = temp->rptr;
                }
                newnode->rptr = temp->rptr;
                newnode->lptr = temp;
                temp->rptr->lptr = newnode;
                temp->rptr = newnode;
            }
        }
    }
    print();
}

void insert_val()
{
    int val;
    temp = start;

    printf("ENTER THE Value of the NODE TO BE INSERTED('BY-VALUE') : ");
    scanf("%d", &val);
    newnode = (struct NODE *)malloc(sizeof(struct NODE));
    newnode->data = val;
    newnode->rptr = NULL;
    newnode->lptr = NULL;
    if (start == NULL)
    {
        start = start->lptr = start->rptr = newnode;
    }
    else
    {
        if ((start->data) < start->rptr->data)
        {
            if ((start->data) > val)
            {
                newnode->rptr = start;
                newnode->lptr = start->lptr;
                start->lptr->rptr = newnode;
                start->lptr = newnode;
                start = newnode;
            }
            else
            {
                while (temp->rptr != start)
                {
                    if ((temp->data) <= val && ((temp->rptr->data) >= val))
                    {
                        break;
                    }
                    else
                    {
                        temp = temp->rptr;
                    }
                }
                if (temp->rptr == start)
                {
                    newnode->lptr = temp;
                    newnode->rptr = start;
                    start->lptr = newnode;
                    temp->rptr = newnode;
                    start = newnode;
                }
                else
                {
                    newnode->rptr = temp->rptr;
                    newnode->lptr = temp;
                    temp->rptr->lptr = newnode;
                    temp->rptr = newnode;
                }
            }
        }
        else
        {
            if ((start->data) > start->rptr->data)
            {
                if ((start->data) < val)
                {
                    newnode->rptr = start;
                    newnode->lptr = start->lptr;
                    start->lptr->rptr = newnode;
                    start->lptr = newnode;
                    start = newnode;
                }
                else
                {
                    while (temp->rptr != start)
                    {
                        if ((temp->data) >= val && ((temp->rptr->data) <= val))
                        {
                            break;
                        }
                        else
                        {
                            temp = temp->rptr;
                        }
                    }
                    if (temp->rptr == start)
                    {
                        newnode->lptr = temp;
                        newnode->rptr = start;
                        start->lptr = newnode;
                        temp->rptr = newnode;
                        start = newnode;
                    }
                    else
                    {
                        newnode->rptr = temp->rptr;
                        newnode->lptr = temp;
                        temp->rptr->lptr = newnode;
                        temp->rptr = newnode;
                    }
                }
            }
        }
        print();
    }
}
void delete_pos()
{
    int pos, i = 1;
    temp = start;
    printf("ENTER POSITION OF THE NODE TO BE DELETED : ");
    scanf("%d", &pos);

    if (start == NULL)
    {
        printf("LINKED LIST IS EMPTY");
    }
    else
    {
        if (pos == 1)
        {

            if (start->rptr == NULL)
            {
                start = NULL;
                free(temp);
            }
            else
            {

                temp->rptr->lptr = start->lptr;
                start->lptr->rptr = temp->rptr;
                start = temp->rptr;
                free(temp);
                n--;
            }
        }
        else
        {
            while (i++ < pos && temp->rptr != NULL)
            {
                temp = temp->rptr;
            }
            if (temp->rptr == start)
            {
                temp->lptr->rptr = start;
                start->lptr = temp->lptr;
                free(temp);
                n--;
            }
            else
            {
                temp->lptr->rptr = temp->rptr;
                temp->rptr->lptr = temp->lptr;
                free(temp);
                n--;
            }
        }
    }
    print();
}
void delete_val()
{

    temp = start;
    int val;
    printf("ENTER THE VALUE TO BE DELTED : ");
    scanf("%d", &val);

    if (start == NULL)
    {
        printf("LINKED LIST IS EMPTY");
    }
    else
    {
        if (start->data == val)
        {
            if (start->rptr == start)
            {
                start = NULL;
                free(temp);
            }
            else
            {
                start->rptr->lptr = start->lptr;
                start->lptr->rptr = start->rptr;
                start = start->rptr;
                free(temp);
            }
        }
        else
        {
            while (temp->data != val && temp->rptr != start)
            {
                temp = temp->rptr;
            }
            if (temp->rptr == start)
            {
                if (temp->data != val)
                {
                    printf("VALUE NOT FOUND ");
                }
                else
                {
                    temp->rptr->lptr = temp->lptr;
                    temp->lptr->rptr = start;
                    free(temp);
                }
            }
            else
            {
                temp->rptr->lptr = temp->lptr;
                temp->lptr->rptr = temp->rptr;
                free(temp);
            }
        }
    }
    print();
}
void reverse()
{
    temp = start;
    while (temp->rptr != start)
    {
        next = temp->rptr;
        temp->rptr = temp->lptr;
        temp->lptr = next;
        temp = temp->lptr;
      
    }

    next = temp->rptr;
    temp->rptr = temp->lptr;
    temp->lptr = next;

    start = temp;
    print();
  
}

void create2()
{
    int n;

    printf("\n\nENTER NO OF NODES for SECOND LINKED LIST : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        newnode = (struct NODE *)malloc(sizeof(struct NODE));
        newnode->rptr = NULL;
        newnode->lptr = NULL;
        printf("ENTER THE DATA FOR %d NODE : ", i);
        scanf("%d", &newnode->data);

        if (start2 == NULL)
        {
            start2 = temp = newnode;
            temp->lptr = NULL;
            temp->rptr = NULL;
        }
        else
        {
            newnode->lptr = temp;
            newnode->rptr = temp->rptr;
            temp->rptr = newnode;
            temp = newnode;
        }
    }

    merge();
}
void merge()
{
    temp = start;
    while (temp->rptr != NULL)
    {
        temp = temp->rptr;
        printf("%d", temp->data);
    }
    temp->rptr = start2;
    start2->lptr = temp;
    printf("MERGED LINKED LIST IS : ");
    print();
}