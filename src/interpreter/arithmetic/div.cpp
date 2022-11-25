#include "div.hpp"

using namespace std;
namespace NB32
{	
	Div::Div(string instructionString) : ArithInst(instructionString)
	{
		this->mnemonic = INST_ARITH_DIV_MNEMONIC;
	}
	int Div::execute()
	{	
		// TODO
		return Instruction::CODE_NOT_IMPLEMENTED;
	}
}
