#ifndef __USART_H
#define __USART_H


/*******************ͷ�ļ���������ʼ��*********************/
#include "stm32f4xx_hal.h"
/*******************ͷ�ļ�������������*********************/

extern UART_HandleTypeDef huart1;

/*******************�궨�塾��ʼ��*********************/
#define USART_RCC_ENABLE    __HAL_RCC_USART1_CLK_ENABLE     /**< ʱ��ʹ�� */
#define TX_GPIO_PORT        GPIOA                           /**< GPIO�˿� */
#define TX_GPIO_PIN         GPIO_PIN_9                      /**< GPIO���� */
#define TX_RCC_ENABLE       __HAL_RCC_GPIOA_CLK_ENABLE
#define RX_GPIO_PORT        GPIOA
#define RX_GPIO_PIN         GPIO_PIN_10
#define RX_RCC_ENABLE       __HAL_RCC_GPIOA_CLK_ENABLE
/*******************�궨�塾������*********************/

/*******************������������ʼ��*********************/
void USART_InitConfig(void);
/*******************����������������*********************/
#endif
