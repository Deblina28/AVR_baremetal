#include <stdint.h>
//#include "utils.h"

#define BAUD 115200.0
#define BAUD_REG (RoundOff((1000000.0/BAUD) - 1.0))
//#define BAUD_REG 8

volatile uint8_t* loc_UDR0 = (volatile uint8_t*)0xC6;
volatile uint8_t* loc_UBRR0H = (volatile uint8_t*)0xC5;
volatile uint8_t* loc_UBRR0L = (volatile uint8_t*)0xC4;
volatile uint8_t* loc_UCSR0C = (volatile uint8_t*)0xC2;
volatile uint8_t* loc_UCSR0B = (volatile uint8_t*)0xC1;
volatile uint8_t* loc_UCSR0A = (volatile uint8_t*)0xC0;

void UART_begin();
void TX_Char(char);
//void TX_String(char [], int);
void UART_print(char []);
char RX_Char();
int Data_Available();
void Print_int(uint16_t);

void UART_begin()
{
    *loc_UBRR0H = HB(BAUD_REG);
    *loc_UBRR0L = LB(BAUD_REG); 
    SetBit(loc_UCSR0B, 3);
    SetBit(loc_UCSR0B, 4);
}

void TX_Char(char t)
{   
    while(CheckBit(loc_UCSR0A, 5) == 0)
    {}
    *loc_UDR0 = (uint8_t)t;
}

void TX_String(char arr[], int x)
{
    for(int i=0; i<x; i++)
    {
        TX_Char(arr[i]);
    }
}

void UART_print(char string[])
{
    for(int i=0; string[i]!='\0'; i++)
    {
        TX_Char(string[i]);
    }
}

char RX_Char()
{
    while(CheckBit(loc_UCSR0A, 7)== 0)
    {}
    return *loc_UDR0;
}

int Data_Available()
{
    return CheckBit(loc_UCSR0A, 7);
}

/* 
       //UART_print(str);
        //UART_print("hello\n");
        //_delay_ms(1000);
        
        if(Data_Available() == 1)
        {
            char z = RX_Char();
            TX_Char(z);
            
            if(z == 'n')
            {
                PinWrite(4, 1);            
            }

            else if(z == 'f')
            {
                PinWrite(4, 0);
            }
        }
 */