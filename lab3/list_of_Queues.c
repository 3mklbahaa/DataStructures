#include <stdio.h>
#include <stdlib.h>

typedef struct element{
    int a;
}element;

typedef struct node{
    int priority;
    element e;
    struct node* next;
}node;

typedef struct queue{
    node* front;
    int priority;
    struct queue* next;
}queue;

node* createNode(int priority, element e){
    node* new = malloc(sizeof(node));
    if(new==NULL){
        return NULL;
    }
    new->priority = priority;
    new->e = e;
    new->next = NULL;
    return new;
}

queue* createQueue(int priority, node* front){
    queue* q = malloc(sizeof(queue));
    if(q==NULL){
        return NULL;
    }
    q->priority = priority;
    q->front = front;
    q->next = NULL;
    return q;
}

int enqueue(queue** q, element e, int priority){
    node* newNode = createNode(priority,e);
    if(newNode==NULL){
        return 0;
    }
    if(*q == NULL || priority>(*q)->priority){
        queue* newQueue = createQueue(priority,newNode);
        newQueue->next = *q;
        *q = newQueue;
        return 1;
    }
    queue* current = *q;
    queue* prev = NULL;
    while(current!=NULL && priority<=current->priority){
        prev = current;
        current = current->next;
    }
    if(prev->priority == priority){
        newNode->next = prev->front;
        prev->front = newNode;
        return 1;
    }
    queue* newQueue = createQueue(priority,newNode);
    newQueue->next = current;
    prev->next = newQueue;
    return 1;
}

int main() {
    queue* q = NULL;

    element e1 = {1};
    element e2 = {2};
    element e3 = {3};
    element e4 = {4};

    enqueue(&q, e1, 2); 
    enqueue(&q, e2, 1); 
    enqueue(&q, e3, 3); 
    enqueue(&q, e4, 2);
    queue* currentQueue = q;
    while (currentQueue != NULL) {
        printf("Priority: %d\n", currentQueue->priority);
        node* currentNode = currentQueue->front;
        while (currentNode != NULL) {
            printf("%d ", currentNode->e.a);
            currentNode = currentNode->next;
        }
        printf("\n");
        currentQueue = currentQueue->next;
    }
    while (q != NULL) {
        node* temp = q->front;
        while (temp != NULL) {
            node* next = temp->next;
            free(temp);
            temp = next;
        }
        queue* nextQueue = q->next;
        free(q);
        q = nextQueue;
    }
    return 0;
}
