#include "key.h"
#include "Exti.h"
#include "config.h"
#include "delay.h"
#include 	"LCD12864.h"

//按键初始化
//按键挂在int0上
void key_init() {
    //下面开启外部中断
    //	EXTI_InitTypeDef	EXTI_InitStructure;
    ////结构定义
    //
    //	EXTI_InitStructure.EXTI_Mode      = EXT_MODE_Fall;
    ////中断模式下降沿触发 	EXTI_InitStructure.EXTI_Polity    = PolityHigh;
    ////中断优先级高 	EXTI_InitStructure.EXTI_Interrupt = ENABLE;
    ////中断允许 	Ext_Inilize(EXT_INT0,&EXTI_InitStructure);
    ////初始化INT0
    EXTI_config(EXT_MODE_Fall, PolityHigh, ENABLE, EXT_INT0);
}

/********************* INT0中断函数 *************************/
void Ext_INT0(void) interrupt INT0_VECTOR  //进中断时已经清除标志
{
    delay_ms(10);
    if (P32 == 0) {
        //开始执行中断服务部分
        P20 = ~P20;
    }
}
#define Submit P00
#define key1 P01
#define key2 P02
#define key3 P03

unsigned char datas[3]={0};
void mutiKeyDemo(void){
	while(Submit==1){
		if(key1==0){
			delay_ms(hold_time);
			if(key1==0){
				datas[0]++;
				print_lcd12864("key1\n");
			}
			while(key1==0);
		}
		if(key2==0){
			delay_ms(hold_time);
			if(key2==0){
				datas[1]++;
				print_lcd12864("key2\n");
			}
			while(key2==0);
		}
		if(key3==0){
			delay_ms(hold_time);
			if(key3==0){
				datas[2]++;
				print_lcd12864("key3\n");
			}
			while(key3==0);
		}
	}
}