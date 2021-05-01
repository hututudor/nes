#include "cpu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void print_disassembled_instruction(cpu_t* cpu) {
  u8 instruction = bus_read8(cpu->bus, cpu->pc);

  printf("> %02X: ", instruction);
  printf("%s ", instructions[instruction].mnemonic);

  switch (instructions[instruction].extraBytes) {
    case 1:
      printf("%02X", bus_read8(cpu->bus, cpu->pc + 1));
      break;

    case 2:
      printf("%04X", bus_read16(cpu->bus, cpu->pc + 1));
      break;
  }

  printf("\n");
}

void cpu_print_debug(cpu_t* cpu) {
  printf("PC: %04X A: %02X X: %02X Y: %02X S: %02X\n", cpu->pc, cpu->a, cpu->x,
         cpu->y, cpu->s);
  printf("C: %d Z: %d I: %d D: %d B: %d V: %d N: %d\n", cpu->p.c, cpu->p.z,
         cpu->p.i, cpu->p.d, cpu->p.b, cpu->p.v, cpu->p.n);

  u8 instruction = bus_read8(cpu->bus, cpu->pc);

  // TODO: fix with handler check
  if (!instructions[instruction].mnemonic) {
    printf("PANIC! INSTRUCTION NOT IMPLEMENTED: %02X AT %04X\n", instruction,
           cpu->pc);

    bus_save_state(cpu->bus);
    exit(0);
  }

  print_disassembled_instruction(cpu);
}

u8 cpu_fetch8(cpu_t* cpu) { return bus_read8(cpu->bus, cpu->pc++); }

void cpu_cld(cpu_t* cpu, cpu_address_mode_t am) { cpu->p.d = 0; }

void cpu_sei(cpu_t* cpu, cpu_address_mode_t am) { cpu->p.i = 1; }