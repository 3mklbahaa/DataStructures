#include <stdio.h>
#define N 20

typedef struct element{
    int a;
}element;

typedef struct threeStacks{
    int Top1, Top2, Top3, But3;
    element T[N];
}threeStacks;

threeStacks createStack(){
    threeStacks s;
    s.Top1 = -1;
    s.Top2 = N;
    s.Top3 = N/2;
    s.But3 = N/2 + 1;
    return s;
}

int isEmpty(threeStacks s, int x){
    if(x==1){
        return s.Top1 == -1;
    }
    else if(x==2){
        return s.Top2 == N;
    }
    else if(x==3){
        return s.Top3 == N/2;
    }
}

int isFull(threeStacks s, int x){
    if(x==1){
        return s.Top1 == s.But3 - 1;
    }
    else if(x==2){
        return s.Top2 == s.But3 - 1;
    }
    else if(x==3){
        return s.Top3 == s.Top2 - 1;
    }
}

int push(threeStacks* s, element e, int x){
    if(isFull(*s,1)&& isFull(*s,2)&& isFull(*s,3)){
        return 0;
    }
    switch (x) {
        case 1:
            if(!isFull(*s,1)){
                s->T[++s->Top1] = e;
                return 1;
            }
            else if(isFull(*s,1) && !isFull(*s,3)){
                for(int i=s->Top3-1;i>=0;i--){
                    s->T[i+1] = s->T[i];
                }
                s->Top3++;
                s->T[++s->Top1] = e;
                return 1;
            }
            break;
        case 2:
            if(!isFull(*s,2)){
                s->T[--s->Top2] = e;
                return 1;
            }
            else if(isFull(*s,2)&&!isFull(*s,1)){
                for(int i=s->But3+1; i<s->Top3;i++){
                    s->T[i-1] = s->T[i];
                }
                s->Top1++;
                s->T[s->Top3] = e;
                return 1;
            }
            break;
        case 3:
            if(isFull(*s,3)){
                return 0;
            }
            else if(!isFull(*s,3)){
                s->T[++s->Top3] = e;
                return 1;
            }
            break;
    }

    return 0;
}

int pop(threeStacks* s, int x){
    if(isEmpty(*s,x)){
        return 0;
    }
    switch (x) {
        case 1:
            s->Top1--;
            return 1;
        case 2:
            s->Top2++;
            return 1;
        case 3:
            s->Top3--;
            return 1;
    }
}

int Top(threeStacks s, element* e, int x){
    if(isEmpty(s,x)){
        return 0;
    }
    switch (x) {
        case 1:
            *e = s.T[s.Top1];
            return 1;
        case 2:
            *e = s.T[s.Top2];
            return 1;
        case 3:
            *e = s.T[s.Top3];
            return 1;
    }
}


// Main men chatgpt


int main() {
    // Create three stacks
    threeStacks stacks = createStack();

    // Push elements onto stack 1
    push(&stacks, (element){10}, 1);
    push(&stacks, (element){20}, 1);
    push(&stacks, (element){30}, 1);

    // Push elements onto stack 2
    push(&stacks, (element){40}, 2);
    push(&stacks, (element){50}, 2);

    // Push elements onto stack 3
    push(&stacks, (element){60}, 3);
    push(&stacks, (element){70}, 3);

    // Pop elements from stack 1
    pop(&stacks, 1);
    pop(&stacks, 1);

    // Pop elements from stack 2
    pop(&stacks, 2);

    // Pop elements from stack 3
    pop(&stacks, 3);

    // Access and print the top elements of all three stacks
    element topElement;

    if (Top(stacks, &topElement, 1))
        printf("Top element of stack 1: %d\n", topElement.a);
    else
        printf("Stack 1 is empty.\n");

    if (Top(stacks, &topElement, 2))
        printf("Top element of stack 2: %d\n", topElement.a);
    else
        printf("Stack 2 is empty.\n");

    if (Top(stacks, &topElement, 3))
        printf("Top element of stack 3: %d\n", topElement.a);
    else
        printf("Stack 3 is empty.\n");

    return 0;
}
