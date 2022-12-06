/*
 * SerialJN.h
 *
 *  Created on: 06/12/2022
 *      Author: wleyb
 */

#ifndef SOURCES_SERIALJN_H_
#define SOURCES_SERIALJN_H_


#include "Util.h"

/****************************************************************************
 * DEFINITIONS
 ***************************************************************************/
#define         GPRMC   "$GPRMC,"
#define         GPGGA   "$GPGGA,"


/****************************************************************************
 * FUNCTIONS
 ***************************************************************************/
//$GPRMC,092751.000,A,5321.6802,N,00630.3371,W,0.06,31.66,280511,,,A*45

void SendNMEASentenceToServer(void);
void SendNMEASentenceToDebug(void);
uint8_t StringCompareGNSS(char *Str1, char *Str2);


#endif /* SOURCES_SERIALJN_H_ */
