#ifndef _DOUBLE_LL_H_
#define _DOUBLE_LL_H_

#include <stdio.h>
#include <stdlib.h>
#include "../platform_Types.h"

typedef struct node
{
    uint32 Data;                    /*Node data*/
    struct node *LeftNodeLink;      /*Pointer to pervious node*/
    struct node *RightNodeLink;     /*Pointer to next node*/
}node_t;

typedef enum
{
    R_NOK,          /* Node operation not performed successfully */    
    R_OK,           /* Node operation performed successfully  */
    NULL_POINTER    /* NULL pointer passed to the Node */
}StatusRet_t;

/**
 * @brief   Insert node at beginning of linked list.
 * @param   (**list) Double pointer to the linked list head.
 * @param   (data) Inserted data.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t Insert_Node_At_Beginning(node_t **list, uint32 data);
/**
 * @brief   Insert node at end of linked list.
 * @param   (**list) Double pointer to the linked list head.
 * @param   (data) Inserted data.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t Insert_Node_At_End(node_t **list, uint32 data);
/**
 * @brief   Insert node after another node in linked list.
 * @param   (*list) Pointer to the linked list head.
 * @param   (data) Inserted data.
 * @param   (pos) Position of node that you want to insert node after.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t Insert_Node_After(node_t *list, uint32 data, uint32 pos);
/**
 * @brief   Insert node before another node in linked list.
 * @param   (**list) Double pointer to the linked list head.
 * @param   (data) Inserted data.
 * @param   (pos) Position of node that you want to insert node before.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t Insert_Node_Before(node_t **list, uint32 data, uint32 pos);
/**
 * @brief   Delete node from the beginning of linked list.
 * @param   (**list) Double pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t Delete_Node_At_Beginning(node_t **list);
/**
 * @brief   Delete node from the end of linked list.
 * @param   (**list) Double pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t Delete_Node_At_End(node_t **list);
/**
 * @brief   Delete specific node from linked list.
 * @param   (**list) Double pointer to the linked list head.
 * @param   (pos) Position of node that you want to delete.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t Delete_Node_At_Intermediate(node_t **list, uint32 pos);
/**
 * @brief   Display all data in the linked list.
 * @param   (*list) Pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t DisplayList(node_t *list);
/**
 * @brief   Display all data in the linked list (reversed).
 * @param   (*list) Pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t DisplayReverseList(node_t *list);
/**
 * @brief   Returns number of nodes in linked list.
 * @param   (*list) Pointer to the linked list head.
 * @retval  Number of nodes.
*/
uint32 Get_Length(node_t *list);
/**
 * @brief   Reverse nodes in the linked list.
 * @param   (**list) Double pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t ReverseList(node_t **list);
/**
 * @brief   Swap data of specific 2 nodes in the linked list.
 * @param   (*list) Pointer to the linked list head.
 * @param   (pos1) Position of first node.
 * @param   (pos2) Position of second node.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t Swap2Nodes(node_t *list, uint32 pos1, uint32 pos2);
/**
 * @brief   Sort data of nodes in the linked list.
 * @param   (*list) Pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t SortList(node_t *list);
/**
 * @brief   Print middle node in the linked list.
 * @param   (*list) Pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t PrintMiddleNode(node_t *list);
/**
 * @brief   Delete middle node in the linked list.
 * @param   (*list) Pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t DeleteMiddleNode(node_t *list);
/**
 * @brief   Deallocating all memory of linked list from the heap.
 * @param   (**list) Double pointer to the linked list head.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t DeleteList(node_t **list);
/**
 * @brief   Rotate linked list about specific Position.
 * @param   (**list) Double pointer to the linked list head.
 * @param   (pos) Position of node that list will rotate about.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t RotateList(node_t **list, uint32 pos);
/**
 * @brief   Print (pos)th node from the last of linked list.
 * @param   (*list) Pointer to the linked list head.
 * @param   (pos) Position of node.
 * @retval  Status returned while performing this operation.
*/
StatusRet_t PrintNthNodeFromLast(node_t *list, uint32 pos);


#endif //_DOUBLE_LL_H_