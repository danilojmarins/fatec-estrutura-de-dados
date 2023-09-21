#include <stdio.h>
#include <stdlib.h>

struct DoublyLinkedList
{
    struct Node* head;
    struct Node* tail;
};

struct Node
{
    struct Node* next;
    struct Node* prev;
    int data;
};

struct DoublyLinkedList* createDoublyLinkedList()
{
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

void insertOrdered(struct DoublyLinkedList* list, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;

        return;
    }

    struct Node* current = list->head;

    while (current->data < newNode->data)
    {
        if (current->next == NULL)
        {
            break;
        }

        if (current->next->data > newNode->data)
        {
            break;
        }

        current = current->next;
    }

    if (current->data > newNode->data && current->prev == NULL)
    {
        list->head = newNode;
        newNode->prev = NULL;
        newNode->next = current;
        current->prev = newNode;

        return;
    }

    if (current->data == newNode->data)
    {
        printf("\nNão é possível inserir valores repetidos. \n");
        return;
    }
    
    if (current->next == NULL)
    {
        current->next = newNode;
        newNode->prev = current;
        newNode->next = NULL;
        list->tail = newNode;
        
        return;
    }

    current->next->prev = newNode;
    newNode->next = current->next;
    current->next = newNode;
    newNode->prev = current;

    return;
}

void displayDoublyLinkedList(struct DoublyLinkedList* list)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        printf("%d ->", current->data);
        current = current->next;
    }
}

void freeDoublyLinkedList(struct DoublyLinkedList* list)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    free(list);
}

int main()
{
    struct DoublyLinkedList* list = createDoublyLinkedList();

    insertOrdered(list, 5);
    insertOrdered(list, 2);
    insertOrdered(list, 1);
    insertOrdered(list, 30);
    insertOrdered(list, 20);
    insertOrdered(list, 10);
    insertOrdered(list, 0);
    insertOrdered(list, 13);
    insertOrdered(list, 15);
    insertOrdered(list, 20);

    displayDoublyLinkedList(list);

    freeDoublyLinkedList(list);

    return 0;
}