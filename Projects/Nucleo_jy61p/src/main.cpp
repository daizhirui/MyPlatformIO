#include <mbed.h>
#include "Jy61p.h"
#define UART1TX PA_9
#define UART1RX PA_10

Serial pc(USBTX, USBRX);
Serial uart(UART1TX, UART1RX);

DigitalOut  myled(LED1);
/*
int main()
{
    myled = 0;
    pc.baud(115200);
    uart.baud(115200);
    myled = 1;
    while(true)
        pc.putc(uart.getc());
}
*/

int main()
{
    myled = 0;
    pc.baud(115200);
    uart.baud(115200);
    Jy61p   jy61p(&uart);
    myled = 1;
    while(1)
    {
        jy61p.update(&pc);
        pc.printf("   Acceleration = (%.3f, %.3f, %.3f)\n",(float)jy61p.acce.x/32768*16,(float)jy61p.acce.y/32768*16,(float)jy61p.acce.z/32768*16);
        pc.printf("AngularVelocity = (%.3f, %.3f, %.3f)\n",(float)jy61p.angleV.x/32768*2000,(float)jy61p.angleV.y/32768*2000,(float)jy61p.angleV.z/32768*2000);
        pc.printf("          Angle = (%.3f, %.3f, %.3f)\n\n",(float)jy61p.angle.x/32768*180,(float)jy61p.angle.y/32768*180,(float)jy61p.angle.z/32768*180);
        wait_ms(10);
    }
}
