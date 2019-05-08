/*********************************************************************************************************
*
* File                : modbustcp.c
* Hardware Environment: stm32f407 eval board "https://github.com/ARoozitalab/STM32F4-Eval-board"
* Version             : V1.0
* By                  : alireza roozitalab
* email               : alireza.roozitalab@gmail.com
* git user            : ARoozitalab
*                                                
*                                          All Rights Reserved
*
*********************************************************************************************************/
#include "main.h"
#include "modbustcp.h"
#include "modbus.h"
#include "stm32f4xx_it.h"
//-------------------------------------variable
extern char mobus_rflag;
extern	char *mget;


/*******************************************************************************
* Function Name  : modbuscp_pros
* Description    : changing modbus/rtu send flacg and modbus/rtu pointer , when modbus/tcp packet recived 	
* Input          : pay load bufer (data of recived ethernet paket)
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void modbuscp_pros(struct pbuf *p)
{

char *data;
uint8_t z=0;

mobus_rflag=1;
data=p->payload;
//set modbus rtu pointer to data part of modbus/tcp packet 
mget=p->payload;
	
//wait fot modbus/rtu procces finish(flag will change in MODBUS_Task)
while(mobus_rflag);
while(!dif_countmb());
	
//config data for send modbus tcp packer
data[5]=7;	
	
for(z=6;z<(mb_count+8);z++)
data[z]=mb_buf[z-6];
	
	p->len=z+1;

}


