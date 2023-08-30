#ifndef _Stack_Array_DS_H_
#define _Stack_Array_DS_H_

/*********************** Includes Section Start *************************/
#include <stdio.h>
#include <stdlib.h>
#include "../platform_Types.h"
/*********************** Includes Section End ***************************/

typedef struct
{
    void **StackArray;      /* Points to the array that allocated in the heap */
    uint32 StackCount;      /* Has the actual number of elements in the stack */
    uint32 StackMaxSize;    /* Has the maximum number of elements in the stack */
    sint32 StackTop;        /* Has the index of the top element in the stack */
}Stack_t;

typedef enum
{
    STACK_NOK,           /* Stack operation not performed successfully */
    STACK_OK,            /* Stack operation performed successfully  */
    STACK_FULL,          /* Stack is full */
    STACK_EMPTY,         /* Stack is empty */
    STACK_NULL_POINTER   /* NULL pointer passed to the Stack operations */
}StackStatus_t;

/**
  * @brief  This algorithm creates an empty stack by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Maximum number of elements in stack
  * @param  (ret) Status returned while performing this operation
  * @retval Pointer to the allocated stack in the heap
  */
Stack_t* CreateStack (uint32 maxSize, StackStatus_t *ret);
/**
  * @brief  Deallocating all memory of stack from the heap
  * @param  (my_stack) Pointer to stack head
  * @param  (ret) Status returned pointer while performing this operation
  * @retval NULL
  */
Stack_t* DestroyStack (Stack_t* my_stack, StackStatus_t *ret);
/**
  * @brief  Push item onto the stack
  * @param  (my_stack) Pointer to stack head
  * @param  (itemPtr) Pointer to pushed item
  * @retval Status returned while performing this operation
  */
StackStatus_t PushStack (Stack_t* my_stack, void* itemPtr);
/**
  * @brief  Pops item on the top of the stack
  * @param  (my_stack) Pointer to stack head
  * @param  (ret) Status returned while performing this operation
  * @retval Pointer to the popped item if successful, NULL if underflow
  */
void* PopStack (Stack_t* my_stack, StackStatus_t *ret);
/**
  * @brief  Retrieves item on the top of the stack without changing the stack.
  * @param  (my_stack) Pointer to stack head
  * @param  (ret) Status returned while performing this operation
  * @retval Pointer to the popped item if successful, NULL if underflow
  */
void* StackTop (Stack_t* my_stack, StackStatus_t *ret);
/**
  * @brief  Returns number of elements in stack.
  * @param  (my_stack) Pointer to stack head
  * @param  (stack_count) number of elements in stack.
  * @retval Status returned while performing this operation
  */
StackStatus_t StackCount (Stack_t* my_stack, uint32 *stack_count);
/**
  * @brief  Display all integer data of the stack
  * @param  (my_stack) Pointer to stack head
  * @retval Status returned while performing this operation
  */
StackStatus_t DisplayIntegerStack(Stack_t* my_stack);

#endif // _Stack_Array_DS_H_