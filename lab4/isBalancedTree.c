#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int a;
}element;

typedef struct node{
    element data;
    struct node* right, *left;
}*Btree;

typedef struct nodeS{
    Btree data;
    struct nodeS* next;
}nodeS;

typedef struct stack{
    nodeS* top;
}stack;

stack createStack(){
    stack s;
    s.top = NULL;
    return s;
}

nodeS* createNode(Btree data){
    nodeS* new = malloc(sizeof(nodeS));
    new->data = data;
    new->next = NULL;
    return new;
}

Btree construct(element data, Btree right, Btree left){
    Btree new = malloc(sizeof(Btree));
    new->data = data;
    new->right = right;
    new->left = left;
    return new;
}

int isEmpty(stack s){
    return s.top == NULL;
}

int push(stack* s, Btree data){
    nodeS* new = createNode(data);
    new->next = s->top;
    s->top = new;
    return 1;
}

int pop(stack* s){
    if(isEmpty(*s)){
        return 0;
    }
    nodeS* tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    return 1;
}

int Top(stack s, Btree* data){
    if(isEmpty(s)){
        return 0;
    }
    *data = s.top->data;
    return 1;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}


int height(Btree B)
{
    if(!B){
        return 0;
    }
    return 1+ max(height(B->left), height(B->right));
}


int balanced(Btree B)
{
    if(!B){
        return 1;
    }
    return balanced(B->left) &&  balanced(B->right) && abs(height(B->right) - height(B->left))<=1;
}

int main() {
    element e1 = {1};
    element e2 = {2};
    element e3 = {3};
    element e4 = {4};
    element e5 = {5};

    Btree root = construct(e1,
                           construct(e2, construct(e4, NULL, NULL), NULL),
                           construct(e3, NULL, construct(e5, NULL, NULL)));

    printf("Height of the tree: %d\n", height(root));

    if (balanced(root))
        printf("The tree is balanced.\n");
    else
        printf("The tree is not balanced.\n");

    return 0;
}
