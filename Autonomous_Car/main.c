/*
 * Autonomous_Car.c
 *
 * Created: 11/29/2023 9:28:33 PM
 * Author : hp
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




int main(void)
{
		
	/*INIT ALL FUN */
	GI_voidEnable();
	ULT_VoidInit();
	LCD_Voidinit();
	TIM_Voidinit();
	TIM_Voidstart();
	Motor_Init(M_1);
	Motor_Init(M_2);
	SE_Inti();
	Interrupt_Inti();
	
	SE_Org_Position();
	
	
	while(1)
	{
		Run();
	}
}
