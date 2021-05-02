#include <stdio.h>
#include <stdlib.h>

#include "bus/bus.h"
#include "cpu/cpu.h"
#include "parser/parser.h"

#define DEBUG FALSE

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("USAGE: %s ROM\n", argv[0]);
    return 0;
  }

  bus_t bus;
  bus_create(&bus);

  parse_and_load(&bus, argv[1]);

  cpu_t cpu;
  cpu_create(&cpu, &bus);

  while (cpu.is_running) {
    cpu_print_debug(&cpu);
    cpu_execute(&cpu);

    if (DEBUG)
      getchar();
    else
      printf("\n");
  }

  bus_save_state(&bus);
  bus_destroy(&bus);
}