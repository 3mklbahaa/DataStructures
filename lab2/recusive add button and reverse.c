#include <stdio.h>
#define N 20

typedef struct element{
    int a;
}element;

typedef struct stack{
    int Top;
    element T[N];
}stack;

stack createStack(){
    stack s;
    s.Top = -1;
    return s;
}

int isFull(stack s){
    return s.Top == N-1;
}

int isEmpty(stack s){
    return s.Top == -1;
}

int push(stack* s, element e){
    if(isFull(*s)){
        return 0;
    }
    s->T[++s->Top] = e;
    return 1;
}

int pop(stack* s){
    if(isEmpty(*s)){
        return 0;
    }
    s->Top--;
    return 1;
}

int Top(stack s, element* e){
    if(isEmpty(s)){
        return 0;
    }
    *e = s.T[s.Top];
    return 1;
}

void insertButton(stack* s, element e){
    if(isEmpty(*s)){
        push(s,e);
        return;
    }
    element z;
    Top(*s,&z);
    pop(s);
    insertButton(s,e);
    push(s,z);
}

void reverseStack(stack* s){
    element e;
    if(!isEmpty(*s)){
        Top(*s,&e);
        pop(s);
        reverseStack(s);
        insertButton(s,e);
    }
}

//main men chatgpt

int main() {
    stack s = createStack(); // Create an empty stack

    // Push some elements onto the stack
    element e1 = {1};
    element e2 = {2};
    element e3 = {3};
    push(&s, e1);
    push(&s, e2);
    push(&s, e3);

    printf("Original Stack:\n");
    printf("Top -> ");
    for (int i = s.Top; i >= 0; i--) {
        printf("%d ", s.T[i].a);
    }
    printf("\n");

    // Reverse the stack
    reverseStack(&s);

    printf("Reversed Stack:\n");
    printf("Top -> ");
    for (int i = s.Top; i >= 0; i--) {
        printf("%d ", s.T[i].a);
    }
    printf("\n");

    return 0;
}
