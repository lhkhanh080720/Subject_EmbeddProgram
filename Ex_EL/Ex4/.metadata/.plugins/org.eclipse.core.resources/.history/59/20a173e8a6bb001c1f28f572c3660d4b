/*
 * State.h
 *
 *  Created on: Apr 13, 2022
 *      Author: USER
 */

#ifndef SRC_STATE_H_
#define SRC_STATE_H_

#include "main.h"

typedef enum {SW_PRESS, SW_NONPRESS}    SW_t;
typedef enum {S0, S1, S2, S3}     state_t;

#define ON  GPIO_PIN_SET
#define OFF GPIO_PIN_RESET

void ledCtrl(uint8_t x);
SW_t SW(void);
void initState(void);
void stateSystemUpdate(void);


#endif /* SRC_STATE_H_ */
