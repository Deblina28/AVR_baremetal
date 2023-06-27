#include <stdint.h>

volatile uint8_t* loc_ADCSRA = (volatile uint8_t*)0x7A;
volatile uint8_t* loc_ADCSRB = (volatile uint8_t*)0x7B;
volatile uint8_t* loc_ADMUX = (volatile uint8_t*)0x7C;
volatile uint8_t* loc_ADCH = (volatile uint8_t*)0x79;
volatile uint8_t* loc_ADCL = (volatile uint8_t*)0x78;

void ADC_init();
uint16_t ADC_read(uint8_t);

void ADC_init()
{
//Setting prescaler (clock)
SetBit(loc_ADCSRA, 0);
SetBit(loc_ADCSRA, 1);
SetBit(loc_ADCSRA, 2);

//ADMUX Voltage reference set
SetBit(loc_ADMUX, 6);

//ADC Enable
SetBit(loc_ADCSRA, 7);

//ADC Start Conversion
SetBit(loc_ADCSRA, 6);
}

uint16_t ADC_read(uint8_t x)
{
    if(x<8)
    {   
        *loc_ADMUX = *loc_ADMUX & 0xF0;

        *loc_ADMUX = *loc_ADMUX|x;
        
        //ADC Start Conversion
        SetBit(loc_ADCSRA, 6);

        while(CheckBit(loc_ADCSRA, 6)==1)
        {}
        uint16_t a;
        a = (uint16_t)*loc_ADCL; 
        a = a|(uint16_t)*loc_ADCH << 8;

        return a;
    }
}

/*
uint16_t ADC_read(uint8_t w, uint8_t x, uint8_t y, uint8_t z)
{
    if(w==1)
    SetBit(loc_ADMUX, 3);
    else if(w==0)
    ClearBit(loc_ADMUX, 3);

    if(x==1)
    SetBit(loc_ADMUX, 2);
    else if(x==0)
    ClearBit(loc_ADMUX, 2);

    if(y==1)
    SetBit(loc_ADMUX, 1);
    else if(y==0)
    ClearBit(loc_ADMUX, 1);

    if(z==1)
    SetBit(loc_ADMUX, 0);
    else if(z==0)
    ClearBit(loc_ADMUX, 0);

    
    //ADC Start Conversion
    SetBit(loc_ADCSRA, 6);

    while(CheckBit(loc_ADCSRA, 6)==1)
    {}
    uint16_t a;
    a = (uint16_t)*loc_ADCL; 
    a = a|(uint16_t)*loc_ADCH << 8;

    return a;
}

void Print_int(uint16_t a)
{
    if(a == 0)
    {
        TX_Char('0');
        TX_Char('\n');
        return;
    }

    uint16_t c=0;
    uint8_t b=0, y=0;

    while(a>0)
    {
        b = a%10;
        c = c*10 + b;
        a=a/10;
    }

    for(uint16_t i = c; i>0; )
    {   
        y = i%10;
        TX_Char((char)(y+48)); 
        i = i/10;
    }

    TX_Char('\n');
}
*/