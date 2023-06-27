//BLINK LED

#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>

int main()
{
//setup content
uint8_t* loc_DDRB = (uint8_t*)0x24;
uint8_t* loc_PORTB = (uint8_t*)0x25;
uint8_t* loc_DDRD = (uint8_t*)0x2A;
uint8_t* loc_PORTD = (uint8_t*)0x2B;


*loc_DDRB = 0b00100000;
*loc_DDRD = 0b00010000;

    for(;;)
    {
        //loop content
        *loc_PORTB = 0b00100000;
        *loc_PORTD = 0b00010000;
        _delay_ms(1000);
        *loc_PORTB = 0b00000000;
        *loc_PORTD = 0b00000000;                
        _delay_ms(1000);
    }

    return 0;
}