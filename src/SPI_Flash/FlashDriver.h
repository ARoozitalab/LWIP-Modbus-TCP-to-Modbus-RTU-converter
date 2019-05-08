/****************************************Copyright (c)**************************************************
**
**                                 http://www.powermcu.com
**
**--------------File Info-------------------------------------------------------------------------------
** File Name: 			FlashDriver.h
** Last modified Date: 	2010-10-29
** Last Version: 		1.0
** Descriptions: 		SPI flash ¹¦ÄÜº¯Êý
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
#ifndef __FLASHDRIVER_H 
#define __FLASHDRIVER_H 

#ifdef __cplusplus
 extern "C" {
#endif 
/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Private function prototypes -----------------------------------------------*/
void df_read_open(uint32_t addr);
void df_write_open(uint32_t addr);
void df_read(uint8_t *buf,uint16_t size);
void df_write(uint8_t *buf,uint16_t size);
void df_read_seek(uint32_t addr);
void df_write_seek(uint32_t addr);
void df_read_close(void);
void df_write_close(void);
#ifdef __cplusplus
}
#endif
#endif 
/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

