
//CODE of lcd interfacing with 8051 microcontroller
#include<reg51.h>
#include<lcd.h>
#include<I2C.h>

void main()
{
	unsigned char x;
	lcd_init();
//	lcd_str("   WELCOME TO   ");
//	lcd_cmd(0xc0);
//	lcd_str("   MY PROJECT   ");
//	delay(65000);
//	lcd_cmd(0x01);
//	lcd_cmd(0x80);
//	lcd_str("   YT TRAINING   ");
//	lcd_cmd(0xc0);
//	lcd_str("   INSTITUTE   ");
//	delay(65000);
//	lcd_cmd(0x01);
//	lcd_cmd(0x80);
//	lcd_str(" I2C PROTOCOL R/W");
	
	//Sending Data to a Slave Device
	I2C_Start();
	I2C_DataWrite(0xA0); //1010 0000
	I2C_DataWrite(0x00); //register address or memory address
	I2C_DataWrite('H');
	
	// I2C_DataWrite('E');
	// I2C_DataWrite('T');
	I2C_Stop();
	delay(500);
	
	//reading Data from a Slave Device
	I2C_Start();
	I2C_DataWrite(0xA0); //1010 0000
	I2C_DataWrite(0x01); //register address or memory address
	I2C_Start();
	I2C_DataWrite(0xA1);	//1010 0001 read
	x=I2C_DataRead();
	lcd_cmd(0xc0);
	lcd_data(x);
	I2C_Stop();
	while(1);
}


