#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *lptr;
    struct node *rptr;
}node;

void create();
void insert_pos();
void insert_val();
void display();
void search();
void delete_pos();
void delete_val();

node *start = NULL,*temp;
int n = 0;

int main()
{
    int value;
    char ch;
    do
    {
        printf("Operations available:\n1 - Create\n2 - Insert by Position\n3 - Insert by value\n4 - Print\n5 - Search\n6 - Delete By Position\n7 - Delete By Value\n8 - Exit\n");
        printf("Enter your choice:");
        scanf("%d", &value);
        switch(value)
        {
            case 1:
                create();
                break;
            case 2:
                insert_pos();
                break;
            case 3:
                insert_val();
                break;
            case 4:
                display();
                break;
            case 5:
                search();
                break;
            case 6:
                delete_pos();
                break;
            case 7:
                delete_val();
                break;
            case 8:
                return 1 ;
            default:
                printf("Invalid Choice!\n");
        }
        printf("Would you like to continue(Y/N)?:\n");
        scanf("%s", &ch);
    } while (ch=='y'||ch=='Y');

    return 0;
}

void create()
{
    node *newnode, *temp=start;
    int value;
    newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Memory not allocated!\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        if(start == NULL)
        {
            start = newnode;
            newnode->lptr = start;
            newnode->rptr = start;
        }
        else
        {
            while(temp->rptr!=start)
            {
                temp = temp->rptr;
            }
            temp->rptr = newnode;
            newnode->lptr = temp;
            newnode->rptr = start;
        }
    }
}
void insert_pos()
{
    int value, pos, i=2;
    node *newnode, *temp=start;
    newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Memory not allocated!\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        if(start == NULL)
        {
            start = newnode;
            newnode->lptr = start;
            newnode->rptr = start;
        }
        else
        {
            printf("Enter position: ");
            scanf("%d", &pos);
            if(pos == 1)
            {
                newnode->lptr = start->lptr;
                newnode->rptr = start;
                start->lptr->rptr = newnode;
                start->lptr = newnode;
                start = newnode;
            }
            else
            {
                while(i<pos && temp->rptr!=start)
                {
                    temp = temp->rptr;
                    i++;
                }
                newnode->lptr = temp;
                newnode->rptr = temp->rptr;
                temp->rptr->lptr = newnode;
                temp->rptr = newnode;
            }
        }
    }
}

void insert_val()
{
    int value;
    node *newnode, *temp=start;
    newnode = (node*)malloc(sizeof(node));
    if(newnode == NULL)
    {
        printf("Memory not allocated!\n");
    }
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);
        newnode->data = value;
        newnode->lptr = NULL;
        newnode->rptr = NULL;
        if(start == NULL)
        {
            start = newnode;
            newnode->lptr = start;
            newnode->rptr = start;
        }
        else
        {
            if(start->data >= value)
            {
                newnode->lptr = start->lptr;
                newnode->rptr = start;
                start->lptr->rptr = newnode;
                start->lptr = newnode;
                start = newnode;
            }
            else
            {
                while(temp->rptr!=start)
                {
                    if(temp->data >= value && temp->rptr->data <= value)
                    {
                        break;
                    }
                    temp = temp->rptr;
                }
                newnode->lptr = temp;
                newnode->rptr = temp->rptr;
                temp->rptr->lptr = newnode;
                temp->rptr = newnode;
            }
        }
    }
}

void display()
{
    temp = start;
    printf("The values are: \n");

    
   do
    {
        printf("%d\t", temp->data);
        temp = temp->rptr;
    } while (temp!=start);
    printf("\n");
}

void search()
{
    return;
}

void delete_pos()
{
    int pos, i = 1;
    node *temp = start;

    if (start == NULL)
    {
        printf("DCLL is empty");
    }
    else
    {
        printf("Enter position to delete: ");
        scanf("%d", &pos);

        if (pos == 1)
        {
            if (start->rptr == start)
            {
                free(temp);
                start = NULL;
            }
            else
            {
                start->lptr->rptr = start->rptr;
                start->rptr->lptr = start->lptr;
                temp = start;
                start = start->rptr;
                free(temp);
            }
        }
        else
        {
            while (i < pos && temp->rptr != start)
            {
                temp = temp->rptr;
                i++;
            }
            temp->lptr->rptr = temp->rptr;
            temp->rptr->lptr = temp->lptr;
            free(temp);
        }
    }
}

void delete_val()
{
    int value;
    node *temp = start;
    if(start == NULL)
    {
        printf("Circular DLL is empty\n");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &value);
        if(start->data == value)
        {
           if(start->rptr == start)
            {
                free(temp);
                start = NULL;
            }
            else
            {
                start->lptr->rptr = start->rptr;
                start->rptr->lptr = start->lptr;
                start = start->rptr;
                free(temp);
            } 
        }
        else
        {
            do
            {
                if(temp->data == value)
                {
                    temp->lptr->rptr = temp->rptr;
                    temp->rptr->lptr = temp->lptr;
                    free(temp);
                    break;   
                }
                temp = temp->rptr;
            }while(temp!=start);
        }
    }
}
