#include "bus.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../assert.h"

void bus_create(bus_t* bus) {
  memory_create(&bus->ram, 0x0800, 0x00);
  memory_create(&bus->ppu, 0x08, 0x2000);
  memory_create(&bus->apu_io, 0x20, 0x4000);
  memory_create(&bus->rom, 0xBFE0, 0x4020);
}

void bus_destroy(bus_t* bus) {
  memory_destroy(&bus->ram);
  memory_destroy(&bus->ppu);
  memory_destroy(&bus->apu_io);
  memory_destroy(&bus->rom);
}

real_memory_t get_real_memory(bus_t* bus, u16 address) {
  real_memory_t real_memory;

  if (address >= 0x4020) {
    real_memory.memory = &bus->rom;
    real_memory.address = address;
    return real_memory;
  }

  if (address < 0x2000) {
    real_memory.memory = &bus->ram;
    real_memory.address = address % 0x0800;
    return real_memory;
  }

  if (address < 0x4000) {
    real_memory.memory = &bus->ppu;
    real_memory.address = address % 0x08 + 0x2000;
    return real_memory;
  }

  real_memory.memory = &bus->apu_io;
  real_memory.address = address;
  return real_memory;
}

u8 bus_read8(bus_t* bus, u16 address) {
  real_memory_t real_memory = get_real_memory(bus, address);

  return memory_read8(real_memory.memory, real_memory.address);
}

void bus_write8(bus_t* bus, u16 address, u8 value) {
  real_memory_t real_memory = get_real_memory(bus, address);

  memory_write8(real_memory.memory, real_memory.address, value);
}

u16 bus_read16(bus_t* bus, u16 address) {
  u8 low = bus_read8(bus, address);
  u8 high = bus_read8(bus, address + 1);

  return (high << 8) + low;
}

void bus_write16(bus_t* bus, u16 address, u16 value) {
  u8 low = value & 0xFF;
  u8 high = value >> 8;

  bus_write8(bus, address, low);
  bus_write8(bus, address + 1, high);
}

u8* bus_get_pointer_with_size(bus_t* bus, u16 address, u16 size) {
  real_memory_t real_memory = get_real_memory(bus, address);

  if (real_memory.memory->end < real_memory.address + size - 1) {
    return 0;
  }

  u16 offset = address - real_memory.memory->start;
  return real_memory.memory->data + offset;
}

static void bus_save_all_state(bus_t* bus, char* filename) {
  FILE* file = fopen(filename, "wb");
  if (!file) ASSERT_NOT_REACHED;

  u8* content = malloc(0xFFFF * sizeof(u8));
  if (!content) ASSERT_NOT_REACHED;

  memset(content, 0, 0xFFFF);
  memcpy(content, bus->ram.data, bus->ram.size);
  memcpy(content + bus->ppu.start, bus->ppu.data, bus->ppu.size);
  memcpy(content + bus->apu_io.start, bus->apu_io.data, bus->apu_io.size);
  memcpy(content + bus->rom.start, bus->rom.data, bus->rom.size);

  fwrite(content, sizeof(u8), 0xFFFF, file);

  free(content);
  fclose(file);
}

void bus_save_state(bus_t* bus) {
  bus_save_all_state(bus, "state/all.state");

  memory_save_state(&bus->ram, "state/ram.state");
  memory_save_state(&bus->ppu, "state/ppu.state");
  memory_save_state(&bus->apu_io, "state/apu_io.state");
  memory_save_state(&bus->rom, "state/rom.state");
}
