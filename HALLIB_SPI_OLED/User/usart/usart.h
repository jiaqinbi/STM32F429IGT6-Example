#ifndef __USART_H
#define __USART_H


/*******************头文件包含【开始】*********************/
#include "stm32f4xx_hal.h"
/*******************头文件包含【结束】*********************/

extern UART_HandleTypeDef huart1;

/*******************宏定义【开始】*********************/
#define USART_RCC_ENABLE    __HAL_RCC_USART1_CLK_ENABLE     /**< 时钟使能 */
#define TX_GPIO_PORT        GPIOA                           /**< GPIO端口 */
#define TX_GPIO_PIN         GPIO_PIN_9                      /**< GPIO引脚 */
#define TX_RCC_ENABLE       __HAL_RCC_GPIOA_CLK_ENABLE
#define RX_GPIO_PORT        GPIOA
#define RX_GPIO_PIN         GPIO_PIN_10
#define RX_RCC_ENABLE       __HAL_RCC_GPIOA_CLK_ENABLE
/*******************宏定义【结束】*********************/

/*******************函数声明【开始】*********************/
void USART_InitConfig(void);
/*******************函数声明【结束】*********************/
#endif
