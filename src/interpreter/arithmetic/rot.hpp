#ifndef ROT
#define ROT
#include "arithInst.hpp"


namespace NB32
{
	class Rot : public ArithInst
	{
		public:
			Rot(std::string instructionString);
			int execute();
	};
}

#endif
