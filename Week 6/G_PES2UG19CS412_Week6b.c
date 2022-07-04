#include "6b.h"
stack *stack_initialize(int size)
{
    stack *stk = (stack *)malloc(sizeof(stack));
    stk->arr = (int *)malloc(size * sizeof(int));
    stk->top = -1;
    return stk;
}

void stack_push(stack *ptr_stack, int key)
{
    ptr_stack->top++;
    ptr_stack->arr[ptr_stack->top] = key;
}

void stack_pop(stack *ptr_stack)
{
    ptr_stack->top--;
}

int stack_is_empty(stack *ptr_stack)
{
    if (ptr_stack->top == -1)
        return 1;
    else
        return 0;
}

int stack_peek(stack *ptr_stack)
{
    return ptr_stack->arr[ptr_stack->top];
}

void stack_destroy(stack *ptr_stack)
{
    ptr_stack->top = -1;
    free(ptr_stack->arr);
}

void convert_infix_to_postfix(const char *source_infix, char *target_postfix)
{
    stack *stk = stack_initialize(2000);
    int j = 0;
    for (int i = 0; source_infix[i] != '\0'; i++)
    {
        if (source_infix[i] == '(' || source_infix[i] == '{' || source_infix[i] == '[' || source_infix[i] == '+' || source_infix[i] == '-' || source_infix[i] == '*' || source_infix[i] == '/')
        {
            stack_push(stk, source_infix[i]);
        }
        else if (source_infix[i] == ')' || source_infix[i] == '}' || source_infix[i] == ']')
        {
            switch (source_infix[i])
            {
            case ')':
            {
                while (stack_peek(stk) != '(')
                {
                    target_postfix[j] = stack_peek(stk);
                    stack_pop(stk);
                    j++;
                }
                stack_pop(stk);
                break;
            }
            case ']':
            {
                while (stack_peek(stk) != '[')
                {
                    target_postfix[j] = stack_peek(stk);
                    stack_pop(stk);
                    j++;
                }
                stack_pop(stk);
                break;
            }
            case '}':
            {
                while (stack_peek(stk) != '{')
                {
                    target_postfix[j] = stack_peek(stk);
                    stack_pop(stk);
                    j++;
                }
                stack_pop(stk);
                break;
            }
            default:
                break;
            }
        }
        else
        {
            target_postfix[j] = source_infix[i];
            j++;
        }
    }
    while (stack_is_empty(stk) == 0)
    {
        target_postfix[j] = stack_peek(stk);
        stack_pop(stk);
        j++;
    }
}