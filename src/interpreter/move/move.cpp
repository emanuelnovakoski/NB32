#include "move.hpp"

using namespace std;
namespace NB32
{	
	Move::Move(string instructionString) : MoveInst(instructionString)
	{
		this->mnemonic = INST_MOVE_MOVE_MNEMONIC;
	}
	int Move::execute()
	{	
		// does nothing
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
