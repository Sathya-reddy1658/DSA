#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *lptr;
    struct node *rptr;
}node;

node* insert(node* root, int key);
node *delete(node *root,int key);
node* search(node* root, int key);
void inorder(node *root);
void preorder(node *root);
void postorder(node *root);
node* minvalue(node *node);

int main()
{
    node *root = NULL;
    int ch,key;
    char ch2;
    do
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d",&key);
                root=insert(root,key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d",&key);
                root = delete(root, key);
                break;
            case 3:
                printf("Enter key to Search: ");
                scanf("%d",&key);
                node *temp = search(root,key);
                if(temp==NULL)
                    printf("Key not found!\n");
                else
                    printf("Key is found!\n");
                break;
            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                printf("Terminated\n");
                return 1;
            default:
                printf("Invalid choice\n");
        }
        printf("Would you like to continue?(Y/N):\n");
        scanf("%s", &ch2);
    }while(ch=='Y'||ch2=='y');
    return 0;
}


node *newnode(int key)
{
    node *newtemp = (node *)malloc(sizeof(node));
    newtemp->key = key;
    newtemp->lptr = newtemp->rptr = NULL;
    return newtemp;
}

node* insert(node* root, int key)
{
    if(root==NULL)
    {
        return newnode(key);
    }
    if(key<root->key)
    {
        root->lptr = insert(root->lptr, key);
    }
    else if(key>root->key)
    {
        root->rptr = insert(root->rptr, key);
    }
    return root;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->lptr);
        printf("%d ",root->key);
        inorder(root->rptr);
    }
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}

void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->lptr);
        postorder(root->rptr);
        printf("%d ",root->key);
    }
}

node* minvalue(node *node)
{
    while(node->lptr!=NULL)
    {
        node = node->lptr;
    }
    return node;
}

node *delete(node *root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(key<root->key)
    {
        root->lptr=delete(root->lptr,key);
    }
    else if(key>root->key)
    {
        root->rptr=delete(root->rptr,key);
    }
    else{
        if(root->lptr==NULL) {
            node *temp=root->rptr;
            free(root);
            return temp;
        }
        else if(root->rptr==NULL)
         {
            node *temp=root->lptr;
            free(root);
            return temp;
        }
        node *temp=minvalue(root->rptr);
        root->key=temp->key;
        root->rptr=delete(root->rptr,temp->key);
    }
    return root;
}

node* search(node* root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(key==root->key)
    {
        return root;
    }
    else if(key<root->key)
    {
        return search(root->lptr, key);
    }
    else if(key>root->key)
    {
        return search(root->rptr, key);
    }
}


