O_SOURCE=$(wildcard ./src/processor/*.o)
O_INTERFACE_SOURCE=$(wildcard ./src/interface/*.o)
O_INTERPRETER_SOURCE=$(wildcard ./src/interpreter/*.o)
O_INTERPRETER_SPECIAL_SOURCE=$(wildcard ./src/interpreter/special/*.o)
O_INTERPRETER_ARITH_SOURCE=$(wildcard ./src/interpreter/arithmetic/*.o)
O_INTERPRETER_BRANCH_SOURCE=$(wildcard ./src/interpreter/branch/*.o)

SRC_DIR=src/processor
INTERFACE_DIR=src/interface
INTERPRETER_DIR=src/interpreter
SPECIAL_DIR=special
ARITHMETIC_DIR=arithmetic
BRANCH_DIR=branch

NB32: memory alu register registerBank memoryInterface 
	g++ $(SRC_DIR)/nb32.cpp $(O_SOURCE) $(O_INTERFACE_SOURCE) $(O_INTERPRETER_SOURCE)  $(O_INTERPRETER_SPECIAL_SOURCE) $(O_INTERPRETER_ARITH_SOURCE) $(O_INTERPRETER_BRANCH_SOURCE) -o nb32 -lncurses
	rm $(O_SOURCE) $(O_INTERFACE_SOURCE) $(O_INTERPRETER_SOURCE) $(O_INTERPRETER_SPECIAL_SOURCE) $(O_INTERPRETER_ARITH_SOURCE) $(O_INTERPRETER_BRANCH_SOURCE)
	
register:
	g++ -c $(SRC_DIR)/register.cpp -o $(SRC_DIR)/register.o

registerBank: register stateRegister
	g++ -c $(SRC_DIR)/registerBank.cpp -o $(SRC_DIR)/registerBank.o
	
stateRegister: 
	g++ -c $(SRC_DIR)/stateRegister.cpp -o $(SRC_DIR)/stateRegister.o
	
memory: 
	g++ -c $(SRC_DIR)/memory.cpp -o $(SRC_DIR)/memory.o

alu: 
	g++ -c $(SRC_DIR)/alu.cpp -o $(SRC_DIR)/alu.o

memoryInterface: memory interpreter 
	g++ -c $(INTERFACE_DIR)/memoryInterface.cpp -o $(SRC_DIR)/memoryInterface.o

branchInst: br bzs bzc bvs bvc bns bnc bcc bcs bbs bbc
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/branchInst.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/branchInst.o

specialInst: nop hlt
	g++ -c $(INTERPRETER_DIR)/$(SPECIAL_DIR)/specialInst.cpp -o $(INTERPRETER_DIR)/$(SPECIAL_DIR)/specialInst.o

arithInst: add sub mul div mod and or xor asl rot
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/arithInst.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/arithInst.o
	
interpreter: specialInst arithInst branchInst
	g++ -c $(INTERPRETER_DIR)/interpreter.cpp -o $(INTERPRETER_DIR)/interpreter.o
	
br:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/br.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/br.o
	
bzs:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bzs.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bzs.o

bzc:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bzc.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bzc.o
	
bvs:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bvs.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bvs.o

bvc:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bvc.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bvc.o
	
bns:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bns.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bns.o

bnc:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bnc.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bnc.o

bcs:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bcs.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bcs.o

bcc:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bcc.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bcc.o
	
bbs:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bbs.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bbs.o

bbc:
	g++ -c $(INTERPRETER_DIR)/$(BRANCH_DIR)/bbc.cpp -o $(INTERPRETER_DIR)/$(BRANCH_DIR)/bbc.o
	
nop:
	g++ -c $(INTERPRETER_DIR)/$(SPECIAL_DIR)/nop.cpp -o $(INTERPRETER_DIR)/$(SPECIAL_DIR)/nop.o

hlt:
	g++ -c $(INTERPRETER_DIR)/$(SPECIAL_DIR)/hlt.cpp -o $(INTERPRETER_DIR)/$(SPECIAL_DIR)/hlt.o

add:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/add.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/add.o
	
sub:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/sub.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/sub.o

mul:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/mul.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/mul.o

div:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/div.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/div.o
	
mod:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/mod.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/mod.o
	
and:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/and.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/and.o

or:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/or.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/or.o
	
xor:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/xor.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/xor.o
	
asl:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/asl.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/asl.o
	
rot:
	g++ -c $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/rot.cpp -o $(INTERPRETER_DIR)/$(ARITHMETIC_DIR)/rot.o

clean:
	rm $(O_SOURCE) $(O_INTERFACE_SOURCE) $(O_INTERPRETER_SOURCE) $(O_INTERPRETER_SPECIAL_SOURCE) $(O_INTERPRETER_BRANCH_SOURCE) nb32
