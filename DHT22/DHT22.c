#include "DHT22.h"
#include "config.h"
#include "delay.h"
#include "math.h"
#include "stdio.h"
#include "string.h"
//************dht22
unsigned char Sensor_Dat_DHT22[5] = {0x00, 0x00, 0x00, 0x00, 0x00};
unsigned char Sensor_Check;       //校验和
unsigned char Sensor_AnswerFlag;  //收到起始标志位
unsigned char Sensor_ErrorFlag;   //读取传感器错误标志
unsigned int Sys_CNT;
unsigned int Tmp;
unsigned char Read_SensorData(void)  //读一位数据
{
    unsigned char i, cnt;
    unsigned char buffer, tmp;
    buffer = 0;
    for (i = 0; i < 8; i++) {
        cnt = 0;
        while (!Sensor_SDA)  //检测上次低电平是否结束
        {
            if (++cnt >= 300) {
                break;
            }
        }
        //延时Min=26us Max50us 跳过数据"0" 的高电平
        Delay10us();  //延时30us
        Delay10us();
        Delay10us();
        //判断传感器发送数据位
        tmp = 0;
        if (Sensor_SDA) {
            tmp = 1;
        }
        cnt = 0;
        while (Sensor_SDA)  //等待高电平 结束
        {
            if (++cnt >= 200) {
                break;
            }
        }
        buffer <<= 1;
        buffer |= tmp;
    }
    return buffer;
}

unsigned char Read_Sensor_DHT22(void)  //读全部数据
{
    unsigned char i;
    //主机拉低(Min=800US Max=20Ms)
    Sensor_SDA = 0;
    Delay_N1ms(2);  //延时2Ms

    //释放总线 延时(Min=30us Max=50us)
    Sensor_SDA = 1;
    Delay10us();  //延时30us
    Delay10us();
    Delay10us();
    //主机设为输入 判断传感器响应信号
    Sensor_SDA = 1;

    Sensor_AnswerFlag = 0;  // 传感器响应标志

    //判断从机是否有低电平响应信号 如不响应则跳出，响应则向下运行
    if (Sensor_SDA == 0) {
        Sensor_AnswerFlag = 1;  //收到起始信号
        Sys_CNT = 0;
        //判断从机是否发出 80us 的低电平响应信号是否结束
        while ((!Sensor_SDA)) {
            if (++Sys_CNT > 300)  //防止进入死循环
            {
                Sensor_ErrorFlag = 1;
                return 0;
            }
        }
        Sys_CNT = 0;
        //判断从机是否发出 80us 的高电平，如发出则进入数据接收状态
        while ((Sensor_SDA)) {
            if (++Sys_CNT > 300)  //防止进入死循环
            {
                Sensor_ErrorFlag = 1;
                return 0;
            }
        }
        // 数据接收	传感器共发送40位数据
        // 即5个字节 高位先送  5个字节分别为湿度高位 湿度低位 温度高位 温度低位
        // 校验和 校验和为：湿度高位+湿度低位+温度高位+温度低位
        for (i = 0; i < 5; i++) {
            Sensor_Dat_DHT22[i] = Read_SensorData();
        }
    } else {
        Sensor_AnswerFlag = 0;  // 未收到传感器响应
    }
    return 1;
}