
#include<util/delay.h>

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/MACROS.h"
#include "../MUART/UART_int.h"
#include "../MUART/UART_cfg.h"
#include "../MUART/UART_priv.h"

#include"../MDIO/DIO_int.h"

#include "../MINT/INT_int.h"
#include "../MINT/INT_priv.h"

  u8 str[30] = {0};

  //u8 recieved_data=0 ;

void UART_Init(void)
{
  // Set BaudRate >> 9600/8MhZ
  UBRRL_Reg = 51;
  UBRRH_Reg = 0;

  // Set Frame Format >> 8 data, 1 stop, No Parity   //BITS 7 ,2, 1 >> 1
  //UCSRC_Reg = 0x86;
   UCSRC_Reg = URSEL + UCSZ1 + UCSZ0  ;

  // Enable RX and TX - BITS 4, 3  >> 1  / Bit 2 � UCSZ2 >> 0 +  //En TX,RX interrupt
   //UCSRB_Reg = URXEN + UTXEN +  URXCIE + UDRIE;
   UCSRB_Reg = URXEN + UTXEN ;

}

void UART_SendChar(u8 data)
{
   // Wait until transmission Register Empty  //BIT 5
    while((UCSRA_Reg &0x20) == 0x00);

	SET_BIT(UCSRA_Reg,5);

    UDR_Reg = data;
}

void UART_SendString(u8* str1)
{
	 u8 j =0;

	  while( (str1[j] != '\0') )
	  {
		 UART_SendChar(str1[j]);
		 j++;
	  }
}

u8 UART_GetChar(void)
{
 u8 Result;
  // Wait until Reception Complete  //BIT 7
  while((UCSRA_Reg &0x80) == 0x00);

  Result = UDR_Reg;

  // Clear Flag
  SET_BIT(UCSRA_Reg,7);

  return Result;
}

u8* UART_GetString(void)
{
    u8 i=0 , y =0 ;

	while( ( y = UART_GetChar() ) != ',')
	{
		str[i] = y;
         i++;
	}

	//insert NULL to terminate the string
	 str[i] = '\0';

	return (str);
}



