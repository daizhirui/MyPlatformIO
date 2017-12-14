#include "mbed.h"

#define UART6TX PA_11
#define UART6RX PA_12

Serial pc(USBTX, USBRX);
Serial uart(UART6TX, UART6RX);

DigitalOut pc_activity(LED1);
DigitalOut uart_activity(LED2);
# LED1 and LED2 are both PA_5.

int main() {
    while(1) {
        if(pc.readable()) {
            uart.putc(pc.getc());
            pc_activity = !pc_activity;
        }
        if(uart.readable()) {
            pc.putc(uart.getc());
            uart_activity = !uart_activity;
        }
    }
}
