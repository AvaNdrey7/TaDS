/* Стек с помощью списка и массива
 * операции удаления и добавления с
 * проверкой переполнения, операция
 * отображения текущего состояния стека */

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 8
#define TRUE 1
#define FALSE 0

typedef struct Node_t {
    int value;
    struct Node_t *next;
} List_t;

typedef unsigned char boolean;

boolean is_stack_empty(int end) {
    if (end == -1)
        return TRUE;
    else
        return FALSE; 
}

boolean is_stack_full(int end) {
    if (end == 7)
        return TRUE;
    else
        return FALSE;
}

int push(int *array, int *end, int value) {
    if (is_stack_full(*end)) {
        printf("Stack is full.\n");
        return -1;
    }
    
    array[++(*end)] = value;
    return 0;
}

int pop(int *end) {
    if (is_stack_empty(*end)) {
        printf("Stack is empty\n");
        return -1;
    }

    (*end)--;
    return 0;
}

void display(int *arr, int end) {
    printf("[");
    for (int i = 0; i < end; i++) {
        printf("%d, ", arr[i]);
    }
    if (!is_stack_empty(end)) {
        printf("%d", arr[end]);
    }
    printf("]\n");
}

void menu() {
    printf("Menu.\n0. Exit.\n1. Display.\n2. Push.\n3. Pop.");
}

int main(void) {
    
    int stack_array[STACK_SIZE];
    int stack_end = -1;
    
    int choice, value;

    do {
        menu();
        printf("\n\n>>> ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                break;
            case 1:
                display(stack_array, stack_end);
                break;
            case 2:
                printf("Input value: ");
                scanf("%d", &value);
                push(stack_array, &stack_end, value);
                break;
            case 3:
                pop(&stack_end);
                break;
            default:
                printf("Incorrect input.\n");
        }
    } while (choice != 0);
    
    return 0;
}
