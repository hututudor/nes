#include "cpu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../assert.h"
#include "instructions.h"

// static u16 get_cpu_nmi_vector(cpu_t* cpu) {
//   return bus_read16(cpu->bus, 0xFFFA);
// }

static u16 get_cpu_reset_vector(cpu_t* cpu) {
  return bus_read16(cpu->bus, 0xFFFC);
}

// static u16 get_cpu_irq_vector(cpu_t* cpu) {
//   return bus_read16(cpu->bus, 0xFFFE);
// }

void cpu_create(cpu_t* cpu, bus_t* bus) {
  load_instructions();

  memset(cpu, 0, sizeof(cpu_t));

  // TODO: find a way to set this to 0x34
  // cpu->p = 0x34;

  cpu->bus = bus;
  cpu->pc = get_cpu_reset_vector(cpu);
  cpu->is_running = TRUE;
}

void cpu_execute(cpu_t* cpu) {
  if (cpu->is_running) {
    cpu_instruction_t instruction = instructions[cpu_fetch8(cpu)];

    cpu_address_mode_t am = instruction.am(cpu);
    instruction.handler(cpu, am);
  }
}

u8 cpu_fetch8(cpu_t* cpu) { return bus_read8(cpu->bus, cpu->pc++); }

u16 cpu_fetch16(cpu_t* cpu) {
  cpu->pc += 2;
  return bus_read16(cpu->bus, cpu->pc - 2);
}

void handle_n(cpu_t* cpu, u8 value) { cpu->p.n = (value & 0x80) >> 7; }
void handle_z(cpu_t* cpu, u8 value) { cpu->p.z = (value == 0); }

void cpu_lda(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->a = am.value;

  handle_n(cpu, cpu->a);
  handle_z(cpu, cpu->a);
}

void cpu_ldx(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->x = am.value;

  handle_n(cpu, cpu->x);
  handle_z(cpu, cpu->x);
}

void cpu_ldy(cpu_t* cpu, cpu_address_mode_t am) {
  cpu->y = am.value;

  handle_n(cpu, cpu->y);
  handle_z(cpu, cpu->y);
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
void cpu_inx(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_iny(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

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
void cpu_bit(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_bcc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bcs(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bne(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_beq(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bpl(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bmi(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bvc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_bvs(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_tax(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_txa(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_tay(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_tya(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_tsx(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_txs(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_pha(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_pla(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_php(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_plp(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_jmp(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_jsr(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_rts(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_rti(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_clc(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_sec(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_cld(cpu_t* cpu, cpu_address_mode_t am) { cpu->p.d = 0; }

void cpu_sed(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
void cpu_cli(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_sei(cpu_t* cpu, cpu_address_mode_t am) { cpu->p.i = 1; }

void cpu_clv(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_brk(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }

void cpu_nop(cpu_t* cpu, cpu_address_mode_t am) { ASSERT_NOT_REACHED; }
