/*
 * NAU7802.h
 *
 *  Created on: 07-Dec-2021
 *      Author: Kunal
 */

#ifndef NAU7802_NAU7802_H_
#define NAU7802_NAU7802_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "I2C/I2C.h"
#include "NAU7802_Reg.h"

static int temp;
static int counter;

I2C_Config NAU7802;

#define NAU7802_DEBUG 0


void NAU7802_Setup(I2C_TypeDef *I2C);

float NAU7802_Get_Load_Cell_1(void);

float NAU7802_Get_Load_Cell_2(void);

float NAU7802_Get_Temperature(void);

#endif /* NAU7802_NAU7802_H_ */
