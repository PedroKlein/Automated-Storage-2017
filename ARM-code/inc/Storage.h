/**
 ******************************************************************************
 * @file    Storage.h
 * @author  Pedro Klein
 * @version V1.0
 * @date    11-October-2017
 * @brief   Library for the automated storage
 ******************************************************************************
 */

#ifndef _STORAGE_H
#define _STORAGE_H

#include "StepMotor.h"
#include "stm32f4xx.h"
#include "Timers.h"

/**
 * @param Activates the H-bridge to push the product.
 * @note Activates the  H-bridge for a determined time.
 */
void Push(void)
{
	Timer11EN(16000, 500);
	TIM11->CR1 |= TIM_CR1_CEN;
	OutPORT(GPIOA, low, 1, 12);
	OutPORT(GPIOA, high, 1, 11);
	while (1)
	{
		if (TIM11->SR & TIM_SR_UIF)
		{
			TIM11->SR &= ~TIM_SR_UIF;
			OutPORT(GPIOA, low, 1, 11);
			TIM11->CR1 &= ~TIM_CR1_CEN;
			return;
		}
	}
}
/**
 * @param Activates the H-bridge to pull the product.
 * @note Activates the  H-bridge for a determined time.
 */
void Pull(void)
{
	Timer11EN(16000, 500);
	TIM11->CR1 |= TIM_CR1_CEN;
	OutPORT(GPIOA, low, 1, 11);
	OutPORT(GPIOA, high, 1, 12);
	while (1)
	{
		if (TIM11->SR & TIM_SR_UIF)
		{
			TIM11->SR &= ~TIM_SR_UIF;
			OutPORT(GPIOA, low, 1, 12);
			TIM11->CR1 &= ~TIM_CR1_CEN;
			return;
		}
	}
}

/**
 * @brief The action that the machine should do.
 * @note pick a product or put a product
 */
typedef enum type
{
	put,
	pick
} type;

/**
 * @brief All the actions needed to execute the order according to the product.
 * @note It executes every function needed to pick or to put a product.
 * @note Activate the Status LEDs and at the end sends a character using USART6 to identify the end of the order.
 * @param x: structure used for the horizontal step motor. y: structure used for the vertical step motor.
 * mode: The action that the machine should do.
 */
void ProductA2(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 0.5);
		MotorRun(y, 9);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -0.5);
		MotorRun(y, -9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 0.5);
		MotorRun(y, 9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductA3(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 0.5);
		MotorRun(y, 18);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -0.5);
		MotorRun(y, -18);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 0.5);
		MotorRun(y, 18);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductB1(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 9);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductB2(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 9);
		MotorRun(y, 9);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -9);
		MotorRun(y, -9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 9);
		MotorRun(y, 9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductB3(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 9);
		MotorRun(y, 18);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -9);
		MotorRun(y, -18);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 9);
		MotorRun(y, 18);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductC1(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 19);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -19);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 19);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductC2(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 19);
		MotorRun(y, 9);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -19);
		MotorRun(y, -9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 19);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductC3(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 19);
		MotorRun(y, 18);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -19);
		MotorRun(y, -18);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 19);
		MotorRun(y, 18);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductD1(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 28.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -28.5);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 28.5);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductD2(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 28.5);
		MotorRun(y, 9);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -28.5);
		MotorRun(y, -9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 28.5);
		MotorRun(y, 9);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
void ProductD3(stepmotor x, stepmotor y, type mode)
{
	//! Turns off the red LED.
	OutPORT(GPIOB, low, 1, 15);
	//! Turns on the yellow LED.
	OutPORT(GPIOB, high, 1, 14);
	//!Checks the mode and execute it.
	if (mode == pick)
	{
		MotorRun(x, 28.5);
		MotorRun(y, 18);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, -28.5);
		MotorRun(y, -18);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	else
	{
		MotorRun(x, 0.5);
		Push();
		MotorRun(y, 1);
		Pull();
		MotorRun(x, 28.5);
		MotorRun(y, 18);
		Push();
		MotorRun(y, -1);
		Pull();
	}
	//!Turns off the yellow LED.
	OutPORT(GPIOB, low, 1, 14);
	//!Returns to the initial position.
	MotorReturnX(x);
	MotorReturnY(y);
	//!Blinks the green LED to indicate conclusion.
	PiscaLed(GPIOB, 13, 2, 5);
	UartTX(USART6, 'z');
	//!Turns on the red LED.
	OutPORT(GPIOB, high, 1, 15);
}
#endif
