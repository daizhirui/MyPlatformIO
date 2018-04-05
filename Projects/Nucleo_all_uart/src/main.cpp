#include <mbed.h>

Serial uart1(PA_9,PA_10);
Serial uart2(PA_2,PA_3);
Serial uart6(PA_11,PA_12);


int main() {

    // put your setup code here, to run once:
    uart1.baud(115200);
    uart2.baud(19200);
    uart6.baud(9600);
    while(1) {
        // put your main code here, to run repeatedly:
        uart1.puts("This is message from uart1, baudrate 115200\n");
        uart2.puts("This is message from uart2, baudrate 19200\n");
        uart6.puts("This is message from uart6, baudrate 9600\n");
    }
}
