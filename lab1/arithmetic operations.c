#include <stdio.h>
#define N 20

typedef struct element{
    char a;
}element;

typedef struct stack{
    element T[N];
    int top;
}stack;

stack createStack(){
    stack s ;
    s.top = -1;
    return s;
}

int isFull(stack s){
    return s.top == N-1;
}

int isEmpty(stack s){
    return s.top == -1;
}

int push(stack* s, element e){
    if(isFull(*s)){
        return 0;
    }
    s->T[++s->top] = e;
    return 1;
}

int pop(stack* s){
    if(isEmpty(*s)){
        return 0;
    }
    s->top--;
    return 1;
}

int Top(stack s, element *e){
    if(isEmpty(s)){
        return 0;
    }
    *e = s.T[s.top];
    return 1;
}

int arithmetic(char* expression){
    stack s1 = createStack();
    stack s2 = createStack();
    int i=0;
    for(;expression[i];i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
            element e;
            e.a = expression[i];
            push(&s2,e);
        }
        else{
            element e;
            e.a = expression[i];
            push(&s1,e);
        }
    }
    element z;
    Top(s1,&z);
    pop(&s1);
    while(!isEmpty(s1)){
        element a,b;
        Top(s2,&b);
        pop(&s2);
        Top(s1,&a);
        pop(&s1);
        int c, d;
        c = a.a - '0';
        d = z.a - '0';
        int y;
        if(b.a == '+'){
            y = c + d;
        }
        else if(b.a == '-'){
            y = c - d;
        }
        else if(b.a == '*'){
            y = c * d;
        }
        else if(b.a == '/'){
            y = c / d;
        }
        z.a = y + '0';
    }
    int k = z.a - '0';
    return k;
}

int main() {
    char expression[] = "3+6";
    int result = arithmetic(expression);
    printf("%d", result);
    return 0;
}'
