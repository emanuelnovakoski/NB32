#ifndef BVS
#define BVS

#include "branchInst.hpp"

namespace NB32
{
	class Bvs : public BranchInst
	{
		public:
			Bvs(std::string instructionString);
			int execute();
	};
}

#endif
