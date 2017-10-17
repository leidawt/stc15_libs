/*************************************************
File name: MAIN.c
Author:   山东大学电子设计协会
Version:  V0.2
Date: // 2017.10.15
Description: 基本51模块封测
Function List:
更新日志：
V0.1 2017.10.14 完成sys架构，LCD1602,adc，串口，BUG:串口波特率加倍错误
v0.2 2017.10.14 修复 BUG:串口波特率加倍错误，完善注释
*************************************************/
#include	"config.h"
#include	"USART1.h"
#include	"delay.h"
//#include	"adc.h"
//#include    "LCD1602.h"

/*************	本地常量声明	**************/


/*************	本地变量声明	**************/

int time=0;
/*************	本地函数声明	**************/



/*************  外部函数和变量声明 *****************/



/**********************************************/
void main(void)
{
	UART_config();//配置串口1,P30_P31,使用定时器2 默认波特率115200,8,1
	//ADC_config(ADC_P10);//ADC基础配置，准备P10口	
	LCD1602_init();
	EA = 1;			   //开中断
//	while(1){
//		print_lcd("TIME: %d:%d",time/60,time%60);
//		time++;
//		delay_ms(1000);
//	}
	while(1){
		printf("hello\r\n");
		//printf("adc:%d",Get_ADC10bitResult(0));
		delay_ms(1000);
	}
	
}



