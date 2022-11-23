#include <ncurses.h>
#include <iomanip>
#include <algorithm>
#include "../processor/memory.hpp"
#define WINDOW_WIDTH 47
#define MAX_WINDOWS 2
#define IMM_HEX_XPOS 33
#define IMM_DEC_XPOS 19

// TODO decouple this class from the actual processor implementation

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
