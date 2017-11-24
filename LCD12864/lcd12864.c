#include "LCD12864.H"
#include "delay.h"
#include "stdio.h"
#include "stdarg.h"
#include <string.h>
unsigned char line_count=1;//换行函数计数变量
/*****************************************************************
          初始化函数 init();	  
     初始化液晶，显示坐标，显示游标闪烁
*****************************************************************/
void init_LCD12864()			    //12864初始化函数
{					                    //并行初始化
	write_com_LCD12864(0x30);   //写基本指令集
	delay_ms(50);
	write_com_LCD12864(0x0c);    //on打开
	delay_ms(50);
	write_com_LCD12864(0x01);    //清屏
	delay_ms(50);

}

// 按照液晶的串口通信协议，发送数据

void sendbyte(unsigned char zdata)
{
	unsigned int i;
	for(i=0; i<8; i++)
	{
		if((zdata << i) & 0x80)
		{
			SID = 1;
		}
		else 
		{
			SID = 0;
		}
		SCLK = 0;
		SCLK = 1;//上升沿发送数据
	}
}

/*****************************************************************
	   写命令函数 write_com();	写清屏、显示游标、地址到液晶
*****************************************************************/
void write_com_LCD12864(unsigned char cmdcode)
{
	CS = 1;
	sendbyte(0xf8);
	sendbyte(cmdcode & 0xf0);
	sendbyte((cmdcode << 4) & 0xf0);
	delay_ms(2);
}


/*****************************************************************
	   写数据函数 write_data();	写显示数据到液晶
*****************************************************************/
void write_data_LCD12864(unsigned char Dispdata)
{	
	CS = 1;
	sendbyte(0xfa);
	sendbyte(Dispdata & 0xf0);
	sendbyte((Dispdata << 4) & 0xf0);
	delay_ms(2);
}

/*****************************************************************
	   显示函数	显示液晶的一行数据
*****************************************************************/
void disp_line_LCD12864(unsigned char x,unsigned char *dat)		 //
{
	unsigned char add,i;
	switch(x)
	{
		case 1:add=0x80;break;
		case 2:add=0x90;break;
		case 3:add=0x88;break;
		case 4:add=0x98;break;
	}
	write_com_LCD12864(add);
	for(i=0;i<strlen(dat);i++)write_data_LCD12864(dat[i]);
}

/*****************************************************************
	   显示函数	显示一个字符串s到液晶   x：第x行，y：第y列，从第X行第Y列开始写
*****************************************************************/
void disp_string_LCD12864(unsigned char x,unsigned char y,unsigned char *s)		  
{
	unsigned char add;
	switch(x)
	{
		case 1:add=0x80;break;
		case 2:add=0x90;break;
		case 3:add=0x88;break;
		case 4:add=0x98;break;
	}
	write_com_LCD12864(add+y-1);
	while(*s>0) { write_data_LCD12864(*s); s++; }
}
//换行函数
void Wrap(){
	switch(line_count){
		case 1:write_com_LCD12864(0x90);break;
		case 2:write_com_LCD12864(0x88);break;
		case 3:write_com_LCD12864(0x98);break;
	}
	line_count++;
}
void print_lcd12864(char* fmt ,...){
	unsigned char i,num;
	unsigned char xdata lcd_buf[64]={0};
	va_list ap;  
    va_start(ap,fmt); 
	num=vsprintf(lcd_buf,fmt,ap);
	write_com_LCD12864(0x01);//clear
	for(i=0;i<num;i++){
		if(lcd_buf[i]=='\n'||lcd_buf[i]=='\r'||(i%16==0)&&i){ //处理\r或\n换行
			if(!((i%16==0)&&i))	//排除换行符处于自动换行位置
				i++;
			if(lcd_buf[i]=='\n'||lcd_buf[i]=='\r') //处理\r\n写法
				i++;
			Wrap();
		}
		write_data_LCD12864(lcd_buf[i]);		
	}
	line_count=1;
	va_end(ap);
}