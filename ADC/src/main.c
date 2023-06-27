//UART communication protocol

//#include "utils.h"
#include "gpio.h"
#include "uart.h"
#include <util/delay.h>
#include <avr/io.h>
#include <stdio.h>
#include "adc.h"

int main()
{
//setup content
UART_begin();
ADC_init();
GPIO_PinMode(4, 1);
GPIO_PinMode(13, 1);

char buf[64];

//char str[] = "hello\n";

    for(;;)
    {
        //loop content
        PinToggle(4);
        PinToggle(13);

        uint16_t val = ADC_read(0);
        uint16_t val2 = ADC_read(2);
        sprintf(buf, "ADC0: %d, ADC2: %d\n", val, val2);
        UART_print(buf);

        _delay_ms(100);
        //Print_int(val);
    }
    return 0;
}