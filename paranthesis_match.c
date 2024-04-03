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

void push(struct stack *s, char value)
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

char pop(struct stack *s)
{
    if (isempty(s))
    {
        printf("stack under flow");
        return -1;
    }

    else
    {
        char value = s->arr[s->top];
        s->top--;
        return value;
    }
}

int paranthesisMatch(char *exp)
{
    // create and initialize the stack
    struct stack *s;
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)  // \0 is a NULL Character
    {
        if (exp[i] == '(')
        {
            push(s, '(');
        }
        else if (exp[i] == ')')
        {
            if (isempty(s))
            {
                return 0;
            }
            pop(s);
        }
    }

    if(isempty(s))
    {
        return 1;
    }
    else
    {
       return 0;
    }
}

int main()
{
    char *exp = "(8)(*--$$9";
    // Check if stack is empty
    if (paranthesisMatch(exp))
    {
        printf("The paranthesis is matching");
    }
    else
    {
        printf("The paranthesis is not matching");
    }
    return 0;
}