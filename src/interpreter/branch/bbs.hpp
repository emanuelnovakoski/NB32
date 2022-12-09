#ifndef BBS
#define BBS

#include "branchInst.hpp"

namespace NB32
{
	class Bbs : public BranchInst
	{
		public:
			Bbs(std::string instructionString);
			int execute();
	};
}

#endif
