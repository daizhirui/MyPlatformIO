#include "mbed.h"

//------------------------------------
// Hyperterminal configuration
// 9600 bauds, 8-bit data, no parity
//------------------------------------

DigitalOut led(LED1);

int main()
{
    int i = 1;

    printf("Hello World !\n");

    while(1) {
        wait(1); // 1 second
        led = !led; // Toggle LED
        printf("This program runs since %d seconds.\n", i++);
    }
}