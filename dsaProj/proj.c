//Header files 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 101

// Structures
struct student
{
    int id;
    char name[30];
    char parent1[30];
    float gpa;
    float marks;
    float attendance;
    int backs;
    float feeDue;
    int section;
};

typedef struct node
{
    int key;
    int idx;
    struct node *lptr;
    struct node *rptr;
} node;

// ALL students array
struct student *allStudents[MAX];
node *root = NULL;

// ALL functions
// main-functions
void insert(struct student *stuData);
void newEntry();
void init();
void print(int idx);
int hash(int n);
void display();
int search();
void menu();
void update();
void greet();
void delete();

// tree-functions
node *createnode(int key, int idx);
node *preSuc(node *root);
node *insertTree(node *root, int key, int idx);
node *deleteTree(node *root, int key);
node *searchTree(node *root, int key);
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
int isAVLTree(node *root);
int max(int a, int b);
int height(node *root);
int getBalanceFactor(node *root);
node *LL(node *y);
node *RR(node *y);

//main-code

int main()
{
    init();
    while (1)
    {
        menu();
        printf("\n\033[1;33m| ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ |\033[0m\n");
    }
}

void menu()
{
    int choice, n;
    printf("\n\033[1;34m************************************\033[0m\n");
    printf("\033[1;34m*            \033[1;33mMAIN MENU\033[0m             \033[1;34m*\033[0m\n");
    printf("\033[1;34m************************************\033[0m\n");
    printf("\033[1;32m1. New Entry\033[0m\n");
    printf("\033[1;33m2. Update Record\033[0m\n");
    printf("\033[1;34m3. View All Records\033[0m\n");
    printf("\033[1;37m4. Search Record\033[0m\n");
    printf("\033[1;31m5. Delete Record\033[0m\n");
    printf("\033[1;35m6. Exit\033[0m\n");
    printf("\033[1;34m************************************\033[0m\n");
    printf("\033[1;36mEnter your choice: \033[0m");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
        newEntry();
        break;
    case 2:
        update();
        break;
    case 3:
        display();
        break;
    case 4:
        n = search();
        if (n != -1)
        {
            print(n);
        }
        break;
    case 5:
        delete ();
        break;
    case 6:
        greet();
        exit(0);
    default:
        printf("\033[1;31mInvalid choice! Please try again.\033[0m\n");
    }
}

void newEntry()
{
    struct student *newStu = (struct student *)malloc(sizeof(struct student));

    printf("\n*****************************************\n");
    printf("*              \033[1;32mNEW ENTRY FORM\033[0m           *\n");
    printf("*****************************************\n\n");

    printf("\033[1;34mPLEASE ENTER STUDENT ID: \033[0m");
    scanf("%d", &newStu->id);
    getchar(); // To consume the newline character left by scanf

    printf("\033[1;34mPLEASE ENTER STUDENT NAME: \033[0m");
    fgets(newStu->name, sizeof(newStu->name), stdin);
    newStu->name[strcspn(newStu->name, "\n")] = '\0';

    printf("\033[1;34mPLEASE ENTER PARENT NAME (M/F): \033[0m");
    fgets(newStu->parent1, sizeof(newStu->parent1), stdin);
    newStu->parent1[strcspn(newStu->parent1, "\n")] = '\0';

    printf("\033[1;34mPLEASE ENTER STUDENT SECTION: \033[0m");
    scanf("%d", &newStu->section);
    getchar(); // To consume the newline character left by scanf

    printf("\033[1;34mPLEASE ENTER STUDENT GPA: \033[0m");
    scanf("%f", &newStu->gpa);
    getchar(); // To consume the newline character left by scanf

    printf("\033[1;34mPLEASE ENTER STUDENT ATTENDANCE: \033[0m");
    scanf("%f", &newStu->attendance);
    getchar(); // To consume the newline character left by scanf

    printf("\033[1;34mPLEASE ENTER STUDENT BACKLOGS: \033[0m");
    scanf("%d", &newStu->backs);
    getchar(); // To consume the newline character left by scanf

    printf("\033[1;34mPLEASE ENTER FEE DUE: \033[0m");
    scanf("%f", &newStu->feeDue);
    getchar(); // To consume the newline character left by scanf

    insert(newStu);
}

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        allStudents[i] = 0;
    }
}

void insert(struct student *newStu)
{
    int idx = hash(newStu->id);
    allStudents[idx] = newStu;
    root = insertTree(root, allStudents[idx]->id, idx);
    printf("\n\033[1;32m*****************************************\033[0m\n");
    printf("\033[1;32m*\033[0m           \033[1;33mNew Student Added!\033[0m          \033[1;32m*\033[0m\n");
    printf("\033[1;32m*****************************************\033[0m\n\n");
    print(idx);
}

int hash(int n)
{
    int idx = n % MAX;
    if (allStudents[idx] == 0)
    {
        return idx;
    }
    else
    {
        int i = 1;
        while (allStudents[idx] != 0)
        {
            idx = (n % MAX + (int)pow(i, 2)) % MAX;
            i++;
        }
        return idx;
    }
}

void print(int idx)
{
    printf("\n+---------------------------------------+\n");
    printf("|          Student Information          |\n");
    printf("|---------------------------------------|\n");
    printf("| Name : %-30s |\n", allStudents[idx]->name);
    printf("| Parent Name : %-23s |\n", allStudents[idx]->parent1);
    printf("| Section : %-27d |\n", allStudents[idx]->section);
    printf("| Student Id : %-24d |\n", allStudents[idx]->id);
    printf("| GPA : %-31.2f |\n", allStudents[idx]->gpa);
    printf("| Attendance : %-24.2f |\n", allStudents[idx]->attendance);
    printf("| Backlogs : %-26d |\n", allStudents[idx]->backs);
    printf("| Fee due : %-27.2f |\n", allStudents[idx]->feeDue);
    printf("+---------------------------------------+\n");
}

void display()
{
    printf("\n####################################################################################################\n");
    printf("#                              \033[1;31m          All Student Record         \033[0m                               #\n");
    printf("####################################################################################################\n");

    printf("+--------------------------------------------------------------------------------------------------+\n");
    printf("| \033[1;36m%-15s\033[0m | \033[1;35m%-10s\033[0m | \033[1;33m%-15s\033[0m | \033[1;32m%-10s\033[0m | \033[1;34m%-10s\033[0m | \033[1;33m%-8s\033[0m | \033[1;31m%-10s\033[0m |\n", "Student Name", "ID", "Parent Name", "Attendance", "Backlogs", "GPA", "Fee-Due");
    printf("+--------------------------------------------------------------------------------------------------+\n");
    inorder(root);
    printf("+--------------------------------------------------------------------------------------------------+\n");
}

void print_partial(int i)
{
    if (allStudents[i] != NULL)
    {
        printf("| %-15s | %-10d | %-15s | %-10.2f | %-10d | %-8.3f | %-10.3f |\n", allStudents[i]->name, allStudents[i]->id, allStudents[i]->parent1, allStudents[i]->attendance, allStudents[i]->backs, allStudents[i]->gpa, allStudents[i]->feeDue);
    }
}

int search()
{
    int ID;
    printf("Please enter Student Id : ");
    scanf("%d", &ID);
    int found = 0;
    node *temp = searchTree(root, ID);
    if (temp == NULL)
    {
        printf("\n\033[1;31mInvalid Student ID!\033[0m\n");
        return -1;
    }
    else
    {
        return temp->idx;
    }
}

void update()
{
    int id = search();
    struct student *stu = allStudents[id];
    printf("\n*****************************************\n");
    printf("*            \033[1;32mUPDATE ENTRY FORM\033[0m          *\n");
    printf("*****************************************\n\n");
    fflush(stdin);
    printf("\033[1;34mPLEASE ENTER STUDENT NAME  \033[0m (%s) :", stu->name);
    fgets(stu->name, sizeof(stu->name), stdin);
    stu->name[strcspn(stu->name, "\n")] = '\0';

    printf("\033[1;34mPLEASE ENTER PARENT NAME (M/F)  \033[0m (%s) :", stu->parent1);
    fgets(stu->parent1, sizeof(stu->parent1), stdin);
    stu->parent1[strcspn(stu->parent1, "\n")] = '\0';

    printf("\033[1;34mPLEASE ENTER STUDENT SECTION  \033[0m (%d) :", stu->section);
    scanf("%d", &stu->section);
    getchar();

    printf("\033[1;34mPLEASE ENTER STUDENT GPA \033[0m  (%.2f) :", stu->gpa);
    scanf("%f", &stu->gpa);
    getchar();

    printf("\033[1;34mPLEASE ENTER STUDENT ATTENDANCE  \033[0m (%.2f) :", stu->attendance);
    scanf("%f", &stu->attendance);
    getchar();

    printf("\033[1;34mPLEASE ENTER STUDENT BACKLOGS  \033[0m (%d) :", stu->backs);
    scanf("%d", &stu->backs);
    getchar();

    printf("\033[1;34mPLEASE ENTER FEE DUE  \033[0m (%.2f) :", stu->feeDue);
    scanf("%f", &stu->feeDue);
    getchar();
    print(id);
    printf("\n\033[1;32m*****************************************\033[0m\n");
    printf("\033[1;32m*\033[0m       \033[1;33mStudent Record Updated!\033[0m         \033[1;32m*\033[0m\n");
    printf("\033[1;32m*****************************************\033[0m\n\n");
}

void greet()
{
    printf("\n\033[1;34m********************************************\033[0m\n");
    printf("\033[1;34m*\033[0m                                          \033[1;34m*\033[0m\n");
    printf("\033[1;32m*             THANK YOU!                   *\033[0m\n");
    printf("\033[1;32m*      Session endedd successfully!        *\033[0m\n");
    printf("\033[1;34m*\033[0m                                          \033[1;34m*\033[0m\n");
    printf("\033[1;34m********************************************\033[0m\n");
}

void delete()
{
    int n;
    int idx = search();
    print(idx);
    printf("\033[1;31m"); // Start red color
    printf("\nWARNING: Do you want to delete this student's record? This action cannot be undone and data cannot be retrieved!\n\n");
    printf("\033[0m"); // Reset color
    printf("Choose 1 to continue and 2 to abort : ");
    scanf("%d", &n);
    if (n == 1)
    {
        deleteTree(root, allStudents[idx]->id);
        allStudents[idx] = NULL;
        printf("\n\033[1;31mStudent Deleted Successfully.\033[0m\n");
    }
    else
    {
        printf("\n\033[1;32mAction Aborted.\033[0m\n");
    }
}

// TREE CODE(AVL)

node *createnode(int key, int idx)
{
    node *newtemp = (node *)malloc(sizeof(node));
    newtemp->key = key;
    newtemp->idx = idx;
    newtemp->lptr = newtemp->rptr = NULL;
    return newtemp;
}

node *preSuc(node *root)
{
    while (root->lptr != NULL)
    {
        root = root->lptr;
    }
    return root;
}

node *insertTree(node *root, int key, int idx)
{
    if (root == NULL)
    {
        return createnode(key, idx);
    }
    else if (key < root->key)
    {
        root->lptr = insertTree(root->lptr, key, idx);
    }
    else if (key > root->key)
    {
        root->rptr = insertTree(root->rptr, key, idx);
    }

    int bf = getBalanceFactor(root);
    if (bf > 1 && key < root->lptr->key)
    {
        return RR(root);
    }
    if (bf < -1 && key > root->rptr->key)
    {
        return LL(root);
    }
    if (bf > 1 && key > root->lptr->key)
    {
        root->lptr = LL(root->lptr);
        return RR(root);
    }
    if (bf < -1 && key < root->rptr->key)
    {
        root->rptr = RR(root->rptr);
        return LL(root);
    }

    return root;
}

node *deleteTree(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->key)
    {
        root->lptr = deleteTree(root->lptr, key);
    }
    else if (key > root->key)
    {
        root->rptr = deleteTree(root->rptr, key);
    }
    else
    {
        if (root->lptr == NULL)
        {
            node *temp = root->rptr;
            free(root);
            return temp;
        }
        else if (root->rptr == NULL)
        {
            node *temp = root->lptr;
            free(root);
            return temp;
        }
        node *temp = preSuc(root->rptr);
        root->key = temp->key;
        root->rptr = deleteTree(root->rptr, temp->key);
    }

    int bf = getBalanceFactor(root);
    if (bf > 1 && getBalanceFactor(root->lptr) >= 0)
    {
        return RR(root);
    }
    if (bf < -1 && getBalanceFactor(root->rptr) <= 0)
    {
        return LL(root);
    }
    if (bf > 1 && getBalanceFactor(root->lptr) < 0)
    {
        root->lptr = LL(root->lptr);
        return RR(root);
    }
    if (bf < -1 && getBalanceFactor(root->rptr) > 0)
    {
        root->rptr = RR(root->rptr);
        return LL(root);
    }
    return root;
}

node *searchTree(node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->key == key)
    {
        return root;
    }
    else if (key < root->key)
    {
        searchTree(root->lptr, key);
    }
    else if (key > root->key)
    {
        searchTree(root->rptr, key);
    }
}

void preorder(node *root)
{
    if (root != NULL)
    {
        print_partial(root->idx);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->lptr);
        print_partial(root->idx);
        inorder(root->rptr);
    }
}

void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->lptr);
        postorder(root->rptr);
        print_partial(root->idx);
    }
}

int isAVLTree(node *root)
{
    if (root == NULL)
    {
        return 1;
    }
    int leftHt = height(root->lptr);
    int rightHt = height(root->rptr);

    if (abs(leftHt - rightHt) <= 1 && isAVLTree(root->lptr) && isAVLTree(root->rptr))
    {
        return 1;
    }
    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->lptr), height(root->rptr));
}

int countleaf(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->lptr == NULL && root->rptr == NULL)
    {
        return 1;
    }
    return countleaf(root->lptr) + countleaf(root->rptr);
}

int getBalanceFactor(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (height(root->lptr) - height(root->rptr));
    }
}

node *RR(node *y)
{
    node *x = y->lptr;
    node *z = x->rptr;
    x->rptr = y;
    y->lptr = z;
    return x;
}

node *LL(node *y)
{
    node *x = y->rptr;
    node *z = x->lptr;
    x->lptr = y;
    y->rptr = z;
    return x;
}
