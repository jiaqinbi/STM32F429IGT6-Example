/******************************************************
 *  @brief  	usart����                             *              
 *  @file       usart.h                               *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��21��                        *
 *  @note                                             *
 ******************************************************/

#ifndef __USART_H
#define __USART_H


/*******************ͷ�ļ�����ʼ��*********************/
#include "stm32f4xx_hal.h"
/*****************ͷ�ļ�������������******************/

/******************������������ʼ��********************/
extern UART_HandleTypeDef huart1;
/******************����������������********************/

/******************�궨�塾��ʼ��********************/
#define USART               USART1
#define USART_Handle         huart1
#define USART_RCC_ENABLE    __HAL_RCC_USART1_CLK_ENABLE

#define TX_GPIO_PORT        GPIOA
#define TX_GPIO_PIN         GPIO_PIN_9
#define TX_RCC_ENABLE       __HAL_RCC_GPIOA_CLK_ENABLE
#define RX_GPIO_PORT        GPIOA
#define RX_GPIO_PIN         GPIO_PIN_10
#define RX_RCC_ENABLE       __HAL_RCC_GPIOA_CLK_ENABLE
/******************�궨�塾������********************/

/******************������������ʼ��********************/
void USART_Config(void);
/******************����������������********************/

#endif
