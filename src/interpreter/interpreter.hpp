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
#include "branch/bzs.hpp"
#include "branch/bzc.hpp"
#include "branch/bvc.hpp"
#include "branch/bvs.hpp"
#include "branch/bnc.hpp"
#include "branch/bns.hpp"
#include "branch/bcc.hpp"
#include "branch/bcs.hpp"
#include "branch/bbc.hpp"
#include "branch/bbs.hpp"
#include "move/move.hpp"
#include "subroutine/call.hpp"
#include "subroutine/ret.hpp"
#include "1math/inc.hpp"
#include "1math/dec.hpp"
#include "1math/neg.hpp"
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
