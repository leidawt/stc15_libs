/*************************************************
File name: MAIN.c
Author:   山东大学电子设计协会
Description: 基本51模块封测

*************************************************/
#include	"config.h"
#include	"delay.h"
#include	"GPIO.h"
#include	"USART1.h"
#include 	"LCD12864.h"
#include 	"DHT11.h"
#include 	"key.h"
#include	"global.h"
void main(void){
	GPIO_INIT();//所有GPIO配置为准双向
	UART_config();//配置串口1,P30_P31,使用定时器2 默认波特率115200,8,1
	EA = 1;			   //开中断
	init_LCD12864();
	init_DHT11();
	mutiKeyDemo();
	while(1){
		delay_ms(1000);
		getdat_DHT11();
		print_lcd12864("hum:\n%d\n",(int)Sensor_Data_DHT11[2]);
	}	
}



