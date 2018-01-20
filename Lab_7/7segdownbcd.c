 #include <LPC17xx.h>
 #include <stdio.h>

 #define	FIRST_SEG	0xF87FFFFF
 #define	SECOND_SEG	0xF8FFFFFF
 #define	THIRD_SEG	0xF97FFFFF
 #define	FOURTH_SEG	0xF9FFFFFF
 #define	DISABLE_ALL 0xFA7FFFFF

 unsigned int dig1=0x09,dig2=0x09,dig3=0x09,dig4=0x09;
 unsigned int twenty_count = 0x00,dig_count=0x04,temp1=0x00;
 unsigned char array_dec[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
 unsigned char one_sec_flg = 0x00;
 unsigned long int temp2 = 0x00000000,i=0;
void delay(void);
 
 void Display(void);

 int main(void)
 {    
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;	 
	LPC_PINCON->PINSEL3 &= 0xFFC03FFF;	 

	LPC_GPIO0->FIODIR |= 0x00000FF0;	
	LPC_GPIO1->FIODIR |= 0x07800000;

	
	while(1)
	{
	delay();  
		
	if(dig_count == 0x00)
            dig_count = 0x04;
		if(one_sec_flg == 0xFF)
		{
 			one_sec_flg = 0x00;
			dig1 -=1;
              
			if(dig1 == 0xFFFFFFFF)
			{ 
				dig1 = 9;
				dig2 -=1;

				if(dig2 == 0xFFFFFFFF)
				{
					dig2 = 9;
					dig3-=1;

					if(dig3 == 0xFFFFFFFF)
					{
						dig3 = 9;
						dig4 -= 1;
                             
						if(dig4 == 0xFFFFFFFF)
						{
							dig4 = 9;
						} //end of dig4
					
					} //end of dig3
				
				} //end of dig2

			}  //end of dig1

		}   //end of one_sec if

		Display();
		
	dig_count -=1;		

	} //end of while(1)

 }//end of main

 

 void delay(void)
 {
	 unsigned int i;
	 for (i=0;i<100;i++);
		if(twenty_count == 500) 
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
//	LPC_GPIO1->FIOPIN = DISABLE_ALL; //disable all the segments
 }		


