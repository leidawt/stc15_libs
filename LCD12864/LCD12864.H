#ifndef _LCD12864_H_
#define _LCD12864_H_
#include "config.h"
//************LCD12864
#define CS P33    //片选信号RS
#define SID P34   //数据信号R/W
#define SCLK P35  //时钟信号E
// sbit RST=P2^5;		//复位信号RST 可选
//可以直接接VCC
void init_LCD12864();
void print_lcd12864(char *fmt, ...);
void Wrap();
void write_data_LCD12864(unsigned char dat);
void write_com_LCD12864(unsigned char com);
void disp_line_LCD12864(unsigned char x, unsigned char *dat);
//显示函数	显示液晶的一行数据
//显示函数	显示一个字符串s到液晶   x：第x行，y：第y列，从第X行第Y列开始写
void disp_string_LCD12864(unsigned char x, unsigned char y, unsigned char *s);

#endif