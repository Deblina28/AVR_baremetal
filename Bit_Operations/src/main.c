//Set bit and clear bit and toggle bit function

#include <stdint.h>
#include <util/delay.h>
#include <avr/io.h>

void SetBit(volatile uint8_t*, uint8_t);
void ClearBit(volatile uint8_t*, uint8_t);
void ToggleBit(volatile uint8_t*, uint8_t);
uint8_t CheckBit(volatile uint8_t*, uint8_t);

int main()
{
//setup content
volatile uint8_t* loc_DDRD = (volatile uint8_t*)0x2A;
volatile uint8_t* loc_PORTD = (volatile uint8_t*)0x2B;
volatile uint8_t* loc_PIND = (volatile uint8_t*)0x29;
volatile uint8_t* loc_PORTB = (volatile uint8_t*)0x25;
volatile uint8_t* loc_DDRB = (volatile uint8_t*)0x24;

SetBit(loc_DDRD, 4);
SetBit(loc_DDRB, 5);

    for(;;)
    {
        //loop content
        ToggleBit(loc_PORTB, 5);
        _delay_ms(100);

        uint8_t x = CheckBit(loc_PIND, 6);
        
        if(x==1)
            {
                SetBit(loc_PORTD, 4);
            }
        else
            {
                ClearBit(loc_PORTD, 4);
            }
    }

    return 0;
}

void SetBit(volatile uint8_t* loc, uint8_t pos) 
{
    *loc |= (1<<pos);
}

void ClearBit(volatile uint8_t* loc, uint8_t pos)
{
    *loc = *loc & (~(1<<pos));
}

void ToggleBit(volatile uint8_t* loc, uint8_t pos)
{
    *loc = *loc^(1<<pos);
}

uint8_t CheckBit(volatile uint8_t* loc, uint8_t pos)
{
    uint8_t x = (1<<pos);

    if((*loc & x) == x)
        return 1;

    else
        return 0;   
}