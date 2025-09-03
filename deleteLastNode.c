#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* link;
};
typedef struct node NODE;

NODE* traverseList(NODE* head)
{
    NODE* ptr = head;
    while(ptr != NULL)
    {
        printf("%d  ", ptr -> data);
        ptr = ptr -> link;
    }
    return head;
}

NODE* deleteLastNode(NODE* head)
{
    NODE* p = head;
    NODE* q = head -> link;
    while(q -> link != NULL)
    {
        p = p -> link;
        q = q -> link;
    }
    p -> link = q -> link;
    free(q);
    return head;
}

int main()
{
    NODE* head = (NODE*) malloc(sizeof(NODE));
    NODE* first = (NODE*) malloc(sizeof(NODE));
    NODE* second = (NODE*) malloc(sizeof(NODE));
    NODE* third = (NODE*) malloc(sizeof(NODE));
    NODE* fourth = (NODE*) malloc(sizeof(NODE));
    head -> data = 10;
    head -> link = first;
    first -> data = 20;
    first -> link = second;
    second -> data = 30;
    second -> link = third;
    third -> data = 40;
    third -> link = fourth;
    fourth -> data = 50;
    fourth -> link = NULL;
    traverseList(head); //before deletion
    head = deleteLastNode(head);
    traverseList(head); //after deletion
    return 0;
}