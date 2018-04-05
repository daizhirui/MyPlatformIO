#include <mbed.h>
#include "Jy61p.h"

#define UART6TX PA_11
#define UART6RX PA_12

DigitalOut  myled(LED1);

Serial pc(USBTX, USBRX);
Serial uart(UART6TX, UART6RX);

Timer  myTimer;
int main() {

    // put your setup code here, to run once:
    myled = 0;
    Jy61p   jy61p(&uart);
    wait(1);
    myled = 1;
    int start;
    while(1) {
        // put your main code here, to run repeatedly:
        start = myTimer.read_us();
        jy61p.update();
        pc.printf("Acceleration = (%f, %f, %f)\n",jy61p.acce.x,jy61p.acce.y,jy61p.acce.z);
        pc.printf("AngularVelocity = (%f, %f, %f)\n",jy61p.angleV.x,jy61p.angleV.y,jy61p.angleV.z);
        pc.printf("Angle = (%f, %f, %f)\n",jy61p.angle.x,jy61p.angle.y,jy61p.angle.z);
        pc.printf("Spend %d us\n\n",myTimer.read_us() - start);
    }
}
