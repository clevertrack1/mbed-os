/**************************************************************************//**
 * @file     startup_ARMCM3.c
 * @brief    CMSIS Core Device Startup File for
 *           ARMCM3 Device
 * @version  V5.3.1
 * @date     09. July 2018
 ******************************************************************************/
/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
*/

#include "ADuCM350.h"


/*----------------------------------------------------------------------------
  Linker generated Symbols
 *----------------------------------------------------------------------------*/
extern uint32_t __etext;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __copy_table_start__;
extern uint32_t __copy_table_end__;
extern uint32_t __zero_table_start__;
extern uint32_t __zero_table_end__;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern uint32_t __StackTop;


/*----------------------------------------------------------------------------
  Exception / Interrupt Handler Function Prototype
 *----------------------------------------------------------------------------*/
typedef void( *pFunc )( void );


/*----------------------------------------------------------------------------
  External References
 *----------------------------------------------------------------------------*/
extern void _start     (void) __attribute__((noreturn)); /* PreeMain (C library entry point) */


/*----------------------------------------------------------------------------
  Internal References
 *----------------------------------------------------------------------------*/
void Default_Handler(void) __attribute__ ((noreturn));
void Reset_Handler  (void) __attribute__ ((noreturn));


/*----------------------------------------------------------------------------
  User Initial Stack & Heap
 *----------------------------------------------------------------------------*/
//<h> Stack Configuration
//  <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
//</h>
#define  __STACK_SIZE  0x00000400
static uint8_t stack[__STACK_SIZE] __attribute__ ((aligned(8), used, section(".stack")));

//<h> Heap Configuration
//  <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
//</h>
#define  __HEAP_SIZE   0x00000C00
#if __HEAP_SIZE > 0
static uint8_t heap[__HEAP_SIZE]   __attribute__ ((aligned(8), used, section(".heap")));
#endif


/*----------------------------------------------------------------------------
  Exception / Interrupt Handler
 *----------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void WakeUp_Int_Handler		(void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int0_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int1_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int2_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int3_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int4_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int5_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int6_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int7_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void Ext_Int8_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void WDog_Tmr_Int_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void GP_Tmr0_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void GP_Tmr1_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Flash0_Int_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void UART_Int_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI0_Int_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void SPIH_Int_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_Slave_Int_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_Master_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_Err_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPIH_TX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPIH_RX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPI0_TX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPI0_RX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPI1_TX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_SPI1_RX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_UART_TX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_UART_RX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_I2C0_STX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_I2C0_SRX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_I2C0_MX_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_AFE_TX_Int_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_AFE_RX_Int_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_CRC_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_PDI_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void DMA_I2S_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_Wakeup_Int_Handler (void) __attribute__ ((weak, alias("Default_Handler")));
void USB_Control_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void USB_DMA_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void I2S_Int_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void GP_Tmr2_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void Flash1_Int_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SPI1_Int_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void RTC_Int_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void Beep_Int_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void LCD_Int_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIO_A_Int_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIO_B_Int_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void AFE_Capture_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void AFE_Generate_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void AFE_CmdFIFO_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void AFE_DataFIFO_Int_Handler(void) __attribute__ ((weak, alias("Default_Handler")));
void CapTouch_Int_Handler   (void) __attribute__ ((weak, alias("Default_Handler")));
void GPFlash_Int_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void XTAL_Int_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PLL_Int_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void Random_Int_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void PDI_Int_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void Parity_Int_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));


/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/
extern const pFunc __Vectors[77];
       const pFunc __Vectors[77] __attribute__ ((section(".vectors"))) = {
  (pFunc)(&__StackTop),                     /*     Initial Stack Pointer */
  Reset_Handler,                            /*     Reset Handler */
  NMI_Handler,                              /* -14 NMI Handler */
  HardFault_Handler,                        /* -13 Hard Fault Handler */
  MemManage_Handler,                        /* -12 MPU Fault Handler */
  BusFault_Handler,                         /* -11 Bus Fault Handler */
  UsageFault_Handler,                       /* -10 Usage Fault Handler */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  0,                                        /*     Reserved */
  SVC_Handler,                              /*  -5 SVCall Handler */
  DebugMon_Handler,                         /*  -4 Debug Monitor Handler */
  0,                                        /*     Reserved */
  PendSV_Handler,                           /*  -2 PendSV Handler */
  SysTick_Handler,                          /*  -1 SysTick Handler */

	// programmable interrupt mappings...
    WakeUp_Int_Handler        ,  // 0
    Ext_Int0_Handler          ,  // 1
    Ext_Int1_Handler          ,  // 2
    Ext_Int2_Handler          ,  // 3
    Ext_Int3_Handler          ,  // 4
    Ext_Int4_Handler          ,  // 5
    Ext_Int5_Handler          ,  // 6
    Ext_Int6_Handler          ,  // 7
    Ext_Int7_Handler          ,  // 8
    Ext_Int8_Handler          ,  // 9
    WDog_Tmr_Int_Handler      ,  // 10
    GP_Tmr0_Int_Handler       ,  // 11
    GP_Tmr1_Int_Handler       ,  // 12
    Flash0_Int_Handler        ,  // 13
    UART_Int_Handler          ,  // 14
    SPI0_Int_Handler          ,  // 15
    SPIH_Int_Handler          ,  // 16
    I2C0_Slave_Int_Handler    ,  // 17
    I2C0_Master_Int_Handler   ,  // 18
    DMA_Err_Int_Handler       ,  // 19
    DMA_SPIH_TX_Int_Handler   ,  // 20
    DMA_SPIH_RX_Int_Handler   ,  // 21
    DMA_SPI0_TX_Int_Handler   ,  // 22
    DMA_SPI0_RX_Int_Handler   ,  // 23
    DMA_SPI1_TX_Int_Handler   ,  // 24
    DMA_SPI1_RX_Int_Handler   ,  // 25
    DMA_UART_TX_Int_Handler   ,  // 26
    DMA_UART_RX_Int_Handler   ,  // 27
    DMA_I2C0_STX_Int_Handler  ,  // 28
    DMA_I2C0_SRX_Int_Handler  ,  // 29
    DMA_I2C0_MX_Int_Handler   ,  // 30
    DMA_AFE_TX_Int_Handler    ,  // 31
    DMA_AFE_RX_Int_Handler    ,  // 32
    DMA_CRC_Int_Handler       ,  // 33
    DMA_PDI_Int_Handler       ,  // 34
    DMA_I2S_Int_Handler       ,  // 35
    USB_Wakeup_Int_Handler    ,  // 36
    USB_Control_Int_Handler   ,  // 37
    USB_DMA_Int_Handler       ,  // 38
    I2S_Int_Handler           ,  // 39
    GP_Tmr2_Int_Handler       ,  // 40
    Flash1_Int_Handler        ,  // 41
    SPI1_Int_Handler          ,  // 42
    RTC_Int_Handler           ,  // 43
    0                         ,  // 44
    Beep_Int_Handler          ,  // 45
    LCD_Int_Handler           ,  // 46
    GPIO_A_Int_Handler        ,  // 47
    GPIO_B_Int_Handler        ,  // 48
    0                         ,  // 49
    AFE_Capture_Int_Handler   ,  // 50
    AFE_Generate_Int_Handler  ,  // 51
    AFE_CmdFIFO_Int_Handler   ,  // 52
    AFE_DataFIFO_Int_Handler  ,  // 53
    CapTouch_Int_Handler      ,  // 54
    GPFlash_Int_Handler       ,  // 55
    XTAL_Int_Handler          ,  // 56
    PLL_Int_Handler           ,  // 57
    Random_Int_Handler        ,  // 58
    PDI_Int_Handler           ,  // 59
    Parity_Int_Handler        ,  // 60                                            /* Interrupts 10 .. 224 are left out */
};


/*----------------------------------------------------------------------------
  Reset Handler called on controller reset
 *----------------------------------------------------------------------------*/
void Reset_Handler(void) {
  uint32_t *pSrc, *pDest;
  uint32_t *pTable __attribute__((unused));

/* Firstly it copies data from read only memory to RAM.
 * There are two schemes to copy. One can copy more than one sections.
 * Another can copy only one section. The former scheme needs more
 * instructions and read-only data to implement than the latter.
 * Macro __STARTUP_COPY_MULTIPLE is used to choose between two schemes.
 */

#ifdef __STARTUP_COPY_MULTIPLE
/* Multiple sections scheme.
 *
 * Between symbol address __copy_table_start__ and __copy_table_end__,
 * there are array of triplets, each of which specify:
 *   offset 0: LMA of start of a section to copy from
 *   offset 4: VMA of start of a section to copy to
 *   offset 8: size of the section to copy. Must be multiply of 4
 *
 * All addresses must be aligned to 4 bytes boundary.
 */
  pTable = &__copy_table_start__;

  for (; pTable < &__copy_table_end__; pTable = pTable + 3) {
    pSrc  = (uint32_t*)*(pTable + 0);
    pDest = (uint32_t*)*(pTable + 1);
    for (; pDest < (uint32_t*)(*(pTable + 1) + *(pTable + 2)) ; ) {
      *pDest++ = *pSrc++;
    }
  }
#else
/* Single section scheme.
 *
 * The ranges of copy from/to are specified by following symbols
 *   __etext: LMA of start of the section to copy from. Usually end of text
 *   __data_start__: VMA of start of the section to copy to
 *   __data_end__: VMA of end of the section to copy to
 *
 * All addresses must be aligned to 4 bytes boundary.
 */
  pSrc  = &__etext;
  pDest = &__data_start__;

  for ( ; pDest < &__data_end__ ; ) {
    *pDest++ = *pSrc++;
  }
#endif /*__STARTUP_COPY_MULTIPLE */

/* This part of work usually is done in C library startup code.
 * Otherwise, define this macro to enable it in this startup.
 *
 * There are two schemes too.
 * One can clear multiple BSS sections. Another can only clear one section.
 * The former is more size expensive than the latter.
 *
 * Define macro __STARTUP_CLEAR_BSS_MULTIPLE to choose the former.
 * Otherwise define macro __STARTUP_CLEAR_BSS to choose the later.
 */
#ifdef __STARTUP_CLEAR_BSS_MULTIPLE
/* Multiple sections scheme.
 *
 * Between symbol address __copy_table_start__ and __copy_table_end__,
 * there are array of tuples specifying:
 *   offset 0: Start of a BSS section
 *   offset 4: Size of this BSS section. Must be multiply of 4
 */
  pTable = &__zero_table_start__;

  for (; pTable < &__zero_table_end__; pTable = pTable + 2) {
    pDest = (uint32_t*)*(pTable + 0);
    for (; pDest < (uint32_t*)(*(pTable + 0) + *(pTable + 1)) ; ) {
      *pDest++ = 0;
    }
  }
#elif defined (__STARTUP_CLEAR_BSS)
/* Single BSS section scheme.
 *
 * The BSS section is specified by following symbols
 *   __bss_start__: start of the BSS section.
 *   __bss_end__: end of the BSS section.
 *
 * Both addresses must be aligned to 4 bytes boundary.
 */
  pDest = &__bss_start__;

  for ( ; pDest < &__bss_end__ ; ) {
    *pDest++ = 0UL;
  }
#endif /* __STARTUP_CLEAR_BSS_MULTIPLE || __STARTUP_CLEAR_BSS */

  SystemInit();                             /* CMSIS System Initialization */
  _start();                                 /* Enter PreeMain (C library entry point) */
}


/*----------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *----------------------------------------------------------------------------*/
void Default_Handler(void) {

  while(1);
}
