/*
USE AS:
	#include "Runtime.h"
	Runtime_init();
	Runtime_start();
		delay_ms(1);
	Runtime_stop();

*/

#include "Runtime.h"
void Runtime_init(){
	TIM_InitTypeDef		TIM_InitStructure;					//结构定义
	TIM_InitStructure.TIM_Mode      = TIM_16Bit;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
	TIM_InitStructure.TIM_Polity    = PolityLow;			//指定中断优先级, PolityHigh,PolityLow
	TIM_InitStructure.TIM_Interrupt = DISABLE;				//中断是否允许,   ENABLE或DISABLE
	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;			//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
	TIM_InitStructure.TIM_ClkOut    = DISABLE;				//是否输出高速脉冲, ENABLE或DISABLE
	TIM_InitStructure.TIM_Value     = 0;					//初值,
	TIM_InitStructure.TIM_Run       = DISABLE;				//是否初始化后启动定时器, ENABLE或DISABLE
	Timer_Inilize(Timer1,&TIM_InitStructure);				//初始化Timer0	  Timer0,Timer1,Timer2
}
//执行时间测量开始    占用定时器1
void Runtime_start(){
	TL1=0;
	TH1=0;
	TR1=1;	
}
//执行时间测量结束
void Runtime_stop(){
	TR1=0;
	printf("Runtime=%fms\r\n",(unsigned int)(TL1+TH1*256)*12000.0/MAIN_Fosc);
	TL1=0;
	TH1=0;
}