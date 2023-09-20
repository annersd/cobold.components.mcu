#pragma once

#include <Cobold.hpp>
#include "ISensor.h"

class MqttTeperatureSensorOptions 
{
private:
    /* data */
public:
    MqttTeperatureSensorOptions(/* args */);
    ~MqttTeperatureSensorOptions();
};


class MqttTeperatureSensor : public cobold::sensors::ISensor
{
public:
  MqttTeperatureSensor(const char* name, const char* topic, const char* unit, const char* deviceClass, const char* icon, const char* uniqueId, const char* stateTopic, const char* availabilityTopic, const char* payloadAvailable, const char* payloadNotAvailable, const char* payloadOn, const char* payloadOff, const char* payloadStop, const char* payloadOpen, const char* payloadClose, const char* payloadOpening, const char* payloadClosing, const char* payloadStopped, const char* payloadOnOff, const char* payloadOpenClose, const char* payloadValueTemplate, const char* commandTopic, const char* commandOn, const char* commandOff, const char* commandOpen, const char* commandClose, const char* commandStop, const char* commandStateTopic, const char* commandValueTemplate, const char* commandOnPublish, const char* commandOffPublish, const char* commandOpenPublish, const char* commandClosePublish, const char* commandStopPublish, const char* commandOnPublishRetain, const char* commandOffPublishRetain, const char* commandOpenPublishRetain, const char* commandClosePublishRetain, const char* commandStopPublishRetain, const char* commandStatePublish, const char* commandStatePublishRetain, const char* commandStateOff, const char* commandStateOn, const char* commandStateOpen, const char* commandStateClosed, const char* commandStateOpening, const char* commandStateClosing, const char* commandStateStopped, const char* commandStateValueTemplate, const char* commandAvailabilityTopic, const char* commandPayloadAvailable, const char* commandPayloadNotAvailable, const char* commandQos, const char* commandRetain, const char* commandPayload, const char* commandOptimistic, const char* commandPayloadOff, const char* commandPayloadOn, const char* commandPayloadOpen, const char* commandPayloadClose, const char* commandPayloadStop, const char* commandPayloadOpening, const char* commandPayloadClosing, const char* commandPayloadStopped, const char* commandPayloadOnOff, const char* commandPayloadOpenClose, const char* commandPayloadValueTemplate);
  ~MqttTeperatureSensor();

  void setup();
  void loop();

  void publishState();
  void publishAvailability();

  void setTemperature(float temperature
};