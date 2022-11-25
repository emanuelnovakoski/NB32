#include "mul.hpp"

using namespace std;
namespace NB32
{	
	Mul::Mul(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_MUL_MNEMONIC;
	}
	int Mul::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
