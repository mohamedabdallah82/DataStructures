#include "StackArrayDS.h"
/**
  * @brief  Helper function to check if stack is empty.
  * @param  (my_stack) Pointer to stack head.
  * @retval 1 if stack empty, 0 if not.
  */
static uint8 StackIsEmpty (Stack_t* my_stack);
/**
  * @brief  Helper function to check if stack is full.
  * @param  (my_stack) Pointer to stack head.
  * @retval 1 if stack full, 0 if not.
  */
static uint8 StackIsFull (Stack_t* my_stack);



Stack_t* CreateStack (uint32 maxSize, StackStatus_t *ret)
{
    Stack_t *my_stack = NULL;
    if (NULL == ret)
    {
        my_stack = NULL;
    }
    else
    {
        my_stack = (Stack_t *)malloc(sizeof(Stack_t));
        
        if (NULL != my_stack)
        {
            my_stack->StackCount = 0;
            my_stack->StackTop = -1;
            my_stack->StackMaxSize = maxSize;
            my_stack->StackArray = (void **)calloc(maxSize, sizeof(void *));
            if (NULL != my_stack->StackArray)
            {
                *ret = STACK_OK;
            }
            else
            {
                free(my_stack);
                my_stack = NULL;
                *ret = STACK_NOK;
            }
        }
        else
        {
            *ret = STACK_NOK;
        }
    }

    return my_stack;
}

Stack_t* DestroyStack (Stack_t* my_stack, StackStatus_t *ret)
{
    if (NULL == ret)
    {}
    else if (NULL == my_stack)
    {
        *ret = STACK_NULL_POINTER;
    }
    else
    {
        free(my_stack->StackArray);
        free(my_stack);
        my_stack = NULL;
        *ret = STACK_OK;
    }

    return my_stack;
}

StackStatus_t PushStack (Stack_t* my_stack, void* itemPtr)
{
    StackStatus_t ret = STACK_NOK;

    if ((NULL == itemPtr) || (NULL == my_stack))
    {
        ret = STACK_NULL_POINTER;
    }
    else if (StackIsFull(my_stack))
    {
        ret = STACK_FULL;
    }
    else
    {
        (my_stack->StackTop)++;
        (my_stack->StackCount)++;
        my_stack->StackArray[my_stack->StackTop] = itemPtr;
        ret = STACK_OK;
    }

    return ret;
}

void* PopStack (Stack_t* my_stack, StackStatus_t *ret)
{
    void* retPtr = NULL;

    if (NULL == ret)
    {}
    else if (NULL == my_stack)
    {
        *ret = STACK_NULL_POINTER;
    }
    else if (StackIsEmpty(my_stack))
    {
        *ret = STACK_EMPTY;
    }
    else
    {
        retPtr = my_stack->StackArray[my_stack->StackTop];
        (my_stack->StackTop)--;
        (my_stack->StackCount)--;
        *ret = STACK_OK;
    }

    return retPtr;
}

void* StackTop (Stack_t* my_stack, StackStatus_t *ret)
{
    void* retPtr = NULL;

    if (NULL == ret)
    {}
    else if (NULL == my_stack)
    {
        *ret = STACK_NULL_POINTER;
    }
    else if (StackIsEmpty(my_stack))
    {
        *ret = STACK_EMPTY;
    }
    else
    {
        retPtr = my_stack->StackArray[my_stack->StackTop];
        *ret = STACK_OK;
    }

    return retPtr;
}

StackStatus_t StackCount (Stack_t* my_stack, uint32 *stack_count)
{
    StackStatus_t ret = STACK_NOK;

    if (NULL == stack_count)
    {
        ret = STACK_NULL_POINTER;
    }
    else if (NULL == my_stack)
    {
        *stack_count = my_stack->StackCount;
        ret = STACK_NULL_POINTER;
    }
    else
    {
        *stack_count = my_stack->StackCount;
        ret = STACK_OK;
    }

    return ret;
}

StackStatus_t DisplayIntegerStack(Stack_t* my_stack)
{
    StackStatus_t ret = STACK_NOK;

    if (NULL == my_stack)
    {
        printf("Empty Stack !!!\n");
        ret = STACK_NULL_POINTER;
    }
    else if (StackIsEmpty(my_stack))
    {
        printf("Empty Stack !!!\n");
        ret = STACK_EMPTY;
    }
    else
    {
        uint32 index = 0;
        for (index = 0 ; index < my_stack->StackCount ; index++)
        {
            printf("%i\t", *((uint32 *)(my_stack->StackArray[index])));
        }
        printf("\n");
        ret = STACK_OK;
    }
    return ret;
}

static uint8 StackIsEmpty (Stack_t* my_stack) // my_stack not NULL pointer
{
    return (0 == my_stack->StackCount);
}

static uint8 StackIsFull (Stack_t* my_stack) // my_stack not NULL pointer
{
    return (my_stack->StackMaxSize == my_stack->StackCount);
}