/*
 * M.c
 *
 * Created: 2/7/2024 10:20:30 PM
 *  Author: FAHD9
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
# define F_CPU 16000000UL
#include <util/delay.h>
#include "DIO_Private.h"
#include "DIO_interface.h"
#include "Timer_private.h"
#include "Timer_interface.h"
#include "TIM1_private.h"
#include "TIM1_interface.h"
#include "GI_interface.h"
#include "EXTI_interface.h"
#include "LCD_inteface.h"
#include "servo_interface.h"
#include "MOTOR_interface.h"
#include "ULT_Interface.h"
#include "M.h"

volatile u32 dis=0;
volatile u32 dis_R=0,dis_L=0;


void Run()
{
	dis=0;
	dis_R=0,dis_L=0;
	
		/*READ DISTANCE*/
		ULT_Voidget_Distance(&dis);
		
		/*CLEAR LCD  */
		LCD_Voidclear();
		//SEND STRING
		LCD_VoidsendString((u8*)"distance:");
		//SEND NUM OF THE DISTANCE
		LCD_VoidsendNumber(dis);
		//SEND STRING
		LCD_VoidsendString((u8*)" cm");
		_delay_ms(90);
		/*CLEAR LCD  */
		LCD_Voidclear();
		
		if(dis > 80)
		{
			/*GO RTO FW*/
			Car_Move();
		}
		else if(dis <= 80)
		{
			/*STOP CAR*/
			Car_Stop();
			Car_Move_Back();
			_delay_ms(40);
			Car_Stop();
			
			
			SE_L_Move();
			
			/*DISTANCE LEFT*/
			ULT_Voidget_Distance(&dis_L);
			//dis_L=dis;
			LCD_VoidsendString((u8*)"L-dist.:");
			LCD_VoidsendNumber(dis_L);
			LCD_VoidsendString((u8*)" cm");
			_delay_ms(90);
			LCD_Voidclear();
			
			//oreginal postion
			SE_Org_Position();
			dis=0;
			SE_R_Move();
			
			/*DISTANCE RIGHT*/
			ULT_Voidget_Distance(&dis_R);
			//dis_R=dis;
			LCD_Voidclear();
			LCD_VoidsendString((u8*)"R-dist.:");
			LCD_VoidsendNumber(dis_R);
			LCD_VoidsendString((u8*)" cm");
			_delay_ms(90);
			LCD_Voidclear();
			
			//oreginal postion
			SE_Org_Position();
			
			if (dis_L > dis_R)
			{
				LCD_Voidclear();
				LCD_VoidsendString((u8*)"Moving Left");
				Car_Move_L();
				LCD_Voidclear();
				dis=0;
				dis_R=0,dis_L=0;
				
			}
			
			if ( dis_R>dis_L)
			{
				
				LCD_Voidclear();
				LCD_VoidsendString((u8*)"Moving Right");
				Car_Move_R();
				LCD_Voidclear();
				dis=0;
				dis_R=0,dis_L=0;
			}
			dis=0;
		dis_R=0,dis_L=0;
		}
		
}