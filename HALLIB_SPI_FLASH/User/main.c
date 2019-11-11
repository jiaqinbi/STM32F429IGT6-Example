
/******************************************************
 *  @brief  	����ļ�                              *              
 *  @file   	main.c                                *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��10��31��                        *
 *  @note       ʵ����ͨ��SPI��д�ڲ�FLASH�Ĺ��ܵĵ���*
 ******************************************************/
 
/*******************ͷ�ļ�����ʼ��*********************/
#include "main.h"
#include "usart.h"
#include "spi.h"
#include "flash_w25q256.h"
#include "stdio.h"
/*******************ͷ�ļ���������*********************/

/*******************������������ʼ��*********************/
uint16_t DeviceID;
uint32_t JedecID;
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
    USART_InitConfig();     /**< USART1��ʼ������ */
    SPI_InitConfig();       /**< SPI5��ʼ������ */
    FLASH_InitConfig();     /**< FLASH_W25Q256��ʼ������ */
    /********Ӳ����ʼ����������********/
  
    printf("*********SPI-EXAMPLE********** \r\n");       /**< ������ʾ */
    
    while(1)
    {
         DeviceID = W25Q256_READ_DeviceID();
         JedecID = W25Q256_READ_JedecID();
         printf("[  main]info : W25Q256_DeviceID: %x \r\n", DeviceID);       /**< ���*/
         printf("[  main]info : W25Q256_JedecID: %x \r\n", JedecID);
         HAL_Delay(100);
    }
}
/*******************������������*********************/

