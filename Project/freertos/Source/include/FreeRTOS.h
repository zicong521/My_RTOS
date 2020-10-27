#ifndef INC_FREERTOS_H
#define INC_FREERTOS_H
#include "list.h"
#include "FreeRTOSConfig.h"
#include "portable.h"
#include "projdefs.h"
struct xLIST_ITEM
{
	TickType_t xItemValue;             /* 辅助值，用于帮助节点做顺序排列 */			
	struct xLIST_ITEM *  pxNext;       /* 指向链表下一个节点 */		
	struct xLIST_ITEM *  pxPrevious;   /* 指向链表前一个节点 */	
	void * pvOwner;					   /* 指向拥有该节点的内核对象，通常是TCB */
	void *  pvContainer;		       /* 指向该节点所在的链表 */
};
typedef struct xLIST_ITEM ListItem_t;  /* 节点数据类型重定义 */

typedef struct tskTaskControlBlock
{
	volatile StackType_t    *pxTopOfStack;     
	xLIST_ITEM			    xStateListItem;
    //ListItem_t xStateListItem;
    StackType_t             *pxStack;         
	                                         
	char                    pcTaskName[ configMAX_TASK_NAME_LEN ];  
} tskTCB;
typedef tskTCB TCB_t;

#endif /* INC_FREERTOS_H */
