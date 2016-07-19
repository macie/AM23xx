#include "../AM23xx.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "fakeit.hpp"


SCENARIO("Reading from sensor")
{
    GIVEN("An AM23xx sensor")
    {
        Mock<Arduino> ArduinoMock;
        Fake(Method(WireMock, delayMicroseconds));

        Mock<Wire> WireMock;
        Fake(Method(WireMock, beginTransmission));
        Fake(Method(WireMock, endTransmission));
        Fake(Method(WireMock, write));
        Fake(Method(WireMock, requestFrom));

        WHEN("we get correct measurement")
        {
            When(Method(WireMock, read)).Return(1);
            int isSuccess = AM23xx.read();

            THEN("we should be informed")
            {
                REQUIRE(isSuccess == 1);
            }
        }

        WHEN("we have problem while reading")
        {
            When(Method(WireMock, read)).Return(0);
            int isSuccess = AM23xx.read();

            THEN("we should be informed")
            {
                REQUIRE(isSuccess == 0);
            }
        }
    }
}
