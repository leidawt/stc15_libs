#ifndef _LCD12864_H_
#define _LCD12864_H_
#include "config.h"
//************LCD12864
sbit CS=P3^3;	    //Ƭѡ�ź�RS
sbit SID=P3^4;		//�����ź�R/W
sbit SCLK=P3^5;		//ʱ���ź�E
//sbit RST=P2^5;		//��λ�ź�RST ��ѡ
						//����ֱ�ӽ�VCC
void print_lcd12864(char* fmt ,...);
void init_LCD12864();
void write_data_LCD12864(unsigned char dat);
void write_com_LCD12864(unsigned char  com);
void disp_line_LCD12864(unsigned char x,unsigned char *dat);  //��ʾ����	��ʾҺ����һ������
void disp_string_LCD12864(unsigned char x,unsigned char y,unsigned char *s);
//��ʾ����	��ʾһ���ַ���s��Һ��   x����x�У�y����y�У��ӵ�X�е�Y�п�ʼд
#endif