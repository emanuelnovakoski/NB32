#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <bitset>
#include "alu.hpp"
#include <ncurses.h>
#include "../interface/memoryInterface.hpp"


namespace NB32
{
	static const std::string USAGE_STRING = std::string("Usage: nb32 [flags]\n\nFlags:\n\r\t-h --help\t\tPrints this message.\n\r\t-l --load [filename]\tLoads filename to memory on startup.\n\r\t-pc [address]\t\tInitializes PC on this address\n");
	class Nb32
	{
		private:
			RegisterBank* regBank;
	};
}
