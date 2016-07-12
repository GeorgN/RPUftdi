/*
io macros for AVR chips 
*/

//input 
#define a0_input DDRA &= ~(1<<PA0)
#define a1_input DDRA &= ~(1<<PA1)
#define a2_input DDRA &= ~(1<<PA2)
#define a3_input DDRA &= ~(1<<PA3)
#define a4_input DDRA &= ~(1<<PA4)
#define a5_input DDRA &= ~(1<<PA5)
#define a6_input DDRA &= ~(1<<PA6)
#define a7_input DDRA &= ~(1<<PA7)

#define b0_input DDRB &= ~(1<<PB0)
#define b1_input DDRB &= ~(1<<PB1)
#define b2_input DDRB &= ~(1<<PB2)
#define b3_input DDRB &= ~(1<<PB3)
#define b4_input DDRB &= ~(1<<PB4)
#define b5_input DDRB &= ~(1<<PB5)
#define b6_input DDRB &= ~(1<<PB6)
#define b7_input DDRB &= ~(1<<PB7)

#define c0_input DDRC &= ~(1<<PC0)
#define c1_input DDRC &= ~(1<<PC1)
#define c2_input DDRC &= ~(1<<PC2)
#define c3_input DDRC &= ~(1<<PC3)
#define c4_input DDRC &= ~(1<<PC4)
#define c5_input DDRC &= ~(1<<PC5)
#define c6_input DDRC &= ~(1<<PC6)
#define c7_input DDRC &= ~(1<<PC7)

#define d0_input DDRD &= ~(1<<PD0)
#define d1_input DDRD &= ~(1<<PD1)
#define d2_input DDRD &= ~(1<<PD2)
#define d3_input DDRD &= ~(1<<PD3)
#define d4_input DDRD &= ~(1<<PD4)
#define d5_input DDRD &= ~(1<<PD5)
#define d6_input DDRD &= ~(1<<PD6)
#define d7_input DDRD &= ~(1<<PD7)

#define e0_input DDRE &= ~(1<<PE0)
#define e1_input DDRE &= ~(1<<PE1)
#define e2_input DDRE &= ~(1<<PE2)
#define e3_input DDRE &= ~(1<<PE3)
#define e4_input DDRE &= ~(1<<PE4)
#define e5_input DDRE &= ~(1<<PE5)
#define e6_input DDRE &= ~(1<<PE6)
#define e7_input DDRE &= ~(1<<PE7)

//output
#define a0_output DDRA|= (1<<PA0)
#define a1_output DDRA|= (1<<PA1)
#define a2_output DDRA|= (1<<PA2)
#define a3_output DDRA|= (1<<PA3)
#define a4_output DDRA|= (1<<PA4)
#define a5_output DDRA|= (1<<PA5)
#define a6_output DDRA|= (1<<PA6)
#define a7_output DDRA|= (1<<PA7)

#define b0_output DDRB|= (1<<PB0)
#define b1_output DDRB|= (1<<PB1)
#define b2_output DDRB|= (1<<PB2)
#define b3_output DDRB|= (1<<PB3)
#define b4_output DDRB|= (1<<PB4)
#define b5_output DDRB|= (1<<PB5)
#define b6_output DDRB|= (1<<PB6)
#define b7_output DDRB|= (1<<PB7)

#define c0_output DDRC|= (1<<PC0)
#define c1_output DDRC|= (1<<PC1)
#define c2_output DDRC|= (1<<PC2)
#define c3_output DDRC|= (1<<PC3)
#define c4_output DDRC|= (1<<PC4)
#define c5_output DDRC|= (1<<PC5)
#define c6_output DDRC|= (1<<PC6)
#define c7_output DDRC|= (1<<PC7)

#define d0_output DDRD|= (1<<PD0)
#define d1_output DDRD|= (1<<PD1)
#define d2_output DDRD|= (1<<PD2)
#define d3_output DDRD|= (1<<PD3)
#define d4_output DDRD|= (1<<PD4)
#define d5_output DDRD|= (1<<PD5)
#define d6_output DDRD|= (1<<PD6)
#define d7_output DDRD|= (1<<PD7)

#define e0_output DDRE|= (1<<PE0)
#define e1_output DDRE|= (1<<PE1)
#define e2_output DDRE|= (1<<PE2)
#define e3_output DDRE|= (1<<PE3)
#define e4_output DDRE|= (1<<PE4)
#define e5_output DDRE|= (1<<PE5)
#define e6_output DDRE|= (1<<PE6)
#define e7_output DDRE|= (1<<PE7)

//high if output (or pullup if set as an input)
#define a0_high PORTA|= (1<<PA0)
#define a1_high PORTA|= (1<<PA1)
#define a2_high PORTA|= (1<<PA2)
#define a3_high PORTA|= (1<<PA3)
#define a4_high PORTA|= (1<<PA4)
#define a5_high PORTA|= (1<<PA5)
#define a6_high PORTA|= (1<<PA6)
#define a7_high PORTA|= (1<<PA7)

#define b0_high PORTB|= (1<<PB0)
#define b1_high PORTB|= (1<<PB1)
#define b2_high PORTB|= (1<<PB2)
#define b3_high PORTB|= (1<<PB3)
#define b4_high PORTB|= (1<<PB4)
#define b5_high PORTB|= (1<<PB5)
#define b6_high PORTB|= (1<<PB6)
#define b7_high PORTB|= (1<<PB7)

#define c0_high PORTC|= (1<<PC0)
#define c1_high PORTC|= (1<<PC1)
#define c2_high PORTC|= (1<<PC2)
#define c3_high PORTC|= (1<<PC3)
#define c4_high PORTC|= (1<<PC4)
#define c5_high PORTC|= (1<<PC5)
#define c6_high PORTC|= (1<<PC6)
#define c7_high PORTC|= (1<<PC7)

#define d0_high PORTD|= (1<<PD0)
#define d1_high PORTD|= (1<<PD1)
#define d2_high PORTD|= (1<<PD2)
#define d3_high PORTD|= (1<<PD3)
#define d4_high PORTD|= (1<<PD4)
#define d5_high PORTD|= (1<<PD5)
#define d6_high PORTD|= (1<<PD6)
#define d7_high PORTD|= (1<<PD7)

#define e0_high PORTE|= (1<<PE0)
#define e1_high PORTE|= (1<<PE1)
#define e2_high PORTE|= (1<<PE2)
#define e3_high PORTE|= (1<<PE3)
#define e4_high PORTE|= (1<<PE4)
#define e5_high PORTE|= (1<<PE5)
#define e6_high PORTE|= (1<<PE6)
#define e7_high PORTE|= (1<<PE7)

//low
#define a0_low PORTA &= ~(1<<PA0)
#define a1_low PORTA &= ~(1<<PA1)
#define a2_low PORTA &= ~(1<<PA2)
#define a3_low PORTA &= ~(1<<PA3)
#define a4_low PORTA &= ~(1<<PA4)
#define a5_low PORTA &= ~(1<<PA5)
#define a6_low PORTA &= ~(1<<PA6)
#define a7_low PORTA &= ~(1<<PA7)

#define b0_low PORTB &= ~(1<<PB0)
#define b1_low PORTB &= ~(1<<PB1)
#define b2_low PORTB &= ~(1<<PB2)
#define b3_low PORTB &= ~(1<<PB3)
#define b4_low PORTB &= ~(1<<PB4)
#define b5_low PORTB &= ~(1<<PB5)
#define b6_low PORTB &= ~(1<<PB6)
#define b7_low PORTB &= ~(1<<PB7)

#define c0_low PORTC &= ~(1<<PC0)
#define c1_low PORTC &= ~(1<<PC1)
#define c2_low PORTC &= ~(1<<PC2)
#define c3_low PORTC &= ~(1<<PC3)
#define c4_low PORTC &= ~(1<<PC4)
#define c5_low PORTC &= ~(1<<PC5)
#define c6_low PORTC &= ~(1<<PC6)
#define c7_low PORTC &= ~(1<<PC7)

#define d0_low PORTD &= ~(1<<PD0)
#define d1_low PORTD &= ~(1<<PD1)
#define d2_low PORTD &= ~(1<<PD2)
#define d3_low PORTD &= ~(1<<PD3)
#define d4_low PORTD &= ~(1<<PD4)
#define d5_low PORTD &= ~(1<<PD5)
#define d6_low PORTD &= ~(1<<PD6)
#define d7_low PORTD &= ~(1<<PD7)

#define e0_low PORTE &= ~(1<<PE0)
#define e1_low PORTE &= ~(1<<PE1)
#define e2_low PORTE &= ~(1<<PE2)
#define e3_low PORTE &= ~(1<<PE3)
#define e4_low PORTE &= ~(1<<PE4)
#define e5_low PORTE &= ~(1<<PE5)
#define e6_low PORTE &= ~(1<<PE6)
#define e7_low PORTE &= ~(1<<PE7)

//read
#define a0_read PINA & (1<<PA0)
#define a1_read PINA & (1<<PA1)
#define a2_read PINA & (1<<PA2)
#define a3_read PINA & (1<<PA3)
#define a4_read PINA & (1<<PA4)
#define a5_read PINA & (1<<PA5)
#define a6_read PINA & (1<<PA6)
#define a7_read PINA & (1<<PA7)

#define b0_read PINB & (1<<PB0)
#define b1_read PINB & (1<<PB1)
#define b2_read PINB & (1<<PB2)
#define b3_read PINB & (1<<PB3)
#define b4_read PINB & (1<<PB4)
#define b5_read PINB & (1<<PB5)
#define b6_read PINB & (1<<PB6)
#define b7_read PINB & (1<<PB7)

#define c0_read PINC & (1<<PC0)
#define c1_read PINC & (1<<PC1)
#define c2_read PINC & (1<<PC2)
#define c3_read PINC & (1<<PC3)
#define c4_read PINC & (1<<PC4)
#define c5_read PINC & (1<<PC5)
#define c6_read PINC & (1<<PC6)
#define c7_read PINC & (1<<PC7)

#define d0_read PIND & (1<<PD0)
#define d1_read PIND & (1<<PD1)
#define d2_read PIND & (1<<PD2)
#define d3_read PIND & (1<<PD3)
#define d4_read PIND & (1<<PD4)
#define d5_read PIND & (1<<PD5)
#define d6_read PIND & (1<<PD6)
#define d7_read PIND & (1<<PD7)

#define e0_read PINE & (1<<PE0)
#define e1_read PINE & (1<<PE1)
#define e2_read PINE & (1<<PE2)
#define e3_read PINE & (1<<PE3)
#define e4_read PINE & (1<<PE4)
#define e5_read PINE & (1<<PE5)
#define e6_read PINE & (1<<PE6)
#define e7_read PINE & (1<<PE7)