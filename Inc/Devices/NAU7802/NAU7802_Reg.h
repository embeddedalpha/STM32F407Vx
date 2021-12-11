/*
 * NAU7802_Reg.h
 *
 *  Created on: 25-Oct-2021
 *      Author: Kunal
 */

#ifndef NAU7820_NAU7802_REG_H_
#define NAU7820_NAU7802_REG_H_

#define nau7802_address          0x2A

//Register Map
typedef enum
{
  NAU7802_PU_CTRL = 0x00,
  NAU7802_CTRL1,
  NAU7802_CTRL2,
  NAU7802_OCAL1_B2,
  NAU7802_OCAL1_B1,
  NAU7802_OCAL1_B0,
  NAU7802_GCAL1_B3,
  NAU7802_GCAL1_B2,
  NAU7802_GCAL1_B1,
  NAU7802_GCAL1_B0,
  NAU7802_OCAL2_B2,
  NAU7802_OCAL2_B1,
  NAU7802_OCAL2_B0,
  NAU7802_GCAL2_B3,
  NAU7802_GCAL2_B2,
  NAU7802_GCAL2_B1,
  NAU7802_GCAL2_B0,
  NAU7802_I2C_CONTROL,
  NAU7802_ADCO_B2,
  NAU7802_ADCO_B1,
  NAU7802_ADCO_B0,
  NAU7802_ADC = 0x15, //Shared ADC and OTP 32:24
  NAU7802_OTP_B1,     //OTP 23:16 or 7:0?
  NAU7802_OTP_B0,     //OTP 15:8
  NAU7802_PGA = 0x1B,
  NAU7802_PGA_PWR = 0x1C,
  NAU7802_DEVICE_REV = 0x1F,
} Scale_Registers;

//Bits within the PU_CTRL register
typedef enum
{
  NAU7802_PU_CTRL_RR = 0,
  NAU7802_PU_CTRL_PUD,
  NAU7802_PU_CTRL_PUA,
  NAU7802_PU_CTRL_PUR,
  NAU7802_PU_CTRL_CS,
  NAU7802_PU_CTRL_CR,
  NAU7802_PU_CTRL_OSCS,
  NAU7802_PU_CTRL_AVDDS,
} PU_CTRL_Bits;

//Bits within the CTRL1 register
typedef enum
{
  NAU7802_CTRL1_GAIN_1 =   0,
  NAU7802_CTRL1_GAIN_2 =   1,
  NAU7802_CTRL1_GAIN_4 =   2,
  NAU7802_CTRL1_GAIN_8 =   3,
  NAU7802_CTRL1_GAIN_16 =  4,
  NAU7802_CTRL1_GAIN_32 =  5,
  NAU7802_CTRL1_GAIN_64 =  6,
  NAU7802_CTRL1_GAIN_128 = 7,

  NAU7802_CTRL1_VLDO_4V5 = 0 << 3,
  NAU7802_CTRL1_VLDO_4V2 = 1 << 3,
  NAU7802_CTRL1_VLDO_3V9 = 2 << 3,
  NAU7802_CTRL1_VLDO_3V6 = 3 << 3,
  NAU7802_CTRL1_VLDO_3V3 = 4 << 3,
  NAU7802_CTRL1_VLDO_3V0 = 5 << 3,
  NAU7802_CTRL1_VLDO_2V7 = 6 << 3,
  NAU7802_CTRL1_VLDO_2V4 = 7 << 3,

  NAU7802_CTRL1_DRDY_SEL = 1 << 6,
  NAU7802_CTRL1_CRP = 1 << 7,
} CTRL1_Bits;

//Bits within the CTRL2 register
typedef enum
{
  NAU7802_CTRL2_CALMOD_Gain_Calibration_System = 3 << 0,
  NAU7802_CTRL2_CALMOD_Offset_Calibration_System = 2 << 0,
  NAU7802_CTRL2_CALMOD_Gain_Calibration_Internal = 0 << 0, //default

  NAU7802_CTRL2_CALs_Start = 1 << 2,

  NAU7802_CTRL2_CAL_ERROR = 1 << 3,

  NAU7802_CTRL2_CRS_10SPS  = 0 << 4, //default
  NAU7802_CTRL2_CRS_20SPS  = 1 << 4,
  NAU7802_CTRL2_CRS_40SPS  = 2 << 4,
  NAU7802_CTRL2_CRS_80SPS  = 3 << 4,
  NAU7802_CTRL2_CRS_320SPS = 7 << 4,

  NAU7802_CTRL2_Channel_Select_0 = 0 << 7,
  NAU7802_CTRL2_Channel_Select_1 = 1 << 7,
} CTRL2_Bits;

//Bits within the PGA register
typedef enum
{
  NAU7802_PGA_CHP_DIS = 0,
  NAU7802_PGA_INV = 3,
  NAU7802_PGA_BYPASS_EN,
  NAU7802_PGA_OUT_EN,
  NAU7802_PGA_LDOMODE,
  NAU7802_PGA_RD_OTP_SEL,
} PGA_Bits;

//Bits within the PGA PWR register
typedef enum
{
  NAU7802_PGA_PWR_PGA_CURR = 0,
  NAU7802_PGA_PWR_ADC_CURR = 2,
  NAU7802_PGA_PWR_MSTR_BIAS_CURR = 4,
  NAU7802_PGA_PWR_PGA_CAP_EN = 1 << 7,
} PGA_PWR_Bits;

//Allowed Low drop out regulator voltages
typedef enum
{
  NAU7802_LDO_2V4 = 0b111,
  NAU7802_LDO_2V7 = 0b110,
  NAU7802_LDO_3V0 = 0b101,
  NAU7802_LDO_3V3 = 0b100,
  NAU7802_LDO_3V6 = 0b011,
  NAU7802_LDO_3V9 = 0b010,
  NAU7802_LDO_4V2 = 0b001,
  NAU7802_LDO_4V5 = 0b000,
} NAU7802_LDO_Values;

//Allowed gains
typedef enum
{
  NAU7802_GAIN_128 = 0b111,
  NAU7802_GAIN_64 = 0b110,
  NAU7802_GAIN_32 = 0b101,
  NAU7802_GAIN_16 = 0b100,
  NAU7802_GAIN_8 = 0b011,
  NAU7802_GAIN_4 = 0b010,
  NAU7802_GAIN_2 = 0b001,
  NAU7802_GAIN_1 = 0b000,
} NAU7802_Gain_Values;

//Allowed samples per second
typedef enum
{
  NAU7802_SPS_320 = 0b111,
  NAU7802_SPS_80 = 0b011,
  NAU7802_SPS_40 = 0b010,
  NAU7802_SPS_20 = 0b001,
  NAU7802_SPS_10 = 0b000,
} NAU7802_SPS_Values;

//Select between channel values
typedef enum
{
  NAU7802_CHANNEL_1 = 0,
  NAU7802_CHANNEL_2 = 1,
} NAU7802_Channels;

//Calibration state
typedef enum
{
  NAU7802_CAL_SUCCESS = 0,
  NAU7802_CAL_IN_PROGRESS = 1,
  NAU7802_CAL_FAILURE = 2,
} NAU7802_Cal_Status;
#endif /* NAU7820_NAU7802_REG_H_ */