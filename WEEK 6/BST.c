#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *temp = NULL, *root = NULL, *newnode;
struct node *insert(struct node *root, int key);
struct node *delete(struct node *root, int key);
void inorder(struct node *root);
void postorder(struct node *root);
void preorder(struct node *root);

int key;
int main()
{
    int choice, val;
    do
    {
        printf("SELECT ANY OPERTAION : \n1. INSERT\n2. DELETE\n3. INORDER\n4. POSTORDER\n5. PREORDER\nchoose : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter key to insert : ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("enter key to delete : ");
            scanf("%d", &key);
            root = delete (root, key);
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            preorder(root);
            break;
        default:
            printf("invlaid choice");
        }
        printf("\ndo you want to continue (1 for YES ,2 for NO): ");
        scanf("%d", &val);
    } while (val == 1);
}

struct node *Newnode(int n)
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return Newnode(key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    return root;
}

void inorder(struct node *root)
{
    while (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    while (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}
void preorder(struct node *root)
{
    while (root != NULL)
    {
        printf("%d", root->left);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node *minvalue(struct node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else if (key > root->data)
    {
        return search(root->right, key);
    }
}

struct node *delete(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else
    {
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        temp = minvalue(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}
