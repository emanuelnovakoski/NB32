#include "arithInst.hpp"
#include <string>

using namespace std;
namespace NB32
{
	ArithInst::ArithInst(string instructionString) 
	{
		string ra, rb, rr;
		
		rr = instructionString.substr(17, 3);
		ra = instructionString.substr(25, 3);
		rb = instructionString.substr(29, 3);
		
		this->rega = stoi(ra, nullptr, 2);
		this->regb = stoi(rb, nullptr, 2);
		this->regr = stoi(rr, nullptr, 2);
		
	}
	
	std::string ArithInst::instructionAsString()
	{
		return this->mnemonic + "   " + "$" + to_string(this->regr) + ", $" + to_string(this->rega) + ", $" + to_string(this->regb);
	}
	
}
