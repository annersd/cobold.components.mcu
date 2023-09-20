#pragma once
#include <cstdint>
#include <string>

namespace cobold::components
{
    namespace gpio
    {
        enum Flags : uint8_t
        {
            // Can't name these just INPUT because of Arduino defines :(
            FLAG_NONE = 0x00,
            FLAG_INPUT = 0x01,
            FLAG_OUTPUT = 0x02,
            FLAG_OPEN_DRAIN = 0x04,
            FLAG_PULLUP = 0x08,
            FLAG_PULLDOWN = 0x10,
        };

        class FlagsHelper
        {
        public:
            constexpr FlagsHelper(Flags val) : val_(val) {}
            constexpr operator Flags() const { return val_; }

        protected:
            Flags val_;
        };
        constexpr FlagsHelper operator&(Flags lhs, Flags rhs)
        {
            return static_cast<Flags>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
        }
        constexpr FlagsHelper operator|(Flags lhs, Flags rhs)
        {
            return static_cast<Flags>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
        }

        enum InterruptType : uint8_t
        {
            INTERRUPT_RISING_EDGE = 1,
            INTERRUPT_FALLING_EDGE = 2,
            INTERRUPT_ANY_EDGE = 3,
            INTERRUPT_LOW_LEVEL = 4,
            INTERRUPT_HIGH_LEVEL = 5,
        };
    } // namespace gpio
    
    class AbstractGPIOPin
    {
    public:
        virtual void pin_mode(gpio::Flags flags) = 0;
        virtual bool digital_read() = 0;
        virtual void digital_write(bool value) = 0;
    };

} // namespace cobold::components