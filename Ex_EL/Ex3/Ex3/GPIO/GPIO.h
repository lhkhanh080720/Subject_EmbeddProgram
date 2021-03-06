/*
 * GPIO.h
 *
 *  Created on: Feb 18, 2022
 *      Author: USER
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#define LedPort     GPIO_PORTF_BASE
#define LedR        GPIO_PIN_1
#define LedB        GPIO_PIN_2
#define LedG        GPIO_PIN_3

#define SWPort      GPIO_PORTF_BASE
#define SW1         GPIO_PIN_4
#define SW2         GPIO_PIN_0

extern void Config_Led();
extern void Config_SW();

#endif /* GPIO_GPIO_H_ */

