#include "libpower/libpower.h"
#include "libcomponent/e_resistance.h"
#include "libresistance/libresistance.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Läser in heltal
  output är texten som ska skriva ut
  input är en pekare till var heltalet ska sparas */
void read_int(char* output, int* input) {
  char tmp[20];
  printf("%s", output);
  fgets(tmp, 10, stdin);
  *input = atoi(tmp);
}

/* Läser in flyttal
  output är texten som ska skriva ut
  input är en pekare till var flyttalet ska sparas */
void read_float(char* output, float* input) {
  char tmp[20];
  printf("%s", output);
  fgets(tmp, 20, stdin);
  *input = atof(tmp);
}

/* Läser in ett tecken och kastar bort resterande tecken på raden.
  output är texten som ska skriva ut
  input är en pekare till var tecknet ska sparas */
void read_char(char* output, char* input) {
  char tmp[10] = "\0";
  printf("%s", output);
  fgets(tmp, 10, stdin);
  *input = tmp[0];
}


int main(int argc, char *argv[]) {
  char text[30];
  int V, num, i, num_res;
  char type;
  float *array, res_array[3];
  float resistance;

  /* Läser in data */
  read_int("Ange spänningskälla i V: ", &V);
  read_char("Ange koppling[S | P]: ", &type);
  read_int("Antal komponenter: ", &num);

  /* Skapar arrayen som ska innehålla komponenternas resistanser */
  array = calloc(num, sizeof(float));
  /* Läser in resistanserna */
  for(i = 0; i < num; ++i) {
    sprintf(text, "Komponent %d i ohm: ", i+1);
    read_float(text, &array[i]);
  }

  /* Beräknar ersättningsresistansen */
  resistance = calc_resistance(num, type, array);
  /* Kolla om calc_resistance har returnerat -1,
    vilket infikerar att felaktig data har skrivits in */
  if(fabs(resistance + 1.0f) < 0.0001) {
    printf("Felaktig data inmatad!\n");
    /* Avsluta programmet och returnera -1 till terminalen */
    return -1;
  }

  /* Ta fram ersättningsresistanserna */
  num_res = e_resistance(resistance, res_array);

  printf("Ersättningsresistans: \n%.1f ohm\n", resistance);
  printf("Effekt: \n%.2f W\n", calc_power_r(V, resistance));
  printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");
  if(num_res == 0)
    printf("Inga ersättningsresistanser hittades!\n");
  for(i = 0; i < num_res; ++i)
    printf("%.0f\n", res_array[i]);

  free(array);
	return 0;
}
