#include"STD_Lib.h"
#include"BIT_Math.h"
#define F_CPU 8000000UL
#include "avr/delay.h"
#include"DIO.h"
#include"avr/interrupt.h"
#include "Timers.h"
#include"ADC.h"
#include"LCD.h"
#include"SPI.h"



void main(void)
{
	//***********lamp illusion depends on time***********
	OCR0=0;
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_Output);
	Timers_VidTimer0Init();
	LCD_VidInit();
	//*******SPI*********************
	u8 x;
		// pins
		DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_Intput);
		DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_Output);
		DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_Intput);
		DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_Intput);

		//DIO_VidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_Output);

	ADC_VidInit();

	u16 Local_U16DigitalResult , Local_U16AnalogResult ,Local_U16Temp ;


	while(1)
	{
		//***********lamp illusion depends on time***********
		LCD_VidSendChar('1');
		LCD_VidSendChar('2');
		LCD_VidSendChar('p');
		LCD_VidSendChar('m');
		_delay_ms(300);
		 	LCD_VidDelChar();
		LCD_VidSendChar('5');
		LCD_VidSendChar('5');
		LCD_VidSendChar('p');
		LCD_VidSendChar('m');
		OCR0=50;
		_delay_ms(300);
		LCD_VidDelChar();
		LCD_VidSendChar('1');
		LCD_VidSendChar('1');
		LCD_VidSendChar('2');
		LCD_VidSendChar('a');
		LCD_VidSendChar('m');
		OCR0=250;
		_delay_ms(300);
		LCD_VidDelChar();
		OCR0=0;


		//*******SPI2*********
		Local_U16DigitalResult = ADC_U16GetDigitalValue( ADC_CHANNEL_0 );
		// analog = digital * step
		Local_U16AnalogResult =(u16)((Local_U16DigitalResult * 2560UL) / (1024)) ;

		Local_U16Temp = Local_U16AnalogResult / 10 ;


		SPI_VidSlaveInit();

		_delay_ms(505);
		x=SPI_U8Recieve();
		if(x=='f'){
			//DIO_VidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_High);
			//DIO_VidTogglePinValue(DIO_PORTA,DIO_PIN0);
			Timer_VidTimer1Init();
			DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN5 , DIO_Output );

		}

	}

}
