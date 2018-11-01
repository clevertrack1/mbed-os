/*!
 *****************************************************************************
 * @file:    system.h
 * @brief:   CMSIS Cortex-M3 Device Peripheral Access Layer Header File
 *           for the ADI ADuCxxx Device Series
 * @version: $Revision: 32908 $
 * @date:    $Date: 2015-12-03 04:38:45 -0500 (Thu, 03 Dec 2015) $
 *-----------------------------------------------------------------------------
 *
 * Copyright (C) 2009-2013 ARM Limited. All rights reserved.
 *
 * ARM Limited (ARM) is supplying this software for use with Cortex-M3
 * processor based microcontrollers.  This file can be freely distributed
 * within development tools that are supporting such ARM based processors.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *****************************************************************************/


/*! \addtogroup SYS_Driver System Interfaces
 *  @{
 * add result types to doxygen
 */

#ifndef __SYSTEM_ADUCM350_H__
#define __SYSTEM_ADUCM350_H__

#ifdef __cplusplus
 extern "C" {
#endif 

extern uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
extern void SetSysClock(void);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_H__ */


/*@}*//*
** EOF
*/
