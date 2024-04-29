#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int a;
}element;

typedef struct node{
    element data;
    struct node* left, *right;
}*Btree;

Btree construct(element e, Btree left, Btree right){
    Btree tmp = malloc(sizeof(struct node));
    tmp->left = left;
    tmp->right = right;
    tmp->data = e;
    return tmp;
}

void inOrderTraversal(Btree B){
    if(B){
        inOrderTraversal(B->left);
        printf("%d ",B->data);
        inOrderTraversal(B->right);
    }
}

void printOutsideRange(Btree B, int a, int b){
    if(!B){
        return;
    }
    if(B->data.a<a || B->data.a>b){
        printf("%d ",B->data.a);
    }
    printOutsideRange(B->left,a,b);
    printOutsideRange(B->right,a,b);
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
