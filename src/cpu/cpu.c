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

  cpu_set_sr(cpu, 0x01);

  cpu->bus = bus;
  cpu->pc = get_cpu_reset_vector(cpu);
  cpu->s = 0xFD;
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

void cpu_push8(cpu_t* cpu, u8 value) {
  bus_write8(cpu->bus, 0x0100 + cpu->s--, value);
}

void cpu_push16(cpu_t* cpu, u16 value) {
  cpu_push8(cpu, value >> 8);
  cpu_push8(cpu, value & 0xFF);
}

void cpu_handle_n(cpu_t* cpu, u8 value) { cpu->p.n = (value & 0x80) >> 7; }
void cpu_handle_z(cpu_t* cpu, u8 value) { cpu->p.z = (value == 0); }

u8 cpu_get_sr(cpu_t* cpu) {
  u8 ret = 0;

  ret += cpu->p.n;
  ret <<= 1;

  ret += cpu->p.v;
  ret <<= 1;

  ret += 1;
  ret <<= 1;

  ret += cpu->p.b;
  ret <<= 1;

  ret += cpu->p.d;
  ret <<= 1;

  ret += cpu->p.i;
  ret <<= 1;

  ret += cpu->p.z;
  ret <<= 1;

  ret += cpu->p.c;
  ret <<= 1;

  return ret;
}

void cpu_set_sr(cpu_t* cpu, u8 sr) {
  cpu->p.c = sr & 1;
  sr >>= 1;

  cpu->p.z = sr & 1;
  sr >>= 1;

  cpu->p.i = sr & 1;
  sr >>= 1;

  cpu->p.d = sr & 1;
  sr >>= 1;

  cpu->p.b = sr & 1;
  sr >>= 2;

  cpu->p.v = sr & 1;
  sr >>= 1;

  cpu->p.n = sr & 1;
  sr >>= 1;
}

void cpu_call_interrupt(cpu_t* cpu, u16 address) {}

void cpu_call_nmi(cpu_t* cpu);
void cpu_call_irq(cpu_t* cpu);