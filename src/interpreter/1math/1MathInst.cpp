#include "1MathInst.hpp"
#include <string>

using namespace std;
namespace NB32
{
	Math1Inst::Math1Inst(string instructionString) 
	{
		string r = instructionString.substr(29, 3);
		
		this->reg = stoi(r, nullptr, 2);
	}
	
	std::string Math1Inst::instructionAsString()
	{
		string inst(this->mnemonic);
		
		inst += "   $";
		
		inst += to_string(this->reg);
		
		
		return inst;
	}
	
}
