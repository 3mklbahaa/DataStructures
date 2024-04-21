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

int isSumTreeUtil(Btree root, int *isSumT) {
    if (root == NULL)
        return 0;
    if(root->right == NULL && root->left == NULL){
        return 1;
    }
    int sumLeft = isSumTreeUtil(root->left,isSumT);
    int sumRight = isSumTreeUtil(root->right,isSumT);
    if(root->data.a != sumLeft + sumRight || !(*isSumT)){
        *isSumT = 0;
    }
    return 1;
}

int isSumTree(Btree root) {
    int isSumT = 1;
    isSumTreeUtil(root, &isSumT);
    return isSumT;
}

int main() {
    // Constructing a sample binary tree
    element e1 = { 10 };
    element e2 = { 5 };
    element e3 = { 3 };
    element e4 = { 7 };
    element e5 = { 6 };
    element e6 = { 2 };

    Btree root = construct(e1,
                           construct(e2,
                                     construct(e3, NULL, NULL),
                                     construct(e4, NULL, NULL)
                           ),
                           construct(e5, NULL, construct(e6, NULL, NULL))
    );

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    if (isSumTree(root)) {
        printf("The binary tree is a sum tree.\n");
    } else {
        printf("The binary tree is not a sum tree.\n");
    }

    return 0;
}