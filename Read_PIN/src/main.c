//Read pin D6 and light up LED at D4

#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>

int main()
{
//setup content
volatile uint8_t* loc_DDRD = (volatile uint8_t*)0x2A;
volatile uint8_t* loc_PORTD = (volatile uint8_t*)0x2B;
volatile uint8_t* loc_PIND = (volatile uint8_t*)0x29;
volatile uint8_t* loc_PORTB = (volatile uint8_t*)0x25;
volatile uint8_t* loc_DDRB = (volatile uint8_t*)0x24;

*loc_DDRD = *loc_DDRD | 0b00010000;
*loc_DDRB |= 0b00100000;

uint8_t a = 0b01000000;

    for(;;)
    {
        //loop content        
        *loc_PORTB = 0b00100000;

        if((*loc_PIND & a) == a)
            {
                *loc_PORTD = *loc_PORTD | 0b00010000;
                //*loc_PORTD |= 0b00010000;     Same as above line

            }
        else
            {
                *loc_PORTD = *loc_PORTD & 0b11101111;
                //*loc_PORTD = *loc_PORTD & (~(1<<4));      Same as above line
            }
    }

    return 0;
}