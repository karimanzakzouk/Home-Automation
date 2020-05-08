/*
 * INT_int.h
 *
 *  Created on: Jan 23, 2019
 *      Author: kariman
 */

#ifndef MCAL_MINT_INT_INT_H_
#define MCAL_MINT_INT_INT_H_


#  define __INTR_ATTRS used, externally_visible

#  define ISR(vector, ...)            \
    void  vector  (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void  vector  (void)



void GlobalInt_EN (void);


void ExtInt0_Init (u8 u8ExtInt0_SENSE);


void ExtInt1_Init (u8 u8ExtInt1_SENSE);


void ExtInt2_Init (u8 u8ExtInt2_SENSE);


void ExtInt0_change_SENSE (u8 u8Int0_SENSE);

void ExtInt1_change_SENSE (u8 u8Int1_SENSE);

void ExtInt2_change_SENSE (u8 u8Int2_SENSE);


/* call back function */

void EXTint0_callback(void);

void EXTint1_callback(void);

void EXTint2_callback(void);


void EXTint0_func_setter (void(*EXTint0_callback)(void));

void EXTint1_func_setter (void(*EXTint1_callback)(void));

void EXTint2_func_setter (void(*EXTint2_callback)(void));


#endif /* MCAL_MINT_INT_INT_H_ */
