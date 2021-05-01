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

void cpu_create(cpu_t* cpu, bus_t* bus);

void cpu_execute(cpu_t* cpu);
void cpu_print_debug(cpu_t* cpu);

#endif