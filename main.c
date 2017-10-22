/*************************************************
File name: MAIN.c
Author:   山东大学电子设计协会
Version:  V0.2
Date: // 2017.10.15
Description: 基本51模块封测
更新日志：
V0.1 2017.10.14 完成sys架构，LCD1602,adc，串口，BUG:串口波特率加倍错误
v0.2 2017.10.14 修复 BUG:串口波特率加倍错误，完善注释
v0.3 2017.10.18 add 6路PWM 控制器
*************************************************/
#include	"config.h"
#include	"USART1.h"
#include	"delay.h"
#include	"GPIO.h"
#include	"adc.h"
#include    "LCD1602.h"
#include "PWM.h"
/*************	本地常量声明	**************/


/*************	本地变量声明	**************/

int i=0;
/*************	本地函数声明	**************/



/*************  外部函数和变量声明 *****************/



/**********************************************/
void main(void)
{
	GPIO_INIT();//所有GPIO配置为准双向
	UART_config();//配置串口1,P30_P31,使用定时器2 默认波特率115200,8,1
	//ADC_config(ADC_P10);//ADC基础配置，准备P10口	
	//LCD1602_init();
	EA = 1;			   //开中断
	PWM_INIT(10000);
	PWM_CHN_ENABLE(3);
	while(1){
		for(i=10;i<9000;i+=100){
			PWM_set_ratio(i,3);
			delay_ms(10);
		}
//		for(i=1000;i>0;i-=5){
//			PWM_set_ratio(i,3);
//			delay_ms(10);
//		}
		
	}
	
}



