#include "memory.hpp"

using namespace std;
namespace NB32
{

	Memory::Memory()
	{
		for (int i=0; i<MEM_SIZE; i++)
		{
			memoryBlock.push_back("00000000");
		}
	}

	vector<string> Memory::read(int index, int length)
	{
		vector<string> rVec;
		if ((index + length > MEM_SIZE) || (index + length < 0))
		{
			cout << "Out of bounds\n";
			// Out of bounds error
			return rVec;
		}

		for (int i=0; i<length; i++)
		{
			rVec.push_back(this->memoryBlock[index+i]);
		}
		return rVec;
	}
	
	int Memory::store(int index, int length, vector<string> buffer)
	{
		if ((index + length > MEM_SIZE) || (index < 0))
		{
			// Out of bounds error
			return -1;
		}
		
		for (int i=0; i<length; i++)
		{
			this->memoryBlock[index+i] = buffer[i];
		} 
		
		return 0;
	}
	
/*	void Memory::dumpMemoryToFile(char* filename)
	{
		FILE* dump = fopen(filename, "w");
		
		for (int i=0; i<MEM_SIZE; i++)
		{
			fputs(this->memoryBlock[i], dump);
			fputs("\n", dump);
		}
	}
	
	void Memory::loadMemoryFromFile(char* filename)
	{
		FILE* file = fopen(filename, "r");
		
		for (int i=0; i<10; i++)
		{
			char example[10];
			fgets(example, 10, file);
			
			example[8] = '\0';
//			for (int i=0; i<9; i++)
				//cout << (int) example[i] << " ";
//			cout << endl;
//			cout << example << endl;;
			strcpy(this->memoryBlock[i], example);
		}
		
	}*/
}
