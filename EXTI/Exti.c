
/*------------------------------------------------------------------*/
/* --- STC MCU International Limited -------------------------------*/
/* --- STC 1T Series MCU RC Demo -----------------------------------*/
/* --- Mobile: (86)13922805190 -------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ---------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ---------------------*/
/* --- Web: www.GXWMCU.com -----------------------------------------*/
/* --- QQ:  800003751 ----------------------------------------------*/
/* If you want to use the program or the program referenced in the  */
/* article, please specify in which data and procedures from STC    */
/*------------------------------------------------------------------*/
/*****************************************


INT0(P3.2)
INT1(P3.3)
INT2(P3.6)固定为下降沿触发
INT3(P3.7)固定为下降沿触发
INT4(P3.0)固定为下降沿触发


******************************************/

/*************	功能说明	**************

本文件为STC15xxx系列的外中断初始化和中断程序,用户可以在这个文件中修改自己需要的中断程序.

******************************************/



#include	"Exti.h"
/*
//INT0中断函数
void Ext_INT0 (void) interrupt INT0_VECTOR		//进中断时已经清除标志
{
	P00 = ~P00;
}

//INT1中断函数
void Ext_INT1 (void) interrupt INT1_VECTOR		//进中断时已经清除标志
{
	P01 = ~P01;
}

//INT2中断函数
void Ext_INT2 (void) interrupt INT2_VECTOR	//
{
	P02 = ~P02;
}

//INT3中断函数
void Ext_INT3 (void) interrupt INT3_VECTOR
{
	P03 = ~P03;
}

//INT4中断函数
void Ext_INT4 (void) interrupt INT4_VECTOR
{
	P04 = ~P04;
}
*/
//========================================================================
// 函数: u8	Ext_Inilize(u8 EXT, EXTI_InitTypeDef *INTx)
// 描述: 外部中断初始化程序.
// 参数: INTx: 结构参数,请参考Exti.h里的定义.
// 返回: 成功返回0, 空操作返回1,错误返回2.
// 版本: V1.0, 2012-10-22
//========================================================================
u8	Ext_Inilize(u8 EXT, EXTI_InitTypeDef *INTx)
{
	if(EXT >  EXT_INT4)	return 1;	//空操作
	
	if(EXT == EXT_INT0)	//外中断0
	{
		if(INTx->EXTI_Interrupt == ENABLE)		EX0 = 1;	//允许中断
		else									EX0 = 0;	//禁止中断
		if(INTx->EXTI_Polity == PolityHigh)		PX0 = 1;	//高优先级中断
		else									PX0 = 0;	//低优先级中断
		if(INTx->EXTI_Mode == EXT_MODE_Fall)	IT0 = 1;	//下降沿中断
		else									IT0 = 0;	//上升,下降沿中断
		return	0;		//成功
	}

	if(EXT == EXT_INT1)	//外中断1
	{
		if(INTx->EXTI_Interrupt == ENABLE)		EX1 = 1;	//允许中断
		else									EX1 = 0;	//禁止中断
		if(INTx->EXTI_Polity == PolityHigh)		PX1 = 1;	//高优先级中断
		else									PX1 = 0;	//低优先级中断
		if(INTx->EXTI_Mode == EXT_MODE_Fall)	IT1 = 1;	//下降沿中断
		else									IT1 = 0;	//上升,下降沿中断
		return	0;		//成功
	}

	if(EXT == EXT_INT2)		//外中断2, 固定为下降沿低优先级中断
	{
		if(INTx->EXTI_Interrupt == ENABLE)	INT_CLKO |=  (1 << 4);	//允许中断	
		else								INT_CLKO &= ~(1 << 4);	//禁止中断
		return	0;		//成功
	}

	if(EXT == EXT_INT3)		//外中断3, 固定为下降沿低优先级中断
	{
		if(INTx->EXTI_Interrupt == ENABLE)	INT_CLKO |=  (1 << 5);	//允许中断	
		else								INT_CLKO &= ~(1 << 5);	//禁止中断
		return	0;		//成功
	}

	if(EXT == EXT_INT4)		//外中断4, 固定为下降沿低优先级中断
	{
		if(INTx->EXTI_Interrupt == ENABLE)	INT_CLKO |=  (1 << 6);	//允许中断	
		else								INT_CLKO &= ~(1 << 6);	//禁止中断
		return	0;		//成功
	}
	return 2;	//失败
}


void	EXTI_config(u8 EXTI_Mode,u8	EXTI_Polity,u8	EXTI_Interrupt,u8 EXT_chn)
{
	EXTI_InitTypeDef	EXTI_InitStructure;					//结构定义

	EXTI_InitStructure.EXTI_Mode      = EXTI_Mode;	//中断模式,  	EXT_MODE_RiseFall, EXT_MODE_Fall
	EXTI_InitStructure.EXTI_Polity    = EXTI_Polity;			//中断优先级,   PolityLow,PolityHigh
	EXTI_InitStructure.EXTI_Interrupt = EXTI_Interrupt;				//中断允许,     ENABLE或DISABLE
	Ext_Inilize(EXT_chn,&EXTI_InitStructure);				//初始化INT0	EXT_INT0,EXT_INT1,EXT_INT2,EXT_INT3,EXT_INT4

	//EXTI_InitStructure.EXTI_Mode      = EXT_MODE_RiseFall;	//中断模式,  	EXT_MODE_RiseFall, EXT_MODE_Fall
	//EXTI_InitStructure.EXTI_Polity    = PolityLow;			//中断优先级,   PolityLow,PolityHigh
	//EXTI_InitStructure.EXTI_Interrupt = ENABLE;				//中断允许,     ENABLE或DISABLE
	//Ext_Inilize(EXT_INT1,&EXTI_InitStructure);				//初始化INT1	EXT_INT0,EXT_INT1,EXT_INT2,EXT_INT3,EXT_INT4

	//Ext_Inilize(EXT_INT2,&EXTI_InitStructure);				//初始化INT2	EXT_INT0,EXT_INT1,EXT_INT2,EXT_INT3,EXT_INT4
	//Ext_Inilize(EXT_INT3,&EXTI_InitStructure);				//初始化INT3	EXT_INT0,EXT_INT1,EXT_INT2,EXT_INT3,EXT_INT4
	//Ext_Inilize(EXT_INT4,&EXTI_InitStructure);				//初始化INT4	EXT_INT0,EXT_INT1,EXT_INT2,EXT_INT3,EXT_INT4
}