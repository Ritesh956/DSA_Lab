#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} CharStack;

typedef struct {
    int top;
    char items[MAX][MAX];
} StringStack;


void pushChar(CharStack* s, char value);
char popChar(CharStack* s);
char peekChar(CharStack* s);
int isEmptyChar(CharStack* s);
void pushString(StringStack* s, const char* value);
char* popString(StringStack* s);
char* peekString(StringStack* s);
int isEmptyString(StringStack* s);
void prefixToPostfix(const char* prefix, char* postfix);

int main() {
    char prefix[MAX];
    char postfix[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", prefix);

    prefixToPostfix(prefix, postfix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}

void pushChar(CharStack* s, char value) {
    if (s->top < (MAX - 1)) {
        s->items[++(s->top)] = value;
    } else {
        printf("Stack is full\n");
        exit(1);
    }
}

char popChar(CharStack* s) {
    if (!isEmptyChar(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

char peekChar(CharStack* s) {
    if (!isEmptyChar(s)) {
        return s->items[s->top];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

int isEmptyChar(CharStack* s) {
    return s->top == -1;
}

void pushString(StringStack* s, const char* value) {
    if (s->top < (MAX - 1)) {
        strcpy(s->items[++(s->top)], value);
    } else {
        printf("Stack is full\n");
        exit(1);
    }
}

char* popString(StringStack* s) {
    if (!isEmptyString(s)) {
        return s->items[(s->top)--];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

char* peekString(StringStack* s) {
    if (!isEmptyString(s)) {
        return s->items[s->top];
    } else {
        printf("Stack is empty\n");
        exit(1);
    }
}

int isEmptyString(StringStack* s) {
    return s->top == -1;
}

void prefixToPostfix(const char* prefix, char* postfix) {
    CharStack opStack;
    StringStack expStack;
    opStack.top = -1;
    expStack.top = -1;

    int length = strlen(prefix);

    for (int i = length - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isalnum(ch)) {
            char operand[2] = {ch, '\0'};
            pushString(&expStack, operand);
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {

            char* op1 = popString(&expStack);
            char* op2 = popString(&expStack);

            char result[MAX];
            snprintf(result, sizeof(result), "%s%s%c", op1, op2, ch);

            pushString(&expStack, result);
        }
    }

    strcpy(postfix, popString(&expStack));
}
