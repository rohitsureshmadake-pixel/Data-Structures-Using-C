/*
Practical No. 17 and 18
Title: Implement Binary Search Tree (BST), Search a Node, and Perform
       Inorder, Preorder, and Postorder Traversals.

Exercise:
1. Construct a BST and search for a node.
2. Perform Inorder, Preorder, and Postorder traversals.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate value %d ignored.\n", value);

    return root;
}

struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    struct Node *root = NULL;
    struct Node *found;
    int n, value, key, i;

    printf("Enter number of nodes: ");
    if (scanf("%d", &n) != 1 || n < 0)
    {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        if (scanf("%d", &value) != 1)
        {
            printf("Invalid input.\n");
            freeTree(root);
            return 1;
        }
        root = insert(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter value to search: ");
    if (scanf("%d", &key) != 1)
    {
        printf("Invalid input.\n");
        freeTree(root);
        return 1;
    }

    found = search(root, key);

    if (found != NULL)
        printf("%d found in the BST.\n", key);
    else
        printf("%d not found in the BST.\n", key);

    freeTree(root);
    return 0;
}

/*
Sample Output:
Enter number of nodes: 7
Enter value 1: 50
Enter value 2: 30
Enter value 3: 70
Enter value 4: 20
Enter value 5: 40
Enter value 6: 60
Enter value 7: 80

Inorder Traversal: 20 30 40 50 60 70 80
Preorder Traversal: 50 30 20 40 70 60 80
Postorder Traversal: 20 40 30 60 80 70 50

Enter value to search: 60
60 found in the BST.

Time Complexity:
Insert/Search: O(h), where h is the height of the tree.
Each traversal: O(n), where n is the number of nodes.
*/
