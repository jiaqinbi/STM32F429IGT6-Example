一、名称：SPI读写W25Q256实验
二、描述：通过写入命令读取W25Q256的ID,然后通过命令输出
三、引脚配置：
		PF6     ------> SPI5_SS
		PF7     ------> SPI5_SCK
        PF8     ------> SPI5_MISO
        PF9     ------> SPI5_MOSI 
四、相关函数：
	1、HAL_SPI_Init();
	2、HAL_SPI_MspInit();
	3、HAL_SPI_Transmit();
	4、HAL_SPI_Receive();
	5、HAL_SPI_TransmitReceive();
五、注意：在stm32f4xx_hal_conf.h文件中取消#define HAL_SPI_MODULE_ENABLED的注释