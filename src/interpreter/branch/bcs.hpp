#ifndef BCS
#define BCS

#include "branchInst.hpp"

namespace NB32
{
	class Bcs : public BranchInst
	{
		public:
			Bcs(std::string instructionString);
			int execute();
	};
}

#endif
