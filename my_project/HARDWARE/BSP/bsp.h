#ifndef __BSP_H
#define __BSP_H




#include "stm32f4xx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TRUE
	#define TRUE  1
#endif

#ifndef FALSE
	#define FALSE 0
#endif


#include "bsp_uart_fifo.h"
#include "bsp_led.h"	
#include "bsp_beep.h"	
#include "bsp_key.h"



/* 提供给其他C文件调用的函数 */
void bsp_Init(void);
void bsp_Idle(void);


#endif

