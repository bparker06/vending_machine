#include "delay.h"  	
#include "includes.h"





	

int main(void)
{ 			
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����2
   	system_init();		//ϵͳ��ʼ�� 
 	OSInit();   
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//������ʼ����
	OSStart();	  						    
}


