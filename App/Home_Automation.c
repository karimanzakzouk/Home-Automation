/*
 *  Created on: Feb 23, 2019
 *      Author: kariman
 */


#include"../LIB/STD_TYPES.h"
#include"../MCAL/MDIO/DIO_int.h"
#include"../MCAL/MDIO/DIO_priv.h"
#include"../MCAL/MUART/UART_int.h"
#include"../MCAL/MUART/UART_priv.h"
#include"../MCAL/MINT/INT_int.h"
#include"../MCAL/MINT/INT_priv.h"

typedef struct
{
u8*  name;
u8*  password;

}user;

user user1[10] = { {"kimo" , "1230"} , {"asmaa" ,"1231"}, {"samar"  ,"1232"} , {"shimaa"  ,"1233"},
                   {"karim", "1234"} , {"ali", "1235"} , {"aya" ,"1236"} , {"ahmed" ,"1237"} ,
				   {"reem"  ,"1238"} ,{"mohamed" ,"1239"}  };


void main (void)
{
	u8  i=0 , j=0, identical_name =0 , identical_password =0 , trials =0 , state =0 , order =0 , not_found =0;
	u8 *ptr_password =0 , *ptr_name = 0 ;


	DIO_SetPinDirection ( PIN8, OUTPUT );
	DIO_SetPinDirection ( PIN9, OUTPUT );
	DIO_SetPinDirection ( PIN10, OUTPUT );
	DIO_SetPinDirection ( PIN12, OUTPUT );
	DIO_SetPinDirection ( PIN11, INPUT );
 	DIO_SetPinValue( PIN11 , HIGH);

	UART_Init();

    while(1)
    {
		if ( state ==0 ) /// check name
		{
			    UART_SendString("\nenter your name\n");
				ptr_name =  UART_GetString() ;
				UART_SendString(ptr_name);
				identical_name =0; not_found = 0; j=0;  i=0; trials=0;

				 while( ( (user1[i].name[j] != '\0') || (ptr_name[j] != '\0') ) && (not_found == 0) )
				 {
						  if ( (user1[i].name[j]) == ptr_name[j] )
						  {
								  identical_name = 1 ;
								  j++;
						  }
						  else
						  {
								  identical_name = 0;

								  if( i < 9 )
								  {
									  j=0;
									  i++;
								  }
								  else
								  {
									  not_found = 1;
								  }
						  }
				 }

				 if(identical_name == 1)
				 {
					  UART_SendString("\ncorrect name");
					  state = 1 ;
				 }
				 else
				 {
					  UART_SendString("\nIncorrect name");
					  state = 0;
				 }
		}

		else if (state == 1 ) // check password
		{
			   while( (state == 1) && (trials!=3) )
	           {
				     UART_SendString("\nenter your password\n");
				     ptr_password = UART_GetString() ;
					 UART_SendString( ptr_password );
					 j=0;  identical_password=1;

					 while( ( ( (user1[i].password[j]) != '\0') || (ptr_password[j] != '\0') ) && (identical_password == 1) ) //system_password[j]
					 {
							  if (  (user1[i].password[j]) == ptr_password[j] ) 
							  {
								  identical_password = 1 ;
								  j++;
							  }
							  else
							  {
								  identical_password =0;
							  }
					 }
					 if( identical_password == 1 )
					 {
						  UART_SendString("\nCorrect Password");
						  DIO_SetPinValue( PIN8, HIGH);
						  UART_SendString("\ndoor opened");
						  state = 2;
					 }
					 else
					 {
						    UART_SendString("\nIncorrect Password");

						    if(trials < 2)
						    {
						     	UART_SendString("\ntry again");
						    }
							trials++;

    						if( trials == 3 ) // block and alarm
    						{
        						 DIO_SetPinValue( PIN10, HIGH); 
        						 UART_SendString("\nNo more trials");
    						}
					 }
	           }
		}

		else if ( state == 2 ) // access system
		{
			     UART_SendString("\nenter your order\n");
				 order = UART_GetChar();
				 UART_SendChar(order);

                 //door
				 if(order == '1')
				 {
					 	 DIO_SetPinValue( PIN8, HIGH);
					     UART_SendString("\ndoor opened");
				 }
				 else if (order == '2')
				 {
						DIO_SetPinValue( PIN8, LOW);
					    UART_SendString("\ndoor closed");
				 }
				 else {}

                 //led
				 if(order == '3')
				 {
						DIO_SetPinValue( PIN9, HIGH);
					    UART_SendString("\nLED ON");
				 }
				 else if (order == '4')
				 {
						DIO_SetPinValue( PIN9, LOW);
					    UART_SendString("\nLED OFF");
				 }
				 else{}

                 //fan
				 if(order == '5')
				 {
					 	DIO_SetPinValue( PIN12, HIGH);
					    UART_SendString("\nFAN ON");
				 }
				 else if (order == '6')
				 {
						DIO_SetPinValue( PIN12, LOW);
					    UART_SendString("\nFAN OFF");
				 }
				 else {}

                 //reset
				 if(order == '9')
				 {
					    UART_SendString("\nreset");
					 
					    DIO_SetPinValue( PIN8, LOW);
					    DIO_SetPinValue( PIN9, LOW);
					    DIO_SetPinValue( PIN12, LOW);
					    state = 0 ;
				 }
				 else{}
		}

	      //switch to reset system
		  if( (DIO_GetPinValue(PIN11)) == LOW )
		  {
		    	UART_SendString("\nreset");
		    	DIO_SetPinValue( PIN10, LOW); // alarm
		    	state = 0;
		  }

    }
}
