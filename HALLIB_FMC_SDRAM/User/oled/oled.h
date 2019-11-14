#ifndef __OLED__H
#define __OLED__H

/*******************ͷ�ļ���������ʼ��*********************/
#include "main.h"
/*******************ͷ�ļ�������������*********************/

/*******************�궨�塾��ʼ��*********************/
#define OLED_DC_Pin GPIO_PIN_2
#define OLED_DC_GPIO_Port GPIOE     /**< DC ��PE2  ����/���ݱ�־��д0������/д1�����ݣ� */

#define OLED_RST_Pin GPIO_PIN_4
#define OLED_RST_GPIO_Port GPIOA    /**< RST  ��PA4   Ӳ��λ OLED */

#define LCD_SCK_Pin GPIO_PIN_5
#define LCD_SCK_GPIO_Port GPIOA     /**< D0   ��PA5  (SPI1_SCK===>LCD_SCK)   ����ʱ���� */

#define LCD_MISO_Pin GPIO_PIN_6
#define LCD_MISO_GPIO_Port GPIOA    /**< PA6   MISO */

#define LCD_MOSI_Pin GPIO_PIN_7
#define LCD_MOSI_GPIO_Port GPIOA    /**< D1   ��PA7  (SPI1_MOSI===>LCD_MOSI) ���������� */

#define OLED_CS_Pin GPIO_PIN_2
#define OLED_CS_GPIO_Port GPIOB      /**< CS   ��PB2   OLEDƬѡ�ź� */

#define OLED_CS_Set()       HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET);
#define OLED_CS_Clr()       HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);

#define OLED_DC_Set()       HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_SET);
#define OLED_DC_Clr()       HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_RESET);

#define OLED_RST_Set()      HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_SET);
#define OLED_RST_Clr()      HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_RESET);

#define typedef u8  uint8_t

/********���������ֲ��ṩ��Ӧ�ĺ궨�塾��ʼ��********/
#define	BRIGHTNESS	            0xCF			/**< ���� */
#define X_WIDTH                 128				/**< ��� */
#define Y_WIDTH                 64				/**< ���� */
#define	PAGE			        8			    /**< ҳ�� */
#define	MAX_CHAR_POSX           X_WIDTH-6       /**< �ַ������Ҫ-6 */
#define	MAX_CHAR_POSY           Y_WIDTH-6       /**< �ַ�������Ҫ-6 */

#define OLED_CMD  	            0		        /**< д���� */
#define OLED_DATA 	            1		        /**< д���� */
/********���������ֲ��ṩ��Ӧ�ĺ궨�塾������********/
/*******************�궨�塾������*********************/

/*******************������������ʼ��*********************/
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);		   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size);
/*******************����������������*********************/

#endif //__OLED__H
