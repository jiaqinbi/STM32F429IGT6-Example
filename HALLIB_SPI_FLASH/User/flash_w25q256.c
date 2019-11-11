/******************************************************
 *  @brief  	FLASH初始化文件                       *              
 *  @file   	flash_w25q256.c                       *
 *  @author 	毕家钦                                *
 *  @version	v1.0                                  *
 *  @date  	    2019年10月31日                        *
 *  @note       实现了w25q256硬件初始化               *
 ******************************************************/

/*******************头文件【开始】*********************/
#include "flash_w25q256.h"
#include "spi.h"
/*******************头文件【结束】*********************/



/*******************函数【开始】*********************/
/**  
 * @brief         FLASH_W25Q256初始化
 * @retval        void
 * @return		  无
 * @note          无
 */
void FLASH_InitConfig(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOF_CLK_ENABLE();           /**< 使能GPIOF时钟 */	    
    
        /**W25Q256 GPIO引脚配置      
           PF6     ------> SPI5_SS
         */
    GPIO_Initure.Pin=GPIO_PIN_6;            
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  
    GPIO_Initure.Pull=GPIO_PULLUP;          
    GPIO_Initure.Speed=GPIO_SPEED_FAST;              
    HAL_GPIO_Init(GPIOF,&GPIO_Initure);     
    

}
/**  
 * @brief         读写一个字节
 * @retval        uint8_t
 * @param         TxData  写入的字节
 * @return		  Rxdata  读取的字节
 * @note          SPI支持全双工通信，发送立即接收
 */
uint8_t SPI5_ReadWriteByte(uint8_t TxData)
{
    uint8_t Rxdata;
    HAL_SPI_TransmitReceive(&hspi5,&TxData,&Rxdata,1, 1000);       
 	return Rxdata;          		
}


/**  
 * @brief         读取芯片ID  FLASH芯片型号为W25Q256的ID为0XEF18
 * @retval        uint16_t
 * @return		  Temp  读取的设备ID
 * @note          软件NSS需要软件来拉高或拉低片选线
 */
uint16_t W25Q256_READ_DeviceID(void)
{
	uint16_t Temp = 0;	  
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_6,GPIO_PIN_RESET); 	/**< 片選拉低 */	    
	SPI5_ReadWriteByte(0x90);	                            /**< Dummy随便写什么都行 */
	SPI5_ReadWriteByte(0x90); 	                            /**< Dummy随便写什么都行 */
	SPI5_ReadWriteByte(0x90); 	                            /**< Dummy随便写什么都行 */
	SPI5_ReadWriteByte(0x00); 	 			                /**< 芯片手册中第4个写入的命令 */
	Temp|=SPI5_ReadWriteByte(0xFF)<<8;                      /**< 读取Dummy随便写什么都行 */  
	Temp|=SPI5_ReadWriteByte(0xFF);	                        /**< 读取Dummy随便写什么都行 */
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_6,GPIO_PIN_SET);       /**< 片選拉高 */		    
	return Temp;
}
/**  
 * @brief         读取芯片JEDECID  0XEF4096
 * @retval        uint16_t
 * @return		  Temp  JEDECID
 * @note          软件NSS需要软件来拉高或拉低片选线，JEDECID需要三个8位来接收
 */
uint32_t W25Q256_READ_JedecID(void)
{
    uint32_t Temp = 0;
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_6,GPIO_PIN_RESET);     /**< 片選拉低 */	   
	SPI5_ReadWriteByte(0x9f);                               /**< 写入读取JEDECID的命令 */   
	
	Temp|=SPI5_ReadWriteByte(0x9f)<<16;                     /**< 读取Dummy随便写什么都行 */    
	Temp|=SPI5_ReadWriteByte(0x9f)<<8;	                    /**< 读取Dummy随便写什么都行 */   
    Temp|=SPI5_ReadWriteByte(0x9f);                         /**< 读取Dummy随便写什么都行 */
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_6,GPIO_PIN_SET);       /**< 片選拉高 */ 			    
	return Temp;
}
/*******************函数【结束】*********************/


