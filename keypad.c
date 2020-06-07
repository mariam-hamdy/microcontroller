#include "keypad.h"



/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/



static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number);



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void  KeyPad_Init(PORT Port){
	 SYSCTL_RCGC2_R |=(1<<Port);//enable clock port X
	 while( BIT_IS_CLEAR(SYSCTL_PRGPIO_R,Port) );

 if(Port==PortA){//unlock Pins
   GPIO_PORTA_LOCK_R=0x4c4f434B;
   GPIO_PORTA_CR_R =0xFF;

 GPIO_PORTA_DEN_R  =0xFF;
 GPIO_PORTA_AMSEL_R =0;
 GPIO_PORTA_AFSEL_R  =0;
 GPIO_PORTA_PCTL_R=0;

	 GPIO_PORTA_PUR_R |=0x0f;

	}
else if (Port==PortB){
	 GPIO_PORTB_LOCK_R=0x4c4f434B;
	 GPIO_PORTB_CR_R =0xFF;

  GPIO_PORTB_DEN_R  =0xFF;
 GPIO_PORTB_AMSEL_R =0;
 GPIO_PORTB_AFSEL_R  =0;
 GPIO_PORTB_PCTL_R=0;
	 GPIO_PORTB_PUR_R |=0x0f;

}

else if (Port==PortD){
	 GPIO_PORTD_LOCK_R=0x4c4f434B;
	 GPIO_PORTD_CR_R =0xFF;

  GPIO_PORTD_DEN_R  =0xFF;
 GPIO_PORTD_AMSEL_R =0;
 GPIO_PORTD_AFSEL_R  =0;
 GPIO_PORTD_PCTL_R=0;
	 GPIO_PORTD_PUR_R |=0x0f;

}


}


uint8 KeyPad_getPressedKey(void){

uint8 col,row;
	while(1)
	{
		for(col=0;col<4;col++) /* loop for columns */
		{
			/* 
			 * each time only one of the column pins will be output and 
			 * the rest will be input pins include the row pins 
			 */ 
			KEYPAD_PORT_DIR = (1<<(col+4));
			
			/* 
			 * clear the output pin column in this trace and enable the internal 
			 * pull up resistors for the rows pins
			 */ 
			KEYPAD_PORT_DATA = (~(1<<(col+4)));

			for(row=0;row<4;row++) /* loop for rows */
			{
				if(BIT_IS_CLEAR(KEYPAD_PORT_DATA,row)) /* if the switch is press in this row */
				{

						return KeyPad_4x4_adjustKeyNumber((row*4)+col+1);

				}
			}
		}
	}	
}






 
static uint8 KeyPad_4x4_adjustKeyNumber(uint8 button_number)
{
	switch(button_number)
	{
		case 1: return 7; 
				break;
		case 2: return 8; 
				break;
		case 3: return 9; 
				break;
		case 4: return '%'; // ASCII Code of %
				break;
		case 5: return 4; 
				break;
		case 6: return 5;
				break;
		case 7: return 6; 
				break;
		case 8: return '*'; /* ASCII Code of '*' */
				break;		
		case 9: return 1; 
				break;
		case 10: return 2; 
				break;
		case 11: return 3; 
				break;
		case 12: return '-'; /* ASCII Code of '-' */
				break;
		case 13: return 13;  /* ASCII of Enter */
				break;			
		case 14: return 0; 
				break;
		case 15: return '='; /* ASCII Code of '=' */
				break;
		case 16: return '+'; /* ASCII Code of '+' */
				break;
		default: return button_number;								 						
	}
}
