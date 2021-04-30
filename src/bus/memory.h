#ifndef MEMORY_H
#define MEMORY_H

#include "../types.h"

typedef struct {
  u8* data;
  u16 start;
  u16 end;
  u16 size;
  b8 is_allocated;
} memory_t;

void memory_create(memory_t* memory, u16 size, u16 start);
void memory_destroy(memory_t* memory);

u8 memory_read8(memory_t* memory, u16 address);
void memory_write8(memory_t* memory, u16 address, u8 value);

void memory_save_state(memory_t* memory, char* filename);

#endif