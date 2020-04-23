#pragma once
//
//    FILE: DS18B20.h
//  AUTHOR: Rob.Tillaart@gmail.com
// VERSION: 0.1.4
//    DATE: 2017-07-25
//
// PUPROSE: library for DS18B20 temperature sensor with minimal footprint
//

//
//  BOTTOM VIEW
//
//          PIN  MEANING
//   /---+
//  /  o |  1    GND
//  |  o |  2    DATA
//  \  o |  3    VCC
//   \---+
//

#define DS18B20_LIB_VERSION "0.1.4"

#include <OneWire.h>

// Error Code
#define DEVICE_DISCONNECTED -127

typedef uint8_t DeviceAddress[8];
typedef uint8_t ScratchPad[9];

class DS18B20
{
public:
  explicit  DS18B20(OneWire *);
  bool      begin(void);
  void      setResolution(uint8_t);
  void      requestTemperatures(void);
  float     getTempC(void);
  bool      isConversionComplete(void);
  bool      getAddress(uint8_t*);

private:
  void          readScratchPad(uint8_t *, uint8_t);
  DeviceAddress _deviceAddress;
  OneWire*      _wire;
  bool          _configured;
};

//  -- END OF FILE --
