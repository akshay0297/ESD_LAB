#include<LPC17XX.h>
#include<stdio.h>

unsigned long int i;
unsigned int j;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	while(1)
	{
		for(i=1 ; i<256 ; i++)
		{
			LPC_GPIO0->FIOPIN = i<<4;
			for(j = 0 ; j<1000000; j++);
		}
	}
}