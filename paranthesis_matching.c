//self

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr; // integer pointer by help of which we allocate dynamic memory
};

int isempty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
        return 0;
}

int isfull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
        return 0;
}

void push(struct stack *s, int value)
{
    if (isfull(s))
    {
        printf("stack over flow");
    }

    else
    {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct stack *s)
{
    if (isempty(s))
    {
        printf("stack under flow");
        return -1;
    }

    else
    {
        int x = s->arr[s->top];
        s->top--;
        return x;
    }
}

void check(struct stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        if (s->arr[i] == '(')
        {
            push(s, s->arr[i]);
        }
        if (s->arr[i] == ')')
        {
            pop(s);
        }
    }

    if (isempty(s))
    {
        printf("balanced expression");
    }
    else
    {
        printf("unbalanced expression");
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    push(s, '(');
    push(s, '7');
    push(s, '+');
    push(s, ')');
    push(s, ')');
    push(s, ')');

    check(s);
}