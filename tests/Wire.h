
#ifndef WireMock_h
#define WireMock_h

#include <inttypes.h>


class WireMock
{
  private:
    static uint8_t rxBuffer[];
    static uint8_t rxBufferIndex;
    static uint8_t rxBufferLength;

    static uint8_t txAddress;
    static uint8_t txBuffer[];
    static uint8_t txBufferIndex;
    static uint8_t txBufferLength;

    static uint8_t transmitting;
    static void (*user_onRequest)(void);
    static void (*user_onReceive)(int);
    static void onRequestService(void);
    static void onReceiveService(uint8_t*, int);
  public:
    WireMock();
    void begin(int sda, int scl);
    void begin();
    void begin(uint8_t);
    void begin(int);
    void setClock(uint32_t);
    void setClockStretchLimit(uint32_t);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    uint8_t endTransmission(void);
    uint8_t endTransmission(uint8_t);
    uint8_t requestFrom(uint8_t address, uint8_t size, bool sendStop);
	uint8_t status();

    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    uint8_t requestFrom(int, int, int);
    
    virtual uint8_t write(uint8_t);
    virtual uint8_t write(const uint8_t *, uint8_t);
    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    void onReceive( void (*)(int) );
    void onRequest( void (*)(void) );

    inline uint8_t write(unsigned long n) { return write((uint8_t)n); }
    inline uint8_t write(long n) { return write((uint8_t)n); }
    inline uint8_t write(unsigned int n) { return write((uint8_t)n); }
    inline uint8_t write(int n) { return write((uint8_t)n); }
};

extern WireMock Wire;

#endif

