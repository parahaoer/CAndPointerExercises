# include<stdio.h>

typedef struct Node
{
    int val;
    struct Node *next;
} Node;

void callBack(void *node) {

    printf("%d ", ((Node *) node) -> val);
}

void traverse(Node *head, void (*callBack)(void *node)) {
    while (head != NULL) {
        callBack(head);
        head = head -> next;
    }
}

int main(int argc, char const *argv[])
{
    Node *head = (Node *) malloc(sizeof(Node));
    Node *node1 = (Node *) malloc(sizeof(Node));
    Node *node2 = (Node *) malloc(sizeof(Node));

    head -> val = 1;
    head -> next = node1;
    node1 -> val = 2;
    node1 -> next = node2;
    node2 -> val = 3;
    node2 -> next = NULL;

    traverse(head, callBack);
    return 0;
}

