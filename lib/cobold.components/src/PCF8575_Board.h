#pragma once

#include "Cobold.hpp"
#include "PCF8575.h"
#include "PCF8575_GPIO.h"

class PCF8575_Board : public cobold::components::Component 
{
private:
    PCF8575 *pcf8575_;

public:

    PCF8575_Board(PCF8575 *pcf8575) : pcf8575_(pcf8575) {}

    void configure_impl() override
    {
        this->name_ = "PCF8575_Board";
        this->identifier_ = "io.pcf8575.board";
    }

    void initialize_impl() override
    {
        pcf8575_->begin();
    }

    void update_impl() override
    {
    }

    cobold::components::AbstractGPIOPin *get_pin(uint8_t pin)
    {
        return new cobold::components::PCF8575_GPIO(pcf8575_, pin);
    }
};
