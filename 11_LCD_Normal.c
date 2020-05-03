#include <reg51.h>
#define ldata P2
sbit rs = P3^0;
sbit rw = P3^1;
sbit en = P3^2;

void lcdcmd(unsigned char value);
void lcddata(unsigned char value);
void MSDelay(unsigned int itime);
void main()
	{
		while(1)			// Repeat forevermore 
		{
		lcdcmd(0x38); //8bit 2 line
		MSDelay(10);
		lcdcmd(0x0E); //Display cursor ON
		MSDelay(10);
		lcdcmd(0x01); // Clear Display
		MSDelay(10);
		lcdcmd(0x06); // Entry Mode
		MSDelay(10);
		lcdcmd(0x80); // LCD Line Address
		MSDelay(10);
		lcddata('L'); // Here you can change your name and display it virtually
		MSDelay(25);
		lcddata('C');
		MSDelay(25);
		lcddata('D');
		MSDelay(25);
		lcddata(' ');
		MSDelay(25);
		lcddata('D');
		MSDelay(25);
		lcddata('I');
		MSDelay(25);
		lcddata('S');
		MSDelay(25);
		lcddata('P');
		MSDelay(25);
		lcddata('L');
		MSDelay(25);
		lcddata('A');
		MSDelay(25);
		lcddata('Y');
		lcddata(' ');
		
		MSDelay(25);
		lcddata('!');
		MSDelay(25);
		lcddata('@');
		MSDelay(25);
		lcddata('$');
		MSDelay(25);
		lcddata('*');
		MSDelay(25);
		lcddata(' ');
		lcdcmd(0xC5 ); //Second line address
		lcddata('_');
		lcddata('*');
		lcddata('*');
		lcddata('*');
		lcddata('*');
		lcddata('*');
		lcddata('*');
		lcddata('*');
		lcddata('*');
		lcddata('*');
		lcddata('_');
	}
		
	}
void lcdcmd(unsigned char value)
	{
		ldata = value;
		rs =  0;
		rw = 0;
		en = 1;
		MSDelay(1);
		en = 0;
		return;
	}
void lcddata(unsigned char value)
	{
		ldata = value;
		rs =  1;
		rw = 0;
		en = 1;
		MSDelay(1);
		en = 0;
		return;
	}
void MSDelay(unsigned int itime)
	{
		unsigned  int i,j;
		for(i=0;i<itime;i++)
			for(j=0;j<1275;j++);
	}