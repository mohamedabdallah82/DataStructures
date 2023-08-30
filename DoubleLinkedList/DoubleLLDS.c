#include "DoubleLLDS.h"

StatusRet_t Insert_Node_At_Beginning(node_t **list, uint32 data)
{
    StatusRet_t ret = R_NOK;
    node_t *tempNode = NULL;

    tempNode = (node_t *)malloc(sizeof(node_t));
    if (NULL == tempNode)
    {
        ret = NULL_POINTER;
    }
    else
    {
        tempNode->Data = data;

        if (NULL == *list)
        {
            tempNode->RightNodeLink = NULL;
            tempNode->LeftNodeLink = NULL;
            *list = tempNode;
        }
        else
        {
            tempNode->RightNodeLink = (*list);
            tempNode->LeftNodeLink = NULL;
            (*list)->LeftNodeLink = tempNode;
            *list = tempNode;
        }

        ret = R_OK;
    }
    return ret;
}


StatusRet_t Insert_Node_At_End(node_t **list, uint32 data)
{
    StatusRet_t ret = R_NOK;
    node_t *tempNode = NULL;
    node_t *lastNode = *list;

    tempNode = (node_t *)malloc(sizeof(node_t));
    if (NULL == tempNode)
    {
        ret = NULL_POINTER;
    }
    else
    {
        tempNode->Data = data;

        if (NULL == *list)
        {
            tempNode->RightNodeLink = NULL;
            tempNode->LeftNodeLink = NULL;
            *list = tempNode;
        }
        else
        {
            while (NULL != lastNode->RightNodeLink)
            {
                lastNode = lastNode->RightNodeLink;
            }
            
            lastNode->RightNodeLink = tempNode;
            tempNode->LeftNodeLink = lastNode;
            tempNode->RightNodeLink = NULL;
        }

        ret = R_OK;
    }
    return ret;
}

StatusRet_t Insert_Node_After(node_t *list, uint32 data, uint32 pos)
{
    StatusRet_t ret = R_NOK;
    node_t *tempNode = NULL;

    tempNode = (node_t *)malloc(sizeof(node_t));
    if ((NULL == tempNode) || (NULL == list))
    {
        ret = NULL_POINTER;
    }
    else
    {
        while ((--pos) && (list->RightNodeLink))
        {
            list = list->RightNodeLink;
        }
        if (pos)
        {
            printf("Invalid Pos !!!\n");
            ret = R_NOK;
        }
        else
        {
            if (NULL != list->RightNodeLink)
            {
                list->RightNodeLink->LeftNodeLink = tempNode;
            }
            else{}
            tempNode->Data = data;
            tempNode->RightNodeLink = list->RightNodeLink;
            tempNode->LeftNodeLink = list;
            list->RightNodeLink = tempNode;
            
            ret = R_OK;
        }   
    }
    return ret;
}


StatusRet_t Insert_Node_Before(node_t **list, uint32 data, uint32 pos)
{
    StatusRet_t ret = R_NOK;
    node_t *tempNode = NULL;
    node_t *counterNode = *list;

    tempNode = (node_t *)malloc(sizeof(node_t));
    if ((NULL == tempNode) || (NULL == *list))
    {
        ret = NULL_POINTER;
    }
    else
    {
        while ((--pos) && (counterNode->RightNodeLink))
        {
            counterNode = counterNode->RightNodeLink;
        }
        if (pos)
        {
            printf("Invalid Pos !!!\n");
            ret = R_NOK;
        }
        else
        {
            tempNode->Data = data;
            if (NULL == counterNode->LeftNodeLink)
            {
                (*list) = tempNode;
            }
            else
            {
                counterNode->LeftNodeLink->RightNodeLink = tempNode;
            }
            tempNode->LeftNodeLink = counterNode->LeftNodeLink;
            tempNode->RightNodeLink = counterNode;
            counterNode->LeftNodeLink = tempNode;
            
            ret = R_OK;
        }   
    }
    return ret;
}

StatusRet_t Delete_Node_At_Beginning(node_t **list)
{
    StatusRet_t ret = R_NOK;
    if (NULL == *list)
    {
        printf("List is empty !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        node_t *tempNode = *list;
        *list = (*list)->RightNodeLink;
        tempNode->LeftNodeLink = NULL;
        free(tempNode);
        tempNode = NULL;
        if (*list)
        {
            (*list)->LeftNodeLink = NULL;
        }
        else{}

        ret = R_OK;
    }
    return ret;
}

StatusRet_t Delete_Node_At_End(node_t **list)
{
    StatusRet_t ret = R_NOK;
    if (NULL == (*list))
    {
        printf("List is empty !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        node_t *tempNode = *list;
        while (NULL != tempNode->RightNodeLink)
        {
            tempNode = tempNode->RightNodeLink;
        }
        if (tempNode->LeftNodeLink)
        {
            tempNode->LeftNodeLink->RightNodeLink = NULL;
            tempNode->LeftNodeLink = NULL;
            free(tempNode);
            tempNode = NULL;
        }
        else
        {
            (*list)->LeftNodeLink = NULL;
            free((*list));
            (*list) = NULL;
        }
    
        ret = R_OK;
    }
    return ret;
}

StatusRet_t Delete_Node_At_Intermediate(node_t **list, uint32 pos)
{
    StatusRet_t ret = R_NOK;
    
    if (NULL == (*list))
    {
        printf("List is empty !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        if (1 == pos)
        {
            ret = Delete_Node_At_Beginning(&(*list));
        }
        else
        {
            node_t *tempNode = *list;
            while ((--pos) && (tempNode->RightNodeLink))
            {
                tempNode = tempNode->RightNodeLink;
            }
            if (pos)
            {
                printf("Invalid Pos !!!\n");
                ret = R_NOK;
            }
            else
            {
                if (NULL == tempNode->RightNodeLink)
                {
                    Delete_Node_At_End(&(*list));
                }
                else
                {
                    tempNode->LeftNodeLink->RightNodeLink = tempNode->RightNodeLink;
                    tempNode->RightNodeLink->LeftNodeLink = tempNode->LeftNodeLink;
                    tempNode->LeftNodeLink = NULL;
                    tempNode->RightNodeLink = NULL;
                    free(tempNode);
                    tempNode = NULL;
                }
            
                ret = R_OK;
            }
        }
    }
        
    return ret;
}

StatusRet_t DisplayList(node_t *list)
{
    StatusRet_t ret = R_NOK;

    printf("List : ");

    if (NULL == list)
    {
        printf("is empty !!\n");
        ret = NULL_POINTER;
    }
    else
    {
        while (NULL != list)
        {
            printf("%i -> ", list->Data);
            list = list->RightNodeLink;
        }
        printf("NULL\n");
        
        ret = R_OK;
    }

    return ret;
}

StatusRet_t DisplayReverseList(node_t *list)
{
    StatusRet_t ret = R_NOK;

    printf("Reverse List : ");

    if (NULL == list)
    {
        printf("is empty !!\n");
        ret = NULL_POINTER;
    }
    else
    {
        while (NULL != list->RightNodeLink)
        {
            list = list->RightNodeLink;
        }

        while (NULL != list)
        {
            printf("%i -> ", list->Data);
            list = list->LeftNodeLink;
        }
        printf("NULL\n");
        
        ret = R_OK;
    }

    return ret;
}


uint32 Get_Length(node_t *list)
{
    uint32 len = 0;

    while (list)
    {
        list = list->RightNodeLink;
        len++;
    }
        
    return len;
}


StatusRet_t ReverseList(node_t **list)
{
    StatusRet_t ret = R_NOK;
    node_t *tempNode = *list;
    node_t *tempPtr = NULL;

    if (NULL == *list)
    {
        printf("List is empty !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        /*traversal to last node*/
        while (tempNode->RightNodeLink)
        {
            tempNode = tempNode->RightNodeLink;
        }
        /*make head pointer point to last node*/
        (*list) = tempNode;
        while (tempNode)
        {
            /*swap between RightNodeLink and LeftNodeLink*/
            tempPtr = tempNode->RightNodeLink;
            tempNode->RightNodeLink = tempNode->LeftNodeLink;
            tempNode->LeftNodeLink = tempPtr;
            /*shifting to previous node*/
            tempNode = tempNode->RightNodeLink;
        }

        ret = R_OK;
    }
    return ret;
}


StatusRet_t Swap2Nodes(node_t *list, uint32 pos1, uint32 pos2)
{
    StatusRet_t ret = R_NOK;
    uint32 len = Get_Length(list);
    uint32 temp = 0;
    node_t *node1 = list;
    node_t *node2 = list;

    if ((NULL == list) || (0 >= pos1) || (0 >= pos2) || (pos1 > len) || (pos2 > len))
    {
        printf("Can't Swap !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        while (--pos1)
        {
            node1 = node1->RightNodeLink;
        }
        while (--pos2)
        {
            node2 = node2->RightNodeLink;
        }
        temp = node1->Data;
        node1->Data = node2->Data;
        node2->Data = temp;
        
        ret = R_OK;
    }
    return ret;
}

StatusRet_t SortList(node_t *list)
{
    StatusRet_t ret = R_NOK;
    uint32 temp = 0;
    uint32 len = Get_Length(list);
    node_t *tempNode = NULL;

    if (NULL == list)
    {
        printf("Can't Sort !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        while (len--)
        {
            tempNode = list;
            while (tempNode->RightNodeLink)
            {
                if ((tempNode->Data) > (tempNode->RightNodeLink->Data))
                {
                    temp = tempNode->Data;
                    tempNode->Data = tempNode->RightNodeLink->Data;
                    tempNode->RightNodeLink->Data = temp;
                }
                else{}
                tempNode = tempNode->RightNodeLink;
            }
        }
        
        ret = R_OK;
    }
    return ret;
}


StatusRet_t PrintMiddleNode(node_t *list)
{
    StatusRet_t ret = R_NOK;
    uint32 len = Get_Length(list);
    uint32 pos = (len + 1) / 2;

    if (2 >= len)
    {
        printf("Can't find middle (List have %i node)\n", len);
    }
    else
    {
        while (--pos)
        {
            list = list->RightNodeLink;
        }
        printf("Middle node data = %i\n", list->Data);
        
        ret = R_OK;
    }
    return ret;
}

StatusRet_t DeleteMiddleNode(node_t *list)
{
    StatusRet_t ret = R_NOK;
    uint32 len = Get_Length(list);
    uint32 pos = (len + 1) / 2;

    if (2 >= len)
    {
        printf("Can't find middle (List have %i node)\n", len);
    }
    else
    {
        while (--pos)
        {
            list = list->RightNodeLink;
        }
        list->RightNodeLink->LeftNodeLink = list->LeftNodeLink;
        list->LeftNodeLink->RightNodeLink = list->RightNodeLink;
        list->RightNodeLink = NULL;
        list->LeftNodeLink = NULL;
        free(list);
        list = NULL;
        
        ret = R_OK;
    }
    return ret;
}


StatusRet_t DeleteList(node_t **list)
{
    StatusRet_t ret = R_NOK;

    if (NULL == *list)
    {
        printf("Deleted List !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        while ((*list)->RightNodeLink)
        {
            *list = (*list)->RightNodeLink;
            (*list)->LeftNodeLink->RightNodeLink = NULL;
            free((*list)->LeftNodeLink);
            (*list)->LeftNodeLink = NULL;
        }
        free(*list);
        (*list) = NULL;
        
        ret = R_OK;
    }

    return ret;
}


StatusRet_t RotateList(node_t **list, uint32 pos)
{
    StatusRet_t ret = R_NOK;
    node_t *tempNode = *list;

    if (NULL == *list)
    {
        printf("List is empty !!!\n");
        ret = NULL_POINTER;
    }
    else if ((0 >= pos) || (pos > Get_Length(*list)))
    {
        printf("Invalid pos !!!\n");
        ret = R_NOK;
    }
    else
    {
        /*traversal to last node*/
        while (tempNode->RightNodeLink)
        {
            tempNode = tempNode->RightNodeLink;
        }
        /*make list => circular*/
        tempNode->RightNodeLink = (*list);
        (*list)->LeftNodeLink = tempNode;

        tempNode = (*list);
        /*traversal to (pos)th node*/
        while (--pos)
        {
            tempNode = tempNode->RightNodeLink;
        }
        /*make head pointer point to (pos)th node*/
        (*list) = tempNode;
        (*list)->LeftNodeLink->RightNodeLink = NULL;
        (*list)->LeftNodeLink = NULL;

        ret = R_OK;
    }
    return ret;
}


StatusRet_t PrintNthNodeFromLast(node_t *list, uint32 pos)
{
    StatusRet_t ret = R_NOK;
    uint32 len = Get_Length(list);

    if (NULL == list)
    {
        printf("List is empty !!!\n");
        ret = NULL_POINTER;
    }
    else if ((0 >= pos) || (pos > len))
    {
        printf("Invalid pos !!!\n");
        ret = R_NOK;
    }
    else
    {
        printf("(%i)th node data from last = ", pos);
        pos = (len - pos + 1);
        while (--pos)
        {
            list = list->RightNodeLink;
        }
        printf("%i\n", list->Data);
        
        ret = R_OK;
    }
    return ret;
}