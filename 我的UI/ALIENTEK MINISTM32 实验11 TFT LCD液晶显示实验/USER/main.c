#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "ugui.h"


UG_GUI GUI_Struct;


void gui_draw_line(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2,UG_COLOR c)
{
	POINT_COLOR = c;
	LCD_DrawLine(x1,y1,x2,y2);
}

void gui_fill_rectangle(UG_S16 x1, UG_S16 y1, UG_S16 x2, UG_S16 y2,UG_COLOR c) 
{	
	POINT_COLOR = c;
	LCD_DrawRectangle(x1,y1,x2,y2);
}

UG_WINDOW g_calling_window;
	

void MiddleLayer_Init(void)		
{		
	//ugui 初始化
	////////////*******************************************************/
	UG_Init(&GUI_Struct, LCD_Fast_DrawPoint, 120, 120);		
	UG_SelectGUI(&GUI_Struct);		
	
	UG_DriverRegister(DRIVER_DRAW_LINE, (void *) gui_draw_line);
	UG_DriverRegister(DRIVER_FILL_FRAME, (void *) gui_fill_rectangle);
	UG_DriverEnable(DRIVER_DRAW_LINE);
	UG_DriverEnable(DRIVER_FILL_FRAME);	
	
	UG_FillScreen ( C_WHITE) ;				
		
	UG_WindowSetTitleTextColor(&g_calling_window,C_WHEAT);
	
}



static void calling_window_callback(UG_MESSAGE *msg)
{
    if (msg->type == MSG_TYPE_OBJECT) {
        if (msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED) {
	
        }
    }
}



void calling_window_create(void)
{
    static UG_BUTTON button;
    static UG_TEXTBOX textboxs[2];
    static UG_OBJECT objects[3];
	
    UG_WindowCreate(&g_calling_window, objects, 3, calling_window_callback);

	UG_WindowResize( &g_calling_window, 20 , 20 , 119-20, 119-20 ) ;	
	
	UG_WindowSetTitleText(&g_calling_window , "hello" ) ;
	UG_WindowSetTitleTextFont(&g_calling_window , &FONT_6X8 ) ;
				
    UG_ButtonCreate(&g_calling_window, &button, BTN_ID_0, 	
					UG_WindowGetInnerWidth(&g_calling_window)-20, 
					UG_WindowGetInnerHeight(&g_calling_window)-20,	 
					UG_WindowGetInnerWidth(&g_calling_window)-10 , 
					UG_WindowGetInnerHeight(&g_calling_window)-10);
	
    UG_ButtonSetFont(&g_calling_window, BTN_ID_0, &FONT_6X8);			
    UG_ButtonSetText(&g_calling_window, BTN_ID_0, "OK");			

}

	

void calling_window_show(void)
{	
	UG_WindowSetBackColor(&g_calling_window,C_WHITE);		
		
    UG_WindowShow(&g_calling_window);	
}



		
int main(void)
{ 	
	delay_init();	    	 //延时函数初始化	  
	//uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
	LCD_Init();	
	
	MiddleLayer_Init();	
		
	calling_window_create();

	calling_window_show();	

	UG_Update();	

	while(1) 
	{		 
		
	} 
}
