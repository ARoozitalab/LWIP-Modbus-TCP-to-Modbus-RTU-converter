/****************************************Copyright (c)**************************************************                         
** Created date:		2010-10-29
** Version:				1.0
** Descriptions:		The original version
**
**------------------------------------------------------------------------------------------------------
** Modified by:			
** Modified date:	
** Version:
** Descriptions:		
********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "SST25VF016B.h"
#include "FlashDriver.h"

/* Private variables ---------------------------------------------------------*/
static uint32_t CurReadAddr;	/* 当前读的地址 */
static uint32_t CurWriteAddr;	/* 当前写页地址	*/

/*******************************************************************************
* Function Name  : df_read_open
* Description    : 读初始化功能函数
* Input          : - addr: 打开后读到的初始地址
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_read_open(uint32_t addr)
{
  CurReadAddr=addr;	/* 当前读的地址	*/
}


/*******************************************************************************
* Function Name  : df_write_open
* Description    : 写初始化功能函数
* Input          : - addr: 要写的初始地址
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_write_open(uint32_t addr)
{
CurWriteAddr=addr;	/* 当前写地址 */
}

/*******************************************************************************
* Function Name  : df_read
* Description    : 读FLASH函数
* Input          : - buf: 接受数据的指针
*                  - size: 读取数据的大小
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_read(uint8_t *buf,uint16_t size)
{
  if( CurReadAddr + size <= MAX_ADDR )
  {
    SSTF016B_RD(CurReadAddr,buf,size);
    CurReadAddr+=size;
  }
}

/*******************************************************************************
* Function Name  : df_write
* Description    : 写FLASH函数
* Input          : - buf: 写数据的指针
*                  - size: 要写数据的大小
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_write(uint8_t *buf,uint16_t size)
{
  if( CurWriteAddr + size <= MAX_ADDR )
  {
    SSTF016B_WR(CurWriteAddr,buf,size);
    CurWriteAddr+=size;
  }
}

/*******************************************************************************
* Function Name  : df_read_seek
* Description    : 调整读取FLASH的地址	
* Input          : - addr: 新的地址
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_read_seek(uint32_t addr)
{
 df_read_close();
 df_read_open(addr);
}

/*******************************************************************************
* Function Name  : df_write_seek
* Description    : 调整写FLASH的地址
* Input          : - addr: 新的地址
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_write_seek(uint32_t addr)
{
 df_write_close();
 df_write_open(addr); 
}

/*******************************************************************************
* Function Name  : df_read_close
* Description    : None
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_read_close(void)
{
 /* 此处不做任何处理 */
}

/*******************************************************************************
* Function Name  : df_write_close
* Description    : None
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_write_close(void)
{
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
