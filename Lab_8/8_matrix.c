#include<LPC17xx.h>
unsigned int i,j,flag=0,x,var,temp,row,col;
unsigned long a[16]={0X3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
void SCAN(void);
void display(void);
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

LPC_PINCON->PINSEL3 &=0xFFC03FFF;
LPC_PINCON->PINSEL4 &=0xF00FFFFF;
LPC_GPIO0->FIODIR =0xFFF87FFF;
//LPC_GPIO2->FIODIR |=0x00003C00;
//LPC_PINCON->PINSEL0 =0xFF0000FF;
//LPC_PINCON->PINSEL1=0xFFC03FFF;
//LPC_GPIO0->FIODIR |=0x07800FF0;
	while(1)
	{
		LPC_GPIO0->FIOSET =(0xF<<19);
		while((col=(LPC_GPIO0->FIOPIN &(0xF<<15)))==0);
			for(row=0;row<=4;row++)
		{
			if(row==0)
				var=0x00080000;
			if(row==1)
				var=0x00100000;
			if(row==2)
				var=0x00200000;
			if(row==3)
				var=0x00400000;
			LPC_GPIO0->FIOCLR=0X00780000;
			LPC_GPIO0->FIOSET=var;
			SCAN();
			if(flag==1)
				break;
		}
		if(flag==1)
		{
			temp=a[((row*4)+col)];
			display();
			flag=0;
		}
	}
}
void SCAN()
{
j=15;
	for(col=0;col<4;col++)
	{
		//LPC_GPIO0->FIOMASK=(0xf<<15);
x=LPC_GPIO0->FIOPIN;
		x=x&1<<j;
		j++;
		if(x)
		{
flag=1;
			//LPC_GPIO0->FIOMASK=(0xf<<19);
			break;
}
}
}

void display()
{
LPC_GPIO0->FIOPIN=temp<<4;
	LPC_GPIO0->FIOCLR=0x07800000;
	for(i=0;i<500000;i++);
	LPC_GPIO0->FIOPIN=1<<25;
	for(i=0;i<50000;i++);
}
			
				

