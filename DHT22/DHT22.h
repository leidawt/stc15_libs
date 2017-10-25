#ifndef    __DHT22_H
#define    __DHT22_H
unsigned char Sensor_Dat_DHT22[5];
unsigned char Read_SensorData(void);
unsigned char Read_Sensor_DHT22(void);
#define Sensor_SDA P06
#endif