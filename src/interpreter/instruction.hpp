#ifndef INSTRUCTION
#define INSTRUCTION

#include <string>
#include "mnemonics.hpp"

namespace NB32
{
	class Instruction
	{
		public:
			virtual std::string instructionAsString()  = 0;
			virtual int execute() = 0;
			static const int CODE_OK = 0;
			static const int CODE_HALT = 1;
			static const int CODE_PARAMETER_ERROR = -1;
			static const int CODE_INSTRUCTION_ERROR = -2;
			static const int CODE_NOT_IMPLEMENTED = -3;
		
		protected:
			std::string mnemonic;
	};
}

#endif
