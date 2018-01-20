#include <LPC17xx.h>
#include <stdio.h>

#define	FIRST_SEG	0xF87FFFFF
#define	SECOND_SEG	0xF8FFFFFF
 
void scan (void);
void display(unsigned long );
void display2(unsigned long , unsigned long);

unsigned char col , row , var , flag ;
unsigned long int i , var1 , temp1 , temp , key , dig1 , dig2;
unsigned int twenty_count = 0x00,dig_count=0x01;
unsigned long a[16]={0X3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned long c[4];

 
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
			for(i=0 ; i<4 ; i++)
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
			 c[i]=((row*4)+col);
				flag=0;
			}
		
	}
	if(c[1] == 10)
	{
		key = c[0] + c[2];
		dig1 = key%10;
		dig1 = a[dig1];
		key = key/10;
		dig2 = key%10;
		dig2 = a[dig2];
		if(c[3] == 12)
		{
				display2(dig1 , dig2);
			flag=0;
	}
		
	}
	else if(c[1] == 11)
	{
		key = c[0] - c[2];
		key = a[key];
		if(c[3]==12)
		{
				display2(0 , key);
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
	{
		if(dig_count == 0x01)		
	{
		temp1 = b; 
		LPC_GPIO0->FIOPIN = FIRST_SEG;    

	}
	LPC_GPIO0->FIOPIN = b<<4;		
	for(i=0;i<5000;i++);
	LPC_GPIO0->FIOCLR = 0x00000FF0;
	}
	void display2(unsigned long int p , unsigned long int q)
	{
			if(dig_count == 0x01)		
			{
		temp1 = p; 
		LPC_GPIO0->FIOPIN = FIRST_SEG;
	LPC_GPIO0->FIOPIN = p<<4;	
	LPC_GPIO0->FIOPIN = SECOND_SEG;
	LPC_GPIO0->FIOPIN = q<<4;	
			}
	for(i=0;i<500000;i++);
	
	LPC_GPIO0->FIOCLR = 0x00000FF0;
}