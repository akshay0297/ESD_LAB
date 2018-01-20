#include<LPC17xx.h>
unsigned int i,j,k=0,x,var,temp,temp1,temp2,temp3,row,col,p[3]={300000,200000,100000},g=0X40,h;
unsigned long a[16]={0X3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7E,0x6F,0x73,0x40};
unsigned long flag[3]={0,0,0};

unsigned long val[3]={0,0,0};

unsigned long val1[2]={0,0};

void SCAN(void);
void display(void);
void display1(void);
void display2(void);
void rowed(void);
void calculate(void);
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
	while(1)	
	{	
		if(flag[k]==0)
		{
			rowed();
			val[k]=a[((row*4)+col)];	
			
			if(flag[2]==1)
			{
				display();
				k=0;
				calculate();
			}
		
	}
	display();
	k++;
}
}
}
void rowed()
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
			if(flag[k]==1)
				break;
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
flag[k]=1;break;
}
}
}

void display()
{
	temp=val[k];
LPC_GPIO0->FIOPIN=temp<<4;
if(k==2)
{
LPC_GPIO0->FIOCLR=0x07800000;
LPC_GPIO0->FIOSET=0x00800000;
	for(i=0;i<p[k];i++);
}
if(k==1)
{
LPC_GPIO0->FIOCLR=0x07800000;
	LPC_GPIO0->FIOSET=0x01000000;
		for(i=0;i<p[k];i++);
}
if(k==0)
{
LPC_GPIO0->FIOCLR=0x07800000;
LPC_GPIO0->FIOSET=0x01800000;
		for(i=0;i<p[k];i++);
}
for(i=0;i<100000;i++);
	LPC_GPIO0->FIOPIN=1<<25;
	for(i=0;i<50000;i++);
}



void calculate()
{
	
		for(i=0;i<10;i++)
	if(val[0]==a[i])
	{
val1[0]=i;
}
		for(i=0;i<10;i++)
	if(val[2]==a[i])
	{
val1[1]=i;
}

if(val[1]==0x73)
{
temp1=val1[0]+val1[1];
if (temp1<10)
{
	temp1=a[temp1];
display1();
}	
else
{
	temp2=0X06;
	temp3=temp1-10;
	temp3=a[temp3];
	display2();
}
}

if(val[1]==0x40)
{
temp1=val1[0]-val1[1];
if (temp1>0)
{
	temp1=a[temp1];
display1();
}	
else
{
	temp2=0x40;
	
	temp3=0Xffffffff-temp1;
	
	temp3=a[temp3];
	display2();
}
}

}


void display1()
{
LPC_GPIO0->FIOPIN=temp1<<4;
	LPC_GPIO0->FIOCLR=0x07800000;
	for(i=0;i<500000;i++);
	LPC_GPIO0->FIOPIN=1<<25;
	for(i=0;i<50000;i++);
}


void display2()
{
	LPC_GPIO0->FIOPIN=temp2<<4;
	LPC_GPIO0->FIOCLR=0x07800000;
	LPC_GPIO0->FIOSET=0x00800000;
	for(i=0;i<100000;i++);
	LPC_GPIO0->FIOPIN=1<<25;
	for(i=0;i<50000;i++);
LPC_GPIO0->FIOPIN=temp3<<4;
	LPC_GPIO0->FIOCLR=0x07800000;
	for(i=0;i<100000;i++);
	LPC_GPIO0->FIOPIN=1<<25;
	for(i=0;i<50000;i++);
}