#ifndef EX_int_h_
#define EX_int_h_


#include"avr/interrupt.h"
#include"BIT_Math.h"
#include "STD_Lib.h"




void EX_INT0VidSetCallBack(void (*ptr)(void));
void EX_INT1VidSetCallBack(void (*ptr)(void));
void EX_INT2VidSetCallBack(void (*ptr)(void));

void EX_INT0VidInit(void);
void EX_INT1VidInit(void);
void EX_INT2VidInit(void);


#endif
