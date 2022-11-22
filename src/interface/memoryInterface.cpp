#include "memoryInterface.hpp"
#define WINDOW_WIDTH 40
#define MAX_WINDOWS 2

using namespace std;
namespace NB32
{
	int MemoryInterface::interfaceCounter = 1;
	
	MemoryInterface::MemoryInterface()
	{
		if (MemoryInterface::interfaceCounter > MAX_WINDOWS)
			throw "Max memory windows exceeded";
		
		int xpos = COLS - MemoryInterface::interfaceCounter*40;
		this->window = newwin(LINES, WINDOW_WIDTH, 0, xpos);
		
		box(this->window, 0 , 0);	
		
		this->ram = new Memory();
		
		
		this->refreshScreen();
	
		
		MemoryInterface::interfaceCounter++;
		
		this->memoryPointer = 0;
		
		
		
	}
	
	void MemoryInterface::updatePointer(int pos)
	{
		if ((pos < 0) || (pos > MEM_SIZE))
			throw "memoryPointer out of range";
		this->memoryPointer = pos;
		refreshScreen();
	}
	
	int MemoryInterface::getPointer()
	{
		return this->memoryPointer;
	}
	
	void MemoryInterface::refreshScreen()
	{
		vector<string> memSegment;
		/*
		int middleElement = this->memoryPointer;
		
		if (middleElement < (LINES-2)/2)
			middleElement = (LINES-2)/2;
		else
			if (MEM_SIZE - middleElement < (LINES-2)/2)
				middleElement = MEM_SIZE - (LINES-2)/2;
		*/
		
		vector<string> myvec = {"111111111"};
		
		this->ram->store(5, 1, myvec);
		
		memSegment = this->ram->read(4, 5);
		
		for (int i=0; i<memSegment.size(); i++)
			cout << memSegment[i] << endl;
	
		wrefresh(this->window);
	}
	
	void MemoryInterface::destroyScreen()
	{
		delwin(this->window);
	}
}
