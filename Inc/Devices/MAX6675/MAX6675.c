/*
 * MAX6675.c
 *
 *  Created on: 27-Nov-2021
 *      Author: Kunal
 */


#include "MAX6675.h"


////////////////////////////////////////////////////////////////////////////////////////////
void MAX6675_Init_1(SPI_TypeDef *Port, GPIO_TypeDef *nCSS_Port, int nCSS_Pin)
{
	MAX6675_1.SPI = Port;
	MAX6675_1.Frame = SPI_Frame_16Bit;
	MAX6675_1.LSB_MSB = 0;
	MAX6675_1.frequency = 4;
	MAX6675_1.mode = SPI_Master;
	MAX6675_1.phase = 1;
	MAX6675_1.polarity = 1;
	MAX6675_1.type = SPI_Full_Duplex_Master;
	MAX6675_1.nCSS_Port = nCSS_Port;
	MAX6675_1.nCSS_pin = nCSS_Pin;
	SPI_Init(MAX6675_1);
}

int MAX6675_Get_Raw_Temperature_1(void)
{
	SPI_CSS_Low(MAX6675_1);
	int temp;
	temp = SPI_Receive_Data(MAX6675_1);
	SPI_CSS_High(MAX6675_1);
	return temp;
}

float MAX6675_Get_Celcius_Temperature_1(void)
{
	SPI_CSS_Low(MAX6675_1);
	float temp;
	temp = (float)(MAX6675_Get_Raw_Temperature_1()) * 0.25 / 10;
	SPI_CSS_High(MAX6675_1);
	return temp;
}

float MAx6675_Get_Farenheit_Temperature_1(void)
{
	SPI_CSS_Low(MAX6675_1);
	float temp;
	temp = (float)(MAX6675_Get_Raw_Temperature_1())* 9.0 / 5.0 + 32.0;
	SPI_CSS_High(MAX6675_1);
	return temp;
}
////////////////////////////////////////////////////////////////////////////////////////////
void MAX6675_Init_2(SPI_TypeDef *Port, GPIO_TypeDef *nCSS_Port, int nCSS_Pin)
{
	MAX6675_2.SPI = Port;
	MAX6675_2.Frame = SPI_Frame_16Bit;
	MAX6675_2.LSB_MSB = 0;
	MAX6675_2.frequency = 4;
	MAX6675_2.mode = SPI_Master;
	MAX6675_2.phase = 1;
	MAX6675_2.polarity = 1;
	MAX6675_2.type = SPI_Full_Duplex_Master;
	MAX6675_2.nCSS_Port = nCSS_Port;
	MAX6675_2.nCSS_pin = nCSS_Pin;
	SPI_Init(MAX6675_2);
}

int MAX6675_Get_Raw_Temperature_2(void)
{
	SPI_CSS_Low(MAX6675_2);
	int temp;
	temp = SPI_Receive_Data(MAX6675_2);
	SPI_CSS_High(MAX6675_2);
	return temp;
}

float MAX6675_Get_Celcius_Temperature_2(void)
{
	SPI_CSS_Low(MAX6675_2);
	float temp;
	temp = (float)(MAX6675_Get_Raw_Temperature_2()) * 0.25 / 10;
	SPI_CSS_High(MAX6675_2);
	return temp;
}

float MAx6675_Get_Farenheit_Temperature_2(void)
{
	SPI_CSS_Low(MAX6675_2);
	float temp;
	temp = (float)(MAX6675_Get_Raw_Temperature_2())* 9.0 / 5.0 + 32.0;
	SPI_CSS_High(MAX6675_2);
	return temp;
}
////////////////////////////////////////////////////////////////////////////////////////////
