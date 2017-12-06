#ifndef __DS1302_H_
#define __DS1302_H_

//---包含头文件---//
#include"config.h"
#include<intrins.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

//---定义ds1302使用的IO口---//
#define DSIO P23
#define RST P24
#define SCLK1302 P25

//---定义全局函数---//
void Ds1302Write(uchar addr, uchar dat);
uchar Ds1302Read(uchar addr);
void Ds1302Init();
void Ds1302ReadTime();

//---加入全局变量--//
extern uchar TIME[7];	//加入全局变量

#endif