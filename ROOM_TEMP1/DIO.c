
#include"STD_Lib.h"
#include"BIT_Math.h"
#include"avr/io.h"
#include"DIO.h"

void DIO_VidSetPinDirection(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_u8Direction){

	if(Copy_u8Direction== DIO_Output){
		switch(Copy_U8Port){

				case DIO_PORTA:
					SET_BIT(DDRA,Copy_U8Pin);
					break;
				case DIO_PORTB:
					SET_BIT(DDRB,Copy_U8Pin);
					break;
				case DIO_PORTC:
					SET_BIT(DDRC,Copy_U8Pin);
					break;
				case DIO_PORTD:
					SET_BIT(DDRD,Copy_U8Pin);
					break;
				}
	}
	else if(Copy_u8Direction==DIO_Intput){
		switch(Copy_U8Port){
				case DIO_PORTA:
					CLR_BIT(DDRA,Copy_U8Pin);
					break;
				case DIO_PORTB:
					CLR_BIT(DDRB,Copy_U8Pin);
					break;
				case DIO_PORTC:
					CLR_BIT(DDRC,Copy_U8Pin);
					break;
				case DIO_PORTD:
					CLR_BIT(DDRD,Copy_U8Pin);
					break;

				}
	}

}
void DIO_VidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_u8Value){

	if(Copy_u8Value== DIO_High){
		switch(Copy_U8Port){

		    case DIO_PORTA :
				SET_BIT(PORTA,Copy_U8Pin);
				break;

			case DIO_PORTB :
				SET_BIT(PORTB,Copy_U8Pin);
				break;

			case DIO_PORTC :
				SET_BIT(PORTC,Copy_U8Pin);
				break;

			case DIO_PORTD :
				SET_BIT(PORTD,Copy_U8Pin);
				break;

						}
	}
	else if(Copy_u8Value== DIO_Low){
		switch(Copy_U8Port)
				{
					case DIO_PORTA :
						CLR_BIT(PORTA,Copy_U8Pin);
						break;

					case DIO_PORTB :
						CLR_BIT(PORTB,Copy_U8Pin);
						break;

					case DIO_PORTC :
						CLR_BIT(PORTC,Copy_U8Pin);
						break;

					case DIO_PORTD :
						CLR_BIT(PORTD,Copy_U8Pin);
						break;
				}

	}
}
void DIO_VidSetPortDirection( u8 Copy_U8Port , u8 Copy_U8Direction ){
	switch(Copy_U8Port)
			{
				case DIO_PORTA :
					DDRA = Copy_U8Direction ;
					break;

				case DIO_PORTB :
					DDRB = Copy_U8Direction ;
					break;

				case DIO_PORTC :
					DDRC = Copy_U8Direction ;
					break;

				case DIO_PORTD :
					DDRD = Copy_U8Direction ;
					break;
			}

}
void DIO_VidSetPortValue ( u8 Copy_U8Port , u8 Copy_U8Value ){
	switch(Copy_U8Port)
			{
				case DIO_PORTA :
					PORTA = Copy_U8Value ;
					break;

				case DIO_PORTB :
					PORTB = Copy_U8Value ;
					break;

				case DIO_PORTC :
					PORTC = Copy_U8Value ;
					break;

				case DIO_PORTD :
					PORTD = Copy_U8Value ;
					break;
			}

}
void DIO_VidTogglePinValue(u8 Copy_U8Port,u8 Copy_U8Pin){
	switch(Copy_U8Port)
			{
				case DIO_PORTA :
					TOGGLE_BIT(PORTA,Copy_U8Pin);
					break;

				case DIO_PORTB :
					TOGGLE_BIT(PORTB,Copy_U8Pin);
					break;

				case DIO_PORTC :
					TOGGLE_BIT(PORTC,Copy_U8Pin);
					break;

				case DIO_PORTD :
					TOGGLE_BIT(PORTD,Copy_U8Pin);
					break;
			}
}
u8 DIO_GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin){
	switch(Copy_U8Port)
			{
				case DIO_PORTA :
					GET_BIT(PINA,Copy_U8Pin);
					break;

				case DIO_PORTB :
					GET_BIT(PINB,Copy_U8Pin);
					break;

				case DIO_PORTC :
					GET_BIT(PINC,Copy_U8Pin);
					break;

				case DIO_PORTD :
					GET_BIT(PIND,Copy_U8Pin);
					break;
			}
}
