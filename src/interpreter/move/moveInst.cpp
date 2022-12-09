#include "moveInst.hpp"
#include <string>

using namespace std;
namespace NB32
{
	std::string regAsString(int reg, int mode)
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

	MoveInst::MoveInst(string instructionString) 
	{
		string dr = instructionString.substr(29, 3);
		string dm = instructionString.substr(25, 3);
		
		string sr = instructionString.substr(21, 3);
		string sm = instructionString.substr(17, 3);
		
		this->sreg = stoi(sr, nullptr, 2);
		this->smode = stoi(sm, nullptr, 2);
		this->dreg = stoi(dr, nullptr, 2);
		this->dmode = stoi(dm, nullptr, 2);
	}
	
	std::string MoveInst::instructionAsString()
	{
		string inst(this->mnemonic);
		
		inst += "   ";
		
		inst += regAsString(this->sreg, this->smode);
		
		inst += ", ";
		
		inst += regAsString(this->dreg, this->dmode);
		
		return inst;
	}
	
}
