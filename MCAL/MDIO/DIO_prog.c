/*
 * DIO.c
 *
 *  Created on: Dec 29, 2018
 *      Author: kariman
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/MACROS.h"
#include "DIO_int.h"
#include "DIO_priv.h"



void DIO_SetPinDirection (u8 u8PinNoCopy, u8 u8PinDirCopy)  
{
	  u8 u8port_num;
	  u8 u8pin_num;

	  u8pin_num  = u8PinNoCopy%8;
	  u8port_num = u8PinNoCopy/8;

	  if ((u8port_num<= PORT3) && (u8pin_num  <= PIN7))
			{
				if (u8PinDirCopy == OUTPUT)
				{
					switch (u8port_num)
					{
						case PORT0:
							SET_BIT(DDRA_Reg,u8pin_num );
							break;
						case PORT1:
							SET_BIT(DDRB_Reg,u8pin_num );
							break;
						case PORT2:
							SET_BIT(DDRC_Reg,u8pin_num );
							break;
						case PORT3:
							SET_BIT(DDRD_Reg,u8pin_num );
							break;
						default:
							   /* Wrong Port No */
						    break;
					}

				}

				else if (u8PinDirCopy == INPUT)
				{

					switch (u8port_num)
					{
						case PORT0:
							CLR_BIT(DDRA_Reg,u8pin_num );
							break;
						case PORT1:
							CLR_BIT(DDRB_Reg,u8pin_num );
							break;
						case PORT2:
							CLR_BIT(DDRC_Reg,u8pin_num );
							break;
						case PORT3:
							CLR_BIT(DDRD_Reg,u8pin_num);
							break;
						default:
							   /* Wrong Port No */
						    break;
					}
				}
				else
				{
					// Do nothing, Wrong value to set
				}
			}
			else
			{
				// Do nothing, Error in the Pin No or PORT No
			}

}
void DIO_SetPinValue(u8 u8PinNoCopy, u8 u8PinValCopy) 
{
		u8 u8port_num;
		u8 u8pin_num;

		u8pin_num  = u8PinNoCopy%8;
		u8port_num = u8PinNoCopy/8;

		if ((u8port_num <= PORT3) && (u8pin_num <= PIN7))
			{
				if (u8PinValCopy == HIGH)
				{
					switch (u8port_num)
					{
						case PORT0:
							SET_BIT(PORTA_Reg,u8pin_num);
							break;
						case PORT1:
							SET_BIT(PORTB_Reg,u8pin_num);
							break;
						case PORT2:
							SET_BIT(PORTC_Reg,u8pin_num);
							break;
						case PORT3:
							SET_BIT(PORTD_Reg,u8pin_num);
							break;
						default:
							   /* Wrong Port No */
							break;
					}
				}
				else if (u8PinValCopy == LOW)
				{
					switch (u8port_num)
					{
						case PORT0:
							CLR_BIT(PORTA_Reg,u8pin_num );
							break;
						case PORT1:
							CLR_BIT(PORTB_Reg,u8pin_num);
							break;
						case PORT2:
							CLR_BIT(PORTC_Reg,u8pin_num);
							break;
						case PORT3:
							CLR_BIT(PORTD_Reg,u8pin_num);
							break;
						default:
							   /* Wrong Port No */
							break;
					}
				}
				else
				{
					// Do nothing, Wrong value to set
				}
			}
			else
			{
				// Do nothing, Error in the Pin No or PORT No
			}
}
 u8 DIO_GetPinValue(u8 u8PinNoCopy)        
{
	        u8 u8port_num;
            u8 u8pin_num;
			u8 u8InputPinValue;

			u8pin_num =  u8PinNoCopy  % 8;
			u8port_num = u8PinNoCopy  / 8;
			
			if((u8port_num <= PORT3) && (u8pin_num <= PIN7))
			{
				switch (u8port_num)
				{
					case PORT0:
					u8InputPinValue = ( GET_BIT(PINA_Reg,u8pin_num) )  & 0x01;
						break;
					case PORT1:
						u8InputPinValue = ( GET_BIT(PINB_Reg,u8pin_num) )  & 0x01;
						break;
					case PORT2:
						u8InputPinValue = ( GET_BIT(PINC_Reg,u8pin_num)  )  & 0x01 ;
						break;
					case PORT3:
						u8InputPinValue = ( GET_BIT(PIND_Reg,u8pin_num) )   & 0x01;
						break;
					default:
						              /* Wrong Port No */
						break;
				}
			}
		    else
			{
				  // return 0xff in case of error in the Pin No or PORT No
				  u8InputPinValue = 0xFF;
		    }
	       return u8InputPinValue;
}


void DIO_SetPortDirection (u8 u8PortNo, u8 u8PortDir) 
{
	if (u8PortNo <= PORT3)
	{
					if (u8PortDir == OUTPUT_PORT)
					{
						switch (u8PortNo)
						{
							case PORT0:
								SET_PORT(DDRA_Reg);
								break;
							case PORT1:
								SET_PORT(DDRB_Reg);
								break;
							case PORT2:
								SET_PORT(DDRC_Reg);
								break;
							case PORT3:
								SET_PORT(DDRD_Reg);
								break;
							default:
								   /* Wrong Port No */
							    break;
						}

					}

					else if (u8PortDir == INPUT)
					{

						switch (u8PortNo)
						{
							case PORT0:
								CLR_PORT(DDRA_Reg);
								break;
							case PORT1:
								CLR_PORT(DDRB_Reg);
								break;
							case PORT2:
								CLR_PORT(DDRC_Reg);
								break;
							case PORT3:
								CLR_PORT(DDRD_Reg);
								break;
							default:
								   /* Wrong Port No */
							    break;
						}
					}
					else
					{

							switch (u8PortNo)
							{
							case PORT0:

								 SET_PORTValue(DDRA_Reg,  u8PortDir);
								break;
							case PORT1:
								 SET_PORTValue(DDRB_Reg, u8PortDir);
								break;
							case PORT2:
								 SET_PORTValue(DDRC_Reg, u8PortDir);
								break;
							case PORT3:
								 SET_PORTValue(DDRD_Reg, u8PortDir);
								break;
							default:
								   /* Wrong Port No */
							    break;
					         }
					 }
	}
				else
				{
					// Do nothing, Error in  PORT No
				}
}

void DIO_SetPortValue(u8 u8PortNo, u8 u8PortVal) 
{

	if (u8PortNo <= PORT3)
					{
						if (u8PortVal== HIGH_PORT)
						{
							switch (u8PortNo)
							{
								case PORT0:
									SET_PORT(PORTA_Reg);
									break;
								case PORT1:
									SET_PORT(PORTB_Reg);
									break;
								case PORT2:
									SET_PORT(PORTC_Reg);
									break;
								case PORT3:
									SET_PORT(PORTD_Reg);
									break;
								default:
									   /* Wrong Port No */
								    break;
							}

						}

						else if (u8PortVal == LOW)
						{

							switch (u8PortNo)
							{
								case PORT0:
									CLR_PORT(PORTA_Reg);
									break;
								case PORT1:
									CLR_PORT(PORTB_Reg);
									break;
								case PORT2:
									CLR_PORT(PORTC_Reg);
									break;
								case PORT3:
									CLR_PORT(PORTD_Reg);
									break;
								default:
									   /* Wrong Port No */
								    break;
							}
						}
						else
						{
							switch (u8PortNo)
							{
								case PORT0:
									 SET_PORTValue(PORTA_Reg, u8PortVal);
									break;
								case PORT1:
									 SET_PORTValue(PORTB_Reg,u8PortVal);
									break;
								case PORT2:
									 SET_PORTValue(PORTC_Reg,u8PortVal);
									break;
								case PORT3:
									 SET_PORTValue(PORTD_Reg,u8PortVal);
									break;
								default:
									   /* Wrong Port No */
								    break;
						     }

						}
					}
					else
					{
						// Do nothing, Error in  PORT No
					}
}

extern u8 DIO_GetPortValue(u8 u8PortNo)  
{
	u8 u8InputPortValue;
	if(u8PortNo <= PORT3)
	{
		switch(u8PortNo)
		{
		   case PORT0 :
			 u8InputPortValue =   ( GET_PORT(PINA_Reg) )  & 0xFF ;
			   break;
		   case PORT1 :
			   u8InputPortValue = ( GET_PORT(PINB_Reg) )  & 0xFF ;
			   break;
		   case PORT2 :
			   u8InputPortValue = ( GET_PORT(PINC_Reg) )  & 0xFF ;
			   break;
		   case PORT3 :
			   u8InputPortValue = ( GET_PORT(PIND_Reg) )  & 0xFF ;
			   break;
		   default:
			   /* Wrong Port No */
			   break;
		}
	}
	else
	{
		//error in the PORT No
	}
	return u8InputPortValue;
}
