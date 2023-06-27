#include <stdint.h>


void SetBit(volatile uint8_t*, uint8_t);
void ClearBit(volatile uint8_t*, uint8_t);
void ToggleBit(volatile uint8_t*, uint8_t);
uint8_t CheckBit(volatile uint8_t*, uint8_t);
uint8_t LB(uint16_t);
uint8_t HB(uint16_t);
int RoundOff(float);


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

uint8_t LB(uint16_t a)
{
	return (a & 0xFF);
}

uint8_t HB(uint16_t a)
{
	return ((a >> 8) & 0xFF);
}

int RoundOff(float x)
{
    int y = (int)x;

    if(x-y >= 0.5)
    {
        return (int)x+1;
    }
    else 
    {
        return (int)x;
    }
}