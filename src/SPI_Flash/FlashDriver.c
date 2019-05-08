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
static uint32_t CurReadAddr;	/* ��ǰ���ĵ�ַ */
static uint32_t CurWriteAddr;	/* ��ǰдҳ��ַ	*/

/*******************************************************************************
* Function Name  : df_read_open
* Description    : ����ʼ�����ܺ���
* Input          : - addr: �򿪺�����ĳ�ʼ��ַ
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_read_open(uint32_t addr)
{
  CurReadAddr=addr;	/* ��ǰ���ĵ�ַ	*/
}


/*******************************************************************************
* Function Name  : df_write_open
* Description    : д��ʼ�����ܺ���
* Input          : - addr: Ҫд�ĳ�ʼ��ַ
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void df_write_open(uint32_t addr)
{
CurWriteAddr=addr;	/* ��ǰд��ַ */
}

/*******************************************************************************
* Function Name  : df_read
* Description    : ��FLASH����
* Input          : - buf: �������ݵ�ָ��
*                  - size: ��ȡ���ݵĴ�С
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
* Description    : дFLASH����
* Input          : - buf: д���ݵ�ָ��
*                  - size: Ҫд���ݵĴ�С
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
* Description    : ������ȡFLASH�ĵ�ַ	
* Input          : - addr: �µĵ�ַ
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
* Description    : ����дFLASH�ĵ�ַ
* Input          : - addr: �µĵ�ַ
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
 /* �˴������κδ��� */
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
