/*
 * DIO.h
 *
 *  Created on: Dec 29, 2018
 *      Author: kariman
 */

#ifndef DIO_INT_H_
#define DIO_INT_H_


#define PORT0    0
#define PORT1    1
#define PORT2    2
#define PORT3    3


#define OUTPUT  1
#define OUTPUT_PORT  0xFF
#define INPUT   0


#define HIGH  1
#define HIGH_PORT   0xFF
#define LOW   0


#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7

#define DIO_PORT0  conc(PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7);


#define PIN8   8
#define PIN9   9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15

#define DIO_PORT1  conc(PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15);


#define PIN16   16
#define PIN17   17
#define PIN18   18
#define PIN19   19
#define PIN20   20
#define PIN21   21
#define PIN22   22
#define PIN23   23

#define DIO_PORT2   conc(PIN16,PIN17,PIN18,PIN19,PIN20,PIN21,PIN22,PIN23);


#define PIN24   24
#define PIN25   25
#define PIN26   26
#define PIN27   27
#define PIN28   28
#define PIN29   29
#define PIN30   30
#define PIN31   31

#define DIO_PORT3  conc(PIN24,PIN25,PIN26,PIN27,PIN28,PIN29,PIN30,PIN31);




void DIO_SetPinDirection ( u8 u8PinNoCopy, u8 u8PinDirCopy); 

void DIO_SetPinValue( u8 u8PinNoCopy, u8 u8PinValCopy); 

extern u8 DIO_GetPinValue( u8 u8PinNoCopy); 



void DIO_SetPortDirection (u8 u8PortNo, u8 u8PortDir); 

void DIO_SetPortValue(u8 u8PortNo, u8 u8PortVal); 

extern u8 DIO_GetPortValue(u8 u8PortNo); 


#endif /* DIO_INT_H_ */

