/******************************************************
 *  @brief  	SPI��ʼ���ļ�                         *              
 *  @file   	oled.c                                *
 *  @author 	�ϼ���                                *
 *  @version	v1.0                                  *
 *  @date  	    2019��11��11��                        *
 *  @note       ʵ����oled���ܳ�ʼ���������ܺ����ı�д*
 ******************************************************/

/*******************ͷ�ļ�����ʼ��*********************/
#include "oled.h"
#include "spi.h"
#include "oledfont.h"
/*******************ͷ�ļ���������*********************/

uint8_t OLED_GRAM [128][8];	


/*******************��������ʼ��*********************/
 /**  
 * @brief         �����Դ浽LCD		
 * @retval        void
 * @return		  ��
 * @note          ��
 */
void OLED_Refresh_Gram(void)
{
	u8 i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    /**< ����ҳ��ַ��0~7�� */
		OLED_WR_Byte (0x00,OLED_CMD);      /**< ������ʾλ�á��е͵�ַ */
		OLED_WR_Byte (0x10,OLED_CMD);      /**< ������ʾλ�á��иߵ�ַ    */
		for(n=0;n<128;n++)OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA); 
	}   
}



 /**  
 * @brief         ��SSD1306д��һ���ֽ�	
 * @param1        dat:Ҫд�������/����
 * @param2        cmd:����/�����־ 0,��ʾ����;1,��ʾ����;
 * @retval        void
 * @return		  ��
 * @note          ��
 */
void OLED_WR_Byte(u8 dat,u8 cmd)
{	
    if(cmd == 1)
    {
        OLED_DC_Set();
        HAL_SPI_Transmit(&hspi1, &dat, 1, 1000);
        HAL_Delay(2);
    }
    else
    {
         OLED_DC_Clr();
         HAL_SPI_Transmit(&hspi1, &dat, 1, 1000);
         HAL_Delay(2);
    } 
} 

 /**  
 * @brief         ����OLED��ʾ 		
 * @retval        void
 * @return		  ��
 * @note          ��
 */
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  /**< SET DCDC���� */
	OLED_WR_Byte(0X14,OLED_CMD);  /**< DCDC ON */
	OLED_WR_Byte(0XAF,OLED_CMD);  /**< DISPLAY ON */
}
 /**  
 * @brief         �ر�OLED��ʾ 		
 * @retval        void
 * @return		  ��
 * @note          ��
 */   
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  /**< SET DCDC���� */
	OLED_WR_Byte(0X10,OLED_CMD);  /**< DCDC OFF */
	OLED_WR_Byte(0XAE,OLED_CMD);  /**< DISPLAY OFF */
}		   			 
 /**  
 * @brief         ������������ 		
 * @retval        void
 * @return		  ��
 * @note          ��
 */
void OLED_Clear(void)  
{  
	u8 i,n;  
	for(i=0;i<8;i++)for(n=0;n<128;n++)OLED_GRAM[n][i]=0X00;  
	OLED_Refresh_Gram();            /**< ������ʾ */
}


 /**  
 * @brief         ����		
 * @param1        x:0~127
 * @param2        y:0~63
 * @param3        t:1 ��� 0,���		
 * @retval        void
 * @return		  ��
 * @note          ��
 */		   
void OLED_DrawPoint(u8 x,u8 y,u8 t)
{
	u8 pos,bx,temp=0;
	if(x>127||y>63)return;          /**< ������Χ */
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)OLED_GRAM[x][pos]|=temp;
	else OLED_GRAM[x][pos]&=~temp;	    
}

 /**  
 * @brief         ����		
 * @param         x1,y1,x2,y2: �������ĶԽ�����
                  dot:0,���;1,���
 * @retval        void
 * @return		  ��
 * @note          ȷ��x1<=x2;y1<=y2 0<=x1<=127 0<=y1<=63
 */	  
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot)  
{  
	u8 x,y;  
	for(x=x1;x<=x2;x++)
	{
		for(y=y1;y<=y2;y++)OLED_DrawPoint(x,y,dot);
	}													    
	OLED_Refresh_Gram();                    /**< ������ʾ */
}


 /**  
 * @brief         ��ָ��λ����ʾһ���ַ�,���������ַ�		
 * @param         x1,y1,x2,y2: �������ĶԽ�����
                  mode: 0,������ʾ;1,������ʾ
                  size: ѡ������ 12/16/24
 * @retval        void
 * @return		  ��
 * @note          x:0~127   y:0~63
 */	
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode)
{      			    
	u8 temp,t,t1;
	u8 y0=y;
	u8 csize=(size/8+((size%8)?1:0))*(size/2);		/**< �õ�����һ���ַ���Ӧ������ռ���ֽ��� */
	chr=chr-' ';                                    /**< �õ�ƫ�ƺ��ֵ */
    for(t=0;t<csize;t++)
    {   
		if(size==12)temp=asc2_1206[chr][t]; 	 	/**< ����1206���� */
		else if(size==16)temp=asc2_1608[chr][t];	/**< ����1608���� */
		else if(size==24)temp=asc2_2412[chr][t];	/**< ����2412���� */
		else return;								/**< û�е��ֿ� */
        for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				break;
			}
		}  	 
    }          
}

 /**  
 * @brief         //m^n����	
 * @retval        void
 * @return		  ��
 * @note          ��
 */ 
u32 mypow(u8 m,u8 n)
{
	u32 result=1;	 
	while(n--)result*=m;    
	return result;
}	

 /**  
 * @brief         ��ʾ2������
 * @param         x,y :�������	
                  len :���ֵ�λ��
                  size:�����С
                  mode:ģʽ	0,���ģʽ;1,����ģʽ
                  num:��ֵ(0~4294967295);	 	
 * @retval        void
 * @return		  ��
 * @note          x:0~127   y:0~63
 */	  
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size)
{         	
	u8 t,temp;
	u8 enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size/2)*t,y,' ',size,1);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size,1); 
	}
} 

 /**  
 * @brief         ��ʾ�ַ���
 * @param         x,y :�������	
                  len :���ֵ�λ��
                  *p:�ַ�����ʼ��ַ 	 	
                  size:�����С                 
 * @retval        void
 * @return		  ��
 * @note          x:0~127   y:0~63
 */	
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size)
{	
    while((*p<='~')&&(*p>=' '))     /**< �ж��ǲ��ǷǷ��ַ�! */
    {       
        if(x>(128-(size/2))){x=0;y+=size;}
        if(y>(64-size)){y=x=0;OLED_Clear();}
        OLED_ShowChar(x,y,*p,size,1);	 
        x+=size/2;
        p++;
    }  
	
}	


/**  
 * @brief         oled��ʼ��
 * @retval        void
 * @return		  ��
 * @note          ��
 */
void OLED_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = OLED_DC_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(OLED_DC_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = OLED_RST_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(OLED_RST_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = OLED_CS_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(OLED_CS_GPIO_Port, &GPIO_InitStruct);

        
        
    OLED_RST_Clr();
    HAL_Delay(100);
    OLED_RST_Set();
    OLED_WR_Byte(0xAE,OLED_CMD); /**< �ر���ʾ */
    OLED_WR_Byte(0xD5,OLED_CMD); /**< ����ʱ�ӷ�Ƶ����,��Ƶ�� */
    OLED_WR_Byte(80,OLED_CMD);   /**< [3:0],��Ƶ����;[7:4],��Ƶ�� */
    OLED_WR_Byte(0xA8,OLED_CMD); /**< ��������·�� */
    OLED_WR_Byte(0X3F,OLED_CMD); /**< Ĭ��0X3F(1/64) */
    OLED_WR_Byte(0xD3,OLED_CMD); /**< ������ʾƫ�� */
    OLED_WR_Byte(0X00,OLED_CMD); /**< Ĭ��Ϊ0 */
    OLED_WR_Byte(0x40,OLED_CMD); /**< ������ʾ��ʼ�� [5:0],����. */								    
    OLED_WR_Byte(0x8D,OLED_CMD); /**< ��ɱ����� */
    OLED_WR_Byte(0x14,OLED_CMD); /**< bit2������/�ر� */
    OLED_WR_Byte(0x20,OLED_CMD); /**< �����ڴ��ַģʽ */
    OLED_WR_Byte(0x02,OLED_CMD); /**< [1:0],00���е�ַģʽ;01���е�ַģʽ;10,ҳ��ַģʽ;Ĭ��10; */
    OLED_WR_Byte(0xA1,OLED_CMD); /**< ���ض�������,bit0:0,0->0;1,0->127; */
    OLED_WR_Byte(0xC0,OLED_CMD); /**< ����COMɨ�跽��;bit3:0,��ͨģʽ;1,�ض���ģʽ COM[N-1]->COM0;N:����·�� */
    OLED_WR_Byte(0xDA,OLED_CMD); /**< ����COMӲ���������� */
    OLED_WR_Byte(0x12,OLED_CMD); /**< [5:4]���� */
    OLED_WR_Byte(0x81,OLED_CMD); /**< �Աȶ����� */
    OLED_WR_Byte(0xEF,OLED_CMD); /**< 1~255;Ĭ��0X7F (��������,Խ��Խ��) */
    OLED_WR_Byte(0xD9,OLED_CMD); /**< ����Ԥ������� */
    OLED_WR_Byte(0xf1,OLED_CMD); /**< [3:0],PHASE 1;[7:4],PHASE 2; */
    OLED_WR_Byte(0xDB,OLED_CMD); /**< ����VCOMH ��ѹ���� */
    OLED_WR_Byte(0x30,OLED_CMD); /**< [6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc; */
    OLED_WR_Byte(0xA4,OLED_CMD); /**< ȫ����ʾ����;bit0:1,����;0,�ر�;(����/����) */
    OLED_WR_Byte(0xA6,OLED_CMD); /**< ������ʾ��ʽ;bit0:1,������ʾ;0,������ʾ */	    						   
    OLED_WR_Byte(0xAF,OLED_CMD); /**< ������ʾ */	 
}
/*******************������������*********************/

