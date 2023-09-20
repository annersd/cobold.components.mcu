#pragma once

#include <Arduino.h>
#include "AbstractGPIO.h"

namespace cobold::components
{

    class OnBoardGPIO : public cobold::components::AbstractGPIOPin
    {
    private:
        uint8_t pin_;

    public:
        OnBoardGPIO(uint8_t pin) : pin_(pin) {}

        void pin_mode(gpio::Flags flags) override
        {

            // switch (flags) to set the pin mode
            switch (flags)
            {
            case gpio::Flags::FLAG_INPUT:
                pinMode(pin_, INPUT);
                break;
            case gpio::Flags::FLAG_OUTPUT:
                pinMode(pin_, OUTPUT);
                break;
            case gpio::Flags::FLAG_OPEN_DRAIN:
                pinMode(pin_, OUTPUT_OPEN_DRAIN);
                break;
            case gpio::Flags::FLAG_PULLUP:
                pinMode(pin_, INPUT_PULLUP);
                break;
            case gpio::Flags::FLAG_PULLDOWN:
                pinMode(pin_, INPUT_PULLDOWN);
                break;
            default:
                break;
            }
        }
        bool digital_read() override
        {
            return digitalRead(pin_);
        }
        void digital_write(bool value) override
        {
            digitalWrite(pin_, value);
        }
    };

} // namespace cobold::components