#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H

/*********************** Includes Section Start *************************/
#include <stdio.h>
#include <stdlib.h>
#include "../platform_Types.h"
/*********************** Includes Section End ***************************/

typedef struct
{
    void **QueueArray;      /* Pointer to array of void pointers */
    uint32 QueueMaxSize;    /* Maximum elements in the Queue */
    uint32 QueueCount;      /* Number of elements in the Queue */
    uint32 QueueFront;      /* Index of the front elements */
    uint32 QueueRear;       /* Index of the rear elements */
}Queue_t;

typedef enum
{
    QUEUE_NOK,          /* Queue operation not performed successfully */
    QUEUE_OK,           /* Queue operation performed successfully  */
    QUEUE_FULL,         /* Queue is full */
    QUEUE_EMPTY,        /* Queue is empty */
    QUEUE_NULL_POINTER  /* NULL pointer passed to the Queue */
}QueueStatus_t;

/**
  * @brief  This algorithm creates an empty queue by allocating the head
            structure and the array from dynamic memory.
  * @param  (maxSize) Maximum number of elements in queue
  * @param  (retStatus) Status returned while performing this operation
  * @retval Pointer to the allocated queue in the heap
  */
Queue_t *CreateQueue(uint32 maxSize, QueueStatus_t *retStatus);
/**
  * @brief   Add element in the end the queue.
  * @param   (my_Queue) Pointer to queue head.
  * @param   (itemPtr) Pointer to enqueued item.
  * @retval  Status returned while performing this operation.
  */
QueueStatus_t EnqueueElement(Queue_t *my_Queue, void *itemPtr);
/**
  * @brief   Delet element from the front of the queue.
  * @param   (my_Queue) Pointer to queue head.
  * @param   (retStatus) Status returned while performing this operation.
  * @retval  Pointer to the deleted item if successful, NULL if underflow.
  */
void *DequeueElement(Queue_t *my_Queue, QueueStatus_t *retStatus);
/**
  * @brief  Retrieves item on the front of the queue without changing the queue.
  * @param  (my_Queue) Pointer to queue head.
  * @param  (retStatus) Status returned while performing this operation.
  * @retval Pointer to the front item if successful, NULL if underflow.
  */
void *QueueFront(Queue_t *my_Queue, QueueStatus_t *retStatus);
/**
  * @brief  Retrieves item on the end of the queue without changing the queue.
  * @param  (my_Queue) Pointer to queue head.
  * @param  (retStatus) Status returned while performing this operation.
  * @retval Pointer to the end item if successful, NULL if underflow.
  */
void *QueueRear(Queue_t *my_Queue, QueueStatus_t *retStatus);
/**
  * @brief  Returns number of elements in queue.
  * @param  (my_Queue) Pointer to queue head.
  * @param  (retStatus) Status returned while performing this operation.
  * @retval number of elements in queue.
  */
uint32 GetQueueCount(Queue_t *my_Queue, QueueStatus_t *retStatus);
/**
  * @brief  Deallocating all memory of queue from the heap.
  * @param  (my_Queue) Pointer to queue head.
  * @param  (retStatus) Status returned while performing this operation.
  * @retval NULL.
  */
Queue_t *DetroyQueue(Queue_t *my_Queue, QueueStatus_t *retStatus);
/**
  * @brief  Display all integer data of the queue.
  * @param  (my_Queue) Pointer to queue head.
  * @retval Status returned while performing this operation.
  */
QueueStatus_t DisplayIntegerQueue(Queue_t *my_Queue);

#endif // _QUEUE_ARRAY_H