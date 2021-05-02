#include "instructions.h"

cpu_instruction_t instructions[0xFF];

void load_instructions() {
  INST(INSTRUCTION_LDA_IMM, "[X] LDA", cpu_lda, address_mode_imm, 1);

  INST(INSTRUCTION_LDX_IMM, "[X] LDX", cpu_ldx, address_mode_imm, 1);

  INST(INSTRUCTION_LDY_IMM, "[X] LDY", cpu_ldy, address_mode_imm, 1);

  INST(INSTRUCTION_STA_A, "[a] STA", cpu_sta, address_mode_a, 2);

  INST(INSTRUCTION_STX_A, "[a] STX", cpu_stx, address_mode_a, 2);

  INST(INSTRUCTION_STY_A, "[a] STY", cpu_sty, address_mode_a, 2);

  INST(INSTRUCTION_SEI, "SEI", cpu_sei, address_mode_i, 0);
  INST(INSTRUCTION_CLD, "CLD", cpu_cld, address_mode_i, 0);
}
