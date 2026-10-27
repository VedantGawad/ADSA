/*Read the sequence of integers.
Insert the first integer as the root.
For every subsequent integer:
- If the tree is empty, create a node.
- If the value is smaller than the current node, move left.
- If the value is larger than the current node, move right.
- Continue until an empty position is found.
Insert the new node at that position.
Repeat for all integers.*/


#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
}; 
struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        struct Node *newNode =
            (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    struct Node *root = NULL;
    int n, i, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Pre-order: ");
    preorder(root);
    printf("\nIn-order: ");
    inorder(root);
    printf("\nPost-order: ");
    postorder(root);
    return 0;
}

