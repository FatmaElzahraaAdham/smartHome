///////////////////////master
#include"SPI.h"
#define F_CPU 8000000UL
#include"avr/delay.h"
#include "avr/io.h"
#include"STD_Lib.h"
#include"BIT_Math.h"
#include"DIO.h"
#include "Timers.h"
#include"ADC.h"
void main(void){

	// pins
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN7,DIO_Output);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN6,DIO_Intput);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN5,DIO_Output);
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN4,DIO_Output);

	SPI_VidMasterInit();
	//*****LM35*******
	ADC_VidInit();
	u16 Local_U16DigitalResult , Local_U16AnalogResult ,Local_U16Temp ;
	OCR0=0;
	DIO_VidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_Output);
	Timers_VidTimer0Init();


	while(1){
		_delay_ms(500);
		SPI_U8Transmit('f');
		//***LM35
		Local_U16DigitalResult = ADC_U16GetDigitalValue( ADC_CHANNEL_0 );
				// analog = digital * step
		Local_U16AnalogResult =(u16)((Local_U16DigitalResult * 2560UL) / (1024)) ;

		Local_U16Temp = Local_U16AnalogResult / 10 ;
		if((Local_U16Temp<20)){
				OCR0=0;
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

