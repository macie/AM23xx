//
// AM23xx - an Arduino library for Aosong humidity and temperature sensors.
//
//

#define AM23XX_SUCCESS       1
#define AM23XX_FAIL          0
#define AM23XX_BAD_CHECKSUM -1


class AM23xx
{
    public:
	    AM23xx() {};
        int8_t read();
        double humidity;
        double temperature;

	private:
		uint8_t measurements[5];
        bool isCorrect();
};
