#ifndef MOVE
#define MOVE

#include "moveInst.hpp"

namespace NB32
{
	class Move : public MoveInst
	{
		public:
			Move(std::string instructionString);
			int execute();
	};
}

#endif
