#include <LPC17xx.h>
#include <stdio.h>
#include <stdlib.h>

#define	FIRST_SEG	0xF87FFFFF

void display(unsigned int);

unsigned long a[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int dig_count = 0x01 , temp1 , temp;
unsigned char x ;
unsigned int i , key;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 = 0x00;
	LPC_PINCON->PINSEL3 = 0x00;
	LPC_PINCON->PINSEL4 = 0x00;
	
	LPC_GPIO0->FIODIR = 0x0FF0;
	LPC_GPIO1->FIODIR = (0x0F<<23);
	LPC_GPIO2->FIODIR = 0x00;
	
	while(1)
	{
			x = LPC_GPIO2->FIOPIN;
			x &= 0x01;
			if(!x)
			{
				temp = (rand()%(6) + 1);
				key = a[temp];
				display(key);
		}
		else
			{
					continue;
		}
	}
}
void display(unsigned int b)
{
	
	if(dig_count == 0x01)		
	{
		temp1 = b; 
		LPC_GPIO1->FIOPIN = FIRST_SEG;    
	}
	LPC_GPIO0->FIOPIN = b<<4;		
	for(i=0;i<500000;i++);
	LPC_GPIO0->FIOCLR = 0x00000FF0;
}
