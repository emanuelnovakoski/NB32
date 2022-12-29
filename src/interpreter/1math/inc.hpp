#ifndef INC
#define INC

#include "1MathInst.hpp"

namespace NB32
{
	class Inc : public Math1Inst
	{
		public:
			Inc(std::string instructionString);
			int execute();
	};
}

#endif
