/*
 * MAX6675.h
 *
 *  Created on: 27-Nov-2021
 *      Author: Kunal
 */

#ifndef MAX6675_MAX6675_H_
#define MAX6675_MAX6675_H_

#include "main.h"
#include "GPIO/GPIO.h"
#include "SPI/SPI.h"


SPI_Config MAX6675_1;
SPI_Config MAX6675_2;

////////////////////////////////////////////////////////////////////////////////////////////
void MAX6675_Init_1(SPI_TypeDef *Port, GPIO_TypeDef *nCSS_Port, int nCSS_Pin);
int MAX6675_Get_Raw_Temperature_1(void);
float MAX6675_Get_Celcius_Temperature_1(void);
float MAx6675_Get_Farenheit_Temperature_1(void);
////////////////////////////////////////////////////////////////////////////////////////////
void MAX6675_Init_2(SPI_TypeDef *Port, GPIO_TypeDef *nCSS_Port, int nCSS_Pin);
int MAX6675_Get_Raw_Temperature_2(void);
float MAX6675_Get_Celcius_Temperature_2(void);
float MAx6675_Get_Farenheit_Temperature_2(void);
///////////////////////////////////////////////////////////////////////////////////////////
#endif /* MAX6675_MAX6675_H_ */
