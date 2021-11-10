/*
 * Timer.c
 *
 *  Created on: 10-Nov-2021
 *      Author: Kunal
 */


#include "Timer.h"




void Encoder_1_Init(TIM_TypeDef *TIM)
{
		RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;

		GPIO_Pin_Setup('E', 9, ALTERNATE_FUNCTION_OUTPUT_PUSHPULL, TIM1_CH1);
		GPIO_Pin_Setup('E', 11, ALTERNATE_FUNCTION_OUTPUT_PUSHPULL, TIM1_CH2);

		TIM1 -> ARR = 0xFFFF;
		TIM1 -> CCMR1 |= TIM_CCMR1_CC1S_0 | TIM_CCMR1_CC2S_0;
		TIM1 -> CCER &= ~(TIM_CCER_CC1P | TIM_CCER_CC2P);
		TIM1 -> SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1;
		TIM1 -> CR1 |= TIM_CR1_CEN;


}


void Encoder_2_Init(TIM_TypeDef *TIM)
{

}



int Encoder_1_Read(TIM_TypeDef *TIM)
{
	return 	TIM1 -> CCR1;
}

int Encoder_2_Read(TIM_TypeDef *TIM)
{
	return 	TIM1 -> CCR3;
}
