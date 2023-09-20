#pragma once
#include "AbstractGPIO.h"
#include <functional>

namespace cobold::components
{
    class BindableGPIO
    {
    public:
        
        // an bind function for each member function of AbstractGPIOPin with a suitable signature
        std::function<void(BindableGPIO*,gpio::Flags)> pin_mode;
        std::function<bool(BindableGPIO*)> digital_read;
        std::function<void(BindableGPIO*,bool)> digital_write;

        // constructor
        
        void bind_pin_mode(std::function<void(BindableGPIO*,gpio::Flags)> f) {
            pin_mode = f;
        }
        void bind_digital_read(std::function<bool(BindableGPIO*)> f) {
            digital_read = f;
        }
        void bind_digital_write(std::function<void(BindableGPIO*,bool)> f) {
            digital_write = f;
        }

        virtual void pin_mode(gpio::Flags flags) {
            pin_mode(this,flags);
        }
        virtual bool digital_read() {
            return digital_read(this);
        }
        virtual void digital_write(bool value) {
            digital_write(this,value);
        }
    };
} // namespace cobold::components