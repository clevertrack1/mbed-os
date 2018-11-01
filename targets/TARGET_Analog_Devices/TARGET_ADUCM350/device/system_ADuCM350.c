/*********************************************************************************

Copyright (c) 2010-2014 Analog Devices, Inc. All Rights Reserved.

This software is proprietary to Analog Devices, Inc. and its licensors.  By using 
this software you agree to the terms of the associated Analog Devices Software 
License Agreement.

*********************************************************************************/

/*!
 *****************************************************************************
 * @file:    system.c
 * @brief:   System startup code for ADuCM350
 * @version: $Revision: 33058 $
 * @date:    $Date: 2015-12-17 01:26:28 -0500 (Thu, 17 Dec 2015) $
 *****************************************************************************/

/*! \addtogroup SYS_Driver System Interfaces
 *  @{
 */
#include "stdint.h"
#include "system_ADuCM350.h"

uint32_t SystemCoreClock;          /*!< System Clock Frequency (Core Clock) */
void SystemInit(void)
{
		SystemCoreClockUpdate();
}

void SystemCoreClockUpdate(void)
{
	SystemCoreClock = 1;
}

void SetSysClock(void)
{
		SystemCoreClockUpdate();
}


/*
** EOF
*/

/*@}*/
