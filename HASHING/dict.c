#include <stdio.h>
#include <stdlib.h>

struct dict
{
    int key;
    int val;
    struct dict *ptr;
};
void insert(int, int);
void print();
struct dict *start = NULL, *newnode, *temp;
int main()
{
    int key, value;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("enter key value : ");
        scanf("%d %d", &key, &value);
        insert(key, value);
    }
    print();
    return 0;
}
void insert(int key, int value)
{
    newnode = (struct dict *)malloc(sizeof(struct dict));
    newnode->key = key;
    newnode->val = value;
    newnode->ptr = NULL;

    if (start == NULL)
    {
        start = newnode;
    }
    else if (start->ptr == NULL)
    {
        if (key > start->key)
        {

            newnode->ptr = start;
            start = newnode;
        }
        else
        {
            start->ptr = newnode;
        }
    }
    else
    {
        temp = start;
        while (temp->ptr->key >= key && temp->ptr != NULL)
        {
            temp = temp->ptr;
        }
        if (temp->ptr == NULL)
        {
            temp->ptr = newnode;
        }
        else
        {
            newnode->ptr = temp->ptr;
            temp->ptr = newnode;
        }
    }
}

void print(){
    temp=start;
    while(temp->ptr!=NULL){
        printf("%d %d\n",temp->key,temp->val);
    }
}