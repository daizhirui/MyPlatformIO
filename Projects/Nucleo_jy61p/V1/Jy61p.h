#include "mbed.h"

#define ACC_PACK    0x51
#define ANV_PACK    0x52
#define ANG_PACK    0x53

typedef struct
{
    double  x;
    double  y;
    double  z;
} Acceleration;

typedef struct
{
    double  x;
    double  y;
    double  z;
} AngularVelocity;

typedef struct
{
    double x;
    double y;
    double z;
} Angle;

class Jy61p
{
private:
    Serial*         uartPtr;
    unsigned char   buffer[21];
public:
    Acceleration    acce;
    AngularVelocity angleV;
    Angle           angle;
    Jy61p(Serial*);
    void update();
};
