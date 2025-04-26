#include <cstdint>
#include <vector>

class BittyEmulator
{
public:
	BittyEmulator(){};
	uint16_t 	Evaluate(uint16_t instruction);
	uint16_t 	GetRegisterValue(uint16_t reg_num);
	void 		SetRegisterValue(uint16_t reg_num, uint16_t value);
	void 		ResetRegisters() { registers_.assign(16, 0); } // Reset all registers to 0
private:
	std::vector<uint16_t> registers_ = {0};
};