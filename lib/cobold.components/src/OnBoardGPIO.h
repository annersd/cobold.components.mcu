#pragma once

#include <Arduino.h>
#include "AbstractGPIO.h"

namespace cobold::components
{

    class OnBoardGPIO : public cobold::components::AbstractGPIOPin
    {
    private:
     

    public:
        OnBoardGPIO(uint8_t pin)  {
            pin_number = pin;
        }

        void pin_mode(gpio::Flags flags) override
        {

            // switch (flags) to set the pin mode
            switch (flags)
            {
            case gpio::Flags::FLAG_INPUT:
                pinMode(pin_number, INPUT);
                break;
            case gpio::Flags::FLAG_OUTPUT:
                pinMode(pin_number, OUTPUT);
                break;
            case gpio::Flags::FLAG_OPEN_DRAIN:
                pinMode(pin_number, OUTPUT_OPEN_DRAIN);
                break;
            case gpio::Flags::FLAG_PULLUP:
                pinMode(pin_number, INPUT_PULLUP);
                break;
            case gpio::Flags::FLAG_PULLDOWN:
                pinMode(pin_number, INPUT_PULLDOWN);
                break;
            default:
                break;
            }
        }
        bool digital_read() override
        {
            return digitalRead(pin_number);
        }
        void digital_write(bool value) override
        {
            digitalWrite(pin_number, value);
        }

        void configure_impl() override
        {
            this->name_ = "OnBoardGPIO Pin " + std::to_string(pin_number) + "";
            this->identifier_ = "io.onboard.gpio.pin." + std::to_string(pin_number) + "";
        }
    };

} // namespace cobold::components