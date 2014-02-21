begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: adm5120reg.h,v 1.1 2007/03/20 08:52:03 dyoung Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 Ruslan Ermilov and Vsevolod Lobko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ADM5120REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ADM5120REG_H_
end_define

begin_comment
comment|/* Helpers from NetBSD */
end_comment

begin_comment
comment|/* __BIT(n): nth bit, where __BIT(0) == 0x1. */
end_comment

begin_define
define|#
directive|define
name|__BIT
parameter_list|(
name|__n
parameter_list|)
define|\
value|(((__n)>= NBBY * sizeof(uintmax_t)) ? 0 : ((uintmax_t)1<< (__n)))
end_define

begin_comment
comment|/* __BITS(m, n): bits m through n, m< n. */
end_comment

begin_define
define|#
directive|define
name|__BITS
parameter_list|(
name|__m
parameter_list|,
name|__n
parameter_list|)
define|\
value|((__BIT(MAX((__m), (__n)) + 1) - 1) ^ (__BIT(MIN((__m), (__n))) - 1))
end_define

begin_comment
comment|/* Last byte of physical address space. */
end_comment

begin_define
define|#
directive|define
name|ADM5120_TOP
value|0x1fffffff
end_define

begin_define
define|#
directive|define
name|ADM5120_BOTTOM
value|0x0
end_define

begin_comment
comment|/* Flash addresses */
end_comment

begin_define
define|#
directive|define
name|ADM5120_BASE_SRAM0
value|0x1fc00000
end_define

begin_comment
comment|/* UARTs */
end_comment

begin_define
define|#
directive|define
name|ADM5120_BASE_UART1
value|0x12800000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_UART0
value|0x12600000
end_define

begin_comment
comment|/* ICU */
end_comment

begin_define
define|#
directive|define
name|ADM5120_BASE_ICU
value|0x12200000
end_define

begin_define
define|#
directive|define
name|ICU_STATUS_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|ICU_RAW_STATUS_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|ICU_ENABLE_REG
value|0x08
end_define

begin_define
define|#
directive|define
name|ICU_DISABLE_REG
value|0x0c
end_define

begin_define
define|#
directive|define
name|ICU_SOFT_REG
value|0x10
end_define

begin_define
define|#
directive|define
name|ICU_MODE_REG
value|0x14
end_define

begin_define
define|#
directive|define
name|ICU_FIQ_STATUS_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|ICU_TESTSRC_REG
value|0x1c
end_define

begin_define
define|#
directive|define
name|ICU_SRCSEL_REG
value|0x20
end_define

begin_define
define|#
directive|define
name|ICU_LEVEL_REG
value|0x24
end_define

begin_define
define|#
directive|define
name|ICU_INT_MASK
value|0x3ff
end_define

begin_comment
comment|/* Switch */
end_comment

begin_define
define|#
directive|define
name|ADM5120_BASE_SWITCH
value|0x12000000
end_define

begin_define
define|#
directive|define
name|SW_CODE_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|CLKS_MASK
value|0x00300000
end_define

begin_define
define|#
directive|define
name|CLKS_175MHZ
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CLKS_200MHZ
value|0x00100000
end_define

begin_define
define|#
directive|define
name|SW_SFTRES_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|SW_MEMCONT_REG
value|0x1c
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_4MBYTES
value|0x0001
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_8MBYTES
value|0x0002
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_16MBYTES
value|0x0003
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_64MBYTES
value|0x0004
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_128MBYTES
value|0x0005
end_define

begin_define
define|#
directive|define
name|SDRAM_SIZE_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|SRAM0_SIZE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SRAM1_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SRAM_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|SRAM_SSIZE
value|0x40000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_PCI_CONFDATA
value|0x115ffff8
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_PCI_CONFADDR
value|0x115ffff0
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_PCI_IO
value|0x11500000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_PCI_MEM
value|0x11400000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_USB
value|0x11200000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_MPMC
value|0x11000000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_EXTIO1
value|0x10e00000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_EXTIO0
value|0x10c00000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_RSVD0
value|0x10800000
end_define

begin_define
define|#
directive|define
name|ADM5120_BASE_SRAM1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|_REG_READ
parameter_list|(
name|b
parameter_list|,
name|o
parameter_list|)
value|*((volatile uint32_t *)MIPS_PHYS_TO_KSEG1((b) + (o)))
end_define

begin_define
define|#
directive|define
name|SW_READ
parameter_list|(
name|o
parameter_list|)
value|_REG_READ(ADM5120_BASE_SWITCH, o)
end_define

begin_define
define|#
directive|define
name|_REG_WRITE
parameter_list|(
name|b
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
value|(_REG_READ(b, o)) = (v)
end_define

begin_define
define|#
directive|define
name|SW_WRITE
parameter_list|(
name|o
parameter_list|,
name|v
parameter_list|)
value|_REG_WRITE(ADM5120_BASE_SWITCH,o, v)
end_define

begin_comment
comment|/* USB */
end_comment

begin_comment
comment|/* Watchdog Timers: base address is switch controller */
end_comment

begin_define
define|#
directive|define
name|ADM5120_WDOG0
value|0x00c0
end_define

begin_define
define|#
directive|define
name|ADM5120_WDOG1
value|0x00c4
end_define

begin_define
define|#
directive|define
name|ADM5120_WDOG0_WTTR
value|__BIT(31)
end_define

begin_comment
comment|/* 0: do not reset, 						 * 1: reset on wdog expiration 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_WDOG1_WDE
value|__BIT(31)
end_define

begin_comment
comment|/* 0: deactivate, 						 * 1: drop all CPU-bound 						 * packets, disable flow 						 * control on all ports. 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_WDOG_WTS_MASK
value|__BITS(30, 16)
end_define

begin_comment
comment|/* Watchdog Timer Set: 						 * timer expires when it 						 * reaches WTS.  Units of 						 * 10ms. 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_WDOG_RSVD
value|__BIT(15)
end_define

begin_define
define|#
directive|define
name|ADM5120_WDOG_WT_MASK
value|__BITS(14, 0)
end_define

begin_comment
comment|/* Watchdog Timer: 						 * counts up, write to clear. 						 */
end_comment

begin_comment
comment|/* GPIO: base address is switch controller */
end_comment

begin_define
define|#
directive|define
name|ADM5120_GPIO0
value|0x00b8
end_define

begin_define
define|#
directive|define
name|ADM5120_GPIO0_OV
value|__BITS(31, 24)
end_define

begin_comment
comment|/* rw: output value */
end_comment

begin_define
define|#
directive|define
name|ADM5120_GPIO0_OE
value|__BITS(23, 16)
end_define

begin_comment
comment|/* rw: output enable, 						 * bit[n] = 0 -> input 						 * bit[n] = 1 -> output 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_GPIO0_IV
value|__BITS(15, 8)
end_define

begin_comment
comment|/* ro: input value */
end_comment

begin_define
define|#
directive|define
name|ADM5120_GPIO0_RSVD
value|__BITS(7, 0)
end_define

begin_comment
comment|/* rw: reserved */
end_comment

begin_define
define|#
directive|define
name|ADM5120_GPIO2
value|0x00bc
end_define

begin_define
define|#
directive|define
name|ADM5120_GPIO2_EW
value|__BIT(6)
end_define

begin_comment
comment|/* 1: enable wait state pin, 						 * pin GPIO[0], for GPIO[1] 						 * or GPIO[3] Chip Select: 						 * memory controller waits for 						 * WAIT# inactive (high). 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_GPIO2_CSX1
value|__BIT(5)
end_define

begin_comment
comment|/* 1: GPIO[3:4] act as 						 * Chip Select for 						 * External I/O 1 (CSX1) 						 * and External Interrupt 1 						 * (INTX1), respectively. 						 * 0: CSX1/INTX1 disabled 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_GPIO2_CSX0
value|__BIT(4)
end_define

begin_comment
comment|/* 1: GPIO[1:2] act as 						 * Chip Select for 						 * External I/O 0 (CSX0) 						 * and External Interrupt 0 						 * (INTX0), respectively. 						 * 0: CSX0/INTX0 disabled 						 */
end_comment

begin_comment
comment|/* MultiPort Memory Controller (MPMC) */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_CONTROL
value|0x000
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_CONTROL_DWB
value|__BIT(3)
end_define

begin_comment
comment|/* write 1 to 							 * drain write 							 * buffers.  write 0 							 * for normal buffer 							 * operation. 							 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_CONTROL_LPM
value|__BIT(2)
end_define

begin_comment
comment|/* 1: activate low-power 							 * mode.  SDRAM is 							 * still refreshed. 							 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_CONTROL_AM
value|__BIT(1)
end_define

begin_comment
comment|/* 1: address mirror: 							 * static memory 							 * chip select 0 							 * is mapped to chip 							 * select 1. 							 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_CONTROL_ME
value|__BIT(0)
end_define

begin_comment
comment|/* 0: disable MPMC. 							 * DRAM is not 							 * refreshed. 							 * 1: enable MPMC. 							 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_STATUS
value|0x004
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_STATUS_SRA
value|__BIT(2)
end_define

begin_comment
comment|/* read-only 							 * MPMC operating mode 							 * indication, 							 * 1: self-refresh 							 * acknowledge 							 * 0: normal mode 							 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_STATUS_WBS
value|__BIT(1)
end_define

begin_comment
comment|/* read-only 							 * write-buffer status, 							 * 0: buffers empty 							 * 1: contain data 							 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_STATUS_BU
value|__BIT(0)
end_define

begin_comment
comment|/* read-only MPMC 							 * "busy" indication, 							 * 0: MPMC idle 							 * 1: MPMC is performing 							 * memory transactions 							 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SEW
value|0x080
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SEW_RSVD
value|__BITS(31, 10)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SEW_EWTO
value|__BITS(9, 0)
end_define

begin_comment
comment|/* timeout access after 						 * 16 * (n + 1) clock cycles 						 * (XXX which clock?) 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC
parameter_list|(
name|__i
parameter_list|)
value|(0x200 + 0x020 * (__i))
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_RSVD0
value|__BITS(31, 21)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_WP
value|__BIT(20)
end_define

begin_comment
comment|/* 1: write protect */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_BE
value|__BIT(20)
end_define

begin_comment
comment|/* 1: enable write buffer */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_RSVD1
value|__BITS(18, 9)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_EW
value|__BIT(8)
end_define

begin_comment
comment|/* 1: enable extended wait; 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_BLS
value|__BIT(7)
end_define

begin_comment
comment|/* 0: byte line state pins 						 * are active high on read, 						 * active low on write. 						 * 						 * 1: byte line state pins 						 * are active low on read and 						 * on write. 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_CCP
value|__BIT(6)
end_define

begin_comment
comment|/* 0: chip select is active low, 						 * 1: active high 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_RSVD2
value|__BITS(5, 4)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_PM
value|__BIT(3)
end_define

begin_comment
comment|/* 0: page mode disabled, 						 * 1: enable asynchronous 						 * page mode four 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_RSVD3
value|__BIT(2)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_MW_MASK
value|__BITS(1, 0)
end_define

begin_comment
comment|/* memory width, bits */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_MW_8B
value|__SHIFTIN(0, ADM5120_MPMC_SC_MW_MASK)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_MW_16B
value|__SHIFTIN(1, ADM5120_MPMC_SC_MW_MASK)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_MW_32B
value|__SHIFTIN(2, ADM5120_MPMC_SC_MW_MASK)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SC_MW_RSVD
value|__SHIFTIN(3, ADM5120_MPMC_SC_MW_MASK)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWW
parameter_list|(
name|__i
parameter_list|)
value|(0x204 + 0x020 * (__i))
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWW_RSVD
value|__BITS(31, 4)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWW_WWE
value|__BITS(3, 0)
end_define

begin_comment
comment|/* delay (n + 1) * HCLK cycles 						 * after asserting chip select 						 * (CS) before asserting write 						 * enable (WE) 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWO
parameter_list|(
name|__i
parameter_list|)
value|(0x208 + 0x020 * (__i))
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWO_RSVD
value|__BITS(31, 4)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWO_WOE
value|__BITS(3, 0)
end_define

begin_comment
comment|/* delay n * HCLK cycles 						 * after asserting chip select 						 * before asserting output 						 * enable (OE) 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWR
parameter_list|(
name|__i
parameter_list|)
value|(0x20c + 0x020 * (__i))
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWR_RSVD
value|__BITS(31, 5)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWR_NMRW
value|__BITS(4, 0)
end_define

begin_comment
comment|/* read wait states for 						 * either first page-mode 						 * access or for non-page mode 						 * read, (n + 1) * HCLK cycles 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWP
parameter_list|(
name|__i
parameter_list|)
value|(0x210 + 0x020 * (__i))
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWP_RSVD
value|__BITS(31, 5)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWP_WPS
value|__BITS(4, 0)
end_define

begin_comment
comment|/* read wait states for 						 * second and subsequent 						 * page-mode read, 						 * (n + 1) * HCLK cycles 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWWR
parameter_list|(
name|__i
parameter_list|)
value|(0x214 + 0x020 * (__i))
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWWR_RSVD
value|__BITS(31, 5)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWWR_WWS
value|__BITS(4, 0)
end_define

begin_comment
comment|/* write wait states after 						 * the first read (??), 						 * (n + 2) * HCLK cycles 						 */
end_comment

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWT
parameter_list|(
name|__i
parameter_list|)
value|(0x218 + 0x020 * (__i))
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWT_RSVD
value|__BITS(31, 4)
end_define

begin_define
define|#
directive|define
name|ADM5120_MPMC_SWT_WAITTURN
value|__BITS(3, 0)
end_define

begin_comment
comment|/* bus turnaround time, 							 * (n + 1) * HCLK cycles 							 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ADM5120REG_H_ */
end_comment

end_unit

