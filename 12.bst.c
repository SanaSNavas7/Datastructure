#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

int display();
void insert();
void delete();
int search();
void inorder();
void preorder();
void postorder();

void main()
{
    while (1)
    {
        int choice;
        printf("___Enter___\n 1.display\n 2.insert\n 3 to delete\n 4. search \n 5 .exit\n ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
        default:
            printf("invalid choice");
            
        }
    }
}

struct node *insertion(struct node *root, struct node *newnode)
{
    if (root == NULL)
    {
        root = newnode;
    }
    else if (root->data < newnode->data)
    {
        root->right = insertion(root->right, newnode);
    }
    else
    {
        root->left = insertion(root->left, newnode);
    }
    return root;
}
void insert()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter element to insert :");
    scanf("%d", &newnode->data);
    newnode->left = newnode->right = NULL;
    root = insertion(root, newnode);
}

struct node *find_min(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
struct node *temp;
struct node *deletion(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("Tree is empty");
    }
    if (value < root->data)
    {
        root->left = deletion(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deletion(root->right, value);
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
        else
        {
            root->data = find_min(root->right)->data;

            root->right = deletion(root->right, root->data);
        }
    }
}
void delete()
{
    int value;
    printf("enter data to delete :");
    scanf("%d", &value);
    root = deletion(root, value);
    display();
}

int display()
{
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("preorder: ");
    preorder(root);
    printf("\n");
    printf("postorder: ");
    postorder(root);
    printf("\n");
}
void inorder(struct node *root)
{
    if (root == NULL)
    {

        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root == NULL)
    {

        return;
    }
    else
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root == NULL)
    {

        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search() {
    int value;
    printf("Enter the value to search for: ");
    scanf("%d", &value);

    struct node *current = root;
    while (current != NULL) {
        if (current->data == value) {
            printf("Element %d found in the tree.\n", value);
            return 1; 
        } else if (value < current->data) {
            current = current->left; 
        } else {
            current = current->right;  
        }
    }
    printf("Element %d not found in the tree.\n", value);
}
