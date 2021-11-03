/*
 * Debug.h
 *
 *  Created on: Nov 2, 2021
 *      Author: Kunal
 */

#ifndef DEBUG_DEBUG_H_
#define DEBUG_DEBUG_H_

#include "main.h"
#include "GPIO/GPIO.h"

	void Console_Init(USART_TypeDef *port,int baudrate);
  void printConsole(USART_TypeDef *port,char *msg, ...);
  int scanConsole(char *msg,...);
  char * Console_Return(char *s);


#endif /* DEBUG_DEBUG_H_ */
