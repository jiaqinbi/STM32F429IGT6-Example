
/******************************************************
 *  @brief  	入口文件                              *              
 *  @file   	main.c                                *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年11月14日                        *
 *  @note       实现SPI读写内部FLASH及驱动OLED功能调用*
 ******************************************************/
 
/*******************头文件【开始】*********************/
#include "stdio.h"
#include "main.h"
#include "usart.h"
#include "spi.h"
#include "oled.h"
#include "fmc_sdram.h"
/*******************头文件【结束】*********************/

/*******************变量声明【开始】*********************/
uint16_t *pdata_test;
uint16_t read_temp;
uint16_t ptest __attribute__ ((at(Bank5_SDRAM_ADDR+100)));
/*******************变量声明【结束】*********************/

/*******************函数【开始】*********************/
/**  
 * @brief         主函数
 * @retval        int
 * @return		  无
 * @note          无
 */
int main(void)
{
    /********硬件初始化【开始】********/
    SystemClock_Config();
    USART_InitConfig();     /**< USART1初始化配置 */
    SPI_InitConfig();       /**< SPI5初始化配置 */
//    OLED_Init();            /**< OLED初始化配置 */
    SDRAM_Init();           /**< SDRAM初始化配置 */
    HAL_Delay(100);
    printf("[   INFO] main.c : 这是串口回显实验\r\n");
    /********硬件初始化【结束】********/
  
    
//    printf("*********SPI-OLED-EXAMPLE-BEGIN********** \r\n");       /**< 运行提示 */
//    OLED_ShowString(10,24, "0.96 oled show",16);  
//    printf("[  main]info : oled show string: 0.96 oled show \r\n");
//	  OLED_Refresh_Gram();//更新显示到OLED
//    printf("*********SPI-OLED-EXAMPLE-END********** \r\n\r\n");
    
    //< 使用指针访问SDRAM数据，写入
    *(uint16_t *)(Bank5_SDRAM_ADDR) = 0XF55;    /**< 地址强制转换成16位的指针，再进行取值操作 */
    
    //< 使用指针访问SDRAM数据，读出
    read_temp = *(uint16_t *)(Bank5_SDRAM_ADDR);
    ptest = 0XAA;
    printf("[   INFO] main.c : 读出的数据read_temp-->0x%x \r\n", read_temp);
    printf("[   INFO] main.c : 读出的数据ptest-->0x%x \r\n \r\n", ptest);
    
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


/*******************函数【结束】*********************/

