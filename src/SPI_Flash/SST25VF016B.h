/****************************************Copyright (c)**************************************************
**
**                                 http://www.powermcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File Name: 			SST25VF016B.h
** Last modified Date: 	2010-10-29
** Last Version: 		1.0
** Descriptions: 		SPI flash 操作函数 
**
**------------------------------------------------------------------------------------------------------
** Created 	 By: 		AVRman
** Created date: 		2010-10-29
** Version: 1.0
** Descriptions: 		First version
**
**------------------------------------------------------------------------------------------------------
** Modified by: 	
** Modified date: 	
** Version:
** Descriptions:  	
**
********************************************************************************************************/

#ifndef __SST25VF016B_H 
#define __SST25VF016B_H
#ifdef __cplusplus
 extern "C" {
#endif 
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Private typedef -----------------------------------------------------------*/
/* 定义操作SST25VF016B所需的数据 */
typedef enum ERTYPE{Sec1,Sec8,Sec16,Chip} ErType;  
typedef enum IDTYPE{Manu_ID,Dev_ID,Jedec_ID} idtype;

/* Private define ------------------------------------------------------------*/
#define MAX_ADDR		0x800000	/* 定义芯片内部最大地址 */
#define	SEC_MAX     	800         /* 定义最大扇区号 */
#define SEC_SIZE		0x1000      /* 扇区大小	*/

/* 宏,用于定义SST25VF016B的片选引脚 */
#define RCC_APB2Periph_GPIO_SPI_FLASH_CS      RCC_AHB1Periph_GPIOA
#define SPI_FALSH_CS_PORT                     GPIOA 
#define SPI_FALSH_CS_PIN                      GPIO_Pin_3

#define SPI_FLASH_CS_LOW()       GPIO_ResetBits(SPI_FALSH_CS_PORT, SPI_FALSH_CS_PIN)
#define SPI_FLASH_CS_HIGH()      GPIO_SetBits(SPI_FALSH_CS_PORT, SPI_FALSH_CS_PIN)

/* Private function prototypes -----------------------------------------------*/
void  SPI_FLASH_Init(void);
uint8_t SSTF016B_RD(uint32_t Dst, uint8_t* RcvBufPt ,uint32_t NByte);
uint8_t SSTF016B_RdID(idtype IDType,uint32_t* RcvbufPt);
uint8_t SSTF016B_WR(uint32_t Dst, uint8_t* SndbufPt,uint32_t NByte);
void WR_prs(uint32_t Dst, uint8_t SndbufPt);
void start_data_wirte();
void end_data_wirte();


uint8_t SSTF016B_Erase(uint32_t sec1, uint32_t sec2);
void SPI_FLASH_Test(void);
#ifdef __cplusplus
}
#endif

#endif
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

