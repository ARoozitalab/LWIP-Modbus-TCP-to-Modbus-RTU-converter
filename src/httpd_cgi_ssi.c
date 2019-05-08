/**
  ******************************************************************************
  * @file    httpd_cg_ssi.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    31-October-2011
  * @brief   Webserver SSI and CGI handlers
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/


#include "lwip/debug.h"
#include "httpd.h"
#include "lwip/tcp.h"
#include "fs.h"
#include "main.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stm32f4x7_eth.h"
#include "netconf.h"
#include "httpd.h"
#include "modbus.h"
#include "SST25VF016B.h"
#include "FlashDriver.h"
tSSIHandler ADC_Page_SSI_Handler;
uint64_t num_call=0;
extern long long num_save[5];
/* we will use character "t" as tag for CGI */
/*char const* TAGCHAR="t";
char const** TAGS=&TAGCHAR;*/

/* CGI handler for LED control */ 
const char * LEDS_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

/* Html request for "/leds.cgi" will start LEDS_CGI_Handler */
const tCGI LEDS_CGI={"/ertefa.cgi", LEDS_CGI_Handler};
const tCGI LEDS1_CGI={"/relayout.cgi", LEDS_CGI_Handler};
const tCGI LEDS2_CGI={"/calibration.cgi", LEDS_CGI_Handler};
const tCGI LEDS3_CGI={"/speedm.cgi", LEDS_CGI_Handler};
const tCGI LEDS4_CGI={"/login.cgi", LEDS_CGI_Handler};
const tCGI LEDS5_CGI={"/ipset.cgi", LEDS_CGI_Handler};
const tCGI LEDS6_CGI={"/serialset.cgi", LEDS_CGI_Handler};
/* Cgi call table, only one CGI used */
tCGI CGI_TAB[7];

/**
  * @brief  Configures the ADC.
  * @param  None
  * @retval None
  */

/**
  * @brief  ADC_Handler : SSI handler for ADC page 
  */
u16_t ADC_Handler(int iIndex, char *pcInsert, int iInsertLen)
{
char b5;
float AD_value_1,AD_value_2;

  /* We have only one SSI handler iIndex = 0 */
   if (iIndex ==0)
		 
	 {
			if(num_save[iIndex])
		 sprintf(&pcInsert[0],"0%llu",num_save[iIndex]);
			else
			sprintf(&pcInsert[0],"empty");	
 		 return strlen(pcInsert);
		 return 3;
	 }
	 
	    if (iIndex ==1)
		 
	 {
			if(num_save[iIndex])
		 sprintf(&pcInsert[0],"0%llu",num_save[iIndex]);
			else
			sprintf(&pcInsert[0],"empty");	
		 return strlen(pcInsert);
	 }
	 
	  if (iIndex ==2)
		 
	 {
			if(num_save[iIndex])
		 sprintf(&pcInsert[0],"0%llu",num_save[iIndex]);
			else
			sprintf(&pcInsert[0],"empty");	
		 return strlen(pcInsert);
	 }

	 if (iIndex ==3)
		 
	 {
			if(num_save[iIndex])
		 sprintf(&pcInsert[0],"0%llu",num_save[iIndex]);
			else
			sprintf(&pcInsert[0],"empty");	
		 return strlen(pcInsert);
	 }
	  if (iIndex ==4)
		 
	 {
			if(num_save[iIndex])
		 sprintf(&pcInsert[0],"0%llu",num_save[iIndex]);
			else
			sprintf(&pcInsert[0],"empty");	
		 return strlen(pcInsert);
	 }
	 	  if (iIndex ==5)
		 
	 {
    *pcInsert='\0';
			sprintf(&pcInsert[0],"%u",bud_rate);
		 return strlen(pcInsert);
	 }
	  if (iIndex ==6)
		 
	 {
    *pcInsert='\0';
			sprintf(&pcInsert[0],"%u",stp_bit);
		 return strlen(pcInsert);
	 }
	if (iIndex ==7)
		 
	 {
    *pcInsert='\0';
			sprintf(&pcInsert[0],"%u",dta_bit);
		 return strlen(pcInsert);
	 }
	 if (iIndex ==8)
	 {
    *pcInsert='\0';
		 if(prt_bit==1)
			sprintf(&pcInsert[0],"none");
		 else if(prt_bit==2)
			sprintf(&pcInsert[0],"even");		 
		 else if(prt_bit==3)
			sprintf(&pcInsert[0],"odd");			 
		 else
		sprintf(&pcInsert[0],"space");			 
		 

		 return strlen(pcInsert);
	 }
  return 0;
}

/**
  * @brief  CGI handler for LEDs control 
  */
const char * LEDS_CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
   uint8_t i=0;
	uint8_t j=0;
	char ali[4];
	uint16_t state;
state=0;
  //		pca9535d_WordSet(0x44,output_port0,0x00,0x00);
  /* We have only one SSI handler iIndex = 0 */
  if (iIndex==0)
  {	
///////////////////////
			
  }
  if (iIndex==1)
  {
		STM_EVAL_LEDOff(LED1);
    STM_EVAL_LEDOff(LED2);
    STM_EVAL_LEDOff(LED3);
    STM_EVAL_LEDOff(LED4);
    
    /* Check cgi parameter : example GET /leds.cgi?led=2&led=4 */
    for (i=0; i<iNumParams; i++)
    {
      /* check parameter "led" */
      if (strcmp(pcParam[i] , "led")==0)   
      {
        /* switch led1 ON if 1 */
        if(strcmp(pcValue[i], "1") ==0) 
          STM_EVAL_LEDOn(LED1);
          
        /* switch led2 ON if 2 */
        else if(strcmp(pcValue[i], "2") ==0) 
          STM_EVAL_LEDOn(LED2);
        
        /* switch led3 ON if 3 */
        else if(strcmp(pcValue[i], "3") ==0) 
          STM_EVAL_LEDOn(LED3);
        
        /* switch led4 ON if 4 */
        else if(strcmp(pcValue[i], "4") ==0) 
          STM_EVAL_LEDOn(LED4);
      }
    }
    
			//pca9535d_WordSet(0x44,output_port0,(state>>8),state);
			return "/frame7.html"; 
	}
	  if (iIndex==2)
  { 

		return "/frame5.html"; 
	}
	  if (iIndex==3)
  {
//		num_call=atoll(pcValue[0]);
//		call_number(num_call);
		  return "/frame4.html";  
	}
		  if (iIndex==4)
  {

   if ((pcValue[0][0]=='a') &(pcValue[0][1]=='d')&(pcValue[0][2]=='m')&(pcValue[0][3]=='i')&(pcValue[0][4]=='n')&
		    (pcValue[1][0]=='a')&(pcValue[1][1]=='d')&(pcValue[1][2]=='m')&(pcValue[1][3]=='i')&(pcValue[1][4]=='n'))
	 {	 
	  return "/xtest.shtml";
	 }		 
	}
	 if (iIndex==5)
  {
	for(j=0;j<4;j++)
	{	
		ali[j]=0;
		for(i=0; i<strlen(pcValue[j]);i++)
		{  	
				ali[j]=ali[j]*10;
		 ali[j]=ali[j]+(pcValue[j][i]-48);
		
		}
	}
	IP_ADDR0 =(ali[0]);
  IP_ADDR1 =(ali[1]);
  IP_ADDR2 =(ali[2]);
  IP_ADDR3 =(ali[3]);
   LwIP_Init1();
	  return 0;  
	}
	
	
	if (iIndex==6)
  {
			bud_rate=atoll(pcValue[0]);
		stp_bit=atoll(pcValue[1]);
		dta_bit=atoll(pcValue[2]);
		if(pcValue[3][0]=='1')
		prt_bit=1;
		if(pcValue[3][0]=='2')
		prt_bit=2;
		if(pcValue[3][0]=='3')
		prt_bit=3;			
		if(pcValue[3][0]=='4')
		prt_bit=4;	
		SSTF016B_Erase( 0 , 0 );
			   vTaskDelay(200);
	
	df_write_open(0x10);	
	df_write((uint8_t *)&bud_rate,4); 
			df_write_close();
	df_write_open(0x20);		
	df_write((uint8_t *)&stp_bit,1); 
			df_write_close();
	df_write_open(0x21);	
	df_write((uint8_t *)&dta_bit,1); 	
			df_write_close();
	df_write_open(0x22);	
	df_write((uint8_t *)&prt_bit,1); 		
	df_write_close();	
		 init_modnus();
	  return "/frame5.shtml";  
	}
  return "/index.html";  
}

const char* tag[]={"q","w","e","r","t","z","x","c","v"};
/**
 * Initialize SSI handlers
 */
void httpd_ssi_init(void)
{  
  /* configure SSI handlers (ADC page SSI) */
 http_set_ssi_handler(ADC_Handler, tag, 9);
}

/**
 * Initialize CGI handlers
 */
void httpd_cgi_init(void)
{ 
  /* configure CGI handlers (LEDs control CGI) */

   CGI_TAB[0]=LEDS_CGI;
   CGI_TAB[1]=LEDS1_CGI;
	 CGI_TAB[2]=LEDS2_CGI;
	 CGI_TAB[3]=LEDS3_CGI;
	 CGI_TAB[4]=LEDS4_CGI;
	 CGI_TAB[5]=LEDS5_CGI;
		CGI_TAB[6]=LEDS6_CGI;
  http_set_cgi_handlers(CGI_TAB, 7);
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
