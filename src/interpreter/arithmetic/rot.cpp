#include "rot.hpp"

using namespace std;
namespace NB32
{	
	Rot::Rot(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_ROT_MNEMONIC;
	}
	int Rot::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
