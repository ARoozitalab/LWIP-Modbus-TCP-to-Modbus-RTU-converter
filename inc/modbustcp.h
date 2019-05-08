/*********************************************************************************************************
*
* File                : modbustcp.h
* Hardware Environment: stm32f407 eval board "https://github.com/ARoozitalab/STM32F4-Eval-board"
* Version             : V1.0
* By                  : alireza roozitalab
* email               : alireza.roozitalab@gmail.com
* git user            : ARoozitalab
*                                                
*                                          All Rights Reserved
*
*********************************************************************************************************/


#include "httpd_structs.h"
#include "lwip/tcp.h"
#include "fs.h"
#include "lwip/debug.h"

#ifndef __MODBUS_TCP_H
#define __MODBUS_TCP_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
struct modbus_tcp_struct
{
  u8_t state;             /* current connection state */
  struct tcp_pcb *pcb;    /* pointer on the current tcp_pcb */
  struct pbuf *p;         /* pointer on the received/to be transmitted pbuf */
};

enum modbus_tcp_states
{
  ES_NONE = 0,
  ES_ACCEPTED,
  ES_RECEIVED,
  ES_CLOSING
};

void modbuscp_pros(struct pbuf *p);	 

#define ICMP_PROTOCOL 1
#define TCP_PROTOCOL 6


#define TYPE_ARP  0X0806
#define TYPE_ICMP 0X0800
	 
	 
	 #ifdef __cplusplus
}
#endif

#endif /* __STM32F4x7_ETH_H */






