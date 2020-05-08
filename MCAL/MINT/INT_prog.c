/*
 * INT_prog.c
 *
 *  Created on: Jan 23, 2019
 *      Author: kariman
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/MACROS.h"
#include "INT_cfg.h"
#include "INT_int.h"
#include "INT_priv.h"
#include"../MDIO/DIO_int.h"

u8  ExtInt0_SENSE ,  ExtInt1_SENSE  , ExtInt2_SENSE ;



void GlobalInt_EN (void)
{

	SET_BIT( SREG_Reg , 7);  //GIE

	 MCUCR_Reg = ExtInt0_SENSE + ExtInt1_SENSE ;
	 MCUCSR_Reg =	 ExtInt2_SENSE ;

}

void GlobalInt_DIS (void)
{

	CLR_BIT( SREG_Reg , 7);  //GIE
}


void ExtInt0_Init (u8 u8ExtInt0_SENSE)
{
	//EXT INT0 EN
	 GICR_Reg += ExtInt0_EN;

    //RISING/Falling
	 ExtInt0_SENSE =  u8ExtInt0_SENSE ;   
	 MCUCR_Reg = ExtInt0_SENSE + ExtInt1_SENSE ;

	//EXT INT 0 >INPUT   /////PD2
	DIO_SetPinDirection ( PIN26, INPUT);
	//pull up
	DIO_SetPinValue( PIN26, HIGH);

}

void ExtInt1_Init (u8 u8ExtInt1_SENSE)
{
		//EXT INT1  EN
		 GICR_Reg += ExtInt1_EN;

	    //RISING/Falling
		 ExtInt1_SENSE =  u8ExtInt1_SENSE ;
		 MCUCR_Reg = ExtInt0_SENSE + ExtInt1_SENSE ;

		//EXT INT1 >INPUT   PD3
		DIO_SetPinDirection ( PIN27, INPUT);
		//pull up
		DIO_SetPinValue( PIN27, HIGH);

}
void ExtInt2_Init (u8 u8ExtInt2_SENSE)
{
		//EXT INT2  EN
		 GICR_Reg += ExtInt2_EN;

	    //RISING/Falling
		 ExtInt2_SENSE =  u8ExtInt2_SENSE ;
		 MCUCSR_Reg =	 ExtInt2_SENSE ;


	// EXT INT2 >INPUT   PB2
	DIO_SetPinDirection ( PIN10, INPUT);
	//pull up
	DIO_SetPinValue( PIN10 , HIGH);

}

void ExtInt0_change_SENSE (u8 u8Int0_SENSE)
{
	//RISING/Falling
	ExtInt0_SENSE =  u8Int0_SENSE ;

	 MCUCR_Reg = ExtInt0_SENSE + ExtInt1_SENSE ;
}

void ExtInt1_change_SENSE (u8 u8Int1_SENSE)
{
   //RISING/Falling
	ExtInt1_SENSE =  u8Int1_SENSE ;

	MCUCR_Reg = ExtInt0_SENSE + ExtInt1_SENSE ;

}

void ExtInt2_change_SENSE (u8 u8Int2_SENSE)
{
    //RISING/Falling
	ExtInt2_SENSE =  u8Int2_SENSE ;

	 MCUCSR_Reg =	 ExtInt2_SENSE ;
}

ISR( EXT_INT0_vect  )
{
	EXTint0_callback();
}



ISR( EXT_INT1_vect )
{
	EXTint1_callback();
}


ISR( EXT_INT2_vect )
{
	EXTint2_callback();
}
