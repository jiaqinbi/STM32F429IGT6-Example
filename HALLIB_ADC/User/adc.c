/******************************************************
 *  @brief  	adc1配置                              *              
 *  @file       adc.c                                 *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年11月21日                        *
 *  @note                                             *
 ******************************************************/

/*******************头文件【开始】*********************/
#include "adc.h"
#include "stdio.h"
/*******************头文件【结束】*********************/

/******************变量声明【开始】********************/
ADC_HandleTypeDef hadc1;
/******************变量声明【结束】********************/


/*******************函数【开始】*********************/
/**  
 * @brief         ADC1 抽象层初始化
 * @retval        void
 * @return        无
 * @note          无
 */
 void MX_ADC_Init(void)
 {
     hadc1.Instance = adc;
     hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;  /**< 预分频 */
     hadc1.Init.ContinuousConvMode = DISABLE;
     hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;    
     hadc1.Init.DiscontinuousConvMode = DISABLE;     
     hadc1.Init.DMAContinuousRequests = DISABLE;
     hadc1.Init.EOCSelection = DISABLE;                     /**< EOC IT */
     hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;      /**< 软件触发 */
     hadc1.Init.NbrOfConversion = 1;                        /**< 1个转换 */
     hadc1.Init.NbrOfDiscConversion = 0;                    /**< 未使用 */
     hadc1.Init.Resolution = ADC_RESOLUTION12b;
     hadc1.Init.ScanConvMode = DISABLE;                     /**< 仅对于多通道而言 */
     if(HAL_ADC_Init(&hadc1) != HAL_OK)
     {  
     }
     else
     {
        printf("[   INFO] adc.c : ADC1 Init Done! \r\n");   
     }
 }

/**  
 * @brief         ADC1 GPIO | RCC 初始化
 * @retval        void
 * @param         hadc 
 * @return        无
 * @note          无
 */
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
    GPIO_InitTypeDef GPIO_InitTypeStruct; 
    __HAL_RCC_ADC1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    
    
    GPIO_InitTypeStruct.Pin = ADC_GPIO_PIN;
    GPIO_InitTypeStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitTypeStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(ADC_GPIO_PORT, &GPIO_InitTypeStruct);
    
}
 
/**  
 * @brief         获取ADC通道采集的值
 * @retval        int
 * @param         hadc 
 * @return        HAL_ADC_GetValue(&hadc1)
 * @note          无
 */
uint16_t Get_adcValue(uint32_t ch)
{
    ADC_ChannelConfTypeDef channelConfig;
    channelConfig.Channel = ch;
    channelConfig.Rank = 1;     /**< 一个转换序列 */
    channelConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;  /**< 单通道转换对采样时间无要求 */
    channelConfig.Offset = 0;
    HAL_ADC_ConfigChannel(&hadc1, &channelConfig);
    
    /** 开启ADC */
    HAL_ADC_Start(&hadc1);
    
    /** 等待转换完成 */
    HAL_ADC_PollForConversion(&hadc1, 0x0A);
    
    /** 获取转换结果并返回 */
    return HAL_ADC_GetValue(&hadc1);
    
}

/**  
 * @brief         平均ADC通道采集的值
 * @retval        int
 * @param1        ch 
 * @param2        count 
 * @return        HAL_ADC_GetValue(&hadc1)
 * @note          无
 */
uint16_t Get_adcAverage(uint32_t ch, uint8_t count)
{
    uint16_t temp = 0;
    for(int i=0; i<count; i++)
    {
        temp += Get_adcValue(ch);
        HAL_Delay(5);
    }
    
    return temp/count;
}
/*******************函数【结束】*********************/




