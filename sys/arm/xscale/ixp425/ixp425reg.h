begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ixp425reg.h,v 1.19 2005/12/11 12:16:51 christos Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2003  *	Ichiro FUKUHARA<ichiro@ichiro.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Ichiro FUKUHARA.  * 4. The name of the company nor the name of the author may be used to  *    endorse or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ICHIRO FUKUHARA ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL ICHIRO FUKUHARA OR THE VOICES IN HIS HEAD BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXP425REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXP425REG_H_
end_define

begin_comment
comment|/*  * Physical memory map for the Intel IXP425  */
end_comment

begin_comment
comment|/*  * CC00 00FF ---------------------------  *           SDRAM Configuration Registers  * CC00 0000 ---------------------------  *  * C800 BFFF ---------------------------  *           System and Peripheral Registers  * C800 0000 ---------------------------  *           Expansion Bus Configuration Registers  * C400 0000 ---------------------------  *           PCI Configuration and Status Registers  * C000 0000 ---------------------------  *  * 6400 0000 ---------------------------  *           Queue manager  * 6000 0000 ---------------------------  *           Expansion Bus Data  * 5000 0000 ---------------------------  *           PCI Data  * 4800 0000 ---------------------------  *  * 4000 0000 ---------------------------  *           SDRAM  * 1000 0000 ---------------------------  */
end_comment

begin_comment
comment|/*  * Virtual memory map for the Intel IXP425 integrated devices  */
end_comment

begin_comment
comment|/*  * FFFF FFFF ---------------------------  *  * FC00 0000 ---------------------------  *           PCI Data (memory space)  * F800 0000 ---------------------------  *  * F020 1000 ---------------------------  *           SDRAM Controller  * F020 0000 ---------------------------  *  * F001 2000 ---------------------------  *           PCI Configuration and Status Registers  * F001 1000 ---------------------------  *           Expansion bus Configuration Registers  * F001 0000 ---------------------------  *           System and Peripheral Registers  *            VA F000 0000 = PA C800 0000 (SIZE 0x10000)  * F000 0000 ---------------------------  *  * 0000 0000 ---------------------------  *  */
end_comment

begin_comment
comment|/* Physical/Virtual address for I/O space */
end_comment

begin_define
define|#
directive|define
name|IXP425_IO_VBASE
value|0xf0000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_IO_HWBASE
value|0xc8000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_IO_SIZE
value|0x00010000UL
end_define

begin_comment
comment|/* Offset */
end_comment

begin_define
define|#
directive|define
name|IXP425_UART0_OFFSET
value|0x00000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_UART1_OFFSET
value|0x00001000UL
end_define

begin_define
define|#
directive|define
name|IXP425_PMC_OFFSET
value|0x00002000UL
end_define

begin_define
define|#
directive|define
name|IXP425_INTR_OFFSET
value|0x00003000UL
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_OFFSET
value|0x00004000UL
end_define

begin_define
define|#
directive|define
name|IXP425_TIMER_OFFSET
value|0x00005000UL
end_define

begin_define
define|#
directive|define
name|IXP425_NPE_A_OFFSET
value|0x00006000UL
end_define

begin_comment
comment|/* Not User Programmable */
end_comment

begin_define
define|#
directive|define
name|IXP425_NPE_B_OFFSET
value|0x00007000UL
end_define

begin_comment
comment|/* Not User Programmable */
end_comment

begin_define
define|#
directive|define
name|IXP425_NPE_C_OFFSET
value|0x00008000UL
end_define

begin_comment
comment|/* Not User Programmable */
end_comment

begin_define
define|#
directive|define
name|IXP425_MAC_A_OFFSET
value|0x00009000UL
end_define

begin_define
define|#
directive|define
name|IXP425_MAC_B_OFFSET
value|0x0000a000UL
end_define

begin_define
define|#
directive|define
name|IXP425_USB_OFFSET
value|0x0000b000UL
end_define

begin_define
define|#
directive|define
name|IXP425_REG_SIZE
value|0x1000
end_define

begin_comment
comment|/*  * UART  * 	UART0 0xc8000000  * 	UART1 0xc8001000  *  */
end_comment

begin_comment
comment|/* I/O space */
end_comment

begin_define
define|#
directive|define
name|IXP425_UART0_HWBASE
value|(IXP425_IO_HWBASE + IXP425_UART0_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_UART1_HWBASE
value|(IXP425_IO_HWBASE + IXP425_UART1_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_UART0_VBASE
value|(IXP425_IO_VBASE + IXP425_UART0_OFFSET)
end_define

begin_comment
comment|/* 0xf0000000 */
end_comment

begin_define
define|#
directive|define
name|IXP425_UART1_VBASE
value|(IXP425_IO_VBASE + IXP425_UART1_OFFSET)
end_define

begin_comment
comment|/* 0xf0001000 */
end_comment

begin_define
define|#
directive|define
name|IXP425_UART_FREQ
value|14745600
end_define

begin_define
define|#
directive|define
name|IXP425_UART_IER
value|0x01
end_define

begin_comment
comment|/* interrupt enable register */
end_comment

begin_define
define|#
directive|define
name|IXP425_UART_IER_RTOIE
value|0x10
end_define

begin_comment
comment|/* receiver timeout interrupt enable */
end_comment

begin_define
define|#
directive|define
name|IXP425_UART_IER_UUE
value|0x40
end_define

begin_comment
comment|/* UART Unit enable */
end_comment

begin_comment
comment|/*#define	IXP4XX_COM_NPORTS	8*/
end_comment

begin_comment
comment|/*  * Timers  *  */
end_comment

begin_define
define|#
directive|define
name|IXP425_TIMER_HWBASE
value|(IXP425_IO_HWBASE + IXP425_TIMER_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_TIMER_VBASE
value|(IXP425_IO_VBASE + IXP425_TIMER_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_OST_TS
value|0x0000
end_define

begin_define
define|#
directive|define
name|IXP425_OST_TIM0
value|0x0004
end_define

begin_define
define|#
directive|define
name|IXP425_OST_TIM1
value|0x000C
end_define

begin_define
define|#
directive|define
name|IXP425_OST_TIM0_RELOAD
value|0x0008
end_define

begin_define
define|#
directive|define
name|IXP425_OST_TIM1_RELOAD
value|0x0010
end_define

begin_define
define|#
directive|define
name|TIMERRELOAD_MASK
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|OST_ONESHOT_EN
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|OST_TIMER_EN
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|IXP425_OST_STATUS
value|0x0020
end_define

begin_define
define|#
directive|define
name|OST_WARM_RESET
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|OST_WDOG_INT
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|OST_TS_INT
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|OST_TIM1_INT
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|OST_TIM0_INT
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|IXP425_OST_WDOG
value|0x0014
end_define

begin_define
define|#
directive|define
name|IXP425_OST_WDOG_ENAB
value|0x0018
end_define

begin_define
define|#
directive|define
name|IXP425_OST_WDOG_KEY
value|0x001c
end_define

begin_define
define|#
directive|define
name|OST_WDOG_KEY_MAJICK
value|0x482e
end_define

begin_define
define|#
directive|define
name|OST_WDOG_ENAB_RST_ENA
value|(1u<< 0)
end_define

begin_define
define|#
directive|define
name|OST_WDOG_ENAB_INT_ENA
value|(1u<< 1)
end_define

begin_define
define|#
directive|define
name|OST_WDOG_ENAB_CNT_ENA
value|(1u<< 2)
end_define

begin_comment
comment|/*  * Interrupt Controller Unit.  *  PA 0xc8003000  */
end_comment

begin_define
define|#
directive|define
name|IXP425_IRQ_HWBASE
value|IXP425_IO_HWBASE + IXP425_INTR_OFFSET
end_define

begin_define
define|#
directive|define
name|IXP425_IRQ_VBASE
value|IXP425_IO_VBASE  + IXP425_INTR_OFFSET
end_define

begin_comment
comment|/* 0xf0003000 */
end_comment

begin_define
define|#
directive|define
name|IXP425_IRQ_SIZE
value|0x00000020UL
end_define

begin_define
define|#
directive|define
name|IXP425_INT_STATUS
value|(IXP425_IRQ_VBASE + 0x00)
end_define

begin_define
define|#
directive|define
name|IXP425_INT_ENABLE
value|(IXP425_IRQ_VBASE + 0x04)
end_define

begin_define
define|#
directive|define
name|IXP425_INT_SELECT
value|(IXP425_IRQ_VBASE + 0x08)
end_define

begin_define
define|#
directive|define
name|IXP425_IRQ_STATUS
value|(IXP425_IRQ_VBASE + 0x0C)
end_define

begin_define
define|#
directive|define
name|IXP425_FIQ_STATUS
value|(IXP425_IRQ_VBASE + 0x10)
end_define

begin_define
define|#
directive|define
name|IXP425_INT_PRTY
value|(IXP425_IRQ_VBASE + 0x14)
end_define

begin_define
define|#
directive|define
name|IXP425_IRQ_ENC
value|(IXP425_IRQ_VBASE + 0x18)
end_define

begin_define
define|#
directive|define
name|IXP425_FIQ_ENC
value|(IXP425_IRQ_VBASE + 0x1C)
end_define

begin_define
define|#
directive|define
name|IXP425_INT_SW1
value|31
end_define

begin_comment
comment|/* SW Interrupt 1 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_SW0
value|30
end_define

begin_comment
comment|/* SW Interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_12
value|29
end_define

begin_comment
comment|/* GPIO 12 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_11
value|28
end_define

begin_comment
comment|/* GPIO 11 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_10
value|27
end_define

begin_comment
comment|/* GPIO 11 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_9
value|26
end_define

begin_comment
comment|/* GPIO 9 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_8
value|25
end_define

begin_comment
comment|/* GPIO 8 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_7
value|24
end_define

begin_comment
comment|/* GPIO 7 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_6
value|23
end_define

begin_comment
comment|/* GPIO 6 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_5
value|22
end_define

begin_comment
comment|/* GPIO 5 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_4
value|21
end_define

begin_comment
comment|/* GPIO 4 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_3
value|20
end_define

begin_comment
comment|/* GPIO 3 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_2
value|19
end_define

begin_comment
comment|/* GPIO 2 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_XSCALE_PMU
value|18
end_define

begin_comment
comment|/* XScale PMU */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_AHB_PMU
value|17
end_define

begin_comment
comment|/* AHB PMU */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_WDOG
value|16
end_define

begin_comment
comment|/* Watchdog Timer */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_UART0
value|15
end_define

begin_comment
comment|/* HighSpeed UART */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_STAMP
value|14
end_define

begin_comment
comment|/* Timestamp Timer */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_UART1
value|13
end_define

begin_comment
comment|/* Console UART */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_USB
value|12
end_define

begin_comment
comment|/* USB */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_TMR1
value|11
end_define

begin_comment
comment|/* General-Purpose Timer1 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_PCIDMA2
value|10
end_define

begin_comment
comment|/* PCI DMA Channel 2 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_PCIDMA1
value|9
end_define

begin_comment
comment|/* PCI DMA Channel 1 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_PCIINT
value|8
end_define

begin_comment
comment|/* PCI Interrupt */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_1
value|7
end_define

begin_comment
comment|/* GPIO 1 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_GPIO_0
value|6
end_define

begin_comment
comment|/* GPIO 0 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_TMR0
value|5
end_define

begin_comment
comment|/* General-Purpose Timer0 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_QUE33_64
value|4
end_define

begin_comment
comment|/* Queue Manager 33-64 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_QUE1_32
value|3
end_define

begin_comment
comment|/* Queue Manager  1-32 */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_NPE_C
value|2
end_define

begin_comment
comment|/* NPE C */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_NPE_B
value|1
end_define

begin_comment
comment|/* NPE B */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_NPE_A
value|0
end_define

begin_comment
comment|/* NPE A */
end_comment

begin_comment
comment|/*  * software interrupt  */
end_comment

begin_define
define|#
directive|define
name|IXP425_INT_bit31
value|31
end_define

begin_define
define|#
directive|define
name|IXP425_INT_bit30
value|30
end_define

begin_define
define|#
directive|define
name|IXP425_INT_bit14
value|14
end_define

begin_define
define|#
directive|define
name|IXP425_INT_bit11
value|11
end_define

begin_define
define|#
directive|define
name|IXP425_INT_HWMASK
value|(0xffffffff& \ 					~((1<< IXP425_INT_bit31) | \ 					  (1<< IXP425_INT_bit30) | \ 					  (1<< IXP425_INT_bit14) | \ 					  (1<< IXP425_INT_bit11)))
end_define

begin_define
define|#
directive|define
name|IXP425_INT_GPIOMASK
value|(0x3ff800c0u)
end_define

begin_comment
comment|/*  * GPIO  */
end_comment

begin_define
define|#
directive|define
name|IXP425_GPIO_HWBASE
value|IXP425_IO_HWBASE + IXP425_GPIO_OFFSET
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_VBASE
value|IXP425_IO_VBASE  + IXP425_GPIO_OFFSET
end_define

begin_comment
comment|/* 0xf0004000 */
end_comment

begin_define
define|#
directive|define
name|IXP425_GPIO_SIZE
value|0x00000020UL
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_GPOUTR
value|0x00
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_GPOER
value|0x04
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_GPINR
value|0x08
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_GPISR
value|0x0c
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_GPIT1R
value|0x10
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_GPIT2R
value|0x14
end_define

begin_define
define|#
directive|define
name|IXP425_GPIO_GPCLKR
value|0x18
end_define

begin_define
define|#
directive|define
name|GPCLKR_MUX14
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|GPCLKR_CLK0TC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|GPCLKR_CLK0DC_SHIFT
value|0
end_define

begin_comment
comment|/* GPIO Output */
end_comment

begin_define
define|#
directive|define
name|GPOUT_ON
value|0x1
end_define

begin_define
define|#
directive|define
name|GPOUT_OFF
value|0x0
end_define

begin_comment
comment|/* GPIO direction */
end_comment

begin_define
define|#
directive|define
name|GPOER_INPUT
value|0x1
end_define

begin_define
define|#
directive|define
name|GPOER_OUTPUT
value|0x0
end_define

begin_comment
comment|/* GPIO Type bits */
end_comment

begin_define
define|#
directive|define
name|GPIO_TYPE_ACT_HIGH
value|0x0
end_define

begin_define
define|#
directive|define
name|GPIO_TYPE_ACT_LOW
value|0x1
end_define

begin_define
define|#
directive|define
name|GPIO_TYPE_EDG_RISING
value|0x2
end_define

begin_define
define|#
directive|define
name|GPIO_TYPE_EDG_FALLING
value|0x3
end_define

begin_define
define|#
directive|define
name|GPIO_TYPE_TRANSITIONAL
value|0x4
end_define

begin_define
define|#
directive|define
name|GPIO_TYPE_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|GPIO_TYPE
parameter_list|(
name|b
parameter_list|,
name|v
parameter_list|)
value|((v)<< (((b)& 0x7) * 3))
end_define

begin_define
define|#
directive|define
name|GPIO_TYPE_REG
parameter_list|(
name|b
parameter_list|)
value|(((b)&8)?IXP425_GPIO_GPIT2R:IXP425_GPIO_GPIT1R)
end_define

begin_comment
comment|/*  * Expansion Bus Configuration Space.  */
end_comment

begin_define
define|#
directive|define
name|IXP425_EXP_HWBASE
value|0xc4000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_VBASE
value|(IXP425_IO_VBASE + IXP425_IO_SIZE)
end_define

begin_comment
comment|/* 0xf0010000 */
end_comment

begin_define
define|#
directive|define
name|IXP425_EXP_SIZE
value|IXP425_REG_SIZE
end_define

begin_comment
comment|/* 0x1000 */
end_comment

begin_comment
comment|/* offset */
end_comment

begin_define
define|#
directive|define
name|EXP_TIMING_CS0_OFFSET
value|0x0000
end_define

begin_define
define|#
directive|define
name|EXP_TIMING_CS1_OFFSET
value|0x0004
end_define

begin_define
define|#
directive|define
name|EXP_TIMING_CS2_OFFSET
value|0x0008
end_define

begin_define
define|#
directive|define
name|EXP_TIMING_CS3_OFFSET
value|0x000c
end_define

begin_define
define|#
directive|define
name|EXP_TIMING_CS4_OFFSET
value|0x0010
end_define

begin_define
define|#
directive|define
name|EXP_TIMING_CS5_OFFSET
value|0x0014
end_define

begin_define
define|#
directive|define
name|EXP_TIMING_CS6_OFFSET
value|0x0018
end_define

begin_define
define|#
directive|define
name|EXP_TIMING_CS7_OFFSET
value|0x001c
end_define

begin_define
define|#
directive|define
name|EXP_CNFG0_OFFSET
value|0x0020
end_define

begin_define
define|#
directive|define
name|EXP_CNFG1_OFFSET
value|0x0024
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_OFFSET
value|0x0028
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_RECOVERY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_HOLD_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_STROBE_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_SETUP_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_ADDR_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_CS_EN
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_RECOVERY_T
parameter_list|(
name|x
parameter_list|)
value|(((x)& 15)<< IXP425_EXP_RECOVERY_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_HOLD_T
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< IXP425_EXP_HOLD_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_STROBE_T
parameter_list|(
name|x
parameter_list|)
value|(((x)& 15)<< IXP425_EXP_STROBE_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_SETUP_T
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< IXP425_EXP_SETUP_SHIFT)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_ADDR_T
parameter_list|(
name|x
parameter_list|)
value|(((x)& 3)<< IXP425_EXP_ADDR_SHIFT)
end_define

begin_comment
comment|/* EXP_CSn bits */
end_comment

begin_define
define|#
directive|define
name|EXP_BYTE_EN
value|0x00000001
end_define

begin_comment
comment|/* bus uses only 8-bit data */
end_comment

begin_define
define|#
directive|define
name|EXP_WR_EN
value|0x00000002
end_define

begin_comment
comment|/* ena writes to CS region */
end_comment

begin_comment
comment|/* bit 2 is reserved */
end_comment

begin_define
define|#
directive|define
name|EXP_SPLT_EN
value|0x00000008
end_define

begin_comment
comment|/* ena AHB split transfers */
end_comment

begin_define
define|#
directive|define
name|EXP_MUX_EN
value|0x00000010
end_define

begin_comment
comment|/* multiplexed address/data */
end_comment

begin_define
define|#
directive|define
name|EXP_HRDY_POL
value|0x00000020
end_define

begin_comment
comment|/* HPI|HRDY polarity */
end_comment

begin_define
define|#
directive|define
name|EXP_BYTE_RD16
value|0x00000040
end_define

begin_comment
comment|/* byte rd access to word dev */
end_comment

begin_define
define|#
directive|define
name|EXP_CNFG
value|0x00003c00
end_define

begin_comment
comment|/* device config size */
end_comment

begin_define
define|#
directive|define
name|EXP_SZ_512
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_1K
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_2K
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_4K
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_8K
value|(4<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_16K
value|(5<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_32K
value|(6<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_64K
value|(7<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_128K
value|(8<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_256K
value|(9<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_512K
value|(10<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_1M
value|(11<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_2M
value|(12<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_4M
value|(13<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_8M
value|(14<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_SZ_16M
value|(15<< 10)
end_define

begin_define
define|#
directive|define
name|EXP_CYC_TYPE
value|0x0000c000
end_define

begin_comment
comment|/* bus cycle "type" */
end_comment

begin_define
define|#
directive|define
name|EXP_CYC_INTEL
value|(0<< 14)
end_define

begin_define
define|#
directive|define
name|EXP_CYC_MOTO
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|EXP_CYC_HPI
value|(2<< 14)
end_define

begin_define
define|#
directive|define
name|EXP_T5
value|0x000f0000
end_define

begin_comment
comment|/* recovery timing */
end_comment

begin_define
define|#
directive|define
name|EXP_T4
value|0x00300000
end_define

begin_comment
comment|/* hold timing */
end_comment

begin_define
define|#
directive|define
name|EXP_T3
value|0x03c00000
end_define

begin_comment
comment|/* strobe timing */
end_comment

begin_define
define|#
directive|define
name|EXP_T2
value|0x0c000000
end_define

begin_comment
comment|/* setup/chip select timing */
end_comment

begin_define
define|#
directive|define
name|EXP_T1
value|0x30000000
end_define

begin_comment
comment|/* address timing */
end_comment

begin_comment
comment|/* bit 30 is reserved */
end_comment

begin_define
define|#
directive|define
name|EXP_CS_EN
value|0x80000000
end_define

begin_comment
comment|/* chip select enabled */
end_comment

begin_comment
comment|/* EXP_CNFG0 bits */
end_comment

begin_define
define|#
directive|define
name|EXP_CNFG0_8BIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EXP_CNFG0_PCI_HOST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EXP_CNFG0_PCI_ARB
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|EXP_CNFG0_PCI_66MHZ
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|EXP_CNFG0_MEM_MAP
value|(1<< 31)
end_define

begin_comment
comment|/* EXP_CNFG1 bits */
end_comment

begin_define
define|#
directive|define
name|EXP_CNFG1_SW_INT0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|EXP_CNFG1_SW_INT1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_RCOMP
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_USB
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_HASH
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_AES
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_DES
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_HDLC
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_AAL
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_HSS
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_UTOPIA
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_ETH0
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_ETH1
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_NPEA
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_NPEB
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_NPEC
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|EXP_FCTRL_PCI
value|(1<<14)
end_define

begin_comment
comment|/* XXX more stuff we don't care about */
end_comment

begin_comment
comment|/*  * PCI  */
end_comment

begin_define
define|#
directive|define
name|IXP425_PCI_HWBASE
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|IXP425_PCI_VBASE
value|(IXP425_EXP_VBASE + IXP425_EXP_SIZE)
end_define

begin_comment
comment|/* 0xf0011000 */
end_comment

begin_define
define|#
directive|define
name|IXP425_PCI_SIZE
value|IXP425_REG_SIZE
end_define

begin_comment
comment|/* 0x1000 */
end_comment

begin_comment
comment|/*  * Mapping registers of IXP425 PCI Configuration  */
end_comment

begin_comment
comment|/* PCI_ID_REG			0x00 */
end_comment

begin_comment
comment|/* PCI_COMMAND_STATUS_REG	0x04 */
end_comment

begin_comment
comment|/* PCI_CLASS_REG		0x08 */
end_comment

begin_comment
comment|/* PCI_BHLC_REG			0x0c */
end_comment

begin_define
define|#
directive|define
name|PCI_MAPREG_BAR0
value|0x10
end_define

begin_comment
comment|/* Base Address 0 */
end_comment

begin_define
define|#
directive|define
name|PCI_MAPREG_BAR1
value|0x14
end_define

begin_comment
comment|/* Base Address 1 */
end_comment

begin_define
define|#
directive|define
name|PCI_MAPREG_BAR2
value|0x18
end_define

begin_comment
comment|/* Base Address 2 */
end_comment

begin_define
define|#
directive|define
name|PCI_MAPREG_BAR3
value|0x1c
end_define

begin_comment
comment|/* Base Address 3 */
end_comment

begin_define
define|#
directive|define
name|PCI_MAPREG_BAR4
value|0x20
end_define

begin_comment
comment|/* Base Address 4 */
end_comment

begin_define
define|#
directive|define
name|PCI_MAPREG_BAR5
value|0x24
end_define

begin_comment
comment|/* Base Address 5 */
end_comment

begin_comment
comment|/* PCI_SUBSYS_ID_REG		0x2c */
end_comment

begin_comment
comment|/* PCI_INTERRUPT_REG		0x3c */
end_comment

begin_define
define|#
directive|define
name|PCI_RTOTTO
value|0x40
end_define

begin_comment
comment|/* PCI Controller CSR Base Address */
end_comment

begin_define
define|#
directive|define
name|IXP425_PCI_CSR_BASE
value|IXP425_PCI_VBASE
end_define

begin_comment
comment|/* PCI Memory Space */
end_comment

begin_define
define|#
directive|define
name|IXP425_PCI_MEM_HWBASE
value|0x48000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_PCI_MEM_VBASE
value|0xf8000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_PCI_MEM_SIZE
value|0x04000000UL
end_define

begin_comment
comment|/* 64MB */
end_comment

begin_comment
comment|/* PCI I/O Space */
end_comment

begin_define
define|#
directive|define
name|IXP425_PCI_IO_HWBASE
value|0x00000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_PCI_IO_SIZE
value|0x00100000UL
end_define

begin_comment
comment|/* 1Mbyte */
end_comment

begin_comment
comment|/* PCI Controller Configuration Offset */
end_comment

begin_define
define|#
directive|define
name|PCI_NP_AD
value|0x00
end_define

begin_define
define|#
directive|define
name|PCI_NP_CBE
value|0x04
end_define

begin_define
define|#
directive|define
name|NP_CBE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PCI_NP_WDATA
value|0x08
end_define

begin_define
define|#
directive|define
name|PCI_NP_RDATA
value|0x0c
end_define

begin_define
define|#
directive|define
name|PCI_CRP_AD_CBE
value|0x10
end_define

begin_define
define|#
directive|define
name|PCI_CRP_AD_WDATA
value|0x14
end_define

begin_define
define|#
directive|define
name|PCI_CRP_AD_RDATA
value|0x18
end_define

begin_define
define|#
directive|define
name|PCI_CSR
value|0x1c
end_define

begin_define
define|#
directive|define
name|CSR_PRST
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|CSR_IC
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|CSR_ABE
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|CSR_PDS
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|CSR_ADS
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|CSR_HOST
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|PCI_ISR
value|0x20
end_define

begin_define
define|#
directive|define
name|ISR_AHBE
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|ISR_PPE
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|ISR_PFE
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|ISR_PSE
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|PCI_INTEN
value|0x24
end_define

begin_define
define|#
directive|define
name|PCI_DMACTRL
value|0x28
end_define

begin_define
define|#
directive|define
name|PCI_AHBMEMBASE
value|0x2c
end_define

begin_define
define|#
directive|define
name|PCI_AHBIOBASE
value|0x30
end_define

begin_define
define|#
directive|define
name|PCI_PCIMEMBASE
value|0x34
end_define

begin_define
define|#
directive|define
name|PCI_AHBDOORBELL
value|0x38
end_define

begin_define
define|#
directive|define
name|PCI_PCIDOORBELL
value|0x3c
end_define

begin_define
define|#
directive|define
name|PCI_ATPDMA0_AHBADDR
value|0x40
end_define

begin_define
define|#
directive|define
name|PCI_ATPDMA0_PCIADDR
value|0x44
end_define

begin_define
define|#
directive|define
name|PCI_ATPDMA0_LENGTH
value|0x48
end_define

begin_define
define|#
directive|define
name|PCI_ATPDMA1_AHBADDR
value|0x4c
end_define

begin_define
define|#
directive|define
name|PCI_ATPDMA1_PCIADDR
value|0x50
end_define

begin_define
define|#
directive|define
name|PCI_ATPDMA1_LENGTH
value|0x54
end_define

begin_define
define|#
directive|define
name|PCI_PTADMA0_AHBADDR
value|0x58
end_define

begin_define
define|#
directive|define
name|PCI_PTADMA0_PCIADDR
value|0x5c
end_define

begin_define
define|#
directive|define
name|PCI_PTADMA0_LENGTH
value|0x60
end_define

begin_define
define|#
directive|define
name|PCI_PTADMA1_AHBADDR
value|0x64
end_define

begin_define
define|#
directive|define
name|PCI_PTADMA1_PCIADDR
value|0x68
end_define

begin_define
define|#
directive|define
name|PCI_PTADMA1_LENGTH
value|0x6c
end_define

begin_comment
comment|/* PCI target(T)/initiator(I) Interface Commands for PCI_NP_CBE register */
end_comment

begin_define
define|#
directive|define
name|COMMAND_NP_IA
value|0x0
end_define

begin_comment
comment|/* Interrupt Acknowledge   (I)*/
end_comment

begin_define
define|#
directive|define
name|COMMAND_NP_SC
value|0x1
end_define

begin_comment
comment|/* Special Cycle	   (I)*/
end_comment

begin_define
define|#
directive|define
name|COMMAND_NP_IO_READ
value|0x2
end_define

begin_comment
comment|/* I/O Read		(T)(I) */
end_comment

begin_define
define|#
directive|define
name|COMMAND_NP_IO_WRITE
value|0x3
end_define

begin_comment
comment|/* I/O Write		(T)(I) */
end_comment

begin_define
define|#
directive|define
name|COMMAND_NP_MEM_READ
value|0x6
end_define

begin_comment
comment|/* Memory Read		(T)(I) */
end_comment

begin_define
define|#
directive|define
name|COMMAND_NP_MEM_WRITE
value|0x7
end_define

begin_comment
comment|/* Memory Write		(T)(I) */
end_comment

begin_define
define|#
directive|define
name|COMMAND_NP_CONF_READ
value|0xa
end_define

begin_comment
comment|/* Configuration Read	(T)(I) */
end_comment

begin_define
define|#
directive|define
name|COMMAND_NP_CONF_WRITE
value|0xb
end_define

begin_comment
comment|/* Configuration Write	(T)(I) */
end_comment

begin_comment
comment|/* PCI byte enables */
end_comment

begin_define
define|#
directive|define
name|BE_8BIT
parameter_list|(
name|a
parameter_list|)
value|((0x10u<< ((a)& 0x03)) ^ 0xf0)
end_define

begin_define
define|#
directive|define
name|BE_16BIT
parameter_list|(
name|a
parameter_list|)
value|((0x30u<< ((a)& 0x02)) ^ 0xf0)
end_define

begin_define
define|#
directive|define
name|BE_32BIT
parameter_list|(
name|a
parameter_list|)
value|0x00
end_define

begin_comment
comment|/* PCI byte selects */
end_comment

begin_define
define|#
directive|define
name|READ_8BIT
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|)
value|((u_int8_t)((v)>> (((a)& 3) * 8)))
end_define

begin_define
define|#
directive|define
name|READ_16BIT
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|)
value|((u_int16_t)((v)>> (((a)& 2) * 8)))
end_define

begin_define
define|#
directive|define
name|WRITE_8BIT
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|)
value|(((u_int32_t)(v))<< (((a)& 3) * 8))
end_define

begin_define
define|#
directive|define
name|WRITE_16BIT
parameter_list|(
name|v
parameter_list|,
name|a
parameter_list|)
value|(((u_int32_t)(v))<< (((a)& 2) * 8))
end_define

begin_comment
comment|/* PCI Controller Configuration Commands for PCI_CRP_AD_CBE */
end_comment

begin_define
define|#
directive|define
name|COMMAND_CRP_READ
value|0x00
end_define

begin_define
define|#
directive|define
name|COMMAND_CRP_WRITE
value|(1U<< 16)
end_define

begin_comment
comment|/*  * SDRAM Configuration Register  */
end_comment

begin_define
define|#
directive|define
name|IXP425_MCU_HWBASE
value|0xcc000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_MCU_VBASE
value|0xf0200000UL
end_define

begin_define
define|#
directive|define
name|IXP425_MCU_SIZE
value|0x1000
end_define

begin_comment
comment|/* Actually only 256 bytes */
end_comment

begin_define
define|#
directive|define
name|MCU_SDR_CONFIG
value|0x00
end_define

begin_define
define|#
directive|define
name|MCU_SDR_CONFIG_MCONF
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_define
define|#
directive|define
name|MCU_SDR_CONFIG_64MBIT
value|(1u<< 5)
end_define

begin_define
define|#
directive|define
name|MCU_SDR_REFRESH
value|0x04
end_define

begin_define
define|#
directive|define
name|MCU_SDR_IR
value|0x08
end_define

begin_comment
comment|/*  * Performance Monitoring Unit          (CP14)  *  *      CP14.0.1	Performance Monitor Control Register(PMNC)  *      CP14.1.1	Clock Counter(CCNT)  *      CP14.4.1	Interrupt Enable Register(INTEN)  *      CP14.5.1	Overflow Flag Register(FLAG)  *      CP14.8.1	Event Selection Register(EVTSEL)  *      CP14.0.2	Performance Counter Register 0(PMN0)  *      CP14.1.2	Performance Counter Register 0(PMN1)  *      CP14.2.2	Performance Counter Register 0(PMN2)  *      CP14.3.2	Performance Counter Register 0(PMN3)  */
end_comment

begin_define
define|#
directive|define
name|PMNC_E
value|0x00000001
end_define

begin_comment
comment|/* enable all counters */
end_comment

begin_define
define|#
directive|define
name|PMNC_P
value|0x00000002
end_define

begin_comment
comment|/* reset all PMNs to 0 */
end_comment

begin_define
define|#
directive|define
name|PMNC_C
value|0x00000004
end_define

begin_comment
comment|/* clock counter reset */
end_comment

begin_define
define|#
directive|define
name|PMNC_D
value|0x00000008
end_define

begin_comment
comment|/* clock counter / 64 */
end_comment

begin_define
define|#
directive|define
name|INTEN_CC_IE
value|0x00000001
end_define

begin_comment
comment|/* enable clock counter interrupt */
end_comment

begin_define
define|#
directive|define
name|INTEN_PMN0_IE
value|0x00000002
end_define

begin_comment
comment|/* enable PMN0 interrupt */
end_comment

begin_define
define|#
directive|define
name|INTEN_PMN1_IE
value|0x00000004
end_define

begin_comment
comment|/* enable PMN1 interrupt */
end_comment

begin_define
define|#
directive|define
name|INTEN_PMN2_IE
value|0x00000008
end_define

begin_comment
comment|/* enable PMN2 interrupt */
end_comment

begin_define
define|#
directive|define
name|INTEN_PMN3_IE
value|0x00000010
end_define

begin_comment
comment|/* enable PMN3 interrupt */
end_comment

begin_define
define|#
directive|define
name|FLAG_CC_IF
value|0x00000001
end_define

begin_comment
comment|/* clock counter overflow */
end_comment

begin_define
define|#
directive|define
name|FLAG_PMN0_IF
value|0x00000002
end_define

begin_comment
comment|/* PMN0 overflow */
end_comment

begin_define
define|#
directive|define
name|FLAG_PMN1_IF
value|0x00000004
end_define

begin_comment
comment|/* PMN1 overflow */
end_comment

begin_define
define|#
directive|define
name|FLAG_PMN2_IF
value|0x00000008
end_define

begin_comment
comment|/* PMN2 overflow */
end_comment

begin_define
define|#
directive|define
name|FLAG_PMN3_IF
value|0x00000010
end_define

begin_comment
comment|/* PMN3 overflow */
end_comment

begin_define
define|#
directive|define
name|EVTSEL_EVCNT_MASK
value|0x0000000ff
end_define

begin_comment
comment|/* event to count for PMNs */
end_comment

begin_define
define|#
directive|define
name|PMNC_EVCNT0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PMNC_EVCNT1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PMNC_EVCNT2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PMNC_EVCNT3_SHIFT
value|24
end_define

begin_comment
comment|/*   * Queue Manager  */
end_comment

begin_define
define|#
directive|define
name|IXP425_QMGR_HWBASE
value|0x60000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_QMGR_VBASE
value|(IXP425_PCI_VBASE + IXP425_PCI_SIZE)
end_define

begin_define
define|#
directive|define
name|IXP425_QMGR_SIZE
value|0x4000
end_define

begin_comment
comment|/*  * Network Processing Engines (NPE's) and associated Ethernet MAC's.  */
end_comment

begin_define
define|#
directive|define
name|IXP425_NPE_A_HWBASE
value|(IXP425_IO_HWBASE + IXP425_NPE_A_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_NPE_A_VBASE
value|(IXP425_IO_VBASE + IXP425_NPE_A_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_NPE_A_SIZE
value|0x1000
end_define

begin_comment
comment|/* Actually only 256 bytes */
end_comment

begin_define
define|#
directive|define
name|IXP425_NPE_B_HWBASE
value|(IXP425_IO_HWBASE + IXP425_NPE_B_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_NPE_B_VBASE
value|(IXP425_IO_VBASE + IXP425_NPE_B_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_NPE_B_SIZE
value|0x1000
end_define

begin_comment
comment|/* Actually only 256 bytes */
end_comment

begin_define
define|#
directive|define
name|IXP425_NPE_C_HWBASE
value|(IXP425_IO_HWBASE + IXP425_NPE_C_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_NPE_C_VBASE
value|(IXP425_IO_VBASE + IXP425_NPE_C_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_NPE_C_SIZE
value|0x1000
end_define

begin_comment
comment|/* Actually only 256 bytes */
end_comment

begin_define
define|#
directive|define
name|IXP425_MAC_A_HWBASE
value|(IXP425_IO_HWBASE + IXP425_MAC_A_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_MAC_A_VBASE
value|(IXP425_IO_VBASE + IXP425_MAC_A_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_MAC_A_SIZE
value|0x1000
end_define

begin_comment
comment|/* Actually only 256 bytes */
end_comment

begin_define
define|#
directive|define
name|IXP425_MAC_B_HWBASE
value|(IXP425_IO_HWBASE + IXP425_MAC_B_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_MAC_B_VBASE
value|(IXP425_IO_VBASE + IXP425_MAC_B_OFFSET)
end_define

begin_define
define|#
directive|define
name|IXP425_MAC_B_SIZE
value|0x1000
end_define

begin_comment
comment|/* Actually only 256 bytes */
end_comment

begin_comment
comment|/*  * Expansion Bus Data Space.  */
end_comment

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_HWBASE
value|0x50000000UL
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_SIZE
value|0x01000000
end_define

begin_comment
comment|/* max, typically smaller */
end_comment

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CSx_HWBASE
parameter_list|(
name|i
parameter_list|)
define|\
value|(IXP425_EXP_BUS_HWBASE + (i)*IXP425_EXP_BUS_SIZE)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CSx_VBASE
parameter_list|(
name|i
parameter_list|)
define|\
value|(IXP425_MAC_B_VBASE + (i)*IXP425_MAC_B_SIZE)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS1_HWBASE
value|IXP425_EXP_BUS_CSx_HWBASE(1)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS1_VBASE
value|IXP425_EXP_BUS_CSx_VBASE(1)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS1_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS2_HWBASE
value|IXP425_EXP_BUS_CSx_HWBASE(2)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS2_VBASE
value|IXP425_EXP_BUS_CSx_VBASE(2)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS2_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS3_HWBASE
value|IXP425_EXP_BUS_CSx_HWBASE(3)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS3_VBASE
value|IXP425_EXP_BUS_CSx_VBASE(3)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS3_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS4_HWBASE
value|IXP425_EXP_BUS_CSx_HWBASE(4)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS4_VBASE
value|IXP425_EXP_BUS_CSx_VBASE(4)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS4_SIZE
value|0x1000
end_define

begin_comment
comment|/* NB: not mapped (yet) */
end_comment

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS0_HWBASE
value|IXP425_EXP_BUS_CSx_HWBASE(0)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS5_HWBASE
value|IXP425_EXP_BUS_CSx_HWBASE(5)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS6_HWBASE
value|IXP425_EXP_BUS_CSx_HWBASE(6)
end_define

begin_define
define|#
directive|define
name|IXP425_EXP_BUS_CS7_HWBASE
value|IXP425_EXP_BUS_CSx_HWBASE(7)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXP425REG_H_ */
end_comment

end_unit

