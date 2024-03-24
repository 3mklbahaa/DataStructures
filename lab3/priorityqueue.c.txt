#include <stdio.h>
#include <stdlib.h>
#define N 20

typedef struct node{
    int data;
    int priority;
    struct node* next;
}node;

typedef struct queue{
    node* front;
}queue;

node* createNode(int data, int priority) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        return NULL;
    }
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    return newnode;
}

void initializeQueue(queue* pq) {
    pq->front = NULL;
}

void enqueueSingleQueue(queue* pq, int data, int priority) {
    node* newNode = createNode(data, priority);
    if (pq->front == NULL || pq->front->priority < priority) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        node* current = pq->front;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int dequeueSingleQueue(queue * pq) {
    if (pq->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    node* temp = pq->front;
    int data = temp->data;
    pq->front = pq->front->next;
    return data;
}

