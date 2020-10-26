#include "list.h"
#include "stdlib.h"
#include "FreeRTOS.h"

void vListInitialiseItem( ListItem_t * const pxItem)
{
    /* ��ʼ���ýڵ����ڵ�����Ϊ�գ���ʾ�ڵ㻹û�в����κ����� */
    pxItem->pvContainer = NULL;
}
/* ������ڵ��ʼ�� */
void vListInitialise(List_t * const pxList)
{
    pxList->pxIndex = ( ListItem_t *) & (pxList->xListEnd);
    pxList->uxNumberOfItems = 0;
    pxList->xListEnd.xItemValue = portMAX_DELAY;
    pxList->xListEnd.pxNext = ( ListItem_t *) & (pxList->xListEnd);
    pxList->xListEnd.pxPrevious = ( ListItem_t *) & (pxList->xListEnd);
}
/* ���ڵ���뵽�����β�� */
void vListInsertEnd(List_t * const pxList, ListItem_t * const pxNewListItem)
{
    ListItem_t * const pxIndex = pxList->pxIndex;
    pxNewListItem->pxNext = pxIndex;
    pxNewListItem->pxPrevious = pxIndex->pxPrevious;
    pxIndex->pxPrevious->pxNext = pxNewListItem;
    pxIndex->pxPrevious = pxNewListItem;
    pxNewListItem->pvContainer = (void*)pxList;
    
    (pxList->uxNumberOfItems)++;
}
/* ���ڵ㰴���������в��뵽���� */
void vListInsert(List_t * const pxList, ListItem_t * const pxNewListItem)
{
 ListItem_t *pxIterator;
	
	/* ��ȡ�ڵ��������ֵ */
	const TickType_t xValueOfInsertion = pxNewListItem->xItemValue;

	/* Ѱ�ҽڵ�Ҫ�����λ�� */
	if( xValueOfInsertion == portMAX_DELAY )
	{
		pxIterator = pxList->xListEnd.pxPrevious;
	}
	else
	{
		for( pxIterator = ( ListItem_t * ) &( pxList->xListEnd );
		     pxIterator->pxNext->xItemValue <= xValueOfInsertion; 
			 pxIterator = pxIterator->pxNext )
		{
			/* û��������������ϵ���ֻΪ���ҵ��ڵ�Ҫ�����λ�� */			
		}
	}

	pxNewListItem->pxNext = pxIterator->pxNext;
	pxNewListItem->pxNext->pxPrevious = pxNewListItem;
	pxNewListItem->pxPrevious = pxIterator;
	pxIterator->pxNext = pxNewListItem;

	/* ��ס�ýڵ����ڵ����� */
	pxNewListItem->pvContainer = ( void * ) pxList;

	/* ����ڵ������++ */
	( pxList->uxNumberOfItems )++;
}
/* ���ڵ��������ɾ�� */
UBaseType_t uxListRemove(ListItem_t * const pxItemToRemove)
{
    	/* ��ȡ�ڵ����ڵ����� */
	List_t * const pxList = ( List_t * ) pxItemToRemove->pvContainer;

	pxItemToRemove->pxNext->pxPrevious = pxItemToRemove->pxPrevious;
	pxItemToRemove->pxPrevious->pxNext = pxItemToRemove->pxNext;

	/* Make sure the index is left pointing to a valid item. */
	if( pxList->pxIndex == pxItemToRemove )
	{
		pxList->pxIndex = pxItemToRemove->pxPrevious;
	}

	/* ��ʼ���ýڵ����ڵ�����Ϊ�գ���ʾ�ڵ㻹û�в����κ����� */
	pxItemToRemove->pvContainer = NULL;
	
	/* ����ڵ������-- */
	( pxList->uxNumberOfItems )--;

	/* ����������ʣ��ڵ�ĸ��� */
	return pxList->uxNumberOfItems;
}
