#ifndef __OLED__H
#define __OLED__H

/*******************头文件包含【开始】*********************/
#include "main.h"
/*******************头文件包含【结束】*********************/

/*******************宏定义【开始】*********************/
#define OLED_DC_Pin GPIO_PIN_2
#define OLED_DC_GPIO_Port GPIOE     /**< DC 接PE2  命令/数据标志（写0—命令/写1—数据） */

#define OLED_RST_Pin GPIO_PIN_4
#define OLED_RST_GPIO_Port GPIOA    /**< RST  接PA4   硬复位 OLED */

#define LCD_SCK_Pin GPIO_PIN_5
#define LCD_SCK_GPIO_Port GPIOA     /**< D0   接PA5  (SPI1_SCK===>LCD_SCK)   串行时钟线 */

#define LCD_MISO_Pin GPIO_PIN_6
#define LCD_MISO_GPIO_Port GPIOA    /**< PA6   MISO */

#define LCD_MOSI_Pin GPIO_PIN_7
#define LCD_MOSI_GPIO_Port GPIOA    /**< D1   接PA7  (SPI1_MOSI===>LCD_MOSI) 串行数据线 */

#define OLED_CS_Pin GPIO_PIN_2
#define OLED_CS_GPIO_Port GPIOB      /**< CS   接PB2   OLED片选信号 */

#define OLED_CS_Set()       HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_SET);
#define OLED_CS_Clr()       HAL_GPIO_WritePin(OLED_CS_GPIO_Port, OLED_CS_Pin, GPIO_PIN_RESET);

#define OLED_DC_Set()       HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_SET);
#define OLED_DC_Clr()       HAL_GPIO_WritePin(OLED_DC_GPIO_Port, OLED_DC_Pin, GPIO_PIN_RESET);

#define OLED_RST_Set()      HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_SET);
#define OLED_RST_Clr()      HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_RESET);

#define typedef u8  uint8_t

/********根据数据手册提供对应的宏定义【开始】********/
#define	BRIGHTNESS	            0xCF			/**< 亮度 */
#define X_WIDTH                 128				/**< 宽度 */
#define Y_WIDTH                 64				/**< 长度 */
#define	PAGE			        8			    /**< 页数 */
#define	MAX_CHAR_POSX           X_WIDTH-6       /**< 字符宽度需要-6 */
#define	MAX_CHAR_POSY           Y_WIDTH-6       /**< 字符长度需要-6 */

#define OLED_CMD  	            0		        /**< 写命令 */
#define OLED_DATA 	            1		        /**< 写数据 */
/********根据数据手册提供对应的宏定义【结束】********/
/*******************宏定义【结束】*********************/

/*******************函数声明【开始】*********************/
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
/*******************函数声明【结束】*********************/

#endif //__OLED__H
