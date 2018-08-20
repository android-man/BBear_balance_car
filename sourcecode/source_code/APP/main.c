/*************************************HEAD FILES******************************/
#include"BSP.H"

/******************************************************************************
Name��main 
Function:	
		  	main
Parameters��
		   	void
Returns��
			void 
Description:
			null
******************************************************************************/
void SystemInit(){}
int main()
{	
	RCC_Configuration();				//initialize the system clock
	USART_Configuration();				//initialize the usart
	GPIO_Configuration();
	NVIC_Configuration();
	EXTI_Configuration();
	PID_Init(&Angle_PID, 150, 0, -100); //20170219 150,0,-100
	PID_Init(&Angle_PID2,600, 0, 100);
	PID_Init(&Speed_PID, 360, 37.5, 0);   //20170219 50,0.5,0   //20171019 100,25,0 //20171024 180,37.5,0
	PWM_Motor_Configuration();
	InitMPU6050();
	Cal_angle();
	Heart_TIM();
	while(1)
	{
	}
}
