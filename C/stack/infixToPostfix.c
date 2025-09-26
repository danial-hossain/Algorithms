#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

char stackTop(struct stack *sp)
{
    if (sp->top == -1)
        return '\0';
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
        return '\0';
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
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}
char *infixToPostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = strlen(infix);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) *2) * sizeof(char));
    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (infix[i] == '(')
        {
            push(sp, infix[i]);
            i++;
        }
     

        else if (infix[i] == ')')
        {
            while (!isEmpty(sp) && stackTop(sp) != '(')
            {
                postfix[j] = pop(sp);
                j++;
            }
            pop(sp);
            i++;
        }
        else if ((!isOperator(infix[i])))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else if (precedence(infix[i]) > precedence(stackTop(sp)))
        {
            push(sp, infix[i]);
            i++;
        }
        else
        {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp)))
            {

                postfix[j] = pop(sp);
                j++;
                
            }
            push(sp, infix[i]); // Push current operator after popping higher precedence ones
            i++;
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    free(sp->arr);
    free(sp);
    return postfix;
}
    int main()
    {
        char *infix = "a+b*(c^d-e)^(f+g*h)-i";
        printf("postfix is %s", infixToPostfix(infix));
        return 0;
    }
