#include "QueueArrayDS.h"

/**
  * @brief  Helper function to check if queue is empty.
  * @param  (my_Queue) Pointer to stack head.
  * @retval 1 if queue empty, 0 if not.
  */
static uint8 QueueIsEmpty(Queue_t *my_Queue);
/**
  * @brief  Helper function to check if queue is full.
  * @param  (my_Queue) Pointer to stack head.
  * @retval 1 if queue full, 0 if not.
  */
static uint8 QueueIsFull(Queue_t *my_Queue);



Queue_t *CreateQueue(uint32 maxSize, QueueStatus_t *retStatus)
{
    Queue_t *my_Queue = NULL;

    if (NULL == retStatus){}
    else
    {
        my_Queue = (Queue_t *)malloc(sizeof(Queue_t));
        if (NULL == my_Queue)
        {
            *retStatus = QUEUE_NULL_POINTER;
        }
        else
        {
            my_Queue->QueueArray = (void **)calloc(maxSize, sizeof(void *));
            if (NULL == my_Queue->QueueArray)
            {
                free(my_Queue);
                my_Queue = NULL;
                *retStatus = QUEUE_NULL_POINTER;
            }
            else
            {
                my_Queue->QueueCount = 0;
                my_Queue->QueueFront = -1;
                my_Queue->QueueRear = -1;
                my_Queue->QueueMaxSize = maxSize;
                *retStatus = QUEUE_OK;
            }
        }
        
    }
    
    return my_Queue;
}

QueueStatus_t EnqueueElement(Queue_t *my_Queue, void *itemPtr)
{
    QueueStatus_t retStatus = QUEUE_NOK;

    if ((NULL == my_Queue) || (NULL == itemPtr))
    {
        retStatus = QUEUE_NULL_POINTER;
    }
    else if (QueueIsFull(my_Queue))
    {
        retStatus = QUEUE_FULL;
    }
    
    else
    {
        if (-1 == my_Queue->QueueFront)
        {
            (my_Queue->QueueFront)++;
        }else{}

        if (++(my_Queue->QueueRear) == my_Queue->QueueMaxSize)
        {
            my_Queue->QueueRear = 0;
        }else{}

        my_Queue->QueueArray[my_Queue->QueueRear] = itemPtr;
        (my_Queue->QueueCount)++;

        retStatus = QUEUE_OK;
    }

    return retStatus;
}

void *DequeueElement(Queue_t *my_Queue, QueueStatus_t *retStatus)
{
    void *retPtr = NULL;

    if (NULL == retStatus){}
    else if (NULL == my_Queue)
    {
        *retStatus = QUEUE_NULL_POINTER;
    }
    else if (QueueIsEmpty(my_Queue))
    {
        *retStatus = QUEUE_EMPTY;
    }
    else
    {
        retPtr = my_Queue->QueueArray[my_Queue->QueueFront];

        if (++(my_Queue->QueueFront) == my_Queue->QueueMaxSize)
        {
            my_Queue->QueueFront = 0;
        }else{}

        (my_Queue->QueueCount)--;

        *retStatus = QUEUE_OK;
    }

    return retPtr;
}

void *QueueFront(Queue_t *my_Queue, QueueStatus_t *retStatus)
{
    void *retPtr = NULL;

    if (NULL == retStatus){}
    else if (NULL == my_Queue)
    {
        *retStatus = QUEUE_NULL_POINTER;
    }
    else if (QueueIsEmpty(my_Queue))
    {
        *retStatus = QUEUE_EMPTY;
    }
    else
    {
        retPtr = my_Queue->QueueArray[my_Queue->QueueFront];

        *retStatus = QUEUE_OK;
    }

    return retPtr;
}

void *QueueRear(Queue_t *my_Queue, QueueStatus_t *retStatus)
{
    void *retPtr = NULL;

    if (NULL == retStatus){}
    else if (NULL == my_Queue)
    {
        *retStatus = QUEUE_NULL_POINTER;
    }
    else if (QueueIsEmpty(my_Queue))
    {
        *retStatus = QUEUE_EMPTY;
    }
    else
    {
        retPtr = my_Queue->QueueArray[my_Queue->QueueRear];

        *retStatus = QUEUE_OK;
    }

    return retPtr;
}

uint32 GetQueueCount(Queue_t *my_Queue, QueueStatus_t *retStatus)
{
    uint32 count = 0;
    if (NULL == retStatus){}
    else if (NULL == my_Queue)
    {
        *retStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        count = my_Queue->QueueCount;

        *retStatus = QUEUE_OK;
    }

    return count;
}

Queue_t *DetroyQueue(Queue_t *my_Queue, QueueStatus_t *retStatus)
{
    if (NULL == retStatus){}
    else if (NULL == my_Queue)
    {
        *retStatus = QUEUE_NULL_POINTER;
    }
    else
    {
        free(my_Queue->QueueArray);
        free(my_Queue);
        my_Queue = NULL;
        *retStatus = QUEUE_OK;
    }

    return my_Queue;
}

QueueStatus_t DisplayIntegerQueue(Queue_t *my_Queue)
{
    QueueStatus_t ret = QUEUE_NOK;
    if (NULL == my_Queue)
    {
        ret = QUEUE_NULL_POINTER;
    }
    else
    {
        for (uint32 counter = my_Queue->QueueFront ; counter <= my_Queue->QueueRear; counter++)
        {
            printf("0x%X ", *((uint32 *)my_Queue->QueueArray[counter]));
        }
        printf("\n");
        ret = QUEUE_OK;
    }

    return ret;
}

static uint8 QueueIsEmpty(Queue_t *my_Queue)
{
    return (!(my_Queue->QueueCount));
}

static uint8 QueueIsFull(Queue_t *my_Queue)
{
    return (my_Queue->QueueCount == my_Queue->QueueMaxSize);
}