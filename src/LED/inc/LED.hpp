#ifndef LED_HPP
#define LED_HPP

#include "../../GPIO/inc/GPIO.hpp"
#include "../../../lib/std_types.h"

class LED :public GPIO
{
private:
    void delay(uint32_t milliseconds);
public:
    LED();
    LED(PORT_t , Pin_t , Mode_t );
    void blink_Led();
    ~LED();
};

#endif
