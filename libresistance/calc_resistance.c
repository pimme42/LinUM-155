#include "calc_resistance.h"

float calc_resistance(int count, char conn, float *array){
	if (count < 0 || !array){
		return -1; /* Error if array was null or count is negative */
	}
	if (conn == 'S'){
		float rtot = 0;
		for (int i=0; i<count; i++){
      			rtot += array[i];
		}
		return rtot;
	}
	if (conn == 'P'){
		if (count < 2){
			return -1; /*Error if less than 2 resistors since 
				     atleast 2 resistors are needed for a
				     parallel conncetion */
		}
		float rinv = 0;
		for (int i=0; i<count; i++){
			if (array[i] <= 0){
				return 0;
			}
			rinv += 1/array[i];
		}
		return 1/rinv;
	}
	return -1; /* Error if neither 'S' or 'P' was input as conn */ 
}
