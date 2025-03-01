#include <iostream>
#include <cstdint> // Include for uint32_t
#include "../inc/LED.hpp"
#include "../../GPIO/inc/GPIO.hpp"
#include "../../../lib/BIT_MATH.h"
//#include "../../../lib/std_types.h"

// Default constructor
LED::LED() {
    std::cout << "Please Enter Required value for Port and Pin \n";
}

// Parameterized constructor
LED::LED(PORT_t port, Pin_t pin, Mode_t mode) : GPIO(port, pin, mode) {
}

// Method to blink the LED with a 2-second delay
void LED::blink_Led() {
    while (true) {
        set_pin_value(Pin_value_t::PIN_HIGH); // Turn on the LED
        delay(500); // Delay for 2 seconds
        set_pin_value(Pin_value_t::PIN_LOW);  // Turn off the LED
        delay(500); // Delay for 2 seconds
    }
}

// Simple busy-wait delay function
void LED::delay(uint32_t milliseconds) {
    // Approximate delay calculation (adjust based on your system clock speed)
    for (volatile uint32_t i = 0; i < milliseconds * 1000; i++) {
        // Busy-wait loop
    }
}

// Destructor
LED::~LED() {
    // Clean up resources if needed
}