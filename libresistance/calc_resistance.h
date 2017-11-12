/**@file 
 * @brief The function calc_resistance for calculating equivalent resistance
 * @author Simon Groenberg
 * @bug No known bugs
 */

#ifndef CALC_RESISTANCE
#define CALC_RESISTANCE

/**
 * @brief This function calculates the equivalent resistance of resistor
 * networks
 * @param count The number of connected resistors
 * @param conn The type of connection, 'S' for serial or 'P' for parallel
 * @param array a pointer to an array that keeps the resistance of each
 * connected resistor
 * @return The equivalent resistance
 */
float calc_resistance(int count, char conn, float* array);

#endif
