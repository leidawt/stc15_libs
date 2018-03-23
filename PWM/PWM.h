#ifndef __PWM_H
#define __PWM_H

//补充头文件
//增强型PWM波形发生器特殊功能寄存器
sfr PWMCFG = 0xf1;   // x000,0000 PWM配置寄存器
sfr PWMCR = 0xf5;    // 0000,0000 PWM控制寄存器
sfr PWMIF = 0xf6;    // x000,0000 PWM中断标志寄存器
sfr PWMFDCR = 0xf7;  // xx00,0000 PWM外部异常检测控制寄存器
//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
#define PWMC (*(unsigned int volatile xdata *)0xfff0)
#define PWMCH (*(unsigned char volatile xdata *)0xfff0)
#define PWMCL (*(unsigned char volatile xdata *)0xfff1)
#define PWMCKS (*(unsigned char volatile xdata *)0xfff2)
#define PWM2T1 (*(unsigned int volatile xdata *)0xff00)
#define PWM2T1H (*(unsigned char volatile xdata *)0xff00)
#define PWM2T1L (*(unsigned char volatile xdata *)0xff01)
#define PWM2T2 (*(unsigned int volatile xdata *)0xff02)
#define PWM2T2H (*(unsigned char volatile xdata *)0xff02)
#define PWM2T2L (*(unsigned char volatile xdata *)0xff03)
#define PWM2CR (*(unsigned char volatile xdata *)0xff04)
#define PWM3T1 (*(unsigned int volatile xdata *)0xff10)
#define PWM3T1H (*(unsigned char volatile xdata *)0xff10)
#define PWM3T1L (*(unsigned char volatile xdata *)0xff11)
#define PWM3T2 (*(unsigned int volatile xdata *)0xff12)
#define PWM3T2H (*(unsigned char volatile xdata *)0xff12)
#define PWM3T2L (*(unsigned char volatile xdata *)0xff13)
#define PWM3CR (*(unsigned char volatile xdata *)0xff14)
#define PWM4T1 (*(unsigned int volatile xdata *)0xff20)
#define PWM4T1H (*(unsigned char volatile xdata *)0xff20)
#define PWM4T1L (*(unsigned char volatile xdata *)0xff21)
#define PWM4T2 (*(unsigned int volatile xdata *)0xff22)
#define PWM4T2H (*(unsigned char volatile xdata *)0xff22)
#define PWM4T2L (*(unsigned char volatile xdata *)0xff23)
#define PWM4CR (*(unsigned char volatile xdata *)0xff24)
#define PWM5T1 (*(unsigned int volatile xdata *)0xff30)
#define PWM5T1H (*(unsigned char volatile xdata *)0xff30)
#define PWM5T1L (*(unsigned char volatile xdata *)0xff31)
#define PWM5T2 (*(unsigned int volatile xdata *)0xff32)
#define PWM5T2H (*(unsigned char volatile xdata *)0xff32)
#define PWM5T2L (*(unsigned char volatile xdata *)0xff33)
#define PWM5CR (*(unsigned char volatile xdata *)0xff34)
#define PWM6T1 (*(unsigned int volatile xdata *)0xff40)
#define PWM6T1H (*(unsigned char volatile xdata *)0xff40)
#define PWM6T1L (*(unsigned char volatile xdata *)0xff41)
#define PWM6T2 (*(unsigned int volatile xdata *)0xff42)
#define PWM6T2H (*(unsigned char volatile xdata *)0xff42)
#define PWM6T2L (*(unsigned char volatile xdata *)0xff43)
#define PWM6CR (*(unsigned char volatile xdata *)0xff44)
#define PWM7T1 (*(unsigned int volatile xdata *)0xff50)
#define PWM7T1H (*(unsigned char volatile xdata *)0xff50)
#define PWM7T1L (*(unsigned char volatile xdata *)0xff51)
#define PWM7T2 (*(unsigned int volatile xdata *)0xff52)
#define PWM7T2H (*(unsigned char volatile xdata *)0xff52)
#define PWM7T2L (*(unsigned char volatile xdata *)0xff53)
#define PWM7CR (*(unsigned char volatile xdata *)0xff54)

void PWM_INIT(unsigned int pwm_duty);
void PWM_CHN_ENABLE(unsigned char chn);
void PWM_port_remap(unsigned char chn, bit enable);
void PWM_set_ratio(unsigned int Duty_ration, unsigned char chn);

#endif