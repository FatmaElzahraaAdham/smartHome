
#include"STD_Lib.h"
#include"avr/io.h"
#include"avr/delay.h"
#include"LCD.h"
#include"DIO.h"

void LCD_VidInit(void)
{
	//Directions
	DIO_VidSetPinDirection( LCD_RS_PORT , LCD_RS_PIN , DIO_OUTPUT );
	DIO_VidSetPinDirection( LCD_RW_PORT , LCD_RW_PIN , DIO_OUTPUT );
	DIO_VidSetPinDirection( LCD_E_PORT , LCD_E_PIN , DIO_OUTPUT );
	DIO_VidSetPortDirection( LCD_DATA_COMMAND_PORT , 0b11111111 );


	_delay_ms(35);

	LCD_VidSendCommand( 0b00111000 );

	_delay_us(45);

	LCD_VidSendCommand( 0b00001100 );

	_delay_us(45);

	LCD_VidSendCommand( 0b00000001 );

	_delay_ms(2);

	LCD_VidSendCommand( 0b00000110 );

}


void LCD_VidSendCommand( u8 Copy_U8Command )
{
	//RS = 0
	DIO_VidSetPinValue( LCD_RS_PORT , LCD_RS_PIN , DIO_LOW );

	//RW = 0
	DIO_VidSetPinValue( LCD_RW_PORT , LCD_RW_PIN , DIO_LOW );

	//Command
	DIO_VidSetPortValue( LCD_DATA_COMMAND_PORT , Copy_U8Command ) ;


	//E
	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_HIGH );

	_delay_us(1);

	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_LOW);

}

void LCD_VidSendChar( u8 Copy_U8Char )
{
	//RS =1
	DIO_VidSetPinValue( LCD_RS_PORT , LCD_RS_PIN , DIO_HIGH );

	//RW = 0
	DIO_VidSetPinValue( LCD_RW_PORT , LCD_RW_PIN , DIO_LOW );

	//Command
	DIO_VidSetPortValue( LCD_DATA_COMMAND_PORT , Copy_U8Char ) ;


	//E
	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_HIGH );

	_delay_us(1);

	DIO_VidSetPinValue( LCD_E_PORT , LCD_E_PIN , DIO_LOW );

}
/*void LCD_Send_command(u8 command){
    DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_Low);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_Low);
	DIO_VidSetPortValue(DIO_PORTB,command);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_High);
	_delay_ms(5);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_Low);
	_delay_ms(5);
}
void LCD_VidSendChar(u8 command){
    DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_High);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_Low);
	DIO_VidSetPortValue(DIO_PORTB,command);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_High);
	_delay_ms(5);
	DIO_VidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_Low);
	_delay_ms(5);
}*/

void LCD_VidSendString( u8 *Copy_Pu8String ) {
	for(int i=0;Copy_Pu8String[i]!='\0';i++){
		LCD_VidSendChar(Copy_Pu8String[i]);
	}
}

//Send Number
void LCD_VidSendNumber( u32 Copy_U32Number ){

	u32 Local_u32Counter=1 , Local_u32Digit=0;

		if (Copy_U32Number == 0)
		{
			LCD_VidSendChar('0');
		}
		else
		{
			while (Copy_U32Number/Local_u32Counter != 0)
			{
				Local_u32Counter *= 10;
			}
			Local_u32Counter /=10;

			while (Local_u32Counter != 0)
			{
				Local_u32Digit = Copy_U32Number/Local_u32Counter;

				LCD_VidSendChar(Local_u32Digit + '0');

				Copy_U32Number = Copy_U32Number%Local_u32Counter;

				Local_u32Counter /= 10;
			}
		}
}

void LCD_VidGoToLocation ( u8 Copy_U8RowNumber , u8 Copy_U8ColNumber )
{
	if( Copy_U8RowNumber == LCD_FIRST_LINE )
	{
		LCD_VidSendCommand( 0b10000000/*For Busy Flag*/ + Copy_U8ColNumber );
	}
	else if( Copy_U8RowNumber == LCD_Second_LINE )
	{
		LCD_VidSendCommand( 0b10000000/*For Busy Flag*/ + 0b01000000/*First address of line 2*/ + Copy_U8ColNumber);
	}
}
void LCD_VidDelChar()
{
	LCD_VidSendCommand(0b00000001);
	LCD_VidSendCommand(0b10000000);


}

