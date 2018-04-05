#include <mbed.h>
class motor_pwm{
private:
    PwmOut* pwm;
    DigitalOut* enable_pin;
    DigitalOut* direct_pin;
public:
    motor_pwm(PwmOut*, DigitalOut*, DigitalOut*);
    void setup_pwm(int,int);
    void setup_direction(int encoder, int target);
    void enable();
    void disable();
};
