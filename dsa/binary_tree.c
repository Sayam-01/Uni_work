#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

//func to create node
struct node* create_node(int value){
    struct node* newNode = malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Error allocating size.\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//func to insert node
struct node* insert_node(struct node* root, int value){
    if(root == NULL){
        return create_node(value);
    }
    if(value <= root->data){
        root->left = insert_node(root->left, value);
    }
    else if(value > root->data){
        root->right = insert_node(root->right, value);
    }

    return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%i -> ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%i -> ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root != NULL){
        preorder(root->left);
        preorder(root->right);
        printf("%i -> ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        root = insert_node(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n----By Sayam Shrestha-----\n");
    return 0;
}