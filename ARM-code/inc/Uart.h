/**
 ******************************************************************************
 * @file    Uart.h
 * @author  Pedro Klein
 * @version V1.0
 * @date    11-October-2017
 * @brief   Library for UART.
 *****/
#ifndef _UART_H
#define _UART_H
#include "stm32f4xx.h"
#include "math.h"
#include "GPIO.h"
#define _USE_SERIAL_PRINTF 1
#ifdef _USE_SERIAL_PRINTF
#include <stdio.h>
#endif

/**
 * @brief Enables an UART peripheral.
 * @note Can enable UART 2,3,4,5 and 6.
 * @note Configures all the needed pins to make the chosen  UART peripheral work.
 * @note Configure it with one stop byte, no parity and with oversampling by 16.
 * @param *uart: pointer to a UART structure. baud: the Baud Rate used.
 */
void UartEN(USART_TypeDef *uart, int baud)
{
	if (uart == USART2)
	{
		RCC->APB1ENR |= (1 << 17);
		SetPORT(GPIOA, alter, 2, 2, 3);
		AlterFunc(GPIOA, 2, AF7);
		AlterFunc(GPIOA, 3, AF7);
	}
	if (uart == USART3)
	{
		RCC->APB1ENR |= (1 << 18);
		SetPORT(GPIOC, alter, 2, 5, 10);
		AlterFunc(GPIOC, 5, AF7);  //RX
		AlterFunc(GPIOC, 10, AF7); //TX
	}
	if (uart == UART4)
	{
		RCC->APB1ENR |= (1 << 19);
		SetPORT(GPIOC, alter, 2, 10, 11);
		AlterFunc(GPIOC, 10, AF8);
		AlterFunc(GPIOC, 11, AF8);
	}
	if (uart == UART5)
	{
		RCC->APB1ENR |= (1 << 20);
		SetPORT(GPIOC, alter, 1, 12);
		SetPORT(GPIOD, alter, 1, 2);
		AlterFunc(GPIOC, 12, AF8);
		AlterFunc(GPIOD, 2, AF8);
	}
	if (uart == USART6)
	{
		RCC->APB2ENR |= (1 << 5);
		SetPORT(GPIOC, alter, 2, 6, 7);
		AlterFunc(GPIOC, 6, AF8); //TX
		AlterFunc(GPIOC, 7, AF8); //RX
	}
	uart->BRR = round(16 * (SystemCoreClock / (baud * 16.)));
	uart->CR1 = USART_CR1_UE | USART_CR1_TE | USART_CR1_RE | USART_CR1_RXNEIE;
	uart->CR2 = 0;
	uart->CR3 = 0;
}

/**
 * @brief Checks the UART buffer, if empty it sends a data.
 * @param *uart: pointer to a UART structure. txData: the data to be transmitted.
 */
void UartTX(USART_TypeDef *uart, char txData)
{
	if (uart->SR & USART_SR_TXE)
		uart->DR = txData;
}

/**
 * @brief Checks the UART buffer, if empty it receives a data.
 * @param *uart: pointer to a UART structure. *rxData: pointer to received the data.
 */
void UartRX(USART_TypeDef *uart, uint8_t *rxData)
{
	if (uart->SR & USART_SR_RXNE)
		*rxData = uart->DR;
}

/**
 * @brief Send a character vector until the end of the size.
 * @param *uart: pointer to a UART structure. *txData: pointer to the character vector. size: size of the character vector.
 */
void UartTX_string(USART_TypeDef *uart, uint8_t *txData, uint8_t size)
{
	static int i;
	i = -1;
	do
	{
		i++;
		while (!(uart->SR & USART_SR_TXE))
			UartTX(uart, *(txData + i));
	} while (i < size);
}

//!Enables the use of printf() function to send data via USART2.
#ifdef _USE_SERIAL_PRINTF
struct __FILE
{
	int dummy;
};
FILE __stdout;
int __io_putchar(int ch)
{
	while (!((USART2->SR) & USART_SR_TXE))
	{
	};
	USART2->DR = ch;
	return ch;
}
#endif
#endif
