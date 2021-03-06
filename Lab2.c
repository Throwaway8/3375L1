#include "address_map_arm.h"
//Stop watch program
volatile int * load_ptr = (int*)HPS_TIMER0_BASE;
volatile int * currVal_ptr = (int*)HPS_TIMER0_BASE + 1;
volatile int * ctrl_ptr = (int*)HPS_TIMER0_BASE + 2;
volatile int * endInterrupt_ptr = (int*)HPS_TIMER0_BASE + 3;
volatile int * interrupt_ptr = (int*)HPS_TIMER0_BASE + 4;
volatile int * hex_ptr = (int*)HEX3_HEX0_BASE;
volatile int * hex_ptr2 = (int*)HEX5_HEX4_BASE;
volatile int * Key_ptr = (int*)KEY_BASE;

void start()
{
	int count = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	int count5 = 0;
	int lookUpTable[10];
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
	
	*(hex_ptr) = 0x3F;
		*(hex_ptr + 1) = 0x3F;
		*(hex_ptr+2) = 0x3F;
		*(hex_ptr+3) = 0x3F;
		*(hex_ptr2) = 0x3F;
		*(hex_ptr2+1) = 0x3F;
	
	while (1)
	{
		*(ctrl_ptr) &= 0x000;
		*(load_ptr) |= 0xF4240;
		*(ctrl_ptr) |= 0b011;

		if (*(interrupt_ptr) &= 0b1 == 1)
		{
			*(hex_ptr) = *lookUpTable + 1;
			count++;
			if (count == 9)
			{
				*(hex_ptr+1) = *lookUpTable + 1;
				count = 0;
				count2++;
				if (count2 == 9)
				{
					*(hex_ptr + 2) = *lookUpTable + 1;
					count2 = 0;
					count3++;
					if (count3 == 0)
					{
						*(hex_ptr+3) = *lookUpTable + 1;
						count3 = 0;
						count4++;
						if (count4 == 9)
						{
							*(hex_ptr2) = *lookUpTable + 1;
							count4 = 0;
							count5++;
							if (count5 == 9)
							{
								*(hex_ptr2+1) = *lookUpTable + 1;
								count5 = 0;
							}
						}
					}
				}
			}
		}
	}
}

void reset()
{
	*(ctrl_ptr) |= 0b100;
	*(interrupt_ptr) |= 0b1;
	*(load_ptr) &= 0x0;
	*(ctrl_ptr) |= 0x1;
}

void stop()
{
	*(ctrl_ptr) &= 0x0;
}


int main(void) {


	while (1)
	{
		if ((*(Key_ptr) &= 0b1) == 1 && (*(Key_ptr) &= 0b10) == 0 && (*(Key_ptr) &= 0b100) == 0)
		{
			start();
			*(Key_ptr) &= 0x0;
		}
		else if ((*(Key_ptr) &= 0b1) == 0 && (*(Key_ptr) &= 0b10) == 1 && (*(Key_ptr) &= 0b100) == 0)
		{
			stop();
			*(Key_ptr) &= 0x0;
		}
		else if ((*(Key_ptr) &= 0b1) == 0 && (*(Key_ptr) &= 0b10) == 0 && (*(Key_ptr) &= 0b100) == 1)
		{
			reset();
			*(Key_ptr) &= 0x0;
		}
		else
		{
			*(Key_ptr) &= = 0x0;
		}
	}
}
