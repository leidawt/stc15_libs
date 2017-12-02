
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


#ifndef	__EXTI_H
#define	__EXTI_H

#include	"config.h"

#define	EXT_INT0			0	//初始化外中断0
#define	EXT_INT1			1	//初始化外中断1
#define	EXT_INT2			2	//初始化外中断2
#define	EXT_INT3			3	//初始化外中断3
#define	EXT_INT4			4	//初始化外中断4

#define	EXT_MODE_RiseFall	0	//上升沿/下降沿中断
#define	EXT_MODE_Fall		1	//下降沿中断

typedef struct
{
	u8	EXTI_Mode;			//中断模式,  	EXT_MODE_RiseFall, EXT_MODE_Fall
	u8	EXTI_Polity;		//优先级设置	PolityHigh,PolityLow
	u8	EXTI_Interrupt;		//中断允许		ENABLE,DISABLE
} EXTI_InitTypeDef;

u8	Ext_Inilize(u8 EXT, EXTI_InitTypeDef *INTx);
void	EXTI_config(u8 EXTI_Mode,u8	EXTI_Polity,u8	EXTI_Interrupt,u8 EXT_chn) ;
#endif
