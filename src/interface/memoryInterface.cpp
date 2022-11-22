#include "memoryInterface.hpp"
#define WINDOW_WIDTH 40
#define MAX_WINDOWS 2

using namespace std;
namespace NB32
{	
	void formatString(string str);
	int MemoryInterface::interfaceCounter = 1;
	
	MemoryInterface::MemoryInterface()
	{
		if (MemoryInterface::interfaceCounter > MAX_WINDOWS)
			throw "Max memory windows exceeded";
		
		int xpos = COLS - MemoryInterface::interfaceCounter*40;
		this->window = newwin(LINES, WINDOW_WIDTH, 0, xpos);
		
		box(this->window, 0 , 0);	
		
		this->ram = new Memory();
		
		this->memoryPointer = 0;
		

		MemoryInterface::interfaceCounter++;
		
		this->refreshScreen();
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
	
		int middleElement = this->memoryPointer;
		int topElement;
		
		this->ram->loadMemoryFromFile("in.txt");
		
		
		if (middleElement < (LINES-2)/2)
			middleElement = (LINES-2)/2;
		else
			if (middleElement + (LINES-2)/2 > MEM_SIZE)
				middleElement = MEM_SIZE - (LINES-2)/2 - 1;
	
		
		topElement = middleElement - (LINES-2)/2;
		
		memSegment = this->ram->read(topElement, LINES-2);
		
		
		for (int i=0; i<memSegment.size(); i++)
		{
			to_string(topElement+i);
			
			std::stringstream ss;
			ss << std::hex << std::setfill('0') << std::setw(8) << topElement+i;
			string index = ss.str();
			
			
			string dword;
			dword += memSegment[i];
			dword += memSegment[i];
			dword += memSegment[i];
			dword += memSegment[i];
	
			
			mvwprintw(this->window, i+1, 1, (index + ": " + memSegment[i]).c_str());
			
			
		}
		
		
	
		wrefresh(this->window);

	}
	
	void MemoryInterface::destroyScreen()
	{
		delwin(this->window);
	}
	
	
}
