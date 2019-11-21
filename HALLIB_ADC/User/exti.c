#include "exti.h"

void EXTI_KEY_Config(void)
{
     GPIO_InitTypeDef GPIO_InitTypeStruct; 
    
    //使能KEY时钟
    WK_UP_RCC_ENABLE();
    
    GPIO_InitTypeStruct.Pin = WK_UP_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_IT_RISING;
    GPIO_InitTypeStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(WK_UP_GPIO_PORT, &GPIO_InitTypeStruct);
    
    //中断优先级分组
    HAL_NVIC_SetPriority(EXTI0_IRQn, 2, 2);
    HAL_NVIC_EnableIRQ(EXTI0_IRQn);
    
}
