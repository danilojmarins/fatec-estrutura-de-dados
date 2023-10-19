/*
    Implementar as duas funções abaixo chamadas dentro do main.
    A primeira função cria uma lista simplesmente encadeada,
    a partir de uma lista duplamente encadeada.
    Já a segunda função imprime somente os elementos impares da lista.
    Por exemplo, uma lista com 5 elementos, imprime os valores dos nodes 1, 3 e 5.

    struct LinkedList* list2 = createLinkedList(list1);
    displayOddNodes(list2);
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct DoublyLinkedList
{
    struct Node* head;
    struct Node* tail;
};

struct NodeSimple
{
    int data;
    struct NodeSimple* next;
};

struct LinkedList
{
    struct NodeSimple* head;
};

struct DoublyLinkedList* createDoublyLinkedList()
{
    struct DoublyLinkedList* list = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

    list->head = NULL;
    list->tail = NULL;

    return list;
}

void insertAtEnd(struct DoublyLinkedList* list, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;

        return;
    }

    list->tail->next = newNode;
    list->tail = newNode;

    return;
}

void displayDoublyLinkedList(struct DoublyLinkedList* list)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
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

struct LinkedList* createLinkedList(struct DoublyLinkedList* doublyList)
{
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));

    list->head = NULL;

    struct Node* current = doublyList->tail;

    while (current != NULL)
    {
        struct NodeSimple* newNode = (struct NodeSimple*)malloc(sizeof(struct NodeSimple));

        newNode->data = current->data;
        newNode->next = list->head;
        list->head = newNode;

        current = current->prev;
    }

    return list;
}

void displayLinkedList(struct LinkedList* list)
{
    struct NodeSimple* current = list->head;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
}

void displayOddNodes(struct LinkedList* list)
{
    int counter = 1;
    struct NodeSimple* current = list->head;

    while (current != NULL)
    {
        if (counter % 2 != 0)
        {
            printf("%d -> ", current->data);
        }

        current = current->next;
        counter++;
    }
}

int main()
{
    struct DoublyLinkedList* list = createDoublyLinkedList();

    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);
    insertAtEnd(list, 40);
    insertAtEnd(list, 50);

    displayDoublyLinkedList(list);
    printf("\n");

    struct LinkedList* list2 = createLinkedList(list);

    displayLinkedList(list2);
    printf("\n");

    displayOddNodes(list2);
    printf("\n");

    return 0;
}