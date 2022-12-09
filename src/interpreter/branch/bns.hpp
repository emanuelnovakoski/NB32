#ifndef BNS
#define BNS

#include "branchInst.hpp"

namespace NB32
{
	class Bns : public BranchInst
	{
		public:
			Bns(std::string instructionString);
			int execute();
	};
}

#endif
