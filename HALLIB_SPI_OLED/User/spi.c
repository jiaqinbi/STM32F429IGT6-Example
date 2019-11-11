/******************************************************
 *  @brief  	SPI��ʼ���ļ�                         *              
 *  @file   	spi.c                                 *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��11��                        *
 *  @note       ʵ����SPI���ܳ�ʼ��                   *
 ******************************************************/

/*******************ͷ�ļ�����ʼ��*********************/
#include "spi.h"
#include "oled.h"
/*******************ͷ�ļ���������*********************/


SPI_HandleTypeDef hspi5;
SPI_HandleTypeDef hspi1;

/*******************��������ʼ��*********************/
/**  
 * @brief         SPIӲ��������ʼ��
 * @retval        void
 * @return		  ��
 * @note          ��
 */
 void SPI_InitConfig(void)
 {
    hspi5.Instance = SPI5;
    hspi5.Init.Mode = SPI_MODE_MASTER;
    hspi5.Init.Direction = SPI_DIRECTION_2LINES;
    hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
    hspi5.Init.CLKPolarity = SPI_POLARITY_HIGH;
    hspi5.Init.CLKPhase = SPI_PHASE_2EDGE;
    hspi5.Init.NSS = SPI_NSS_SOFT;
    hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2; 
    hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
    hspi5.Init.TIMode = SPI_TIMODE_DISABLED;
    hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
    hspi5.Init.CRCPolynomial = 7;
    HAL_SPI_Init(&hspi5); 
     
     
    hspi1.Instance = SPI1;
      hspi1.Init.Mode = SPI_MODE_MASTER;
      hspi1.Init.Direction = SPI_DIRECTION_2LINES;
      hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
      hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
      hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
      hspi1.Init.NSS = SPI_NSS_SOFT;
      hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_128;
      hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
      hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
      hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
      hspi1.Init.CRCPolynomial = 10;
      if (HAL_SPI_Init(&hspi1) != HAL_OK)
      {
//        Error_Handler();
      }
 }
 /**  
 * @brief         SPI��MCUӲ���е�GPIO��ʼ��
 * @retval        void
 * @return		  ��
 * @note          ��
 */
 void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
 {
    GPIO_InitTypeDef GPIO_InitStruct;
    if(hspi->Instance == SPI5)
    {
         __HAL_SPI_ENABLE(&hspi5);   /**< ʹ��SPI5 */
         __HAL_RCC_SPI5_CLK_ENABLE();
         __HAL_RCC_GPIOF_CLK_ENABLE();
        
        /**SPI5 GPIO��������      
        PF7     ------> SPI5_SCK
        PF8     ------> SPI5_MISO
        PF9     ------> SPI5_MOSI 
        */
        GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI5;
        HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);
    }
    else if(hspi->Instance == SPI1)
    {
        __HAL_RCC_SPI1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        
        /**SPI1 GPIO Configuration    
        PA5     ------> SPI1_SCK
        PA6     ------> SPI1_MISO
        PA7     ------> SPI1_MOSI 
        */
        GPIO_InitStruct.Pin = LCD_SCK_Pin|LCD_MOSI_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = LCD_MISO_Pin;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF5_SPI1;
        HAL_GPIO_Init(LCD_MISO_GPIO_Port, &GPIO_InitStruct);
    }
 }
 
/*******************������������*********************/