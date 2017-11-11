/**
 * \file libpower.c
 * \author Tobias Rörstam
 * \date 11 Nov 2017
 * \brief Innehåller implementeringen av funktioner för beräkning av effektutvecklingen över en resistor.
 */

#include "libpower.h"

float calc_power_r(float volt, float resistance)
{
  return volt * volt / resistance;
}

float calc_power_i(float volt, float current)
{
  return volt * current;
}
