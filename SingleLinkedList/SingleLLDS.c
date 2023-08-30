#include "SingleLLDS.h"

StatusRet_t Insert_Node_At_Beginning(node_t **list)
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
        printf("Enter Node Data : ");
        scanf("%i", &tempNode->data);

        if (NULL == *list)
        {
            tempNode->nodeLink = NULL;
            *list = tempNode;
        }
        else
        {
            tempNode->nodeLink = *list;
            *list = tempNode;
        }
        
        ret = R_OK;
    }
    
    return ret;
}

StatusRet_t Insert_Node_At_End(node_t **list)
{
    StatusRet_t ret = R_NOK;

    node_t *lastNode = NULL;
    node_t *tempNode = NULL;
    tempNode = (node_t *)malloc(sizeof(node_t));

    if (NULL == tempNode)
    {
        ret = NULL_POINTER;
    }
    else
    {
        printf("Enter Node Data : ");
        scanf("%i", &tempNode->data);
        tempNode->nodeLink = NULL;

        if (NULL == *list)
        {
            *list = tempNode;
        }
        else
        {
            lastNode = *list;

            while (NULL != lastNode->nodeLink)
            {
                lastNode = lastNode->nodeLink;
            }
            lastNode->nodeLink = tempNode;
        }
        
        ret = R_OK;
    }
    
    return ret;
}


StatusRet_t Insert_Node_After(node_t *list)
{
    node_t *tempNode = NULL, *nodeListCounter = NULL;

    StatusRet_t ret = R_NOK;
    uint32 nodePosition = 0, listLength = 0;

    listLength = Get_Length(list);
    printf("Enter Node Position (From 1 -> %i) : ", listLength);
    scanf("%i", &nodePosition);

    if ((nodePosition <= 0) || (nodePosition > listLength))
    {
        printf("Invalid Position \"List Has %i Nodes\"\n", listLength);
    }
    else
    {
        nodeListCounter = list;
        while (--nodePosition)
        {
            nodeListCounter = nodeListCounter->nodeLink;
        }

        tempNode = (node_t *)malloc(sizeof(node_t));
        if (NULL == tempNode)
        {
            ret = NULL_POINTER;
        }
        else
        {
            printf("Enter Node Data : ");
            scanf("%i", &tempNode->data);

            tempNode->nodeLink = nodeListCounter->nodeLink;
            nodeListCounter->nodeLink = tempNode;
        }
        
        ret = R_OK;
    }
    
    return ret;
}


StatusRet_t Delete_Node_At_Beginning(node_t **list)
{
    node_t *tempNode = *list;
    StatusRet_t ret = R_NOK;

    if (NULL == *list)
    {
        printf("List is empty !!! \n");
        ret = NULL_POINTER;
    }
    else
    {
        *list = tempNode->nodeLink;
        tempNode->nodeLink = NULL;
        free(tempNode);

        ret = R_OK;
    }

    return ret;
}

StatusRet_t Delete_Node(node_t *list)
{
    StatusRet_t ret = R_NOK;

    node_t *tempNode = NULL, *nodeListCounter = NULL;

    uint32 nodePosition = 0, listLength = 0;

    listLength = Get_Length(list);
    printf("Enter Node Position (From 1 -> %i) : ", listLength);
    scanf("%i", &nodePosition);

    if ((nodePosition <= 1) || (nodePosition > listLength))
    {
        printf("Invalid Position \"List Has %i Nodes\" (You can use Delete_Node_At_Beginning.) !!!\n", 
                listLength);
    }
    else
    {
        nodeListCounter = list;
        while ((--nodePosition) - 1)
        {
            nodeListCounter = nodeListCounter->nodeLink;
        }

        tempNode = nodeListCounter->nodeLink;
        nodeListCounter->nodeLink = tempNode->nodeLink;
        tempNode->nodeLink = NULL;
        free(tempNode);
        
        ret = R_OK;
    }

    return ret;
}

StatusRet_t Display_All_Node(node_t *list)
{
    StatusRet_t ret = R_NOK;
    uint32 Length = Get_Length(list);

    if (0 == Length)
    {
        printf("Your list is empty !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        node_t *tempNode = list;

        printf("Your list is :\t");
        while (Length--)
        {
            printf("%i -> ", tempNode->data);
            tempNode = tempNode->nodeLink;
        }
        printf("NULL\n");
        ret = R_OK;
    }
    
    return ret;
}

uint32 Get_Length(node_t *list)
{
    node_t *tempNode = list;
    uint32 ret = 0;

    while (NULL != tempNode)
    {
        tempNode = tempNode->nodeLink;
        ret++;
    }
    
    return ret;
}


StatusRet_t ReverseList(node_t *list)
{
    StatusRet_t ret = R_NOK;
    node_t *tempNode = list;
    uint32 temp = 0;
    uint32 row = Get_Length(list);
    uint32 col = 0;

    if (NULL == list)
    {
        printf("List is empty !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        while (row--)
        {
            col = row;
            tempNode = list;
            while (col--)
            {
                temp = tempNode->data;
                tempNode->data = tempNode->nodeLink->data;
                tempNode = tempNode->nodeLink;
                tempNode->data = temp;
            }
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
            node1 = node1->nodeLink;
        }
        while (--pos2)
        {
            node2 = node2->nodeLink;
        }
        temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
        
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
            while (tempNode->nodeLink)
            {
                if ((tempNode->data) > (tempNode->nodeLink->data))
                {
                    temp = tempNode->data;
                    tempNode->data = tempNode->nodeLink->data;
                    tempNode->nodeLink->data = temp;
                }
                else{}
                tempNode = tempNode->nodeLink;
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
            list = list->nodeLink;
        }
        printf("Middle node data = %i\n", list->data);
        
        ret = R_OK;
    }
    return ret;
}

StatusRet_t DeleteMiddleNode(node_t *list)
{
    StatusRet_t ret = R_NOK;
    uint32 len = Get_Length(list);
    uint32 pos = (len + 1) / 2;
    node_t *tempNode = NULL;

    if (2 >= len)
    {
        printf("Can't find middle (List have %i node)\n", len);
    }
    else
    {
        while (--pos)
        {
            tempNode = list;
            list = list->nodeLink;
        }
        tempNode->nodeLink = list->nodeLink;
        list->nodeLink = NULL;
        free(list);
        list = NULL;
        
        ret = R_OK;
    }
    return ret;
}

StatusRet_t DeleteList(node_t **list)
{
    StatusRet_t ret = R_NOK;
    node_t *tempNode = NULL;

    if (NULL == *list)
    {
        printf("Deleted List !!!\n");
        ret = NULL_POINTER;
    }
    else
    {
        while ((*list)->nodeLink)
        {
            tempNode = (*list)->nodeLink;
            (*list)->nodeLink = NULL;
            free(*list);
            (*list) = tempNode;
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
    node_t *lastNode = NULL;

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
        while (tempNode->nodeLink)
        {
            tempNode = tempNode->nodeLink;
        }
        /*make list => circular*/
        tempNode->nodeLink = (*list);

        tempNode = (*list);
        /*traversal to (pos)th node*/
        while (--pos)
        {
            lastNode = tempNode;
            tempNode = tempNode->nodeLink;
        }
        /*make head pointer point to (pos)th node*/
        (*list) = tempNode;
        lastNode->nodeLink = NULL;

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
            list = list->nodeLink;
        }
        printf("%i\n", list->data);
        
        ret = R_OK;
    }
    return ret;
}