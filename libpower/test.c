/**
 * \file test.c
 * \author Tobias Rörstam
 * \date 11 Nov 2017
 * \brief Ett program för att testa biblioteket libpower.so
 */

#include "calc_power.h"
#include <stdio.h>

/** \brief Main-funktionen som testar libpower.so.
 *  \return Returnerar 0 till terminalen.
 */
int main()
{
  float R = 12; /** R är resistansen vi vill räkna med */
  float V = 120; /** V är spänningen vi vill räkna med */
  float I = 10; /** I är strömmen vi vill räkna med */

  printf("power_r: %f x %f / %f = %f\n", V, V, R, calc_power_r(V, R));
  printf("power_i: %f x %f = %f\n", V, I, calc_power_i(V, I));
  return 0;
}
