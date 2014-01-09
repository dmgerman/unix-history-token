begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Jakub Wojciech Klama<jceel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_LPC_LPCREG_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_LPC_LPCREG_H
end_define

begin_define
define|#
directive|define
name|LPC_DEV_PHYS_BASE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|LPC_DEV_P5_PHYS_BASE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|LPC_DEV_P6_PHYS_BASE
value|0x30000000
end_define

begin_define
define|#
directive|define
name|LPC_DEV_SIZE
value|0x10000000
end_define

begin_comment
comment|/*  * Interrupt controller (from UM10326: LPC32x0 User manual, page 87)   */
end_comment

begin_define
define|#
directive|define
name|LPC_INTC_MIC_ER
value|0x0000
end_define

begin_define
define|#
directive|define
name|LPC_INTC_MIC_RSR
value|0x0004
end_define

begin_define
define|#
directive|define
name|LPC_INTC_MIC_SR
value|0x0008
end_define

begin_define
define|#
directive|define
name|LPC_INTC_MIC_APR
value|0x000c
end_define

begin_define
define|#
directive|define
name|LPC_INTC_MIC_ATR
value|0x0010
end_define

begin_define
define|#
directive|define
name|LPC_INTC_MIC_ITR
value|0x0014
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC1_ER
value|0x4000
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC1_RSR
value|0x4004
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC1_SR
value|0x4008
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC1_APR
value|0x400c
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC1_ATR
value|0x4010
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC1_ITR
value|0x4014
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC2_ER
value|0x8000
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC2_RSR
value|0x8004
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC2_SR
value|0x8008
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC2_APR
value|0x800c
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC2_ATR
value|0x8010
end_define

begin_define
define|#
directive|define
name|LPC_INTC_SIC2_ITR
value|0x8014
end_define

begin_comment
comment|/*  * Timer 0|1|2|3|4|5. (from UM10326: LPC32x0 User manual, page 540)  */
end_comment

begin_define
define|#
directive|define
name|LPC_TIMER_IR
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_TCR
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_TCR_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_TCR_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_TC
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_PR
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_PC
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR0I
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR0R
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR0S
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR1I
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR1R
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR1S
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR2I
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR2R
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR2S
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR3I
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR3R
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MCR_MR3S
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_MR0
value|0x18
end_define

begin_define
define|#
directive|define
name|LPC_TIMER_CTCR
value|0x70
end_define

begin_comment
comment|/*  * Watchdog timer. (from UM10326: LPC32x0 User manual, page 572)  */
end_comment

begin_define
define|#
directive|define
name|LPC_WDTIM_PHYS_BASE
value|(LPC_DEV_PHYS_BASE + 0x3c000)
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_INT
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_COUNTER
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_MCTRL
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_MATCH0
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_EMR
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_PULSE
value|0x18
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_RES
value|0x1c
end_define

begin_define
define|#
directive|define
name|LPC_WDTIM_SIZE
value|0x20
end_define

begin_comment
comment|/*  * Clocking and power control. (from UM10326: LPC32x0 User manual, page 58)  */
end_comment

begin_define
define|#
directive|define
name|LPC_CLKPWR_PHYS_BASE
value|(LPC_DEV_PHYS_BASE + 0x4000)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_PWR_CTRL
value|0x44
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_OSC_CTRL
value|0x4c
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SYSCLK_CTRL
value|0x50
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_PLL397_CTRL
value|0x48
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_HCLKPLL_CTRL
value|0x58
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_HCLKDIV_CTRL
value|0x40
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TEST_CTRL
value|0xa4
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_AUTOCLK_CTRL
value|0xec
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_START_ER_PIN
value|0x30
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_START_ER_INT
value|0x20
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_P0_INTR_ER
value|0x18
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_START_SR_PIN
value|0x38
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_START_SR_INT
value|0x28
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_START_RSR_PIN
value|0x34
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_START_RSR_INT
value|0x24
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_START_APR_PIN
value|0x3c
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_START_APR_INT
value|0x2c
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL
value|0x64
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_SLAVE_HCLK
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_I2C_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_DEV_NEED_CLK_EN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_HOST_NEED_CLK_EN
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_BUSKEEPER
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_CLK_EN2
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_CLK_EN1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_PLL_PDOWN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_BYPASS
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_DIRECT_OUT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_FEEDBACK
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_POSTDIV
parameter_list|(
name|_x
parameter_list|)
value|((_x& 0x3)<< 11)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_PREDIV
parameter_list|(
name|_x
parameter_list|)
value|((_x& 0x3)<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_FDBKDIV
parameter_list|(
name|_x
parameter_list|)
value|(((_x-1)& 0xff)<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USB_CTRL_PLL_LOCK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_USBDIV_CTRL
value|0x1c
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MS_CTRL
value|0x80
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MS_CTRL_DISABLE_SD
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MS_CTRL_CLOCK_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MS_CTRL_MSSDIO23_PAD
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MS_CTRL_MSSDIO1_PAD
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MS_CTRL_MSSDIO0_PAD
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MS_CTRL_SD_CLOCK
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MS_CTRL_CLKDIV_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_DMACLK_CTRL
value|0xe8
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_DMACLK_CTRL_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_FLASHCLK_CTRL
value|0xc8
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MACCLK_CTRL
value|0x90
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MACCLK_CTRL_REG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MACCLK_CTRL_SLAVE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MACCLK_CTRL_MASTER
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_MACCLK_CTRL_HDWINF
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x3)<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL
value|0x54
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL_DISPTYPE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL_MODE
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL_MODE_12
value|0x0
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL_MODE_15
value|0x1
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL_MODE_16
value|0x2
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL_MODE_24
value|0x3
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL_HCLKEN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_LCDCLK_CTRL_CLKDIV
parameter_list|(
name|_n
parameter_list|)
value|((_n)& 0x1f)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_I2S_CTRL
value|0x7c
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SSP_CTRL
value|0x78
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SSP_CTRL_SSP1RXDMA
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SSP_CTRL_SSP1TXDMA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SSP_CTRL_SSP0RXDMA
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SSP_CTRL_SSP0TXDMA
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SSP_CTRL_SSP1EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SSP_CTRL_SSP0EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SPI_CTRL
value|0xc4
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_I2CCLK_CTRL
value|0xac
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL1
value|0xc0
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL1_TIMER4
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL1_TIMER5
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL1_TIMER0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL1_TIMER1
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL1_TIMER2
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL1_TIMER3
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL1_MOTORCTL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL
value|0xbc
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL_WATCHDOG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_TIMCLK_CTRL_HSTIMER
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_ADCLK_CTRL
value|0xb4
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_ADCLK_CTRL1
value|0x60
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_KEYCLK_CTRL
value|0xb0
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_PWMCLK_CTRL
value|0xb8
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_UARTCLK_CTRL
value|0xe4
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_POS0_IRAM_CTRL
value|0x110
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_POS1_IRAM_CTRL
value|0x114
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_SIZE
value|0x118
end_define

begin_comment
comment|/* Additional UART registers in CLKPWR address space. */
end_comment

begin_define
define|#
directive|define
name|LPC_CLKPWR_UART_U3CLK
value|0xd0
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_UART_U4CLK
value|0xd4
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_UART_U5CLK
value|0xd8
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_UART_U6CLK
value|0xdc
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_UART_UCLK_HCLK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_UART_UCLK_X
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_UART_UCLK_Y
parameter_list|(
name|_n
parameter_list|)
value|((_n)& 0xff)
end_define

begin_define
define|#
directive|define
name|LPC_CLKPWR_UART_IRDACLK
value|0xe0
end_define

begin_comment
comment|/* Additional UART registers */
end_comment

begin_define
define|#
directive|define
name|LPC_UART_BASE
value|0x80000
end_define

begin_define
define|#
directive|define
name|LPC_UART_CONTROL_BASE
value|0x54000
end_define

begin_define
define|#
directive|define
name|LPC_UART5_BASE
value|0x90000
end_define

begin_define
define|#
directive|define
name|LPC_UART_CTRL
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_UART_CLKMODE
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_UART_CLKMODE_UART3
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0x3)<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_UART_CLKMODE_UART4
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0x3)<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_UART_CLKMODE_UART5
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0x3)<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_UART_CLKMODE_UART6
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0x3)<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_UART_LOOP
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_UART_CONTROL_SIZE
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_UART_FIFOSIZE
value|64
end_define

begin_comment
comment|/*  * Real time clock. (from UM10326: LPC32x0 User manual, page 566)  */
end_comment

begin_define
define|#
directive|define
name|LPC_RTC_UCOUNT
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_RTC_DCOUNT
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_RTC_MATCH0
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_RTC_MATCH1
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_RTC_CTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_RTC_CTRL_ONSW
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_RTC_CTRL_DISABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_RTC_CTRL_RTCRESET
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_RTC_CTRL_MATCH0ONSW
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_RTC_CTRL_MATCH1ONSW
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_RTC_CTRL_MATCH1INTR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_RTC_CTRL_MATCH0INTR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_RTC_INTSTAT
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_RTC_KEY
value|0x18
end_define

begin_define
define|#
directive|define
name|LPC_RTC_SRAM_BEGIN
value|0x80
end_define

begin_define
define|#
directive|define
name|LPC_RTC_SRAM_END
value|0xff
end_define

begin_comment
comment|/*  * MMC/SD controller. (from UM10326: LPC32x0 User manual, page 436)  */
end_comment

begin_define
define|#
directive|define
name|LPC_SD_PHYS_BASE
value|(LPC_DEV_P5_PHYS_BASE + 0x98000)
end_define

begin_define
define|#
directive|define
name|LPC_SD_CLK
value|(13 * 1000 * 1000)
end_define

begin_comment
comment|// 13Mhz
end_comment

begin_define
define|#
directive|define
name|LPC_SD_POWER
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_SD_POWER_OPENDRAIN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_SD_POWER_CTRL_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_SD_POWER_CTRL_UP
value|0x02
end_define

begin_define
define|#
directive|define
name|LPC_SD_POWER_CTRL_ON
value|0x03
end_define

begin_define
define|#
directive|define
name|LPC_SD_CLOCK
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_SD_CLOCK_WIDEBUS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LPC_SD_CLOCK_BYPASS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_SD_CLOCK_PWRSAVE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_SD_CLOCK_ENABLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_SD_CLOCK_CLKDIVMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|LPC_SD_ARGUMENT
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_SD_COMMAND
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_SD_COMMAND_ENABLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_SD_COMMAND_PENDING
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_SD_COMMAND_INTERRUPT
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_SD_COMMAND_LONGRSP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_SD_COMMAND_RESPONSE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_SD_COMMAND_CMDINDEXMASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|LPC_SD_RESPCMD
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_SD_RESP0
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_SD_RESP1
value|0x18
end_define

begin_define
define|#
directive|define
name|LPC_SD_RESP2
value|0x1c
end_define

begin_define
define|#
directive|define
name|LPC_SD_RESP3
value|0x20
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATATIMER
value|0x24
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATALENGTH
value|0x28
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACTRL
value|0x2c
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACTRL_BLOCKSIZESHIFT
value|4
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACTRL_BLOCKSIZEMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACTRL_DMAENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACTRL_MODE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACTRL_WRITE
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACTRL_READ
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACTRL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SD_DATACNT
value|0x30
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS
value|0x34
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_RXDATAAVLBL
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_TXDATAAVLBL
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_RXFIFOEMPTY
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_TXFIFOEMPTY
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_RXFIFOFULL
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_TXFIFOFULL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_RXFIFOHALFFULL
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_TXFIFOHALFEMPTY
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_RXACTIVE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_TXACTIVE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_CMDACTIVE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_DATABLOCKEND
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_STARTBITERR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_DATAEND
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_CMDSENT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_CMDRESPEND
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_RXOVERRUN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_TXUNDERRUN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_DATATIMEOUT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_CMDTIMEOUT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_DATACRCFAIL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SD_STATUS_CMDCRCFAIL
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SD_CLEAR
value|0x38
end_define

begin_define
define|#
directive|define
name|LPC_SD_MASK0
value|0x03c
end_define

begin_define
define|#
directive|define
name|LPC_SD_MASK1
value|0x40
end_define

begin_define
define|#
directive|define
name|LPC_SD_FIFOCNT
value|0x48
end_define

begin_define
define|#
directive|define
name|LPC_SD_FIFO
value|0x80
end_define

begin_comment
comment|/*  * USB OTG controller (from UM10326: LPC32x0 User manual, page 410)  */
end_comment

begin_define
define|#
directive|define
name|LPC_OTG_INT_STATUS
value|0x100
end_define

begin_define
define|#
directive|define
name|LPC_OTG_INT_ENABLE
value|0x104
end_define

begin_define
define|#
directive|define
name|LPC_OTG_INT_SET
value|0x108
end_define

begin_define
define|#
directive|define
name|LPC_OTG_INT_CLEAR
value|0x10c
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS
value|0x110
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS_ATOB_HNP_TRACK
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS_BTOA_HNP_TACK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS_TRANSP_I2C_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS_TIMER_RESET
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS_TIMER_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS_TIMER_MODE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS_TIMER_SCALE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_STATUS_HOST_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_TIMER
value|0x114
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_TXRX
value|0x300
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS
value|0x304
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_TFE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_TFF
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_RFE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_RFF
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_SDA
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_SCL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_ACTIVE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_DRSI
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_DRMI
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_NAI
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_AFI
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_STATUS_TDI
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL
value|0x308
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_SRST
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_TFFIE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_RFDAIE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_RFFIE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_DRSIE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_DRMIE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_NAIE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_AFIE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CTRL_TDIE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CLKHI
value|0x30c
end_define

begin_define
define|#
directive|define
name|LPC_OTG_I2C_CLKLO
value|0x310
end_define

begin_define
define|#
directive|define
name|LPC_OTG_CLOCK_CTRL
value|0xff4
end_define

begin_define
define|#
directive|define
name|LPC_OTG_CLOCK_CTRL_AHB_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_CLOCK_CTRL_OTG_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_CLOCK_CTRL_I2C_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_CLOCK_CTRL_DEV_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_CLOCK_CTRL_HOST_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_OTG_CLOCK_STATUS
value|0xff8
end_define

begin_comment
comment|/*  * ISP3101 USB transceiver registers  */
end_comment

begin_define
define|#
directive|define
name|LPC_ISP3101_I2C_ADDR
value|0x2d
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MODE_CONTROL_1
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC1_SPEED_REG
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC1_SUSPEND_REG
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC1_DAT_SE0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC1_TRANSPARENT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC1_BDIS_ACON_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC1_OE_INT_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC1_UART_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MODE_CONTROL_2
value|0x12
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC2_GLOBAL_PWR_DN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC2_SPD_SUSP_CTRL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC2_BI_DI
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC2_TRANSP_BDIR0
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC2_TRANSP_BDIR1
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC2_AUDIO_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC2_PSW_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_MC2_EN2V7
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG_CONTROL_1
value|0x06
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG1_DP_PULLUP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG1_DM_PULLUP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG1_DP_PULLDOWN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG1_DM_PULLDOWN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG1_ID_PULLDOWN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG1_VBUS_DRV
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG1_VBUS_DISCHRG
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG1_VBUS_CHRG
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG_CONTROL_2
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG_INTR_LATCH
value|0x0a
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG_INTR_FALLING
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_OTG_INTR_RISING
value|0x0e
end_define

begin_define
define|#
directive|define
name|LPC_ISP3101_REG_CLEAR_ADDR
value|0x01
end_define

begin_comment
comment|/*  * LCD Controller (from UM10326: LPC32x0 User manual, page 229)  */
end_comment

begin_define
define|#
directive|define
name|LPC_LCD_TIMH
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMH_HBP
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0xff)<< 24)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMH_HFP
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMH_HSW
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMH_PPL
parameter_list|(
name|_n
parameter_list|)
value|(((_n) / 16 - 1)<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMV
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMV_VBP
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0xff)<< 24)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMV_VFP
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0xff)<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMV_VSW
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0x3f)<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_TIMV_LPP
parameter_list|(
name|_n
parameter_list|)
value|((_n)& 0x1ff)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_PCD_HI
value|(((_n)& 0x1f)<< 27)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_BCD
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_CPL
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0x3ff)<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_IOE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_IPC
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_IHS
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_IVS
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_ACB
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x1f)<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_CLKSEL
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_POL_PCD_LO
parameter_list|(
name|_n
parameter_list|)
value|((_n)& 0x1f)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_LE
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_LCD_LE_LEE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_LE_LED
value|((_n)& 0x7f)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_UPBASE
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_LCD_LPBASE
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL
value|0x18
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_WATERMARK
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_LCDVCOMP
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0x3)<< 12)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_LCDPWR
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BEPO
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BEBO
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BGR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_LCDDUAL
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_LCDMONO8
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_LCDTFT
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_LCDBW
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_LCDBPP
parameter_list|(
name|_n
parameter_list|)
value|(((_n)& 0x7)<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BPP1
value|0
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BPP2
value|1
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BPP4
value|2
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BPP8
value|3
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BPP16
value|4
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BPP24
value|5
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BPP16_565
value|6
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_BPP12_444
value|7
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CTRL_LCDEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_LCD_INTMSK
value|0x1c
end_define

begin_define
define|#
directive|define
name|LPC_LCD_INTRAW
value|0x20
end_define

begin_define
define|#
directive|define
name|LPC_LCD_INTSTAT
value|0x24
end_define

begin_define
define|#
directive|define
name|LPC_LCD_INTCLR
value|0x28
end_define

begin_define
define|#
directive|define
name|LPC_LCD_UPCURR
value|0x2c
end_define

begin_define
define|#
directive|define
name|LPC_LCD_LPCURR
value|0x30
end_define

begin_define
define|#
directive|define
name|LPC_LCD_PAL
value|0x200
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_IMG
value|0x800
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_CTRL
value|0xc00
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_CFG
value|0xc04
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_PAL0
value|0xc08
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_PAL1
value|0xc0c
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_XY
value|0xc10
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_CLIP
value|0xc14
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_INTMSK
value|0xc20
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_INTCLR
value|0xc24
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_INTRAW
value|0xc28
end_define

begin_define
define|#
directive|define
name|LPC_LCD_CRSR_INTSTAT
value|0xc2c
end_define

begin_comment
comment|/*  * SPI interface (from UM10326: LPC32x0 User manual, page 483)  */
end_comment

begin_define
define|#
directive|define
name|LPC_SPI_GLOBAL
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_SPI_GLOBAL_RST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_GLOBAL_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_UNIDIR
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_BHALT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_BPOL
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_MSB
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_MODE
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_RXTX
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_THR
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_SHIFT_OFF
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_BITNUM
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0xf)<< 9)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_MS
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_CON_RATE
parameter_list|(
name|_n
parameter_list|)
value|(_n& 0x7f)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_FRM
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_SPI_IER
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_SPI_IER_INTEOT
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_IER_INTTHR
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_STAT
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_SPI_STAT_INTCLR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_STAT_EOT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_STAT_BUSYLEV
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_STAT_SHIFTACT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_STAT_BF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_STAT_THR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_STAT_BE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SPI_DAT
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_SPI_TIM_CTRL
value|0x400
end_define

begin_define
define|#
directive|define
name|LPC_SPI_TIM_COUNT
value|0x404
end_define

begin_define
define|#
directive|define
name|LPC_SPI_TIM_STAT
value|0x408
end_define

begin_comment
comment|/*  * SSP interface (from UM10326: LPC32x0 User manual, page 500)  */
end_comment

begin_define
define|#
directive|define
name|LPC_SSP0_BASE
value|0x4c00
end_define

begin_define
define|#
directive|define
name|LPC_SSP1_BASE
value|0xc000
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR0
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR0_DSS
parameter_list|(
name|_n
parameter_list|)
value|((_n-1)& 0xf)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR0_TI
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR0_MICROWIRE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR0_CPOL
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR0_CPHA
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR0_SCR
parameter_list|(
name|_n
parameter_list|)
value|((_x&& 0xff)<< 8)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR1
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR1_LBM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR1_SSE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR1_MS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CR1_SOD
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_DR
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_SSP_SR
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_SSP_SR_TFE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_SR_TNF
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_SR_RNE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_SR_RFF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_SR_BSY
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_CPSR
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_SSP_IMSC
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_SSP_IMSC_RORIM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_IMSC_RTIM
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_IMSC_RXIM
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_IMSC_TXIM
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_RIS
value|0x18
end_define

begin_define
define|#
directive|define
name|LPC_SSP_RIS_RORRIS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_RIS_RTRIS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_RIS_RXRIS
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_RIS_TXRIS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|LPC_SSP_MIS
value|0x1c
end_define

begin_define
define|#
directive|define
name|LPC_SSP_ICR
value|0x20
end_define

begin_define
define|#
directive|define
name|LPC_SSP_DMACR
value|0x24
end_define

begin_comment
comment|/*  * GPIO (from UM10326: LPC32x0 User manual, page 606)  */
end_comment

begin_define
define|#
directive|define
name|LPC_GPIO_PHYS_BASE
value|(LPC_DEV_PHYS_BASE + 0x28000)
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P0_COUNT
value|8
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P1_COUNT
value|24
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P2_COUNT
value|13
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P3_COUNT
value|52
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P0_INP_STATE
value|0x40
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P0_OUTP_SET
value|0x44
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P0_OUTP_CLR
value|0x48
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P0_OUTP_STATE
value|0x4c
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P0_DIR_SET
value|0x50
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P0_DIR_CLR
value|0x54
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P0_DIR_STATE
value|0x58
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P1_INP_STATE
value|0x60
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P1_OUTP_SET
value|0x64
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P1_OUTP_CLR
value|0x68
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P1_OUTP_STATE
value|0x6c
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P1_DIR_SET
value|0x70
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P1_DIR_CLR
value|0x74
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P1_DIR_STATE
value|0x78
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P2_INP_STATE
value|0x1c
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P2_OUTP_SET
value|0x20
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P2_OUTP_CLR
value|0x24
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P2_DIR_SET
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P2_DIR_CLR
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P2_DIR_STATE
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P3_INP_STATE
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P3_OUTP_SET
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P3_OUTP_CLR
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_P3_OUTP_STATE
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_SIZE
value|0x80
end_define

begin_comment
comment|/* Aliases for logical pin numbers: */
end_comment

begin_define
define|#
directive|define
name|LPC_GPIO_GPI_00
parameter_list|(
name|_n
parameter_list|)
value|(0 + _n)
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_GPI_15
parameter_list|(
name|_n
parameter_list|)
value|(10 + _n)
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_GPI_25
value|(19)
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_GPI_27
parameter_list|(
name|_n
parameter_list|)
value|(20 + _n)
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_GPO_00
parameter_list|(
name|_n
parameter_list|)
value|(22 + _n)
end_define

begin_define
define|#
directive|define
name|LPC_GPIO_GPIO_00
parameter_list|(
name|_n
parameter_list|)
value|(46 + _n)
end_define

begin_comment
comment|/* SPI devices chip selects: */
end_comment

begin_define
define|#
directive|define
name|SSD1289_CS_PIN
value|LPC_GPIO_GPO_00(4)
end_define

begin_define
define|#
directive|define
name|SSD1289_DC_PIN
value|LPC_GPIO_GPO_00(5)
end_define

begin_define
define|#
directive|define
name|ADS7846_CS_PIN
value|LPC_GPIO_GPO_00(11)
end_define

begin_define
define|#
directive|define
name|ADS7846_INTR_PIN
value|LPC_GPIO_GPIO_00(0)
end_define

begin_comment
comment|/*  * GPDMA controller (from UM10326: LPC32x0 User manual, page 106)  */
end_comment

begin_define
define|#
directive|define
name|LPC_DMAC_INTSTAT
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_INTTCSTAT
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_INTTCCLEAR
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_INTERRSTAT
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_INTERRCLEAR
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_RAWINTTCSTAT
value|0x14
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_RAWINTERRSTAT
value|0x18
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_ENABLED_CHANNELS
value|0x1c
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SOFTBREQ
value|0x20
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SOFTSREQ
value|0x24
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SOFTLBREQ
value|0x28
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SOFTLSREQ
value|0x2c
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CONFIG
value|0x30
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CONFIG_M1
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CONFIG_M0
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CONFIG_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CHADDR
parameter_list|(
name|_n
parameter_list|)
value|(0x100 + (_n * 0x20))
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CHNUM
value|8
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CHSIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_SRCADDR
value|0x00
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_DSTADDR
value|0x04
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_LLI
value|0x08
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_LLI_AHB1
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL
value|0x0c
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_I
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_DI
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_SI
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_D
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_S
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_WIDTH_4
value|2
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_DWIDTH
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x7)<< 21)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_SWIDTH
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x7)<< 18)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_BURST_8
value|2
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_DBSIZE
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x7)<< 15)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_SBSIZE
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x7)<< 12)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONTROL_XFERLEN
parameter_list|(
name|_n
parameter_list|)
value|(_n& 0xfff)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG
value|0x10
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_H
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_A
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_L
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_ITC
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_IE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_FLOWCNTL
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x7)<< 11)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_DESTP
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x1f)<< 6)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_SRCP
parameter_list|(
name|_n
parameter_list|)
value|((_n& 0x1f)<< 1)
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_CH_CONFIG_E
value|(1<< 0)
end_define

begin_comment
comment|/* DMA flow control values */
end_comment

begin_define
define|#
directive|define
name|LPC_DMAC_FLOW_D_M2M
value|0
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_FLOW_D_M2P
value|1
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_FLOW_D_P2M
value|2
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_FLOW_D_P2P
value|3
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_FLOW_DP_P2P
value|4
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_FLOW_P_M2P
value|5
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_FLOW_P_P2M
value|6
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_FLOW_SP_P2P
value|7
end_define

begin_comment
comment|/* DMA peripheral ID's */
end_comment

begin_define
define|#
directive|define
name|LPC_DMAC_I2S0_DMA0_ID
value|0
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_NAND_ID
value|1
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_IS21_DMA0_ID
value|2
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SSP1_ID
value|3
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SPI2_ID
value|3
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SD_ID
value|4
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_UART1_TX_ID
value|5
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_UART1_RX_ID
value|6
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_UART2_TX_ID
value|7
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_UART2_RX_ID
value|8
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_UART7_TX_ID
value|9
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_UART7_RX_ID
value|10
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_I2S1_DMA1_ID
value|10
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SPI1_ID
value|11
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SSP1_TX_ID
value|11
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_NAND2_ID
value|12
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_I2S0_DMA1_ID
value|13
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SSP0_RX
value|14
end_define

begin_define
define|#
directive|define
name|LPC_DMAC_SSP0_TX
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_LPC_LPCREG_H */
end_comment

end_unit

