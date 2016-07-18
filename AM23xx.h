//
// AM23xx - an Arduino library for aosong humidity and temperature sensors.
//
//
#include "Wire.h"

class AM23xx
{
    public:
	    AM23xx();
        int read();
        int temperature;
        int humidity;
	private:
        int isCorrect();
};
