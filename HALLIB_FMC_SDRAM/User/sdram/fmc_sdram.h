/******************************************************
 *  @brief  	sdramͷ�ļ�               *              
 *  @file   	fmc_sdram.h                           *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��14��                        *
 *  @note       ʵ��FMC����sdram��չоƬ���ڴ�ʵ��    *
 ******************************************************/
#ifndef __FMC_H
#define __FMC_H
#ifdef __cplusplus
 extern "C" {
#endif

/*******************ͷ�ļ���������ʼ��*********************/
#include "stm32f4xx_hal.h"
/*******************ͷ�ļ�������������*********************/

/*******************�궨�塾��ʼ��*********************/
#define Bank5_SDRAM_ADDR    ((uint32_t)(0XC0000000)) //SDRAM��ʼ��ַ
#define Bank5_SDRAM_SIZE    ((uint32_t)(0X00800000)) 
#define Bank5_SDRAM_END     ((uint32_t)(Bank5_SDRAM_ADDR+Bank5_SDRAM_SIZE-1)) //SDRAM������ַ

/* SDRAM���ò��� */
#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)

/* FMC SDRAM DGPIO pin */
#define SDRAM_A0_Pin            GPIO_PIN_0
#define SDRAM_A0_GPIO_Port      GPIOF
#define SDRAM_A1_Pin            GPIO_PIN_1
#define SDRAM_A1_GPIO_Port      GPIOF
#define SDRAM_A2_Pin            GPIO_PIN_2
#define SDRAM_A2_GPIO_Port      GPIOF
#define SDRAM_A3_Pin            GPIO_PIN_3
#define SDRAM_A3_GPIO_Port      GPIOF
#define SDRAM_A4_Pin            GPIO_PIN_4
#define SDRAM_A4_GPIO_Port      GPIOF
#define SDRAM_A5_Pin            GPIO_PIN_5
#define SDRAM_A5_GPIO_Port      GPIOF
#define SDRAM_SDNRAS_Pin        GPIO_PIN_11
#define SDRAM_SDNRAS_GPIO_Port  GPIOF
#define SDRAM_A6_Pin            GPIO_PIN_12
#define SDRAM_A6_GPIO_Port      GPIOF
#define SDRAM_A7_Pin            GPIO_PIN_13
#define SDRAM_A7_GPIO_Port      GPIOF
#define SDRAM_A8_Pin            GPIO_PIN_14
#define SDRAM_A8_GPIO_Port      GPIOF
#define SDRAM_A9_Pin            GPIO_PIN_15
#define SDRAM_A9_GPIO_Port      GPIOF
#define SDRAM_A10_Pin           GPIO_PIN_0
#define SDRAM_A10_GPIO_Port     GPIOG
#define SDRAM_A11_Pin           GPIO_PIN_1
#define SDRAM_A11_GPIO_Port     GPIOG
#define SDRAM_D4_Pin            GPIO_PIN_7
#define SDRAM_D4_GPIO_Port      GPIOE
#define SDRAM_D5_Pin            GPIO_PIN_8
#define SDRAM_D5_GPIO_Port      GPIOE
#define SDRAM_D6_Pin            GPIO_PIN_9
#define SDRAM_D6_GPIO_Port      GPIOE
#define SDRAM_D7_Pin            GPIO_PIN_10
#define SDRAM_D7_GPIO_Port      GPIOE
#define SDRAM_D8_Pin            GPIO_PIN_11
#define SDRAM_D8_GPIO_Port      GPIOE
#define SDRAM_D9_Pin            GPIO_PIN_12
#define SDRAM_D9_GPIO_Port      GPIOE
#define SDRAM_D10_Pin           GPIO_PIN_13
#define SDRAM_D10_GPIO_Port     GPIOE
#define SDRAM_D11_Pin           GPIO_PIN_14
#define SDRAM_D11_GPIO_Port     GPIOE
#define SDRAM_D12_Pin           GPIO_PIN_15
#define SDRAM_D12_GPIO_Port     GPIOE
#define SDRAM_D0_Pin            GPIO_PIN_14
#define SDRAM_D0_GPIO_Port      GPIOD
#define SDRAM_D1_Pin            GPIO_PIN_15
#define SDRAM_D1_GPIO_Port      GPIOD
#define SDRAM_A12_Pin           GPIO_PIN_2
#define SDRAM_A12_GPIO_Port     GPIOG
#define SDRAM_BA0_Pin           GPIO_PIN_4
#define SDRAM_BA0_GPIO_Port     GPIOG
#define SDRAM_BA1_Pin           GPIO_PIN_5
#define SDRAM_BA1_GPIO_Port     GPIOG
#define SDRAM_SDCLK_Pin         GPIO_PIN_8
#define SDRAM_SDCLK_GPIO_Port   GPIOG
#define SDRAM_SDNCAS_Pin        GPIO_PIN_15
#define SDRAM_SDNCAS_GPIO_Port  GPIOG

extern SDRAM_HandleTypeDef hsdram1;
/*******************�궨�塾������*********************/

/*******************������������ʼ��*********************/
void MX_FMC_Init(void);
void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef* hsdram);
void HAL_SDRAM_MspDeInit(SDRAM_HandleTypeDef* hsdram);
void SDRAM_Init(void);
/*******************����������������*********************/

#ifdef __cplusplus
}
#endif
#endif /*__FMC_H */
