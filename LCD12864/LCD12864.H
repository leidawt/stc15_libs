#ifndef _LCD12864_H_
#define _LCD12864_H_
#include "config.h"
//************LCD12864
#define CS P33    //片选信号RS
#define SID P34   //数据信号R/W
#define SCLK P35  //时钟信号E
// sbit RST=P2^5;		//复位信号RST 可选
//可以直接接VCC


/***************************************************************************/
#define			CMD_clear		0x01             // 清除屏幕
#define			CMD_back		0x02             // DDRAM回零位
#define			CMD_dec1		0x04             // 读入后AC（指针）减1，向左写
#define			CMD_add1		0x06             // 读入后AC（指针）加1，向右写
#define			CMD_dis_gb1		0x0f             // 开显示_开光标_开光标闪烁
#define			CMD_dis_gb2		0x0e             // 开显示_开光标_关光标闪烁
#define			CMD_dis_gb3		0x0c             // 开显示_关光标_关光标闪烁
#define			CMD_OFF_dis		0x08             // 关显示_关光标_关光标闪烁
#define			CMD_set82		0x38             // 8位总线_2行显示
#define			CMD_set81		0x30             // 8位总线_1行显示（上边行）
#define			CMD_set42		0x28             // 4位总线_2行显示
#define			CMD_set41		0x20             // 4位总线_1行显示（上边行）
#define			lin_1			0x80             // 4位总线_1行显示（上边行）
#define			lin_2			0xc0             // 4位总线_1行显示（上边行）	
/***************************************************************************/


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