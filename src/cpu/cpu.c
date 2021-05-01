#include "cpu.h"

#include <stdio.h>
#include <string.h>

static u16 get_cpu_nmi_vector(cpu_t* cpu) {
  return bus_read16(cpu->bus, 0xFFFA);
}

static u16 get_cpu_reset_vector(cpu_t* cpu) {
  return bus_read16(cpu->bus, 0xFFFC);
}

static u16 get_cpu_irq_vector(cpu_t* cpu) {
  return bus_read16(cpu->bus, 0xFFFE);
}

void cpu_create(cpu_t* cpu, bus_t* bus) {
  memset(cpu, 0, sizeof(cpu_t));

  // TODO: find a way to set this to 0x34
  // cpu->p = 0x34;

  cpu->bus = bus;
  cpu->pc = get_cpu_reset_vector(cpu);
  cpu->is_running = TRUE;
}

void cpu_execute(cpu_t* cpu) {
  printf("executing\n");
  cpu->pc++;
}

void cpu_print_debug(cpu_t* cpu) {
  printf("PC: %04X A: %02X X: %02X Y: %02X S: %02X\n", cpu->pc, cpu->a, cpu->x,
         cpu->y, cpu->s);
  printf("C: %d Z: %d I: %d D: %d B: %d V: %d N: %d\n", cpu->p.c, cpu->p.z,
         cpu->p.i, cpu->p.d, cpu->p.b, cpu->p.v, cpu->p.n);
}
