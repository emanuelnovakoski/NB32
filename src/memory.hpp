#define MEM_SIZE 4096
#define MEM_LENGTH_BYTE 1
#define MEM_LENGTH_WORD 2
#define MEM_LENGTH_DWORD 4

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <bits/stdc++.h>

namespace NB32
{
	class Memory
	{
		private:
			char memoryBlock[MEM_SIZE][9];
		
		public:
			Memory();
			int read(char* buffer[], int index, int length);
			int store(int index, int length, char value[][9]);
			void dumpMemoryToFile(char* filename);
			void loadMemoryFromFile(char* filename);
	};
}
