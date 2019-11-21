/******************************************************
 *  @brief  	usart配置                             *              
 *  @file       usart.h                               *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年11月21日                        *
 *  @note                                             *
 ******************************************************/

#ifndef __USART_H
#define __USART_H


/*******************头文件【开始】*********************/
#include "stm32f4xx_hal.h"
/*****************头文件包含【结束】******************/

/******************变量声明【开始】********************/
extern UART_HandleTypeDef huart1;
/******************变量声明【结束】********************/

/******************宏定义【开始】********************/
#define USART               USART1
#define USART_Handle         huart1
#define USART_RCC_ENABLE    __HAL_RCC_USART1_CLK_ENABLE

#define TX_GPIO_PORT        GPIOA
#define TX_GPIO_PIN         GPIO_PIN_9
#define TX_RCC_ENABLE       __HAL_RCC_GPIOA_CLK_ENABLE
#define RX_GPIO_PORT        GPIOA
#define RX_GPIO_PIN         GPIO_PIN_10
#define RX_RCC_ENABLE       __HAL_RCC_GPIOA_CLK_ENABLE
/******************宏定义【结束】********************/

/******************函数声明【开始】********************/
void USART_Config(void);
/******************函数声明【结束】********************/

#endif
