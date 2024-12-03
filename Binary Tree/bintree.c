//binary tree and its funstions
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *left, *right;
} node;
void insert(node **root, int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    if (*root==NULL)
        *root = newnode;
    else if (x<(*root)->data)
        insert(&(*root)->left, x);
    else if (x>(*root)->data)
        insert(&(*root)->right, x);
}
void iterinsert(node **root, int x) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;
    if(*root==NULL) {
        *root = newnode;
        return;
    }
    node *parent = NULL, *temp = *root;
    while(temp!=NULL) {
        parent = temp;
        if (x<temp->data)
            temp = temp->left;
        else if(x>temp->data)
            temp = temp->right;
    }
    if(x<parent->data)
        parent->left = newnode;
    else if(x>parent->data)
        parent->right = newnode;
}
void preorderTraversal(node *root) {
    if (root!=NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void inorderTraversal(node *root) {
    if (root!=NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void postorderTraversal(node *root) {
    if (root!=NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
void preorder(node *root) {
    if(root==NULL)
        return;
    node *stack[20];
    int top = -1;
    stack[++top] = root;
    while(top>=0) {
        node *temp = stack[top--];
        printf("%d ", temp->data);
        if(temp->right) stack[++top] = temp->right;
        if(temp->left) stack[++top] = temp->left;
    }
}
void inorder(node* root) {
    node* stack[100];
    int top = -1;
    node* curr = root;
    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
}
void postorder(node* root) {
    if (root == NULL) return;
    node* stack1[20], *stack2[20];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1>=0) {
        node* node = stack1[top1--];
        stack2[++top2] = node;
        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }
    while (top2 >= 0) {
        node* node = stack2[top2--];
        printf("%d ", node->data);
    }
}
int max(int a, int b) {
    return (a>=b)?a:b;
}
int height(node *root) {
    if(root==NULL)
        return -1;
    return 1 + max(height(root->left), height(root->right));
}
int search(node *root, int val) {
    if(root==NULL)
        return 0;
    node *temp = root;
    while(temp!=NULL) {
        if(val==temp->data)
            return 1;
        else if(val<temp->data)
            temp = temp->left;
        else if(val>temp->data)
            temp = temp->right;
    }
    return 0;
}
int main() {
    node *root = NULL;
    for(int i = 0; i<10; i++) {
        int x = rand()%10;
        printf("Inserting %d\n", x);
        insert(&root, x);
    }
    //inserting without using recursion
    iterinsert(&root, 10); 
    iterinsert(&root, 11);
    printf("Inorder traversal of the binary tree: ");
    // inorderTraversal(root);
    inorder(root);
    printf("\nPreorder traversal of the binary tree: ");
    // preorderTraversal(root);
    preorder(root);
    printf("\nPostorder traversal of the binary tree: ");
    // postorderTraversal(root);
    postorder(root);
    int h = height(root);
    printf("\nHeight of binary tree: %d\n", h);
    printf("Enter value to search: ");
    scanf("%d", &h);
    if(search(root, h))
        printf("Element found!\n");
    else printf("Element not found!\n");
    return 0;
}