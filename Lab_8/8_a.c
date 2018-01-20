#include<LPC17xx.h>
unsigned int i,j,flag=0,x,var,temp,row,col;
unsigned long a[16]={0X3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7E,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};
unsigned long 	b[4]={0x01,0x22,0x40,0x14};
void SCAN(void);
void display(void);
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();

LPC_PINCON->PINSEL3 &=0xFFC03FFF;
LPC_PINCON->PINSEL4 &=0xF00FFFFF;
LPC_GPIO1->FIODIR |=0xF87FFFFF;
LPC_GPIO2->FIODIR |=0x00003C00;
LPC_PINCON->PINSEL0 =0xFF0000FF;
LPC_PINCON->PINSEL1=0xFFC03FFF;
LPC_GPIO0->FIODIR |=0x07800FF0;
	while(1)
	{
		LPC_GPIO2->FIOSET =(0xF<<10);
		while((LPC_GPIO1->FIOPIN &(0xF<<23))==0);
			for(row=0;row<=4;row++)
		{
			if(row==0)
				var=0x00000400;
			if(row==1)
				var=0x00000800;
			if(row==2)
				var=0x00001000;
			if(row==3)
				var=0x00002000;
			LPC_GPIO2->FIOCLR=0X00003C00;
			LPC_GPIO2->FIOSET=var;
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
j=23;
	for(col=0;col<4;col++)
	{
x=LPC_GPIO1->FIOPIN;
		x=x&1<<j;
		j++;
		if(x)
		{
flag=1;break;
}
}
}

void display()
{
	temp=b[row];
LPC_GPIO0->FIOPIN=temp<<4;
if(col==3)
{
LPC_GPIO0->FIOCLR=0x07800000;
}
if(col==2)
{
LPC_GPIO0->FIOCLR=0x07800000;
LPC_GPIO0->FIOSET=0x00800000;
}
if(col==1)
{
LPC_GPIO0->FIOCLR=0x07800000;
	LPC_GPIO0->FIOSET=0x01000000;
}
if(col==0)
{
LPC_GPIO0->FIOCLR=0x07800000;
LPC_GPIO0->FIOSET=0x01800000;
}
for(i=0;i<100000;i++);
	LPC_GPIO0->FIOPIN=1<<25;
	for(i=0;i<50000;i++);
}
			
				

