#ifndef _ESP01S_H_
#define _ESP01S_H_

#define REV_OK		0	//接收完成标志
#define REV_WAIT	1	//接收未完成标志

#define USART_DEBUG		USART1		//调试打印所使用的串口组

void ESP8266_Init(void);
void ESP8266_Clear(void);
void ESP8266_SendData(unsigned char *data, unsigned short len);
_Bool ESP8266_SendCmd(char *cmd, char *res);
unsigned char *ESP8266_GetIPD(unsigned short timeOut);

#endif

