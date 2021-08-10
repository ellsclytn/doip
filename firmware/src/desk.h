#include "esphome.h"

class DeskHeightSensor : public PollingComponent, public UARTDevice, public Sensor {
public:
  DeskHeightSensor(UARTComponent *parent) : UARTDevice(parent) {}

  int lastPublished;
  int height;
  int highByte;
  int byteIndex = 0;

  float get_setup_priority() const override {
    return esphome::setup_priority::DATA;
  }

  void setup() override {
    // nothing to do here
  }

  void loop() override {
    while (available() > 0) {
      int incomingByte = read();

      switch (byteIndex) {
        case 0 ... 1:
          ESP_LOGD("DEBUG", "Byte index %d: %02x", byteIndex, incomingByte);
          if (incomingByte == 1) {
            byteIndex++;
          } else {
            byteIndex = 0;
          }

          break;
        case 2:
          ESP_LOGD("DEBUG", "Byte index %d: %02x", byteIndex, incomingByte);
          if (incomingByte >= 2 && incomingByte <= 4) {
            highByte = incomingByte;
            byteIndex++;
          } else {
            byteIndex = 0;
          }

          break;
        case 3:
          ESP_LOGD("DEBUG", "Byte index %d: %02x", byteIndex, incomingByte);
          height = ((unsigned int)highByte << 8) + incomingByte;
          byteIndex = 0;
          highByte = NULL;

          break;
        default:
          byteIndex = 0;

          break;
      }

      yield();
    }
  }

  void update() override {
    if (height && height != lastPublished) {
      lastPublished = height;
      publish_state(height);
    }
  }
};
