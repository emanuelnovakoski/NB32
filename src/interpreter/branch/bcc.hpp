#ifndef BCC
#define BCC

#include "branchInst.hpp"

namespace NB32
{
	class Bcc : public BranchInst
	{
		public:
			Bcc(std::string instructionString);
			int execute();
	};
}

#endif
