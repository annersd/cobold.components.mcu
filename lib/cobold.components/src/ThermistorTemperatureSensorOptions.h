#pragma once

#include "Cobold.hpp"
#include <string>

namespace cobold
{
    namespace sensors
    {

        class ThermistorTemperatureSensorOptions : public cobold::sys::Options
        {
        public:
            int pin;
            std::string name;

            ThermistorTemperatureSensorOptions(cobold::configuration::IConfiguration *configuration)
                : Options(configuration)
            {
            }
            ThermistorTemperatureSensorOptions(int pin) : pin(pin){};
            ThermistorTemperatureSensorOptions() = default;
            ~ThermistorTemperatureSensorOptions() = default;

            void logOptions() override
            {
                auto logger = cobold::services::getLogger();
                logger->debug("ThermistorTemperatureSensorOptions::logOptions()");
                logger->debug("pin: {%u}", pin);
                logger->debug("name: {%s}", name.c_str());
            }

            void parseConfiguration(cobold::configuration::IConfiguration *configuration) override
            {
                pin = configuration->getInt("pin");
                name = configuration->getString("name");
            }
        };

    } // namespace sensors
} // namespace cobold