#include <stdint.h>
#include "utils.h"

volatile uint8_t* loc_DDRD = (volatile uint8_t*)0x2A;
volatile uint8_t* loc_PORTD = (volatile uint8_t*)0x2B;
volatile uint8_t* loc_PIND = (volatile uint8_t*)0x29;
volatile uint8_t* loc_PORTB = (volatile uint8_t*)0x25;
volatile uint8_t* loc_DDRB = (volatile uint8_t*)0x24;
//volatile uint8_t* loc_PINB = (volatile uint8_t*)0x;

void PinWrite(int, int);
void GPIO_PinMode(int, int);
void PinToggle(int);

void GPIO_PinMode(int x, int y)
{
    if(x<8 && y==1)
    {
        SetBit(loc_DDRD, x);
    }
    
    else if(x>7 && x<14 && y==1)
    {
        SetBit(loc_DDRB, (x-8));
    }

    else if(x<8 && y==0)
    {
        ClearBit(loc_DDRD, x);
    }
    
    else if(x>7 && x<14 && y==0)
    {
        ClearBit(loc_DDRB, (x-8));
    }
}

void PinWrite(int x, int y)
{
    if(x<8 && y==1)
    {
        SetBit(loc_PORTD, x);
    }
    
    else if(x>7 && x<14 && y==1)
    {
        SetBit(loc_PORTB, (x-8));
    }

    else if(x<8 && y==0)
    {
        ClearBit(loc_PORTD, x);
    }
    
    else if(x>7 && x<14 && y==0)
    {
        ClearBit(loc_PORTB, (x-8));
    }
}

void PinToggle(int x)
{
    if(x<8)
    {
        ToggleBit(loc_PORTD, x);
    }
    
    else if(x>7 && x<14)
    {
        ToggleBit(loc_PORTB, (x-8));
    }
}