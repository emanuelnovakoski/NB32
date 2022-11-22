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
#include <vector>

namespace NB32
{
	class Memory
	{
		private:
			std::vector<std::string> memoryBlock;
		
		public:
			Memory();
			std::vector<std::string> read(int index, int length);
			int store(int index, int length, std::vector<std::string> buffer);
			/*void dumpMemoryToFile(char* filename);
			void loadMemoryFromFile(char* filename);*/
	};
}
