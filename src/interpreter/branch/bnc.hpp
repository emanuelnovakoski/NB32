#ifndef BNC
#define BNC

#include "branchInst.hpp"

namespace NB32
{
	class Bnc : public BranchInst
	{
		public:
			Bnc(std::string instructionString);
			int execute();
	};
}

#endif
