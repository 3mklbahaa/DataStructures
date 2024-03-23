#include <stdio.h>
#include <stdlib.h>
#define N 20
typedef struct stack{
    int top;
    int array[N];
}stack;
stack* create_stack(){
    stack* s = malloc(sizeof(stack));
    s->top=-1;
    return s;
}
int isFull(stack* s){
    return (s->top==N-1);
}
int isEmpty(stack* s){
    return (s->top==-1);
}
int push(stack* s, int e){
    if(isFull(s)){
        return -1;
    }
    s->top++;
    s->array[s->top] = e;
    return 1;
}
int pop(stack* s){
    if(isEmpty(s)){
        return -1;
    }
    s->top--;
    return 1;
}
int Top(stack* s, int* e){
    if(isEmpty(s)){
        return -1;
    }
    *e = s->array[s->top];
    return 1;
}
int nth(stack* s, int index, int* e) {
    for (int i = -1; i < index; i++) {
        if (!isEmpty(s)) {
            Top(s, e);
            pop(s);
        }
        else if (isEmpty(s)) {
            *e = -1;
            break;
        }
    }
    return *e;
}
int main(){
    stack* s = create_stack();
    int e;
    push(s,2);
    push(s,7);
    push(s,1);
    push(s,8);
    printf("%d", nth(s,4,&e));
}
