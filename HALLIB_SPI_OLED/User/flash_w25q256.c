/******************************************************
 *  @brief  	FLASH��ʼ���ļ�                       *              
 *  @file   	flash_w25q256.c                       *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��10��31��                        *
 *  @note       ʵ����w25q256Ӳ����ʼ��               *
 ******************************************************/

/*******************ͷ�ļ�����ʼ��*********************/
#include "flash_w25q256.h"
#include "spi.h"
/*******************ͷ�ļ���������*********************/



/*******************��������ʼ��*********************/
/**  
 * @brief         FLASH_W25Q256��ʼ��
 * @retval        void
 * @return		  ��
 * @note          ��
 */
void FLASH_InitConfig(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    
    __HAL_RCC_GPIOF_CLK_ENABLE();           /**< ʹ��GPIOFʱ�� */	    
    
        /**W25Q256 GPIO��������      
           PF6     ------> SPI5_SS
         */
    GPIO_Initure.Pin=GPIO_PIN_6;            
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  
    GPIO_Initure.Pull=GPIO_PULLUP;          
    GPIO_Initure.Speed=GPIO_SPEED_FAST;              
    HAL_GPIO_Init(GPIOF,&GPIO_Initure);     
    

}
/**  
 * @brief         ��дһ���ֽ�
 * @retval        uint8_t
 * @param         TxData  д����ֽ�
 * @return		  Rxdata  ��ȡ���ֽ�
 * @note          SPI֧��ȫ˫��ͨ�ţ�������������
 */
uint8_t SPI5_ReadWriteByte(uint8_t TxData)
{
    uint8_t Rxdata;
    HAL_SPI_TransmitReceive(&hspi5,&TxData,&Rxdata,1, 1000);       
 	return Rxdata;          		
}


/**  
 * @brief         ��ȡоƬID  FLASHоƬ�ͺ�ΪW25Q256��IDΪ0XEF18
 * @retval        uint16_t
 * @return		  Temp  ��ȡ���豸ID
 * @note          ���NSS��Ҫ��������߻�����Ƭѡ��
 */
uint16_t W25Q256_READ_DeviceID(void)
{
	uint16_t Temp = 0;	  
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_6,GPIO_PIN_RESET); 	/**< Ƭ�x���� */	    
	SPI5_ReadWriteByte(0x90);	                            /**< Dummy���дʲô���� */
	SPI5_ReadWriteByte(0x90); 	                            /**< Dummy���дʲô���� */
	SPI5_ReadWriteByte(0x90); 	                            /**< Dummy���дʲô���� */
	SPI5_ReadWriteByte(0x00); 	 			                /**< оƬ�ֲ��е�4��д������� */
	Temp|=SPI5_ReadWriteByte(0xFF)<<8;                      /**< ��ȡDummy���дʲô���� */  
	Temp|=SPI5_ReadWriteByte(0xFF);	                        /**< ��ȡDummy���дʲô���� */
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_6,GPIO_PIN_SET);       /**< Ƭ�x���� */		    
	return Temp;
}
/**  
 * @brief         ��ȡоƬJEDECID  0XEF4096
 * @retval        uint16_t
 * @return		  Temp  JEDECID
 * @note          ���NSS��Ҫ��������߻�����Ƭѡ�ߣ�JEDECID��Ҫ����8λ������
 */
uint32_t W25Q256_READ_JedecID(void)
{
    uint32_t Temp = 0;
    HAL_GPIO_WritePin(GPIOF,GPIO_PIN_6,GPIO_PIN_RESET);     /**< Ƭ�x���� */	   
	SPI5_ReadWriteByte(0x9f);                               /**< д���ȡJEDECID������ */   
	
	Temp|=SPI5_ReadWriteByte(0x9f)<<16;                     /**< ��ȡDummy���дʲô���� */    
	Temp|=SPI5_ReadWriteByte(0x9f)<<8;	                    /**< ��ȡDummy���дʲô���� */   
    Temp|=SPI5_ReadWriteByte(0x9f);                         /**< ��ȡDummy���дʲô���� */
	HAL_GPIO_WritePin(GPIOF,GPIO_PIN_6,GPIO_PIN_SET);       /**< Ƭ�x���� */ 			    
	return Temp;
}
/*******************������������*********************/


