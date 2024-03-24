#include <stdio.h>
#define N 20

//not in lab

typedef struct element{
    int a;
}element;

typedef struct queue{
    int front, rear;
    element T[N];
}queue;

queue create_queue(){
    queue q;
    q.front = 1;
    q.rear = 0;
    return q;
}

int isEmpty(queue q){
    return q.front == (q.rear+1)%N;
}

int isFull(queue q){
    return q.front == (q.rear+2)%N;
}

int enque(queue *q, element e){
    if(isFull(*q)){
        return 0;
    }
    q->rear = (q->rear+1)%N;
    q->T[q->rear] = e;
    return 1;
}

int dequeue(queue *q){
    if(isEmpty(*q)){
        return 0;
    }
    q->front = (q->front+1)%N;
    return 1;
}

int Front(queue q, element* e){
    if(isEmpty(q)){
        return 0;
    }
    *e=q.T[q.front];
    return 1;
}

