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

int isSuffix(char* word1,char* word2){
    stack* s1 = createStack();
    stack* s2 = createStack();
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    for(int i=0; i<len1; i++){
        element e;
        e.lah = word1[i];
        push(s1,e);
    }
    for(int i=0; i<len2; i++){
        element e;
        e.lah = word2[i];
        push(s2,e);
    }
    element e1, e2;
    while(!isEmpty(s1)&&!isEmpty(s2)){
        Top(s1,&e1);
        Top(s2,&e2);
        if(e1.lah!=e2.lah){
            return -1;
        }
        pop(s1);
        pop(s2);
    }
    return 1;
}

int main(){//dayman 3am hot 1 ye3ne mazbouta w -1 mesh mazbouta
    printf("%d", isSuffix("table", "intertable"));
    return 0;
}
