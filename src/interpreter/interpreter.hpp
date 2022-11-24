#include "special/nop.hpp"
#include "special/hlt.hpp"
#include "mnemonics.hpp"
#include <string>
namespace NB32
{
	class Nb32Interpreter
	{
		public:
			/*static const int OK = 0;
			static const int INST_PARSING_ERROR = 1;
			static const int INST_GROUP_ERROR = 2;
			static const int INST_OP_ERROR = 3;
			static const int INST_PARAM_ERROR = 4;*/
			static Instruction* interpret(std::string instructionString);
	};
}
