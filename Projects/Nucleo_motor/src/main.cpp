#include <mbed.h>
#include "motor_pwm.h"

PwmOut     motor_pwm_pin(PB_3);
DigitalOut motor_enable_pin(PB_4);
DigitalOut motor_direction_pin(PB_5);

/*
int main() {

    // put your setup code here, to run once:
    motor_pwm   motor(&motor_pwm_pin, &motor_enable_pin, &motor_enable_pin);
    motor.setup_pwm(1, 200);
    motor.setup_direction(100, 200);    // positive direction
    motor.enable();
    //motor_pwm_pin.pulsewidth_us(1000000/200);
    //motor_pwm_pin.write(50/100.0);
    while(1) {
        // put your main code here, to run repeatedly:
    }
}
*/

int main() {

    
}
