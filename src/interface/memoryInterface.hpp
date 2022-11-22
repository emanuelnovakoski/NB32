#include <ncurses.h>
#include "../processor/memory.hpp"

namespace NB32
{
	class MemoryInterface
	{
		private:
			WINDOW* window;
			Memory* ram;
			int memoryPointer;
			static int interfaceCounter;
			
		public:
			MemoryInterface();
			void updatePointer(int pos);
			void refreshScreen();
			void destroyScreen();
			int getPointer();
	};
}
