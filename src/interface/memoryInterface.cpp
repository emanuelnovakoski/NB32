#include "memoryInterface.hpp"
using namespace std;

namespace NB32
{	
	void formatString(string str);
	int MemoryInterface::interfaceCounter = 1;
	
	MemoryInterface::MemoryInterface(Memory* memory)
	{
		if (MemoryInterface::interfaceCounter > MAX_WINDOWS)
			throw "Max memory windows exceeded";
		
		int xpos = COLS - MemoryInterface::interfaceCounter*WINDOW_WIDTH;
		this->window = newwin(LINES, WINDOW_WIDTH, 0, xpos);
		
		box(this->window, 0 , 0);	
		
		
		
		this->ram = memory;
		
		this->memoryPointer = 76;
		

		MemoryInterface::interfaceCounter++;
		
		mvwprintw(this->window, 0, 1, "MEMORY");	
		
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
		int topElement, amountOfElements;
		
		amountOfElements = (LINES-2)/4;
		
		if (middleElement < (LINES-2)/2)
			middleElement = (LINES-2)/2;
		else
			if (middleElement + (LINES-2)/2 > MEM_SIZE)
				middleElement = MEM_SIZE - (LINES-2)/2 - 1;
		
		// finds the element that should be on top
		topElement = middleElement - (int)((amountOfElements)/2) * 4;
		
		
		memSegment = this->ram->read(topElement, LINES-2);
		
		for (int i=0; i+3<memSegment.size(); i+=4)
		{
			//to_string(topElement+i);
			
			// build address
			std::stringstream ss;
			ss << std::hex << std::setfill('0') << std::setw(6) << topElement+i;
			string index = ss.str();
			
			// build dword as string
			string d(" ");
			d = d +	 memSegment[i] + " ";
			d = d + memSegment[i+1] + " ";
			d = d + memSegment[i+2] + " ";
			d = d + memSegment[i+3];
			
			// build dword as number
			string iChar(d);
			iChar.erase (std::remove (iChar.begin(), iChar.end(), ' '), iChar.end());
			
			
			long iDecimal = stol(iChar, nullptr, 2);
			
			// print address
			wattron(this->window, A_BOLD);
			wattron(this->window, A_STANDOUT);
			wattron(this->window, A_UNDERLINE);
			mvwprintw(this->window, i+1, 1, "0x%s", (index + ":").c_str());
			wattroff(this->window, A_BOLD);
			wattroff(this->window, A_STANDOUT);
			wattroff(this->window, A_UNDERLINE);
			
			// print binary value of dword
			wprintw(this->window, "%s", d.c_str());
			
			mvwprintw(this->window, i+2, 1, "Instruction: ");
			
			// print instruction representation
			Instruction* instruction = Nb32Interpreter::interpret(iChar);
			if (instruction == nullptr)
				wprintw(this->window, "    NOT AN INSTRUCTION ");
			else
				wprintw(this->window, "    %s ", instruction->instructionAsString().c_str());
			
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
