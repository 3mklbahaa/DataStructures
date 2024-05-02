#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element{
    int a;
}element;

typedef struct node{
    element data;
    struct node* left, *right;
}*Btree;

typedef struct ListNode{
    element data;
    struct ListNode *next;
}ListNode;

Btree construct(element e, Btree left, Btree right){
    Btree tmp = malloc(sizeof(struct node));
    tmp->left = left;
    tmp->right = right;
    tmp->data = e;
    return tmp;
}

void inOrderTraversal(Btree B){
    if(B){
        inOrderTraversal(B->left);
        printf("%d ",B->data);
        inOrderTraversal(B->right);
    }
}

bool isPathUtil(ListNode* curList, Btree currTree){
    if(currTree==NULL){
        return false;
    }
    if(curList==NULL){
        return true;
    }
    if (curList->data.a == currTree->data.a) {
        return isPathUtil(curList->next, currTree->left) || isPathUtil(curList->next, currTree->right);
    }
    return false;
}

bool isSubPath(ListNode* head, Btree root){
    if(root == NULL){
        return true;
    }
    if(head == NULL){
        return true;
    }
    if(isPathUtil(head,root)){
        return true;
    }
    return isPathUtil(head,root->right) || isPathUtil(head,root->left);
}

int main() {
    // Constructing a binary tree
    Btree root = construct((element){1},
                           construct((element){2},
                                     construct((element){4}, NULL, NULL),
                                     construct((element){5}, NULL, NULL)),
                           construct((element){3},
                                     construct((element){6}, NULL, NULL),
                                     construct((element){7}, NULL, NULL)));

    // Printing the in-order traversal of the binary tree
    printf("In-order traversal of the binary tree: ");
    inOrderTraversal(root);
    printf("\n");

    // Creating a linked list
    ListNode* head = malloc(sizeof(ListNode));
    head->data = (element){2};
    head->next = malloc(sizeof(ListNode));
    head->next->data = (element){4};
    head->next->next = malloc(sizeof(ListNode));
    head->next->next->data = (element){5};
    head->next->next->next = NULL;

    // Checking if the linked list is a subpath of the binary tree
    if(isSubPath(head, root)) {
        printf("The linked list is a subpath of the binary tree.\n");
    } else {
        printf("The linked list is not a subpath of the binary tree.\n");
    }

    return 0;
}
