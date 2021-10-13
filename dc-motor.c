
 /******************************************************************************
 *
 * Module: dc-motor
 *
 * File Name: dc-motor.c
 *
 * Description: DC MOTOR deriver
 *
 *Author: Kyrillos Phelopos
 *******************************************************************************/


#include"dc-motor.h"
#include"pwm.h"
/****************************************
 * FUNCTION DECLARATIONS
 ***************************************/

void DcMotor_Init(void)
{
GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN0_ID, PIN_OUTPUT);
GPIO_setupPinDirection(MOTOR_PORT_ID, MOTOR_PIN1_ID, PIN_OUTPUT);
GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN0_ID , 0);
GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID , 0);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
if(state == stop)
{
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN0_ID , 0);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID , 0);
}
else if (state == CLOCK_WISE)
{
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN0_ID , 1);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID , 0);
	PWM_Timer0_Start(speed);
}
else if (state==ANTI_CLOCK_WISE)
{
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN0_ID , 0);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID , 1);
	PWM_Timer0_Start(speed);
}
}

