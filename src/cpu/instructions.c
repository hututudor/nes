#include "instructions.h"

cpu_instruction_t instructions[0xFF];

void load_instructions() {
  instructions[INSTRUCTION_SEI].mnemonic = "SEI";
  instructions[INSTRUCTION_SEI].extraBytes = 0;
  instructions[INSTRUCTION_SEI].am = address_mode_i;
  instructions[INSTRUCTION_SEI].handler = cpu_sei;

  instructions[INSTRUCTION_CLD].mnemonic = "CLD";
  instructions[INSTRUCTION_CLD].extraBytes = 0;
  instructions[INSTRUCTION_CLD].am = address_mode_i;
  instructions[INSTRUCTION_CLD].handler = cpu_cld;
}
