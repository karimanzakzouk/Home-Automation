/*
 *  Created on: Jan 31, 2019
 *      Author: kariman
 */

#ifndef MCAL_WUART_UART_INT_H_
#define MCAL_MUART_UART_INT_H_

#include"../../LIB/STD_TYPES.h"



void UART_Init(void);


void UART_SendChar(u8 data);


u8 UART_GetChar(void);


void UART_SendString(u8* str1);


u8* UART_GetString(void);



#endif /*  MCAL_WUART_UART_INT_H_ */
