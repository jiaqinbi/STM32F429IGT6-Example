#ifndef __EXTI_H
#define __EXTI_H

#include "stm32f4xx_hal.h"

#define WK_UP_GPIO_PORT      GPIOA
#define WK_UP_GPIO_PIN       GPIO_PIN_0
#define WK_UP_RCC_ENABLE      __HAL_RCC_GPIOA_CLK_ENABLE

void EXTI_KEY_Config(void);

#endif

