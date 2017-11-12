/**
 * \file calc_power.h
 * \author Tobias Rörstam
 * \date 11 Nov 2017
 * \brief Innehåller funktioner för beräkning
 * av effektutvecklingen över en resistor.
 */

#ifndef __CALC_POWER_H__
#define __CALC_POWER_H__

/** \brief Beräknar effektutvecklingen över en resistans
 *  med hjälp av formeln P = U * U / R

 *  \param volt Spänningen över resistorn
 *  \param resistance Resistorns resistans
 *  \return Returnerar den beräknade effektutvecklingen
 */
float calc_power_r(float volt, float resistance);

/** \brief Beräknar effektutvecklingen över en resistans
 *  med hjälp av formeln P = U * I

 *  \param volt Spänningen över resistorn
 *  \param current Strömmen genom resistorn
 *  \return Returnerar den beräknade effektutvecklingen
 */
float calc_power_i(float volt, float current);

#endif
