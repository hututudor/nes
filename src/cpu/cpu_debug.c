#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"
#include "instructions.h"

static void print_disassembled_instruction(cpu_t* cpu) {
  u8 instruction = bus_read8(cpu->bus, cpu->pc);

  printf("INSTRUCTION 0x%02X: ", instruction);
  printf("%s ", instructions[instruction].mnemonic);

  switch (instructions[instruction].extraBytes) {
    case 1:
      printf("0x%02X", bus_read8(cpu->bus, cpu->pc + 1));
      break;

    case 2:
      printf("0x%04X", bus_read16(cpu->bus, cpu->pc + 1));
      break;
  }

  printf("\n");
}

void cpu_print_debug(cpu_t* cpu) {
  printf("PC: 0x%04X  A: 0x%02X  X: 0x%02X  Y: 0x%02X  S: 0x%02X\n", cpu->pc,
         cpu->a, cpu->x, cpu->y, cpu->s);
  printf("C: %d Z: %d I: %d D: %d B: %d V: %d N: %d\n", cpu->p.c, cpu->p.z,
         cpu->p.i, cpu->p.d, cpu->p.b, cpu->p.v, cpu->p.n);

  u8 instruction = bus_read8(cpu->bus, cpu->pc);

  // TODO: fix with handler check
  if (!instructions[instruction].mnemonic) {
    printf("PANIC! INSTRUCTION NOT IMPLEMENTED: 0x%02X AT 0x%04X\n",
           instruction, cpu->pc);

    bus_save_state(cpu->bus);
    exit(0);
  }

  print_disassembled_instruction(cpu);
}
