#ifndef CPU_H
#define CPU_H

#include "../bus/bus.h"
#include "../types.h"

typedef struct {
  u16 pc;
  u8 a;
  u8 x;
  u8 y;
  u8 s;
  struct {
    u8 c : 1;
    u8 z : 1;
    u8 i : 1;
    u8 d : 1;
    u8 b : 1;
    u8 v : 1;
    u8 n : 1;
  } p;
  bus_t* bus;
  b8 is_running;
} cpu_t;

typedef struct {
  u8 value;
  u16 address;
} cpu_address_mode_t;

typedef struct {
  void (*handler)(cpu_t* cpu, cpu_address_mode_t am);
  cpu_address_mode_t (*am)(cpu_t* cpu);
  char* mnemonic;
  u8 extraBytes;
} cpu_instruction_t;

void cpu_create(cpu_t* cpu, bus_t* bus);

void cpu_execute(cpu_t* cpu);
void cpu_print_debug(cpu_t* cpu);

u8 cpu_fetch8(cpu_t* cpu);
u16 cpu_fetch16(cpu_t* cpu);

void cpu_push8(cpu_t* cpu, u8 value);
void cpu_push16(cpu_t* cpu, u16 value);

u8 cpu_pop8(cpu_t* cpu);
u16 cpu_pop16(cpu_t* cpu);

void cpu_handle_n(cpu_t* cpu, u8 value);
void cpu_handle_z(cpu_t* cpu, u8 value);

u8 cpu_get_sr(cpu_t* cpu);
void cpu_set_sr(cpu_t* cpu, u8 sr);

void cpu_call_interrupt(cpu_t* cpu, u16 address);
void cpu_call_nmi(cpu_t* cpu);
void cpu_call_irq(cpu_t* cpu);

cpu_address_mode_t address_mode_i(cpu_t* cpu);
cpu_address_mode_t address_mode_imm(cpu_t* cpu);
cpu_address_mode_t address_mode_a(cpu_t* cpu);
cpu_address_mode_t address_mode_zp(cpu_t* cpu);
cpu_address_mode_t address_mode_r(cpu_t* cpu);
cpu_address_mode_t address_mode_ind_a(cpu_t* cpu);
cpu_address_mode_t address_mode_a_x(cpu_t* cpu);
cpu_address_mode_t address_mode_a_y(cpu_t* cpu);
cpu_address_mode_t address_mode_zp_x(cpu_t* cpu);
cpu_address_mode_t address_mode_zp_y(cpu_t* cpu);
cpu_address_mode_t address_mode_ind_zp_x(cpu_t* cpu);
cpu_address_mode_t address_mode_ind_zp_y(cpu_t* cpu);

void cpu_lda(cpu_t* cpu, cpu_address_mode_t am);
void cpu_ldx(cpu_t* cpu, cpu_address_mode_t am);
void cpu_ldy(cpu_t* cpu, cpu_address_mode_t am);

void cpu_sta(cpu_t* cpu, cpu_address_mode_t am);
void cpu_stx(cpu_t* cpu, cpu_address_mode_t am);
void cpu_sty(cpu_t* cpu, cpu_address_mode_t am);

void cpu_adc(cpu_t* cpu, cpu_address_mode_t am);
void cpu_sbc(cpu_t* cpu, cpu_address_mode_t am);

void cpu_inc(cpu_t* cpu, cpu_address_mode_t am);
void cpu_inx(cpu_t* cpu, cpu_address_mode_t am);
void cpu_iny(cpu_t* cpu, cpu_address_mode_t am);

void cpu_dec(cpu_t* cpu, cpu_address_mode_t am);
void cpu_dex(cpu_t* cpu, cpu_address_mode_t am);
void cpu_dey(cpu_t* cpu, cpu_address_mode_t am);

void cpu_asl(cpu_t* cpu, cpu_address_mode_t am);
void cpu_lsr(cpu_t* cpu, cpu_address_mode_t am);
void cpu_rol(cpu_t* cpu, cpu_address_mode_t am);
void cpu_ror(cpu_t* cpu, cpu_address_mode_t am);
void cpu_and(cpu_t* cpu, cpu_address_mode_t am);
void cpu_ora(cpu_t* cpu, cpu_address_mode_t am);
void cpu_eor(cpu_t* cpu, cpu_address_mode_t am);

void cpu_cmp(cpu_t* cpu, cpu_address_mode_t am);
void cpu_cpx(cpu_t* cpu, cpu_address_mode_t am);
void cpu_cpy(cpu_t* cpu, cpu_address_mode_t am);
void cpu_bit(cpu_t* cpu, cpu_address_mode_t am);

void cpu_bcc(cpu_t* cpu, cpu_address_mode_t am);
void cpu_bcs(cpu_t* cpu, cpu_address_mode_t am);
void cpu_bne(cpu_t* cpu, cpu_address_mode_t am);
void cpu_beq(cpu_t* cpu, cpu_address_mode_t am);
void cpu_bpl(cpu_t* cpu, cpu_address_mode_t am);
void cpu_bmi(cpu_t* cpu, cpu_address_mode_t am);
void cpu_bvc(cpu_t* cpu, cpu_address_mode_t am);
void cpu_bvs(cpu_t* cpu, cpu_address_mode_t am);

void cpu_tax(cpu_t* cpu, cpu_address_mode_t am);
void cpu_txa(cpu_t* cpu, cpu_address_mode_t am);
void cpu_tay(cpu_t* cpu, cpu_address_mode_t am);
void cpu_tya(cpu_t* cpu, cpu_address_mode_t am);
void cpu_tsx(cpu_t* cpu, cpu_address_mode_t am);
void cpu_txs(cpu_t* cpu, cpu_address_mode_t am);

void cpu_pha(cpu_t* cpu, cpu_address_mode_t am);
void cpu_pla(cpu_t* cpu, cpu_address_mode_t am);
void cpu_php(cpu_t* cpu, cpu_address_mode_t am);
void cpu_plp(cpu_t* cpu, cpu_address_mode_t am);

void cpu_jmp(cpu_t* cpu, cpu_address_mode_t am);
void cpu_jsr(cpu_t* cpu, cpu_address_mode_t am);
void cpu_rts(cpu_t* cpu, cpu_address_mode_t am);
void cpu_rti(cpu_t* cpu, cpu_address_mode_t am);

void cpu_clc(cpu_t* cpu, cpu_address_mode_t am);
void cpu_sec(cpu_t* cpu, cpu_address_mode_t am);
void cpu_cld(cpu_t* cpu, cpu_address_mode_t am);
void cpu_sed(cpu_t* cpu, cpu_address_mode_t am);
void cpu_cli(cpu_t* cpu, cpu_address_mode_t am);
void cpu_sei(cpu_t* cpu, cpu_address_mode_t am);
void cpu_clv(cpu_t* cpu, cpu_address_mode_t am);

void cpu_brk(cpu_t* cpu, cpu_address_mode_t am);

void cpu_nop(cpu_t* cpu, cpu_address_mode_t am);

#endif