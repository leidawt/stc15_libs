#include "DHT11.h"
#include "config.h"
#include "delay.h"

// unsigned char Sensor_Data_DHT11[5]={0x00,0x00,0x00,0x00,0x00};
/*
uchar dht_t1=0,dht_t2=0; //依次为温度整数部分和温度小数部分
uchar dht_d1=0,dht_d2=0; //依次为湿度整数部分和湿度小数部分
uchar dht_chk=0; //和校验，可选择是否使用，具体参照数据手册
*/
uchar dht_num = 0;  //用于while 循环中计数，超时则跳出循环

uchar dht_readat()  //接收一个8 位数据，先高位后低位
{
    uchar i = 0, dat = 0;
    for (i = 0; i < 8; i++) {
        dht_num = 2;
        while ((dht_dat == 0) && (dht_num++))
            ;
        Delay10us();
        Delay10us();
        Delay10us();
        Delay10us();
        dat = dat << 1;
        if (dht_dat == 1) {
            dht_num = 2;
            dat = dat | 0x01;
            while ((dht_dat == 1) && (dht_num++))
                ;
        }
    }
    return dat;
}
void getdat_DHT11()  //给DHT11 一个开始信号，然后读取一次数据，共五个8 位字节
{
    uchar i = 0;
    dht_dat = 0;
    delay_ms(40);
    dht_dat = 1;  //单片机给起始脉冲信号
    Delay10us();
    Delay10us();
    Delay10us();
    Delay10us();
    dht_dat = 1;  //稍作延时，等待DHT11 返回响应（响应为低电平）
    if (dht_dat == 0)  //有响应才接收数据，否则不作处理
    {
        dht_num = 2;
        while ((dht_dat == 0) && (dht_num++))
            ;
        dht_num = 2;
        while ((dht_dat == 1) && (dht_num++))
            ;
        Sensor_Data_DHT11[0] = dht_readat();
        Sensor_Data_DHT11[1] = dht_readat();
        Sensor_Data_DHT11[2] = dht_readat();
        Sensor_Data_DHT11[3] = dht_readat();
        Sensor_Data_DHT11[4] = dht_readat();  //一次读出五个数据
    }
    dht_dat = 1;    //释放总线
    delay_ms(100);  //稍作延时
}
void init_DHT11()  // DHT11 的初始化函数，别忘了写程序时先加上之
{
    delay_ms(1000);  // DHT11 上电前准备时间，大概1s
    dht_dat = 1;     //总线准备
}