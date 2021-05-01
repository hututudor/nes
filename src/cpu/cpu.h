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

cpu_address_mode_t address_mode_i(cpu_t* cpu);

void cpu_cld(cpu_t* cpu, cpu_address_mode_t am);
void cpu_sei(cpu_t* cpu, cpu_address_mode_t am);

#endif