/******************************************************
 *  @brief  	主文件                                *              
 *  @file       main.c                                *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年11月21日                        *
 *  @note       adc1采集PA5电压值                     *
 ******************************************************/
 
/*******************头文件【开始】*********************/
#include "main.h"
#include "led.h"
#include "adc.h"
#include "usart.h"
#include "stdio.h"
/*****************头文件包含【结束】******************/

/******************变量声明【开始】********************/
uint16_t temp;
float adc_value;
/******************变量声明【结束】********************/

/*******************函数【开始】*********************/
/**  
 * @brief         主程序
 * @retval        void
 * @return        无
 * @note          无
 */
int main(void)
{

    HAL_Init();
    MX_ADC_Init();          /**<  ADC1初始化 */
    USART_Config();         /**<  USART初始化 */
    while(1)
    {
        adc_value = 3.3*(Get_adcAverage(ADC_CHANNEL_5,10))/4096;             /**<  采集的电压值 */
        printf("[   INFO] main.c : adc_value= %.3fv \r\n\r\n", adc_value);   /**<  串口助手打印 */
        HAL_Delay(500);
    }
        
}
/*******************函数【结束】*********************/