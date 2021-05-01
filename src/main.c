#include <stdio.h>
#include <stdlib.h>

#include "bus/bus.h"
#include "parser/parser.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("USAGE: %s ROM\n", argv[0]);
    return 0;
  }

  bus_t bus;
  bus_create(&bus);

  parse_and_load(&bus, argv[1]);

  bus_save_state(&bus);
  bus_destroy(&bus);
}