#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct element{
    int a;
}element;

typedef struct node{
    element data;
    struct node* right, *left;
}*Btree;

typedef struct ListNode{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct stack{
    ListNode* top;
}stack;

ListNode* createNode(element data){
    ListNode* new = malloc(sizeof(ListNode));
    new->data = data;
    new->next = NULL;
    return new;
}

stack createStack(){
    stack s;
    s.top = NULL;
    return s;
}

int isEmptyStack(stack s){
    return s.top == NULL;
}

int push(stack* s, element data){
    ListNode* new = createNode(data);
    new->next = s->top;
    s->top = new;
    return 1;
}

int pop(stack* s){
    if(isEmptyStack(*s)){
        return 0;
    }
    ListNode* tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    return 1;
}

int Top(stack s, element* e){
    if(isEmptyStack(s)){
        return 0;
    }
    *e = s.top->data;
    return 1;
}

Btree construct(element e, Btree left, Btree right){
    Btree tmp = malloc(sizeof(struct node));
    tmp->left = left;
    tmp->right = right;
    tmp->data = e;
    return tmp;
}

void inOrderTraversal(Btree root){
    if(root){
        inOrderTraversal(root->left);
        printf("%d",root->data.a);
        inOrderTraversal(root->right);
    }
}

void DFS(Btree root) {
    if (root == NULL)
        return;

    stack s = createStack();
    push(&s, root->data);

    while (!isEmptyStack(s)) {
        element curr;
        Top(s, &curr);
        pop(&s);
        printf("%d ", curr.a);

        if (root->right != NULL)
            push(&s, root->right->data);
        if (root->left != NULL)
            push(&s, root->left->data);
    }
}

bool isPathUtil(struct ListNode* curList, Btree curTree){
    if(curList == NULL){
        return true;
    }
    if(curTree == NULL){
        return false;
    }
    if(curList->data.a != curTree->data.a){
        return false;
    }
    return isPathUtil(curList->next,curTree->left) || isPathUtil(curList->next,curTree->right);
}

bool isSubPath(struct ListNode* head, Btree root) {
    if (head == NULL)
        return true;

    if (root == NULL)
        return false;

    if (isPathUtil(head, root))
        return true;

    return isSubPath(head, root->left) || isSubPath(head, root->right);
}

int main() {
    Btree root = construct((element){1},
                           construct((element){2}, NULL, NULL),
                           construct((element){3}, NULL, NULL));
    root->left->left = construct((element){4}, NULL, NULL);
    root->left->right = construct((element){5}, NULL, NULL);

    printf("Inorder traversal of binary tree:\n");
    inOrderTraversal(root);
    printf("\n");

    ListNode* head = createNode((element){2});
    head->next = createNode((element){4});
    head->next->next = createNode((element){5});

    if (isSubPath(head, root))
        printf("The linked list is a subpath of the binary tree.\n");
    else
        printf("The linked list is not a subpath of the binary tree.\n");

    return 0;
}
