/**
 ******************************************************************************
 * @file    Timers.h
 * @author  Pedro Klein
 * @version V1.0
 * @date    11-October-2017
 * @brief   Library for Timers
 ******************************************************************************
 */
#ifndef _TIMERS_H
#define _TIMERS_H
#include "stm32f4xx.h"

/**
 * @brief Enables Timer 10.
 * @param PSC: TIM prescaler. ARR: TIM auto-reload register.
 */
void Timer10EN(int PSC, int ARR)
{
	RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
	TIM10->PSC = PSC - 1;
	TIM10->ARR = ARR - 1;
	TIM10->CR1 |= TIM_CR1_CEN;
}
/**
 * @brief Enables Timer 11.
 * @param PSC: TIM prescaler. ARR: TIM auto-reload register.
 */
void Timer11EN(int PSC, int ARR)
{
	RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
	TIM11->PSC = PSC - 1;
	TIM11->ARR = ARR - 1;
	TIM11->CR1 |= TIM_CR1_CEN;
}
/**
 * @brief Enables Millis.
 * @note Enables the use of the SysTick timer in milliseconds.
 */
void MillisEN(void)
{
	SysTick_Config(SystemCoreClock / 1000);
	HAL_IncTick();
}
/**
 * @brief Provides a delay in milliseconds.
 * @note Uses the SysTick timer to cause a delay on the program.
 * @param time_ms: delay in milliseconds.
 */
void MillisDelay(uint32_t time_ms)
{
	MillisEN();
	uint32_t tickstart = HAL_GetTick();
	while (time_ms > (HAL_GetTick() - tickstart))
	{
	}
}
/**
 * @brief Provides a delay in milliseconds.
 * @note Uses the Timer 11 to cause a delay on the program.
 * @param time_ms: delay in milliseconds.
 */
void Timer11Delay(uint32_t time_ms)
{
	Timer11EN(16000, 1);
	uint16_t count = 0;
	while (time_ms > count)
	{
		if (TIM11->SR & TIM_SR_UIF)
		{
			TIM11->SR &= ~TIM_SR_UIF;
			count++;
		}
	}
}
/**
 * @brief Makes a LED blink :D.
 * @note Uses the Timer 11 to toggle a pin at a certain frequency and in a certain number of times.
 * @param *port: pointer to a GPIO structure. pin: pin used. freq: frequency in Hz. piscadas: number of toggles.
 */
void PiscaLed(GPIO_TypeDef *port, uint8_t pin, uint8_t freq, uint8_t piscadas)
{
	Timer11EN(16000, (1000 / freq) / 2);
	TIM11->CR1 |= TIM_CR1_CEN;
	while (piscadas > 0)
	{
		if (TIM11->SR & TIM_SR_UIF)
		{
			TIM11->SR &= ~TIM_SR_UIF;
			port->ODR ^= (1 << pin);
			if (port->ODR & (1 << pin))
			{
				piscadas--;
			}
		}
	}
	TIM11->CR1 &= ~TIM_CR1_CEN;
	OutPORT(port, low, 1, pin);
}
#endif
