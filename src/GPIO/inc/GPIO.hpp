#ifndef GPIO_HPP
#define GPIO_HPP
typedef enum { PortA, PortB, PortC, PortD, PortE, PortF, PortG, PortH, PortI }PORT_t;
typedef enum   { Pin0, Pin1, Pin2, Pin3, Pin4, Pin5, Pin6, Pin7, Pin8, Pin9, Pin10, Pin11, Pin12, Pin13, Pin14, Pin15 }Pin_t;
typedef enum   { INPUT, OUTPUT }Mode_t;
typedef enum  { PIN_LOW, PIN_HIGH }Pin_value_t;

typedef enum {
    RCC_HSI,
    RCC_HSE,
    RCC_PLL,
}RCC_enuCLK_t;

typedef enum {
    AHB1ENR,
    AHB2ENR,
    APB1ENR,
    APB2ENR,

}peripheral_clock_t;

class GPIO
{
private:
    void Handle_RCC();
protected:
    PORT_t _port;
    Pin_t _pin;
    Mode_t _mode;
    Pin_value_t _pin_value;
public:
    GPIO();
    GPIO(PORT_t , Pin_t , Mode_t);
    void set_port(PORT_t);
    void set_pin(Pin_t);
    void set_mode(Mode_t);
    void set_pin_value(Pin_value_t);
    PORT_t get_port();
    Pin_t get_pin();
    Mode_t get_mode();
    Pin_value_t get_pin_value();
    ~GPIO();
};
#endif
