#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *lptr;
    struct node *rptr;
} node;

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int height(node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->lptr), height(root->rptr));
}
int isAVLTree(node *root)
{
    if (root == NULL)
        return 1;

    int left_height = height(root->lptr);
    int right_height = height(root->rptr);

    if (abs(left_height - right_height) <= 1 && isAVLTree(root->lptr) && isAVLTree(root->rptr))
        return 1;

    return 0;
}

node *newnode(int key)
{
    node *newtemp = (node *)malloc(sizeof(node));
    newtemp->key = key;
    newtemp->lptr = newtemp->rptr = NULL;
    return newtemp;
}

int countLeafNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->lptr == NULL && root->rptr == NULL)
    {
        return 1;
    }
    return countLeafNodes(root->lptr) + countLeafNodes(root->rptr);
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return newnode(key);
    }
    if (key < root->key)
    {
        root->lptr = insert(root->lptr, key);
    }
    else if (key > root->key)
    {
        root->rptr = insert(root->rptr, key);
    }
    return root;
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->lptr);
        printf("%d ", root->key);
        inorder(root->rptr);
    }
}

int main()
{
    node *root = NULL;
    int ch, key;
    char ch2;
    do
    {
        printf("1. Insert\n");
        printf("2. Check if Tree is AVL\n");
        printf("3. Inorder Traversal\n");
        printf("4. Find Height of tree\n");
        printf("5. Count Leaf nodes of tree\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            if (isAVLTree(root))
            {
                printf("Given Tree is AVL tree!\n");
            }
            else
            {
                printf("Given tree is not AVL tree\n");
            }
            break;
        case 3:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 4:
            printf("The height of the tree is: %d\n", height(root));
            break;
        case 5:
            int ln = countLeafNodes(root);
            printf("Number of leaf nodes: %d", ln);
            break;
        case 6:
            printf("Terminated\n");
            return 0;
        default:
            printf("Invalid choice\n");
        }
        printf("Would you like to continue?(Y/N):\n");
        scanf("%s", &ch2);
    } while (ch == 'Y' || ch2 == 'y');
    return 1;
}