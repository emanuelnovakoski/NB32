#include "xor.hpp"

using namespace std;
namespace NB32
{	
	Xor::Xor(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_XOR_MNEMONIC;
	}
	int Xor::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
