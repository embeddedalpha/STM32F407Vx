/*
 * NAU7802.c
 *
 *  Created on: 07-Dec-2021
 *      Author: Kunal
 */


#include "NAU7802.h"



/******************************************************************************************/
static uint8_t NAU7802_Calibrate(void)
{
	counter = 0;
	temp = 0;
	uint8_t value = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Internal Calibration Started\r\n");
	#endif
	do{
		#if NAU7802_DEBUG
			printConsole(USART1, "Internal Calibration Loop Iteration %d\r\n",counter);
		#endif
		Delay_us(500);
		value = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_CTRL1);
		value &= 0b11000111;
		value |= 0b100 << 3;


		I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_CTRL2, 0x02);
		counter += 1;
		Delay_ms(500);
		temp = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_CTRL2);
	}while(((temp & 0x02) == 0x02) && (counter > 10));
	if(counter > 10)
	{
		temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Internal Calibration Error\r\n");
	#endif
	}
	else
	{
		temp = 1;
	#if NAU7802_DEBUG
		printConsole(USART1, "Internal Calibration Passed\r\n");
	#endif
	}

	return temp;
}


static void NAU7802_Reset(void)
{
	counter = 0;
	temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Chip Reset Initiated \r\n");
	#endif
	I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_PU_CTRL, 0x01);
	Delay_ms(50);
	I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_PU_CTRL, 0x00);
	Delay_ms(5);
	temp = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_PU_CTRL);
	if((temp & 0x00) == 0x00)
	{
	#if NAU7802_DEBUG
		printConsole(USART1, "Chip Reset Successful\r\n");
	#endif
	}
}


static void NAU7802_Power_UP(void)
{
	counter = 0;
	temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Power Up Initiated \r\n");
	#endif
	do{
		#if NAU7802_DEBUG
			printConsole(USART1, "Power Up Loop Iteration %d\r\n",counter);
		#endif
		Delay_us(500);
		I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_PU_CTRL, 0x06);
		counter += 1;
		Delay_ms(500);
		temp = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_PU_CTRL);
	}while( ((temp & 0x06) == 0x06) && (counter > 10) );
	if(counter > 10)
	{
		temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Power UP Error\r\n");
	#endif
	}
	else
	{
		temp = 1;
	#if NAU7802_DEBUG
		printConsole(USART1, "Power UP Passed\r\n");
	#endif
	}
}


static void NAU7802_Set_LDO(void)
{
	uint8_t value;
	counter = 0;
	temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "LDO Initiated \r\n");
	#endif
	do{
	#if NAU7802_DEBUG
		printConsole(USART1, "LDO Loop Iteration %d\r\n",counter);
	#endif
		Delay_us(500);
		counter += 1;
		value = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_CTRL1);
		value &= 0b11000111;
		value |= 0b100 << 3;
		I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_CTRL1, value);
		Delay_us(500);
		temp = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_CTRL1);
	}while( ((temp & 0x38) == 0x38) && (counter > 10) );
	if(counter > 10)
	{
		temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "LDO Error\r\n");
	#endif
	}
	else
	{
		temp = 1;
	#if NAU7802_DEBUG
		printConsole(USART1, "LDO Passed\r\n");
	#endif
	}
}


static void NAU7802_Set_Gain()
{
	uint8_t value;
	counter = 0;
	temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Gain Setting Initiated \r\n");
	#endif
	do{
	#if NAU7802_DEBUG
		printConsole(USART1, "Gain Setting Loop Iteration %d\r\n",counter);
	#endif
		Delay_us(500);
		counter += 1;
		value = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_CTRL1);
		value &= 0b11000111;
		value |= 0b100 << 3;
		I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_CTRL1, value);
		Delay_us(500);
		temp = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_CTRL1);
	}while( ((temp & 0x38) == 0x38) && (counter > 10) );
	if(counter > 10)
	{
		temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Gain Setting Error\r\n");
	#endif
	}
	else
	{
		temp = 1;
	#if NAU7802_DEBUG
		printConsole(USART1, "Gain Setting Passed\r\n");
	#endif
	}
}

static void NAU7802_Set_Sample_Rate(void)
{
	uint8_t value;
	counter = 0;
	temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Sample Rate Setting Initiated \r\n");
	#endif
	do{
	#if NAU7802_DEBUG
		printConsole(USART1, "Sample Rate Setting Loop Iteration %d\r\n",counter);
	#endif
		Delay_us(500);
		counter += 1;
		value = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_CTRL2);
		value &= 0b10001111;
		value |= 0b011 << 4;
		I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_CTRL2, value);
		Delay_us(500);
		temp = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_CTRL2);
	}while( ((temp & 0x30) == 0x30) && (counter > 10) );
	if(counter > 10)
	{
		temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "Sample Rate Setting Error\r\n");
	#endif
	}
	else
	{
		temp = 1;
	#if NAU7802_DEBUG
		printConsole(USART1, "Sample Rate Setting Passed\r\n");
	#endif
	}
}

static void NAU7802_Set_ADC(void)
{

	counter = 0;
	temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "NAU7802 ADC Initiated \r\n");
	#endif
		I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_ADC, 0x30);
		Delay_us(500);
		temp = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_ADC);
	#if NAU7802_DEBUG
		if(temp == 0x30)
		{
			printConsole(USART1, "NAU7802 ADC Set Successful \r\n");
		}
		else
		{
			printConsole(USART1, "NAU7802 ADC Set Unsuccessful \r\n");
		}
	#endif
}

static void NAU7802_Configure_Decoupling_CAP(void)
{
	counter = 0;
	temp = 0;
	#if NAU7802_DEBUG
		printConsole(USART1, "NAU7802 Decoupling Cap Initiated \r\n");
	#endif
		I2C_Master_Write_Register(NAU7802, nau7802_address, NAU7802_PGA_PWR, 0x80);
		Delay_us(500);
		temp = I2C_Master_Read_Register(NAU7802, nau7802_address, NAU7802_PGA_PWR);
	#if NAU7802_DEBUG
		if(temp == 0x80)
		{
			printConsole(USART1, "NAU7802 Decoupling Cap Set Successful \r\n");
		}
		else
		{
			printConsole(USART1, "NAU7802 Decoupling Cap Set Unsuccessful \r\n");
		}
	#endif
}

/******************************************************************************************/

void NAU7802_Setup(I2C_TypeDef *I2C)
{
	counter = 0;
	temp = 0;
	NAU7802.I2C = I2C;
	NAU7802.mode = I2C_Fast_Mode;
	I2C_Master_Init(NAU7802);

	NAU7802_Reset();

	NAU7802_Power_UP();

	NAU7802_Set_LDO();

	NAU7802_Set_Gain();

	NAU7802_Set_Sample_Rate();

	NAU7802_Set_ADC();

	NAU7802_Configure_Decoupling_CAP();

	NAU7802_Calibrate();

}

float NAU7802_Get_Load_Cell_1(void);

float NAU7802_Get_Load_Cell_2(void);

float NAU7802_Get_Temperature(void);
