#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
typedef struct Stack Stack;

struct ListNode {
    int data;
    ListNode *pre;
    ListNode *next;
};

struct Stack {
    ListNode *top;
    int size;
};

void insertStack(Stack *stack, int data) {
    ListNode *current = (ListNode*)malloc(sizeof(ListNode));
    current->data = data;
    current->next = stack->top;
    stack->top = current;
    stack->size++;
}

void insertNode(ListNode *preNode, int data) {
//    ListNode current = {data, preNode, preNode->next};
    ListNode *current = (ListNode*)malloc(sizeof(ListNode));
    current->data = data;
    current->pre = preNode;
    current->next = preNode->next;
    preNode->next = current;
//    preNode->next = &current;
}

void printAll(ListNode *root) {
    while (root) {
        printf("%d", root->data);
        root = root->next;
    }
}

int main() {
//    ListNode a;
//    a.data = 1;
//    a.pre = NULL;
//    a.next = NULL;
//    insertNode(&a, 4);
//    insertNode(&a, 3);
//    insertNode(&a, 2);
//    printAll(&a);

    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    insertStack(stack, 1);
    insertStack(stack, 2);
    insertStack(stack, 3);
    insertStack(stack, 4);
    printAll(stack->top);
}
