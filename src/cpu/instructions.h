#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "../types.h"
#include "cpu.h"

#define INSTRUCTION_SEI 0x78
#define INSTRUCTION_CLD 0xD8

extern cpu_instruction_t instructions[0xFF];

void load_instructions();

#endif