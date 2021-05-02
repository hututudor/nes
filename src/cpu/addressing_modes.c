#include "../assert.h"
#include "cpu.h"

cpu_address_mode_t address_mode_i(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};
  return ret;
}

cpu_address_mode_t address_mode_imm(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};

  ret.value = cpu_fetch8(cpu);

  return ret;
}

cpu_address_mode_t address_mode_a(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};

  ret.address = cpu_fetch16(cpu);
  ret.value = bus_read8(cpu->bus, ret.address);

  return ret;
}

cpu_address_mode_t address_mode_zp(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};
  ASSERT_NOT_REACHED;
  return ret;
}

cpu_address_mode_t address_mode_r(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};

  i8 relative = cpu_fetch8(cpu);
  ret.address = cpu->pc + relative;

  return ret;
}

cpu_address_mode_t address_mode_ind_a(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};
  ASSERT_NOT_REACHED;
  return ret;
}

cpu_address_mode_t address_mode_a_x(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};

  ASSERT_NOT_REACHED;
  return ret;
}

cpu_address_mode_t address_mode_a_y(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};
  ASSERT_NOT_REACHED;
  return ret;
}

cpu_address_mode_t address_mode_zp_x(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};
  ASSERT_NOT_REACHED;
  return ret;
}

cpu_address_mode_t address_mode_zp_y(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};
  ASSERT_NOT_REACHED;
  return ret;
}

cpu_address_mode_t address_mode_ind_zp_x(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};
  ASSERT_NOT_REACHED;
  return ret;
}

cpu_address_mode_t address_mode_ind_zp_y(cpu_t* cpu) {
  cpu_address_mode_t ret = {0};
  ASSERT_NOT_REACHED;
  return ret;
}
