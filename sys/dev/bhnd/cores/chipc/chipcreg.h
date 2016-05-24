begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  * All rights reserved.  *  * This file is derived from the sbchipc.h header distributed with  * Broadcom's initial brcm80211 Linux driver release, as  * contributed to the Linux staging repository.  *   * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_CHIPC_CHIPCREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_CHIPC_CHIPCREG_H_
end_define

begin_define
define|#
directive|define
name|CHIPC_CHIPID_SIZE
value|0x100
end_define

begin_comment
comment|/**< size of the register block 						     containing the chip 						     identification registers 						     required during bus 						     enumeration */
end_comment

begin_comment
comment|/** Evaluates to true if the given ChipCommon core revision provides  *  the core count via the chip identification register. */
end_comment

begin_define
define|#
directive|define
name|CHIPC_NCORES_MIN_HWREV
parameter_list|(
name|hwrev
parameter_list|)
value|((hwrev) == 4 || (hwrev)>= 6)
end_define

begin_define
define|#
directive|define
name|CHIPC_GET_FLAG
parameter_list|(
name|_value
parameter_list|,
name|_flag
parameter_list|)
value|(((_value)& _flag) != 0)
end_define

begin_define
define|#
directive|define
name|CHIPC_GET_BITS
parameter_list|(
name|_value
parameter_list|,
name|_field
parameter_list|)
define|\
value|((_value& _field ## _MASK)>> _field ## _SHIFT)
end_define

begin_define
define|#
directive|define
name|CHIPC_ID
value|0x00
end_define

begin_define
define|#
directive|define
name|CHIPC_CAPABILITIES
value|0x04
end_define

begin_define
define|#
directive|define
name|CHIPC_CORECTRL
value|0x08
end_define

begin_comment
comment|/* rev>= 1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_BIST
value|0x0C
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPST
value|0x10
end_define

begin_comment
comment|/**< otp status */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPCTRL
value|0x14
end_define

begin_comment
comment|/**< otp control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPPROG
value|0x18
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPLAYOUT
value|0x1C
end_define

begin_comment
comment|/**< otp layout (rev>= 23) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_INTST
value|0x20
end_define

begin_comment
comment|/**< interrupt status */
end_comment

begin_define
define|#
directive|define
name|CHIPC_INTM
value|0x24
end_define

begin_comment
comment|/**< interrupt mask */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CHIPCTRL
value|0x28
end_define

begin_comment
comment|/**< chip control (rev>= 11) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CHIPST
value|0x2C
end_define

begin_comment
comment|/**< chip status (rev>= 11) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JTAGCMD
value|0x30
end_define

begin_define
define|#
directive|define
name|CHIPC_JTAGIR
value|0x34
end_define

begin_define
define|#
directive|define
name|CHIPC_JTAGDR
value|0x38
end_define

begin_define
define|#
directive|define
name|CHIPC_JTAGCTRL
value|0x3c
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASHCTRL
value|0x40
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASHADDR
value|0x44
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASHDATA
value|0x48
end_define

begin_comment
comment|/* siba backplane configuration broadcast (siba-only) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SBBCAST_ADDR
value|0x50
end_define

begin_define
define|#
directive|define
name|CHIPC_SBBCAST_DATA
value|0x54
end_define

begin_define
define|#
directive|define
name|CHIPC_GPIOPU
value|0x58
end_define

begin_comment
comment|/**< pull-up mask (rev>= 20) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIOPD
value|0x5C
end_define

begin_comment
comment|/**< pull down mask (rev>= 20) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIOIN
value|0x60
end_define

begin_define
define|#
directive|define
name|CHIPC_GPIOOUT
value|0x64
end_define

begin_define
define|#
directive|define
name|CHIPC_GPIOOUTEN
value|0x68
end_define

begin_define
define|#
directive|define
name|CHIPC_GPIOCTRL
value|0x6C
end_define

begin_define
define|#
directive|define
name|CHIPC_GPIOPOL
value|0x70
end_define

begin_define
define|#
directive|define
name|CHIPC_GPIOINTM
value|0x74
end_define

begin_comment
comment|/**< gpio interrupt mask */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIOEVENT
value|0x78
end_define

begin_comment
comment|/**< gpio event (rev>= 11) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIOEVENT_INTM
value|0x7C
end_define

begin_comment
comment|/**< gpio event interrupt mask (rev>= 11) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_WATCHDOG
value|0x80
end_define

begin_comment
comment|/**< watchdog timer */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIOEVENT_INTPOLARITY
value|0x84
end_define

begin_comment
comment|/**< gpio even interrupt polarity (rev>= 11) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIOTIMERVAL
value|0x88
end_define

begin_comment
comment|/**< gpio-based LED duty cycle (rev>= 16) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIOTIMEROUTMASK
value|0x8C
end_define

begin_comment
comment|/* clock control block */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLKC_N
value|0x90
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKC_SB
value|0x94
end_define

begin_comment
comment|/* m0 (backplane) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLKC_PCI
value|0x98
end_define

begin_comment
comment|/* m1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLKC_M2
value|0x9C
end_define

begin_comment
comment|/* mii/uart/mipsref */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLKC_M3
value|0xA0
end_define

begin_comment
comment|/* cpu */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLKDIV
value|0xA4
end_define

begin_comment
comment|/* rev>= 3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIODEBUGSEL
value|0xA8
end_define

begin_comment
comment|/* rev>= 28 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAPABILITIES_EXT
value|0xAC
end_define

begin_comment
comment|/* pll delay (registers rev>= 4) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PLL_ON_DELAY
value|0xB0
end_define

begin_define
define|#
directive|define
name|CHIPC_PLL_FREFSEL_DELAY
value|0xB4
end_define

begin_define
define|#
directive|define
name|CHIPC_PLL_SLOWCLK_CTL
value|0xB8
end_define

begin_comment
comment|/* revs 6-9 */
end_comment

begin_comment
comment|/* "instaclock" registers */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYS_CLK_CTL
value|0xC0
end_define

begin_comment
comment|/* rev>= 10 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYS_CLKSTATESTRETCH
value|0xC4
end_define

begin_comment
comment|/* rev>= 10 */
end_comment

begin_comment
comment|/* indirect backplane access (rev>= 10) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_BP_ADDRLOW
value|0xD0
end_define

begin_define
define|#
directive|define
name|CHIPC_BP_ADDRHIGH
value|0xD4
end_define

begin_define
define|#
directive|define
name|CHIPC_BP_DATA
value|0xD8
end_define

begin_define
define|#
directive|define
name|CHIPC_BP_INDACCESS
value|0xE0
end_define

begin_comment
comment|/* SPI/I2C (rev>= 37) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GSIO_CTRL
value|0xE4
end_define

begin_define
define|#
directive|define
name|CHIPC_GSIO_ADDR
value|0xE8
end_define

begin_define
define|#
directive|define
name|CHIPC_GSIO_DATA
value|0xEC
end_define

begin_comment
comment|/* More clock dividers (corerev>= 32) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLKDIV2
value|0xF0
end_define

begin_define
define|#
directive|define
name|CHIPC_EROMPTR
value|0xFC
end_define

begin_comment
comment|/**< 32-bit EROM base address 						  *  on BCMA devices */
end_comment

begin_comment
comment|/* ExtBus control registers (rev>= 3) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PCMCIA_CFG
value|0x100
end_define

begin_define
define|#
directive|define
name|CHIPC_PCMCIA_MEMWAIT
value|0x104
end_define

begin_define
define|#
directive|define
name|CHIPC_PCMCIA_ATTRWAIT
value|0x108
end_define

begin_define
define|#
directive|define
name|CHIPC_PCMCIA_IOWAIT
value|0x10C
end_define

begin_define
define|#
directive|define
name|CHIPC_IDE_CFG
value|0x110
end_define

begin_define
define|#
directive|define
name|CHIPC_IDE_MEMWAIT
value|0x114
end_define

begin_define
define|#
directive|define
name|CHIPC_IDE_ATTRWAIT
value|0x118
end_define

begin_define
define|#
directive|define
name|CHIPC_IDE_IOWAIT
value|0x11C
end_define

begin_define
define|#
directive|define
name|CHIPC_PROG_CFG
value|0x120
end_define

begin_define
define|#
directive|define
name|CHIPC_PROG_WAITCOUNT
value|0x124
end_define

begin_define
define|#
directive|define
name|CHIPC_FLASH_CFG
value|0x128
end_define

begin_define
define|#
directive|define
name|CHIPC_FLASH_WAITCOUNT
value|0x12C
end_define

begin_define
define|#
directive|define
name|CHIPC_SECI_CFG
value|0x130
end_define

begin_define
define|#
directive|define
name|CHIPC_SECI_ST
value|0x134
end_define

begin_define
define|#
directive|define
name|CHIPC_SECI_STM
value|0x138
end_define

begin_define
define|#
directive|define
name|CHIPC_SECI_RXNBC
value|0x13C
end_define

begin_comment
comment|/* Enhanced Coexistence Interface (ECI) registers (rev 21-34) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ECI_OUTPUT
value|0x140
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_CTRL
value|0x144
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INPUTLO
value|0x148
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INPUTMI
value|0x14C
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INPUTHI
value|0x150
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INPUTINTPOLARITYLO
value|0x154
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INPUTINTPOLARITYMI
value|0x158
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INPUTINTPOLARITYHI
value|0x15C
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INTMASKLO
value|0x160
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INTMASKMI
value|0x164
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_INTMASKHI
value|0x168
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_EVENTLO
value|0x16C
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_EVENTMI
value|0x170
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_EVENTHI
value|0x174
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_EVENTMASKLO
value|0x178
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_EVENTMASKMI
value|0x17C
end_define

begin_define
define|#
directive|define
name|CHIPC_ECI_EVENTMASKHI
value|0x180
end_define

begin_define
define|#
directive|define
name|CHIPC_FLASHSTRCFG
value|0x18C
end_define

begin_comment
comment|/**< BCM4706 NAND flash config */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SPROM_CTRL
value|0x190
end_define

begin_comment
comment|/**< SPROM interface (rev>= 32) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SPROM_ADDR
value|0x194
end_define

begin_define
define|#
directive|define
name|CHIPC_SPROM_DATA
value|0x198
end_define

begin_comment
comment|/* Clock control and hardware workarounds (corerev>= 20) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLK_CTL_ST
value|0x1E0
end_define

begin_define
define|#
directive|define
name|CHIPC_SPROM_HWWAR
value|0x19
end_define

begin_define
define|#
directive|define
name|CHIPC_UART0
value|0x300
end_define

begin_define
define|#
directive|define
name|CHIPC_UART1
value|0x400
end_define

begin_comment
comment|/* PMU registers (rev>= 20) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU_BASE
value|0x600
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CTRL
value|0x600
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CAP
value|0x604
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_ST
value|0x608
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_STATE
value|0x60c
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_PENDING
value|0x610
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_TIMER
value|0x614
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_MIN_RES_MASK
value|0x618
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_MAX_RES_MASK
value|0x61c
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_TABLE_SEL
value|0x620
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_DEP_MASK
value|0x624
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_UPDN_TIMER
value|0x628
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_TIMER
value|0x62C
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CLKSTRETCH
value|0x630
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_WATCHDOG
value|0x634
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_GPIOSEL
value|0x638
end_define

begin_comment
comment|/* pmu rev>= 1 ? */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU_GPIOEN
value|0x63C
end_define

begin_comment
comment|/* pmu rev>= 1 ? */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_REQ_TIMER_SEL
value|0x640
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_REQ_TIMER
value|0x644
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_RES_REQ_MASK
value|0x648
end_define

begin_define
define|#
directive|define
name|CHIPC_CHIPCTL_ADDR
value|0x650
end_define

begin_define
define|#
directive|define
name|CHIPC_CHIPCTL_DATA
value|0x654
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_REG_CONTROL_ADDR
value|0x658
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_REG_CONTROL_DATA
value|0x65C
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_PLL_CONTROL_ADDR
value|0x660
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_PLL_CONTROL_DATA
value|0x664
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_STRAPOPT
value|0x668
end_define

begin_comment
comment|/* chipc rev>= 28 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU_XTALFREQ
value|0x66C
end_define

begin_comment
comment|/* pmu rev>= 10 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SPROM_OTP
value|0x800
end_define

begin_comment
comment|/* SPROM/OTP address space */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SPROM_OTP_SIZE
value|0x400
end_define

begin_comment
comment|/** chipid */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ID_CHIP_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/**< chip id */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ID_CHIP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_ID_REV_MASK
value|0x000F0000
end_define

begin_comment
comment|/**< chip revision */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ID_REV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_ID_PKG_MASK
value|0x00F00000
end_define

begin_comment
comment|/**< physical package ID */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ID_PKG_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CHIPC_ID_NUMCORE_MASK
value|0x0F000000
end_define

begin_comment
comment|/**< number of cores on chip (rev>= 4) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ID_NUMCORE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_ID_BUS_MASK
value|0xF0000000
end_define

begin_comment
comment|/**< chip/interconnect type (BHND_CHIPTYPE_*) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ID_BUS_SHIFT
value|28
end_define

begin_comment
comment|/* capabilities */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_NUM_UART_MASK
value|0x00000003
end_define

begin_comment
comment|/* Number of UARTs (1-3) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_NUM_UART_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_CAP_MIPSEB
value|0x00000004
end_define

begin_comment
comment|/* MIPS is in big-endian mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_UCLKSEL_MASK
value|0x00000018
end_define

begin_comment
comment|/* UARTs clock select */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_UCLKSEL_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_CAP_UCLKSEL_UINTCLK
value|0x1
end_define

begin_comment
comment|/* UARTs are driven by internal divided clock */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_UARTGPIO
value|0x00000020
end_define

begin_comment
comment|/* UARTs own GPIOs 15:12 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_EXTBUS_MASK
value|0x000000c0
end_define

begin_comment
comment|/* External bus mask */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_EXTBUS_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_CAP_EXTBUS_NONE
value|0x0
end_define

begin_comment
comment|/* No ExtBus present */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_EXTBUS_FULL
value|0x1
end_define

begin_comment
comment|/* ExtBus: PCMCIA, IDE& Prog */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_EXTBUS_PROG
value|0x2
end_define

begin_comment
comment|/* ExtBus: ProgIf only */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_FLASH_MASK
value|0x00000700
end_define

begin_comment
comment|/* Type of flash */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_FLASH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_CAP_FLASH_NONE
value|0x000
end_define

begin_comment
comment|/* No flash */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_SFLASH_ST
value|0x100
end_define

begin_comment
comment|/* ST serial flash */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_SFLASH_AT
value|0x200
end_define

begin_comment
comment|/* Atmel serial flash */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_NFLASH
value|0x300
end_define

begin_comment
comment|/* NAND flash */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_PFLASH
value|0x700
end_define

begin_comment
comment|/* Parallel flash */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_PLL_MASK
value|0x00038000
end_define

begin_comment
comment|/* Type of PLL */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_PLL_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|CHIPC_CAP_PWR_CTL
value|0x00040000
end_define

begin_comment
comment|/* Power control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_OTP_SIZE_MASK
value|0x00380000
end_define

begin_comment
comment|/* OTP Size (0 = none) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_OTP_SIZE_SHIFT
value|19
end_define

begin_comment
comment|/* OTP Size shift */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_OTP_SIZE_BASE
value|5
end_define

begin_comment
comment|/* OTP Size base */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_JTAGP
value|0x00400000
end_define

begin_comment
comment|/* JTAG Master Present */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_ROM
value|0x00800000
end_define

begin_comment
comment|/* Internal boot rom active */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_BKPLN64
value|0x08000000
end_define

begin_comment
comment|/* 64-bit backplane */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_PMU
value|0x10000000
end_define

begin_comment
comment|/* PMU Present, rev>= 20 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_ECI
value|0x20000000
end_define

begin_comment
comment|/* Enhanced Coexistence Interface */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_SPROM
value|0x40000000
end_define

begin_comment
comment|/* SPROM Present, rev>= 32 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP_4706_NFLASH
value|0x80000000
end_define

begin_comment
comment|/* NAND flash present, BCM4706 or chipc rev38 (BCM5357)? */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP2_SECI
value|0x00000001
end_define

begin_comment
comment|/* SECI Present, rev>= 36 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP2_GSIO
value|0x00000002
end_define

begin_comment
comment|/* GSIO (spi/i2c) present, rev>= 37 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP2_GCI
value|0x00000004
end_define

begin_comment
comment|/* GCI present (rev>= ??) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CAP2_AOB
value|0x00000040
end_define

begin_comment
comment|/* Always on Bus present (rev>= 49) 							 * 							 * If set, PMU and GCI registers 							 * are found in dedicated cores. 							 * 							 * This appears to be a lower power 							 * APB bus, bridged via ARM APB IP. */
end_comment

begin_comment
comment|/*  * ChipStatus (Common)  */
end_comment

begin_comment
comment|/** ChipStatus CIS/OTP/SPROM values used to advertise OTP/SPROM availability in  *  chipcommon revs 11-31. */
end_comment

begin_enum
enum|enum
block|{
name|CHIPC_CST_DEFCIS_SEL
init|=
literal|0
block|,
comment|/**< OTP is powered up, use default CIS, no SPROM */
name|CHIPC_CST_SPROM_SEL
init|=
literal|1
block|,
comment|/**< OTP is powered up, SPROM is present */
name|CHIPC_CST_OTP_SEL
init|=
literal|2
block|,
comment|/**< OTP is powered up, no SPROM */
name|CHIPC_CST_OTP_PWRDN
init|=
literal|3
comment|/**< OTP is powered down, SPROM is present (rev<= 22 only) */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|CHIPC_CST_SPROM_OTP_SEL_R22_MASK
value|0x00000003
end_define

begin_comment
comment|/**< chipstatus OTP/SPROM SEL value (rev 22) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST_SPROM_OTP_SEL_R22_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_CST_SPROM_OTP_SEL_R23_MASK
value|0x000000c0
end_define

begin_comment
comment|/**< chipstatus OTP/SPROM SEL value (revs 23-31) 								  *   								  *  it is unknown whether this is supported on 								  *  any CC revs>= 32 that also vend CHIPC_CAP_* 								  *  constants for OTP/SPROM/NVRAM availability. 								  */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST_SPROM_OTP_SEL_R23_SHIFT
value|6
end_define

begin_comment
comment|/* PLL type */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PLL_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PLL_TYPE1
value|0x00010000
end_define

begin_comment
comment|/* 48MHz base, 3 dividers */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PLL_TYPE2
value|0x00020000
end_define

begin_comment
comment|/* 48MHz, 4 dividers */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PLL_TYPE3
value|0x00030000
end_define

begin_comment
comment|/* 25MHz, 2 dividers */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PLL_TYPE4
value|0x00008000
end_define

begin_comment
comment|/* 48MHz, 4 dividers */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PLL_TYPE5
value|0x00018000
end_define

begin_comment
comment|/* 25MHz, 4 dividers */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PLL_TYPE6
value|0x00028000
end_define

begin_comment
comment|/* 100/200 or 120/240 only */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PLL_TYPE7
value|0x00038000
end_define

begin_comment
comment|/* 25MHz, 4 dividers */
end_comment

begin_comment
comment|/* ILP clock */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ILP_CLOCK
value|32000
end_define

begin_comment
comment|/* ALP clock on pre-PMU chips */
end_comment

begin_define
define|#
directive|define
name|CHIPC_ALP_CLOCK
value|20000000
end_define

begin_comment
comment|/* HT clock */
end_comment

begin_define
define|#
directive|define
name|CHIPC_HT_CLOCK
value|80000000
end_define

begin_comment
comment|/* corecontrol */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UARTCLKO
value|0x00000001
end_define

begin_comment
comment|/* Drive UART with internal clock */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SE
value|0x00000002
end_define

begin_comment
comment|/* sync clk out enable (corerev>= 3) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UARTCLKEN
value|0x00000008
end_define

begin_comment
comment|/* enable UART Clock (corerev> = 21 */
end_comment

begin_comment
comment|/* chipcontrol */
end_comment

begin_define
define|#
directive|define
name|CHIPCTRL_4321A0_DEFAULT
value|0x3a4
end_define

begin_define
define|#
directive|define
name|CHIPCTRL_4321A1_DEFAULT
value|0x0a4
end_define

begin_define
define|#
directive|define
name|CHIPCTRL_4321_PLL_DOWN
value|0x800000
end_define

begin_comment
comment|/* serdes PLL down override */
end_comment

begin_comment
comment|/* Fields in the otpstatus register in rev>= 21 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_OL_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPS_OL_MFG
value|0x00000001
end_define

begin_comment
comment|/* manuf row is locked */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_OL_OR1
value|0x00000002
end_define

begin_comment
comment|/* otp redundancy row 1 is locked */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_OL_OR2
value|0x00000004
end_define

begin_comment
comment|/* otp redundancy row 2 is locked */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_OL_GU
value|0x00000008
end_define

begin_comment
comment|/* general use region is locked */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_GUP_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPS_GUP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPS_GUP_HW
value|0x00000100
end_define

begin_comment
comment|/* h/w subregion is programmed */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_GUP_SW
value|0x00000200
end_define

begin_comment
comment|/* s/w subregion is programmed */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_GUP_CI
value|0x00000400
end_define

begin_comment
comment|/* chipid/pkgopt subregion is programmed */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_GUP_FUSE
value|0x00000800
end_define

begin_comment
comment|/* fuse subregion is programmed */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_READY
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPS_RV
parameter_list|(
name|x
parameter_list|)
value|(1<< (16 + (x)))
end_define

begin_comment
comment|/* redundancy entry valid */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPS_RV_MASK
value|0x0fff0000
end_define

begin_comment
comment|/* Fields in the otpcontrol register in rev>= 21 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPC_PROGSEL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPC_PCOUNT_MASK
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPC_PCOUNT_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPC_VSEL_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPC_VSEL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPC_TMM_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPC_TMM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPC_ODM
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPC_PROGEN
value|0x80000000
end_define

begin_comment
comment|/* Fields in otpprog in rev>= 21 and HND OTP */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPP_COL_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_COL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_ROW_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_ROW_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_OC_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_OC_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_READERR
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_VALUE_MASK
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_VALUE_SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_START_BUSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPP_READ
value|0x40000000
end_define

begin_comment
comment|/* HND OTP */
end_comment

begin_comment
comment|/* otplayout */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPL_SIZE_MASK
value|0x0000f000
end_define

begin_comment
comment|/* rev>= 49 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPL_SIZE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPL_CISFORMAT_NEW
value|0x80000000
end_define

begin_comment
comment|/* rev>= 36 */
end_comment

begin_comment
comment|/* Opcodes for OTPP_OC field */
end_comment

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_READ
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_BIT_PROG
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_VERIFY
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_INIT
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_SET
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_RESET
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_OCST
value|7
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_ROW_LOCK
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_OTPPOC_PRESCN_TEST
value|9
end_define

begin_comment
comment|/* Jtagm characteristics that appeared at a given corerev */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JTAGM_CREV_OLD
value|10
end_define

begin_comment
comment|/* Old command set, 16bit max IR */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JTAGM_CREV_IRP
value|22
end_define

begin_comment
comment|/* Able to do pause-ir */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JTAGM_CREV_RTI
value|28
end_define

begin_comment
comment|/* Able to do return-to-idle */
end_comment

begin_comment
comment|/* jtagcmd */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCMD_START
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_BUSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_STATE_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_STATE_TLR
value|0x00000000
end_define

begin_comment
comment|/* Test-logic-reset */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCMD_STATE_PIR
value|0x20000000
end_define

begin_comment
comment|/* Pause IR */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCMD_STATE_PDR
value|0x40000000
end_define

begin_comment
comment|/* Pause DR */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCMD_STATE_RTI
value|0x60000000
end_define

begin_comment
comment|/* Run-test-idle */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCMD0_ACC_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD0_ACC_IRDR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD0_ACC_DR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD0_ACC_IR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD0_ACC_RESET
value|0x00003000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD0_ACC_IRPDR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD0_ACC_PDR
value|0x00005000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD0_IRW_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_MASK
value|0x000f0000
end_define

begin_comment
comment|/* Changes for corerev 11 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_IRDR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_DR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_IR
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_RESET
value|0x00030000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_IRPDR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_PDR
value|0x00050000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_PIR
value|0x00060000
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_IRDR_I
value|0x00070000
end_define

begin_comment
comment|/* rev 28: return to run-test-idle */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCMD_ACC_DR_I
value|0x00080000
end_define

begin_comment
comment|/* rev 28: return to run-test-idle */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCMD_IRW_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_IRW_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_JCMD_DRW_MASK
value|0x0000003f
end_define

begin_comment
comment|/* jtagctrl */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCTRL_FORCE_CLK
value|4
end_define

begin_comment
comment|/* Force clock */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCTRL_EXT_EN
value|2
end_define

begin_comment
comment|/* Enable external targets */
end_comment

begin_define
define|#
directive|define
name|CHIPC_JCTRL_EN
value|1
end_define

begin_comment
comment|/* Enable Jtag master */
end_comment

begin_comment
comment|/* Fields in clkdiv */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLKD_SFLASH
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKD_SFLASH_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKD_OTP
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKD_OTP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKD_JTAG
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKD_JTAG_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKD_UART
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKD2_SPROM
value|0x00000003
end_define

begin_comment
comment|/* intstatus/intmask */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CI_GPIO
value|0x00000001
end_define

begin_comment
comment|/* gpio intr */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CI_EI
value|0x00000002
end_define

begin_comment
comment|/* extif intr (corerev>= 3) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CI_TEMP
value|0x00000004
end_define

begin_comment
comment|/* temp. ctrl intr (corerev>= 15) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CI_SIRQ
value|0x00000008
end_define

begin_comment
comment|/* serial IRQ intr (corerev>= 15) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CI_PMU
value|0x00000020
end_define

begin_comment
comment|/* pmu intr (corerev>= 21) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CI_UART
value|0x00000040
end_define

begin_comment
comment|/* uart intr (corerev>= 21) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CI_WDRESET
value|0x80000000
end_define

begin_comment
comment|/* watchdog reset occurred */
end_comment

begin_comment
comment|/* slow_clk_ctl */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_SS_MASK
value|0x00000007
end_define

begin_comment
comment|/* slow clock source mask */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_SS_LPO
value|0x00000000
end_define

begin_comment
comment|/* source of slow clock is LPO */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_SS_XTAL
value|0x00000001
end_define

begin_comment
comment|/* source of slow clock is crystal */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_SS_PCI
value|0x00000002
end_define

begin_comment
comment|/* source of slow clock is PCI */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_LF
value|0x00000200
end_define

begin_comment
comment|/* LPOFreqSel, 1: 160Khz, 0: 32KHz */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_LP
value|0x00000400
end_define

begin_comment
comment|/* LPOPowerDown, 1: LPO is disabled, 						 * 0: LPO is enabled 						 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_FS
value|0x00000800
end_define

begin_comment
comment|/* ForceSlowClk, 1: sb/cores running on slow clock, 						 * 0: power logic control 						 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_IP
value|0x00001000
end_define

begin_comment
comment|/* IgnorePllOffReq, 1/0: power logic ignores/honors 						 * PLL clock disable requests from core 						 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_XC
value|0x00002000
end_define

begin_comment
comment|/* XtalControlEn, 1/0: power logic does/doesn't 						 * disable crystal when appropriate 						 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_XP
value|0x00004000
end_define

begin_comment
comment|/* XtalPU (RO), 1/0: crystal running/disabled */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_CD_MASK
value|0xffff0000
end_define

begin_comment
comment|/* ClockDivider (SlowClk = 1/(4+divisor)) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SCC_CD_SHIFT
value|16
end_define

begin_comment
comment|/* system_clk_ctl */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYCC_IE
value|0x00000001
end_define

begin_comment
comment|/* ILPen: Enable Idle Low Power */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYCC_AE
value|0x00000002
end_define

begin_comment
comment|/* ALPen: Enable Active Low Power */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYCC_FP
value|0x00000004
end_define

begin_comment
comment|/* ForcePLLOn */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYCC_AR
value|0x00000008
end_define

begin_comment
comment|/* Force ALP (or HT if ALPen is not set */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYCC_HR
value|0x00000010
end_define

begin_comment
comment|/* Force HT */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYCC_CD_MASK
value|0xffff0000
end_define

begin_comment
comment|/* ClkDiv  (ILP = 1/(4 * (divisor + 1)) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SYCC_CD_SHIFT
value|16
end_define

begin_comment
comment|/* Indirect backplane access */
end_comment

begin_define
define|#
directive|define
name|CHIPC_BPIA_BYTEEN
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|CHIPC_BPIA_SZ1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CHIPC_BPIA_SZ2
value|0x00000003
end_define

begin_define
define|#
directive|define
name|CHIPC_BPIA_SZ4
value|0x00000007
end_define

begin_define
define|#
directive|define
name|CHIPC_BPIA_SZ8
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|CHIPC_BPIA_WRITE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CHIPC_BPIA_START
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CHIPC_BPIA_BUSY
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CHIPC_BPIA_ERROR
value|0x00000400
end_define

begin_comment
comment|/* pcmcia/prog/flash_config */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_EN
value|0x00000001
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_EM_MASK
value|0x0000000e
end_define

begin_comment
comment|/* mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_EM_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_CF_EM_FLASH
value|0
end_define

begin_comment
comment|/* flash/asynchronous mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_EM_SYNC
value|2
end_define

begin_comment
comment|/* synchronous mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_EM_PCMCIA
value|4
end_define

begin_comment
comment|/* pcmcia mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_DS
value|0x00000010
end_define

begin_comment
comment|/* destsize:  0=8bit, 1=16bit */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_BS
value|0x00000020
end_define

begin_comment
comment|/* byteswap */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_CD_MASK
value|0x000000c0
end_define

begin_comment
comment|/* clock divider */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_CD_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_CF_CD_DIV2
value|0x00000000
end_define

begin_comment
comment|/* backplane/2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_CD_DIV3
value|0x00000040
end_define

begin_comment
comment|/* backplane/3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_CD_DIV4
value|0x00000080
end_define

begin_comment
comment|/* backplane/4 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_CE
value|0x00000100
end_define

begin_comment
comment|/* clock enable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CF_SB
value|0x00000200
end_define

begin_comment
comment|/* size/bytestrobe (synch only) */
end_comment

begin_comment
comment|/* pcmcia_memwait */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PM_W0_MASK
value|0x0000003f
end_define

begin_comment
comment|/* waitcount0 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PM_W1_MASK
value|0x00001f00
end_define

begin_comment
comment|/* waitcount1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PM_W1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PM_W2_MASK
value|0x001f0000
end_define

begin_comment
comment|/* waitcount2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PM_W2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_PM_W3_MASK
value|0x1f000000
end_define

begin_comment
comment|/* waitcount3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PM_W3_SHIFT
value|24
end_define

begin_comment
comment|/* pcmcia_attrwait */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PA_W0_MASK
value|0x0000003f
end_define

begin_comment
comment|/* waitcount0 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PA_W1_MASK
value|0x00001f00
end_define

begin_comment
comment|/* waitcount1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PA_W1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PA_W2_MASK
value|0x001f0000
end_define

begin_comment
comment|/* waitcount2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PA_W2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_PA_W3_MASK
value|0x1f000000
end_define

begin_comment
comment|/* waitcount3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PA_W3_SHIFT
value|24
end_define

begin_comment
comment|/* pcmcia_iowait */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PI_W0_MASK
value|0x0000003f
end_define

begin_comment
comment|/* waitcount0 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PI_W1_MASK
value|0x00001f00
end_define

begin_comment
comment|/* waitcount1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PI_W1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PI_W2_MASK
value|0x001f0000
end_define

begin_comment
comment|/* waitcount2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PI_W2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_PI_W3_MASK
value|0x1f000000
end_define

begin_comment
comment|/* waitcount3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PI_W3_SHIFT
value|24
end_define

begin_comment
comment|/* prog_waitcount */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PW_W0_MASK
value|0x0000001f
end_define

begin_comment
comment|/* waitcount0 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PW_W1_MASK
value|0x00001f00
end_define

begin_comment
comment|/* waitcount1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PW_W1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PW_W2_MASK
value|0x001f0000
end_define

begin_comment
comment|/* waitcount2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PW_W2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_PW_W3_MASK
value|0x1f000000
end_define

begin_comment
comment|/* waitcount3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PW_W3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_PW_W0
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|CHIPC_PW_W1
value|0x00000a00
end_define

begin_define
define|#
directive|define
name|CHIPC_PW_W2
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CHIPC_PW_W3
value|0x01000000
end_define

begin_comment
comment|/* flash_waitcount */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FW_W0_MASK
value|0x0000003f
end_define

begin_comment
comment|/* waitcount0 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FW_W1_MASK
value|0x00001f00
end_define

begin_comment
comment|/* waitcount1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FW_W1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_FW_W2_MASK
value|0x001f0000
end_define

begin_comment
comment|/* waitcount2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FW_W2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_FW_W3_MASK
value|0x1f000000
end_define

begin_comment
comment|/* waitcount3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FW_W3_SHIFT
value|24
end_define

begin_comment
comment|/* When SPROM support present, fields in spromcontrol */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SRC_START
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_BUSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_OPCODE
value|0x60000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_OP_READ
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_OP_WRITE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_OP_WRDIS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_OP_WREN
value|0x60000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_OTPSEL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_LOCK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_SIZE_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_SIZE_1K
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_SIZE_4K
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_SIZE_16K
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_SIZE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_SRC_PRESENT
value|0x00000001
end_define

begin_comment
comment|/* Fields in pmucontrol */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PCTL_ILP_DIV_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|CHIPC_PCTL_ILP_DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_PCTL_PLL_PLLCTL_UPD
value|0x00000400
end_define

begin_comment
comment|/* rev 2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PCTL_NOILP_ON_WAIT
value|0x00000200
end_define

begin_comment
comment|/* rev 1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PCTL_HT_REQ_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CHIPC_PCTL_ALP_REQ_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CHIPC_PCTL_XTALFREQ_MASK
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|CHIPC_PCTL_XTALFREQ_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_PCTL_ILP_DIV_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CHIPC_PCTL_LPO_SEL
value|0x00000001
end_define

begin_comment
comment|/* Fields in clkstretch */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CSTRETCH_HT
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|CHIPC_CSTRETCH_ALP
value|0x0000ffff
end_define

begin_comment
comment|/* gpiotimerval */
end_comment

begin_define
define|#
directive|define
name|CHIPC_GPIO_ONTIME_SHIFT
value|16
end_define

begin_comment
comment|/* clockcontrol_n */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CN_N1_MASK
value|0x3f
end_define

begin_comment
comment|/* n1 control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CN_N2_MASK
value|0x3f00
end_define

begin_comment
comment|/* n2 control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CN_N2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_CN_PLLC_MASK
value|0xf0000
end_define

begin_comment
comment|/* pll control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CN_PLLC_SHIFT
value|16
end_define

begin_comment
comment|/* clockcontrol_sb/pci/uart */
end_comment

begin_define
define|#
directive|define
name|CHIPC_M1_MASK
value|0x3f
end_define

begin_comment
comment|/* m1 control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_M2_MASK
value|0x3f00
end_define

begin_comment
comment|/* m2 control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_M2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_M3_MASK
value|0x3f0000
end_define

begin_comment
comment|/* m3 control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_M3_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_MC_MASK
value|0x1f000000
end_define

begin_comment
comment|/* mux control */
end_comment

begin_define
define|#
directive|define
name|CHIPC_MC_SHIFT
value|24
end_define

begin_comment
comment|/* N3M Clock control magic field values */
end_comment

begin_define
define|#
directive|define
name|CHIPC_F6_2
value|0x02
end_define

begin_comment
comment|/* A factor of 2 in */
end_comment

begin_define
define|#
directive|define
name|CHIPC_F6_3
value|0x03
end_define

begin_comment
comment|/* 6-bit fields like */
end_comment

begin_define
define|#
directive|define
name|CHIPC_F6_4
value|0x05
end_define

begin_comment
comment|/* N1, M1 or M3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_F6_5
value|0x09
end_define

begin_define
define|#
directive|define
name|CHIPC_F6_6
value|0x11
end_define

begin_define
define|#
directive|define
name|CHIPC_F6_7
value|0x21
end_define

begin_define
define|#
directive|define
name|CHIPC_F5_BIAS
value|5
end_define

begin_comment
comment|/* 5-bit fields get this added */
end_comment

begin_define
define|#
directive|define
name|CHIPC_MC_BYPASS
value|0x08
end_define

begin_define
define|#
directive|define
name|CHIPC_MC_M1
value|0x04
end_define

begin_define
define|#
directive|define
name|CHIPC_MC_M1M2
value|0x02
end_define

begin_define
define|#
directive|define
name|CHIPC_MC_M1M2M3
value|0x01
end_define

begin_define
define|#
directive|define
name|CHIPC_MC_M1M3
value|0x11
end_define

begin_comment
comment|/* Type 2 Clock control magic field values */
end_comment

begin_define
define|#
directive|define
name|CHIPC_T2_BIAS
value|2
end_define

begin_comment
comment|/* n1, n2, m1& m3 bias */
end_comment

begin_define
define|#
directive|define
name|CHIPC_T2M2_BIAS
value|3
end_define

begin_comment
comment|/* m2 bias */
end_comment

begin_define
define|#
directive|define
name|CHIPC_T2MC_M1BYP
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_T2MC_M2BYP
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_T2MC_M3BYP
value|4
end_define

begin_comment
comment|/* Type 6 Clock control magic field values */
end_comment

begin_define
define|#
directive|define
name|CHIPC_T6_MMASK
value|1
end_define

begin_comment
comment|/* bits of interest in m */
end_comment

begin_define
define|#
directive|define
name|CHIPC_T6_M0
value|120000000
end_define

begin_comment
comment|/* sb clock for m = 0 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_T6_M1
value|100000000
end_define

begin_comment
comment|/* sb clock for m = 1 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SB2MIPS_T6
parameter_list|(
name|sb
parameter_list|)
value|(2 * (sb))
end_define

begin_comment
comment|/* Common clock base */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLOCK_BASE1
value|24000000
end_define

begin_comment
comment|/* Half the clock freq */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLOCK_BASE2
value|12500000
end_define

begin_comment
comment|/* Alternate crystal on some PLLs */
end_comment

begin_comment
comment|/* Clock control values for 200MHz in 5350 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CLKC_5350_N
value|0x0311
end_define

begin_define
define|#
directive|define
name|CHIPC_CLKC_5350_M
value|0x04020009
end_define

begin_comment
comment|/* Bits in the ExtBus config registers */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CFG_EN
value|0x0001
end_define

begin_comment
comment|/* Enable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CFG_EM_MASK
value|0x000e
end_define

begin_comment
comment|/* Extif Mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CFG_EM_ASYNC
value|0x0000
end_define

begin_comment
comment|/*   Async/Parallel flash */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CFG_EM_SYNC
value|0x0002
end_define

begin_comment
comment|/*   Synchronous */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CFG_EM_PCMCIA
value|0x0004
end_define

begin_comment
comment|/*   PCMCIA */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CFG_EM_IDE
value|0x0006
end_define

begin_comment
comment|/*   IDE */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FLASH_CFG_DS
value|0x0010
end_define

begin_comment
comment|/* Data size, 0=8bit, 1=16bit */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FLASH_CFG_CD_MASK
value|0x00e0
end_define

begin_comment
comment|/* Sync: Clock divisor, rev>= 20 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FLASH_CFG_CE
value|0x0100
end_define

begin_comment
comment|/* Sync: Clock enable, rev>= 20 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FLASH_CFG_SB
value|0x0200
end_define

begin_comment
comment|/* Sync: Size/Bytestrobe, rev>= 20 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_FLASH_CFG_IS
value|0x0400
end_define

begin_comment
comment|/* Extif Sync Clk Select, rev>= 20 */
end_comment

begin_comment
comment|/* ExtBus address space */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_BASE
value|0x1a000000
end_define

begin_comment
comment|/* Chipc ExtBus base address */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_PCMCIA_MEM
value|0x1a000000
end_define

begin_comment
comment|/* PCMCIA 0 memory base address */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_PCMCIA_IO
value|0x1a200000
end_define

begin_comment
comment|/* PCMCIA 0 I/O base address */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_PCMCIA_CFG
value|0x1a400000
end_define

begin_comment
comment|/* PCMCIA 0 config base address */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_IDE
value|0x1a800000
end_define

begin_comment
comment|/* IDE memory base */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_PCMCIA1_MEM
value|0x1a800000
end_define

begin_comment
comment|/* PCMCIA 1 memory base address */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_PCMCIA1_IO
value|0x1aa00000
end_define

begin_comment
comment|/* PCMCIA 1 I/O base address */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_PCMCIA1_CFG
value|0x1ac00000
end_define

begin_comment
comment|/* PCMCIA 1 config base address */
end_comment

begin_define
define|#
directive|define
name|CHIPC_EB_PROGIF
value|0x1b000000
end_define

begin_comment
comment|/* ProgIF Async/Sync base address */
end_comment

begin_comment
comment|/* Start/busy bit in flashcontrol */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_OPCODE
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ACTION
value|0x00000700
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_CS_ACTIVE
value|0x00001000
end_define

begin_comment
comment|/* Chip Select Active, rev>= 20 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_START
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_BUSY
value|SFLASH_START
end_define

begin_comment
comment|/* flashcontrol action codes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ACT_OPONLY
value|0x0000
end_define

begin_comment
comment|/* Issue opcode only */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ACT_OP1D
value|0x0100
end_define

begin_comment
comment|/* opcode + 1 data byte */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ACT_OP3A
value|0x0200
end_define

begin_comment
comment|/* opcode + 3 addr bytes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ACT_OP3A1D
value|0x0300
end_define

begin_comment
comment|/* opcode + 3 addr& 1 data bytes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ACT_OP3A4D
value|0x0400
end_define

begin_comment
comment|/* opcode + 3 addr& 4 data bytes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ACT_OP3A4X4D
value|0x0500
end_define

begin_comment
comment|/* opcode + 3 addr, 4 don't care& 4 data bytes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ACT_OP3A1X4D
value|0x0700
end_define

begin_comment
comment|/* opcode + 3 addr, 1 don't care& 4 data bytes */
end_comment

begin_comment
comment|/* flashcontrol action+opcodes for ST flashes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_WREN
value|0x0006
end_define

begin_comment
comment|/* Write Enable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_WRDIS
value|0x0004
end_define

begin_comment
comment|/* Write Disable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_RDSR
value|0x0105
end_define

begin_comment
comment|/* Read Status Register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_WRSR
value|0x0101
end_define

begin_comment
comment|/* Write Status Register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_READ
value|0x0303
end_define

begin_comment
comment|/* Read Data Bytes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_PP
value|0x0302
end_define

begin_comment
comment|/* Page Program */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_SE
value|0x02d8
end_define

begin_comment
comment|/* Sector Erase */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_BE
value|0x00c7
end_define

begin_comment
comment|/* Bulk Erase */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_DP
value|0x00b9
end_define

begin_comment
comment|/* Deep Power-down */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_RES
value|0x03ab
end_define

begin_comment
comment|/* Read Electronic Signature */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_CSA
value|0x1000
end_define

begin_comment
comment|/* Keep chip select asserted */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_SSE
value|0x0220
end_define

begin_comment
comment|/* Sub-sector Erase */
end_comment

begin_comment
comment|/* Status register bits for ST flashes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_WIP
value|0x01
end_define

begin_comment
comment|/* Write In Progress */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_WEL
value|0x02
end_define

begin_comment
comment|/* Write Enable Latch */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_BP_MASK
value|0x1c
end_define

begin_comment
comment|/* Block Protect */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_BP_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_ST_SRWD
value|0x80
end_define

begin_comment
comment|/* Status Register Write Disable */
end_comment

begin_comment
comment|/* flashcontrol action+opcodes for Atmel flashes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_READ
value|0x07e8
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_PAGE_READ
value|0x07d2
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF1_READ
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF2_READ
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_STATUS
value|0x01d7
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF1_WRITE
value|0x0384
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF2_WRITE
value|0x0387
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF1_ERASE_PROGRAM
value|0x0283
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF2_ERASE_PROGRAM
value|0x0286
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF1_PROGRAM
value|0x0288
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF2_PROGRAM
value|0x0289
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_PAGE_ERASE
value|0x0281
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BLOCK_ERASE
value|0x0250
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF1_WRITE_ERASE_PROGRAM
value|0x0382
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF2_WRITE_ERASE_PROGRAM
value|0x0385
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF1_LOAD
value|0x0253
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF2_LOAD
value|0x0255
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF1_COMPARE
value|0x0260
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF2_COMPARE
value|0x0261
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF1_REPROGRAM
value|0x0258
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_BUF2_REPROGRAM
value|0x0259
end_define

begin_comment
comment|/* Status register bits for Atmel flashes */
end_comment

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_READY
value|0x80
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_MISMATCH
value|0x40
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_ID_MASK
value|0x38
end_define

begin_define
define|#
directive|define
name|CHIPC_SFLASH_AT_ID_SHIFT
value|3
end_define

begin_comment
comment|/*  * These are the UART port assignments, expressed as offsets from the base  * register.  These assignments should hold for any serial port based on  * a 8250, 16450, or 16550(A).  */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_RX
value|0
end_define

begin_comment
comment|/* In:  Receive buffer (DLAB=0) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_TX
value|0
end_define

begin_comment
comment|/* Out: Transmit buffer (DLAB=0) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_DLL
value|0
end_define

begin_comment
comment|/* Out: Divisor Latch Low (DLAB=1) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IER
value|1
end_define

begin_comment
comment|/* In/Out: Interrupt Enable Register (DLAB=0) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_DLM
value|1
end_define

begin_comment
comment|/* Out: Divisor Latch High (DLAB=1) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR
value|2
end_define

begin_comment
comment|/* In: Interrupt Identity Register  */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_FCR
value|2
end_define

begin_comment
comment|/* Out: FIFO Control Register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LCR
value|3
end_define

begin_comment
comment|/* Out: Line Control Register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_MCR
value|4
end_define

begin_comment
comment|/* Out: Modem Control Register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR
value|5
end_define

begin_comment
comment|/* In:  Line Status Register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_MSR
value|6
end_define

begin_comment
comment|/* In:  Modem Status Register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_SCR
value|7
end_define

begin_comment
comment|/* I/O: Scratch Register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LCR_DLAB
value|0x80
end_define

begin_comment
comment|/* Divisor latch access bit */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LCR_WLEN8
value|0x03
end_define

begin_comment
comment|/* Word length: 8 bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_MCR_OUT2
value|0x08
end_define

begin_comment
comment|/* MCR GPIO out 2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_MCR_LOOP
value|0x10
end_define

begin_comment
comment|/* Enable loopback test mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR_RX_FIFO
value|0x80
end_define

begin_comment
comment|/* Receive FIFO error */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR_TDHR
value|0x40
end_define

begin_comment
comment|/* Data-hold-register empty */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR_THRE
value|0x20
end_define

begin_comment
comment|/* Transmit-hold-register empty */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR_BREAK
value|0x10
end_define

begin_comment
comment|/* Break interrupt */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR_FRAMING
value|0x08
end_define

begin_comment
comment|/* Framing error */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR_PARITY
value|0x04
end_define

begin_comment
comment|/* Parity error */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR_OVERRUN
value|0x02
end_define

begin_comment
comment|/* Overrun error */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_LSR_RXRDY
value|0x01
end_define

begin_comment
comment|/* Receiver ready */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_FCR_FIFO_ENABLE
value|1
end_define

begin_comment
comment|/* FIFO control register bit controlling FIFO enable/disable */
end_comment

begin_comment
comment|/* Interrupt Identity Register (IIR) bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR_FIFO_MASK
value|0xc0
end_define

begin_comment
comment|/* IIR FIFO disable/enabled mask */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR_INT_MASK
value|0xf
end_define

begin_comment
comment|/* IIR interrupt ID source */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR_MDM_CHG
value|0x0
end_define

begin_comment
comment|/* Modem status changed */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR_NOINT
value|0x1
end_define

begin_comment
comment|/* No interrupt pending */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR_THRE
value|0x2
end_define

begin_comment
comment|/* THR empty */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR_RCVD_DATA
value|0x4
end_define

begin_comment
comment|/* Received data available */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR_RCVR_STATUS
value|0x6
end_define

begin_comment
comment|/* Receiver status */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IIR_CHAR_TIME
value|0xc
end_define

begin_comment
comment|/* Character time */
end_comment

begin_comment
comment|/* Interrupt Enable Register (IER) bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IER_EDSSI
value|8
end_define

begin_comment
comment|/* enable modem status interrupt */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IER_ELSI
value|4
end_define

begin_comment
comment|/* enable receiver line status interrupt */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IER_ETBEI
value|2
end_define

begin_comment
comment|/* enable transmitter holding register empty interrupt */
end_comment

begin_define
define|#
directive|define
name|CHIPC_UART_IER_ERBFI
value|1
end_define

begin_comment
comment|/* enable data available interrupt */
end_comment

begin_comment
comment|/* pmustatus */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PST_EXTLPOAVAIL
value|0x0100
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_WDRESET
value|0x0080
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_INTPEND
value|0x0040
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_SBCLKST
value|0x0030
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_SBCLKST_ILP
value|0x0010
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_SBCLKST_ALP
value|0x0020
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_SBCLKST_HT
value|0x0030
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_ALPAVAIL
value|0x0008
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_HTAVAIL
value|0x0004
end_define

begin_define
define|#
directive|define
name|CHIPC_PST_RESINIT
value|0x0003
end_define

begin_comment
comment|/* pmucapabilities */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PCAP_REV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_RC_MASK
value|0x00001f00
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_RC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_TC_MASK
value|0x0001e000
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_TC_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_PC_MASK
value|0x001e0000
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_PC_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_VC_MASK
value|0x01e00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_VC_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_CC_MASK
value|0x1e000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP_CC_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP5_PC_MASK
value|0x003e0000
end_define

begin_comment
comment|/* PMU corerev>= 5 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PCAP5_PC_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP5_VC_MASK
value|0x07c00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP5_VC_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP5_CC_MASK
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PCAP5_CC_SHIFT
value|27
end_define

begin_comment
comment|/* PMU Resource Request Timer registers */
end_comment

begin_comment
comment|/* This is based on PmuRev0 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PRRT_TIME_MASK
value|0x03ff
end_define

begin_define
define|#
directive|define
name|CHIPC_PRRT_INTEN
value|0x0400
end_define

begin_define
define|#
directive|define
name|CHIPC_PRRT_REQ_ACTIVE
value|0x0800
end_define

begin_define
define|#
directive|define
name|CHIPC_PRRT_ALP_REQ
value|0x1000
end_define

begin_define
define|#
directive|define
name|CHIPC_PRRT_HT_REQ
value|0x2000
end_define

begin_comment
comment|/* PMU resource bit position */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMURES_BIT
parameter_list|(
name|bit
parameter_list|)
value|(1<< (bit))
end_define

begin_comment
comment|/* PMU resource number limit */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMURES_MAX_RESNUM
value|30
end_define

begin_comment
comment|/* PMU chip control0 register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU_CHIPCTL0
value|0
end_define

begin_comment
comment|/* PMU chip control1 register */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU_CHIPCTL1
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_RXC_DLL_BYPASS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_IF_TYPE_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_IF_TYPE_RMII
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_IF_TYPE_MII
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_IF_TYPE_RGMII
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_SW_TYPE_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_SW_TYPE_EPHY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_SW_TYPE_EPHYMII
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_SW_TYPE_EPHYRMII
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_CC1_SW_TYPE_RGMII
value|0x000000c0
end_define

begin_comment
comment|/* PMU corerev and chip specific PLL controls.  * PMU<rev>_PLL<num>_XX where<rev> is PMU corerev and<num> is an arbitrary number  * to differentiate different PLLs controlled by the same PMU rev.  */
end_comment

begin_comment
comment|/* pllcontrol registers */
end_comment

begin_comment
comment|/* PDIV, div_phy, div_arm, div_adc, dith_sel, ioff, kpd_scale, lsb_sel, mash_sel, lf_c& lf_r */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PLLCTL0
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_PDIV_MASK
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_PDIV_FREQ
value|25000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_BASE
value|8
end_define

begin_comment
comment|/* PC0_DIV_ARM for PLLOUT_ARM */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_110MHZ
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_97_7MHZ
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_88MHZ
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_80MHZ
value|3
end_define

begin_comment
comment|/* Default */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_73_3MHZ
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_67_7MHZ
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_62_9MHZ
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC0_DIV_ARM_58_6MHZ
value|7
end_define

begin_comment
comment|/* Wildcard base, stop_mod, en_lf_tp, en_cal& lf_r2 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PLLCTL1
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC1_WILD_INT_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC1_WILD_INT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC1_WILD_FRAC_MASK
value|0x0fffff00
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC1_WILD_FRAC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC1_STOP_MOD
value|0x00000040
end_define

begin_comment
comment|/* Wildcard base, vco_calvar, vco_swc, vco_var_selref, vso_ical& vco_sel_avdd */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PLLCTL2
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC2_WILD_INT_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU0_PLL0_PC2_WILD_INT_SHIFT
value|4
end_define

begin_comment
comment|/* pllcontrol registers */
end_comment

begin_comment
comment|/* ndiv_pwrdn, pwrdn_ch<x>, refcomp_pwrdn, dly_ch<x>, p1div, p2div, _bypass_sdmod */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PLLCTL0
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC0_P1DIV_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC0_P1DIV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC0_P2DIV_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC0_P2DIV_SHIFT
value|24
end_define

begin_comment
comment|/* m<x>div */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PLLCTL1
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC1_M1DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC1_M1DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC1_M2DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC1_M2DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC1_M3DIV_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC1_M3DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC1_M4DIV_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC1_M4DIV_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_DOT11MAC_880MHZ_CLK_DIVISOR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_DOT11MAC_880MHZ_CLK_DIVISOR_MASK
value|(0xFF<< DOT11MAC_880MHZ_CLK_DIVISOR_SHIFT)
end_define

begin_define
define|#
directive|define
name|CHIPC_DOT11MAC_880MHZ_CLK_DIVISOR_VAL
value|(0xE<< DOT11MAC_880MHZ_CLK_DIVISOR_SHIFT)
end_define

begin_comment
comment|/* m<x>div, ndiv_dither_mfb, ndiv_mode, ndiv_int */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PLLCTL2
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_M5DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_M5DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_M6DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_M6DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_NDIV_MODE_MASK
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_NDIV_MODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_NDIV_MODE_MASH
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_NDIV_MODE_MFB
value|2
end_define

begin_comment
comment|/* recommended for 4319 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_NDIV_INT_MASK
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC2_NDIV_INT_SHIFT
value|20
end_define

begin_comment
comment|/* ndiv_frac */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PLLCTL3
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC3_NDIV_FRAC_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC3_NDIV_FRAC_SHIFT
value|0
end_define

begin_comment
comment|/* pll_ctrl */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PLLCTL4
value|4
end_define

begin_comment
comment|/* pll_ctrl, vco_rng, clkdrive_ch<x> */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PLLCTL5
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC5_CLK_DRV_MASK
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_PC5_CLK_DRV_SHIFT
value|8
end_define

begin_comment
comment|/* PMU rev 2 control words */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU2_PHY_PLL_PLLCTL
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_SI_PLL_PLLCTL
value|10
end_define

begin_comment
comment|/* PMU rev 2 */
end_comment

begin_comment
comment|/* pllcontrol registers */
end_comment

begin_comment
comment|/* ndiv_pwrdn, pwrdn_ch<x>, refcomp_pwrdn, dly_ch<x>, p1div, p2div, _bypass_sdmod */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PLLCTL0
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC0_P1DIV_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC0_P1DIV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC0_P2DIV_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC0_P2DIV_SHIFT
value|24
end_define

begin_comment
comment|/* m<x>div */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PLLCTL1
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC1_M1DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC1_M1DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC1_M2DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC1_M2DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC1_M3DIV_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC1_M3DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC1_M4DIV_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC1_M4DIV_SHIFT
value|24
end_define

begin_comment
comment|/* m<x>div, ndiv_dither_mfb, ndiv_mode, ndiv_int */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PLLCTL2
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC2_M5DIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC2_M5DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC2_M6DIV_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC2_M6DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC2_NDIV_MODE_MASK
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC2_NDIV_MODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC2_NDIV_INT_MASK
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC2_NDIV_INT_SHIFT
value|20
end_define

begin_comment
comment|/* ndiv_frac */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PLLCTL3
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC3_NDIV_FRAC_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC3_NDIV_FRAC_SHIFT
value|0
end_define

begin_comment
comment|/* pll_ctrl */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PLLCTL4
value|4
end_define

begin_comment
comment|/* pll_ctrl, vco_rng, clkdrive_ch<x> */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PLLCTL5
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH1_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH1_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH2_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH2_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH3_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH3_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH4_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH4_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH5_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH5_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH6_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU2_PLL_PC5_CLKDRIVE_CH6_SHIFT
value|28
end_define

begin_comment
comment|/* PMU rev 5 (& 6) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_P1P2_OFF
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_P1_MASK
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_P1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_P2_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_P2_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_M14_OFF
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_MDIV_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_MDIV_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_NM5_OFF
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_NDIV_MASK
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_NDIV_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_NDIV_MODE_MASK
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_NDIV_MODE_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_FMAB_OFF
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_MRAT_MASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_MRAT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_ABRAT_MASK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_ABRAT_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_FDIV_MASK
value|0x07ffffff
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_PLLCTL_OFF
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_PCHI_OFF
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_PLL_PCHI_MASK
value|0x0000003f
end_define

begin_comment
comment|/* pmu XtalFreqRatio */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU_XTALFREQ_REG_ILPCTR_MASK
value|0x00001FFF
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_XTALFREQ_REG_MEASURE_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU_XTALFREQ_REG_MEASURE_SHIFT
value|31
end_define

begin_comment
comment|/* Divider allocation in 4716/47162/5356/5357 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU5_MAINPLL_CPU
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_MAINPLL_MEM
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5_MAINPLL_SI
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU7_PLL_PLLCTL7
value|7
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU7_PLL_PLLCTL8
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU7_PLL_PLLCTL11
value|11
end_define

begin_comment
comment|/* PLL usage in 4716/47162 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU4716_MAINPLL_PLL0
value|12
end_define

begin_comment
comment|/* PLL usage in 5356/5357 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU5356_MAINPLL_PLL0
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU5357_MAINPLL_PLL0
value|0
end_define

begin_comment
comment|/* 4716/47162 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4716_PROC_PLL_ON
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4716_PROC_HT_AVAIL
value|0x00000080
end_define

begin_comment
comment|/* 4716/4717/4718 Chip specific ChipControl register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL471X_I2S_PINS_ENABLE
value|0x0080
end_define

begin_comment
comment|/* I2S pins off by default, shared with pflash */
end_comment

begin_comment
comment|/* 5354 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_EXT_SWITCHER_PWM
value|0
end_define

begin_comment
comment|/* 0x00001 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_BB_SWITCHER_PWM
value|1
end_define

begin_comment
comment|/* 0x00002 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_BB_SWITCHER_BURST
value|2
end_define

begin_comment
comment|/* 0x00004 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_BB_EXT_SWITCHER_BURST
value|3
end_define

begin_comment
comment|/* 0x00008 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_ILP_REQUEST
value|4
end_define

begin_comment
comment|/* 0x00010 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_RADIO_SWITCHER_PWM
value|5
end_define

begin_comment
comment|/* 0x00020 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_RADIO_SWITCHER_BURST
value|6
end_define

begin_comment
comment|/* 0x00040 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_ROM_SWITCH
value|7
end_define

begin_comment
comment|/* 0x00080 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_PA_REF_LDO
value|8
end_define

begin_comment
comment|/* 0x00100 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_RADIO_LDO
value|9
end_define

begin_comment
comment|/* 0x00200 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_AFE_LDO
value|10
end_define

begin_comment
comment|/* 0x00400 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_PLL_LDO
value|11
end_define

begin_comment
comment|/* 0x00800 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_BG_FILTBYP
value|12
end_define

begin_comment
comment|/* 0x01000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_TX_FILTBYP
value|13
end_define

begin_comment
comment|/* 0x02000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_RX_FILTBYP
value|14
end_define

begin_comment
comment|/* 0x04000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_XTAL_PU
value|15
end_define

begin_comment
comment|/* 0x08000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_XTAL_EN
value|16
end_define

begin_comment
comment|/* 0x10000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_BB_PLL_FILTBYP
value|17
end_define

begin_comment
comment|/* 0x20000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_RF_PLL_FILTBYP
value|18
end_define

begin_comment
comment|/* 0x40000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES5354_BB_PLL_PU
value|19
end_define

begin_comment
comment|/* 0x80000 */
end_comment

begin_comment
comment|/* 5357 Chip specific ChipControl register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL5357_EXTPA
value|(1<<14)
end_define

begin_comment
comment|/* extPA in ChipControl 1, bit 14 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL5357_ANT_MUX_2o3
value|(1<<15)
end_define

begin_comment
comment|/* 2o3 in ChipControl 1, bit 15 */
end_comment

begin_comment
comment|/* 4328 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_EXT_SWITCHER_PWM
value|0
end_define

begin_comment
comment|/* 0x00001 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_BB_SWITCHER_PWM
value|1
end_define

begin_comment
comment|/* 0x00002 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_BB_SWITCHER_BURST
value|2
end_define

begin_comment
comment|/* 0x00004 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_BB_EXT_SWITCHER_BURST
value|3
end_define

begin_comment
comment|/* 0x00008 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_ILP_REQUEST
value|4
end_define

begin_comment
comment|/* 0x00010 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_RADIO_SWITCHER_PWM
value|5
end_define

begin_comment
comment|/* 0x00020 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_RADIO_SWITCHER_BURST
value|6
end_define

begin_comment
comment|/* 0x00040 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_ROM_SWITCH
value|7
end_define

begin_comment
comment|/* 0x00080 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_PA_REF_LDO
value|8
end_define

begin_comment
comment|/* 0x00100 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_RADIO_LDO
value|9
end_define

begin_comment
comment|/* 0x00200 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_AFE_LDO
value|10
end_define

begin_comment
comment|/* 0x00400 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_PLL_LDO
value|11
end_define

begin_comment
comment|/* 0x00800 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_BG_FILTBYP
value|12
end_define

begin_comment
comment|/* 0x01000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_TX_FILTBYP
value|13
end_define

begin_comment
comment|/* 0x02000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_RX_FILTBYP
value|14
end_define

begin_comment
comment|/* 0x04000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_XTAL_PU
value|15
end_define

begin_comment
comment|/* 0x08000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_XTAL_EN
value|16
end_define

begin_comment
comment|/* 0x10000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_BB_PLL_FILTBYP
value|17
end_define

begin_comment
comment|/* 0x20000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_RF_PLL_FILTBYP
value|18
end_define

begin_comment
comment|/* 0x40000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4328_BB_PLL_PU
value|19
end_define

begin_comment
comment|/* 0x80000 */
end_comment

begin_comment
comment|/* 4325 A0/A1 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_BUCK_BOOST_BURST
value|0
end_define

begin_comment
comment|/* 0x00000001 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_CBUCK_BURST
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_CBUCK_PWM
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_CLDO_CBUCK_BURST
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_CLDO_CBUCK_PWM
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_BUCK_BOOST_PWM
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_ABUCK_BURST
value|7
end_define

begin_comment
comment|/* 0x00000080 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_ABUCK_PWM
value|8
end_define

begin_comment
comment|/* 0x00000100 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_LNLDO1_PU
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_OTP_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_LNLDO3_PU
value|11
end_define

begin_comment
comment|/* 0x00000800 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_LNLDO4_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_XTAL_PU
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_ALP_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_RX_PWRSW_PU
value|15
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_TX_PWRSW_PU
value|16
end_define

begin_comment
comment|/* 0x00010000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_RFPLL_PWRSW_PU
value|17
end_define

begin_comment
comment|/* 0x00020000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_LOGEN_PWRSW_PU
value|18
end_define

begin_comment
comment|/* 0x00040000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_AFE_PWRSW_PU
value|19
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_BBPLL_PWRSW_PU
value|20
end_define

begin_comment
comment|/* 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325_HT_AVAIL
value|21
end_define

begin_comment
comment|/* 0x00200000 */
end_comment

begin_comment
comment|/* 4325 B0/C0 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325B0_CBUCK_LPOM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325B0_CBUCK_BURST
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325B0_CBUCK_PWM
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325B0_CLDO_PU
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_comment
comment|/* 4325 C1 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4325C1_LNLDO2_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_comment
comment|/* 4325 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4325_SPROM_OTP_SEL_MASK
value|CHIPC_CST_SPROM_OTP_SEL_R22_MASK
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4325_SPROM_OTP_SEL_SHIFT
value|CHIPC_CST_SPROM_OTP_SEL_R22_SHIFT
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4325_SDIO_USB_MODE_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4325_SDIO_USB_MODE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4325_RCAL_VALID_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4325_RCAL_VALID_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4325_RCAL_VALUE_MASK
value|0x000001f0
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4325_RCAL_VALUE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4325_PMUTOP_2B_MASK
value|0x00000200
end_define

begin_comment
comment|/* 1 for 2b, 0 for to 2a */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4325_PMUTOP_2B_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4329_RESERVED0
value|0
end_define

begin_comment
comment|/* 0x00000001 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_CBUCK_LPOM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_CBUCK_BURST
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_CBUCK_PWM
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_CLDO_PU
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_PALDO_PU
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_RESERVED7
value|7
end_define

begin_comment
comment|/* 0x00000080 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_RESERVED8
value|8
end_define

begin_comment
comment|/* 0x00000100 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_LNLDO1_PU
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_OTP_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_RESERVED11
value|11
end_define

begin_comment
comment|/* 0x00000800 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_LNLDO2_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_XTAL_PU
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_ALP_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_RX_PWRSW_PU
value|15
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_TX_PWRSW_PU
value|16
end_define

begin_comment
comment|/* 0x00010000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_RFPLL_PWRSW_PU
value|17
end_define

begin_comment
comment|/* 0x00020000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_LOGEN_PWRSW_PU
value|18
end_define

begin_comment
comment|/* 0x00040000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_AFE_PWRSW_PU
value|19
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_BBPLL_PWRSW_PU
value|20
end_define

begin_comment
comment|/* 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4329_HT_AVAIL
value|21
end_define

begin_comment
comment|/* 0x00200000 */
end_comment

begin_comment
comment|/* 4329 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4329_SPROM_OTP_SEL_MASK
value|CHIPC_CST_SPROM_OTP_SEL_R22_MASK
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4329_SPROM_OTP_SEL_SHIFT
value|CHIPC_CST_SPROM_OTP_SEL_R22_SHIFT
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4329_SPI_SDIO_MODE_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4329_SPI_SDIO_MODE_SHIFT
value|2
end_define

begin_comment
comment|/* 4312 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4312_SPROM_OTP_SEL_MASK
value|CHIPC_CST_SPROM_OTP_SEL_R22_MASK
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4312_SPROM_OTP_SEL_SHIFT
value|CHIPC_CST_SPROM_OTP_SEL_R22_SHIFT
end_define

begin_comment
comment|/* 4312 resources (all PMU chips with little memory constraint) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_SWITCHER_BURST
value|0
end_define

begin_comment
comment|/* 0x00000001 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_SWITCHER_PWM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_PA_REF_LDO
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_CORE_LDO_BURST
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_CORE_LDO_PWM
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_RADIO_LDO
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_BG_FILTBYP
value|7
end_define

begin_comment
comment|/* 0x00000080 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_TX_FILTBYP
value|8
end_define

begin_comment
comment|/* 0x00000100 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_RX_FILTBYP
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_XTAL_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_ALP_AVAIL
value|11
end_define

begin_comment
comment|/* 0x00000800 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_BB_PLL_FILTBYP
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_RF_PLL_FILTBYP
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4312_HT_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_comment
comment|/* 4322 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4322_RF_LDO
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4322_ILP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4322_XTAL_PU
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4322_ALP_AVAIL
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4322_SI_PLL_ON
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4322_HT_SI_AVAIL
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4322_PHY_PLL_ON
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4322_HT_PHY_AVAIL
value|7
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4322_OTP_PU
value|8
end_define

begin_comment
comment|/* 4322 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_XTAL_FREQ_20_40MHZ
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_SPROM_OTP_SEL_MASK
value|CHIPC_CST_SPROM_OTP_SEL_R23_MASK
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_SPROM_OTP_SEL_SHIFT
value|CHIPC_CST_SPROM_OTP_SEL_R23_SHIFT
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_PCI_OR_USB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_BOOT_MASK
value|0x00000600
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_BOOT_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_BOOT_FROM_SRAM
value|0
end_define

begin_comment
comment|/* boot from SRAM, ARM in reset */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_BOOT_FROM_ROM
value|1
end_define

begin_comment
comment|/* boot from ROM */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_BOOT_FROM_FLASH
value|2
end_define

begin_comment
comment|/* boot from FLASH */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_BOOT_FROM_INVALID
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_ILP_DIV_EN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_FLASH_TYPE_MASK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_FLASH_TYPE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_FLASH_TYPE_SHIFT_ST
value|0
end_define

begin_comment
comment|/* ST serial FLASH */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_FLASH_TYPE_SHIFT_ATMEL
value|1
end_define

begin_comment
comment|/* ATMEL flash */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_ARM_TAP_SEL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_RES_INIT_MODE_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_RES_INIT_MODE_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_RES_INIT_MODE_ILPAVAIL
value|0
end_define

begin_comment
comment|/* resinitmode: ILP available */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_RES_INIT_MODE_ILPREQ
value|1
end_define

begin_comment
comment|/* resinitmode: ILP request */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_RES_INIT_MODE_ALPAVAIL
value|2
end_define

begin_comment
comment|/* resinitmode: ALP available */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_RES_INIT_MODE_HTAVAIL
value|3
end_define

begin_comment
comment|/* resinitmode: HT available */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4322_PCIPLLCLK_GATING
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_CLK_SWITCH_PCI_TO_ALP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4322_PCI_CARDBUS_MODE
value|0x00040000
end_define

begin_comment
comment|/* 43224 chip-specific ChipControl register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL43224_GPIO_TOGGLE
value|0x8000
end_define

begin_define
define|#
directive|define
name|CHIPC_CCTRL_43224A0_12MA_LED_DRIVE
value|0x00F000F0
end_define

begin_comment
comment|/* 12 mA drive strength */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL_43224B0_12MA_LED_DRIVE
value|0xF0
end_define

begin_comment
comment|/* 12 mA drive strength for later 43224s */
end_comment

begin_comment
comment|/* 43236 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES43236_REGULATOR
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43236_ILP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43236_XTAL_PU
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43236_ALP_AVAIL
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43236_SI_PLL_ON
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43236_HT_SI_AVAIL
value|5
end_define

begin_comment
comment|/* 43236 chip-specific ChipControl register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL43236_BT_COEXIST
value|(1<<0)
end_define

begin_comment
comment|/* 0 disable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL43236_SECI
value|(1<<1)
end_define

begin_comment
comment|/* 0 SECI is disabled (JATG functional) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL43236_EXT_LNA
value|(1<<2)
end_define

begin_comment
comment|/* 0 disable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL43236_ANT_MUX_2o3
value|(1<<3)
end_define

begin_comment
comment|/* 2o3 mux, chipcontrol bit 3 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL43236_GSIO
value|(1<<4)
end_define

begin_comment
comment|/* 0 disable */
end_comment

begin_comment
comment|/* 43236 Chip specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST43236_SFLASH_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43236_OTP_SEL_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43236_OTP_SEL_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43236_HSIC_MASK
value|0x00000100
end_define

begin_comment
comment|/* USB/HSIC */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST43236_BP_CLK
value|0x00000200
end_define

begin_comment
comment|/* 120/96Mbps */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST43236_BOOT_MASK
value|0x00001800
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43236_BOOT_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43236_BOOT_FROM_SRAM
value|0
end_define

begin_comment
comment|/* boot from SRAM, ARM in reset */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST43236_BOOT_FROM_ROM
value|1
end_define

begin_comment
comment|/* boot from ROM */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST43236_BOOT_FROM_FLASH
value|2
end_define

begin_comment
comment|/* boot from FLASH */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST43236_BOOT_FROM_INVALID
value|3
end_define

begin_comment
comment|/* 4331 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4331_REGULATOR
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4331_ILP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4331_XTAL_PU
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4331_ALP_AVAIL
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4331_SI_PLL_ON
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4331_HT_SI_AVAIL
value|5
end_define

begin_comment
comment|/* 4331 chip-specific ChipControl register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_BT_COEXIST
value|(1<<0)
end_define

begin_comment
comment|/* 0 disable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_SECI
value|(1<<1)
end_define

begin_comment
comment|/* 0 SECI is disabled (JATG functional) */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_EXT_LNA
value|(1<<2)
end_define

begin_comment
comment|/* 0 disable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_SPROM_GPIO13_15
value|(1<<3)
end_define

begin_comment
comment|/* sprom/gpio13-15 mux */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_EXTPA_EN
value|(1<<4)
end_define

begin_comment
comment|/* 0 ext pa disable, 1 ext pa enabled */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_GPIOCLK_ON_SPROMCS
value|(1<<5)
end_define

begin_comment
comment|/* set drive out GPIO_CLK on sprom_cs pin */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_PCIE_MDIO_ON_SPROMCS
value|(1<<6)
end_define

begin_comment
comment|/* use sprom_cs pin as PCIE mdio interface */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_EXTPA_ON_GPIO2_5
value|(1<<7)
end_define

begin_comment
comment|/* aband extpa will be at gpio2/5 and sprom_dout */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_OVR_PIPEAUXCLKEN
value|(1<<8)
end_define

begin_comment
comment|/* override core control on pipe_AuxClkEnable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_OVR_PIPEAUXPWRDOWN
value|(1<<9)
end_define

begin_comment
comment|/* override core control on pipe_AuxPowerDown */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_PCIE_AUXCLKEN
value|(1<<10)
end_define

begin_comment
comment|/* pcie_auxclkenable */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_PCIE_PIPE_PLLDOWN
value|(1<<11)
end_define

begin_comment
comment|/* pcie_pipe_pllpowerdown */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_EXTPA_EN2
value|(1<<12)
end_define

begin_comment
comment|/* 0 ext pa2 disable, 1 ext pa2 enabled */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_BT_SHD0_ON_GPIO4
value|(1<<16)
end_define

begin_comment
comment|/* enable bt_shd0 at gpio4 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL4331_BT_SHD1_ON_GPIO5
value|(1<<17)
end_define

begin_comment
comment|/* enable bt_shd1 at gpio5 */
end_comment

begin_comment
comment|/* 4331 Chip specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4331_XTAL_FREQ
value|0x00000001
end_define

begin_comment
comment|/* crystal frequency 20/40Mhz */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4331_SPROM_PRESENT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4331_OTP_PRESENT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4331_LDO_RF
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4331_LDO_PAR
value|0x00000010
end_define

begin_comment
comment|/* 4315 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_CBUCK_LPOM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_CBUCK_BURST
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_CBUCK_PWM
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_CLDO_PU
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_PALDO_PU
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_LNLDO1_PU
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_OTP_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_LNLDO2_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_XTAL_PU
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_ALP_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_RX_PWRSW_PU
value|15
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_TX_PWRSW_PU
value|16
end_define

begin_comment
comment|/* 0x00010000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_RFPLL_PWRSW_PU
value|17
end_define

begin_comment
comment|/* 0x00020000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_LOGEN_PWRSW_PU
value|18
end_define

begin_comment
comment|/* 0x00040000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_AFE_PWRSW_PU
value|19
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_BBPLL_PWRSW_PU
value|20
end_define

begin_comment
comment|/* 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4315_HT_AVAIL
value|21
end_define

begin_comment
comment|/* 0x00200000 */
end_comment

begin_comment
comment|/* 4315 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4315_SPROM_OTP_SEL_MASK
value|CHIPC_CST_SPROM_OTP_SEL_R22_MASK
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4315_SPROM_OTP_SEL_SHIFT
value|CHIPC_CST_SPROM_OTP_SEL_R22_SHIFT
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4315_SDIO_MODE
value|0x00000004
end_define

begin_comment
comment|/* gpio [8], sdio/usb mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4315_RCAL_VALID
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4315_RCAL_VALUE_MASK
value|0x000001f0
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4315_RCAL_VALUE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4315_PALDO_EXTPNP
value|0x00000200
end_define

begin_comment
comment|/* PALDO is configured with external PNP */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4315_CBUCK_MODE_MASK
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4315_CBUCK_MODE_BURST
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4315_CBUCK_MODE_LPBURST
value|0x00000c00
end_define

begin_comment
comment|/* 4319 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_CBUCK_LPOM
value|1
end_define

begin_comment
comment|/* 0x00000002 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_CBUCK_BURST
value|2
end_define

begin_comment
comment|/* 0x00000004 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_CBUCK_PWM
value|3
end_define

begin_comment
comment|/* 0x00000008 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_CLDO_PU
value|4
end_define

begin_comment
comment|/* 0x00000010 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_PALDO_PU
value|5
end_define

begin_comment
comment|/* 0x00000020 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_ILP_REQUEST
value|6
end_define

begin_comment
comment|/* 0x00000040 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_LNLDO1_PU
value|9
end_define

begin_comment
comment|/* 0x00000200 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_OTP_PU
value|10
end_define

begin_comment
comment|/* 0x00000400 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_LNLDO2_PU
value|12
end_define

begin_comment
comment|/* 0x00001000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_XTAL_PU
value|13
end_define

begin_comment
comment|/* 0x00002000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_ALP_AVAIL
value|14
end_define

begin_comment
comment|/* 0x00004000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_RX_PWRSW_PU
value|15
end_define

begin_comment
comment|/* 0x00008000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_TX_PWRSW_PU
value|16
end_define

begin_comment
comment|/* 0x00010000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_RFPLL_PWRSW_PU
value|17
end_define

begin_comment
comment|/* 0x00020000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_LOGEN_PWRSW_PU
value|18
end_define

begin_comment
comment|/* 0x00040000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_AFE_PWRSW_PU
value|19
end_define

begin_comment
comment|/* 0x00080000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_BBPLL_PWRSW_PU
value|20
end_define

begin_comment
comment|/* 0x00100000 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4319_HT_AVAIL
value|21
end_define

begin_comment
comment|/* 0x00200000 */
end_comment

begin_comment
comment|/* 4319 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4319_SPI_CPULESSUSB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_SPI_CLK_POL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_SPI_CLK_PH
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_SPROM_OTP_SEL_MASK
value|CHIPC_CST_SPROM_OTP_SEL_R23_MASK
end_define

begin_comment
comment|/* gpio [7:6], SDIO CIS selection */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4319_SPROM_OTP_SEL_SHIFT
value|CHIPC_CST_SPROM_OTP_SEL_R23_SHIFT
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_SDIO_USB_MODE
value|0x00000100
end_define

begin_comment
comment|/* gpio [8], sdio/usb mode */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4319_REMAP_SEL_MASK
value|0x00000600
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_ILPDIV_EN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_XTAL_PD_POL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_LPO_SEL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_RES_INIT_MODE
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_PALDO_EXTPNP
value|0x00010000
end_define

begin_comment
comment|/* PALDO is configured with external PNP */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4319_CBUCK_MODE_MASK
value|0x00060000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_CBUCK_MODE_BURST
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_CBUCK_MODE_LPBURST
value|0x00060000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_RCAL_VALID
value|0x01000000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_RCAL_VALUE_MASK
value|0x3e000000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4319_RCAL_VALUE_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_CHIPCTL0
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_CHIPCTL1
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_PMU1_PLL0_CHIPCTL2
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_CCTL_4319USB_XTAL_SEL_MASK
value|0x00180000
end_define

begin_define
define|#
directive|define
name|CHIPC_CCTL_4319USB_XTAL_SEL_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|CHIPC_CCTL_4319USB_48MHZ_PLL_SEL
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_CCTL_4319USB_24MHZ_PLL_SEL
value|2
end_define

begin_comment
comment|/* PMU resources for 4336 */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4336_CBUCK_LPOM
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_CBUCK_BURST
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_CBUCK_LP_PWM
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_CBUCK_PWM
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_CLDO_PU
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_DIS_INT_RESET_PD
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_ILP_REQUEST
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_LNLDO_PU
value|7
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_LDO3P3_PU
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_OTP_PU
value|9
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_XTAL_PU
value|10
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_ALP_AVAIL
value|11
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_RADIO_PU
value|12
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_BG_PU
value|13
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_VREG1p4_PU_PU
value|14
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_AFE_PWRSW_PU
value|15
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_RX_PWRSW_PU
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_TX_PWRSW_PU
value|17
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_BB_PWRSW_PU
value|18
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_SYNTH_PWRSW_PU
value|19
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_MISC_PWRSW_PU
value|20
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_LOGEN_PWRSW_PU
value|21
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_BBPLL_PWRSW_PU
value|22
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_MACPHY_CLKAVAIL
value|23
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_HT_AVAIL
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4336_RSVD
value|25
end_define

begin_comment
comment|/* 4336 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4336_SPI_MODE_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_SPROM_PRESENT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_OTP_PRESENT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_ARMREMAP_0
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_ILPDIV_EN_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_ILPDIV_EN_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_XTAL_PD_POL_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_XTAL_PD_POL_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_LPO_SEL_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_LPO_SEL_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_RES_INIT_MODE_MASK
value|0x00000180
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_RES_INIT_MODE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_CBUCK_MODE_MASK
value|0x00000600
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4336_CBUCK_MODE_SHIFT
value|9
end_define

begin_comment
comment|/* 4330 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4330_CBUCK_LPOM
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_CBUCK_BURST
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_CBUCK_LP_PWM
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_CBUCK_PWM
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_CLDO_PU
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_DIS_INT_RESET_PD
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_ILP_REQUEST
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_LNLDO_PU
value|7
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_LDO3P3_PU
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_OTP_PU
value|9
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_XTAL_PU
value|10
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_ALP_AVAIL
value|11
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_RADIO_PU
value|12
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_BG_PU
value|13
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_VREG1p4_PU_PU
value|14
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_AFE_PWRSW_PU
value|15
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_RX_PWRSW_PU
value|16
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_TX_PWRSW_PU
value|17
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_BB_PWRSW_PU
value|18
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_SYNTH_PWRSW_PU
value|19
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_MISC_PWRSW_PU
value|20
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_LOGEN_PWRSW_PU
value|21
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_BBPLL_PWRSW_PU
value|22
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_MACPHY_CLKAVAIL
value|23
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_HT_AVAIL
value|24
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_5gRX_PWRSW_PU
value|25
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_5gTX_PWRSW_PU
value|26
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4330_5g_LOGEN_PWRSW_PU
value|27
end_define

begin_comment
comment|/* 4330 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4330_CHIPMODE_SDIOD
parameter_list|(
name|cs
parameter_list|)
value|(((cs)& 0x7)< 6)
end_define

begin_comment
comment|/* SDIO || gSPI */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4330_CHIPMODE_USB20D
parameter_list|(
name|cs
parameter_list|)
value|(((cs)& 0x7)>= 6)
end_define

begin_comment
comment|/* USB || USBDA */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4330_CHIPMODE_SDIO
parameter_list|(
name|cs
parameter_list|)
value|(((cs)& 0x4) == 0)
end_define

begin_comment
comment|/* SDIO */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4330_CHIPMODE_GSPI
parameter_list|(
name|cs
parameter_list|)
value|(((cs)& 0x6) == 4)
end_define

begin_comment
comment|/* gSPI */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4330_CHIPMODE_USB
parameter_list|(
name|cs
parameter_list|)
value|(((cs)& 0x7) == 6)
end_define

begin_comment
comment|/* USB packet-oriented */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4330_CHIPMODE_USBDA
parameter_list|(
name|cs
parameter_list|)
value|(((cs)& 0x7) == 7)
end_define

begin_comment
comment|/* USB Direct Access */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4330_OTP_PRESENT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_LPO_AUTODET_EN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_ARMREMAP_0
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_SPROM_PRESENT
value|0x00000080
end_define

begin_comment
comment|/* takes priority over OTP if both set */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4330_ILPDIV_EN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_LPO_SEL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_RES_INIT_MODE_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_RES_INIT_MODE_MASK
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_CBUCK_MODE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_CBUCK_MODE_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_CBUCK_POWER_OK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4330_BB_PLL_LOCKED
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CHIPC_SOCDEVRAM_4330_BP_ADDR
value|0x1E000000
end_define

begin_define
define|#
directive|define
name|CHIPC_SOCDEVRAM_4330_ARM_ADDR
value|0x00800000
end_define

begin_comment
comment|/* 4313 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES4313_BB_PU_RSRC
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_ILP_REQ_RSRC
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_XTAL_PU_RSRC
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_ALP_AVAIL_RSRC
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_RADIO_PU_RSRC
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_BG_PU_RSRC
value|5
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_VREG1P4_PU_RSRC
value|6
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_AFE_PWRSW_RSRC
value|7
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_RX_PWRSW_RSRC
value|8
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_TX_PWRSW_RSRC
value|9
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_BB_PWRSW_RSRC
value|10
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_SYNTH_PWRSW_RSRC
value|11
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_MISC_PWRSW_RSRC
value|12
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_BB_PLL_PWRSW_RSRC
value|13
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_HT_AVAIL_RSRC
value|14
end_define

begin_define
define|#
directive|define
name|CHIPC_RES4313_MACPHY_CLK_AVAIL_RSRC
value|15
end_define

begin_comment
comment|/* 4313 chip-specific ChipStatus register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST4313_SPROM_PRESENT
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4313_OTP_PRESENT
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4313_SPROM_OTP_SEL_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CHIPC_CST4313_SPROM_OTP_SEL_SHIFT
value|0
end_define

begin_comment
comment|/* 4313 Chip specific ChipControl register bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CCTRL_4313_12MA_LED_DRIVE
value|0x00000007
end_define

begin_comment
comment|/* 12 mA drive strengh for later 4313 */
end_comment

begin_comment
comment|/* 43228 resources */
end_comment

begin_define
define|#
directive|define
name|CHIPC_RES43228_NOT_USED
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43228_ILP_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43228_XTAL_PU
value|2
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43228_ALP_AVAIL
value|3
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43228_PLL_EN
value|4
end_define

begin_define
define|#
directive|define
name|CHIPC_RES43228_HT_PHY_AVAIL
value|5
end_define

begin_comment
comment|/* 43228 chipstatus  reg bits */
end_comment

begin_define
define|#
directive|define
name|CHIPC_CST43228_ILP_DIV_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43228_OTP_PRESENT
value|0x2
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43228_SERDES_REFCLK_PADSEL
value|0x4
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43228_SDIO_MODE
value|0x8
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43228_SDIO_OTP_PRESENT
value|0x10
end_define

begin_define
define|#
directive|define
name|CHIPC_CST43228_SDIO_RESET
value|0x20
end_define

begin_comment
comment|/* * Maximum delay for the PMU state transition in us. * This is an upper bound intended for spinwaits etc. */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMU_MAX_TRANSITION_DLY
value|15000
end_define

begin_comment
comment|/* PMU resource up transition time in ILP cycles */
end_comment

begin_define
define|#
directive|define
name|CHIPC_PMURES_UP_TRANSITION
value|2
end_define

begin_comment
comment|/* * Register eci_inputlo bitfield values. * - BT packet type information bits [7:0] */
end_comment

begin_comment
comment|/*  [3:0] - Task (link) type */
end_comment

begin_define
define|#
directive|define
name|CHIPC_BT_ACL
value|0x00
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_SCO
value|0x01
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_eSCO
value|0x02
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_A2DP
value|0x03
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_SNIFF
value|0x04
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_PAGE_SCAN
value|0x05
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_INQUIRY_SCAN
value|0x06
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_PAGE
value|0x07
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_INQUIRY
value|0x08
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_MSS
value|0x09
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_PARK
value|0x0a
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_RSSISCAN
value|0x0b
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_MD_ACL
value|0x0c
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_MD_eSCO
value|0x0d
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_SCAN_WITH_SCO_LINK
value|0x0e
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_SCAN_WITHOUT_SCO_LINK
value|0x0f
end_define

begin_comment
comment|/* [7:4] = packet duration code */
end_comment

begin_comment
comment|/* [8] - Master / Slave */
end_comment

begin_define
define|#
directive|define
name|CHIPC_BT_MASTER
value|0
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_SLAVE
value|1
end_define

begin_comment
comment|/* [11:9] - multi-level priority */
end_comment

begin_define
define|#
directive|define
name|CHIPC_BT_LOWEST_PRIO
value|0x0
end_define

begin_define
define|#
directive|define
name|CHIPC_BT_HIGHEST_PRIO
value|0x3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_CHIPC_CHIPCREG_H_ */
end_comment

end_unit

