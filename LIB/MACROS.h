/*
 * maros.h
 *
 *  Created on: Dec 29, 2018
 *      Author: kimoz
 */

#ifndef LIB_MACROS_H_
#define LIB_MACROS_H_

#define SET_BIT(var,bitno)     var |= (1<<bitno)

#define CLR_BIT(var,bitno)     var &= (~(1<<bitno))

#define TOG_BIT(var,bitno)     var ^= (1<<bitno)

#define GET_BIT(VAR,BITNO)     (  ( (VAR) >> (BITNO) ) & 0x01  )


#define SET_PORT(port)         port = 0xFF

#define CLR_PORT(port)         port = 0x00

#define GET_PORT(port)         port &= 0xFF

#define SET_PORTValue(port,value)      port = value



#define  conc(x0,x1,x2,x3,x4,x5,x6,x7)  conchelp(x0,x1,x2,x3,x4,x5,x6,x7)
#define  conchelp(x0,x1,x2,x3,x4,x5,x6,x7)  0b##x7##x6##x5##x4##x3##x2##x1##x0


#endif /* LIB_MACROS_H_ */
