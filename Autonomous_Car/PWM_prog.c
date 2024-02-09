/*
 * PWM_prog.c
 *
 * Created: 12/17/2023 8:59:52 PM
 *  Author: hp
 */ 
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Timer_private.h"
#include "PWM_interface.h"

/*void PWM0_VoidInit(void){*/
	/* Configuring timer0 registers
	 * to fast PWM mode
	 *  */
		/*SET_BIT(TCCR0,TCCR0_WGM00);
		SET_BIT(TCCR0,TCCR0_WGM01);*/
	/* inverted PWM mode
	 * Set OC0 on compare match, clear OC0 at overflow
	 * when timerCount = OCR0, set OC0 -> PB3 pin else
	 * */
		/*SET_BIT(TCCR0,TCCR0_COM00);
		SET_BIT(TCCR0,TCCR0_COM01);*/
	/* no prescale
	 * and start timer0*/
		/*SET_BIT(TCCR0,TCCR0_CS00);
}


void PWM0_VoidSetDutyCycle(u8 Copy_u8DutyCycle){
	// OCR0 holds the on time of the cycle
	OCR0 = 255 - ((f16)Copy_u8DutyCycle / 100.0f) * 255.0f;
}*/