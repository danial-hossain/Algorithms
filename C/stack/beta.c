#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int stackTop(struct stack *sp)
{
    if (sp->top == -1)
        return -1; // Return a special value when stack is empty
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(sp, infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty(sp) && stackTop(sp) != '(')
            {
                postfix[j++] = pop(sp);
            }
            pop(sp); // Remove '(' from the stack
        }
        else if (!isOperator(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp)))
            {
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i]);
        }
        i++;
    }

    while (!isEmpty(sp))
    {
        postfix[j++] = pop(sp);
    }

    postfix[j] = '\0';

    free(sp->arr);
    free(sp);
    
    return postfix;
}

int main()
{
    char *infix = "a+b*(c^d-e)^(f+g*h)-i";
    char *postfix = infixToPostfix(infix);
    printf("Postfix is %s\n", postfix);
    free(postfix);
    return 0;
}
