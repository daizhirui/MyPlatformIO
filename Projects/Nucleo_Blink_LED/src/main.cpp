#include "mbed.h"

DigitalOut myled(LED1);

#define INTERVAL    0.5
int main() {
    while(1) {
        myled = 1; // LED is ON
        wait(INTERVAL); // 1 sec
        myled = 0; // LED is OFF
        wait(INTERVAL); // 1 sec
    }
}
