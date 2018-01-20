#include<LPC17XX.h>
#include<stdio.h>

unsigned long int i;
unsigned int j;
unsigned long int x;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_PINCON->PINSEL1 &= 0xFFFFF0FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	i = 1;
	while(1 && i<=255)
	{
	x = LPC_GPIO0->FIOPIN;
	x &= 0x00200000;
		if(x)
			{
					LPC_GPIO0->FIOPIN = i<<4;
					i++;
				if(i>255)
					i = 1;
					for(j = 0 ; j<1000000; j++);
			}
	else
		{
				LPC_GPIO0->FIOPIN = i<<4;
				i--;
			if(i<=0)
			{
				i = 255;
	}
				for(j = 0 ; j<1000000; j++);
		}
	}
}