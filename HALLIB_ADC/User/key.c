#include "key.h"

void KEY_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitTypeStruct; 
    
    //Ê¹ÄÜKEYÊ±ÖÓ
    WK_UP_RCC_ENABLE();
    KEY0_RCC_ENABLE();
    KEY1_RCC_ENABLE();
    KEY2_RCC_ENABLE();
    
    GPIO_InitTypeStruct.Pin = WK_UP_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitTypeStruct.Pull = GPIO_PULLDOWN;
    HAL_GPIO_Init(WK_UP_GPIO_PORT, &GPIO_InitTypeStruct);
    
    GPIO_InitTypeStruct.Pin = KEY0_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitTypeStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(KEY0_GPIO_PORT, &GPIO_InitTypeStruct);

    
    GPIO_InitTypeStruct.Pin = KEY1_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitTypeStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(KEY1_GPIO_PORT, &GPIO_InitTypeStruct);


    GPIO_InitTypeStruct.Pin = KEY2_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitTypeStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(KEY2_GPIO_PORT, &GPIO_InitTypeStruct);
}

int KEY_Scan(void)
{
    if(HAL_GPIO_ReadPin(KEY0_GPIO_PORT,KEY0_GPIO_PIN) != SET)
    {
        return (KEYState_TypeDef)KEY0;
    }
    else if(HAL_GPIO_ReadPin(KEY1_GPIO_PORT,KEY1_GPIO_PIN) != SET)
    {
        return (KEYState_TypeDef)KEY1;
    }
    else if(HAL_GPIO_ReadPin(KEY2_GPIO_PORT,KEY2_GPIO_PIN) != SET)
    {
        return (KEYState_TypeDef)KEY2;
    }
    else if(HAL_GPIO_ReadPin(WK_UP_GPIO_PORT,WK_UP_GPIO_PIN) != RESET)
    {
        return (KEYState_TypeDef)WK_UP;
    }
    else
    {
        return (KEYState_TypeDef)error;
    }
}
