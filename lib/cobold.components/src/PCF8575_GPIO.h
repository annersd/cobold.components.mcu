#pragma once

#include "AbstractGPIO.h"
#include "PCF8575.h"

namespace cobold::components
{

    class PCF8575_GPIO : public cobold::components::AbstractGPIOPin
    {
    private:
        
        PCF8575 *pcf8575_;

    public:
        PCF8575_GPIO(PCF8575 *pcf8575, uint8_t pin) : pcf8575_(pcf8575) {
            pin_number = pin;
        }

        void pin_mode(cobold::components::gpio::Flags flags) override
        {
            // switch (flags) to set the pin mode
            switch (flags)
            {
            case cobold::components::gpio::Flags::FLAG_INPUT:
                pcf8575_->pinMode(pin_number, INPUT);
                break;
            case cobold::components::gpio::Flags::FLAG_OUTPUT:
                pcf8575_->pinMode(pin_number, OUTPUT);
                break;
            case cobold::components::gpio::Flags::FLAG_OPEN_DRAIN:
                pcf8575_->pinMode(pin_number, OUTPUT_OPEN_DRAIN);
                break;
            case cobold::components::gpio::Flags::FLAG_PULLUP:
                pcf8575_->pinMode(pin_number, INPUT_PULLUP);
                break;
            case cobold::components::gpio::Flags::FLAG_PULLDOWN:
                pcf8575_->pinMode(pin_number, INPUT_PULLDOWN);
                break;
            default:
                break;
            }
        }
        bool digital_read() override
        {
            return pcf8575_->digitalRead(pin_number);
        }
        void digital_write(bool value) override
        {
            pcf8575_->digitalWrite(pin_number, value);
        }

        void configure_impl() override
        {
            this->name_ = "PCF8575_GPIO Pin " + std::to_string(pin_number) + "";
            this->identifier_ = "io.pcf8575.gpio.pin." + std::to_string(pin_number) + "";
        }
    };

} // namespace cobold::components