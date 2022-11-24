#include <string>
#include "mnemonics.hpp"

namespace NB32
{
	class Instruction
	{
		public:
			virtual std::string instructionAsString()  = 0;;
			virtual void execute() = 0;;
		
		protected:
			std::string mnemonic;
	};
}
