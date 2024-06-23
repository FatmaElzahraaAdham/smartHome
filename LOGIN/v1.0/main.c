#include"DIO.h"
#include"LCD.h"
#include"KBD.h"
#include"DIO.h"
#define F_CPU 8000000UL
#include"avr/delay.h"


u16 pass=12345;

u16 times=0;
u16 rep=0;
u32 conc_val=0;
void conc(u16 x,u16 times){
		conc_val=(conc_val*10)+x;


				if(times==5){
								if(conc_val==pass){
									LCD_VidDelChar();
									LCD_VidSendString("ppass is right");
									DIO_VidSetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);

								}
								else {
									conc_val=0;
									LCD_VidDelChar();
									LCD_VidSendString("ppass is wrong");
									DIO_VidSetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
									_delay_ms(200);
									times=0;

									LCD_VidDelChar();
									return ;


								}
							}




}


void main(void)
{



	//****************************LOGIN*****************************************
	u16 i;
	u8 Local_U8Key ;
	KBD_VidInit();
	LCD_VidInit();
	DIO_VidSetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	DIO_VidSetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUTPUT);
	while(1)
	{
		//***************LOGIN*****************
		Local_U8Key = KBD_U8GetPressedKey();

		if( Local_U8Key != 20 )
		{
				switch(Local_U8Key)
							{
							case '0' :
								LCD_VidSendChar('0');
								times++;
								conc(0,times);
								break;

							case '1' :
								LCD_VidSendChar('1');
								times++;
								conc(1,times);
								break;
							case '2' :
								LCD_VidSendChar('2');
								times++;
								conc(2,times);
								break;
							case '3' :
								LCD_VidSendChar('3');
								times++;
								conc(3,times);
								break;
							case '4' :
								LCD_VidSendChar('4');
								times++;
								conc(4,times);
								break;
							case '5':
								LCD_VidSendChar('5');
								times++;
								conc(5,times);
								break;
							case '6' :
								LCD_VidSendChar('6');
								times++;
								conc(6,times);
								break;
							case '7' :
								LCD_VidSendChar('7');
								times++;
							  conc(7,times);
								break;
							case '8' :
								LCD_VidSendChar('8');
								times++;
								conc(8,times);
								break;
							case '9' :
								LCD_VidSendChar('9');
								times++;
								conc(9,times);
								break;

							}

			}



			}

			}




