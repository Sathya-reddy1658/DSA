#include <stdio.h>
#include <stdlib.h>

struct cir_sing
{
    int data;
    struct cir_sing *ptr;
};
void create();
void insert_pos();
void insert_val();
void delete_pos();
void delete_val();
void print();
void search();
void merge();
struct cir_sing *newnode, *start, *temp, *prev, *start2, *temp2;
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
        newnode = (struct cir_sing *)malloc(sizeof(struct cir_sing));
        newnode->ptr = NULL;
        printf("ENTER THE DATA FOR %d NODE : ", i);
        scanf("%d", &newnode->data);

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
    temp->ptr = start;

    do
    {
        printf("----------------------------------------------------------------");
        printf("\n\n------MENU------\n1. INSERT BY VALUE\n2. INSERT BY POSITION\n3. DELETE BY POSITION\n4. DELETE BY VALUE\n5. SEARCH\n6. MERGE 2 LISTS\n\nCHOOSE AN OPTION(1-5) : ");
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
            search();
            break;
        case 6:
            merge();
            break;
        default:
            printf("INVALID OPTINO CHOOSEN!!");
        }
        printf("\n\nWOULD YOU LIKE TO CONTINUE (Y for YES , N for NO ) :\n\n");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'Y');
}
void insert_pos()
{
    int pos, i = 2;
    temp = start;
    printf("ENTER POSITION FOR THE NODE TO BE INSERTED : ");
    scanf("%d", &pos);
    printf("ENTER DATA OF THE NODE : ");
    newnode = (struct cir_sing *)malloc(sizeof(struct cir_sing));
    scanf("%d", &newnode->data);

    if (start == NULL)
    {
        start = newnode;
        newnode->ptr = start;
    }

    else
    {
        if (pos == 1)
        {

            while (temp->ptr != start)
            {
                temp = temp->ptr;
            }
            temp->ptr = newnode;
            newnode->ptr = start;
            start = newnode;
        }
        else
        {
            while (i++ < pos && temp->ptr != start)
            {
                temp = temp->ptr;
            }
            newnode->ptr = temp->ptr;
            temp->ptr = newnode;
        }
    }
    print();
}
void print()
{
    temp = start;
    int i = 1;

    if (start == NULL)
    {
        printf("LINKED LIST IS EMPTY");
    }
    else
    {
        printf("ELEMENTS OF LINKED LIST ARE : \n");
        while (temp->ptr != start)
        {
            printf(" NODE %d IS %d\n", i++, temp->data);
            temp = temp->ptr;
        }
        printf(" NODE %d IS %d\n", i++, temp->data);
    }
}
void insert_val()
{
    int val;
    newnode = (struct cir_sing *)malloc(sizeof(struct cir_sing));
    printf("ENTER VALUE FOR THE NEWNODE TO BE INSERTED : ");
    scanf("%d", &val);
    newnode->data = val;

    temp = start;
    if (temp->data < temp->ptr->data)
    {
        if (val < temp->data)
        {

            while (temp->ptr != start)
            {
                temp = temp->ptr;
            }
            temp->ptr = newnode;
            newnode->ptr = start;
            start = newnode;
        }
        else
        {

            while (temp->ptr != start)
            {
                if (val > temp->data && val < temp->ptr->data)
                {
                    break;
                }

                temp = temp->ptr;
            }

            newnode->ptr = temp->ptr;
            temp->ptr = newnode;
        }
    }
    else
    {
        {
            if (val > temp->data)
            {

                while (temp->ptr != start)
                {
                    temp = temp->ptr;
                }
                temp->ptr = newnode;
                newnode->ptr = start;
                start = newnode;
            }
            else
            {

                while (temp->ptr != start)
                {
                    if (val <= temp->data && val > temp->ptr->data)
                    {
                        break;
                    }

                    temp = temp->ptr;
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
    int i = 2;
    temp = start;
    int pos;
    printf("ENTER POSITION OF THE NODE TO BE DELETED : ");
    scanf("%d", &pos);
    if (start == NULL)
    {

        printf("LINKED LIST IS EMPTY ");
    }
    else
    {

        if (pos == 1)
        {
            if (start->ptr == start)
            {
                start = NULL;
                free(temp);
            }
            else
            {
                while (temp->ptr != start)
                {
                    temp = temp->ptr;
                }
                prev = start;
                temp->ptr = start->ptr;
                start = start->ptr;
                free(prev);
            }
        }
        else
        {
            while (i++ < pos && temp->ptr != start)
            {
                temp = temp->ptr;
            }
            prev = temp->ptr;
            temp->ptr = temp->ptr->ptr;
            free(prev);
        }
    }
    print();
}
void delete_val()
{

    int val;
    prev = start;
    temp = start->ptr;
    printf("ENTER THE VALUE OF THE NODE TO BE  DELETED :");
    scanf("%d", &val);

    if (start == NULL)
    {
        printf("LINKED LIST IS EMPTY ");
    }
    else
    {

        if (start->data == val)
        {
            if (start->ptr == start)
            {
                start = NULL;
                free(temp);
            }
            else
            {
                while (temp->ptr != start)
                {
                    temp = temp->ptr;
                }
                temp->ptr = start->ptr;
                start = start->ptr;
                free(prev);
            }
        }

        else
        {
            while ((temp->data) != val && temp->ptr != start)
            {
                prev = temp;
                temp = temp->ptr;
            }
            if (temp->ptr == start && temp->data != val)
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
void search()
{
    int val, i = 1, flag = 0;
    printf("ENTER THE VALUE TO BE SEARCHED ");
    scanf("%d", &val);
    temp = start;
    do
    {
        if (temp->data == val)
        {
            printf("VALUE %d FOUND AT NODE %d ", val, i);
            flag = 1;
        }
        temp = temp->ptr;
        i++;
    } while (temp != start);

    if (!flag)
    {
        printf("\nSORRY , ELEMENT WAS NOT FOUND\n\n");
    }
}
void merge()
{
    int n;
    printf("ENTER NO OF NODES FOR THE NEW LIST : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        newnode = (struct cir_sing *)malloc(sizeof(struct cir_sing));
        newnode->ptr = NULL;

        printf("ENTER THE DATA FOR %d NODE : ", i);
        scanf("%d", &newnode->data);

        if (start2 == NULL)
        {
            start2 = temp2 = newnode;
            temp2->ptr = start2;
        }
        else
        {
            newnode->ptr = start;
            temp2->ptr = newnode;
            temp2 = newnode;
        }
    }
    temp2->ptr = start;
    while (temp->ptr != start)
    {
        temp = temp->ptr;
    }
    temp->ptr = start2;
    print();
}