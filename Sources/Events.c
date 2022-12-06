/* ###################################################################
**     Filename    : Events.c
**     Project     : HoleDetector
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2022-12-06, 00:51, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#include "Util.h"
#include "SerialGL.h"
#include "SerialJN.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

extern uint8_t IndexStart;
extern uint8_t IndexStop;
extern char BufferRcv[];
extern bool FlagDebugSending;

extern uint8_t IndexStart_GNSS;
extern byte GNSS_Err_flag;
extern char BufferRcv_GNSS[];
extern uint8_t IndexStop_GNSS;

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT (module Events)
**
**     Component   :  Cpu [MKL25Z128LK4]
*/
/*!
**     @brief
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the [NMI
**         interrupt] property is set to 'Enabled'.
*/
/* ===================================================================*/
void Cpu_OnNMIINT(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnError (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnError(void)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  AS1_OnRxChar (module Events)
**
**     Component   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnRxChar(void)
{
  /* Write your code here ... */
    AS1_RecvChar(&BufferRcv[IndexStop]);	//save the variable in BufferRcv[IndexStop]
    if(((char*) BufferRcv[IndexStop]) == '\r'){	//1º \r come to BufferRcv: INIT of String & Command Echo
        for(IndexStart = 0; IndexStart <= IndexStop; IndexStart++){}
        IndexStart = 0;
        IndexStop = 0;
    }
    else{
        IndexStop++;
    }
}

/*
** ===================================================================
**     Event       :  AS2_OnError (module Events)
**
**     Component   :  AS2 [AsynchroSerial]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS2_OnError(void)
{
  /* Write your code here ... */
    AS2_GetError(&GNSS_Err_flag);
}

/*
** ===================================================================
**     Event       :  AS2_OnRxChar (module Events)
**
**     Component   :  AS2 [AsynchroSerial]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled and either the <Receiver>
**         property is enabled or the <SCI output mode> property (if
**         supported) is set to Single-wire mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS2_OnRxChar(void)
{
  /* Write your code here ... */
    if(FlagDebugSending == 0){
        AS2_RecvChar(&BufferRcv_GNSS[IndexStop_GNSS]);    //receive a char in AS2 and save it in BufferRcv
        if(((char*) BufferRcv_GNSS[IndexStop_GNSS]) == '\n'){
            for(IndexStart_GNSS = 0; IndexStart_GNSS <= IndexStop_GNSS; IndexStart_GNSS++){}
            IndexStart_GNSS = 0;
            IndexStop_GNSS = 0;
        }else{
            IndexStop_GNSS++;
        }
    }
}

/*
** ===================================================================
**     Event       :  AS3_OnTxChar (module Events)
**
**     Component   :  AS3 [AsynchroSerial]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void AS3_OnTxChar(void)
{
  /* Write your code here ... */
	  FlagDebugSending = 1;
}

/*
** ===================================================================
**     Event       :  BaseTimer_OnInterrupt (module Events)
**
**     Component   :  BaseTimer [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void BaseTimer_OnInterrupt(void)
{
  /* Write your code here ... */
    extern uint16_t delay_count;
    delay_count++;
}

/*
** ===================================================================
**     Event       :  Accel_INT_OnInterrupt (module Events)
**
**     Component   :  Accel_INT [ExtInt]
**     Description :
**         This event is called when an active signal edge/level has
**         occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Accel_INT_OnInterrupt(void)
{
  /* Write your code here ... */
    bool FlagTap1 = 1;
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
