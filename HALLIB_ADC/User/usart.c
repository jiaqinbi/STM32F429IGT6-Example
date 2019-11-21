/******************************************************
 *  @brief  	usart配置                             *              
 *  @file       usart.c                               *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年11月21日                        *
 *  @note                                             *
 ******************************************************/
 
/*******************头文件【开始】*********************/
#include "usart.h"
#include "stdio.h"
/*****************头文件包含【结束】******************/

/******************变量声明【开始】********************/
UART_HandleTypeDef huart1;
/******************变量声明【结束】********************/

/*******************函数【开始】*********************/
/**  
 * @brief         usart初始化
 * @retval        void
 * @return        无
 * @note          无
 */
void USART_Config(void)
{
    
    GPIO_InitTypeDef GPIO_InitTypeStruct; 
    
    
    /** 使能USART1时钟 */
    USART_RCC_ENABLE();
    
    USART_Handle.Instance          = USART;
    USART_Handle.Init.BaudRate     = 115200;
    USART_Handle.Init.Mode         = UART_MODE_TX_RX;
    USART_Handle.Init.WordLength   = UART_WORDLENGTH_8B;
    USART_Handle.Init.StopBits     = UART_STOPBITS_1;
    USART_Handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    USART_Handle.Init.Parity       = UART_PARITY_NONE;
    USART_Handle.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&USART_Handle);
    
    /** 使能引脚TX RX时钟 */
    TX_RCC_ENABLE();
    RX_RCC_ENABLE();
    
    GPIO_InitTypeStruct.Pin = TX_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitTypeStruct.Pull = GPIO_PULLUP;
    GPIO_InitTypeStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitTypeStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(TX_GPIO_PORT, &GPIO_InitTypeStruct);
    
    GPIO_InitTypeStruct.Pin = RX_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitTypeStruct.Pull = GPIO_PULLUP;
    GPIO_InitTypeStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitTypeStruct.Alternate = GPIO_AF7_USART1;
    HAL_GPIO_Init(RX_GPIO_PORT, &GPIO_InitTypeStruct);
    
    HAL_NVIC_SetPriority(USART1_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
    
}
/**  
 * @brief         重定向printf
 * @note          无
 */
int fputc(int ch, FILE *f)
{
    uint8_t temp[1] = {ch};
    HAL_UART_Transmit(&huart1, temp, 1, 0xFFFF);
    return ch;
}
/*******************函数【结束】*********************/
