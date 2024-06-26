#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 20
typedef struct element{
    char lah;
}element;

typedef struct stack{
    int top;
    element T[N+1];
}stack;

stack* createStack(){
    stack* s = malloc(sizeof(stack));
    s->top=-1;
    return s;
}

int isFull(stack* s){
    return s->top==N-1;
}

int isEmpty(stack* s){
    return s->top==-1;
}

int push(stack* s, element e){
    if(isFull(s)){
        return 0;
    }
    s->top++;
    s->T[s->top]= e;
    return 1;
}

int pop(stack* s){
    if(isEmpty(s)){
        return 0;
    }
    s->top--;
    return 1;
}

int Top(stack* s, element* e){
    if(isEmpty(s)){
        return 0;
    }
    *e = s->T[s->top];
    return 1;
}

int valid(char* word){
    stack* s = createStack();
    int len = strlen(word);
    for(int i=0; i<len;i++){
        if(word[i] == '(' || word[i] == '[' || word[i] == '{'){
            element e;
            e.lah = word[i];
            push(s,e);
        }
        else if(word[i]== ')' || word[i] == ']' || word[i] == '}'){
            element new, e;
            new.lah = word[i];
            Top(s,&e);
            pop(s);
            if(new.lah == ')' && e.lah != '(' || new.lah == ']' && e.lah != '[' || new.lah == '}' && e.lah != '{'){
                return -1;
            }
        }
    }
    return 1;
}

int main(){
    printf("%d\n", valid(")5((x+1)"));
    printf("%d\n", valid("5(x+1)"));
    printf("%d\n", valid("5(x+1)}{"));
    return 0;
}
