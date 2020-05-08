/*
 * INT_priv.h
 *
 *  Created on: Jan 23, 2019
 *      Author: kariman
 */

#ifndef MCAL_MINT_INT_PRIV_H_
#define MCAL_MINT_INT_PRIV_H_



#define    RESET_vect                        	__vector_0

#define    EXT_INT0_vect                     	__vector_1

#define    EXT_INT1_vect                     	__vector_2

#define    EXT_INT2_vect                     	__vector_3

#define    TIMER2_COMP_vect                   	__vector_4

#define    TIMER2_OVF_vect                     	__vector_5

#define   TIMER1_CAPT_vect                    	__vector_6

#define   TIMER1_COMPA_vect                    	__vector_7

#define   TIMER1_COMPB_vect                   	__vector_8

#define   TIMER1_OVF_vect                     	__vector_9

#define    TIMER0_COMP_vect                    __vector_10

#define    TIMER0_OVF_vect                    	__vector_11

#define     SPI_STC_vect                       	__vector_12

#define    USART_RXC_vect                     	__vector_13

#define    USART_UDRE_vect                   	__vector_14

#define    USART_TXC_vect                    	__vector_15

#define    ADC_vect                           	__vector_16

#define   EE_RDY_vect                          	__vector_17

#define   ANA_COMP_vect                        	__vector_18

#define   TWI_vect                             	__vector_19

#define   SPM_RDY_vect                         	__vector_20



#define    SREG_Reg                        *((volatile u8*)0x5F   )   //GIE

#define    GICR_Reg                        *((volatile u8*)0x5B   )   //PIE

#define    MCUCR_Reg                        *((volatile u8*)0x55   )

#define    MCUCSR_Reg                        *((volatile u8*)0x54   )

#define    GIFR_Reg                        *((volatile u8*)0x5A   )

// GICR_Reg
#define    ExtInt0_EN    64

#define    ExtInt1_EN   128

#define    ExtInt2_EN    32

/*
 MCUCR_Reg
BITS  1,0  >>> (2 ,1) DEC   >>>>>>>>>>>>INT0
 BITS 3,2  >>> (8 ,4) DEC   >>>>>>>>>>>>INT1

 //  Interrupt 1 Sense Control
ISC11 ISC10 Description
0 0 The low level of INT1 generates an interrupt request.
0 1 Any logical change on INT1 generates an interrupt request.
1 0 The falling edge of INT1 generates an interrupt request.
1 1 The rising edge of INT1 generates an interrupt request.  */



#define    ExtInt0_low   0

#define    ExtInt0_Any_change   1

#define    ExtInt0_falling     2

#define    ExtInt0_rising      3


#define    ExtInt1_low   0

#define    ExtInt1_Any_change   4

#define    ExtInt1_falling     8

#define    ExtInt1_rising      12

// >>>>  MCUCSR_Reg
 // BITS 6  >>> (64 OR 0) DEC   >>INT2


#define    ExtInt2_falling     0

#define    ExtInt2_rising      64


#endif /* MCAL_MINT_INT_PRIV_H_ */
