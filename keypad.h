
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "common_macros.h"
#include "std_types.h"

//void SystemInit(){}


typedef enum{
	PortA,PortB,PortC,PortD,PortE,PortF
}PORT;

#define KEYPAD_PORT_DATA    GPIO_PORTA_DATA_R
#define KEYPAD_PORT_DIR     GPIO_PORTA_DIR_R

	/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */

void KeyPad_Init( PORT Port);
uint8 KeyPad_getPressedKey(void);


#endif /* KEYPAD_H_ */
