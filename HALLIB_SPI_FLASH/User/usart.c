/*****************************************************
 *  @brief  	USART����ͨ���ļ�                    *              
 *  @file   	usart.c                              *
 *  @author 	�ϼ���                               *
 *  @version	v1.0                                 *
 *  @date  	    2019��10��31��                       *
 *  @note       ʵ����USART1�ĳ�ʼ��                 *
 *****************************************************/

/*******************ͷ�ļ�����ʼ��*********************/
#include "usart.h"
#include "stdio.h"
/*******************ͷ�ļ���������*********************/

/*******************������������ʼ��*********************/
UART_HandleTypeDef huart1;
/*******************����������������*********************/

/*******************��������ʼ��*********************/

/**  
 * @brief         USART1Ӳ������㣬��ʼ�������ʡ���żУ��λ��ֹͣλ����MCU�޹صĲ���
 * @param1        *huart  ���ھ��
 * @retval        void
 * @return		  ��
 * @note          ��
 */
void USART_InitConfig(void)
{  
    huart1.Instance          = USART1;              /**< ����1����ַ */
    huart1.Init.BaudRate     = 115200;              /**< ������ */
    huart1.Init.Mode         = UART_MODE_TX_RX;     /**< ģʽ */
    huart1.Init.WordLength   = UART_WORDLENGTH_8B;  /**< �ֽڳ��� */
    huart1.Init.StopBits     = UART_STOPBITS_1;     /**< ֹͣλ */
    huart1.Init.HwFlowCtl    = UART_HWCONTROL_NONE; /**< Ӳ����֧�� */
    huart1.Init.Parity       = UART_PARITY_NONE;    /**< ��żУ��λ */
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;/**< ���������� */
    HAL_UART_Init(&huart1);                         /**< ��ʼ������ */
}
/**  
 * @brief         USART1��MCUӲ���е�GPIO��ʼ��
 * @param1        *huart  ���ھ��
 * @retval        void
 * @return		  ��
 * @note          �ض�����Ժܷ����ʹ��C�����е�printf���д�ӡ���
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef GPIO_InitTypeStruct; 
    
    if(huart->Instance == USART1)
    {
        /** ʹ��USART1������ص�����ʱ�� */
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
 * @brief         �ض���printf
 * @param1        ch
 * @param2        *f
 * @retval        int
 * @return		  ch
 * @note          �ض�����Ժܷ����ʹ��C�����е�printf���д�ӡ���
 */
int fputc(int ch, FILE *f)
{
    uint8_t temp[1] = {ch};
    HAL_UART_Transmit(&huart1, temp, 1, 0xFFFF);
    return ch;
}

/*******************������������*********************/

