/**
 ******************************************************************************
 * @file    Stepmotor.h
 * @author  Pedro Klein
 * @version V1.0
 * @date    11-October-2017
 * @brief   Library for the driver A4988
 ******************************************************************************
 */
#ifndef _STEPMOTOR_H
#define _STEPMOTOR_H
#include "stm32f4xx.h"
#include <math.h>
#include "GPIO.h"

/**
 * @brief Structure to hold step motor characteristics.
 */
typedef struct stepmotor
{
	GPIO_TypeDef *port; /*!< PORT used by the step motor */
	int steps_per_cm;	/*!< Number of steps to achieve one centimeter */
	int pin_clock;		/*!< Pin used to clock the driver */
	int pin_dir;		/*!< Pin used indicates the direction of spin */
	int pin_disable;	/*!< Pin used to disable/enable the step motor */
	int frequency;		/*!< the frequency of rotation */
} stepmotor;

/**
 * @brief Configures the pins used for the step motor
 * @param *p: pointer to a stepmotor structure. *port: pointer to a GPIO structure. pin_clk: pin used as clock.
 * pin_dir: pin used as direction. pin_disable: pin used as disabler.
 */
void MotorPin(stepmotor *p, GPIO_TypeDef *port, uint8_t pin_clk,
			  uint8_t pin_dir, uint8_t pin_disable)
{
	p->port = port;
	p->pin_clock = pin_clk;
	p->pin_dir = pin_dir;
	p->pin_disable = pin_disable;
	SetPORT(p->port, output, 3, p->pin_clock, p->pin_dir, p->pin_disable);
}
/**
 * @brief Configurations of the step motor used.
 * @param *p: pointer to a stepmotor structure. measure: the measurement of spirals in one centimeter at the attached lead screw.
 * steps: the number of steps to finish an entire twist. rpm: the rotations per minute desired.
 */
void MotorConfig(stepmotor *p, float measure, int steps, int rpm)
{
	p->steps_per_cm = (int)round(measure * steps);
	p->frequency = (int)round(steps * (rpm / 60));
	OutPORT(p->port, high, 1, p->pin_disable);
}

/**
 * @brief Makes the motor accomplish a certain distance.
 * @note Uses the configurations of the step motor to make it stay active until the distance is completed.
 * @param motor: the structures of the step motor used. distance: the distance that will be traveled.
 */
void MotorRun(stepmotor motor, float distance)
{
	//! Changes the direction according to the signal of the distance.
	if (distance < 0)
	{
		OutPORT(motor.port, high, 1, motor.pin_dir);
		distance = -distance;
	}
	OutPORT(motor.port, low, 1, motor.pin_disable);
	TIM10->SR &= ~TIM_SR_UIF;
	//! Calculates the number of steps needed to accomplish the distance
	int steps_to_distance = (int)round(distance * motor.steps_per_cm);
	Timer10EN(1000, (int)round((16000 / motor.frequency) / 2));
	while (steps_to_distance > 0)
	{
		if (TIM10->SR & TIM_SR_UIF)
		{
			TIM10->SR &= ~TIM_SR_UIF;
			motor.port->ODR ^= (1 << motor.pin_clock);
			if (motor.port->ODR & (1 << motor.pin_clock))
				steps_to_distance--;
		}
	}
	OutPORT(motor.port, high, 1, motor.pin_disable);
	OutPORT(motor.port, low, 2, motor.pin_dir, motor.pin_clock);
}
/**
 * @brief Makes the horizontal step motor keep running until it hits the end-of-stroke sensor.
 * @param motor: the structures of the step motor used.
 */
void MotorReturnX(stepmotor motor)
{
	OutPORT(motor.port, low, 1, motor.pin_disable);
	TIM10->SR &= ~TIM_SR_UIF;
	Timer10EN(1000, (int)round((16000 / motor.frequency) / 2));
	OutPORT(motor.port, high, 1, motor.pin_dir);
	while (1)
	{
		if (TIM10->SR & TIM_SR_UIF)
		{
			TIM10->SR &= ~TIM_SR_UIF;
			motor.port->ODR ^= (1 << motor.pin_clock);
			//! Checks the end-of-stroke sensor.
			if (!(GPIOA->IDR & GPIO_IDR_ID13))
			{
				OutPORT(motor.port, high, 1, motor.pin_disable);
				OutPORT(motor.port, low, 2, motor.pin_dir, motor.pin_clock);
				return;
			}
		}
	}
}

/**
 * @brief Makes the vertical step motor keep running until it hits the end-of-stroke sensor.
 * @param motor: the structures of the step motor used.
 */
void MotorReturnY(stepmotor motor)
{
	OutPORT(motor.port, low, 1, motor.pin_disable);
	TIM10->SR &= ~TIM_SR_UIF;
	Timer10EN(1000, (int)round((16000 / motor.frequency) / 2));
	OutPORT(motor.port, high, 1, motor.pin_dir);
	while (1)
	{
		if (TIM10->SR & TIM_SR_UIF)
		{
			TIM10->SR &= ~TIM_SR_UIF;
			motor.port->ODR ^= (1 << motor.pin_clock);
			//! Checks the end-of-stroke sensor.
			if (!(GPIOA->IDR & GPIO_IDR_ID14))
			{
				OutPORT(motor.port, high, 1, motor.pin_disable);
				OutPORT(motor.port, low, 2, motor.pin_dir, motor.pin_clock);
				return;
			}
		}
	}
}
#endif
