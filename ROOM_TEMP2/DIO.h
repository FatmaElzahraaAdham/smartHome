#ifndef DIO_H_
#define DIO_H_


#include"STD_Lib.h"
#include"BIT_MATH.h"
#include"avr/io.h"
#include"avr/delay.h"

#define DIO_Intput  0
#define DIO_Output 1

#define DIO_High  1
#define DIO_Low   0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

/*Function to set the direction */
void DIO_VidSetPinDirection( u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Direction);
/*Function to set the value */
void DIO_VidSetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin,u8 Copy_u8Value);

void DIO_VidSetPortDirection( u8 Copy_U8Port , u8 Copy_U8Direction );

void DIO_VidSetPortValue ( u8 Copy_U8Port , u8 Copy_U8Value );

void DIO_VidTogglePinValue(u8 Copy_U8Port,u8 Copy_U8Pin);
u8 DIO_GetPinValue(u8 Copy_U8Port,u8 Copy_U8Pin);

#endif
