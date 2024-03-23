#include <stdio.h>
#define N 20
typedef struct element{
    int e;
}element;
typedef struct TwoStack{
    int Top1;
    int Top2;
    element T[N];
}TwoStack;

TwoStack createStack(){
    TwoStack s ;
    s.Top1 = -1;
    s.Top2 = N;
    return s;
}

int isEmpty(TwoStack s){
    return (s.Top2 == N && s.Top1 == -1);
}

int push(TwoStack* s, element e, int a){
    if(s->Top1 == N - 1 || s->Top2 == -1){
        return 0;
    }
    switch (a) {
        case 1:
            s->T[++s->Top1] = e;
            return 1;
        case 2:
            s->T[--s->Top2] = e;
            return 1;
    }
}

int pop(TwoStack* s, int a){
    if(isEmpty(*s)){
        return 0;
    }
    switch (a) {
        case 1:
            s->Top1--;
            return 1;
        case 2:
            s->Top2++;
            return 1;
    }
}

int Top(TwoStack s, element* e, int a){
    if(isEmpty(s)){
        return 0;
    }
    switch (a) {
        case 1:
            *e = s.T[s.Top1];
            return 1;
        case 2:
            *e = s.T[s.Top2];
            return 1;
    }
}
int main() {
    TwoStack s = createStack();
    element e1 = {10};
    element e2 = {20};
    push(&s, e1, 1);
    push(&s, e2, 2);
    element top;
    Top(s, &top, 1);
    printf("%d\n", top.e);
    Top(s, &top, 2);
    printf("%d\n", top.e);
    pop(&s, 1);
    pop(&s, 2);
    return 0;
}
