#include "task.h"

void mppt_task() {
  while (1) {
    mppt_update(&mppt, pv_voltage_mv, pv_current_ma);
  }
}

void boost_converter_sensor_task() {
  while (1) {
    pv_voltage_mv = read_voltage_mV(&boost_converter_ina);
    pv_current_ma = read_current_mA(&boost_converter_ina);
  }
}

void power_mode_stm_task() {
  while (1) {
    state_logic(&power_mode_stm, battery_voltage, exit_SAFE_1);
  }
}
