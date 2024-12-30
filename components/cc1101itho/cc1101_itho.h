#pragma once

#include "esphome/core/component.h"
#include "esphome/core/gpio.h"
#include "esphome/components/button/button.h"
#include "esphome/components/fan/fan.h"

namespace esphome {
namespace c1101itho {

#ifndef ITHOPACKET_H_
#define ITHOPACKET_H_
/*
 * Author: Klusjesman, modified bij supersjimmie for Arduino/ESP8266
 */

enum IthoMessageType {
    ithomsg_unknown = 0,
    ithomsg_control = 1,
    ithomsg_join = 2,
     ithomsg_leave = 3
};
 
 //do not change enum because they are used in calculations!
enum IthoCommand {
    IthoUnknown = 0,

    IthoJoin = 4,
    IthoLeave = 8,

    IthoStandby = 34,
    IthoLow = 35,	
    IthoMedium = 36,	
    IthoHigh = 37,
    IthoFull = 38,

    IthoTimer1 = 41,
    IthoTimer2 = 51,
    IthoTimer3 = 61,

    //duco c system remote
    DucoStandby = 251,
    DucoLow = 252,
    DucoMedium = 253,
    DucoHigh = 254
};


class IthoPacket {
    public:
    uint8_t deviceId1[6];
    uint8_t deviceId2[8];
    IthoMessageType messageType;
    IthoCommand command;
    IthoCommand previous;

    uint8_t counter;		//0-255, counter is increased on every remote button press
};

#endif /* ITHOPACKET_H_ */

class CC1101IthoComponent : public PollingComponent {
 public:
  void setup() override;
  void set_data_pin(InternalGPIOPin *data_pin) { data_pin_ = data_pin; }
  void publish_state();

  static void ITHOinterrupt();
  static void ITHOcheck();

 protected:
  InternalGPIOPin *data_pin_;
};

} // namespace c1101itho
} // namespace esphome 
