
/******************************************************
 *  @brief  	����ļ�                              *              
 *  @file   	main.c                                *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��14��                        *
 *  @note       ʵ��SPI��д�ڲ�FLASH������OLED���ܵ���*
 ******************************************************/
 
/*******************ͷ�ļ�����ʼ��*********************/
#include "stdio.h"
#include "main.h"
#include "usart.h"
#include "spi.h"
#include "oled.h"
#include "fmc_sdram.h"
/*******************ͷ�ļ���������*********************/

/*******************������������ʼ��*********************/
uint16_t *pdata_test;
uint16_t read_temp;
uint16_t ptest __attribute__ ((at(Bank5_SDRAM_ADDR+100)));
/*******************����������������*********************/

/*******************��������ʼ��*********************/
/**  
 * @brief         ������
 * @retval        int
 * @return		  ��
 * @note          ��
 */
int main(void)
{
    /********Ӳ����ʼ������ʼ��********/
    SystemClock_Config();
    USART_InitConfig();     /**< USART1��ʼ������ */
    SPI_InitConfig();       /**< SPI5��ʼ������ */
//    OLED_Init();            /**< OLED��ʼ������ */
    SDRAM_Init();           /**< SDRAM��ʼ������ */
    HAL_Delay(100);
    printf("[   INFO] main.c : ���Ǵ��ڻ���ʵ��\r\n");
    /********Ӳ����ʼ����������********/
  
    
//    printf("*********SPI-OLED-EXAMPLE-BEGIN********** \r\n");       /**< ������ʾ */
//    OLED_ShowString(10,24, "0.96 oled show",16);  
//    printf("[  main]info : oled show string: 0.96 oled show \r\n");
//	  OLED_Refresh_Gram();//������ʾ��OLED
//    printf("*********SPI-OLED-EXAMPLE-END********** \r\n\r\n");
    
    //< ʹ��ָ�����SDRAM���ݣ�д��
    *(uint16_t *)(Bank5_SDRAM_ADDR) = 0XF55;    /**< ��ַǿ��ת����16λ��ָ�룬�ٽ���ȡֵ���� */
    
    //< ʹ��ָ�����SDRAM���ݣ�����
    read_temp = *(uint16_t *)(Bank5_SDRAM_ADDR);
    ptest = 0XAA;
    printf("[   INFO] main.c : ����������read_temp-->0x%x \r\n", read_temp);
    printf("[   INFO] main.c : ����������ptest-->0x%x \r\n \r\n", ptest);
    
    while(1)
    {
         
    }
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 15;
  RCC_OscInitStruct.PLL.PLLN = 216;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
//    Error_Handler();
  }
  /** Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
//    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
//    Error_Handler();
  }
}


/*******************������������*********************/

