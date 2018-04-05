#include "mbed.h"

/*
SPI 1
SPI_MOSI = PA_7
SPI_MISO = PA_6
SPI_SCK  = PA_5
SPI_CS   = PB_6
SPI_NSS  = PA_15

SPI 2
SPI2_NSS  = PB_9\PB_12
SPI2_SCK  = PB_10\PB_13
SPI2_MISO = PC_2\PB_14
SPI2_MOSI = PC_3\PB_15

SPI 3
SPI3_SCK  = PC_10
SPI3_MOSI = PC_12
SPI3_MISO = PC_11
*/

SPI device(SPI_MOSI, SPI_MISO, SPI_SCK);
DigitalOut cs(SPI_CS);

int main() {
    int i = 0;
    while(1) {
        cs = 0;
        printf("Sending...\n");
        //device.write(0x55);
        device.write(i++);
        //device.write(0xE0);
        cs = 1;
        wait_ms(20);
    }
}
