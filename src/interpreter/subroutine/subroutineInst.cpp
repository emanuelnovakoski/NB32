#include "subroutineInst.hpp"
#include <string>

using namespace std;
namespace NB32
{
	// TODO REFACTOR ME
	std::string SubroutineInst::getregAsString(int reg, int mode)
	{
		std::string inst("");
		switch(mode)
		{
			case OPERATION_MODE_REGISTER:
				inst += "$";
				inst += to_string(reg);
				break;
				
			case OPERATION_MODE_POSTINCREMET:
				inst += "($";
				inst += to_string(reg);
				inst += ")+";
				break;
			
			case OPERATION_MODE_PREDECREMENT:
				inst += "-($";
				inst += to_string(reg);
				inst += ")";
				break;
			
			case OPERATION_MODE_INDEXED:
				inst += "($";
				inst += to_string(reg);
				inst += ")";
				break;
				
			case OPERATION_MODE_REGISTER_INDIRECT:
				inst += "[$";
				inst += to_string(reg);
				inst += "]";
				break;
				
			case OPERATION_MODE_POSTINCREMET_INDIRECT:
				inst += "[($";
				inst += to_string(reg);
				inst += ")+]";
				break;
			
			case OPERATION_MODE_PREDECREMENT_INDIRECT:
				inst += "[-($";
				inst += to_string(reg);
				inst += ")]";
				break;
			
			case OPERATION_MODE_INDEXED_INDIRECT:
				inst += "[($";
				inst += to_string(reg);
				inst += ")]";
				break;
		}
		return inst;
	}

	SubroutineInst::SubroutineInst(string instructionString) 
	{
		string dr = instructionString.substr(29, 3);
		string dm = instructionString.substr(25, 3);

		
		this->reg = stoi(dr, nullptr, 2);
		this->mode = stoi(dm, nullptr, 2);

	}
	
	std::string SubroutineInst::instructionAsString()
	{
		string inst(this->mnemonic);
		
		// return has no parameters
		if (inst == INST_SUBROUTINE_RET_MNEMONIC)
			return inst;
		
		inst += "   ";
		
		inst += getregAsString(this->reg, this->mode);
		
		
		return inst;
	}
	
}
