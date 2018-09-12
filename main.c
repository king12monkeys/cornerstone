#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;

struct ListNode{
    int data;
    ListNode *pre;
    ListNode *next;
};

void printNext(ListNode *p) {
    while (p) {
        printf("%d", p->data);
        p = p->next;
    }
}

void insertList(ListNode *preNode, int data) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->pre = preNode;
    newNode->next = preNode->next;
    if (preNode->next) {
        preNode->next->pre = newNode;
    }
    preNode->next = newNode;
}


int main() {
    ListNode a = {111, NULL, NULL};
    insertList(&a, 999);
    printNext(&a);
    return 0;
}
