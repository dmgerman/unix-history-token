begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2007-2008 MARVELL INTERNATIONAL LTD.  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of MARVELL nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MVREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MVREG_H_
end_define

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_comment
comment|/*  * Physical addresses of integrated SoC peripherals  */
end_comment

begin_define
define|#
directive|define
name|MV_PHYS_BASE
value|0xF1000000
end_define

begin_define
define|#
directive|define
name|MV_SIZE
value|0x100000
end_define

begin_comment
comment|/*  * Decode windows addresses (physical)  */
end_comment

begin_define
define|#
directive|define
name|MV_PCIE_IO_PHYS_BASE
value|(MV_PHYS_BASE + MV_SIZE)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_IO_BASE
value|MV_PCIE_IO_PHYS_BASE
end_define

begin_define
define|#
directive|define
name|MV_PCIE_IO_SIZE
value|(1024 * 1024)
end_define

begin_define
define|#
directive|define
name|MV_PCI_IO_PHYS_BASE
value|(MV_PCIE_IO_PHYS_BASE + MV_PCIE_IO_SIZE)
end_define

begin_define
define|#
directive|define
name|MV_PCI_IO_BASE
value|MV_PCI_IO_PHYS_BASE
end_define

begin_define
define|#
directive|define
name|MV_PCI_IO_SIZE
value|(1024 * 1024)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_MEM_PHYS_BASE
value|(MV_PCI_IO_PHYS_BASE + MV_PCI_IO_SIZE)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_MEM_BASE
value|MV_PCIE_MEM_PHYS_BASE
end_define

begin_define
define|#
directive|define
name|MV_PCIE_MEM_SIZE
value|(64 * 1024 * 1024)
end_define

begin_define
define|#
directive|define
name|MV_PCI_MEM_PHYS_BASE
value|(MV_PCIE_MEM_PHYS_BASE + MV_PCIE_MEM_SIZE)
end_define

begin_define
define|#
directive|define
name|MV_PCI_MEM_BASE
value|MV_PCI_MEM_PHYS_BASE
end_define

begin_define
define|#
directive|define
name|MV_PCI_MEM_SIZE
value|(64 * 1024 * 1024)
end_define

begin_comment
comment|/* XXX DEV_BOOT, CSx are board specific, should be defined per platform */
end_comment

begin_comment
comment|/* 512KB NOR FLASH */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_BOOT_PHYS_BASE
value|(MV_PCI_MEM_PHYS_BASE + MV_PCI_MEM_SIZE)
end_define

begin_define
define|#
directive|define
name|MV_DEV_BOOT_SIZE
value|(512 * 1024)
end_define

begin_comment
comment|/* CS0: 7-seg LED */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_CS0_PHYS_BASE
value|0xFA000000
end_define

begin_define
define|#
directive|define
name|MV_DEV_CS0_SIZE
value|(1024 * 1024)
end_define

begin_comment
comment|/* XXX u-boot has 2MB */
end_comment

begin_comment
comment|/* CS1: 32MB NOR FLASH */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_CS1_PHYS_BASE
value|(MV_DEV_CS0_PHYS_BASE + MV_DEV_CS0_SIZE)
end_define

begin_define
define|#
directive|define
name|MV_DEV_CS1_SIZE
value|(32 * 1024 * 1024)
end_define

begin_comment
comment|/* CS2: 32MB NAND FLASH */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_CS2_PHYS_BASE
value|(MV_DEV_CS1_PHYS_BASE + MV_DEV_CS1_SIZE)
end_define

begin_define
define|#
directive|define
name|MV_DEV_CS2_SIZE
value|1024
end_define

begin_comment
comment|/* XXX u-boot has 1MB */
end_comment

begin_comment
comment|/* XXX this is probably not robust against wraparounds... */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|MV_DEV_CS2_PHYS_BASE
operator|+
name|MV_DEV_CS2_SIZE
operator|)
operator|>
literal|0xFFFEFFFF
operator|)
end_if

begin_error
error|#
directive|error
error|Devices memory layout overlaps reset vectors range!
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Integrated SoC peripherals addresses  */
end_comment

begin_define
define|#
directive|define
name|MV_BASE
value|MV_PHYS_BASE
end_define

begin_comment
comment|/* VA == PA mapping */
end_comment

begin_define
define|#
directive|define
name|MV_DDR_CADR_BASE
value|(MV_BASE + 0x1500)
end_define

begin_define
define|#
directive|define
name|MV_MPP_BASE
value|(MV_BASE + 0x10000)
end_define

begin_define
define|#
directive|define
name|MV_GPIO_BASE
value|(MV_BASE + 0x10100)
end_define

begin_define
define|#
directive|define
name|MV_GPIO_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|MV_RTC_BASE
value|(MV_BASE + 0x10300)
end_define

begin_define
define|#
directive|define
name|MV_RTC_SIZE
value|0x08
end_define

begin_define
define|#
directive|define
name|MV_TWSI_BASE
value|(MV_BASE + 0x11000)
end_define

begin_define
define|#
directive|define
name|MV_TWSI_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|MV_UART0_BASE
value|(MV_BASE + 0x12000)
end_define

begin_define
define|#
directive|define
name|MV_UART1_BASE
value|(MV_BASE + 0x12100)
end_define

begin_define
define|#
directive|define
name|MV_UART_SIZE
value|0x20
end_define

begin_define
define|#
directive|define
name|MV_MBUS_BRIDGE_BASE
value|(MV_BASE + 0x20000)
end_define

begin_define
define|#
directive|define
name|MV_INTREGS_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x80)
end_define

begin_define
define|#
directive|define
name|MV_CPU_CONTROL_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x100)
end_define

begin_define
define|#
directive|define
name|MV_IC_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x200)
end_define

begin_define
define|#
directive|define
name|MV_IC_SIZE
value|0x3C
end_define

begin_define
define|#
directive|define
name|MV_TIMERS_BASE
value|(MV_MBUS_BRIDGE_BASE + 0x300)
end_define

begin_define
define|#
directive|define
name|MV_TIMERS_SIZE
value|0x30
end_define

begin_define
define|#
directive|define
name|MV_PCI_BASE
value|(MV_BASE + 0x30000)
end_define

begin_define
define|#
directive|define
name|MV_PCI_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BASE
value|(MV_BASE + 0x40000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|MV_PCIE00_BASE
value|(MV_PCIE_BASE + 0x00000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE01_BASE
value|(MV_PCIE_BASE + 0x04000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE02_BASE
value|(MV_PCIE_BASE + 0x08000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE03_BASE
value|(MV_PCIE_BASE + 0x0C000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE10_BASE
value|(MV_PCIE_BASE + 0x40000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE11_BASE
value|(MV_PCIE_BASE + 0x44000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE12_BASE
value|(MV_PCIE_BASE + 0x48000)
end_define

begin_define
define|#
directive|define
name|MV_PCIE13_BASE
value|(MV_PCIE_BASE + 0x4C000)
end_define

begin_define
define|#
directive|define
name|MV_USB0_BASE
value|(MV_BASE + 0x50000)
end_define

begin_define
define|#
directive|define
name|MV_USB1_BASE
value|(MV_USB0_BASE + 0x1000)
end_define

begin_define
define|#
directive|define
name|MV_USB2_BASE
value|(MV_USB0_BASE + 0x2000)
end_define

begin_define
define|#
directive|define
name|MV_USB_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|MV_USB_HOST_OFST
value|0x0100
end_define

begin_comment
comment|/* EHCI HC regs start at this offset within USB range */
end_comment

begin_define
define|#
directive|define
name|MV_USB_AWR_BASE
value|(MV_USB0_BASE + 0x320)
end_define

begin_define
define|#
directive|define
name|MV_IDMA_BASE
value|(MV_BASE + 0x60000)
end_define

begin_define
define|#
directive|define
name|MV_IDMA_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|MV_XOR_BASE
value|(MV_BASE + 0x60000)
end_define

begin_define
define|#
directive|define
name|MV_XOR_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|MV_ETH0_BASE
value|(MV_BASE + 0x72000)
end_define

begin_define
define|#
directive|define
name|MV_ETH1_BASE
value|(MV_BASE + 0x76000)
end_define

begin_define
define|#
directive|define
name|MV_ETH_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|MV_DEV_CS0_BASE
value|MV_DEV_CS0_PHYS_BASE
end_define

begin_comment
comment|/*  * Interrupt sources  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ORION
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_INT_BRIDGE
value|0
end_define

begin_comment
comment|/* AHB-MBus Bridge Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_UART0
value|3
end_define

begin_comment
comment|/* UART0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_UART1
value|4
end_define

begin_define
define|#
directive|define
name|MV_INT_GPIO7_0
value|6
end_define

begin_comment
comment|/* GPIO[7:0] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO15_8
value|7
end_define

begin_comment
comment|/* GPIO[15:8] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO23_16
value|8
end_define

begin_comment
comment|/* GPIO[23:16] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO31_24
value|9
end_define

begin_comment
comment|/* GPIO[31:24] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX0_ERR
value|10
end_define

begin_comment
comment|/* PCI Express Error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX0
value|11
end_define

begin_comment
comment|/* PCI Express INTA,B,C,D Message */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PCI_ERR
value|15
end_define

begin_comment
comment|/* PCI Error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_USB_BERR
value|16
end_define

begin_comment
comment|/* USB Bridge Error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_USB_CI
value|17
end_define

begin_comment
comment|/* USB Controller interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBERX
value|18
end_define

begin_comment
comment|/* GbE receive interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBETX
value|19
end_define

begin_comment
comment|/* GbE transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBEMISC
value|20
end_define

begin_comment
comment|/* GbE misc. interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBESUM
value|21
end_define

begin_comment
comment|/* GbE summary interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBEERR
value|22
end_define

begin_comment
comment|/* GbE error interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA_ERR
value|23
end_define

begin_comment
comment|/* DMA error interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA0
value|24
end_define

begin_comment
comment|/* IDMA chan. 0 completion interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA1
value|25
end_define

begin_comment
comment|/* IDMA chan. 1 completion interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA2
value|26
end_define

begin_comment
comment|/* IDMA chan. 2 completion interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA3
value|27
end_define

begin_comment
comment|/* IDMA chan. 3 completion interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_SATA
value|29
end_define

begin_comment
comment|/* Serial-ATA Interrupt */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_KIRKWOOD
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_INT_BRIDGE
value|1
end_define

begin_comment
comment|/* AHB-MBus Bridge Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR0_CHAN0
value|5
end_define

begin_comment
comment|/* XOR engine 0 channel 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR0_CHAN1
value|6
end_define

begin_comment
comment|/* XOR engine 0 channel 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR1_CHAN0
value|7
end_define

begin_comment
comment|/* XOR engine 1 channel 0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR1_CHAN1
value|8
end_define

begin_comment
comment|/* XOR engine 1 channel 1 Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX0
value|9
end_define

begin_comment
comment|/* PCI Express INTA,B,C,D Message */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBESUM
value|11
end_define

begin_comment
comment|/* GbE0 summary interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBERX
value|12
end_define

begin_comment
comment|/* GbE0 receive interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBETX
value|13
end_define

begin_comment
comment|/* GbE0 transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBEMISC
value|14
end_define

begin_comment
comment|/* GbE0 misc. interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1SUM
value|15
end_define

begin_comment
comment|/* GbE1 summary interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1RX
value|16
end_define

begin_comment
comment|/* GbE1 receive interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1TX
value|17
end_define

begin_comment
comment|/* GbE1 transmit interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1MISC
value|18
end_define

begin_comment
comment|/* GbE1 misc. interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_USB_CI
value|19
end_define

begin_comment
comment|/* USB Controller interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_SATA
value|21
end_define

begin_comment
comment|/* Serial-ATA Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA_ERR
value|23
end_define

begin_comment
comment|/* DMA error interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_UART0
value|33
end_define

begin_comment
comment|/* UART0 Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_UART1
value|34
end_define

begin_define
define|#
directive|define
name|MV_INT_GPIO7_0
value|35
end_define

begin_comment
comment|/* GPIO[7:0] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO15_8
value|36
end_define

begin_comment
comment|/* GPIO[15:8] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO23_16
value|37
end_define

begin_comment
comment|/* GPIO[23:16] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO31_24
value|38
end_define

begin_comment
comment|/* GPIO[31:24] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIOHI7_0
value|39
end_define

begin_comment
comment|/* GPIOHI[7:0] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIOHI15_8
value|40
end_define

begin_comment
comment|/* GPIOHI[15:8] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIOHI23_16
value|41
end_define

begin_comment
comment|/* GPIOHI[23:16] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR0_ERR
value|42
end_define

begin_comment
comment|/* XOR engine 0 error Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR1_ERR
value|43
end_define

begin_comment
comment|/* XOR engine 1 error Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX0_ERR
value|44
end_define

begin_comment
comment|/* PCI Express Error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBEERR
value|46
end_define

begin_comment
comment|/* GbE0 error interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1ERR
value|47
end_define

begin_comment
comment|/* GbE1 error interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_USB_BERR
value|48
end_define

begin_comment
comment|/* USB Bridge Error */
end_comment

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MV_INT_ERRSUM
value|0
end_define

begin_comment
comment|/* Summary of error interrupts */
end_comment

begin_define
define|#
directive|define
name|MV_INT_SPI
value|1
end_define

begin_comment
comment|/* SPI interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_TWSI0
value|2
end_define

begin_comment
comment|/* TWSI0 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_TWSI1
value|3
end_define

begin_comment
comment|/* TWSI1 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA0
value|4
end_define

begin_comment
comment|/* IDMA Channel0 completion */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA1
value|5
end_define

begin_comment
comment|/* IDMA Channel0 completion */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA2
value|6
end_define

begin_comment
comment|/* IDMA Channel0 completion */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA3
value|7
end_define

begin_comment
comment|/* IDMA Channel0 completion */
end_comment

begin_define
define|#
directive|define
name|MV_INT_TIMER0
value|8
end_define

begin_comment
comment|/* Timer0 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_TIMER1
value|9
end_define

begin_comment
comment|/* Timer1 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_TIMER2
value|10
end_define

begin_comment
comment|/* Timer2 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_TIMER3
value|11
end_define

begin_comment
comment|/* Timer3 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_UART0
value|12
end_define

begin_comment
comment|/* UART0 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_UART1
value|13
end_define

begin_comment
comment|/* UART1 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_UART2
value|14
end_define

begin_comment
comment|/* UART2 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_UART3
value|15
end_define

begin_comment
comment|/* UART3 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_USB0
value|16
end_define

begin_comment
comment|/* USB0 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_USB1
value|17
end_define

begin_comment
comment|/* USB1 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_USB2
value|18
end_define

begin_comment
comment|/* USB2 interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_CRYPTO
value|19
end_define

begin_comment
comment|/* Crypto engine completion interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR0
value|22
end_define

begin_comment
comment|/* XOR engine 0 completion interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR1
value|23
end_define

begin_comment
comment|/* XOR engine 1 completion interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_SATA
value|26
end_define

begin_comment
comment|/* SATA interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX00
value|32
end_define

begin_comment
comment|/* PCI Express port 0.0 INTA/B/C/D */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX01
value|33
end_define

begin_comment
comment|/* PCI Express port 0.1 INTA/B/C/D */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX02
value|34
end_define

begin_comment
comment|/* PCI Express port 0.2 INTA/B/C/D */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX03
value|35
end_define

begin_comment
comment|/* PCI Express port 0.3 INTA/B/C/D */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX10
value|36
end_define

begin_comment
comment|/* PCI Express port 1.0 INTA/B/C/D */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX11
value|37
end_define

begin_comment
comment|/* PCI Express port 1.1 INTA/B/C/D */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX12
value|38
end_define

begin_comment
comment|/* PCI Express port 1.2 INTA/B/C/D */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX13
value|39
end_define

begin_comment
comment|/* PCI Express port 1.3 INTA/B/C/D */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBESUM
value|40
end_define

begin_comment
comment|/* Gigabit Ethernet Port 0 summary */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBERX
value|41
end_define

begin_comment
comment|/* Gigabit Ethernet Port 0 Rx summary */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBETX
value|42
end_define

begin_comment
comment|/* Gigabit Ethernet Port 0 Tx summary */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBEMISC
value|43
end_define

begin_comment
comment|/* Gigabit Ethernet Port 0 Misc summ. */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1SUM
value|44
end_define

begin_comment
comment|/* Gigabit Ethernet Port 1 summary */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1RX
value|45
end_define

begin_comment
comment|/* Gigabit Ethernet Port 1 Rx summary */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1TX
value|46
end_define

begin_comment
comment|/* Gigabit Ethernet Port 1 Tx summary */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE1MISC
value|47
end_define

begin_comment
comment|/* Gigabit Ethernet Port 1 Misc summ. */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO7_0
value|56
end_define

begin_comment
comment|/* GPIO[7:0] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO15_8
value|57
end_define

begin_comment
comment|/* GPIO[15:8] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO23_16
value|58
end_define

begin_comment
comment|/* GPIO[23:16] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GPIO31_24
value|59
end_define

begin_comment
comment|/* GPIO[31:24] Interrupt */
end_comment

begin_define
define|#
directive|define
name|MV_INT_DB_IN
value|60
end_define

begin_comment
comment|/* Inbound Doorbell Cause reg Summary */
end_comment

begin_define
define|#
directive|define
name|MV_INT_DB_OUT
value|61
end_define

begin_comment
comment|/* Outbound Doorbell Cause reg Summ. */
end_comment

begin_define
define|#
directive|define
name|MV_INT_CRYPT_ERR
value|64
end_define

begin_comment
comment|/* Crypto engine error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_DEV_ERR
value|65
end_define

begin_comment
comment|/* Device bus error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_IDMA_ERR
value|66
end_define

begin_comment
comment|/* DMA error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_CPU_ERR
value|67
end_define

begin_comment
comment|/* CPU error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX0_ERR
value|68
end_define

begin_comment
comment|/* PCI-Express port0 error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_PEX1_ERR
value|69
end_define

begin_comment
comment|/* PCI-Express port1 error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_GBE_ERR
value|70
end_define

begin_comment
comment|/* Gigabit Ethernet error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_USB_ERR
value|72
end_define

begin_comment
comment|/* USB error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_DRAM_ERR
value|73
end_define

begin_comment
comment|/* DRAM ECC error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_XOR_ERR
value|74
end_define

begin_comment
comment|/* XOR engine error */
end_comment

begin_define
define|#
directive|define
name|MV_INT_WD
value|79
end_define

begin_comment
comment|/* WD Timer interrupt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOC_MV_ORION */
end_comment

begin_define
define|#
directive|define
name|BRIDGE_IRQ_CAUSE
value|0x10
end_define

begin_define
define|#
directive|define
name|BRIGDE_IRQ_MASK
value|0x14
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_if

begin_define
define|#
directive|define
name|IRQ_CAUSE_ERROR
value|0x0
end_define

begin_define
define|#
directive|define
name|IRQ_CAUSE
value|0x4
end_define

begin_define
define|#
directive|define
name|IRQ_CAUSE_HI
value|0x8
end_define

begin_define
define|#
directive|define
name|IRQ_MASK_ERROR
value|0xC
end_define

begin_define
define|#
directive|define
name|IRQ_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|IRQ_MASK_HI
value|0x14
end_define

begin_define
define|#
directive|define
name|IRQ_CAUSE_SELECT
value|0x18
end_define

begin_define
define|#
directive|define
name|FIQ_MASK_ERROR
value|0x1C
end_define

begin_define
define|#
directive|define
name|FIQ_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|FIQ_MASK_HI
value|0x24
end_define

begin_define
define|#
directive|define
name|FIQ_CAUSE_SELECT
value|0x28
end_define

begin_define
define|#
directive|define
name|ENDPOINT_IRQ_MASK_ERROR
value|0x2C
end_define

begin_define
define|#
directive|define
name|ENDPOINT_IRQ_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|ENDPOINT_IRQ_MASK_HI
value|0x34
end_define

begin_define
define|#
directive|define
name|ENDPOINT_IRQ_CAUSE_SELECT
value|0x38
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SOC_MV_DISCOVERY */
end_comment

begin_define
define|#
directive|define
name|IRQ_CAUSE
value|0x0
end_define

begin_define
define|#
directive|define
name|IRQ_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|FIQ_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|ENDPOINT_IRQ_MASK
value|0xC
end_define

begin_define
define|#
directive|define
name|IRQ_CAUSE_HI
value|0x10
end_define

begin_define
define|#
directive|define
name|IRQ_MASK_HI
value|0x14
end_define

begin_define
define|#
directive|define
name|FIQ_MASK_HI
value|0x18
end_define

begin_define
define|#
directive|define
name|ENDPOINT_IRQ_MASK_HI
value|0x1C
end_define

begin_define
define|#
directive|define
name|IRQ_CAUSE_ERROR
value|(-1)
end_define

begin_comment
comment|/* Fake defines for unified */
end_comment

begin_define
define|#
directive|define
name|IRQ_MASK_ERROR
value|(-1)
end_define

begin_comment
comment|/* interrupt controller code */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BRIDGE_IRQ_CAUSE
value|0x10
end_define

begin_define
define|#
directive|define
name|IRQ_CPU_SELF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IRQ_TIMER0
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IRQ_TIMER1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IRQ_TIMER_WD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BRIDGE_IRQ_MASK
value|0x14
end_define

begin_define
define|#
directive|define
name|IRQ_CPU_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IRQ_TIMER0_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IRQ_TIMER1_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IRQ_TIMER_WD_MASK
value|0x00000008
end_define

begin_comment
comment|/*  * System reset  */
end_comment

begin_define
define|#
directive|define
name|RSTOUTn_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|WD_RST_OUT_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|SOFT_RST_OUT_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SYSTEM_SOFT_RESET
value|0xc
end_define

begin_define
define|#
directive|define
name|SYS_SOFT_RST
value|0x00000001
end_define

begin_comment
comment|/*  * Power Control  */
end_comment

begin_define
define|#
directive|define
name|CPU_PM_CTRL
value|0x1C
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_NONE
value|0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_KIRKWOOD
argument_list|)
end_if

begin_define
define|#
directive|define
name|CPU_PM_CTRL_GE0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX0_PHY
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_USB0
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SDIO
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_TSU
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_DUNIT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_RUNIT
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_XOR0
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_AUDIO
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA0
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA1
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_XOR1
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_CRYPTO
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_GE1
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_TDM
value|(1<< 19)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_elif

begin_define
define|#
directive|define
name|CPU_PM_CTRL_GE0
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_GE1
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX00
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX01
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX02
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX03
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX10
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX11
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX12
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_PEX13
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA0_PHY
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA0
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA1_PHY
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA1
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_USB0
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_USB1
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_USB2
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_IDMA
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_XOR
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_CRYPTO
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_DEVICE
value|(1<< 23)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Timers  */
end_comment

begin_define
define|#
directive|define
name|CPU_TIMER_CONTROL
value|0x0
end_define

begin_define
define|#
directive|define
name|CPU_TIMER0_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CPU_TIMER0_AUTO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CPU_TIMER1_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CPU_TIMER1_AUTO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CPU_TIMER_WD_EN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CPU_TIMER_WD_AUTO
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CPU_TIMER0_REL
value|0x10
end_define

begin_define
define|#
directive|define
name|CPU_TIMER0
value|0x14
end_define

begin_comment
comment|/*  * GPIO  */
end_comment

begin_define
define|#
directive|define
name|GPIO_DATA_OUT
value|0x00
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_OUT_EN_CTRL
value|0x04
end_define

begin_define
define|#
directive|define
name|GPIO_BLINK_EN
value|0x08
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_IN_POLAR
value|0x0c
end_define

begin_define
define|#
directive|define
name|GPIO_DATA_IN
value|0x10
end_define

begin_define
define|#
directive|define
name|GPIO_INT_CAUSE
value|0x14
end_define

begin_define
define|#
directive|define
name|GPIO_INT_EDGE_MASK
value|0x18
end_define

begin_define
define|#
directive|define
name|GPIO_INT_LEV_MASK
value|0x1c
end_define

begin_define
define|#
directive|define
name|GPIO_HI_DATA_OUT
value|0x40
end_define

begin_define
define|#
directive|define
name|GPIO_HI_DATA_OUT_EN_CTRL
value|0x44
end_define

begin_define
define|#
directive|define
name|GPIO_HI_BLINK_EN
value|0x48
end_define

begin_define
define|#
directive|define
name|GPIO_HI_DATA_IN_POLAR
value|0x4c
end_define

begin_define
define|#
directive|define
name|GPIO_HI_DATA_IN
value|0x50
end_define

begin_define
define|#
directive|define
name|GPIO_HI_INT_CAUSE
value|0x54
end_define

begin_define
define|#
directive|define
name|GPIO_HI_INT_EDGE_MASK
value|0x58
end_define

begin_define
define|#
directive|define
name|GPIO_HI_INT_LEV_MASK
value|0x5c
end_define

begin_define
define|#
directive|define
name|GPIO
parameter_list|(
name|n
parameter_list|)
value|(1<< (n))
end_define

begin_define
define|#
directive|define
name|MV_GPIO_MAX_NPINS
value|64
end_define

begin_define
define|#
directive|define
name|MV_GPIO_BLINK
value|0x1
end_define

begin_define
define|#
directive|define
name|MV_GPIO_POLARITY
value|0x2
end_define

begin_define
define|#
directive|define
name|MV_GPIO_EDGE
value|0x4
end_define

begin_define
define|#
directive|define
name|MV_GPIO_LEVEL
value|0x8
end_define

begin_define
define|#
directive|define
name|IS_GPIO_IRQ
parameter_list|(
name|irq
parameter_list|)
value|((irq)>= NIRQ&& (irq)< NIRQ + MV_GPIO_MAX_NPINS)
end_define

begin_define
define|#
directive|define
name|GPIO2IRQ
parameter_list|(
name|gpio
parameter_list|)
value|((gpio) + NIRQ)
end_define

begin_define
define|#
directive|define
name|IRQ2GPIO
parameter_list|(
name|irq
parameter_list|)
value|((irq) - NIRQ)
end_define

begin_comment
comment|/*  * MPP  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ORION
argument_list|)
end_if

begin_define
define|#
directive|define
name|MPP_CONTROL0
value|0x00
end_define

begin_define
define|#
directive|define
name|MPP_CONTROL1
value|0x04
end_define

begin_define
define|#
directive|define
name|MPP_CONTROL2
value|0x50
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_KIRKWOOD
argument_list|)
operator|||
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_elif

begin_define
define|#
directive|define
name|MPP_CONTROL0
value|0x00
end_define

begin_define
define|#
directive|define
name|MPP_CONTROL1
value|0x04
end_define

begin_define
define|#
directive|define
name|MPP_CONTROL2
value|0x08
end_define

begin_define
define|#
directive|define
name|MPP_CONTROL3
value|0x0C
end_define

begin_define
define|#
directive|define
name|MPP_CONTROL4
value|0x10
end_define

begin_define
define|#
directive|define
name|MPP_CONTROL5
value|0x14
end_define

begin_define
define|#
directive|define
name|MPP_CONTROL6
value|0x18
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|SOC_MV_XX not defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ORION
argument_list|)
end_if

begin_define
define|#
directive|define
name|SAMPLE_AT_RESET
value|0x10
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_KIRKWOOD
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SAMPLE_AT_RESET
value|0x30
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SAMPLE_AT_RESET_LO
value|0x30
end_define

begin_define
define|#
directive|define
name|SAMPLE_AT_RESET_HI
value|0x34
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|SOC_MV_XX not defined
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Clocks  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_ORION
argument_list|)
end_if

begin_define
define|#
directive|define
name|TCLK_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|TCLK_SHIFT
value|0x08
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TCLK_MASK
value|0x00000180
end_define

begin_define
define|#
directive|define
name|TCLK_SHIFT
value|0x07
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TCLK_100MHZ
value|100000000
end_define

begin_define
define|#
directive|define
name|TCLK_125MHZ
value|125000000
end_define

begin_define
define|#
directive|define
name|TCLK_133MHZ
value|133333333
end_define

begin_define
define|#
directive|define
name|TCLK_150MHZ
value|150000000
end_define

begin_define
define|#
directive|define
name|TCLK_166MHZ
value|166666667
end_define

begin_define
define|#
directive|define
name|TCLK_200MHZ
value|200000000
end_define

begin_comment
comment|/*  * Chip ID  */
end_comment

begin_define
define|#
directive|define
name|MV_DEV_88F5181
value|0x5181
end_define

begin_define
define|#
directive|define
name|MV_DEV_88F5182
value|0x5182
end_define

begin_define
define|#
directive|define
name|MV_DEV_88F5281
value|0x5281
end_define

begin_define
define|#
directive|define
name|MV_DEV_88F6281
value|0x6281
end_define

begin_define
define|#
directive|define
name|MV_DEV_MV78100
value|0x6381
end_define

begin_comment
comment|/*  * Decode windows definitions and macros  */
end_comment

begin_define
define|#
directive|define
name|MV_WIN_CPU_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + (((n)< 8) ? 0x000 : 0x880))
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + (((n)< 8) ? 0x004 : 0x884))
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_REMAP_LO
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + (((n)< 8) ? 0x008 : 0x888))
end_define

begin_define
define|#
directive|define
name|MV_WIN_CPU_REMAP_HI
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + (((n)< 8) ? 0x00C : 0x88C))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOC_MV_DISCOVERY
argument_list|)
end_if

begin_define
define|#
directive|define
name|MV_WIN_CPU_MAX
value|14
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MV_WIN_CPU_MAX
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MV_WIN_DDR_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x0)
end_define

begin_define
define|#
directive|define
name|MV_WIN_DDR_SIZE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x4)
end_define

begin_define
define|#
directive|define
name|MV_WIN_DDR_MAX
value|4
end_define

begin_define
define|#
directive|define
name|MV_WIN_USB_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x0)
end_define

begin_define
define|#
directive|define
name|MV_WIN_USB_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (n) + 0x4)
end_define

begin_define
define|#
directive|define
name|MV_WIN_USB_MAX
value|4
end_define

begin_define
define|#
directive|define
name|MV_WIN_ETH_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x200)
end_define

begin_define
define|#
directive|define
name|MV_WIN_ETH_SIZE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0x204)
end_define

begin_define
define|#
directive|define
name|MV_WIN_ETH_REMAP
parameter_list|(
name|n
parameter_list|)
value|(0x4 * (n) + 0x280)
end_define

begin_define
define|#
directive|define
name|MV_WIN_ETH_MAX
value|6
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0xa00)
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_SIZE
parameter_list|(
name|n
parameter_list|)
value|(0x8 * (n) + 0xa04)
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_REMAP
parameter_list|(
name|n
parameter_list|)
value|(0x4 * (n) + 0xa60)
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_CAP
parameter_list|(
name|n
parameter_list|)
value|(0x4 * (n) + 0xa70)
end_define

begin_define
define|#
directive|define
name|MV_WIN_IDMA_MAX
value|8
end_define

begin_define
define|#
directive|define
name|MV_IDMA_CHAN_MAX
value|4
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_CTRL
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (((n)< 5) ? (n) : \ 					    (n) + 1) + 0x1820)
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (((n)< 5) ? (n) : \ 					    (n) + 1) + 0x1824)
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_REMAP
parameter_list|(
name|n
parameter_list|)
value|(0x10 * (((n)< 5) ? (n) : \ 					    (n) + 1) + 0x182C)
end_define

begin_define
define|#
directive|define
name|MV_WIN_PCIE_MAX
value|6
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BAR
parameter_list|(
name|n
parameter_list|)
value|(0x04 * (n) + 0x1804)
end_define

begin_define
define|#
directive|define
name|MV_PCIE_BAR_MAX
value|3
end_define

begin_define
define|#
directive|define
name|WIN_REG_IDX_RD
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline uint32_t						\ 	pre ## _ ## reg ## _read(int i)						\ 	{									\ 		return (bus_space_read_4(obio_tag, base, off(i)));		\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_IDX_RD
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline uint32_t						\ 	pre ## _ ## reg ## _read(uint32_t base, int i)				\ 	{									\ 		return (bus_space_read_4(obio_tag, base, off(i)));		\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_IDX_WR
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(int i, uint32_t val)				\ 	{									\ 		bus_space_write_4(obio_tag, base, off(i), val);			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_IDX_WR
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(uint32_t base, int i, uint32_t val)		\ 	{									\ 		bus_space_write_4(obio_tag, base, off(i), val);			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_RD
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline uint32_t						\ 	pre ## _ ## reg ## _read(void)						\ 	{									\ 		return (bus_space_read_4(obio_tag, base, off));			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_RD
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline uint32_t						\ 	pre ## _ ## reg ## _read(uint32_t base)					\ 	{									\ 		return (bus_space_read_4(obio_tag, base, off));			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_WR
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|,
name|base
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(uint32_t val)					\ 	{									\ 		bus_space_write_4(obio_tag, base, off, val);			\ 	}
end_define

begin_define
define|#
directive|define
name|WIN_REG_BASE_WR
parameter_list|(
name|pre
parameter_list|,
name|reg
parameter_list|,
name|off
parameter_list|)
define|\
value|static __inline void							\ 	pre ## _ ## reg ## _write(uint32_t base, uint32_t val)			\ 	{									\ 		bus_space_write_4(obio_tag, base, off, val);			\ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MVREG_H_ */
end_comment

end_unit

