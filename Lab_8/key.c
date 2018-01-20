#include<LPC17xx.h>
#include<stdio.h>

 #define	FIRST_SEG	0xF87FFFFF
 #define	SECOND_SEG	0xF8FFFFFF
 #define	THIRD_SEG	0xF97FFFFF
 #define	FOURTH_SEG	0xF9FFFFFF
 #define	DISABLE_ALL 0xFA7FFFFF
 
void scan (void);
void display(unsigned long );

unsigned char col , row , var , flag , key ;
unsigned long int i , var1 , temp , temp;
unsigned int twenty_count = 0x00,dig_count=0x01,temp1=0x00;
unsigned long a[16]={0X3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 = 0x00; //rows output p0.15-> p0.18
	LPC_PINCON->PINSEL1 = 0x00; // col input p0.23-> p0.26
	LPC_PINCON->PINSEL3 = 0x00;
	LPC_PINCON->PINSEL4 = 0x00;
	
	LPC_GPIO0->FIODIR = 0x07800FF0;
	LPC_GPIO1->FIODIR = 0x00000000;
	LPC_GPIO2->FIODIR = 0x00003C00;
	
	while(1)
	{
			while(1)
			{
					for(row = 0; row<4 ; row++)
				{
						if(row==0)
						var1 = 0x400;
						else if(row == 1)
							var1 = 0x800;
						else if(row == 2)
							var1 = 0x1000;
						else if(row == 3)
							var1 = 0x2000;
						temp = var1;
					LPC_GPIO2->FIOCLR = 0x3C00;
					LPC_GPIO2->FIOSET = var1;
					
					flag = 0;
						scan();
					if(flag == 1)
						break;	
			}
			if(flag == 1)
			{		
				key=a[((row*4)+col)];
			display(key);
			flag=0;
		}
	}

	}
}
void scan(void)
	{
			unsigned long temp3;
		temp3 = LPC_GPIO1->FIOPIN;
		temp3 &= 0x07800000;
		if(temp3!=0x00)
		{
				flag = 1;
			if(temp3 == 0x00800000)
				col = 0;
			if(temp3 == 0x01000000)
				col = 1;
			if(temp3 == 0x02000000)
				col = 2;
			if(temp3 == 0x04000000)
				col = 3;
		}
	}
void display(unsigned long b)
	{if(dig_count == 0x01)		
	{
		temp1 = b; 
		LPC_GPIO0->FIOPIN = FIRST_SEG;    

	}
	LPC_GPIO0->FIOPIN = b<<4;		
	for(i=0;i<5000;i++);
	LPC_GPIO0->FIOCLR = 0x00000FF0;
	}