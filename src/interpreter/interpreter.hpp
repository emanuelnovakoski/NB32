#include "special/nop.hpp"
#include "special/hlt.hpp"
#include "arithmetic/add.hpp"
#include "arithmetic/sub.hpp"
#include "arithmetic/mul.hpp"
#include "arithmetic/div.hpp"
#include "arithmetic/mod.hpp"
#include "arithmetic/and.hpp"
#include "arithmetic/or.hpp"
#include "arithmetic/xor.hpp"
#include "arithmetic/asl.hpp"
#include "arithmetic/rot.hpp"
#include "branch/br.hpp"
#include "mnemonics.hpp"
#include <string>
namespace NB32
{
	class Nb32Interpreter
	{
		public:
			static Instruction* interpret(std::string instructionString);
	};
}
