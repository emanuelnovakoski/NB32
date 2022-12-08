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
		string inst(this->mnemonic);
		
		inst += "   ";
		
		switch(mode)
		{
			case OPERATION_MODE_REGISTER:
				inst += "$";
				inst += to_string(this->reg);
				break;
				
			case OPERATION_MODE_POSTINCREMET:
				inst += "($";
				inst += to_string(this->reg);
				inst += ")+";
				break;
			
			case OPERATION_MODE_PREDECREMENT:
				inst += "-($";
				inst += to_string(this->reg);
				inst += ")";
				break;
			
			case OPERATION_MODE_INDEXED:
				inst += "($";
				inst += to_string(this->reg);
				inst += ")";
				break;
				
			case OPERATION_MODE_REGISTER_INDIRECT:
				inst += "[$";
				inst += to_string(this->reg);
				inst += "]";
				break;
				
			case OPERATION_MODE_POSTINCREMET_INDIRECT:
				inst += "[($";
				inst += to_string(this->reg);
				inst += ")+]";
				break;
			
			case OPERATION_MODE_PREDECREMENT_INDIRECT:
				inst += "[-($";
				inst += to_string(this->reg);
				inst += ")]";
				break;
			
			case OPERATION_MODE_INDEXED_INDIRECT:
				inst += "[($";
				inst += to_string(this->reg);
				inst += ")]";
				break;
		}
		return inst;
	}
	
}
