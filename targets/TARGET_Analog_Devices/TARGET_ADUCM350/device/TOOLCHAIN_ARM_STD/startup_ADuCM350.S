;/**************************************************************************//**
; * @file     startup_ADuCM350.s
; * @brief    CMSIS Cortex-M ARMv7-M based Core Device Startup File for
; *           Device ADuCM350
; * @version  V5.3.1
; * @date     09. July 2018
; ******************************************************************************/
;/*
; * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
; *
; * SPDX-License-Identifier: Apache-2.0
; *
; * Licensed under the Apache License, Version 2.0 (the License); you may
; * not use this file except in compliance with the License.
; * You may obtain a copy of the License at
; *
; * www.apache.org/licenses/LICENSE-2.0
; *
; * Unless required by applicable law or agreed to in writing, software
; * distributed under the License is distributed on an AS IS BASIS, WITHOUT
; * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
; * See the License for the specific language governing permissions and
; * limitations under the License.
; */

;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------


;<h> Stack Configuration
;  <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;</h>

Stack_Size      EQU      0x00000400

                AREA     STACK, NOINIT, READWRITE, ALIGN=3
__stack_limit
Stack_Mem       SPACE    Stack_Size
__initial_sp


;<h> Heap Configuration
;  <o> Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
;</h>

Heap_Size       EQU      0x00000C00

                IF       Heap_Size != 0                      ; Heap is provided
                AREA     HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE    Heap_Size
__heap_limit
                ENDIF


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA     RESET, DATA, READONLY
                EXPORT   __Vectors
                EXPORT   __Vectors_End
                EXPORT   __Vectors_Size

__Vectors       DCD      __initial_sp                        ;     Top of Stack
                DCD      Reset_Handler                       ;     Reset Handler
                DCD      NMI_Handler                         ; -14 NMI Handler
                DCD      HardFault_Handler                   ; -13 Hard Fault Handler
                DCD      MemManage_Handler                   ; -12 MPU Fault Handler
                DCD      BusFault_Handler                    ; -11 Bus Fault Handler
                DCD      UsageFault_Handler                  ; -10 Usage Fault Handler
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      SVC_Handler                         ;  -5 SVCall Handler
                DCD      DebugMon_Handler                    ;  -4 Debug Monitor Handler
                DCD      0                                   ;     Reserved
                DCD      PendSV_Handler                      ;  -2 PendSV Handler
                DCD      SysTick_Handler                     ;  -1 SysTick Handler

                ; External Interrupts
; ToDo:  Add here the vectors for the device specific external interrupts handler
                DCD      WUT_Handler                         ;   0  Wake Up Timer interrupt
                DCD      EINT0_Handler                       ;   1  External Interrupt 0
                DCD      EINT1_Handler                       ;   2  External Interrupt 1
                DCD      EINT2_Handler                       ;   3  External Interrupt 2
                DCD      EINT3_Handler                       ;   4  External Interrupt 3
                DCD      EINT4_Handler                       ;   5  External Interrupt 4
                DCD      EINT5_Handler                       ;   6  External Interrupt 5
                DCD      EINT6_Handler                       ;   7  External Interrupt 6
                DCD      EINT7_Handler                       ;   8  External Interrupt 7
                DCD      EINT8_Handler                       ;   9  External Interrupt 8
                DCD      WDT_Handler                         ;   10 WDT Interrupt
                DCD      TIMER0_Handler                      ;   11 Timer interrupt
                DCD      TIMER1_Handler                      ;   12 Timer 1 Interrupt
                DCD      FLASH0_Handler                      ;   13 Flash Controller Interrupt
                DCD      UART_Handler                        ;   14 interrupt
                DCD      SPI0_Handler                        ;   15 SPI 0 interrupt
                DCD      SPIH_Handler                        ;   16 interrupt
                DCD      I2CS_Handler                        ;   17 I2C 0 slave interrupt
                DCD      I2CM_Handler                        ;   18 I2C 0 master interrupt
                DCD      DMA_ERR_Handler                     ;   19 DMA interrupt
                DCD      DMA_SPIH_TX_Handler                 ;   20 DMA Ch 0 interrupt
                DCD      DMA_SPIH_RX_Handler                 ;   21 DMA Ch 1 interrupt
                DCD      DMA_SPI0_TX_Handler                 ;   22 DMA Ch 2 interrupt
                DCD      DMA_SPI0_RX_Handler                 ;   23 DMA Ch 3 interrupt
                DCD      DMA_SPI1_TX_Handler                 ;   24 DMA Ch 4 interrupt
                DCD      DMA_SPI1_RX_Handler                 ;   25 DMA Ch 5 interrupt
                DCD      DMA_UART_TX_Handler                 ;   26 DMA Ch 6 interrupt
                DCD      DMA_UART_RX_Handler                 ;   27 DMA Ch 7 interrupt
                DCD      DMA_I2CS_TX_Handler                 ;   28 DMA Ch 8 interrupt
                DCD      DMA_I2CS_RX_Handler                 ;   29 DMA Ch 9 interrupt
                DCD      DMA_I2CM_Handler                    ;   30 DMA Ch 10 interrupt
                DCD      DMA_AFE_TX_Handler                  ;   31 DMA Ch 11 interrupt
                DCD      DMA_AFE_RX_Handler                  ;   32 DMA Ch 12 interrupt
                DCD      DMA_CRC_Handler                     ;   33 DMA Ch 13 interrupt
                DCD      DMA_PDI_Handler                     ;   34 DMA Ch 14 interrupt
                DCD      DMA_I2S_Handler                     ;   35 DMA Ch 15 interrupt
                DCD      USB_WAKEUP_Handler                  ;   36 USB Wakeup interrupt
                DCD      USB_CNTL_Handler                    ;   37 USB Controller interrupt
                DCD      USB_DMA_Handler                     ;   38 USB DMA interrupt
                DCD      I2S_Handler                         ;   39 I2S interrupt
                DCD      TIMER2_Handler                      ;   40 TIMER 2 interrupt
                DCD      SPI1_Handler                        ;   42 interrupt
                DCD      RTC_Handler                         ;   43 Real Time Clock interrupt
                DCD      BEEP_Handler                        ;   45 Beep interrupt
                DCD      LCD_Handler                         ;   46 LCD Controller interrupt
                DCD      GPIOA_Handler                       ;   47 interrupt
                DCD      GPIOB_Handler                       ;   48 interrupt
                DCD      AFE_CAPTURE_Handler                 ;   50 Analog Front End Capture interrupt
                DCD      AFE_GENERATE_Handler                ;   51 Analog Front End Generation interrupt
                DCD      AFE_CMD_FIFO_Handler                ;   52 Analog Front End FIFO CMD interrupt
                DCD      AFE_DATA_FIFO_Handler               ;   53 Analog Front End FIFO DATA interrupt
                DCD      GP_FLASH_Handler                    ;   55 Flash EEPROM interrupt
                DCD      RAND_Handler                        ;   58 Random Bit Generator interrupt
                DCD      PDI_Handler                         ;   59 Paraller Display Interface interrupt

                SPACE    (163 * 4)                           ; Interrupts 60 .. 224 are left out
__Vectors_End
__Vectors_Size  EQU      __Vectors_End - __Vectors


                AREA     |.text|, CODE, READONLY

; Reset Handler

Reset_Handler   PROC
                EXPORT   Reset_Handler             [WEAK]
                IMPORT   SystemInit
                IMPORT   __main

                LDR      R0, =SystemInit
                BLX      R0
                LDR      R0, =__main
                BX       R0
                ENDP


; Macro to define default exception/interrupt handlers.
; Default handler are weak symbols with an endless loop.
; They can be overwritten by real handlers.
                MACRO
                Set_Default_Handler  $Handler_Name
$Handler_Name   PROC
                EXPORT   $Handler_Name             [WEAK]
                B        .
                ENDP
                MEND


; Default exception/interrupt handler

                Set_Default_Handler  NMI_Handler
                Set_Default_Handler  HardFault_Handler
                Set_Default_Handler  MemManage_Handler
                Set_Default_Handler  BusFault_Handler
                Set_Default_Handler  UsageFault_Handler
                Set_Default_Handler  SVC_Handler
                Set_Default_Handler  DebugMon_Handler
                Set_Default_Handler  PendSV_Handler
                Set_Default_Handler  SysTick_Handler

                Set_Default_Handler  WUT_Handler
                Set_Default_Handler  EINT0_Handler
                Set_Default_Handler  EINT1_Handler
                Set_Default_Handler  EINT2_Handler
                Set_Default_Handler  EINT3_Handler
                Set_Default_Handler  EINT4_Handler
                Set_Default_Handler  EINT5_Handler
                Set_Default_Handler  EINT6_Handler
                Set_Default_Handler  EINT7_Handler
                Set_Default_Handler  EINT8_Handler
                Set_Default_Handler  WDT_Handler
                Set_Default_Handler  TIMER0_Handler
                Set_Default_Handler  TIMER1_Handler
                Set_Default_Handler  FLASH0_Handler
                Set_Default_Handler  UART_Handler
                Set_Default_Handler  SPI0_Handler
                Set_Default_Handler  SPIH_Handler
                Set_Default_Handler  I2CS_Handler
                Set_Default_Handler  I2CM_Handler
                Set_Default_Handler  DMA_ERR_Handler
                Set_Default_Handler  DMA_SPIH_TX_Handler
                Set_Default_Handler  DMA_SPIH_RX_Handler
                Set_Default_Handler  DMA_SPI0_TX_Handler
                Set_Default_Handler  DMA_SPI0_RX_Handler
                Set_Default_Handler  DMA_SPI1_TX_Handler
                Set_Default_Handler  DMA_SPI1_RX_Handler
                Set_Default_Handler  DMA_UART_TX_Handler
                Set_Default_Handler  DMA_UART_RX_Handler
                Set_Default_Handler  DMA_I2CS_TX_Handler
                Set_Default_Handler  DMA_I2CS_RX_Handler
                Set_Default_Handler  DMA_I2CM_Handler
                Set_Default_Handler  DMA_AFE_TX_Handler
                Set_Default_Handler  DMA_AFE_RX_Handler
                Set_Default_Handler  DMA_CRC_Handler
                Set_Default_Handler  DMA_PDI_Handler
                Set_Default_Handler  DMA_I2S_Handler
                Set_Default_Handler  USB_WAKEUP_Handler
                Set_Default_Handler  USB_CNTL_Handler
                Set_Default_Handler  USB_DMA_Handler
                Set_Default_Handler  I2S_Handler
                Set_Default_Handler  TIMER2_Handler
                Set_Default_Handler  SPI1_Handler
                Set_Default_Handler  RTC_Handler
                Set_Default_Handler  BEEP_Handler
                Set_Default_Handler  LCD_Handler
                Set_Default_Handler  GPIOA_Handler
                Set_Default_Handler  GPIOB_Handler
                Set_Default_Handler  AFE_CAPTURE_Handler
                Set_Default_Handler  AFE_GENERATE_Handler
                Set_Default_Handler  AFE_CMD_FIFO_Handler
                Set_Default_Handler  AFE_DATA_FIFO_Handler
                Set_Default_Handler  GP_FLASH_Handler
                Set_Default_Handler  RAND_Handler
                Set_Default_Handler  PDI_Handler
				
                ALIGN


; User setup Stack & Heap

                EXPORT   __stack_limit
                EXPORT   __initial_sp
                IF       Heap_Size != 0                      ; Heap is provided
                EXPORT   __heap_base
                EXPORT   __heap_limit
                ENDIF

                END
