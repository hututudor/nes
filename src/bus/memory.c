#include "memory.h"

#include <malloc.h>
#include <string.h>

#include "../assert.h"

void memory_create(memory_t* memory, u16 size, u16 start) {
  memory->data = malloc(size * sizeof(u8));

  if (!memory->data) ASSERT_NOT_REACHED;

  memset(memory->data, 0, size);

  memory->is_allocated = TRUE;
  memory->end = start + size - 1;
  memory->start = start;
  memory->size = size;
}

void memory_destroy(memory_t* memory) {
  if (memory->is_allocated) {
    free(memory->data);
  }
}

static u16 get_index(memory_t* memory, u16 address) {
  if (!memory->is_allocated) ASSERT_NOT_REACHED;
  if (address < memory->start) ASSERT_NOT_REACHED;
  if (address > memory->end) ASSERT_NOT_REACHED;

  return address - memory->start;
}

u8 memory_read8(memory_t* memory, u16 address) {
  return memory->data[get_index(memory, address)];
}

void memory_write8(memory_t* memory, u16 address, u8 value) {
  memory->data[get_index(memory, address)] = value;
}

void memory_save_state(memory_t* memory, char* filename) {
  FILE* file = fopen(filename, "wb");
  if (!file) ASSERT_NOT_REACHED;

  if (memory->start) {
    u8* padding = malloc(memory->start * sizeof(u8));
    if (!padding) ASSERT_NOT_REACHED;

    memset(padding, 0, memory->start);
    fwrite(padding, sizeof(u8), memory->start, file);
    free(padding);
  }

  fwrite(memory->data, sizeof(u8), memory->size, file);
  fclose(file);
}
