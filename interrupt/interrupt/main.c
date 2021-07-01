// #define F_CPU 4000000
// 
// #include <avr/io.h>
// #include <util/delay.h>
// #include <avr/interrupt.h>
// #include <UART_1_AVR128DA64.h>
// 
// int i;
// 
// int main(void)
// {
// 	sei();
// 	PORTB.DIRCLR |=(1<<2);
// 	PORTB.PIN2CTRL |= (1<<3)|(3<<0); // PULL UP ENABLE AND both edge trigger
// 
// 	USART1_init(9600);
// 	_delay_ms(100);
// 	USART1_sendString("Start1");
// 
//     while (1)
//     {
// 		if (i)
// 		{
// 			USART1_sendString("Interrupted");
// 			i=0;
// 		}
// 		PORTB.INTFLAGS |= (1<<2); //Clear the interrupt flag by writing 1
//     }
// }
// 
// ISR(PORTB_PORT_vect)
// {
// 	if(PORTB.INTFLAGS & (1<<2))
// 	{
// 		i=1;
// 	}
// }



#define  F_CPU 4000000
#include <avr/io.h>
#include <util/delay.h>
#include <UART_1_AVR128DA64.h>
#include <avr/interrupt.h>


int main()
{	
	sei();
	PORTC.PIN7CTRL |= 0b00001010;
	USART1_init(9600);
	while (1)
	{
		
	}
	return 0;
}

ISR(PORTC_PORT_vect)
{
	if(PORTC.INTFLAGS & PIN7_bm)
	{	USART1_sendString("int_2 detected");
		PORTC.INTFLAGS |= PIN7_bm;
	}

