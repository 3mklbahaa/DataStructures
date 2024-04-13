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
    Btree new = malloc(sizeof(struct node));
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

int max(int a, int b){
    return (a>b) ? a:b;
}

void sumOfLvl(Btree B){
    if(!B){
        return ;
    }
    stack currentlvl = createStack();
    stack nextlvl = createStack();
    push(&currentlvl,B);
    Btree current;
    int sum = 0, i=0;
    while(!isEmpty(currentlvl)){
        while(Top(currentlvl,&current)){
            sum += current->data.a;
            pop(&currentlvl);
            if(current->left){
                push(&nextlvl,current->left);
            }
            if(current->right){
                push(&nextlvl,current->right);
            }
        }
        printf("the sum of %d lvl is: %d\n",sum,i);
        i++;
        sum = 0;
        while(Top(nextlvl,&current)){
            sum += current->data.a;
            pop(&nextlvl);
            if(current->left){
                push(&currentlvl,current->left);
            }
            if(current->right){
                push(&currentlvl,current->right);
            }
        }
        printf("the sum of %d lvl is: %d\n",sum,i);
        i++;
        sum = 0;
    }
}

int main() {
    Btree root = construct((element){1},
                           construct((element){2},
                                     construct((element){4}, NULL, NULL),
                                     construct((element){5}, NULL, NULL)),
                           construct((element){3},
                                     construct((element){6}, NULL, NULL),
                                     construct((element){7}, NULL, NULL)));
    sumOfLvl(root);
    return 0;
}
