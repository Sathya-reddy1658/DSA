#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct NODE
{
    int key;
    char value[100];
    struct NODE *ptr;
};
struct NODE *newnode, *temp, *start = NULL;
void insert();
void search();
void print();

int main()
{
    int val;
    do
    {
        int choice;
        printf("CHOOSE A FUNCTION :\n1. INSERT \n2. SEARCH \n3. PRINT");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(); break;
        case 2:
            search(); break;
        case 3:
            print(); break;
        default:
            printf("INVALID CHOICE  ");
        }
        printf("ENTER 1 TO CONTINUE , 0 TO EXIT \n");
        scanf("%d",&val);
    } while (val == 1);
}
void insert()
{
    newnode = (struct NODE *)malloc(sizeof(struct NODE));
    printf("ENTER KEY AND VALUE FOR THE ELEMENT : ");
    scanf("%d %s", &newnode->key, newnode->value);
    newnode->ptr = NULL;
    if (start == NULL)
    {
        start = temp = newnode;
    }
    else
    {
        if (start->ptr == NULL && start->key > newnode->key)
        {
            newnode->ptr = start;
            start = newnode;
        }
        else
        {
            while (temp->ptr != NULL)
            {
                if (temp->key <= newnode->key && temp->ptr->key >= newnode->key)
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
void search()
{
    int key;
    int i = 0;
    temp = start;
    printf("KEY TO BE SEARCHED : ");
    scanf("%d", &key);

    while (temp != NULL)
    {
        i++;
        if (temp->key == key)
        {
            break;
        }
        temp = temp->ptr;
    }
    if (temp != NULL)
    {
        printf("ELEMENT WITH KEY %d FOUND AT NODE %d WITH VALUE %S \n\n", key, i, temp->value);
    }
    else
    {
        printf("SEARCH UNSUCCESSFUL , NO ELEMENT WITH KEY %d WAS FOUND", key);
    }
}
void print()
{
    int i = 0;
    while (temp != NULL)
    {
        i++;
        printf("ELEMENT %d : KEY is %d , VALUE IS %s\n", i, temp->key, temp->value);
        temp = temp->ptr;
    }
}