#include "instructions.h"

cpu_instruction_t instructions[0xFF];

void load_instructions() {
  INST(INSTRUCTION_SEI, "SEI", cpu_sei, address_mode_i, 0);
  INST(INSTRUCTION_CLD, "CLD", cpu_cld, address_mode_i, 0);
}
