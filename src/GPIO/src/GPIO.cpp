#include <iostream>
#include"../inc/GPIO.hpp"
#include "../../../lib/BIT_MATH.h"
//#include "../../../lib/std_types.h"
//#include "GPIO.h"
#define BaseAddress 0x40020000UL
#define RCC_BASE  0x40023800

using namespace std;

typedef struct{
    volatile uint32_t CR;       /*Control register*/
    volatile uint32_t PLLCFGR;  /*PLL configuration register*/
    volatile uint32_t CFGR;     /*Clock configuration register*/
    volatile uint32_t CIR;      /*Clock interrupt register*/
    volatile uint32_t AHB1RSTR; /*AHB1 peripheral reset register*/
    volatile uint32_t AHB2RSTR; /*AHB2 peripheral reset register*/
    volatile const uint64_t reserved1;/*Reserved*/
    volatile uint32_t APB1RSTR; /*APB1 peripheral reset register*/
    volatile uint32_t APB2RSTR; /*APB2 peripheral reset register*/
    volatile const uint64_t reserved2;/*Reserved*/
    volatile uint32_t AHB1ENR;  /*AHB1 peripheral clock enable register*/
    volatile uint32_t AHB2ENR;  /*AHB2 peripheral clock enable register*/
    volatile const uint64_t reserved3;/*Reserved*/
    volatile uint32_t APB1ENR;  /*APB1 peripheral clock enable register*/
    volatile uint32_t APB2ENR;  /*APB2 peripheral clock enable register*/
    volatile const uint64_t reserved4;/*Reserved*/
    volatile uint32_t AHB1LPENR;/*AHB1 peripheral clock enable in low power mode register*/
    volatile uint32_t AHB2LPENR;/*AHB2 peripheral clock enable in low power mode register*/
    volatile const uint64_t reserved5;/*Reserved*/
    volatile uint32_t APB1LPENR;/*APB1 peripheral clock enable in low power mode register*/
    volatile uint32_t APB2LPENR;/*APB2 peripheral clock enable in low power mode register*/
    volatile const uint64_t reserved6;/*Reserved*/
    volatile uint32_t RCC_BDCR; /*Backup domain control register*/
    volatile uint32_t RCC_CSR;  /*Control/status register*/
    volatile const uint64_t reserved7;/*Reserved*/
    volatile uint32_t RCC_SSCGR;/*Spread spectrum clock generation register*/
    volatile uint32_t RCC_PLLI2SCFGR;/*PLLI2S configuration register*/
    volatile const uint32_t reserved8;/*Reserved*/
    volatile uint32_t RCC_DCKCFGR;/*Dedicated Clock Configuration Register*/
}RCC_Peripherial_t;

typedef  struct{
    volatile uint32_t* MODER;
    volatile uint32_t* ODR;
    volatile uint32_t* IDR;
}GPIO_Peripherial_t;

constexpr uint32_t GPIOA_BASE = 0x40020000UL;
constexpr uint32_t GPIO_OFFSET = 0x400UL;

constexpr uint32_t getGPIOBase(PORT_t portIndex) {
    return GPIOA_BASE + ((uint32_t) portIndex * GPIO_OFFSET);
}
GPIO_Peripherial_t GPIO_Peripherial;
RCC_Peripherial_t * RCC_Peripherial = (RCC_Peripherial_t*)RCC_BASE;

GPIO::GPIO(){
    cout <<"Please Enter Required value for GPIO \n";
}

GPIO::GPIO(PORT_t port, Pin_t pin, Mode_t mode){
    if (port<=PORT_t::PortI)
    {
        _port = port;
    }else{
        cout<<"Please Set The Correct value for The Port \n";
    }

    Handle_RCC();
    GPIO_Peripherial.MODER = reinterpret_cast<uint32_t*>(getGPIOBase(port) + 0x00);
    GPIO_Peripherial.ODR   = reinterpret_cast<uint32_t*>(getGPIOBase(port) + 0x14);
    GPIO_Peripherial.IDR   = reinterpret_cast<uint32_t*>(getGPIOBase(port) + 0x10);

    set_mode(mode);

}
void GPIO::Handle_RCC()
{
    uint32_t Clock_Enable = 0x0;
    SET_BIT(&RCC_Peripherial->CR , RCC_HSI);
    SET_BIT(&RCC_Peripherial->CFGR, RCC_HSI);
    SET_BIT(&RCC_Peripherial->AHB1ENR , Clock_Enable);

}
void GPIO::set_port(PORT_t port)
{
    if (port<=PORT_t::PortI)
    {
        _port = port;
    }else{
        cout<<"Please Set The Correct value for The Port \n";
    }
    
}

void GPIO::set_pin(Pin_t pin)
{
    if (pin<=Pin_t::Pin15)
    {
        _pin = pin;
        
    }else{
        cout<<"Please Set The Correct value for The Pin \n";
    }
}

void GPIO::set_mode(Mode_t mode)
{
    if (mode<=Mode_t::OUTPUT)
    {
        _mode = mode;
        CLR_BIT(GPIO_Peripherial.MODER ,(uint32_t) _pin);
        SET_BIT(GPIO_Peripherial.MODER,(uint32_t) _pin) ;
        
    }else{
        cout<<"Please Set The Correct value for The Mode \n";
    }
}

void GPIO::set_pin_value(Pin_value_t pin_value )
{
if (pin_value==Pin_value_t::PIN_LOW)
    {
        _pin_value = pin_value;
        CLR_BIT(GPIO_Peripherial.ODR ,(uint32_t) _pin);
    }else if (pin_value==Pin_value_t::PIN_HIGH)
    {
        _pin_value = pin_value;
        CLR_BIT(GPIO_Peripherial.ODR ,(uint32_t) _pin);
        SET_BIT(GPIO_Peripherial.ODR,(uint32_t) _pin) ;
    }
 else{
        cout<<"Please Set The Correct value for The Pin Value \n";
    }
}

PORT_t GPIO::get_port()
{
    return _port;
}

Pin_t GPIO::get_pin()
{
    return _pin;
}

Mode_t GPIO::get_mode()
{
    return _mode;
}

GPIO::~GPIO()
{
}