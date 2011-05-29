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
name|MV_INT_CESA
value|22
end_define

begin_comment
comment|/* Security engine completion int. */
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
name|MV_INT_CESA
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

begin_define
define|#
directive|define
name|CPU_PM_CTRL_ALL
value|~0x0
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
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_TDM
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_XOR
value|(CPU_PM_CTRL_XOR0 | CPU_PM_CTRL_XOR1)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_USB
parameter_list|(
name|u
parameter_list|)
value|(CPU_PM_CTRL_USB0)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA
value|(CPU_PM_CTRL_SATA0 | CPU_PM_CTRL_SATA1)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_GE
parameter_list|(
name|u
parameter_list|)
value|(CPU_PM_CTRL_GE1 * (u) | CPU_PM_CTRL_GE0 * \ 				(1 - (u)))
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_IDMA
value|(CPU_PM_CTRL_NONE)
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

begin_define
define|#
directive|define
name|CPU_PM_CTRL_USB
parameter_list|(
name|u
parameter_list|)
value|(1<< (17 + (u)))
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA
value|(CPU_PM_CTRL_SATA0 | CPU_PM_CTRL_SATA1)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_GE
parameter_list|(
name|u
parameter_list|)
value|(CPU_PM_CTRL_GE1 * (u) | CPU_PM_CTRL_GE0 * \ 				(1 - (u)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPU_PM_CTRL_CRYPTO
value|(CPU_PM_CTRL_NONE)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_IDMA
value|(CPU_PM_CTRL_NONE)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_XOR
value|(CPU_PM_CTRL_NONE)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_SATA
value|(CPU_PM_CTRL_NONE)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_USB
parameter_list|(
name|u
parameter_list|)
value|(CPU_PM_CTRL_NONE)
end_define

begin_define
define|#
directive|define
name|CPU_PM_CTRL_GE
parameter_list|(
name|u
parameter_list|)
value|(CPU_PM_CTRL_NONE)
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
comment|/*  * SATA  */
end_comment

begin_define
define|#
directive|define
name|SATA_CHAN_NUM
value|2
end_define

begin_define
define|#
directive|define
name|EDMA_REGISTERS_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|EDMA_REGISTERS_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_BASE
parameter_list|(
name|ch
parameter_list|)
value|(EDMA_REGISTERS_OFFSET + \     ((ch) * EDMA_REGISTERS_SIZE))
end_define

begin_comment
comment|/* SATAHC registers */
end_comment

begin_define
define|#
directive|define
name|SATA_CR
value|0x000
end_define

begin_comment
comment|/* Configuration Reg. */
end_comment

begin_define
define|#
directive|define
name|SATA_CR_NODMABS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SATA_CR_NOEDMABS
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|SATA_CR_NOPRDPBS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|SATA_CR_COALDIS
parameter_list|(
name|ch
parameter_list|)
value|(1<< (24 + ch))
end_define

begin_define
define|#
directive|define
name|SATA_ICR
value|0x014
end_define

begin_comment
comment|/* Interrupt Cause Reg. */
end_comment

begin_define
define|#
directive|define
name|SATA_ICR_DMADONE
parameter_list|(
name|ch
parameter_list|)
value|(1<< (ch))
end_define

begin_define
define|#
directive|define
name|SATA_ICR_COAL
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SATA_ICR_DEV
parameter_list|(
name|ch
parameter_list|)
value|(1<< (8 + ch))
end_define

begin_define
define|#
directive|define
name|SATA_MICR
value|0x020
end_define

begin_comment
comment|/* Main Interrupt Cause Reg. */
end_comment

begin_define
define|#
directive|define
name|SATA_MICR_ERR
parameter_list|(
name|ch
parameter_list|)
value|(1<< (2 * ch))
end_define

begin_define
define|#
directive|define
name|SATA_MICR_DONE
parameter_list|(
name|ch
parameter_list|)
value|(1<< ((2 * ch) + 1))
end_define

begin_define
define|#
directive|define
name|SATA_MICR_DMADONE
parameter_list|(
name|ch
parameter_list|)
value|(1<< (4 + ch))
end_define

begin_define
define|#
directive|define
name|SATA_MICR_COAL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SATA_MIMR
value|0x024
end_define

begin_comment
comment|/*  Main Interrupt Mask Reg. */
end_comment

begin_comment
comment|/* Shadow registers */
end_comment

begin_define
define|#
directive|define
name|SATA_SHADOWR_BASE
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x100)
end_define

begin_define
define|#
directive|define
name|SATA_SHADOWR_CONTROL
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x120)
end_define

begin_comment
comment|/* SATA registers */
end_comment

begin_define
define|#
directive|define
name|SATA_SATA_SSTATUS
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x300)
end_define

begin_define
define|#
directive|define
name|SATA_SATA_SERROR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x304)
end_define

begin_define
define|#
directive|define
name|SATA_SATA_SCONTROL
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x308)
end_define

begin_define
define|#
directive|define
name|SATA_SATA_FISICR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x364)
end_define

begin_comment
comment|/* EDMA registers */
end_comment

begin_define
define|#
directive|define
name|SATA_EDMA_CFG
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x000)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_CFG_QL128
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_CFG_HQCACHE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_IECR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x008)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_IEMR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x00C)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_REQBAHR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x010)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_REQIPR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x014)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_REQOPR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x018)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_RESBAHR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x01C)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_RESIPR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x020)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_RESOPR
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x024)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_CMD
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x028)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_CMD_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_CMD_DISABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_CMD_RESET
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_STATUS
parameter_list|(
name|ch
parameter_list|)
value|(SATA_EDMA_BASE(ch) + 0x030)
end_define

begin_define
define|#
directive|define
name|SATA_EDMA_STATUS_IDLE
value|(1<< 7)
end_define

begin_comment
comment|/* Offset to extract input slot from REQIPR register */
end_comment

begin_define
define|#
directive|define
name|SATA_EDMA_REQIS_OFS
value|5
end_define

begin_comment
comment|/* Offset to extract input slot from RESOPR register */
end_comment

begin_define
define|#
directive|define
name|SATA_EDMA_RESOS_OFS
value|3
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
name|MV_GPIO_IN_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|MV_GPIO_IN_POL_LOW
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MV_GPIO_IN_IRQ_EDGE
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|MV_GPIO_IN_IRQ_LEVEL
value|(4<< 16)
end_define

begin_define
define|#
directive|define
name|MV_GPIO_OUT_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|MV_GPIO_OUT_BLINK
value|0x1
end_define

begin_define
define|#
directive|define
name|MV_GPIO_OUT_OPEN_DRAIN
value|0x2
end_define

begin_define
define|#
directive|define
name|MV_GPIO_OUT_OPEN_SRC
value|0x4
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
name|MV_DEV_MV78100_Z0
value|0x6381
end_define

begin_define
define|#
directive|define
name|MV_DEV_MV78100
value|0x7810
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MVREG_H_ */
end_comment

end_unit

