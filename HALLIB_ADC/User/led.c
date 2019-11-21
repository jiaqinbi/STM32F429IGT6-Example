#include "led.h"


void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitTypeStruct; 
    
    //Ê¹ÄÜLEDÊ±ÖÓ
    LED0_RCC_ENABLE();
    LED1_RCC_ENABLE();
    LED1_OFF();
    LED0_OFF();
    GPIO_InitTypeStruct.Pin = LED0_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitTypeStruct.Pull = GPIO_PULLUP;
    GPIO_InitTypeStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED0_GPIO_PORT, &GPIO_InitTypeStruct);
    GPIO_InitTypeStruct.Pin = LED1_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitTypeStruct.Pull = GPIO_PULLUP;
    GPIO_InitTypeStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(LED1_GPIO_PORT, &GPIO_InitTypeStruct);

}

