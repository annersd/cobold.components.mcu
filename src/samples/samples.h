#pragma once

#include "Cobold.hpp"
#include "PCF8575_GPIO.h"


void createPCFio()
{
    auto pcf8575 = new PCF8575(nullptr, 0x20);
    auto gpio = new cobold::components::PCF8575_GPIO(pcf8575, 0 );

    auto gpio_component = new cobold::components::DynamicComponent<cobold::components::PCF8575_GPIO>();

    gpio_component->bind_configure([](cobold::components::DynamicComponent<cobold::components::PCF8575_GPIO> *component) {
         component->bound_object->get()->pin_mode(cobold::components::gpio::Flags::FLAG_OUTPUT);
    });
}

void setupExamples()
{
    // put your examples here, to run once:
    createPCFio();
}