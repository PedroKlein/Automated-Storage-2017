/**
 ******************************************************************************
 * @file    GPIO.h
 * @author  Pedro Klein
 * @version V1.0
 * @date    11-October-2017
 * @brief   Library for the GPIO's structures.
 ******************************************************************************
 */
#ifndef _GPIO_H
#define _GPIO_H
#include "stm32f4xx.h"
#include "stdarg.h"

/* Macro to read a logic level at a pin */
#define ReadPin(port, pin) \
	((port->IDR & (1 << pin)))
/* Macro to toggle a logic level at a pin */
#define TogglePin(port, pin) \
	(port->ODR ^= (1 << pin))

/**
 *  @brief Types of configurations for MODER.
 */
typedef enum mode
{
	input,
	output,
	alter,
	analog
} mode;

/**
 * @brief Logic levels for ODR.
 */
typedef enum logic
{
	low,
	high
} logic;

/**
 * @brief Alternative functions for AFR.
 */
typedef enum alterfunction
{
	AF0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
} alterfunc;

/**
 * @brief Configurations for PUPDR.
 */
typedef enum pupdr
{
	no,
	pullup,
	pulldown
} pupdr;

/**
 * @brief Configures pins at a certain PORT using MODER.
 * @note Configures a determinate number of pins in a PORT as input, output, alternative function or analogic mode.
 * @note Uses a indeterminate number of parameters to configure more then one pin in the PORT.
 * @param *port: pointer to a GPIO structure. mode: define the mode. Qtdpin: number of pins that will be configured. ... : the pins used.
 */
void SetPORT(GPIO_TypeDef *port, mode mode, uint8_t Qtdpin, ...)
{
	va_list ap;
	uint8_t pin;
	uint8_t count;
	va_start(ap, Qtdpin);
	for (count = 0; count < Qtdpin; count++)
	{
		pin = va_arg(ap, int);
		port->MODER &= ~(mode << (pin * 2));
		port->MODER |= (mode << (pin * 2));
	}
	va_end(ap);
}

/**
 * @brief Configures the alternative function.
 * @note Configures a pin in the alternative function mode and in wich alternative function.
 * @param *port: pointer to a GPIO structure. pin: the pin desired. alterfunc: the type of alternative function used.
 */
void AlterFunc(GPIO_TypeDef *port, int pin, alterfunc alterfunc)
{
	SetPORT(port, alter, 1, pin);
	if (pin < 8)
	{
		port->AFR[0] |= (alterfunc << (pin * 4));
	}
	if (pin >= 8)
	{
		port->AFR[1] |= (alterfunc << (pin * 4));
	}
}

/**
 * @brief Writes a logic level in a determined number of pins in a PORT
 * @note Uses a indeterminate number of parameters to configure more then one pin in the PORT.
 * @param *port: pointer to a GPIO structure. type: define the logic value. Qtdpin: number of pins that will be configured. ... : the pins used.
 */
void OutPORT(GPIO_TypeDef *port, uint8_t type, uint8_t Qtdpin, ...)
{
	va_list ap;
	uint8_t pin;
	uint8_t count;
	va_start(ap, Qtdpin);
	for (count = 0; count < Qtdpin; count++)
	{
		pin = va_arg(ap, int);
		if (type == high)
		{
			port->ODR &= ~(type << pin);
			port->ODR |= (type << pin);
		}
		else if (type == low)
			port->ODR &= ~(high << pin);
	}

	va_end(ap);
}

/**
 * @brief Configures the internal resistors at a certain PORT as pull-up or pull-down using PUPDR.
 * @note Uses a indeterminate number of parameters to configure more then one pin in the PORT.
 * @param *port: pointer to a GPIO structure. mode: define the mode of the resistor. Qtdpin: number of pins that will be configured. ... : the pins used.
 */
void PUPDR(GPIO_TypeDef *port, pupdr mode, uint8_t Qtdpin, ...)
{
	va_list ap;
	uint8_t pin;
	uint8_t count;
	va_start(ap, Qtdpin);
	for (count = 0; count < Qtdpin; count++)
	{
		pin = va_arg(ap, int);
		port->PUPDR &= ~(mode << (pin * 2));
		port->PUPDR |= (mode << (pin * 2));
	}
	va_end(ap);
}

#endif
