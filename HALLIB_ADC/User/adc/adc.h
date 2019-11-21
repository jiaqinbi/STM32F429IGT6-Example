/******************************************************
 *  @brief  	adc1.h头文件                          *              
 *  @file       adc.h                                 *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年11月21日                        *
 *  @note                                             *
 ******************************************************/

#ifndef __ADC_H
#define __ADC_H

/*******************头文件【开始】*********************/
#include "stm32f4xx_hal.h"
/*******************头文件【结束】*********************/

/******************宏定义【开始】********************/
#define adc                  ADC1

#define ADC_GPIO_PORT        GPIOA
#define ADC_GPIO_PIN         GPIO_PIN_5
/******************宏定义【结束】********************/

/******************函数声明【开始】********************/
 void MX_ADC_Init(void);
 void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
 uint16_t Get_adcValue(uint32_t ch);
 uint16_t Get_adcAverage(uint32_t ch, uint8_t count);
/*******************函数声明【结束】*********************/


#endif  /* __ADC_H */

