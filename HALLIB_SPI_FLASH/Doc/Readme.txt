һ�����ƣ�SPI��дW25Q256ʵ��
����������ͨ��д�������ȡW25Q256��ID,Ȼ��ͨ���������
�����������ã�
		PF6     ------> SPI5_SS
		PF7     ------> SPI5_SCK
        PF8     ------> SPI5_MISO
        PF9     ------> SPI5_MOSI 
�ġ���غ�����
	1��HAL_SPI_Init();
	2��HAL_SPI_MspInit();
	3��HAL_SPI_Transmit();
	4��HAL_SPI_Receive();
	5��HAL_SPI_TransmitReceive();
�塢ע�⣺��stm32f4xx_hal_conf.h�ļ���ȡ��#define HAL_SPI_MODULE_ENABLED��ע��