/******************************************************
 *  @brief  	SPI初始化文件                         *              
 *  @file   	spi.c                                 *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年10月31日                        *
 *  @note       实现了SPI功能初始化                   *
 ******************************************************/

/*******************头文件【开始】*********************/
#include "spi.h"
/*******************头文件【结束】*********************/


SPI_HandleTypeDef hspi5;

/*******************函数【开始】*********************/
/**  
 * @brief         SPI硬件抽象层初始化
 * @retval        void
 * @return		  无
 * @note          无
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
 }
 /**  
 * @brief         SPI在MCU硬件中的GPIO初始化
 * @retval        void
 * @return		  无
 * @note          无
 */
 void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi)
 {
    GPIO_InitTypeDef GPIO_InitStruct;
    if(hspi->Instance == SPI5)
    {
         __HAL_SPI_ENABLE(&hspi5);   //使能SPI5
         __HAL_RCC_SPI5_CLK_ENABLE();
         __HAL_RCC_GPIOF_CLK_ENABLE();
        
        /**SPI5 GPIO引脚配置      
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
 }
 
/*******************函数【结束】*********************/