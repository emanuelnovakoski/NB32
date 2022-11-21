#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <bitset>
#include "memory.hpp"
#include "alu.hpp"
#include <ncurses.h>


namespace NB32
{
	class Nb32
	{
		private:
			Memory* ram;
			RegisterBank* regBank;
	};
}
