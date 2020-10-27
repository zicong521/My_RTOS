#ifndef INC_TASK_H
#define INC_TASK_H
#include "list.h"

#if(configSUPPORT_STATIC_ALLOCATION == 1)
/* ÈÎÎñ¾ä±ú */
typedef void * TaskHandle_t;

TaskHandle_t xTaskCreateStatic(	TaskFunction_t pxTaskCode,
					            const char * const pcName,
					            const uint32_t ulStackDepth,
					            void * const pvParameters,
					            StackType_t * const puxStackBuffer,
					            TCB_t * const pxTaskBuffer );

#endif /* configSUPPORT_STATIC_ALLOCATION */    

                                
#endif /* INC_TASK_H */ 