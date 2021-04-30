#include <stdio.h>
#include <stdlib.h>

#include "bus/bus.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("USAGE: %s ROM\n", argv[0]);
    return 0;
  }

  bus_t bus;

  bus_create(&bus);

  bus_write8(&bus, 0x0001, 0x20);
  bus_write8(&bus, 0x0804, 0x30);
  bus_write8(&bus, 0x4200, 0x10);
  bus_write8(&bus, 0xFFFF, 0xF8);

  bus_save_state(&bus);
  // bus_destroy(&bus);
}