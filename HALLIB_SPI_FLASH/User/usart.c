/*****************************************************
 *  @brief  	USART串口通信文件                    *              
 *  @file   	usart.c                              *
 *  @author 	毕家钦                               *
 *  @version	v1.0                                 *
 *  @date  	    2019年10月31日                       *
 *  @note       实现了USART1的初始化                 *
 *****************************************************/

/*******************头文件【开始】*********************/
#include "usart.h"
#include "stdio.h"
/*******************头文件【结束】*********************/

/*******************变量声明【开始】*********************/
UART_HandleTypeDef huart1;
/*******************变量声明【结束】*********************/

/*******************函数【开始】*********************/

/**  
 * @brief         USART1硬件抽象层，初始化波特率、奇偶校验位、停止位等与MCU无关的参数
 * @param1        *huart  串口句柄
 * @retval        void
 * @return		  无
 * @note          无
 */
void USART_InitConfig(void)
{  
    huart1.Instance          = USART1;              /**< 串口1基地址 */
    huart1.Init.BaudRate     = 115200;              /**< 波特率 */
    huart1.Init.Mode         = UART_MODE_TX_RX;     /**< 模式 */
    huart1.Init.WordLength   = UART_WORDLENGTH_8B;  /**< 字节长度 */
    huart1.Init.StopBits     = UART_STOPBITS_1;     /**< 停止位 */
    huart1.Init.HwFlowCtl    = UART_HWCONTROL_NONE; /**< 硬件流支持 */
    huart1.Init.Parity       = UART_PARITY_NONE;    /**< 奇偶校验位 */
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;/**< 过采样长度 */
    HAL_UART_Init(&huart1);                         /**< 初始化函数 */
}
/**  
 * @brief         USART1在MCU硬件中的GPIO初始化
 * @param1        *huart  串口句柄
 * @retval        void
 * @return		  无
 * @note          重定向可以很方便的使用C语言中的printf进行打印输出
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef GPIO_InitTypeStruct; 
    
    if(huart->Instance == USART1)
    {
        /** 使能USART1功能相关的所有时钟 */
        USART_RCC_ENABLE();
        TX_RCC_ENABLE();
        RX_RCC_ENABLE();
        
        GPIO_InitTypeStruct.Pin = TX_GPIO_PIN;
        GPIO_InitTypeStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitTypeStruct.Pull = GPIO_PULLUP;
        GPIO_InitTypeStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        GPIO_InitTypeStruct.Alternate = GPIO_AF7_USART1;
        HAL_GPIO_Init(TX_GPIO_PORT, &GPIO_InitTypeStruct);

        GPIO_InitTypeStruct.Pin = RX_GPIO_PIN;
        HAL_GPIO_Init(RX_GPIO_PORT, &GPIO_InitTypeStruct);
    }
}

/**  
 * @brief         重定向printf
 * @param1        ch
 * @param2        *f
 * @retval        int
 * @return		  ch
 * @note          重定向可以很方便的使用C语言中的printf进行打印输出
 */
int fputc(int ch, FILE *f)
{
    uint8_t temp[1] = {ch};
    HAL_UART_Transmit(&huart1, temp, 1, 0xFFFF);
    return ch;
}

/*******************函数【结束】*********************/

