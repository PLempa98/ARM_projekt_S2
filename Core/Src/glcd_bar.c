#include "glcd_bar.h"
#define WIDTH 128

void print_bar(uint8_t poz)
{
	uint8_t set, i, j;
	if(poz>100)
	{
		poz=100;
	}	
		set=poz*(WIDTH-4)/100;
	
//	glcd_GoTo(set, 0);
//	glcd_WriteData(0xff);
	
	
	glcd_GoTo(2, 6);
	for(i=0;i<(WIDTH-4);i++)
	if (i<=set)
				glcd_WriteData(0xff);
	else
				glcd_WriteData(0x0);
}

void glcd_Bar_Init(void)
{
	uint8_t i;
	for(i=0;i<WIDTH;i++)
	{
		glcd_PutPixel(i,57,1);
		glcd_PutPixel(i,46,1);
	}
	for(i=46;i<57;i++)
	{
		glcd_PutPixel(0,i,1);
		glcd_PutPixel(WIDTH-1,i,1);
	}
}