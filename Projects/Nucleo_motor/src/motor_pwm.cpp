#include "motor_pwm.h"
motor_pwm::motor_pwm(PwmOut* ptr, DigitalOut* enablepin, DigitalOut* directpin){
    pwm = ptr;
    enable_pin = enablepin;
    direct_pin = directpin;
    this->disable();
}

void motor_pwm::setup_pwm(int duty, int freq){
    int T=1000000/freq;
    pwm->period_us(T);
    pwm->pulsewidth_us(T*duty/100.0);
    //pwm->write(duty/100.0);
}

void motor_pwm::setup_direction(int encoder, int target){
    if(encoder > target)
        *direct_pin = 0;
    else
        *direct_pin = 1;
}

void motor_pwm::enable(){
    *enable_pin = 0;
}

void motor_pwm::disable(){
    *enable_pin = 1;
}
