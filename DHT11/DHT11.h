#ifndef __DHT11_H
#define __DHT11_H
#define uchar unsigned char
#define uint unsigned int
unsigned char xdata Sensor_Data_DHT11[5];
void getdat_DHT11();
void init_DHT11();
#define dht_dat P07  //ÓÃÄÄ¸öI/O ¿Ú
#endif
