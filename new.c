#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    char name[100];
    int ph;
    struct NODE *ptr;
};
struct NODE *start = NULL, *temp, *newnode, *prev, *next, *start2;

void create();
void print();
void insert_pos();
void insert_val();
void delete_pos();
void delete_val();
void min_max();
void search();
void reverse();
void create2();

int main()

{
    create();
}

void create()
{
    int n, choice;
    char ch;

    printf("ENTER NO OF NODES : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        newnode = (struct NODE *)malloc(sizeof(struct NODE));
        newnode->ptr = NULL;
        printf("ENTER THE DATA FOR %d NODE : ", i);
        scanf("%d", &newnode->ph);

        if (start == NULL)
        {
            start = temp = newnode;
        }
        else
        {
            temp->ptr = newnode;
            temp = newnode;
        }
    }

    do
    {
        printf("----------------------------------------------------------------");
        printf("\n\n------MENU------\n1. INSERT BY VALUE\n2. INSERT BY POSITION\n3. DELETE BY VALUE\n4. DELETE BY POSITION\n5. FIND MIN MAX\n6. SEARCH\n7. Reverse\n8. MERGE TWO LISTS\n\nCHOOSE AN OPTION(1-7) : ");
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
            delete_val();
            break;
        case 4:
            delete_pos();
            break;
        case 5:
            min_max();
            break;
        case 6:
            search();
            break;
        case 7:
            reverse();
            break;
        case 8:
            create2();
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
    while (temp != NULL)
    {
        printf("NODE %d DATA IS : %d\n", i++, temp->ph);
        temp = temp->ptr;
    }
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
    newnode->ph = val;
    if (start == NULL)
    {
        start = newnode;
        newnode->ptr = NULL;
    }
    else
    {
        if (pos == 1)
        {
            newnode->ptr = start;
            start = newnode;
        }
        else
        {
            int i = 2;
            while (i++ < pos && temp->ptr != NULL)
            {
                temp = temp->ptr;
            }
            newnode->ptr = temp->ptr;
            temp->ptr = newnode;
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
    newnode->ph = val;
    newnode->ptr = NULL;
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        if ((start->ph) < start->ptr->ph)
        {
            if ((start->ph) > val)
            {
                newnode->ptr = start;
                start = newnode;
            }
            else
            {
                while (temp->ptr != NULL)
                {
                    if ((temp->ph) <= val && ((temp->ptr->ph) >= val))
                    {
                        break;
                    }
                    else
                    {
                        temp = temp->ptr;
                    }
                }
                newnode->ptr = temp->ptr;
                temp->ptr = newnode;
            }
        }
        else
        {
            if ((start->ph) < val)
            {
                newnode->ptr = start;
                start = newnode;
            }
            else
            {
                while (temp->ptr != NULL)
                {
                    if ((temp->ph) >= val && ((temp->ptr->ph) <= val))
                    {
                        break;
                    }
                    else
                    {
                        temp = temp->ptr;
                    }
                }
                newnode->ptr = temp->ptr;
                temp->ptr = newnode;
            }
        }
    }
    print();
}
void delete_pos()
{
    int pos;
    printf("ENTER THE POSITION OF THE NODE TO BE DELETED :");
    scanf("%d", &pos);

    prev = start;
    temp = start->ptr;
    if (start == NULL)
    {
        printf("LINKED LIST IS EMPTY ");
    }
    else
    {
        if (pos == 1)
        {
            start = temp;
            free(prev);
        }
        else
        {
            int i = 2;
            while (i++ < pos && temp->ptr != NULL)
            {
                prev = temp;
                temp = temp->ptr;
            }
            prev->ptr = temp->ptr;
            free(temp);
        }
    }
    print();
}

void delete_val()
{
    int val;
    prev = start;
    temp = start->ptr;
    printf("ENTER THE POSITION OF THE NODE TO BE DELETED :");
    scanf("%d", &val);

    if (start == NULL)
    {
        printf("LINKED LIST IS EMPTY ");
    }
    else
    {
        if (start->ph == val)
        {
            start = start->ptr;
            free(prev);
        }
        else
        {
            while ((temp->ph) != val && temp->ptr != NULL)
            {
                prev = temp;
                temp = temp->ptr;
            }
            if (temp->ptr == NULL && temp->ph != val)
            {
                printf("\nSORRY , ELEMENT WAS NOT FOUND\n\n");
                return;
            }
            else
            {
                prev->ptr = temp->ptr;
                free(temp);
            }
        }
    }
    print();
}
void min_max()
{
    temp = start;
    int max = start->ph, min = max;
    while (temp != NULL)
    {
        if ((temp->ph) > max)
        {
            max = temp->ph;
        }
        if ((temp->ph) < min)
        {
            min = temp->ph;
        }
        temp = temp->ptr;
    }
    printf("MIN IS %d , MAX IS %d", min, max);
}
void search()
{
    int val, i = 1, flag = 0;
    temp = start;

    printf("ENTER THE VALUE TO BE SEARCHED :");
    scanf("%d", &val);

    while (temp != NULL)
    {
        if (temp->ph == val)
        {
            printf("\n\nTHE VALUE %d is FOUND AT NODE  %d ", val, i);
            flag = 1;
        }
        i++;
        temp = temp->ptr;
    }
    if (flag == 0)
    {
        printf("\n\nSEARCH WAS UNSUCCESSFUL, %d WAS NOT FOUND IN THE LINKED LIST \n\n", val);
    }
}
void reverse()
{
    prev = NULL;
    temp = start;

    while (temp != NULL)
    {
        next = temp->ptr;
        temp->ptr = prev;
        prev = temp;
        temp = next;
    }
    start = prev;
    print();
}
void create2()
{
    int n, choice;
    char ch;

    printf("ENTER NO OF NODES : ");
    scanf("%d", &n);
    start2 = NULL;
    for (int i = 1; i <= n; i++)
    {

        newnode = (struct NODE *)malloc(sizeof(struct NODE));
        newnode->ptr = NULL;
        printf("ENTER THE DATA FOR %d NODE : ", i);
        scanf("%d", &newnode->ph);

        if (start2 == NULL)
        {
            start2 = temp = newnode;
        }
        else
        {
            temp->ptr = newnode;
            temp = newnode;
        }
    }
    temp->ptr = NULL;
    temp = start;
    while (temp->ptr != NULL)
    {
        temp = temp->ptr;
    }
    temp->ptr = start2;
    printf("ELEMENTS OF MERGED LIST ARE ");
    print();
}