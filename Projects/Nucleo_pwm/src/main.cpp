#include "mbed.h"

Serial pc(USBTX, USBRX);

PwmOut mypwm(PWM_OUT);

DigitalOut myled(LED1);

int main() {

    pc.baud(115200);
    mypwm.period_us(500);
    //mypwm.pulsewidth_us(250);
    mypwm.write(0.5);
    printf("pwm set to %.2f %%\n", mypwm.read() * 100);

    while(1) {
        myled = !myled;
        wait(1);
    }
}
