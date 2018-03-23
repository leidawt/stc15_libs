#include "PWM.h"
#include "config.h"
/*************************************************
File name: PWM.c
Author:   山东大学电子设计协会 by lwida
Version:  V0.2
Date:     2017.10.18
Description: stc15 6通道pwm模块
更新日志：
*************************************************/
//========================================================================
// 函数: PWM_INIT(unsigned int pwm_duty)
// 描述: PWM控制器初始化
// 参数: pwm_duty: pwm周期，max 32767
// 返回: none.
// 版本: V0.1, 2017-10-18
//========================================================================
void PWM_INIT(unsigned int pwm_duty) {
    P_SW2 |= 0x80;     //使能扩展SFR
    PWMCFG = 0x00;     // pwm配置初始电平，不触发adc
    PWMFDCR &= ~0x20;  //关闭异常中断
    PWMC = pwm_duty;   //配置pwm周期
    PWMCKS = 0x0f;     //选择输入时钟为1/16主时钟
    PWM2T1 = 1;
    PWM3T1 = 1;
    PWM4T1 = 1;
    PWM5T1 = 1;
    PWM6T1 = 1;
    PWM7T1 = 1;
    PWM2T2 = 0;
    PWM3T2 = 0;
    PWM4T2 = 0;
    PWM5T2 = 0;
    PWM6T2 = 0;
    PWM7T2 = 0;
    P_SW2 &= ~0x80;
}
//========================================================================
// 函数: void PWM_CHN_ENABLE(unsigned char chn)
// 描述: PWM通道使能
// 参数: chn:pwm通道  1-6
// 返回: none.
// 版本: V0.1, 2017-10-18
//========================================================================
void PWM_CHN_ENABLE(unsigned char chn) {
    P_SW2 |= 0x80;            //使能扩展SFR
    PWMCR |= 1 << (chn - 1);  //使能第chn通道
    PWMCR |= 0x80;            //总使能
    P_SW2 &= ~0x80;
    // PWMCR&=~0x80//关总使能
}
//========================================================================
// 函数: void pwm_port_remap(unsigned char chn, bit enable)
// 描述: PWM通道重映射使能
// 参数: enable 使能
//		 chn:pwm通道  1-6
// 返回: none.
// 版本: V0.1, 2017-10-18
//========================================================================
void PWM_port_remap(unsigned char chn, bit enable) {
    switch (chn) {
        case 1:
            PWM2CR = 0x08;
            if (!enable) PWM2CR = 0;
            break;
        case 2:
            PWM3CR = 0x08;
            if (!enable) PWM3CR = 0;
            break;
        case 3:
            PWM4CR = 0x08;
            if (!enable) PWM4CR = 0;
            break;
        case 4:
            PWM5CR = 0x08;
            if (!enable) PWM5CR = 0;
            break;
        case 5:
            PWM6CR = 0x08;
            if (!enable) PWM6CR = 0;
            break;
        case 6:
            PWM7CR = 0x08;
            if (!enable) PWM7CR = 0;
            break;
        default:
            break;
    }
}

//========================================================================
// 函数: set_ratio(unsigned int Duty_ration,unsigned char chn)
// 描述: PWM占空比设置
// 参数: Duty_ration: pwm转变点，==占空比*pwm周期 不可为 0 或 pwm周期
//		 chn:pwm通道  1-6
// 返回: none.
// 版本: V0.1, 2017-10-18
//========================================================================
void PWM_set_ratio(unsigned int Duty_ration, unsigned char chn) {
    switch (chn) {
        case 1:
            P_SW2 |= 0x80;  //使能扩展SFR
            PWM2T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 2:
            P_SW2 |= 0x80;  //使能扩展SFR
            PWM3T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 3:
            P_SW2 |= 0x80;  //使能扩展SFR
            PWM4T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 4:
            P_SW2 |= 0x80;  //使能扩展SFR
            PWM5T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 5:
            P_SW2 |= 0x80;  //使能扩展SFR
            PWM6T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        case 6:
            P_SW2 |= 0x80;  //使能扩展SFR
            PWM7T1 = Duty_ration;
            P_SW2 &= ~0x80;
            PWMCR |= 1 << (chn - 1);
            break;
        default:
            break;
    }
}