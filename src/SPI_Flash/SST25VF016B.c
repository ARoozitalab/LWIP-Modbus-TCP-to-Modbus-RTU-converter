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

/* ��ֲ�������ʱ��Ҫ�޸����µĺ������ */

/*******************************************************************************
* Function Name  : SPI_FLASH_Init
* Description    : ��ʼ������SSI�Ĺܽ�
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void SPI_FLASH_Init(void)
{
  SPI_InitTypeDef  SPI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3, ENABLE); 
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE); 
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 

	
			GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_SPI3);
		GPIO_PinAFConfig(GPIOC, GPIO_PinSource12, GPIO_AF_SPI3);
	
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12;
	   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
								  
  GPIO_InitStructure.GPIO_Pin = SPI_FALSH_CS_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(SPI_FALSH_CS_PORT, &GPIO_InitStructure);

  SPI_FLASH_CS_HIGH();
  /* SPI1 Config -------------------------------------------------------------*/ 								  
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low; 
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge; 
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
  SPI_InitStructure.SPI_CRCPolynomial = 7;
  SPI_Init(SPI3, &SPI_InitStructure);
  /* Enable SPI1 */ 
  SPI_Cmd(SPI3, ENABLE); 
}


/*******************************************************************************
* Function Name  : Flash_ReadWriteByte
* Description    : ͨ��Ӳ��SPI����һ���ֽڵ�SST25VF016B
* Input          : - data: ���͵�����
* Output         : None
* Return         : SST25VF016B ���ص�����
* Attention		 : None
*******************************************************************************/
uint8_t Flash_ReadWriteByte(uint8_t data)		
{
  /* Loop while DR register in not emplty */
  while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE) == RESET);

  /* Send byte through the SPI1 peripheral */
  SPI_I2S_SendData(SPI3, data);
    
  /* Wait to receive a byte */
  while (SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE) == RESET);

  /* Return the byte read from the SPI bus */
  return SPI_I2S_ReceiveData(SPI3);                                              
}


/* ���º�������ֲʱ�����޸� */
/*******************************************************************************
* Function Name  : SSTF016B_RD
* Description    : SST25VF016B�Ķ�����,��ѡ���ID�Ͷ����ݲ���
* Input          : - Dst: Ŀ���ַ,��Χ 0x0 - MAX_ADDR��MAX_ADDR = 0x1FFFFF��
*                  - RcvBufPt: ���ջ����ָ��
*                  - NByte: Ҫ��ȡ�������ֽ���	
* Output         : �����ɹ��򷵻�OK,ʧ���򷵻�ERROR
* Return         : SST25VF016B ���ص�����
* Attention		 : ��ĳ������,ĳһ��ڲ�����Ч,���ڸ���ڲ�������Invalid���ò�����������
*******************************************************************************/
uint8_t SSTF016B_RD(uint32_t Dst, uint8_t* RcvBufPt ,uint32_t NByte)
{
	uint32_t i = 0;
	if ((Dst+NByte > MAX_ADDR)||(NByte == 0))	return (ERROR);	 /*	�����ڲ��� */
	
    SPI_FLASH_CS_LOW();
	Flash_ReadWriteByte(0x0B); 						/* ���Ͷ����� */
	Flash_ReadWriteByte(((Dst & 0xFFFFFF) >> 16));	/* ���͵�ַ��Ϣ:�õ�ַ��3���ֽ����	*/
	Flash_ReadWriteByte(((Dst & 0xFFFF) >> 8));
	Flash_ReadWriteByte(Dst & 0xFF);
	Flash_ReadWriteByte(0xFF);						/* ����һ�����ֽ��Զ�ȡ����	*/
	for (i = 0; i < NByte; i++)		
	{
       RcvBufPt[i] = Flash_ReadWriteByte(0xFF);		
	}
    SPI_FLASH_CS_HIGH();
	return (ENABLE);
}

/*******************************************************************************
* Function Name  : SSTF016B_RdID
* Description    : SST25VF016B�Ķ�ID����,��ѡ���ID�Ͷ����ݲ���
* Input          : - IDType: ID���͡��û�����Jedec_ID,Dev_ID,Manu_ID������ѡ��
* Output         : - RcvbufPt: �洢ID������ָ��
* Return         : �����ɹ��򷵻�OK,ʧ���򷵻�ERROR
* Attention		 : ������Ĳ���������Ҫ���򷵻�ERROR
*******************************************************************************/
uint8_t SSTF016B_RdID(idtype IDType,uint32_t* RcvbufPt)
{
	uint32_t temp = 0;
              
	if (IDType == Jedec_ID)
	{
		SPI_FLASH_CS_LOW();	
				
		Flash_ReadWriteByte(0x9F);		 		         /* ���Ͷ�JEDEC ID����(9Fh)	*/
    	        
        temp = (temp | Flash_ReadWriteByte(0x00)) << 8;  /* �������� */
	    	temp = (temp | Flash_ReadWriteByte(0x00)) << 8;	
        temp = (temp | Flash_ReadWriteByte(0x00)); 	     /* �ڱ�����,temp��ֵӦΪ0xBF2541 */
        SPI_FLASH_CS_HIGH();

		*RcvbufPt = temp;
		return (ENABLE);
	}
	
	if ((IDType == Manu_ID) || (IDType == Dev_ID) )
	{
	    SPI_FLASH_CS_LOW();	
		
		Flash_ReadWriteByte(0x90);				/* ���Ͷ�ID���� (90h or ABh) */
    	Flash_ReadWriteByte(0x00);				/* ���͵�ַ	*/
		Flash_ReadWriteByte(0x00);				/* ���͵�ַ	*/
		Flash_ReadWriteByte(IDType);		    /* ���͵�ַ - ����00H����01H */
		temp = Flash_ReadWriteByte(0x00);	    /* ���ջ�ȡ�������ֽ� */

        SPI_FLASH_CS_HIGH();

		*RcvbufPt = temp;
		return (ENABLE);
	}
	else
	{
		return (ERROR);	
	}
}


/*******************************************************************************
* Function Name  : SSTF016B_WR
* Description    : SST25VF016B��д��������д1���Ͷ�����ݵ�ָ����ַ
* Input          : - Dst: Ŀ���ַ,��Χ 0x0 - MAX_ADDR��MAX_ADDR = 0x1FFFFF��
*                  - SndbufPt: ���ͻ�����ָ��
*                  - NByte: Ҫд�������ֽ���
* Output         : None
* Return         : �����ɹ��򷵻�OK,ʧ���򷵻�ERROR
* Attention		 : ��ĳ������,ĳһ��ڲ�����Ч,���ڸ���ڲ�������Invalid���ò�����������
*******************************************************************************/
uint8_t SSTF016B_WR(uint32_t Dst, uint8_t* SndbufPt,uint32_t NByte)
{
	uint8_t temp = 0,StatRgVal = 0;
	uint32_t i = 0;
	if (( (Dst+NByte-1 > MAX_ADDR)||(NByte == 0) ))
	{
		return (ERROR);	 /*	�����ڲ��� */
	}

	
	SPI_FLASH_CS_LOW();				 
	Flash_ReadWriteByte(0x05);							    /* ���Ͷ�״̬�Ĵ�������	*/
	temp = Flash_ReadWriteByte(0xFF);					    /* ������õ�״̬�Ĵ���ֵ */
	temp =(temp<<8)|Flash_ReadWriteByte(0xFF);	
	SPI_FLASH_CS_HIGH();								

	SPI_FLASH_CS_LOW();				
	Flash_ReadWriteByte(0x50);							    /* ʹ״̬�Ĵ�����д	*/
	SPI_FLASH_CS_HIGH();	
		
	SPI_FLASH_CS_LOW();				
	Flash_ReadWriteByte(0x01);							    /* ����д״̬�Ĵ���ָ�� */
	Flash_ReadWriteByte(2);								    /* ��0BPxλ��ʹFlashоƬȫ����д */
	Flash_ReadWriteByte(0);	
	SPI_FLASH_CS_HIGH();			
	

		do
		{
		  	SPI_FLASH_CS_LOW();					 
			Flash_ReadWriteByte(0x05);					 
			StatRgVal = Flash_ReadWriteByte(0xFF);		
			StatRgVal = (StatRgVal<<8)|Flash_ReadWriteByte(0xFF);
			SPI_FLASH_CS_HIGH();							
  		}
		while (StatRgVal != 0 );	
	
	
	
	for(i = 0; i < NByte; i++)
	{
		SPI_FLASH_CS_LOW();				
		Flash_ReadWriteByte(0x06);						    /* ����дʹ������ */
		SPI_FLASH_CS_HIGH();			

		SPI_FLASH_CS_LOW();					
		Flash_ReadWriteByte(0x02); 						    /* �����ֽ�������д����	*/
		Flash_ReadWriteByte((((Dst+i) & 0xFFFFFF) >> 16));  /* ����3���ֽڵĵ�ַ��Ϣ */
		Flash_ReadWriteByte((((Dst+i) & 0xFFFF) >> 8));
		Flash_ReadWriteByte((Dst+i) & 0xFF);
		Flash_ReadWriteByte(SndbufPt[i]);					/* ���ͱ���д������	*/
		SPI_FLASH_CS_HIGH();			

		do
		{
		  	SPI_FLASH_CS_LOW();					 
			Flash_ReadWriteByte(0x05);					    /* ���Ͷ�״̬�Ĵ������� */
			StatRgVal = Flash_ReadWriteByte(0xFF);			/* ������õ�״̬�Ĵ���ֵ */
			StatRgVal = (StatRgVal<<8)|Flash_ReadWriteByte(0xFF);
			SPI_FLASH_CS_HIGH();							
  		}
		while (StatRgVal == 0x03 );					          /* һֱ�ȴ���ֱ��оƬ����	*/

	}

//	SPI_FLASH_CS_LOW();					
//	Flash_ReadWriteByte(0x06);							    /* ����дʹ������ */
//	SPI_FLASH_CS_HIGH();			

	SPI_FLASH_CS_LOW();					
	Flash_ReadWriteByte(0x50);							    /* ʹ״̬�Ĵ�����д	*/
	SPI_FLASH_CS_HIGH();
			
	SPI_FLASH_CS_LOW();				
	Flash_ReadWriteByte(0x01);							    /* ����д״̬�Ĵ���ָ�� */
	Flash_ReadWriteByte(0);						     	/* �ָ�״̬�Ĵ���������Ϣ */
	Flash_ReadWriteByte(0);
	SPI_FLASH_CS_HIGH();
	return (ENABLE);		
}



/////////////////////////////////////////////writing data
void WR_prs(uint32_t Dst, uint8_t SndbufPt)
{
		uint8_t temp = 0,StatRgVal = 0;
	
		SPI_FLASH_CS_LOW();				
		Flash_ReadWriteByte(0x06);						    /* ����дʹ������ */
		SPI_FLASH_CS_HIGH();			

		SPI_FLASH_CS_LOW();					
		Flash_ReadWriteByte(0x02); 						    /* �����ֽ�������д����	*/
		Flash_ReadWriteByte((((Dst) & 0xFFFFFF) >> 16));  /* ����3���ֽڵĵ�ַ��Ϣ */
		Flash_ReadWriteByte((((Dst) & 0xFFFF) >> 8));
		Flash_ReadWriteByte((Dst) & 0xFF);
		Flash_ReadWriteByte(SndbufPt);					/* ���ͱ���д������	*/
		SPI_FLASH_CS_HIGH();			

		do
		{
		  	SPI_FLASH_CS_LOW();					 
			Flash_ReadWriteByte(0x05);					    /* ���Ͷ�״̬�Ĵ������� */
			StatRgVal = Flash_ReadWriteByte(0xFF);			/* ������õ�״̬�Ĵ���ֵ */
			StatRgVal = (StatRgVal<<8)|Flash_ReadWriteByte(0xFF);
			SPI_FLASH_CS_HIGH();							
  		}
		while (StatRgVal == 0x03 );					          /* һֱ�ȴ���ֱ��оƬ����	*/

	}



/////////////////////////////////////////////start writing data
void start_data_wirte()
{
	uint8_t temp = 0,StatRgVal = 0;
	uint32_t i = 0;

	
	SPI_FLASH_CS_LOW();				 
	Flash_ReadWriteByte(0x05);							    /* ���Ͷ�״̬�Ĵ�������	*/
	temp = Flash_ReadWriteByte(0xFF);					    /* ������õ�״̬�Ĵ���ֵ */
	temp =(temp<<8)|Flash_ReadWriteByte(0xFF);	
	SPI_FLASH_CS_HIGH();								

	SPI_FLASH_CS_LOW();				
	Flash_ReadWriteByte(0x50);							    /* ʹ״̬�Ĵ�����д	*/
	SPI_FLASH_CS_HIGH();	
		
	SPI_FLASH_CS_LOW();				
	Flash_ReadWriteByte(0x01);							    /* ����д״̬�Ĵ���ָ�� */
	Flash_ReadWriteByte(2);								    /* ��0BPxλ��ʹFlashоƬȫ����д */
	Flash_ReadWriteByte(0);	
	SPI_FLASH_CS_HIGH();			
	
			do
		{
		  SPI_FLASH_CS_LOW();					 
			Flash_ReadWriteByte(0x05);					 
			StatRgVal = Flash_ReadWriteByte(0xFF);		
			StatRgVal = (StatRgVal<<8)|Flash_ReadWriteByte(0xFF);
			SPI_FLASH_CS_HIGH();							
  		}
		while (StatRgVal != 0 );	
	
}









/////////////////////////////////////////////end writing data
void end_data_wirte()
{

	SPI_FLASH_CS_LOW();					
	Flash_ReadWriteByte(0x50);							    /* ʹ״̬�Ĵ�����д	*/
	SPI_FLASH_CS_HIGH();
			
	SPI_FLASH_CS_LOW();				
	Flash_ReadWriteByte(0x01);							    /* ����д״̬�Ĵ���ָ�� */
	Flash_ReadWriteByte(0);						     	/* �ָ�״̬�Ĵ���������Ϣ */
	Flash_ReadWriteByte(0);
	SPI_FLASH_CS_HIGH();
}



/*******************************************************************************
* Function Name  : SSTF016B_Erase
* Description    : ����ָ����������ѡȡ���Ч���㷨����
* Input          : - sec1: ��ʼ������,��Χ(0~511)
*                  - sec2: ��ֹ������,��Χ(0~511)
* Output         : None
* Return         : �����ɹ��򷵻�OK,ʧ���򷵻�ERROR
* Attention		 : None
*******************************************************************************/
uint8_t SSTF016B_Erase(uint32_t sec1, uint32_t sec2)
{
	uint8_t  temp1 = 0,temp2 = 0,StatRgVal = 0;
    uint32_t SecnHdAddr = 0;	  			
	uint32_t no_SecsToEr = 0;				   			    /* Ҫ������������Ŀ */
	uint32_t CurSecToEr = 0;	  						    /* ��ǰҪ������������ */
	
	/*  �����ڲ��� */
	if ((sec1 > SEC_MAX)||(sec2 > SEC_MAX))	
	{
		return (ERROR);	
	}
   	
   	SPI_FLASH_CS_LOW();			 
	Flash_ReadWriteByte(0x05);								/* ���Ͷ�״̬�Ĵ�������	*/
	temp1 = Flash_ReadWriteByte(0x00);						/* ������õ�״̬�Ĵ���ֵ */
	SPI_FLASH_CS_HIGH();								

	SPI_FLASH_CS_LOW();			
	Flash_ReadWriteByte(0x50);								/* ʹ״̬�Ĵ�����д	*/
	SPI_FLASH_CS_HIGH();			

	SPI_FLASH_CS_LOW();								  	
	Flash_ReadWriteByte(0x01);								/* ����д״̬�Ĵ���ָ��	*/
	Flash_ReadWriteByte(0);									/* ��0BPxλ��ʹFlashоƬȫ����д */
	SPI_FLASH_CS_HIGH();
	
	SPI_FLASH_CS_LOW();			
	Flash_ReadWriteByte(0x06);								/* ����дʹ������ */
	SPI_FLASH_CS_HIGH();			

	/* ����û��������ʼ�����Ŵ�����ֹ�����ţ������ڲ��������� */
	if (sec1 > sec2)
	{
	   temp2 = sec1;
	   sec1  = sec2;
	   sec2  = temp2;
	} 
	/* ����ֹ���������������������� */
	if (sec1 == sec2)	
	{
		SPI_FLASH_CS_LOW();				
		Flash_ReadWriteByte(0x06);						    /* ����дʹ������ */
		SPI_FLASH_CS_HIGH();			

	    SecnHdAddr = SEC_SIZE * sec1;				          /* ������������ʼ��ַ	*/
	    SPI_FLASH_CS_LOW();	
    	Flash_ReadWriteByte(0x20);							  /* ������������ָ�� */
	    Flash_ReadWriteByte(((SecnHdAddr & 0xFFFFFF) >> 16)); /* ����3���ֽڵĵ�ַ��Ϣ */
   		Flash_ReadWriteByte(((SecnHdAddr & 0xFFFF) >> 8));
   		Flash_ReadWriteByte(SecnHdAddr & 0xFF);
  		SPI_FLASH_CS_HIGH();			
		do
		{
		  	SPI_FLASH_CS_LOW();			 
			Flash_ReadWriteByte(0x05);						  /* ���Ͷ�״̬�Ĵ������� */
			StatRgVal = Flash_ReadWriteByte(0x00);			  /* ������õ�״̬�Ĵ���ֵ	*/
			SPI_FLASH_CS_HIGH();								
  		}
		while (StatRgVal == 0x03);				              /* һֱ�ȴ���ֱ��оƬ����	*/
		return (ENABLE);			
	}
	
    /* ������ʼ��������ֹ��������������ٵĲ������� */	
	
	if (sec2 - sec1 == SEC_MAX)	
	{
		SPI_FLASH_CS_LOW();			
		Flash_ReadWriteByte(0x60);							  /* ����оƬ����ָ��(60h or C7h) */
		SPI_FLASH_CS_HIGH();			
		do
		{
		  	SPI_FLASH_CS_LOW();			 
			Flash_ReadWriteByte(0x05);						  /* ���Ͷ�״̬�Ĵ������� */
			StatRgVal = Flash_ReadWriteByte(0x00);			  /* ������õ�״̬�Ĵ���ֵ	*/
			SPI_FLASH_CS_HIGH();								
  		}
		while (StatRgVal == 0x03);					          /* һֱ�ȴ���ֱ��оƬ����	*/
   		return (ENABLE);
	}
	
	no_SecsToEr = sec2 - sec1 +1;					          /* ��ȡҪ������������Ŀ */
	CurSecToEr  = sec1;								          /* ����ʼ������ʼ����	*/
	
	/* ����������֮��ļ���������ȡ8���������㷨 */
	while (no_SecsToEr >= 8)
	{
		SPI_FLASH_CS_LOW();				
		Flash_ReadWriteByte(0x06);						    /* ����дʹ������ */
		SPI_FLASH_CS_HIGH();			

	    SecnHdAddr = SEC_SIZE * CurSecToEr;			          /* ������������ʼ��ַ */
	    SPI_FLASH_CS_LOW();	
	    Flash_ReadWriteByte(0x52);							  /* ����32KB����ָ�� */
	    Flash_ReadWriteByte(((SecnHdAddr & 0xFFFFFF) >> 16)); /* ����3���ֽڵĵ�ַ��Ϣ */
   		Flash_ReadWriteByte(((SecnHdAddr & 0xFFFF) >> 8));
   		Flash_ReadWriteByte(SecnHdAddr & 0xFF);
  		SPI_FLASH_CS_HIGH();			
		do
		{
		  	SPI_FLASH_CS_LOW();			 
			Flash_ReadWriteByte(0x05);						  /* ���Ͷ�״̬�Ĵ������� */
			StatRgVal = Flash_ReadWriteByte(0x00);			  /* ������õ�״̬�Ĵ���ֵ	*/
			SPI_FLASH_CS_HIGH();								
  		}
		while (StatRgVal == 0x03);					          /* һֱ�ȴ���ֱ��оƬ����	*/
		CurSecToEr  += 8;
		no_SecsToEr -=  8;
	}
	/* �������������㷨����ʣ������� */
	while (no_SecsToEr >= 1)
	{
		SPI_FLASH_CS_LOW();				
		Flash_ReadWriteByte(0x06);						    /* ����дʹ������ */
		SPI_FLASH_CS_HIGH();			

	    SecnHdAddr = SEC_SIZE * CurSecToEr;			          /* ������������ʼ��ַ */
	    SPI_FLASH_CS_LOW();	
    	Flash_ReadWriteByte(0x20);							  /* ������������ָ�� */
	    Flash_ReadWriteByte(((SecnHdAddr & 0xFFFFFF) >> 16)); /* ����3���ֽڵĵ�ַ��Ϣ */
   		Flash_ReadWriteByte(((SecnHdAddr & 0xFFFF) >> 8));
   		Flash_ReadWriteByte(SecnHdAddr & 0xFF);
  		SPI_FLASH_CS_HIGH();			
		do
		{
		  	SPI_FLASH_CS_LOW();			 
			Flash_ReadWriteByte(0x05);						  /* ���Ͷ�״̬�Ĵ������� */
			StatRgVal = Flash_ReadWriteByte(0x00);			  /* ������õ�״̬�Ĵ���ֵ	*/
			SPI_FLASH_CS_HIGH();								
  		}
		while (StatRgVal == 0x03);					          /* һֱ�ȴ���ֱ��оƬ���� */
		CurSecToEr  += 1;
		no_SecsToEr -=  1;
	}
    /* ��������,�ָ�״̬�Ĵ�����Ϣ */
	SPI_FLASH_CS_LOW();			
	Flash_ReadWriteByte(0x06);								  /* ����дʹ������ */
	SPI_FLASH_CS_HIGH();			

	SPI_FLASH_CS_LOW();			
	Flash_ReadWriteByte(0x50);								  /* ʹ״̬�Ĵ�����д */
	SPI_FLASH_CS_HIGH();			
	SPI_FLASH_CS_LOW();			
	Flash_ReadWriteByte(0x01);								  /* ����д״̬�Ĵ���ָ�� */
	Flash_ReadWriteByte(temp1);								  /* �ָ�״̬�Ĵ���������Ϣ */
	SPI_FLASH_CS_HIGH();    
	return (ENABLE);
}


/*******************************************************************************
* Function Name  : SPI_FLASH_Test
* Description    : ��ȡSST25VF016B ID 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void SPI_FLASH_Test(void)
{
    uint32_t  ChipID = 0;
  	SSTF016B_RdID(Jedec_ID, &ChipID);                                   /*  �������е��˴�ʱ, ��Watch��	                                                                        �鿴ChipID��ֵ�Ƿ�0xBF2541  */
    ChipID &= ~0xff000000;						                        /*  ��������24λ����            */
	while (ChipID != 0xEF4017) {											/*  ID����ȷ������ѭ��          */
       	SSTF016B_RdID(Jedec_ID, &ChipID); 
				ChipID &= ~0xff000000;			
    }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/

