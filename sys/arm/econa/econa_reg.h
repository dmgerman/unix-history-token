begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Yohanes Nugroho<yohanes@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_ECONA_REG_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_ECONA_REG_H
end_define

begin_define
define|#
directive|define
name|ECONA_SRAM_SIZE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ECONA_DRAM_BASE
value|0x00000000
end_define

begin_comment
comment|/* DRAM (via DDR Control Module) */
end_comment

begin_define
define|#
directive|define
name|ECONA_SDRAM_BASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ECONA_SDRAM_SIZE
value|0x1000000
end_define

begin_define
define|#
directive|define
name|ECONA_IO_BASE
value|0x70000000
end_define

begin_define
define|#
directive|define
name|ECONA_IO_SIZE
value|0x0E000000
end_define

begin_define
define|#
directive|define
name|ECONA_PIC_BASE
value|0x0D000000
end_define

begin_define
define|#
directive|define
name|ECONA_PIC_SIZE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ECONA_UART_BASE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ECONA_UART_SIZE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_UART
value|0xA
end_define

begin_define
define|#
directive|define
name|ECONA_TIMER_BASE
value|0x09000000
end_define

begin_define
define|#
directive|define
name|ECONA_TIMER_SIZE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_TIMER_1
value|0
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_TIMER_2
value|1
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_OHCI
value|23
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_EHCI
value|24
end_define

begin_define
define|#
directive|define
name|ECONA_NET_BASE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ECONA_SYSTEM_BASE
value|0x07000000
end_define

begin_define
define|#
directive|define
name|ECONA_SYSTEM_SIZE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ECONA_NET_SIZE
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ECONA_CFI_PBASE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ECONA_CFI_VBASE
value|0xD0000000
end_define

begin_define
define|#
directive|define
name|ECONA_CFI_SIZE
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_STATUS
value|18
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_TSTC
value|19
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_FSRC
value|20
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_TSQE
value|21
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_FSQF
value|22
end_define

begin_define
define|#
directive|define
name|ECONA_IRQ_SYSTEM
value|0
end_define

begin_define
define|#
directive|define
name|ECONA_EHCI_PBASE
value|0xC8000000
end_define

begin_define
define|#
directive|define
name|ECONA_EHCI_VBASE
value|0xF8000000
end_define

begin_define
define|#
directive|define
name|ECONA_EHCI_SIZE
value|0x8000000
end_define

begin_define
define|#
directive|define
name|ECONA_OHCI_PBASE
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|ECONA_OHCI_VBASE
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|ECONA_OHCI_SIZE
value|0x8000000
end_define

begin_define
define|#
directive|define
name|ECONA_USB_SIZE
value|0xf000000
end_define

begin_comment
comment|/*Interrupt controller*/
end_comment

begin_define
define|#
directive|define
name|INTC_LEVEL_TRIGGER
value|0
end_define

begin_define
define|#
directive|define
name|INTC_EDGE_TRIGGER
value|1
end_define

begin_define
define|#
directive|define
name|INTC_ACTIVE_HIGH
value|0
end_define

begin_define
define|#
directive|define
name|INTC_ACTIVE_LOW
value|1
end_define

begin_comment
comment|/*  * define rising/falling edge for edge trigger mode  */
end_comment

begin_define
define|#
directive|define
name|INTC_RISING_EDGE
value|0
end_define

begin_define
define|#
directive|define
name|INTC_FALLING_EDGE
value|1
end_define

begin_define
define|#
directive|define
name|INTC_INTERRUPT_SOURCE_REG_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|INTC_INTERRUPT_MASK_REG_OFFSET
value|0x04
end_define

begin_define
define|#
directive|define
name|INTC_INTERRUPT_CLEAR_EDGE_TRIGGER_REG_OFFSET
value|0x08
end_define

begin_define
define|#
directive|define
name|INTC_INTERRUPT_TRIGGER_MODE_REG_OFFSET
value|0x0C
end_define

begin_define
define|#
directive|define
name|INTC_INTERRUPT_TRIGGER_LEVEL_REG_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|INTC_INTERRUPT_STATUS_REG_OFFSET
value|0x14
end_define

begin_define
define|#
directive|define
name|INTC_FIQ_MODE_SELECT_REG_OFFSET
value|0x18
end_define

begin_define
define|#
directive|define
name|INTC_SOFTWARE_INTERRUPT_REG_OFFSET
value|0x1C
end_define

begin_comment
comment|/*  * define rising/falling edge for edge trigger mode  */
end_comment

begin_define
define|#
directive|define
name|INTC_RISING_EDGE
value|0
end_define

begin_define
define|#
directive|define
name|INTC_FALLING_EDGE
value|1
end_define

begin_define
define|#
directive|define
name|TIMER_TM1_COUNTER_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|TIMER_TM1_LOAD_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|TIMER_TM1_MATCH1_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|TIMER_TM1_MATCH2_REG
value|0x0C
end_define

begin_define
define|#
directive|define
name|TIMER_TM2_COUNTER_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|TIMER_TM2_LOAD_REG
value|0x14
end_define

begin_define
define|#
directive|define
name|TIMER_TM2_MATCH1_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|TIMER_TM2_MATCH2_REG
value|0x1C
end_define

begin_define
define|#
directive|define
name|TIMER_TM_CR_REG
value|0x30
end_define

begin_define
define|#
directive|define
name|TIMER_TM_INTR_STATUS_REG
value|0x34
end_define

begin_define
define|#
directive|define
name|TIMER_TM_INTR_MASK_REG
value|0x38
end_define

begin_define
define|#
directive|define
name|TIMER_TM_REVISION_REG
value|0x3C
end_define

begin_define
define|#
directive|define
name|INTC_TIMER1_BIT_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|TIMER1_UP_DOWN_COUNT
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|TIMER2_UP_DOWN_COUNT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|TIMER1_MATCH1_INTR
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TIMER1_MATCH2_INTR
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TIMER1_OVERFLOW_INTR
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TIMER2_MATCH1_INTR
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|TIMER2_MATCH2_INTR
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|TIMER2_OVERFLOW_INTR
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|TIMER_CLOCK_SOURCE_PCLK
value|0
end_define

begin_define
define|#
directive|define
name|TIMER_CLOCK_SOURCE_EXT_CLK
value|1
end_define

begin_comment
comment|/*  * define interrupt trigger mode  */
end_comment

begin_define
define|#
directive|define
name|INTC_LEVEL_TRIGGER
value|0
end_define

begin_define
define|#
directive|define
name|INTC_EDGE_TRIGGER
value|1
end_define

begin_define
define|#
directive|define
name|INTC_TRIGGER_UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|TIMER1_OVERFLOW_INTERRUPT
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TIMER2_OVERFLOW_INTERRUPT
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|TIMER_INTERRUPT_STATUS_REG
value|0x34
end_define

begin_define
define|#
directive|define
name|TIMER1_ENABLE
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|TIMER1_CLOCK_SOURCE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|TIMER1_OVERFLOW_ENABLE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|TIMER2_ENABLE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|TIMER2_CLOCK_SOURCE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|TIMER2_OVERFLOW_ENABLE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|TIMER_1
value|1
end_define

begin_define
define|#
directive|define
name|EC_UART_CLOCK
value|14769200
end_define

begin_define
define|#
directive|define
name|EC_UART_REGSHIFT
value|2
end_define

begin_define
define|#
directive|define
name|SYSTEM_CLOCK
value|0x14
end_define

begin_define
define|#
directive|define
name|RESET_CONTROL
value|0x4
end_define

begin_define
define|#
directive|define
name|GLOBAL_RESET
value|0x1
end_define

begin_define
define|#
directive|define
name|NET_INTERFACE_RESET
value|(0x1<< 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

