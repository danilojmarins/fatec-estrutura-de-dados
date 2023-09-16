#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct LinkedList
{
    struct Node* head;
};

struct LinkedList* createLinkedList()
{
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    return list;
}

void insertAtBeginning(struct LinkedList* list, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;

    return;
}

void insertAtEnd(struct LinkedList* list, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    struct Node* current = list->head;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

void insertAtPosition(struct LinkedList* list, int data, int position)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    int increment = 1;
    struct Node* current = list->head;

    if (position < 0)
    {
        printf("Posição não existe.");
    }

    while (increment < position)
    {
        if (current->next == NULL)
        {
            printf("Posição não existe.");
            return;
        }
        else
        {
            current = current->next;
            increment++;
        }
    }

    if (position == 0)
    {
        list->head = newNode;
        newNode->next = current;
        return;
    }

    struct Node* temp = current->next;

    current->next = newNode;
    newNode->next = temp;
}

void removeFirst(struct LinkedList* list)
{
    struct Node* temp = list->head;
    list->head = list->head->next;

    free(temp);
}

void removeLast(struct LinkedList* list)
{
    struct Node* current = list->head;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

    free(current->next->next);

    current->next = NULL;
}

void removeAtPosition(struct LinkedList* list, int position)
{
    if (position < 0)
    {
        printf("Posição não existe.");
        return;
    }

    if (position == 0)
    {
        removeFirst(list);
        return;
    }

    int increment = 0;
    struct Node* current = list->head;

    while (increment < position - 1)
    {
        if (current->next->next == NULL)
        {
            printf("Posição não existe.");
            return;
        }
        else
        {
            current = current->next;
            increment++;
        }
    }

    struct Node* temp = current->next;
    current->next = current->next->next;

    free(temp);

    return;
}

int findByValue(struct LinkedList* list, int value)
{
    struct Node* current = list->head;
    int position = 0;

    while (current != NULL)
    {
        if (current->data == value)
        {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1;
}

void findAllByValue(struct LinkedList* list, int value)
{
    struct Node* current = list->head;
    int position = 0;

    printf("\nPosições do valor %d: \n", value);

    while (current != NULL)
    {
        if (current->data == value)
        {
            printf("%d, ", position);
        }
        current = current->next;
        position++;
    }

    printf("\n");
}

void removeByValue(struct LinkedList* list, int value)
{
    int position = 0;

    while (position != -1)
    {
        position = findByValue(list, value);
        removeAtPosition(list, position);
    }
}

void displayList(struct LinkedList* list)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
}

void freeList(struct LinkedList* list)
{
    struct Node* current = list->head;

    while (current != NULL)
    {
        free(current);
        current = current->next;
    }

    free(list);
}

int main()
{
    struct LinkedList* list = createLinkedList();
 
    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtBeginning(list, 20);
    insertAtBeginning(list, 30);
    insertAtBeginning(list, 20);

    insertAtEnd(list, 20);
    insertAtEnd(list, 40);
    insertAtEnd(list, 50);
    insertAtEnd(list, 20);

    insertAtPosition(list, 60, 3);
    insertAtPosition(list, 20, 1);

    removeFirst(list);

    removeLast(list);

    removeAtPosition(list, 3);

    findAllByValue(list, 20);

    removeByValue(list, 20);

    displayList(list);

    return 0;
}