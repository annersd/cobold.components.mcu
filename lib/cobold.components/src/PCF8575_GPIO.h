#pragma once

#include "AbstractGPIO.h"
#include "PCF8575.h"

namespace cobold::components
{

    class PCF8575_GPIO : public cobold::components::AbstractGPIOPin
    {
    private:
        uint8_t pin_;
        PCF8575 *pcf8575_;

    public:
        PCF8575_GPIO(PCF8575 *pcf8575, uint8_t pin) : pcf8575_(pcf8575), pin_(pin) {}

        void pin_mode(cobold::components::gpio::Flags flags) override
        {
            // switch (flags) to set the pin mode
            switch (flags)
            {
            case cobold::components::gpio::Flags::FLAG_INPUT:
                pcf8575_->pinMode(pin_, INPUT);
                break;
            case cobold::components::gpio::Flags::FLAG_OUTPUT:
                pcf8575_->pinMode(pin_, OUTPUT);
                break;
            case cobold::components::gpio::Flags::FLAG_OPEN_DRAIN:
                pcf8575_->pinMode(pin_, OUTPUT_OPEN_DRAIN);
                break;
            case cobold::components::gpio::Flags::FLAG_PULLUP:
                pcf8575_->pinMode(pin_, INPUT_PULLUP);
                break;
            case cobold::components::gpio::Flags::FLAG_PULLDOWN:
                pcf8575_->pinMode(pin_, INPUT_PULLDOWN);
                break;
            default:
                break;
            }
        }
        bool digital_read() override
        {
            return pcf8575_->digitalRead(pin_);
        }
        void digital_write(bool value) override
        {
            pcf8575_->digitalWrite(pin_, value);
        }
    };

} // namespace cobold::components