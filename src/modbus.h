/*********************************************************************************************************
*
* File                : modbus.h
* Hardware Environment: stm32f407 eval board "https://github.com/ARoozitalab/STM32F4-Eval-board"
* Version             : V1.0
* By                  : alireza roozitalab
* email               : alireza.roozitalab@gmail.com
* git user            : ARoozitalab
*                                                
*                                          All Rights Reserved
*
*********************************************************************************************************/
#ifndef __MODBUS_h
#define __MODBUS_h
#include "stdio.h"
#include "stdint.h"


#define RW_PORT   GPIOB
#define RW_PIN   GPIO_Pin_15
#define mb_buf_size 256
extern uint32_t bud_rate;
extern uint8_t stp_bit;
extern uint8_t prt_bit;
extern uint8_t dta_bit;
extern uint8_t mb_buf[mb_buf_size];
extern uint8_t mb_count;
uint16_t  crc(uint8_t  *puchMsg ,uint8_t  usDataLen);
uint16_t  modbus_read_req(char *data, uint8_t len);
void send_temp(uint16_t  temp,uint16_t  weight);
void init_modnus(void);
uint16_t  modbus_write_req(char *data, uint8_t len);


#endif
