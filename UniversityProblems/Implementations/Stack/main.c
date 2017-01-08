#include <stdio.h>

typedef struct stack{
    int data;
    struct stack *next;
}stack;


void push_back(stack *head, int value) {
    stack *current = head;
    stack *new_value;
    new_value = (stack*)malloc(sizeof(stack));

    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_value;
    new_value->data = value;
    new_value->next = NULL;
}

int pop_back(stack *head){
    stack *curent = head;
    stack *delNod;
    int value;
    while(curent->next->next != NULL){
        curent = curent->next;
    }
    delNod = curent->next;
    value = delNod->data;
    curent->next = delNod->next;
    free(delNod);
    return value;
}

void printStack(stack *head){
    stack *curent = head;
    while(curent->next != NULL){
        curent = curent->next;
        printf(" %d ", curent->data);
    }
}

int main(){

    stack *head = (stack*)malloc(sizeof(stack));
    head->next = NULL;

    push_back(head,3);
    push_back(head,4);
    push_back(head,6);

    printStack(head);

    printf("\n%d \n", pop_back(head));
    printStack(head);
    return 0;
}
