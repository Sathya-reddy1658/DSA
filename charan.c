#include <stdio.h>
#include <stdlib.h>

struct NODE
{ 
    int data;
    struct NODE *link;
};
struct NODE *start = NULL, *temp , *newnode, *prev;

void create();
void print();
void insert_pos();
void insert_val_asc();
void insert_val_desc();
void delete_pos();
void delete_val();
void min_max();
void reverse();

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
        newnode->link = NULL;
        printf("ENTER THE DATA FOR %d NODE : ", i);
        scanf("%d", &newnode->data);

        if (start == NULL)
        {
            start = temp = newnode;
        }
        else
        {
            temp->link = newnode;
            temp = newnode;
        }
    }

    do
    {
        printf("----------------------------------------------------------------");
        printf("\n\n------MENU------\n1. INSERT BY VALUE (ASCENDING)\n2. INSERT BY VALUE (DESCENDING)\n3. INSERT BY POSITION\n4. DELETE BY VALUE\n5. DELETE BY POSITION\n6. FIND MIN MAX \n7.REVERSE THE LL\n\nCHOOSE AN OPTION(1-7) : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_val_asc();
            break;
        case 2:
            insert_val_desc();
            break;
        case 3:
            insert_pos();
            break;
        case 4:
            delete_val();
            break;
        case 5:
            delete_pos();
            break;
        case 6:
            min_max();
            break;
        case 7:
            reverse();
            break;
        default:
            printf("INVALID OPTION CHOOSEN!!");
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
        printf("NODE %d DATA IS : %d\n", i++, temp->data);
        temp = temp->link;
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
    newnode->data = val;
    newnode->link = NULL;
    if (start == NULL)
    {
        start = newnode;

    }
    else
    {
        if ( pos == 1 )
        {
            newnode->link = start;
            start = newnode;
        }
        else
        {
            int i = 2;
            while (i++ < pos && temp->link != NULL)
            {
                temp = temp->link;
            }
            newnode->link = temp->link;
            temp->link = newnode;
        }
    }
    print();
}
void insert_val_asc()
{
    int val;
    printf("ENTER THE VALUE OF THE NODE TO BE INSERTED ('BY-VALUE'): ");
    scanf("%d", &val);

    newnode = (struct NODE *)malloc(sizeof(struct NODE));
    if (newnode == NULL)
     {
        printf("Memory allocation failed");
        return;
    }
    newnode->data = val;
    newnode->link = NULL;

    if (start == NULL || val < start->data) 
    {
        newnode->link = start;
        start = newnode;  
    }
    else {
        temp = start;
        while (temp->link != NULL && temp->link->data < val) 
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;  
    }
    print();
}
void insert_val_desc()
{
    int val;
    printf("ENTER THE VALUE OF THE NODE TO BE INSERTED ('BY-VALUE'): ");
    scanf("%d", &val);

    newnode = (struct NODE *)malloc(sizeof(struct NODE));
    if (newnode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    newnode->data = val;
    newnode->link = NULL;

    if (start == NULL || val > start->data)
    {
        newnode->link = start;
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->link != NULL && temp->link->data > val)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    print();
}

void delete_pos()
{
    int pos;
    printf("ENTER THE POSITION OF THE NODE TO BE DELETED :");
    scanf("%d", &pos);

    prev = start;
    temp = start->link;
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
            while (i++ < pos && temp->link != NULL)
            {
                prev = temp;
                temp = temp->link;
            }
            prev->link = temp->link;
            free(temp);
        }
    }
    print();
}

void delete_val()
{
    int val;
    printf("ENTER THE VALUE OF THE NODE TO BE DELETED: ");
    scanf("%d", &val);

    if (start == NULL)
    {
        printf("LINKED LIST IS EMPTY\n");
        return;
    }

    temp = start;
    if (temp->data == val)
    {
        start = start->link;
        free(temp);
        printf("Node with value %d deleted successfully\n", val);
        return;
    }

    prev = temp;
    temp = temp->link;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            prev->link = temp->link;
            free(temp);
            printf("Node with value %d deleted successfully\n", val);
            print();
            return;
        }
        prev = temp;
        temp = temp->link;
    }

    printf("Node with value %d not found in the list\n", val);
    print();
}
void min_max()
{
    temp = start;
    int max = start->data, min = max;
    while (temp != NULL)
    {
        if ((temp->data) > max)
        {
            max = temp->data;
        }
        if ((temp->data) < min)
        {
            min = temp->data;
        }
        temp = temp->link;
    }
    printf("MIN IS %d , MAX IS %d", min, max);
}
void reverse()
{
    
}