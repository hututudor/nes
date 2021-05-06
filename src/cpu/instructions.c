#include "instructions.h"

#include "../assert.h"

cpu_instruction_t instructions[0xFF];

void load_instructions() {
  // #define INSTRUCTION_LDA_A 0xAD
  // #define INSTRUCTION_LDA_A_X 0xBD
  // #define INSTRUCTION_LDA_A_Y 0xB9
  INST(INSTRUCTION_LDA_IMM, "[#] LDA", cpu_lda, address_mode_imm, 1);
  // #define INSTRUCTION_LDA_ZP 0xA5
  // #define INSTRUCTION_LDA_IND_ZP_X 0xA1
  // #define INSTRUCTION_LDA_ZP_X 0xB5
  // #define INSTRUCTION_LDA_IND_ZP_Y 0xB1

  // #define INSTRUCTION_LDX_A 0xAE
  // #define INSTRUCTION_LDX_A_Y 0xBE
  INST(INSTRUCTION_LDX_IMM, "[#] LDX", cpu_ldx, address_mode_imm, 1);
  // #define INSTRUCTION_LDX_ZP 0xA6
  // #define INSTRUCTION_LDX_ZP_Y 0xB6

  // #define INSTRUCTION_LDY_A 0xAC
  // #define INSTRUCTION_LDY_A_Y 0xBC
  INST(INSTRUCTION_LDY_IMM, "[#] LDY", cpu_ldy, address_mode_imm, 1);
  // #define INSTRUCTION_LDY_ZP 0xA4
  // #define INSTRUCTION_LDY_ZP_X 0xB4

  INST(INSTRUCTION_STA_A, "[a] STA", cpu_sta, address_mode_a, 2);
  // #define INSTRUCTION_STA_A_X 0x9D
  // #define INSTRUCTION_STA_A_Y 0x99
  // #define INSTRUCTION_STA_ZP 0x85
  // #define INSTRUCTION_STA_IND_ZP_X 0x81
  // #define INSTRUCTION_STA_ZP_X 0x95
  // #define INSTRUCTION_STA_IND_ZP_Y 0x91

  INST(INSTRUCTION_STX_A, "[a] STX", cpu_stx, address_mode_a, 2);
  // #define INSTRUCTION_STX_ZP 0x86
  // #define INSTRUCTION_STX_ZP_Y 0x96

  INST(INSTRUCTION_STY_A, "[a] STY", cpu_sty, address_mode_a, 2);
  // #define INSTRUCTION_STY_ZP 0x84
  // #define INSTRUCTION_STY_ZP_X 0x94

  // #define INSTRUCTION_ADC_A 0x6D
  // #define INSTRUCTION_ADC_A_X 0x7D
  // #define INSTRUCTION_ADC_A_Y 0x79
  // #define INSTRUCTION_ADC_IMM 0x69
  // #define INSTRUCTION_ADC_ZP 0x65
  // #define INSTRUCTION_ADC_IND_ZP_X 0x61
  // #define INSTRUCTION_ADC_ZP_X 0x75
  // #define INSTRUCTION_ADC_IND_ZP_Y 0x71

  // #define INSTRUCTION_SBC_A 0xED
  // #define INSTRUCTION_SBC_A_X 0xFD
  // #define INSTRUCTION_SBC_A_Y 0xF9
  // #define INSTRUCTION_SBC_IMM 0xE9
  // #define INSTRUCTION_SBC_ZP 0xE5
  // #define INSTRUCTION_SBC_IND_ZP_X 0xE1
  // #define INSTRUCTION_SBC_ZP_X 0xF5
  // #define INSTRUCTION_SBC_IND_ZP_Y 0xF1

  // #define INSTRUCTION_INC_A 0xEE
  // #define INSTRUCTION_INC_A_X 0xFE
  // #define INSTRUCTION_INC_ZP 0xE6
  // #define INSTRUCTION_INC_ZP_X 0xF6

  INST(INSTRUCTION_INX, "INX", cpu_inx, address_mode_i, 0);
  INST(INSTRUCTION_INY, "INY", cpu_iny, address_mode_i, 0);

  // #define INSTRUCTION_DEC_A 0xCE
  // #define INSTRUCTION_DEC_A_X 0xDE
  // #define INSTRUCTION_DEC_ZP 0xC6
  // #define INSTRUCTION_DEC_ZP_X 0xD6

  // #define INSTRUCTION_DEX 0xCA
  // #define INSTRUCTION_DEY 0x88

  // #define INSTRUCTION_ASL_A 0x0E
  // #define INSTRUCTION_ASL_A_X 0x1E
  // #define INSTRUCTION_ASL_REG_A 0x0A
  // #define INSTRUCTION_ASL_ZP 0x06
  // #define INSTRUCTION_ASL_ZP_X 0x16

  // #define INSTRUCTION_LSR_A 0x4E
  // #define INSTRUCTION_LSR_A_X 0x5E
  // #define INSTRUCTION_LSR_REG_A 0x4A
  // #define INSTRUCTION_LSR_ZP 0x46
  // #define INSTRUCTION_LSR_ZP_X 0x56

  // #define INSTRUCTION_ROL_A 0x2E
  // #define INSTRUCTION_ROL_A_X 0x3E
  // #define INSTRUCTION_ROL_REG_A 0x2A
  // #define INSTRUCTION_ROL_ZP 0x26
  // #define INSTRUCTION_ROL_ZP_X 0x36

  // #define INSTRUCTION_ROR_A 0x6E
  // #define INSTRUCTION_ROR_A_X 0x7E
  // #define INSTRUCTION_ROR_REG_A 0x6A
  // #define INSTRUCTION_ROR_ZP 0x66
  // #define INSTRUCTION_ROR_ZP_X 0x76

  // #define INSTRUCTION_AND_A 0x2D
  // #define INSTRUCTION_AND_A_X 0x3D
  // #define INSTRUCTION_AND_A_Y 0x39
  // #define INSTRUCTION_AND_IMM 0x29
  // #define INSTRUCTION_AND_ZP 0x25
  // #define INSTRUCTION_AND_IND_ZP_X 0x21
  // #define INSTRUCTION_AND_ZP_X 0x35
  // #define INSTRUCTION_AND_IND_ZP_Y 0x31

  // #define INSTRUCTION_ORA_A 0x0D
  // #define INSTRUCTION_ORA_A_X 0x1D
  // #define INSTRUCTION_ORA_A_Y 0x19
  // #define INSTRUCTION_ORA_IMM 0x09
  // #define INSTRUCTION_ORA_ZP 0x05
  // #define INSTRUCTION_ORA_IND_ZP_X 0x01
  // #define INSTRUCTION_ORA_ZP_X 0x15
  // #define INSTRUCTION_ORA_IND_ZP_Y 0x11

  // #define INSTRUCTION_EOR_A 0x4D
  // #define INSTRUCTION_EOR_A_X 0x5D
  // #define INSTRUCTION_EOR_A_Y 0x59
  // #define INSTRUCTION_EOR_IMM 0x49
  // #define INSTRUCTION_EOR_ZP 0x45
  // #define INSTRUCTION_EOR_IND_ZP_X 0x41
  // #define INSTRUCTION_EOR_ZP_X 0x55
  // #define INSTRUCTION_EOR_IND_ZP_Y 0x51

  // #define INSTRUCTION_CMP_A 0xCD
  // #define INSTRUCTION_CMP_A_X 0xDD
  // #define INSTRUCTION_CMP_A_Y 0xD9
  // #define INSTRUCTION_CMP_IMM 0xC9
  // #define INSTRUCTION_CMP_ZP 0xC5
  // #define INSTRUCTION_CMP_IND_ZP_X 0xC1
  // #define INSTRUCTION_CMP_ZP_X 0xD5
  // #define INSTRUCTION_CMP_IND_ZP_Y 0xD1

  // #define INSTRUCTION_CPX_A 0xEC
  // #define INSTRUCTION_CPX_IMM 0xE0
  // #define INSTRUCTION_CPX_ZP 0xE4

  // #define INSTRUCTION_CPY_A 0xCC
  // #define INSTRUCTION_CPY_IMM 0xC0
  // #define INSTRUCTION_CPY_ZP 0xC4

  INST(INSTRUCTION_BIT_A, "[a] BIT", cpu_bit, address_mode_a, 2);
  // #define INSTRUCTION_BIT_IMM 0x89
  // #define INSTRUCTION_BIT_ZP 0x24

  // #define INSTRUCTION_BCC_R 0x90
  // #define INSTRUCTION_BCS_R 0xB0
  // #define INSTRUCTION_BNE_R 0xD0
  // #define INSTRUCTION_BEQ_R 0xF0
  INST(INSTRUCTION_BPL_R, "[r] BPL", cpu_bpl, address_mode_r, 1);
  // #define INSTRUCTION_BMI_R 0x30
  // #define INSTRUCTION_BVC_R 0x50
  // #define INSTRUCTION_BVS_R 0x70

  INST(INSTRUCTION_TAX, "TAX", cpu_tax, address_mode_i, 0);
  INST(INSTRUCTION_TXA, "TXA", cpu_txa, address_mode_i, 0);
  INST(INSTRUCTION_TAY, "TAY", cpu_tay, address_mode_i, 0);
  INST(INSTRUCTION_TYA, "TYA", cpu_tya, address_mode_i, 0);
  INST(INSTRUCTION_TSX, "TSX", cpu_tsx, address_mode_i, 0);
  INST(INSTRUCTION_TXS, "TXS", cpu_txs, address_mode_i, 0);

  // #define INSTRUCTION_PHA 0x48
  // #define INSTRUCTION_PLA 0x68
  // #define INSTRUCTION_PHP 0x08
  // #define INSTRUCTION_PLP 0x28

  // #define INSTRUCTION_JMP_A 0x4C
  // #define INSTRUCTION_JMP_IND_A 0x6C

  INST(INSTRUCTION_JSR_A, "JSR", cpu_jsr, address_mode_a, 2);

  // #define INSTRUCTION_RTS 0x60
  INST(INSTRUCTION_RTI, "RTI", cpu_rti, address_mode_i, 0);

  // #define INSTRUCTION_CLC 0x18
  // #define INSTRUCTION_SEC 0x38
  INST(INSTRUCTION_CLD, "CLD", cpu_cld, address_mode_i, 0);
  // #define INSTRUCTION_SED 0xF8
  // #define INSTRUCTION_CLI 0x58
  INST(INSTRUCTION_SEI, "SEI", cpu_sei, address_mode_i, 0);
  // #define INSTRUCTION_CLV 0xB8

  // #define INSTRUCTION_BRK 0x00
  // #define INSTRUCTION_NOP 0xEA
}

void cpu_lda(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->a = am.value;

  cpu_handle_n(cpu, cpu->a);
  cpu_handle_z(cpu, cpu->a);
}

void cpu_ldx(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->x = am.value;

  cpu_handle_n(cpu, cpu->x);
  cpu_handle_z(cpu, cpu->x);
}

void cpu_ldy(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->y = am.value;

  cpu_handle_n(cpu, cpu->y);
  cpu_handle_z(cpu, cpu->y);
}

void cpu_sta(cpu_t* cpu, cpu_address_mode_t am) {
  bus_write8(cpu->bus, am.address, cpu->a);
}

void cpu_stx(cpu_t* cpu, cpu_address_mode_t am) {
  bus_write8(cpu->bus, am.address, cpu->x);
}

void cpu_sty(cpu_t* cpu, cpu_address_mode_t am) {
  bus_write8(cpu->bus, am.address, cpu->y);
}

void cpu_adc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_sbc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_inc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_inx(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->x++;

  cpu_handle_n(cpu, cpu->x);
  cpu_handle_z(cpu, cpu->x);
}

void cpu_iny(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->y++;

  cpu_handle_n(cpu, cpu->y);
  cpu_handle_z(cpu, cpu->y);
}

void cpu_dec(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_dex(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_dey(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_asl(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_lsr(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_rol(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_ror(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_and(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_ora(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_eor(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_cmp(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_cpx(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_cpy(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_bit(cpu_t* cpu, cpu_address_mode_t am) {
  u8 res = cpu->a & am.value;

  cpu->p.n = res >> 7;
  cpu->p.v = (res >> 6) & 1;

  cpu_handle_z(cpu, res);
}

void cpu_bcc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bcs(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bne(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_beq(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_bpl(cpu_t* cpu, cpu_address_mode_t am) {
  if (cpu->p.n == 0) {
    cpu->pc = am.address;
  }
}

void cpu_bmi(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bvc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bvs(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_tax(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->x = cpu->a;

  cpu_handle_n(cpu, cpu->x);
  cpu_handle_z(cpu, cpu->x);
}

void cpu_txa(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->a = cpu->x;

  cpu_handle_n(cpu, cpu->a);
  cpu_handle_z(cpu, cpu->a);
}

void cpu_tay(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->y = cpu->a;

  cpu_handle_n(cpu, cpu->y);
  cpu_handle_z(cpu, cpu->y);
}

void cpu_tya(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->a = cpu->y;

  cpu_handle_n(cpu, cpu->a);
  cpu_handle_z(cpu, cpu->a);
}

void cpu_tsx(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->x = cpu->s;

  cpu_handle_n(cpu, cpu->x);
  cpu_handle_z(cpu, cpu->x);
}

void cpu_txs(cpu_t* cpu, cpu_address_mode_t am) { cpu->s = cpu->x; }

void cpu_pha(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_pla(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_php(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_plp(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_jmp(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_jsr(cpu_t* cpu, cpu_address_mode_t am) {
  cpu_push16(cpu, cpu->pc - 1);
  cpu->pc = am.address;
}

void cpu_rts(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_rti(cpu_t* cpu, cpu_address_mode_t am) {
  cpu_set_sr(cpu, cpu_pop8(cpu));
  cpu->pc = cpu_pop16(cpu);
}

void cpu_clc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_sec(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_cld(cpu_t* cpu, cpu_address_mode_t am) { cpu->p.d = 0; }

void cpu_sed(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_cli(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_sei(cpu_t* cpu, cpu_address_mode_t am) { cpu->p.i = 1; }

void cpu_clv(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_brk(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_nop(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }