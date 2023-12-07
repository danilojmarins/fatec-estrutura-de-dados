#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int num = 0;

struct Node* insert(struct Node* root, char* str, int* index) {

    if (str[*index] == '(' || str[*index] == ')' || str[*index] == ' ') {
        (*index)++;
        return insert(root, str, index);
    }

    if (root == NULL) {
        if (str[*index] == '+' || str[*index] == '-' || str[*index] == '*' || str[*index] == '/') {
            printf("\ncreated: %c\n", str[*index]);
            root = createNode(str[*index]);
            (*index)++;
            root->left = insert(root->left, str, index);
            (*index)++;
            root->right = insert(root->right, str, index);
        }
        else if (isdigit(str[*index])) {
            printf("\ncreated: %c\n", str[*index]);
            return createNode(str[*index]);
        }
    }

    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c", root->value);
        inorderTraversal(root->right);
    }
}

int calculateTree(struct Node* root) {
    if (root != NULL) {
        if (root->value == '+') {
            return calculateTree(root->left) + calculateTree(root->right);
        }
        else if (root->value == '-') {
            return calculateTree(root->left) - calculateTree(root->right);
        }
        else if (root->value == '*') {
            return calculateTree(root->left) * calculateTree(root->right);
        }
        else if (root->value == '/') {
            return calculateTree(root->left) / calculateTree(root->right);
        }
        else if (isdigit(root->value)) {
            return root->value - '0';
        }
    }
    
    return 0;
}

int main() {
    struct Node* root;
    char str[] = "(- (* 2 (+ 3 5)) (/ 8 2))";

    int index = 0;

    root = insert(root, str, &index);

    inorderTraversal(root);

    int result = calculateTree(root);

    printf("\nresult: %d\n", result);

    return 0;
}