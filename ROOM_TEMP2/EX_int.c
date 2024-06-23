#include "EX_int.h"

void (*Int0_PFUN)(void);
void (*Int1_PFUN)(void);
void (*Int2_PFUN)(void);

void EX_INT0VidInit(void){
	SET_BIT(SREG ,7);
	SET_BIT(GICR ,6);
//	falling
	CLR_BIT(MCUCR ,0);
	SET_BIT(MCUCR ,1);
}

void EX_INT0VidSetCallBack(void (*ptr)(void)){
	Int0_PFUN=ptr;

}
void EX_INT1VidInit(void){

	SET_BIT(SREG ,7);
	SET_BIT(GICR ,7);
	CLR_BIT(MCUCR ,2);
	SET_BIT(MCUCR ,3);
}
void EX_INT1VidSetCallBack(void (*ptr)(void)){
	Int1_PFUN=ptr;

}

void EX_INT2VidInit(void){

	SET_BIT(SREG ,7);
	SET_BIT(GICR ,5);
	CLR_BIT(MCUCSR ,6);
}
void EX_INT2VidSetCallBack(void (*ptr)(void)){
	Int2_PFUN=ptr;

}

ISR(INT0_vect){
	Int0_PFUN();
}

ISR(INT1_vect){
	Int1_PFUN();
}

ISR(INT2_vect){

	Int2_PFUN();
}
