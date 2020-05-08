
#ifndef  MCAL_MUART_UART_PRIV_H_
#define  MCAL_MUART_UART_PRIV_H_

#include"../../LIB/STD_TYPES.h"



#define  UBRRL_Reg   *((volatile u8*)0x29)

#define  UBRRH_Reg   *((volatile u8*)0x40)

#define  UCSRA_Reg   *((volatile u8*)0x2B)

#define  UCSRB_Reg   *((volatile u8*)0x2A)

#define  UCSRC_Reg   *((volatile u8*)0x40)


#define  UDR_Reg     *((volatile u8*)0x2C)


// cotrol and status Register UCSRA


#define URXC  128  // USART Receive Complete  BIT 7

#define UTXC 64  // USART Transmit Complete  BIT 6

#define UDRE  32  // USART Data Register Empty   BIT 5

#define UFE  16  // Frame Error BIT   4

#define UDOR  8  // Data OverRun BIT  3

#define UPE  4  // Parity Error BIT  2

#define UU2X  2  // Double the USART Transmission Speed  BIT 1

#define UMPCM  1 //  Multi-processor Communication Mode Bit  0


//control and status Register UCSRB


#define URXCIE  128  // Bit 7 � RXCIE: RX Complete Interrupt Enable

#define UTXCIE 64  // Bit 6 � TXCIE: TX Complete Interrupt Enable

#define UDRIE  32  // Bit 5 � UDRIE: USART Data Register Empty Interrupt Enable

#define URXEN  16  // Bit 4 � RXEN: Receiver Enable

#define UTXEN  8  // Bit 3 � TXEN: Transmitter Enable

#define UCSZ2  4  // Bit 2 � UCSZ2: Character Size

#define URXB8  2  // Bit 1 � RXB8: Receive Data Bit 8

#define UTXB8  1 //  Bit 0 � TXB8: Transmit Data Bit 8



//control and status Register � UCSRC


#define URSEL  128  // Bit 7 � URSEL: Register Select

#define UMSEL 64  // Bit 6 � UMSEL: USART Mode Select

// Bit 5:4 � UPM1:0: Parity Mode
/*
 * UPM Bits Settings
UPM1 UPM0 Parity Mode
0 0 Disabled
0 1 Reserved
1 0 Enabled, Even Parity
1 1 Enabled, Odd Parity
 */
#define UPM0  32

#define UPM1  16

/*
 * USBS Bit Settings
USBS Stop Bit(s)
0 1-bit
1 2-bit
 */
#define UDOR  8  // Bit 3 � USBS: Stop Bit Select

//Bit 2:1 � UCSZ1:0: Character Size
/*
 *UCSZ Bits Settings
UCSZ2 UCSZ1 UCSZ0 Character Size
0 0 0 5-bit
0 0 1 6-bit
0 1 0 7-bit
0 1 1 8-bit
1 0 0 Reserved
1 0 1 Reserved
1 1 0 Reserved
1 1 1 9-bit

 *
 */
#define UCSZ1  4  // Bit 2 � UCSZ2: Character Size

#define UCSZ0  2  // Bit 1 � RXB8: Receive Data Bit 8

/*
 * UCPOL Bit Settings
UCPOL
Transmitted Data Changed (Output of
TxD Pin)
Received Data Sampled (Input on
RxD Pin)
0 Rising XCK Edge Falling XCK Edge
1 Falling XCK Edge Rising XCK Edge
 */
#define UCPOL  1 //  Bit 0 � UCPOL: Clock Polarity



//USART Baud Rate Registers �UBRRL and UBRRH

#define URSEL  128  //Bit 15 � URSEL: Register Select //UBRRH




#endif /* MCAL_MUART_UART_PRIV_H_ */
