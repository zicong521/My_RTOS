#ifndef INC_FREERTOS_H
#define INC_FREERTOS_H
#include "list.h"
#include "FreeRTOSConfig.h"
#include "portable.h"
#include "projdefs.h"
// ������ƿ�ṹ��
typedef struct tskTaskControlBlock
{
	volatile StackType_t    *pxTopOfStack;    /* ջ�� */

	ListItem_t			    xStateListItem;   /* ����ڵ� */
    
    StackType_t             *pxStack;         /* ����ջ��ʼ��ַ */
	                                          /* �������ƣ��ַ�����ʽ */
	char                    pcTaskName[ configMAX_TASK_NAME_LEN ];  
} tskTCB;
typedef tskTCB TCB_t;

#endif /* INC_FREERTOS_H */
