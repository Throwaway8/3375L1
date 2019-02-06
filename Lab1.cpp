#include <iostream>
#include "address_map_arm.h"
using namespace std;


int main(void)
{

	volatile int * SW_ptr = (int *)SW_BASE;
	volatile int * HEX_ptr = (int *)HEX3_HEX0_BASE;
	while (1)
	{
		if ((*(SW_ptr) &= 0x1FF) == 0x0)
		{
			*(HEX_ptr) |= 0x3F;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x1)
		{
			*(HEX_ptr) |= 0x6;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x2)
		{
			*(HEX_ptr) |= 0x5B;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x3)
		{
			*(HEX_ptr) |= 0x4F;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x4)
		{
			*(HEX_ptr) |= 0x66;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x5)
		{
			*(HEX_ptr) |= 0x6D;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x6)
		{
			*(HEX_ptr) |= 0x7D;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x7)
		{
			*(HEX_ptr) |= 0x7;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x8)
		{
			*(HEX_ptr) |= 0x7F;
		}
		else if ((*(SW_ptr) &= 0x1FF) == 0x9)
		{
			*(HEX_ptr) |= 0x6F;
		}
		else
		{
			*(HEX_ptr) |= 0x0;
		}

	}
}