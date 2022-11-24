#include "specialInst.hpp"
#include <string>

using namespace std;
namespace NB32
{
	SpecialInst::SpecialInst()
	{
		
	}
	std::string SpecialInst::instructionAsString()
	{
		return this->mnemonic;
	}
	
}
