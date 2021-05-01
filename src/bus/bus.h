#ifndef BUS_H
#define BUS_H

#include "memory.h"

typedef struct {
  memory_t ram;
  memory_t ppu;
  memory_t apu_io;
  memory_t rom;
} bus_t;

typedef struct {
  memory_t* memory;
  u16 address;
} real_memory_t;

void bus_create(bus_t* bus);
void bus_destroy(bus_t* bus);

u8 bus_read8(bus_t* bus, u16 address);
void bus_write8(bus_t* bus, u16 address, u16 value);

u8* bus_get_pointer_with_size(bus_t* bus, u16 address, u16 size);

void bus_save_state(bus_t* bus);

#endif