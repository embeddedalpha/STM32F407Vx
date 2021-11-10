/*
 * Timer.h
 *
 *  Created on: 10-Nov-2021
 *      Author: Kunal
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#include "main.h"
#include "GPIO/GPIO.h"


/*
 * importing parameter: TIM - > {TIM1, TIM2, TIM3, TIM4, TIM5, TIM6, TIM7
 *                                    TIM7, TIM8, TIM9, TIM10, TIM11, TIM12, TIM13, TIM14}
 * return: none
 * Note: For encoder 1: channel 1 and 2
 *       For encoder 2: channel 3 and 4
 */
void Encoder_1_Init(TIM_TypeDef *TIM);
void Encoder_2_Init(TIM_TypeDef *TIM);

/*
 * importing parameter:  TIM - > {TIM1, TIM2, TIM3, TIM4, TIM5, TIM6, TIM7
 *                                    TIM7, TIM8, TIM9, TIM10, TIM11, TIM12, TIM13, TIM14}
 * return: Encoder Ticks
 */
int Encoder_1_Read(TIM_TypeDef *TIM);
int Encoder_2_Read(TIM_TypeDef *TIM);
#endif /* TIMER_TIMER_H_ */
