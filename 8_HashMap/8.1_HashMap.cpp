#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define TABLE_SIZE 10
 
struct HashNode {
    char *key;
    int value;
    struct HashNode *next;
};
 
struct HashNode *table[TABLE_SIZE] = { NULL };
 
unsigned long hash(char *key) {
    unsigned long hash = 5381;
    int c;
 
    while ((c = *key++)) {
        hash = ((hash << 5) + hash) + c;
    }
 
    return hash % TABLE_SIZE;
}
 
void insert(char *key, int value) {
    int index = hash(key);
    struct HashNode *newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}
 
int search(char *key) {
    int index = hash(key);
    struct HashNode *current = table[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}
 
void deleteByKey(char *key) {
    int index = hash(key);
    printf("\n%d\n", index);
    struct HashNode *current = table[index];
    while (current != NULL) {
        if (current == table[index]) {
            if (strcmp(current->key, key) == 0) {
                printf("%s", current->key);
                struct HashNode *temp = current;
                table[index] = current->next;
                free(temp);
                return;
            }
        }

        if (current->next != NULL) {
            if (strcmp(current->next->key, key) == 0) {
                printf("%s", current->next->key);
                struct HashNode *temp = current->next;
                current->next = current->next->next;
                free(temp);
                return;
            }
        }
 
        current = current->next;
    }

    printf("\nChave não encontrada.\n");
}
 
void displayTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
 
        struct HashNode *current = table[i];
 
        while (current != NULL) {
            printf("%d -> ", current->value);
            current = current->next;
        }
 
        printf("\n");
    }
}
 
int main() {
    insert("apple", 42);
    insert("banana", 17);
    insert("cherry", 73);
    insert("orange", 102);
    insert("melao", 5);
    insert("melancia", 21);
    insert("mamao", 249);
    insert("abobrinha", 1);
    insert("xuxu", 12);
    insert("beterraba", 15);
    insert("tomate", 136);
    insert("batata", 8);
    insert("limao", 95);
 
    printf("Value for 'apple': %d\n", search("apple"));
    printf("Value for 'banana': %d\n", search("banana"));
    printf("Value for 'cherry': %d\n", search("cherry"));
 
    displayTable();
 
    deleteByKey("melancia");
 
    printf("\n");
    printf("\n");
    printf("\n");
 
    displayTable();
 
    return 0;
}