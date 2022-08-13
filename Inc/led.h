#ifndef __LED_H__
#define __LED_H__


#include "stm32f4xx.h"


void RCC_Config(void);
void GPIO_Config(void);
void LED_ON(void);
void LED_OFF(void);
void LED_BLUE_ON(void);
void LED_BLUE_OFF(void);
void LED_RED_ON(void);
void LED_RED_OFF(void);
void LED_GREEN_ON(void);
void LED_GREEN_OFF(void);
void LED_ORANGE_ON(void);
void LED_ORANGE_OFF(void);

#endif
