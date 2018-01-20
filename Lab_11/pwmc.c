#include<LPC17xx.h>

void pwm_init(void);
void PWM1_IRQHandler(void);
unsigned long int i;
unsigned char flag , flag1;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	pwm_init();
	while(1)
	{
			for(i=0 ; i<=10000 ; i++);
	}
}
void pwm_init(void)
{
		LPC_SC->PCONP |= (1<<6);
		LPC_PINCON->PINSEL3 &= ~(0x0000C000);
		LPC_PINCON->PINSEL3 |= 0x00008000;
	LPC_PWM1->PR = 0x00;
	LPC_PWM1->PCR = 0x1000;
	LPC_PWM1->MCR = 0x03;
	LPC_PWM1->MR0 = 30000;
	LPC_PWM1->MR4 = 0x1000;
	LPC_PWM1->LER = 0xFF;
	LPC_PWM1->TCR = 0x002;
	LPC_PWM1->TCR = 0x09;
	NVIC_EnableIRQ(PWM1_IRQn);
	return;
}

void PWM1_IRQHandler(void)
{
	LPC_PWM1->IR=0XFF;
	if(flag == 0X00)
	{
		LPC_PWM1->MR4 += 100;
		LPC_PWM1->LER = 0X00FF;
		if(LPC_PWM1->MR4 >= 27000)
		{
				flag1 = 0XFF;
				flag = 0XFF;
				LPC_PWM1->LER = 0X00FF;
		}
	}
	else if(flag1 == 0xFF)
	{
		LPC_PWM1->MR4 -= 100;
		LPC_PWM1->LER = 0X00FF;
		if(LPC_PWM1->MR4 <= 500)
		{
				flag = 0X00;
				flag1 = 0X00;
				LPC_PWM1->LER = 0X00FF;
		}
	}
}