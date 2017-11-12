/**@file calc_resistance.c
 * @brief Implementation of the calc_resistance function in calc_resistance.h
 * @author Simon Groenberg
 * @bug No known bugs *
 */

#include "calc_resistance.h"

/**
 * @brief This function calculates the equivalent resistance of resistor
 * networks
 * @param count The number of connected resistors
 * @param conn The type of connection, 'S' for serial or 'P' for parallel
 * @param array a pointer to an array that keeps the resistance of each 
 * connected resistor
 * @return The equivalent resistance
 *
 **/
float calc_resistance(int count, char conn, float* array){
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
