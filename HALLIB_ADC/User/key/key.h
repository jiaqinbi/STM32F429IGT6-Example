#ifndef __KEY_H
#define __KEY_H


#include "stm32f4xx_hal.h"

#define WK_UP_GPIO_PORT      GPIOA
#define WK_UP_GPIO_PIN       GPIO_PIN_0
#define WK_UP_RCC_ENABLE      __HAL_RCC_GPIOA_CLK_ENABLE

#define KEY0_GPIO_PORT      GPIOH
#define KEY0_GPIO_PIN       GPIO_PIN_3
#define KEY0_RCC_ENABLE      __HAL_RCC_GPIOH_CLK_ENABLE

#define KEY1_GPIO_PORT      GPIOH
#define KEY1_GPIO_PIN       GPIO_PIN_2
#define KEY1_RCC_ENABLE      __HAL_RCC_GPIOH_CLK_ENABLE

#define KEY2_GPIO_PORT      GPIOC
#define KEY2_GPIO_PIN       GPIO_PIN_13
#define KEY2_RCC_ENABLE      __HAL_RCC_GPIOC_CLK_ENABLE

typedef struct
{
    uint8_t WK_UP;
    uint8_t KEY0;
    uint8_t KEY1;
    uint8_t KEY2;
}KEYState_InitTypeDef;

typedef enum
{
    KEY0  = 0,
    KEY1  = 1,
    KEY2  = 2,
    WK_UP = 3,
    error = 4
}KEYState_TypeDef;

void KEY_GPIO_Config(void);
int KEY_Scan(void);



#endif

