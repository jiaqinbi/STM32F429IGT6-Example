#ifndef __LED_H
#define __LED_H

#include "stm32f4xx_hal.h"

#define LED0_GPIO_PORT      GPIOB
#define LED0_GPIO_PIN       GPIO_PIN_1
#define LED0_RCC_ENABLE      __HAL_RCC_GPIOB_CLK_ENABLE

#define LED1_GPIO_PORT      GPIOB
#define LED1_GPIO_PIN       GPIO_PIN_0
#define LED1_RCC_ENABLE      __HAL_RCC_GPIOB_CLK_ENABLE

#define LED0_ON()            HAL_GPIO_WritePin(LED0_GPIO_PORT,LED0_GPIO_PIN,GPIO_PIN_RESET)
#define LED0_OFF()           HAL_GPIO_WritePin(LED0_GPIO_PORT,LED0_GPIO_PIN,GPIO_PIN_SET)
#define LED0_TOGGLE()        HAL_GPIO_TogglePin(LED0_GPIO_PORT,LED0_GPIO_PIN)

#define LED1_ON()            HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_GPIO_PIN,GPIO_PIN_RESET)
#define LED1_OFF()           HAL_GPIO_WritePin(LED1_GPIO_PORT,LED1_GPIO_PIN,GPIO_PIN_SET)
#define LED1_TOGGLE()        HAL_GPIO_TogglePin(LED1_GPIO_PORT,LED1_GPIO_PIN)

void LED_GPIO_Config(void);


#endif

