#include "SingleRelay.h"

#include <Arduino.h>

using namespace cobold::actuators;

SingleRelay::SingleRelay(cobold::components::AbstractGPIOPin *gpio , RelayState defaultNormalState)
    : gpio(gpio), normalState(defaultNormalState), currentState(defaultNormalState)
{
    // this->services = services;
    // logger = services->getService<cobold::Logger>();

    // Initialize the relay
    initialize();
}

void SingleRelay::close()
{
    setRelayState(cobold::actuators::RelayState::CLOSED);
}

void SingleRelay::open()
{
    setRelayState(cobold::actuators::RelayState::OPENED);
}

void SingleRelay::toggle()
{
    setRelayState(currentState == cobold::actuators::RelayState::CLOSED ? cobold::actuators::RelayState::OPENED : cobold::actuators::RelayState::CLOSED);
}

cobold::actuators::RelayState SingleRelay::getState() const
{
    return currentState;
}

cobold::actuators::RelayState SingleRelay::getNormalState() const
{
    return normalState;
}

bool SingleRelay::isNormalState() const
{
    return currentState == normalState;
}

void SingleRelay::update()
{
    // Nothing to do here
}

void SingleRelay::initialize()
{
    gpio->pin_mode(cobold::components::gpio::FLAG_OUTPUT);
    setRelayState(currentState);
}

void SingleRelay::setRelayState(cobold::actuators::RelayState newState)
{
    // logger->info("Changing relay state on pin %d to %s", pin, (newState == cobold::actuators::RelayState::CLOSED ? "CLOSED" : "OPENED"));
    gpio->digital_write(newState == normalState ? HIGH : LOW);
    currentState = newState;
}

void SingleRelay::configure() 
{
    // Nothing to do here
}

std::string SingleRelay::getId() const
{
    return "SingleRelay";
}

std::string SingleRelay::getName() const
{
    return "Single Relay";
}