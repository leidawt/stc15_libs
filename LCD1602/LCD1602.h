#ifndef		__LCD1602
#define		__LCD1602
#include "config.h"
#include <stdarg.h>
#define lcd P2
#define lcdrs   P44			
#define lcdrw   P42					
#define lcden   P41					
#define lcdbusy P27     //busy test port,same as D7
#define uchar unsigned char
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

void LCD1602_busy_test(void);
void LCD1602_com(uchar com);
void LCD1602_data(uchar date);
void LCD1602_init(void);
void print_lcd(char* fmt ,...);
#endif