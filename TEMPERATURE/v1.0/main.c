#include"STD_Lib.h"
#include"BIT_Math.h"
#define F_CPU 8000000UL
#include "avr/delay.h"
#include"DIO.h"
#include "Timers.h"
#include"ADC.h"
#include"LCD.h"

void main(void)
{
	ADC_VidInit();
	//LCD_VidInit();

	u16 Local_U16DigitalResult , Local_U16AnalogResult ,Local_U16Temp ;
	OCR0=0;
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_Output);
	Timers_VidTimer0Init();
	while(1)
	{
		Local_U16DigitalResult = ADC_U16GetDigitalValue( ADC_CHANNEL_0 );
		// analog = digital * step
		Local_U16AnalogResult =(u16)((Local_U16DigitalResult * 2560UL) / (1024)) ;

		Local_U16Temp = Local_U16AnalogResult / 10 ;

//		LCD_VidSendNumber(Local_U16Temp);
//
//		_delay_ms(2000);
//
//		LCD_VidSendCommand(0x01);

		//_delay_ms(500);
			if((Local_U16Temp<20)){
				OCR0=0;
//				DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN5 , DIO_Output );
//				DIO_VidSetPinValue(DIO_PORTD , DIO_PIN5,DIO_High);
//				DIO_VidSetPinDirection( DIO_PORTD , DIO_PIN6 , DIO_Output );
//								DIO_VidSetPinValue(DIO_PORTD , DIO_PIN6,DIO_High);
							//Timer_VidTimer1Init();
				_delay_ms(100);

			}
			else if((Local_U16Temp>20) && (Local_U16Temp<30)){
				OCR0=102;
				_delay_ms(100);
			}
			else if((Local_U16Temp>30)){
							OCR0=255;
							_delay_ms(100);
						}


	}

}
