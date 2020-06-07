#ifndef __UART_H__
#define	__UART_H__

#include "micro_config.h"
/*
    Initialize UART Number index
    index range 0 to 7
*/
void UART_Init(char index);


char UART_Available(char index);

char UART_Read(char index);
void UART_Write(char index,char data);
void UART_sendString(const char *Str);

void UART_receiveString(char *Str);


#endif // __UART_H__
