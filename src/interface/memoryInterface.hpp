#include <ncurses.h>
#include <iomanip>
#include <algorithm>
#include "../processor/memory.hpp"
#include "../interpreter/interpreter.hpp"
#define WINDOW_WIDTH 47
#define MAX_WINDOWS 2
#define IMM_HEX_XPOS 33
#define IMM_DEC_XPOS 18

// TODO decouple processor implementation from this class

namespace NB32
{
	class MemoryInterface
	{
		private:
			WINDOW* window;
			Memory* ram;
			int memoryPointer; // TODO change this to PC
			static int interfaceCounter;
			
		public:
			MemoryInterface();
			void updatePointer(int pos);
			void refreshScreen();
			void destroyScreen();
			int getPointer();
	};
}
