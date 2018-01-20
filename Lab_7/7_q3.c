#include <LPC17xx.h>
 #include <stdio.h>

 #define	FIRST_SEG	0xF87FFFFF
 #define	SECOND_SEG	0xF8FFFFFF
 #define	THIRD_SEG	0xF97FFFFF
 #define	FOURTH_SEG	0xF9FFFFFF
 #define	DISABLE_ALL 0xFA7FFFFF

 unsigned int dig1=0x00,dig2=0x00,dig3=0x00,dig4=0x00;
 unsigned int twenty_count = 0x00,dig_count=0x00,temp1=0x00;
 unsigned char array_dec[20]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0X5E,0X79,0X71};
 unsigned char tmr0_flg = 0x00,one_sec_flg = 0x00;
 unsigned long int temp2 = 0x00000000,i=0,x;
 unsigned int temp3=0x00;
 unsigned char flag=0;
void delay(void);
 
 void Display(void);

 int main(void)
 {    
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;	
	LPC_PINCON->PINSEL3 &= 0xFFC03FFF;	 
	LPC_PINCON->PINSEL4 &= 0XFFFFFFFC;
	
	LPC_GPIO2->FIODIR |= 0XFFFFFFFE;
	LPC_GPIO0->FIODIR |= 0x00000FF0;	
	LPC_GPIO1->FIODIR |= 0x07800000;	
	
	
	while(1)
	{
		x=LPC_GPIO2->FIOPIN;
		x=x&1;
		
		if(x)
	//	while(1)
		{			
		delay();
		dig_count +=1;  
		if(dig_count == 0x05)
            dig_count = 0x00;
				if(one_sec_flg == 0xFF)
		{
			one_sec_flg = 0x00;
			dig1 +=1;
              
			if(dig1 == 0x10)
			{ 
				dig1 = 0;
				dig2 +=1;

				if(dig2 == 0x10)
				{
					dig2 = 0;
					dig3+=1;

					if(dig3 == 0x10)
					{
						dig3 = 0;
						dig4 += 1;
                             
						if(dig4 == 0x10)
						{
							dig4 = 0;
						} //end of dig4
					
					} //end of dig3
				
				} //end of dig2

			}  //end of dig1
		}	
	}
		else	
//	while(1)
	{
	delay();
		dig_count -=1;  
		if(dig_count == 0x00)
            dig_count = 0x04;
				if(one_sec_flg == 0xFF)
		{
			one_sec_flg = 0x00;
			dig1 -=1;
              
			if(dig1 == -1)
			{ 
				dig1 = 0x0F;
				dig2 -=1;

				if(dig2 == -1)
				{
					dig2 = 0X0F;
					dig3-=1;

					if(dig3 == -1)
					{
						dig3 = 0X0F;
						dig4 -= 1;
                             
						if(dig4 == -1)
						{
							dig4 = 0X0F;
						} //end of dig4
					
					} //end of dig3
				
				} //end of dig2

			}  //end of dig1
		}	
	}

Display();	

	
} //end of while(1)


 }//end of main


void delay(void)
 {
	 unsigned int i;
	 for (i=0;i<100;i++);
		if(twenty_count ==500)     
	{ 
		one_sec_flg = 0xFF;
		twenty_count = 0x00;			 
	}
	else twenty_count += 1;
		
 }


 void Display(void)     
 {

        
	if(dig_count == 0x01)		
	{
		temp1 = dig1; 
		LPC_GPIO1->FIOPIN = FIRST_SEG;    

	}

	else if(dig_count == 0x02)	
	{
		temp1 = dig2;             
		LPC_GPIO1->FIOPIN = SECOND_SEG;    
   
	}

	else if(dig_count == 0x03)	
	{
		temp1 = dig3;           
		LPC_GPIO1->FIOPIN = THIRD_SEG;    
	}
	else if(dig_count == 0x04)	
	{ 
		temp1 = dig4;   
		LPC_GPIO1->FIOPIN = FOURTH_SEG;    

	}
	temp1 &= 0x0F;
	temp2 = array_dec[temp1];	
	temp2 = temp2 << 4;
	LPC_GPIO0->FIOPIN = temp2;		
	for(i=0;i<500;i++);
	LPC_GPIO0->FIOCLR = 0x00000FF0;

 }		