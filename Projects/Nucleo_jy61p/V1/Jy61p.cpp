#include "Jy61p.h"
Jy61p::Jy61p(Serial* serialPtr)
{
    uartPtr = serialPtr;
    uartPtr->baud(115200);
    uartPtr->putc(0xFF);
    uartPtr->putc(0xAA);
    uartPtr->putc(0x52);
    uartPtr->putc(0xFF);
    uartPtr->putc(0xAA);
    uartPtr->putc(0x63);
}

void Jy61p::update()
{
    unsigned char *Ptr;
    unsigned char sum;
    unsigned char sum_get;
    unsigned char update = 0;
    unsigned char i = 0;
    // update bit0 ---> Acceleration update bit
    // update bit1 ---> AngularVelocity update bit
    // update bit2 ---> Angle update bit
    while(((update&0x1)==0)&&((update&0x2)==0)&&((update&0x4)==0))
    {
        while (uartPtr->getc() != 0x55) {}
        switch (uartPtr->getc())
        {
            case ACC_PACK:
            {
                Ptr = buffer;                                   // set Ptr point to buffer[0]
                sum = 0x55 + 0x51;                              // initialize sum
                for(i=0;i<7;i++)                                // get the data
                {
                    Ptr[i]=uartPtr->getc();
                    sum += Ptr[i];
                }
                sum_get = uartPtr->getc();
                if(sum_get == sum)                              // calculate if sum check passed
                {
                    acce.x = ((Ptr[1]<<8)|Ptr[0])*16/32768.0;
                    acce.y = ((Ptr[3]<<8)|Ptr[2])*16/32768.0;
                    acce.z = ((Ptr[5]<<8)|Ptr[4])*16/32768.0;
                    update |= 0x1;
                }
                else
                {
                    printf("sum wrong!\n");
                    printf("frame: %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd\n",0x55, 0x51, Ptr[0], Ptr[1], Ptr[2], Ptr[3], Ptr[4], Ptr[5], Ptr[6], sum_get);
                    printf("sum = %xd\n\n",sum);
                    wait(1);
                }
                break;
            }
            case ANV_PACK:
            {
                Ptr = buffer + 7;
                sum = 0x55 + 0x52;                              // initialize sum
                for(i=0;i<7;i++)                                // get the data
                {
                    Ptr[i]=uartPtr->getc();
                    sum += Ptr[i];
                }
                sum_get = uartPtr->getc();
                if(sum_get == sum)                              // calculate if sum check passed
                {
                    angleV.x = ((Ptr[1]<<8)|Ptr[0])*2000/32768.0;
                    angleV.y = ((Ptr[3]<<8)|Ptr[2])*2000/32768.0;
                    angleV.z = ((Ptr[5]<<8)|Ptr[4])*2000/32768.0;
                    update |= 0x2;
                }
                else
                {
                    printf("sum wrong!\n");
                    printf("frame: %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd\n",0x55, 0x52, Ptr[0], Ptr[1], Ptr[2], Ptr[3], Ptr[4], Ptr[5], Ptr[6], sum_get);
                    printf("sum = %xd\n\n",sum);
                    wait(1);
                }
                break;
            }
            case ANG_PACK:
            {
                Ptr = buffer + 14;
                sum = 0x55 + 0x53;                              // initialize sum
                for(i=0;i<7;i++)                                // get the data
                {
                    Ptr[i]=uartPtr->getc();
                    sum += Ptr[i];
                }
                sum_get = uartPtr->getc();
                if(sum_get == sum)                              // calculate if sum check passed
                {
                    angle.x = ((Ptr[1]<<8)|Ptr[0])*180/32768.0;
                    angle.y = ((Ptr[3]<<8)|Ptr[2])*180/32768.0;
                    angle.z = ((Ptr[5]<<8)|Ptr[4])*180/32768.0;
                    update |= 0x4;
                }
                else
                {
                    printf("sum wrong!\n");
                    printf("frame: %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd, %xd\n",0x55, 0x53, Ptr[0], Ptr[1], Ptr[2], Ptr[3], Ptr[4], Ptr[5], Ptr[6], sum_get);
                    printf("sum = %xd\n\n",sum);
                    wait(1);
                }
                break;
            }
        }
    }
}
