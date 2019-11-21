/******************************************************
 *  @brief  	usart����                             *              
 *  @file       usart.c                               *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��21��                        *
 *  @note                                             *
 ******************************************************/
 
/*******************ͷ�ļ�����ʼ��*********************/
#include "usart.h"
#include "stdio.h"
/*****************ͷ�ļ�������������******************/

/******************������������ʼ��********************/
UART_HandleTypeDef huart1;
/******************����������������********************/

/*******************��������ʼ��*********************/
/**  
 * @brief         usart��ʼ��
 * @retval        void
 * @return        ��
 * @note          ��
 */
void USART_Config(void)
{
    
    GPIO_InitTypeDef GPIO_InitTypeStruct; 
    
    
    /** ʹ��USART1ʱ�� */
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
    
    /** ʹ������TX RXʱ�� */
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
 * @brief         �ض���printf
 * @note          ��
 */
int fputc(int ch, FILE *f)
{
    uint8_t temp[1] = {ch};
    HAL_UART_Transmit(&huart1, temp, 1, 0xFFFF);
    return ch;
}
/*******************������������*********************/
