
/******************************************************
 *  @brief  	入口文件                              *              
 *  @file   	main.c                                *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年10月31日                        *
 *  @note       实现了通过SPI读写内部FLASH的功能的调用*
 ******************************************************/
 
/*******************头文件【开始】*********************/
#include "main.h"
#include "usart.h"
#include "spi.h"
#include "flash_w25q256.h"
#include "stdio.h"
/*******************头文件【结束】*********************/

/*******************变量声明【开始】*********************/
uint16_t DeviceID;
uint32_t JedecID;
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
    USART_InitConfig();     /**< USART1初始化配置 */
    SPI_InitConfig();       /**< SPI5初始化配置 */
    FLASH_InitConfig();     /**< FLASH_W25Q256初始化配置 */
    /********硬件初始化【结束】********/
  
    printf("*********SPI-EXAMPLE********** \r\n");       /**< 运行提示 */
    
    while(1)
    {
         DeviceID = W25Q256_READ_DeviceID();
         JedecID = W25Q256_READ_JedecID();
         printf("[  main]info : W25Q256_DeviceID: %x \r\n", DeviceID);       /**< 输出*/
         printf("[  main]info : W25Q256_JedecID: %x \r\n", JedecID);
         HAL_Delay(100);
    }
}
/*******************函数【结束】*********************/

