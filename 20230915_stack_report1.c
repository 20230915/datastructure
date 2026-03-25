#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %c\n", value);
        return;
    }
    s->data[++(s->top)] = value;
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop\n");
        return '\0';
    }
    return s->data[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return '\0';
    }
    return s->data[s->top];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c ", s->data[i]);
    }
    printf("\n");
}

int main(void) {
    Stack s;
    char str[MAX];
    initStack(&s);

    printf("문자열을 입력하세요: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")]='\0';
    for (int i = 0; str[i] != '\0'; i++)
      push(&s, str[i]);
    
    printf("거꾸로 출력된 문자열: ");
    while(!isEmpty(&s)) {
        printf("%c", pop(&s));
    }
    printf("\n");

    return 0;
}