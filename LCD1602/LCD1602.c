#include "LCD1602.h"
#include "stdio.h"

void LCD1602_busy_test()
{
   	lcd = 0xff;	    	//测忙函数
   	lcdrs = 0;
   	lcdrw = 1;
   	lcden = 1;
   	while(lcdbusy);		
   	lcden = 0;			
}
void LCD1602_com(uchar com)  //写命令
{ 
  	LCD1602_busy_test();
  	lcd = com;
  	lcdrs = 0;
  	lcdrw = 0;
  	lcden = 1;
  	lcden = 0;
}
void LCD1602_data(uchar date) //写数据
{ 
    LCD1602_busy_test();
	lcd = date;
  	lcdrs = 1;
  	lcdrw = 0;
  	lcden = 1;
  	lcden = 0;
}
void LCD1602_init(void)
{
	P4M0=0;
	P4M1=0;
	P2M0=0;
	P2M1=0;
  	LCD1602_com(CMD_set82);	    //* 显示模式设置：显示2行，每个字符为5*7个像素
  	LCD1602_com(CMD_clear);   	//  显示清屏
  	LCD1602_com(CMD_back);		//* 数据指针指向第1行第1个字符位置
  	LCD1602_com(CMD_add1);		//  显示光标移动设置：文字不动，光标右移
  	LCD1602_com(CMD_dis_gb3); 	//  显示开及光标设置：显示开，光标开，闪烁开
}
void print_lcd(char* fmt ,...){
	unsigned char i,num;
	unsigned char xdata lcd_buf[32]={0};
	va_list ap;  
    va_start(ap,fmt); 
	num=vsprintf(lcd_buf,fmt,ap);
	LCD1602_com(CMD_clear);
	LCD1602_com(CMD_back);
	for(i=0;i<num;i++){
		if(i==16)
			LCD1602_com(0x80+0x40);	//换行
		if(i<32)
			LCD1602_data(lcd_buf[i]);		
	}
	va_end(ap);
}