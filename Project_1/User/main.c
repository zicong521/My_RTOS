#include "FreeRTOS.h"
#include "task.h"
#include "string.h"
#include "stdlib.h"

/*
*************************************************************************
*                              全局变量
*************************************************************************
*/
portCHAR flag1;
portCHAR flag2;
int main(void)
{	
       
	for(;;)
	{
		
	}
}
void delay (uint32_t count)
{
	for(; count!=0; count--);
}
/* 任务1 */
void Task1_Entry( void *p_arg )
{
	for( ;; )
	{
		flag1 = 1;
		delay( 100 );		
		flag1 = 0;
		delay( 100 );
		
		/* 任务切换，这里是手动切换 */
        //taskYIELD();
	}
}

/* 任务2 */
void Task2_Entry( void *p_arg )
{
	for( ;; )
	{
		flag2 = 1;
		delay( 100 );		
		flag2 = 0;
		delay( 100 );
		
		/* 任务切换，这里是手动切换 */
       // taskYIELD();
	}
}
