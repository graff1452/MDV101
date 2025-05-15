#include <cstdint>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

class BittyEmulator
{
public:
	BittyEmulator() = default;
	~BittyEmulator() = default;
	uint16_t 	Evaluate(uint16_t instruction);
	uint16_t 	GetRegisterValue(uint16_t reg_num);
	uint16_t    GetPCValue();
	uint16_t    GetInstructionMemoryValue(uint16_t address);
	uint16_t 	GetRegisterMemoryValue(uint16_t address);
	uint16_t    GetRegisterCValue();
	void 		SetRegisterValue(uint16_t reg_num, uint16_t value);
	void        SetPCValue(uint16_t pc);
	void        SetInstructionMemoryValue(uint16_t address, uint16_t value);
	void 		SetRegisterMemoryValue(uint16_t address, uint16_t value);
	void        SetRegisterCValue(uint16_t value);
	void        ResetRegisters();
	void        ResetInstructionMemory(); // Reset all memory to 0
	void 		ResetRegisterMemory();
	void 		ResetPC(); // Reset Program Counter to 0
	void        ResetRegisterC(); // Reset Register C to 0
	uint16_t    Step();
	bool 	  LoadInstructionMemoryFromFile(const std::string& filename, uint16_t start_address);
private:
	std::vector<uint16_t> registers_ = std::vector<uint16_t>(8, 0); // 8 registers
	std::vector<uint16_t> instruction_memory_ = std::vector<uint16_t>(256, 0); // 256 memory locations
	std::vector<uint16_t> register_memory_ = std::vector<uint16_t>(8, 0);
	uint16_t 	pc_ = 0; // Program Counter
	uint16_t 	register_c = 0; // Register C output
};