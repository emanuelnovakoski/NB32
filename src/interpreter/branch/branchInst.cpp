#include "branchInst.hpp"
#include <string>

using namespace std;
namespace NB32
{
	BranchInst::BranchInst(string instructionString) 
	{
		string r = instructionString.substr(29, 3);
		string m = instructionString.substr(25, 3);
		
		this->reg = stoi(r, nullptr, 2);
		this->mode = stoi(m, nullptr, 2);
	}
	
	std::string BranchInst::instructionAsString()
	{
		return this->mnemonic;
	}
	
}
