#ifndef MNEMONICS
#define MNEMONICS

namespace NB32
{
	// addressing modes
	const int OPERATION_MODE_REGISTER = 0;
	const int OPERATION_MODE_POSTINCREMET = 1;
	const int OPERATION_MODE_PREDECREMENT = 2;
	const int OPERATION_MODE_INDEXED = 3;
	const int OPERATION_MODE_REGISTER_INDIRECT = 4;
	const int OPERATION_MODE_POSTINCREMET_INDIRECT = 5;
	const int OPERATION_MODE_PREDECREMENT_INDIRECT = 6;
	const int OPERATION_MODE_INDEXED_INDIRECT = 7;
	
	// instruction groups 
	// GGGG xxxx xxxx xxxx
	// xxxx xxxx xxxx xxxx
	const std::string INST_GROUP_SPECIAL = std::string("0000");
	const std::string INST_GROUP_ARITH = std::string("0001");
	const std::string INST_GROUP_BRANCH = std::string("0010");
	const std::string INST_GROUP_MEMORY = std::string("0011");
	const std::string INST_GROUP_SUBROUTINE = std::string("0100");
	const std::string INST_GROUP_1MATH = std::string("0101");
	const std::string INST_GROUP_STACK = std::string("0110");

	
	// instruction mnemonics
	// SPECIAL group
	// 0000 OOOO OOOO xxxx
	// xxxx xxxx xxxx xxxx
	const std::string INST_SPECIAL_NOP_BITCODE = std::string("00000000");
	const std::string INST_SPECIAL_NOP_MNEMONIC = std::string("NOP");
	
	const std::string INST_SPECIAL_HLT_BITCODE = std::string("00000001");
	const std::string INST_SPECIAL_HLT_MNEMONIC = std::string("HLT");
	
	
	// ARITHMETIC group
	// 0001 OOOO OOOO xxxx
	// xxxx xxxx xxxx xxxx
	const std::string INST_ARITH_ADD_BITCODE = std::string("00000000");
	const std::string INST_ARITH_ADD_MNEMONIC = std::string("ADD");
	
	const std::string INST_ARITH_SUB_BITCODE = std::string("00000001");
	const std::string INST_ARITH_SUB_MNEMONIC = std::string("SUB");
	
	const std::string INST_ARITH_MUL_BITCODE = std::string("00000010");
	const std::string INST_ARITH_MUL_MNEMONIC = std::string("MUL");
	
	const std::string INST_ARITH_DIV_BITCODE = std::string("00000011");
	const std::string INST_ARITH_DIV_MNEMONIC = std::string("DIV");
	
	const std::string INST_ARITH_MOD_BITCODE = std::string("00000100");
	const std::string INST_ARITH_MOD_MNEMONIC = std::string("MOD");
	
	const std::string INST_ARITH_AND_BITCODE = std::string("00000101");
	const std::string INST_ARITH_AND_MNEMONIC = std::string("AND");
	
	const std::string INST_ARITH_OR_BITCODE = std::string("00000110");
	const std::string INST_ARITH_OR_MNEMONIC = std::string("OR");
	
	const std::string INST_ARITH_XOR_BITCODE = std::string("00000111");
	const std::string INST_ARITH_XOR_MNEMONIC = std::string("XOR");
	
	const std::string INST_ARITH_ASL_BITCODE = std::string("00001000");
	const std::string INST_ARITH_ASL_MNEMONIC = std::string("ASL");
	
	const std::string INST_ARITH_ROT_BITCODE = std::string("00001001");
	const std::string INST_ARITH_ROT_MNEMONIC = std::string("ROT");
	

	// BRANCH group
	// 0010 OOOO OOOO xxxx
	// xxxx xxxx xxxx xxxx
	const std::string INST_BRANCH_BR_BITCODE = std::string("00000000");
	const std::string INST_BRANCH_BR_MNEMONIC = std::string("BR");
	
	const std::string INST_BRANCH_BZS_BITCODE = std::string("00000001");
	const std::string INST_BRANCH_BZS_MNEMONIC = std::string("BZS");
	
	const std::string INST_BRANCH_BZC_BITCODE = std::string("00000010");
	const std::string INST_BRANCH_BZC_MNEMONIC = std::string("BZC");
	
	const std::string INST_BRANCH_BNS_BITCODE = std::string("00000011");
	const std::string INST_BRANCH_BNS_MNEMONIC = std::string("BNS");
	
	const std::string INST_BRANCH_BNC_BITCODE = std::string("00000100");
	const std::string INST_BRANCH_BNC_MNEMONIC = std::string("BNC");
	
	const std::string INST_BRANCH_BCS_BITCODE = std::string("00000101");
	const std::string INST_BRANCH_BCS_MNEMONIC = std::string("BCS");
	
	const std::string INST_BRANCH_BCC_BITCODE = std::string("00000110");
	const std::string INST_BRANCH_BCC_MNEMONIC = std::string("BCC");
	
	const std::string INST_BRANCH_BBS_BITCODE = std::string("00000111");
	const std::string INST_BRANCH_BBS_MNEMONIC = std::string("BBS");
	
	const std::string INST_BRANCH_BBC_BITCODE = std::string("00001000");
	const std::string INST_BRANCH_BBC_MNEMONIC = std::string("BBC");
	
	const std::string INST_BRANCH_BVS_BITCODE = std::string("00001001");
	const std::string INST_BRANCH_BVS_MNEMONIC = std::string("BVS");
	
	const std::string INST_BRANCH_BVC_BITCODE = std::string("00001010");
	const std::string INST_BRANCH_BVC_MNEMONIC = std::string("BVC");
	

	// MEMORY group
	// 0011 OOOO OOOO xxxx
	// xxxx xxxx xxxx xxxx
	const std::string INST_MEMORY_MOV_BITCODE = std::string("00000000");
	const std::string INST_MEMORY_MOV_MNEMONIC = std::string("MOV");
	

	// SUBROUTINE group
	// 0100 OOOO OOOO xxxx
	// xxxx xxxx xxxx xxxx
	const std::string INST_SUBROUTINE_CALL_BITCODE = std::string("00000000");
	const std::string INST_SUBROUTINE_CALL_MNEMONIC = std::string("CALL");
	
	const std::string INST_SUBROUTINE_RET_BITCODE = std::string("00000001");
	const std::string INST_SUBROUTINE_RET_MNEMONIC = std::string("RET");
	
	// 1MATH group
	// 0101 OOOO OOOO xxxx
	// xxxx xxxx xxxx xxxx
	const std::string INST_1MATH_INC_BITCODE = std::string("00000000");
	const std::string INST_1MATH_INC_MNEMONIC = std::string("INC");
	
	const std::string INST_1MATH_DEC_BITCODE = std::string("00000001");
	const std::string INST_1MATH_DEC_MNEMONIC = std::string("DEC");
	
	const std::string INST_1MATH_NEG_BITCODE = std::string("00000010");
	const std::string INST_1MATH_NEG_MNEMONIC = std::string("NEG");
}

#endif
