#include "memory.hpp"

using namespace std;
namespace NB32
{

	Memory::Memory()
	{
		for (int i=0; i<MEM_SIZE; i++)
		{
			strcpy(this->memoryBlock[i], "00000000");
		}
	}

	int Memory::read(char* buffer[], int index, int length)
	{
		if (index + length > MEM_SIZE)
		{
			// Out of bounds error
			return -1;
		}
		char* fromMemory = (char*) malloc(sizeof(char)*length*9);
		for (int i=0; i<length; i++)
		{
			//cout << "Here is i " << i << endl;
			buffer[i] = (char*) malloc(sizeof(char)*9);
			//cout << strlen(buffer[i]) << endl;
			//cout << strlen(this->memoryBlock[index+i]) << endl;
			strcpy(buffer[i], this->memoryBlock[index+i]);
			//strcat(fromMemory, this->memoryBlock[index+i]);
		}
		return 0;

	}
	
	int Memory::store(int index, int length, char value[][9])
	{
		
		if (index + length > MEM_SIZE)
		{
			// Out of bounds error
			return -1;
		}
		
		for (int i=0; i<length; i++)
		{
			strcpy(this->memoryBlock[index+i], value[i]);
		} 
		
		return 0;
	}
	
	void Memory::dumpMemoryToFile(char* filename)
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
		
	}
}
