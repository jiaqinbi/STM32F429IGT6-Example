/******************************************************
 *  @brief  	adc1.hͷ�ļ�                          *              
 *  @file       adc.h                                 *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��21��                        *
 *  @note                                             *
 ******************************************************/

#ifndef __ADC_H
#define __ADC_H

/*******************ͷ�ļ�����ʼ��*********************/
#include "stm32f4xx_hal.h"
/*******************ͷ�ļ���������*********************/

/******************�궨�塾��ʼ��********************/
#define adc                  ADC1

#define ADC_GPIO_PORT        GPIOA
#define ADC_GPIO_PIN         GPIO_PIN_5
/******************�궨�塾������********************/

/******************������������ʼ��********************/
 void MX_ADC_Init(void);
 void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
 uint16_t Get_adcValue(uint32_t ch);
 uint16_t Get_adcAverage(uint32_t ch, uint8_t count);
/*******************����������������*********************/


#endif  /* __ADC_H */

