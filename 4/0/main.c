/* Стек с помощью списка и массива
 * операции удаления и добавления с
 * проверкой переполнения, операция
 * отображения текущего состояния стека */

#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE  8
#define TRUE        1
#define FALSE       0
#define ARRAY       0
#define LIST        1

typedef struct Node_t {
    int value;
    struct Node_t *next;
} list_t;

typedef unsigned char boolean;
typedef int type;

typedef struct {
    int sp;
    type status;
    int *array;
    list_t *list;
} stack_t;

list_t *create_node(int value) {
    list_t *node = malloc(sizeof(list_t));
    if (node) {
        node->value = value;
        node->next = NULL;
    }
    return node;
}

stack_t *stack_init(type status, int *array, list_t *head) {
    stack_t *Stack = malloc(sizeof(stack_t));
    if (Stack) {
        Stack->sp = -1;
        Stack->array = array;
        Stack->list = head;
        Stack->status = status;
    }
    return Stack;
}

boolean is_stack_empty(stack_t *Stack) {
    if (Stack->sp == -1) {
        return TRUE;
    }
    else {
        return FALSE; 
    }
}

boolean is_stack_full(stack_t *Stack) {
    if (Stack->sp == (STACK_SIZE-1)) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int push(stack_t *Stack, int value) {
    if (is_stack_full(Stack)) {
        printf("Stack is full.\n");
        return -1;
    }
    (Stack->sp)++; 

    if (Stack->status == ARRAY) {
        Stack->array[Stack->sp] = value;
    }
    else if (Stack->status == LIST) {
        list_t *node = create_node(value);
        node->next = Stack->list;
        Stack->list = node;
    }
    return 0;
}

int pop(stack_t *Stack) {
    if (is_stack_empty(Stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    (Stack->sp)--;

    if (Stack->status == LIST) {
        list_t *tmp = Stack->list->next;
        free(Stack->list);
        Stack->list = tmp;
    }
    return 0;
}

void display(stack_t *Stack) {
    if (Stack->status == LIST) {
        printf("[");
        if (!is_stack_empty(Stack)) {
            list_t *tmp = Stack->list;
            for ( ; tmp->next; tmp = tmp->next) {
                printf("%d, ", tmp->value);
            }
            printf("%d", tmp->value);
        }
        printf("]");
        printf("\n");
    }
    else { 
        printf("[");
        for (int i = Stack->sp; i > 0; i--) {
            printf("%d, ", Stack->array[i]);
        }
        if (!is_stack_empty(Stack)) {
            printf("%d", Stack->array[0]);
        }
        printf("]\n");
    }
}

void menu() {
    printf("Menu.\n0. Exit.\n1. Display.\n2. Push.\n3. Pop.");
}

int main(void) {
    type TYPE;
    printf("Type of stack:\n");
    printf("0. Array.\n1. List.\n>>> ");
    scanf("%d", &TYPE);
    
    int array[STACK_SIZE];
    list_t *list = NULL;
    stack_t *Stack = stack_init(TYPE, array, list);
    
    int choice, value;

    do {
        menu();
        printf("\n\n>>> ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                break;
            case 1:
                display(Stack);
                break;
            case 2:
                printf("Input value: ");
                scanf("%d", &value);
                push(Stack, value);
                break;
            case 3:
                pop(Stack);
                break;
            default:
                printf("Incorrect input.\n");
        }
    } while (choice != 0);
    
    return 0;
}
