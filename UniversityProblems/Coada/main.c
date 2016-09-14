#include <stdio.h>

typedef struct coada{
    int data;
    struct coada *next;
}coada;

int pop_back(coada *head) {
		coada *curent = head;
		coada *val_del;
		int x;
		while (curent->next->next != NULL) {
			curent = curent->next;
		}
		val_del = curent->next;
		x = val_del->data;
		free(val_del);
		curent->next = NULL;
	return x;
}

void push_first(coada *head, int value){
    coada *newNod = (coada*)malloc(sizeof(coada));
    newNod->data = value;
    newNod = head->next;
    head->next = newNod;
}

void printCoada(coada *head){
    coada *curent = head;
    while(curent->next != NULL){
        curent = curent->next;
        printf(" %d ", curent->data);
    }
}

int main()
{
    coada *head = (coada*) malloc(sizeof(coada));
    head->next = NULL;

    push_first(head,5);
    push_first(head,6);
    push_first(head,7);

    printCoada(head);

    return 0;
}
