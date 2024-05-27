#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node*lptr;
    struct node*rptr;
}node;

node* createnode(int key);
node* preSuc(node* root);
node* insertTree(node* root, int key);
node* deleteTree(node* root, int  key);
node* searchTree(node* root, int key);
void preorder(node* root);
void inorder(node* root);
void postorder(node* root);
int isAVLTree(node* root);
int max(int a, int b);
int height(node* root);
int getBalanceFactor(node *root);
node* LL(node* y);
node* RR(node* y);




int  main()
{
    node* root = NULL;
    int choice, key;
    char ch;
    do
    {
        printf("Operations on BST: \n");
        printf("1 - Insert\n2 - Delete\n3 - Search\n4 - Inorder Traversal\n5 - Preorder Traversal\n6 - Postorder Traversal\n7 - isAVL or not?\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the key: ");
                scanf("%d", &key);
                root = insertTree(root, key);
                break;
            case 2:
                printf("Enter the key: ");
                scanf("%d", &key);
                root = deleteTree(root, key);
                break;
            case 3:
                printf("Enter the key: ");
                scanf("%d", &key);
                node *temp = searchTree(root, key);
                if(temp==NULL)
                {
                    printf("Key not found!\n");
                }
                else
                {
                    printf("%d is found!\n", key);
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 7:
                if(isAVLTree(root))
                {
                    printf("Given BST is an AVL Tree!\n");
                }
                else
                {
                    printf("Given BST is not an AVL Tree!\n");
                }
                break;
            case 8:
                printf("Program Terminated!\n");
                return 0;
            default:
                printf("Invalid Choice!\n");
        }
        printf("Would you like to continue?(Y/N): \n");
        scanf("%s", &ch);
    }while(ch=='Y'||ch=='y');
}

node* createnode(int key)
{
    node *newtemp = (node*)malloc(sizeof(node));
    newtemp->key = key;
    newtemp->lptr = newtemp->rptr = NULL;
    return newtemp;
}

node* preSuc(node* root)
{
    while(root->lptr!=NULL)
    {
        root = root->lptr;
    }
    return root;
}

node* insertTree(node* root, int key)
{
    if(root == NULL)
    {
        return createnode(key);
    }
    else if(key<root->key)
    {
        root->lptr = insertTree(root->lptr, key);
    }
    else if(key>root->key)
    {
        root->rptr = insertTree(root->rptr, key);
    }
    
    int bf = getBalanceFactor(root);
    if(bf>1 && key<root->lptr->key)
    {
        return RR(root);
    }
    if(bf<-1 && key>root->rptr->key)
    {
        return LL(root);
    }
    if(bf>1&&key>root->lptr->key)
    {
        root->lptr = LL(root->lptr);
        return RR(root);
    }
    if(bf<-1 && key<root->rptr->key)
    {
        root->rptr = RR(root->rptr);
        return LL(root);
    }

    return root;

}

node* deleteTree(node* root, int  key)
{
    if(root == NULL)
    {
        return root;
    }
    
    if(key<root->key)
    {
        root->lptr = deleteTree(root->lptr, key);
    }
    else if(key>root->key)
    {
        root->rptr = deleteTree(root->rptr, key);
    }
    else
    {
        if(root->lptr==NULL)
        {
            node* temp = root->rptr;
            free(root);
            return temp;
        }
        else if(root->rptr == NULL)
        {
            node* temp = root->lptr;
            free(root);
            return  temp;
        }
        node *temp = preSuc(root->rptr);
        root->key = temp->key;
        root->rptr = deleteTree(root->rptr, temp->key);
    }

    int bf = getBalanceFactor(root);
    if(bf>1 && getBalanceFactor(root->lptr)>=0)
    {
        return RR(root);
    }
    if(bf<-1 && getBalanceFactor(root->rptr)<=0)
    {
        return LL(root);
    }
    if(bf>1&& getBalanceFactor(root->lptr)<0)
    {
        root->lptr = LL(root->lptr);
        return RR(root);
    }
    if(bf<-1 && getBalanceFactor(root->rptr)>0)
    {
        root->rptr = RR(root->rptr);
        return LL(root);
    }
    return root;
}

node* searchTree(node* root, int key)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->key == key)
    {
        return root;
    }
    else if(key<root->key)
    {
        searchTree(root->lptr, key);
    }
    else if(key>root->key)
    {
        searchTree(root->rptr, key);
    }
}

void preorder(node* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->key);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}
void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->lptr);
        printf("%d ", root->key);
        inorder(root->rptr);
    }
}

void postorder(node* root)
{
    if(root!=NULL)
    {
        postorder(root->lptr);
        postorder(root->rptr);
        printf("%d ", root->key);
    }
}

int isAVLTree(node* root)
{
    if(root == NULL)
    {
        return 1;
    }
    int leftHt = height(root->lptr);
    int rightHt = height(root->rptr);

    if(abs(leftHt-rightHt)<=1 && isAVLTree(root->lptr) && isAVLTree(root->rptr))
    {
        return 1;
    }
    return 0;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

int height(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1 + max(height(root->lptr), height(root->rptr));
}

int countleaf(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->lptr == NULL && root->rptr == NULL)
    {
        return 1;
    }
    return countleaf(root->lptr)+countleaf(root->rptr);
}

int getBalanceFactor(node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return (height(root->lptr)-height(root->rptr));
    }
}

node* RR(node* y)
{
    node* x = y->lptr; 
    node* z = x->rptr;
    x->rptr = y;
    y->lptr = z;
    return x;
}

node* LL(node* y)
{
    node* x = y->rptr;
    node* z = x->lptr;
    x->lptr = y;
    y->rptr = z;
    return x;
}
