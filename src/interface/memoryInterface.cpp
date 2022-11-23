#include "memoryInterface.hpp"


using namespace std;
namespace NB32
{	
	void formatString(string str);
	int MemoryInterface::interfaceCounter = 1;
	
	MemoryInterface::MemoryInterface()
	{
		if (MemoryInterface::interfaceCounter > MAX_WINDOWS)
			throw "Max memory windows exceeded";
		
		int xpos = COLS - MemoryInterface::interfaceCounter*WINDOW_WIDTH;
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
		
		
		for (int i=0; i+3<memSegment.size(); i+=4)
		{
			to_string(topElement+i);
			
			// build address
			std::stringstream ss;
			ss << std::hex << std::setfill('0') << std::setw(8) << topElement+i;
			string index = ss.str();
			
			
			// build dword as string
			string d(" ");
			d = d + memSegment[topElement+i] + " ";
			d = d + memSegment[topElement+i+1] + " ";
			d = d + memSegment[topElement+i+2] + " ";
			d = d + memSegment[topElement+i+3];
			
			// TODO change this to deduce from string d
			// build dword as number
			string iChar(d);
			iChar.erase (std::remove (iChar.begin(), iChar.end(), ' '), iChar.end());

			long iDecimal = stol(iChar, nullptr, 2);
			
			// print address
			wattron(this->window, A_BOLD);
			wattron(this->window, A_STANDOUT);
			wattron(this->window, A_UNDERLINE);
			mvwprintw(this->window, i+1, 1, (index + ":").c_str());
			wattroff(this->window, A_BOLD);
			wattroff(this->window, A_STANDOUT);
			wattroff(this->window, A_UNDERLINE);
			
			// print binary value of dword
			wprintw(this->window, d.c_str());
			
			// print hexadecimal value of dword
			mvwprintw(this->window, i+3, 3, "Immediate: ");
			mvwprintw(this->window, i+3, IMM_HEX_XPOS, "0x");
			wprintw(this->window, "%08lx ", iDecimal);
			
			// print decimal value of dwod
			wmove(this->window, i+3, IMM_DEC_XPOS);
			wprintw(this->window, "%012li ", iDecimal);
			
		}
		
		
		wrefresh(this->window);
		
	}
	
	void MemoryInterface::destroyScreen()
	{
		delwin(this->window);
	}
	
	
}
