/*
 * SerialDebug.h
 *
 *  Created on: 06/12/2022
 *      Author: wleyb
 */

#ifndef SOURCES_SERIALDEBUG_H_
#define SOURCES_SERIALDEBUG_H_


/****************************************************************************
 * DEFINITIONS
 ***************************************************************************/

/****************************************************************************
 * FUNCTIONS
 ***************************************************************************/
void SerialDebugEnable(void);
void SerialDebugDisable(void);
void SerialDebugSend(char *msg);
void SerialDebugSendInt(short int msg);


#endif /* SOURCES_SERIALDEBUG_H_ */
