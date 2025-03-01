#include <iostream>
#include "GPIO/inc/GPIO.hpp"
#include "LED/inc/LED.hpp"
using namespace std ;
int main(int argc, char const *argv[])
{
    LED LED1(PORT_t::PortA ,Pin_t::Pin0 , Mode_t::OUTPUT);
    LED1.blink_Led();
    while (1){
        /* code */
    }
    
    return 0;
}
