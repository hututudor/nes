#ifndef PARSER_H
#define PARSER_H

#include "../bus/bus.h"
#include "../types.h"

// TODO: maybe account for flags 7-15
typedef struct __attribute__((__packed__)) {
  u8 magic[4];
  u8 prg_size;
  u8 chr_size;
  u8 flag6;
  u8 flag7;
  u8 extra[8];
} parser_header_t;

void parse_and_load(bus_t* bus, char* filename);

#endif