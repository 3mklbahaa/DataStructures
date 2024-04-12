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

Btree lowestCommonAncestor(Btree root, Btree p, Btree q) {
    if(!root){
        return NULL;
    }
    if(root == p || root == q){
        return root;
    }
    Btree left = lowestCommonAncestor(root->left,p,q);
    Btree right = lowestCommonAncestor(root->right,p,q);

    if(left && right){
        return root;
    }
    else if(right){
        return right;
    }
    else if(left){
        return left;
    }
    return NULL;
}

int main() {
    Btree leaf1 = construct((element){1}, NULL, NULL);
    Btree leaf2 = construct((element){2}, NULL, NULL);
    Btree leaf3 = construct((element){3}, NULL, NULL);
    Btree leaf4 = construct((element){4}, NULL, NULL);
    Btree leaf5 = construct((element){5}, NULL, NULL);
    Btree leaf6 = construct((element){6}, NULL, NULL);
    Btree leaf7 = construct((element){7}, NULL, NULL);

    Btree root = construct((element){10}, leaf1, leaf2);
    root->left->left = leaf3;
    root->left->right = leaf4;
    root->right = leaf5;
    root->right->left = leaf6;
    root->right->right = leaf7;

    Btree p = leaf3; 
    Btree q = leaf6;
    Btree lca = lowestCommonAncestor(root, p, q);
    if (lca) {
        printf("Lowest Common Ancestor: %d\n", lca->data.a);
    } else {
        printf("No common ancestor found.\n");
    }
    return 0;
}
