#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(USBTX, USBRX);

int main() {
    char buffer[128];

    while(1)
    {
        pc.gets(buffer, 4);
        pc.printf("I got '%s'\n", buffer);
    }
}
