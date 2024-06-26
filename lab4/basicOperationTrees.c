#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int a;
}element;

typedef struct node{
    element data;
    struct node* right, *left;
}*Btree;

Btree createBtree(){
    return NULL;
}

int isEmptyBtree(Btree b){
    return b==NULL;
}

typedef struct nodeS{
    Btree data;
    struct nodeS* next;
}nodeS;

typedef struct stack{
    nodeS* top;
}stack;

typedef struct queue{
    nodeS* front, *rear;
}queue;


nodeS* createNode(Btree data){
    nodeS* s = malloc(sizeof(nodeS));
    s->data = data;
    s->next = NULL;
    return s;
}

queue createQueue(){
    queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

int isEmptyQueue(queue q){
    return q.front == NULL;
}

int enqueue(queue* q, Btree data){
    nodeS* new = createNode(data);
    if(isEmptyQueue(*q)){
        q->rear = q->front = new;
    }
    q->rear->next = new;
    q->rear = new;
    return 1;
}

int dequeue(queue* q){
    if(isEmptyQueue(*q)){
        return 0;
    }
    nodeS* tmp = q->rear;
    q->rear = q->rear->next;
    free(tmp);
    return 1;
}

int Front(queue q, Btree* e){
    if(isEmptyQueue(q)){
        return 0;
    }
    *e = q.front->data;
    return 1;
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

int Root(Btree B, element* e){
    if(isEmptyBtree(B)){
        return 0;
    }
    *e = B->data;
    return 1;
}

int Right(Btree B, Btree *right){
    if(isEmptyBtree(B)){
        return 0;
    }
    *right = B->right;
    return 1;
}

int Left(Btree B, Btree* left){
    if(isEmptyBtree(B)){
        return 0;
    }
    *left = B->left;
    return 1;
}

void inOrder(Btree B){
    if(B){
        inOrder(B->left);
        printf("%d",B->data);
        inOrder(B->right);
    }
}

void inOrderI(Btree B){
    stack s = createStack();
    int proceed = 1;
    while(proceed){
        while(B!=NULL){
            push(&s,B);
            B = B->left;
        }
        if(!isEmpty(s)){
            Top(s,&B);
            pop(&s);
            printf("%c",B->data);
            B = B->right;
        }
        else{
            proceed = 0;
        }
    }
}

void preOrderI(Btree B){
    stack s = createStack();
    int proceed = 1 ;
    while(proceed){
        while(B!=NULL){
            printf("%c",B->data);
            push(&s,B);
            B = B->left;
        }
        if(!isEmpty(s)){
            Top(s,&B);
            pop(&s);
            B = B->right;
        }
        else{
            proceed = 0;
        }
    }
}

void levelOrder(Btree B){
    queue q = createQueue();
    if(B==NULL){
        return;
    }
    Btree tmp;
    enqueue(&q,B);
    while(Front(q,&tmp)){
        dequeue(&q);
        printf("%c",tmp->data);
        if(tmp->left!=NULL){
            enqueue(&q,tmp->left);
        }
        if(tmp->right!=NULL){
            enqueue(&q,tmp->right);
        }
    }
}

int Max_rec(Btree B){
    if(B==NULL){
        return INT_MIN;
    }
    int max_left = Max_rec(B->left);
    int max_right = Max_rec(B->right);
    int max_subtree = (max_left > max_right) ? max_left : max_right;
    return (B->data.a > max_subtree) ? B->data.a : max_subtree;
}

int Max_rec_Queue(Btree B){
    int max = INT_MIN;
    if(B==NULL){
        return INT_MIN;
    }
    Btree tmp;
    queue q = createQueue();
    enqueue(&q,B);
    while(Front(q,&tmp)){
        dequeue(&q);
        max = (tmp->data.a>max) ? tmp->data.a : max;
        if(tmp->left!=NULL){
            enqueue(&q,tmp->left);
        }
        if(tmp->right!=NULL){
            enqueue(&q,tmp->right);
        }
    }
    return max;
}

int Max_rec_Stack(Btree B){
    int max = 0;
    stack s = createStack();
    if(B==NULL){
        return INT_MIN;
    }
    Btree tmp;
    push(&s,B);
    while(Top(s,&tmp)){
        pop(&s);
        max = (tmp->data.a>max) ? tmp->data.a : max;
        if(tmp->left != NULL){
            push(&s,tmp->left);
        }
        if(tmp->right != NULL){
            push(&s,tmp->right);
        }
    }
    return max;
}

int sum(Btree B){
   if(B==NULL){
       return 0;
   }
   return B->data.a + sum(B->left) + sum(B->left);
}

int numNodes(Btree B){
    if(!B){
        return 0;
    }
    return 1 + numNodes(B->left) + numNodes(B->right);
}

int numLeafNodes(Btree B){
    if(!B){
        return 0;
    }
    if(B->right==NULL && B->left == NULL){
        return 1;
    }
    return numLeafNodes(B->left) + numLeafNodes(B->right);
}

int nonleafNodes(Btree B){
    if(!B){
        return 0;
    }
    if(B->left == NULL && B->right == NULL){
        return 0;
    }
    return 1 + nonleafNodes(B->right) + nonleafNodes(B->left);
}

