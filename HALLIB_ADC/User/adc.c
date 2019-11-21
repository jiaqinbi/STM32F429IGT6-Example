/******************************************************
 *  @brief  	adc1����                              *              
 *  @file       adc.c                                 *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��21��                        *
 *  @note                                             *
 ******************************************************/

/*******************ͷ�ļ�����ʼ��*********************/
#include "adc.h"
#include "stdio.h"
/*******************ͷ�ļ���������*********************/

/******************������������ʼ��********************/
ADC_HandleTypeDef hadc1;
/******************����������������********************/


/*******************��������ʼ��*********************/
/**  
 * @brief         ADC1 ������ʼ��
 * @retval        void
 * @return        ��
 * @note          ��
 */
 void MX_ADC_Init(void)
 {
     hadc1.Instance = adc;
     hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;  /**< Ԥ��Ƶ */
     hadc1.Init.ContinuousConvMode = DISABLE;
     hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;    
     hadc1.Init.DiscontinuousConvMode = DISABLE;     
     hadc1.Init.DMAContinuousRequests = DISABLE;
     hadc1.Init.EOCSelection = DISABLE;                     /**< EOC IT */
     hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;      /**< ������� */
     hadc1.Init.NbrOfConversion = 1;                        /**< 1��ת�� */
     hadc1.Init.NbrOfDiscConversion = 0;                    /**< δʹ�� */
     hadc1.Init.Resolution = ADC_RESOLUTION12b;
     hadc1.Init.ScanConvMode = DISABLE;                     /**< �����ڶ�ͨ������ */
     if(HAL_ADC_Init(&hadc1) != HAL_OK)
     {  
     }
     else
     {
        printf("[   INFO] adc.c : ADC1 Init Done! \r\n");   
     }
 }

/**  
 * @brief         ADC1 GPIO | RCC ��ʼ��
 * @retval        void
 * @param         hadc 
 * @return        ��
 * @note          ��
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
 * @brief         ��ȡADCͨ���ɼ���ֵ
 * @retval        int
 * @param         hadc 
 * @return        HAL_ADC_GetValue(&hadc1)
 * @note          ��
 */
uint16_t Get_adcValue(uint32_t ch)
{
    ADC_ChannelConfTypeDef channelConfig;
    channelConfig.Channel = ch;
    channelConfig.Rank = 1;     /**< һ��ת������ */
    channelConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;  /**< ��ͨ��ת���Բ���ʱ����Ҫ�� */
    channelConfig.Offset = 0;
    HAL_ADC_ConfigChannel(&hadc1, &channelConfig);
    
    /** ����ADC */
    HAL_ADC_Start(&hadc1);
    
    /** �ȴ�ת����� */
    HAL_ADC_PollForConversion(&hadc1, 0x0A);
    
    /** ��ȡת����������� */
    return HAL_ADC_GetValue(&hadc1);
    
}

/**  
 * @brief         ƽ��ADCͨ���ɼ���ֵ
 * @retval        int
 * @param1        ch 
 * @param2        count 
 * @return        HAL_ADC_GetValue(&hadc1)
 * @note          ��
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
/*******************������������*********************/




