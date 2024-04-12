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

nodeS* createNode(Btree data){
    nodeS* s = malloc(sizeof(nodeS));
    s->data = data;
    s->next = NULL;
    return s;
}

stack createStack(){
    stack s;
    s.top = NULL;
    return s;
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

int Top(stack s, Btree* e){
    if(isEmpty(s)){
        return 0;
    }
    *e = s.top->data;
    return 1;
}

Btree construct(element e, Btree left, Btree right){
    Btree tmp = malloc(sizeof(struct node));
    tmp->data = e;
    tmp->left = left;
    tmp->right = right;
    return tmp;
}

int ZigZag(Btree B){
    if(!B){
        return 0;
    }
    stack s1 = createStack();
    stack s2 = createStack();
    push(&s1,B);
    Btree current ;
    while(!isEmpty(s1)){
        while(Top(s1,&current)){
            pop(&s1);
            printf("%d",current->data.a);
            if(current->left){
                push(&s2,current->left);
            }
            if(current->right){
                push(&s2,current->right);
            }
        }
        while(Top(s2,&current)){
            pop(&s2);
            printf("%d",current->data.a);
            if(current->left){
                push(&s1,current->left);
            }
            if(current->right){
                push(&s1,current->right);
            }
        }
    }
    return 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Btree nodes[n];
    for (int i = 0; i < n; i++) {
        element e = {arr[i]};
        nodes[i] = construct(e, NULL, NULL);
    }

    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n) {
            nodes[i]->left = nodes[2 * i + 1];
        }
        if (2 * i + 2 < n) {
            nodes[i]->right = nodes[2 * i + 2];
        }
    }

    ZigZag(nodes[0]);

    return 0;
}
