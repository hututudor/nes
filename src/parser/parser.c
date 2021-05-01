#include "parser.h"

#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "../assert.h"

static u8* load_file(char* filename) {
  FILE* file = fopen(filename, "rb");
  if (!file) ASSERT_NOT_REACHED;

  fseek(file, 0, SEEK_END);
  u32 file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  u8* data = malloc(file_size * sizeof(u8));
  if (!data) ASSERT_NOT_REACHED;

  fread(data, sizeof(u8), file_size, file);
  fclose(file);

  return data;
}

static b8 is_magic_number_valid(parser_header_t* header) {
  return header->magic[0] == 'N' && header->magic[1] == 'E' &&
         header->magic[2] == 'S' && header->magic[3] == 0x1A;
}

static u8 get_mapper(parser_header_t* header) {
  u8 lower = header->flag6 >> 4;
  u8 higher = header->flag7 >> 4;

  return (higher << 4) + lower;
}

static b8 has_trainer(parser_header_t* header) {
  return !!(header->flag6 & 0x4);
}

void parse_and_load(bus_t* bus, char* filename) {
  u8* data = load_file(filename);

  parser_header_t* header = (parser_header_t*)data;
  if (!is_magic_number_valid(header)) ASSERT_NOT_REACHED;

  u8 mapper = get_mapper(header);
  if (mapper != 0) ASSERT_NOT_REACHED;

  if (has_trainer(header)) ASSERT_NOT_REACHED;
  if (header->prg_size != 1) ASSERT_NOT_REACHED;

  u8* first_bank = bus_get_pointer_with_size(bus, 0x8000, 0x4000);
  memcpy(first_bank, data + 16, 0x4000);

  u8* second_bank = bus_get_pointer_with_size(bus, 0xC000, 0x4000);
  memcpy(second_bank, data + 16, 0x4000);

  free(data);
}