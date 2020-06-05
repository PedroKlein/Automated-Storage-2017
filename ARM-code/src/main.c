/**
 ******************************************************************************
 * @file    main.c
 * @author  Pedro Klein
 * @version V1.0
 * @date    11-October-2017
 * @brief   Controls a automated storage.
 ******************************************************************************
 */

#include "Uart.h"
#include "GPIO.h"
#include "stm32f4xx.h"
#include "Timers.h"
#include "StepMotor.h"
#include "Storage.h"
#include <stdio.h>
#include <string.h>

//!Creates the structures for the step motor that will be used.
//!Motorx is the horizontal one and the motory are the two vertical ones.
stepmotor motorx;
stepmotor motory;

/**
 * @brief Manipulates the USART6 interruption.
 */
void USART6_IRQHandler(void)
{
	uint8_t rxData;
	//!Receives the data from the bluetooth(USART6).
	UartRX(USART6, &rxData);
	//!Execute the order according to the data received.
	switch (rxData - 'a')
	{
	case 0:
		ProductA2(motorx, motory, pick);
		break;
	case 1:
		ProductA2(motorx, motory, put);
		break;
	case 2:
		ProductA3(motorx, motory, pick);
		break;
	case 3:
		ProductA3(motorx, motory, put);
		break;
	case 4:
		ProductB1(motorx, motory, pick);
		break;
	case 5:
		ProductB1(motorx, motory, put);
		break;
	case 6:
		ProductB2(motorx, motory, pick);
		break;
	case 7:
		ProductB2(motorx, motory, put);
		break;
	case 8:
		ProductB3(motorx, motory, pick);
		break;
	case 9:
		ProductB3(motorx, motory, put);
		break;
	case 10:
		ProductC1(motorx, motory, pick);
		break;
	case 11:
		ProductC1(motorx, motory, put);
		break;
	case 12:
		ProductC2(motorx, motory, pick);
		break;
	case 13:
		ProductC2(motorx, motory, put);
		break;
	case 14:
		ProductC3(motorx, motory, pick);
		break;
	case 15:
		ProductC3(motorx, motory, put);
		break;
	case 16:
		ProductD1(motorx, motory, pick);
		break;
	case 17:
		ProductD1(motorx, motory, put);
		break;
	case 18:
		ProductD2(motorx, motory, pick);
		break;
	case 19:
		ProductD2(motorx, motory, put);
		break;
	case 20:
		ProductD3(motorx, motory, pick);
		break;
	case 21:
		ProductD3(motorx, motory, put);
		break;
	}
}
int main(void)
{
	//! Enables the clock for the PORTS A, B and C.
	RCC->AHB1ENR = (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN);
	//! Configure the USART6 using Baud Rate of 115200.
	UartEN(USART6, 115200);
	//!Enables the USART6 interruption, setting the priority to 3.
	NVIC_EnableIRQ(USART6_IRQn);
	NVIC_SetPriority(USART6_IRQn, 3);
	//!Configures the pins PA11 and PA12 as output for the H-Bridge.
	SetPORT(GPIOA, output, 2, 11, 12);
	//!Set the pins PA13 and PA14 as input for the end-of-stroke sensors.
	SetPORT(GPIOA, input, 1, 13, 14);
	//!Configures PA13 and PA14 with pull-up resistors.
	PUPDR(GPIOA, pullup, 1, 13, 14);
	//!Configures the pins PB13, PB14 and PB15 as output for the Status LEDs.
	/**
	 * Red LED : Waiting for order.
	 * Yellow LED : Executing order.
	 * Green LED : Order executed.
	 */
	SetPORT(GPIOB, output, 3, 13, 14, 15);
	//!Select the pins for motory.
	MotorPin(&motory, GPIOA, 5, 6, 7);
	//!Configurations of motory.
	MotorConfig(&motory, 7.13, 200, 280);
	//!Select the pins for motorx.
	MotorPin(&motorx, GPIOA, 8, 9, 10);
	//!Configurations of motorx.
	MotorConfig(&motorx, 0.2395, 48, 260);
	//!Enables the Timer 11.
	Timer11EN(16000, 500);
	//!Disable the counting.
	TIM11->CR1 &= ~TIM_CR1_CEN;
	//!Activate the Red LED.
	OutPORT(GPIOB, high, 1, 15);
	//!Pull the "claws" when it starts.
	Pull();
	//!Return to the initial position.
	MotorReturnX(motorx);
	MotorReturnY(motory);
	//!Sends a character to the bluetooth to identify the reset or the start of the board.
	UartTX(USART6, 'y');
	while (1)
	{
	}
}
