#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int a;
}element;

typedef struct node{
    element data;
    struct node* right, *left;
}*Btree;

Btree construct(element e, Btree left, Btree right){
    Btree tmp = malloc(sizeof(struct node));
    tmp->left = left;
    tmp->right = right;
    tmp->data = e;
    return tmp;
}

void inOrderTraversal(Btree root){
    if(root){
        inOrderTraversal(root->left);
        printf("%d",root->data.a);
        inOrderTraversal(root->right);
    }
}

void printOutsideRange(Btree root, int a, int b){
    if(!root){
        return;
    }
    if(root->data.a<a || root->data.a>b){
        printf("%d",root->data.a);
    }
    printOutsideRange(root->right,a,b);
    printOutsideRange(root->left,a,b);
}

int main() {
    element e1 = { 10 };
    element e2 = { 5 };
    element e3 = { 15 };
    element e4 = { 3 };
    element e5 = { 7 };
    element e6 = { 12 };
    element e7 = { 18 };

    Btree root = construct(e1,
        construct(e2,
            construct(e4, NULL, NULL),
            construct(e5, NULL, NULL)
        ),
        construct(e3,
            construct(e6, NULL, NULL),
            construct(e7, NULL, NULL)
        )
    );

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Nodes outside the range [5, 15]: ");
    printOutsideRange(root, 5, 15);
    printf("\n");

    return 0;
}