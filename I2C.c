#include<I2C.h>
#include<reg51.h>
#include<lcd.h>
sbit SCL=P3^0;
sbit SDA=P3^1;

void I2C_Start(void)
{
	SCL=1;
	SDA=1;
	delay(5);
	SDA=0;
	delay(5);
	SCL=0;
}
void I2C_Stop(void)
{
	SCL=0;
	SDA=0;
	delay(5);
	SCL=1;
	delay(5);
	SDA=1;
}
//write byte of data from master to slave
void I2C_DataWrite(unsigned char Data)//0xA0 1010 0000--> 0100 0000
{
	unsigned char i;
	//
	for(i=0;i<8;i++){
	SDA= (Data&0x80)?1:0;
	SCL=1;
	delay(5);
	SCL=0;
	Data=Data<<1;
}
SDA=1;
SCL=1;
	delay(5);
while(SDA==1); //waiting until SDA=0 this should be set by the slave 
SCL=0;
	delay(5);
}
unsigned char I2C_DataRead(void)///1010 0000     1|0=1...101
{
bit rd_bit;
unsigned char i,Dat=0;	

	for(i=0;i<8;i++)
	{
		delay(5);
		SCL=1;
		delay(5);
		rd_bit=SDA;
		Dat=Dat<<1;
		Dat=Dat|rd_bit;
	
			SCL=0;
	}
	//NACK
SDA=1;
SCL=1;
delay(5);
SCL=0;
	return Dat;
}