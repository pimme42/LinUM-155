#include "libpower.h"
#include <stdio.h>

int main()
{
  float R = 120.32;
  float V = 1.3222;
  float I = 10.674533;

  printf("power_r: %f x %f / %f = %f\n", V, V, R, calc_power_r(V, R));
  printf("power_i: %f x %f = %f\n", V, I, calc_power_i(V, I));
  return 0;
}
