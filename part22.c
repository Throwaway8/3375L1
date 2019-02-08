#include "address_map_arm.h"
/* Your first program*/
volatile int * SW_ptr = (int *)SW_BASE;
volatile int * HEX_ptr = (int *)HEX3_HEX0_BASE;
int status = 1;
volatile int DELAY_LENGTH; 
volatile int delay_count; 
void DisplayHex(int value)
{
	int lookUpTable[16];
	
	lookUpTable[0] = 0x3F;
	lookUpTable[1] = 0x6;
	lookUpTable[2] = 0x5B;
	lookUpTable[3] = 0x4F;
	lookUpTable[4] = 0x66;
	lookUpTable[5] = 0x6D;
	lookUpTable[6] = 0x7D;
	lookUpTable[7] = 0x7;
	lookUpTable[8] = 0x7F;
	lookUpTable[9] = 0x6F;
	lookUpTable[10] = 0x77;
	lookUpTable[11] = 0x7F;
	lookUpTable[12] = 0xF;
	lookUpTable[13] = 0x7F;
	lookUpTable[14] = 0x4F;
	lookUpTable[15] = 0x47;
	if(value < 16)
	{
	*(HEX_ptr) = lookUpTable[value];
	}
	else
	{
		*(HEX_ptr) = 0x0;
	}
	
	
	
}

int ReadSwitches(void)
{
	volatile int a;
	a = *(SW_ptr) &= 0xF;
	return a;
	
}
	
int main(void) {
//volatile int * SW_ptr = (int *)SW_BASE;
//volatile int * HEX_ptr = (int *)HEX3_HEX0_BASE;
DELAY_LENGTH = 700000;
	
	while(1)
	{
		
		if(status == 1)
		{
			status = 0;
			
			*(HEX_ptr) &= 0x0;
		}
		else if(status == 0)
		{
			status = 1;
			DisplayHex(ReadSwitches());
		}
		for (delay_count = DELAY_LENGTH; delay_count != 0; --delay_count);
	}
	
	
}
