begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  * All rights reserved.  *  * This file is derived from the hndsoc.h, pci_core.h, and pcie_core.h headers  * distributed with Broadcom's initial brcm80211 Linux driver release, as  * contributed to the Linux staging repository.  *   * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PCI_BHND_PCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PCI_BHND_PCIREG_H_
end_define

begin_comment
comment|/*  * PCI/PCIe-Gen1 DMA Constants  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_DMA32_TRANSLATION
value|0x40000000
end_define

begin_comment
comment|/**< PCI DMA32 address translation (sbtopci2) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_DMA32_MASK
value|BHND_PCI_SBTOPCI2_MASK
end_define

begin_comment
comment|/**< PCI DMA32 translation mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DMA32_TRANSLATION
value|0x80000000
end_define

begin_comment
comment|/**< PCIe-Gen1 DMA32 address translation (sb2pcitranslation2) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DMA32_MASK
value|BHND_PCIE_SBTOPCI2_MASK
end_define

begin_comment
comment|/**< PCIe-Gen1 DMA32 translation mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DMA64_TRANSLATION
value|_BHND_PCIE_DMA64(TRANSLATION)
end_define

begin_comment
comment|/**< PCIe-Gen1 DMA64 address translation (sb2pcitranslation2) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DMA64_MASK
value|_BHND_PCIE_DMA64(MASK)
end_define

begin_comment
comment|/**< PCIe-Gen1 DMA64 translation mask */
end_comment

begin_define
define|#
directive|define
name|_BHND_PCIE_DMA64
parameter_list|(
name|_x
parameter_list|)
value|((uint64_t)BHND_PCIE_DMA32_ ## _x<< 32)
end_define

begin_comment
comment|/*  * PCI Core Registers  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CTL
value|0x000
end_define

begin_comment
comment|/**< PCI core control*/
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_CTL
value|0x010
end_define

begin_comment
comment|/**< PCI arbiter control */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CLKRUN_CTL
value|0x014
end_define

begin_comment
comment|/**< PCI clckrun control (>= rev11) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_INTR_STATUS
value|0x020
end_define

begin_comment
comment|/**< Interrupt status */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_INTR_MASK
value|0x024
end_define

begin_comment
comment|/**< Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX
value|0x028
end_define

begin_comment
comment|/**< Sonics to PCI mailbox */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_BCAST_ADDR
value|0x050
end_define

begin_comment
comment|/**< Sonics broadcast address (pci) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_BCAST_DATA
value|0x054
end_define

begin_comment
comment|/**< Sonics broadcast data (pci) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_GPIO_IN
value|0x060
end_define

begin_comment
comment|/**< GPIO input (>= rev2) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_GPIO_OUT
value|0x064
end_define

begin_comment
comment|/**< GPIO output (>= rev2) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_GPIO_EN
value|0x068
end_define

begin_comment
comment|/**< GPIO output enable (>= rev2) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_GPIO_CTL
value|0x06C
end_define

begin_comment
comment|/**< GPIO control (>= rev2) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI0
value|0x100
end_define

begin_comment
comment|/**< Sonics to PCI translation 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI1
value|0x104
end_define

begin_comment
comment|/**< Sonics to PCI translation 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI2
value|0x108
end_define

begin_comment
comment|/**< Sonics to PCI translation 2 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_FUNC0_CFG
value|0x400
end_define

begin_comment
comment|/**< PCI function 0 cfg space (>= rev8) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_FUNC1_CFG
value|0x500
end_define

begin_comment
comment|/**< PCI function 1 cfg space (>= rev8) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_FUNC2_CFG
value|0x600
end_define

begin_comment
comment|/**< PCI function 2 cfg space (>= rev8) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_FUNC3_CFG
value|0x700
end_define

begin_comment
comment|/**< PCI function 3 cfg space (>= rev8) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SPROM_SHADOW
value|0x800
end_define

begin_comment
comment|/**< PCI SPROM shadow */
end_comment

begin_comment
comment|/* BHND_PCI_CTL */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CTL_RST_OE
value|0x01
end_define

begin_comment
comment|/* When set, drives PCI_RESET out to pin */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CTL_RST
value|0x02
end_define

begin_comment
comment|/* Value driven out to pin */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CTL_CLK_OE
value|0x04
end_define

begin_comment
comment|/* When set, drives clock as gated by PCI_CLK out to pin */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CTL_CLK
value|0x08
end_define

begin_comment
comment|/* Gate for clock driven out to pin */
end_comment

begin_comment
comment|/* BHND_PCI_ARB_CTL */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_INT
value|0x01
end_define

begin_comment
comment|/* When set, use an internal arbiter */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_EXT
value|0x02
end_define

begin_comment
comment|/* When set, use an external arbiter */
end_comment

begin_comment
comment|/* BHND_PCI_ARB_CTL - ParkID (>= rev8) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_MASK
value|0x1c
end_define

begin_comment
comment|/* Selects which agent is parked on an idle bus */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_EXT0
value|0
end_define

begin_comment
comment|/* External master 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_EXT1
value|1
end_define

begin_comment
comment|/* External master 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_EXT2
value|2
end_define

begin_comment
comment|/* External master 2 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_EXT3
value|3
end_define

begin_comment
comment|/* External master 3 (rev>= 11) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_INT_r10
value|3
end_define

begin_comment
comment|/* Internal master (rev< 11) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_INT_r11
value|4
end_define

begin_comment
comment|/* Internal master (rev>= 11) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_LAST_r10
value|4
end_define

begin_comment
comment|/* Last active master (rev< 11) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_ARB_PARKID_LAST_r11
value|5
end_define

begin_comment
comment|/* Last active master (rev>= 11) */
end_comment

begin_comment
comment|/* BHND_PCI_CLKRUN_CTL */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_CLKRUN_DSBL
value|0x8000
end_define

begin_comment
comment|/* Bit 15 forceClkrun */
end_comment

begin_comment
comment|/* BHND_PCI_INTR_STATUS / BHND_PCI_INTR_MASK */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_INTR_A
value|0x01
end_define

begin_comment
comment|/* PCI INTA# is asserted */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_INTR_B
value|0x02
end_define

begin_comment
comment|/* PCI INTB# is asserted */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_INTR_SERR
value|0x04
end_define

begin_comment
comment|/* PCI SERR# has been asserted (write one to clear) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_INTR_PERR
value|0x08
end_define

begin_comment
comment|/* PCI PERR# has been asserted (write one to clear) */
end_comment

begin_comment
comment|/* BHND_PCI_SBTOPCI_MBOX  * (General) PCI/SB mailbox interrupts, two bits per pci function */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX_F0_0
value|0x100
end_define

begin_comment
comment|/* function 0, int 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX_F0_1
value|0x200
end_define

begin_comment
comment|/* function 0, int 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX_F1_0
value|0x400
end_define

begin_comment
comment|/* function 1, int 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX_F1_1
value|0x800
end_define

begin_comment
comment|/* function 1, int 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX_F2_0
value|0x1000
end_define

begin_comment
comment|/* function 2, int 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX_F2_1
value|0x2000
end_define

begin_comment
comment|/* function 2, int 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX_F3_0
value|0x4000
end_define

begin_comment
comment|/* function 3, int 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MBOX_F3_1
value|0x8000
end_define

begin_comment
comment|/* function 3, int 1 */
end_comment

begin_comment
comment|/* BHND_PCI_BCAST_ADDR */
end_comment

begin_define
define|#
directive|define
name|BHNC_PCI_BCAST_ADDR_MASK
value|0xFF
end_define

begin_comment
comment|/* Broadcast register address */
end_comment

begin_comment
comment|/* Sonics to PCI translation types */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI0_MASK
value|0xfc000000
end_define

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI1_MASK
value|0xfc000000
end_define

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI2_MASK
value|0xc0000000
end_define

begin_comment
comment|/* Access type bits (0:1) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_MEM
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_IO
value|1
end_define

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_CFG0
value|2
end_define

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_CFG1
value|3
end_define

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_PREF
value|0x4
end_define

begin_comment
comment|/* prefetch enable */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_BURST
value|0x8
end_define

begin_comment
comment|/* burst enable */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_RC_MASK
value|0x30
end_define

begin_comment
comment|/* read command (>= rev11) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_RC_READ
value|0x00
end_define

begin_comment
comment|/* memory read */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_RC_READLINE
value|0x10
end_define

begin_comment
comment|/* memory read line */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SBTOPCI_RC_READMULTI
value|0x20
end_define

begin_comment
comment|/* memory read multiple */
end_comment

begin_comment
comment|/* PCI core index in SROM shadow area */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SRSH_PI_OFFSET
value|0
end_define

begin_comment
comment|/* first word */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SRSH_PI_MASK
value|0xf000
end_define

begin_comment
comment|/* bit 15:12 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCI_SRSH_PI_SHIFT
value|12
end_define

begin_comment
comment|/* bit 15:12 */
end_comment

begin_comment
comment|/*  * PCIe-Gen1 Core Registers  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_CTL
value|BHND_PCI_CTL
end_define

begin_comment
comment|/**< PCI core control*/
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_BIST_STATUS
value|0x00C
end_define

begin_comment
comment|/**< BIST status */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_GPIO_SEL
value|0x010
end_define

begin_comment
comment|/**< GPIO select */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_GPIO_OUT_EN
value|0x014
end_define

begin_comment
comment|/**< GPIO output enable */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_INTR_STATUS
value|BHND_PCI_INTR_STATUS
end_define

begin_comment
comment|/**< Interrupt status */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_INTR_MASK
value|BHND_PCI_INTR_MASK
end_define

begin_comment
comment|/**< Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI_MBOX
value|BHND_PCI_SBTOPCI_MBOX
end_define

begin_comment
comment|/**< Sonics to PCI mailbox */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI0
value|BHND_PCI_SBTOPCI0
end_define

begin_comment
comment|/**< Sonics to PCI translation 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI1
value|BHND_PCI_SBTOPCI1
end_define

begin_comment
comment|/**< Sonics to PCI translation 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI2
value|BHND_PCI_SBTOPCI2
end_define

begin_comment
comment|/**< Sonics to PCI translation 2 */
end_comment

begin_comment
comment|/* indirect pci config space access */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_CFG_ADDR
value|0x120
end_define

begin_comment
comment|/**< pcie config space address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_CFG_DATA
value|0x124
end_define

begin_comment
comment|/**< pcie config space data */
end_comment

begin_comment
comment|/* mdio register access */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIO_CTL
value|0x128
end_define

begin_comment
comment|/**< mdio control */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIO_DATA
value|0x12C
end_define

begin_comment
comment|/**< mdio data */
end_comment

begin_comment
comment|/* indirect protocol phy/dllp/tlp register access */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_IND_ADDR
value|0x130
end_define

begin_comment
comment|/**< internal protocol register address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_IND_DATA
value|0x134
end_define

begin_comment
comment|/**< internal protocol register data */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_CLKREQEN_CTL
value|0x138
end_define

begin_comment
comment|/**< clkreq rdma control */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_FUNC0_CFG
value|BHND_PCI_FUNC0_CFG
end_define

begin_comment
comment|/**< PCI function 0 cfg space */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_FUNC1_CFG
value|BHND_PCI_FUNC1_CFG
end_define

begin_comment
comment|/**< PCI function 1 cfg space */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_FUNC2_CFG
value|BHND_PCI_FUNC2_CFG
end_define

begin_comment
comment|/**< PCI function 2 cfg space */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_FUNC3_CFG
value|BHND_PCI_FUNC3_CFG
end_define

begin_comment
comment|/**< PCI function 3 cfg space */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SPROM_SHADOW
value|BHND_PCI_SPROM_SHADOW
end_define

begin_comment
comment|/**< PCI SPROM shadow */
end_comment

begin_comment
comment|/* BHND_PCIE_CTL */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_CTL_RST_OE
value|BHND_PCI_CTL_RST_OE
end_define

begin_comment
comment|/* When set, drives PCI_RESET out to pin */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_CTL_RST
value|BHND_PCI_CTL_RST_OE
end_define

begin_comment
comment|/* Value driven out to pin */
end_comment

begin_comment
comment|/* BHND_PCI_INTR_STATUS / BHND_PCI_INTR_MASK */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_INTR_A
value|BHND_PCI_INTR_A
end_define

begin_comment
comment|/* PCIE INTA message is received */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_INTR_B
value|BHND_PCI_INTR_B
end_define

begin_comment
comment|/* PCIE INTB message is received */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_INTR_FATAL
value|0x04
end_define

begin_comment
comment|/* PCIE INTFATAL message is received */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_INTR_NFATAL
value|0x08
end_define

begin_comment
comment|/* PCIE INTNONFATAL message is received */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_INTR_CORR
value|0x10
end_define

begin_comment
comment|/* PCIE INTCORR message is received */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_INTR_PME
value|0x20
end_define

begin_comment
comment|/* PCIE INTPME message is received */
end_comment

begin_comment
comment|/* SB to PCIE translation masks */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI0_MASK
value|BHND_PCI_SBTOPCI0_MASK
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI1_MASK
value|BHND_PCI_SBTOPCI1_MASK
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI2_MASK
value|BHND_PCI_SBTOPCI2_MASK
end_define

begin_comment
comment|/* Access type bits (0:1) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI_MEM
value|BHND_PCI_SBTOPCI_MEM
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI_IO
value|BHND_PCI_SBTOPCI_IO
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI_CFG0
value|BHND_PCI_SBTOPCI_CFG0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI_CFG1
value|BHND_PCI_SBTOPCI_CFG1
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI_PREF
value|BHND_PCI_SBTOPCI_PREF
end_define

begin_comment
comment|/* prefetch enable */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SBTOPCI_BURST
value|BHND_PCI_SBTOPCI_BURST
end_define

begin_comment
comment|/* burst enable */
end_comment

begin_comment
comment|/* BHND_PCIE_CFG_ADDR / BHND_PCIE_CFG_DATA */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_CFG_ADDR_FUNC_MASK
value|0x7000
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_CFG_ADDR_FUNC_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_CFG_ADDR_REG_MASK
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_CFG_ADDR_REG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_CFG_OFFSET
parameter_list|(
name|f
parameter_list|,
name|r
parameter_list|)
define|\
value|((((f)& BHND_PCIE_CFG_ADDR_FUNC_MASK)<< BHND_PCIE_CFG_ADDR_FUNC_SHIFT) | \ 	(((r)& BHND_PCIE_CFG_ADDR_FUNC_SHIFT)<< BHND_PCIE_CFG_ADDR_REG_SHIFT))
end_define

begin_comment
comment|/* BHND_PCIE_MDIO_CTL control */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIOCTL_DIVISOR_MASK
value|0x7f
end_define

begin_comment
comment|/* clock divisor mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIOCTL_DIVISOR_VAL
value|0x2
end_define

begin_comment
comment|/* default clock divisor */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIOCTL_PREAM_EN
value|0x80
end_define

begin_comment
comment|/* enable preamble mode */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIOCTL_DONE
value|0x100
end_define

begin_comment
comment|/* tranaction completed */
end_comment

begin_comment
comment|/* PCIe BHND_PCIE_MDIO_DATA Data */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_PHYADDR_MASK
value|0x0f800000
end_define

begin_comment
comment|/* phy addr */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_PHYADDR_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_REGADDR_MASK
value|0x007c0000
end_define

begin_comment
comment|/* reg/dev addr */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_REGADDR_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_DATA_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* data  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_TA
value|0x00020000
end_define

begin_comment
comment|/* slave turnaround time */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_START
value|0x40000000
end_define

begin_comment
comment|/* start of transaction */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_CMD_WRITE
value|0x10000000
end_define

begin_comment
comment|/* write command */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_CMD_READ
value|0x20000000
end_define

begin_comment
comment|/* read command */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_MDIODATA_ADDR
parameter_list|(
name|_phyaddr
parameter_list|,
name|_regaddr
parameter_list|)
value|(		\ 	(((_phyaddr)<< BHND_PCIE_MDIODATA_PHYADDR_SHIFT)&		\ 	    BHND_PCIE_MDIODATA_PHYADDR_MASK) |				\ 	(((_regaddr)<< BHND_PCIE_MDIODATA_REGADDR_SHIFT)&		\ 	    BHND_PCIE_MDIODATA_REGADDR_MASK)				\ )
end_define

begin_comment
comment|/* PCIE protocol PHY diagnostic registers */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_MODEREG
value|0x200
end_define

begin_comment
comment|/* Mode */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_STATUSREG
value|0x204
end_define

begin_comment
comment|/* Status */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_LTSSMCTRLREG
value|0x208
end_define

begin_comment
comment|/* LTSSM control */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_LTLINKNUMREG
value|0x20c
end_define

begin_comment
comment|/* Link Training Link number */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_LTLANENUMREG
value|0x210
end_define

begin_comment
comment|/* Link Training Lane number */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_LTNFTSREG
value|0x214
end_define

begin_comment
comment|/* Link Training N_FTS */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_ATTNREG
value|0x218
end_define

begin_comment
comment|/* Attention */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_ATTNMASKREG
value|0x21C
end_define

begin_comment
comment|/* Attention Mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_RXERRCTR
value|0x220
end_define

begin_comment
comment|/* Rx Error */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_RXFRMERRCTR
value|0x224
end_define

begin_comment
comment|/* Rx Framing Error */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_RXERRTHRESHREG
value|0x228
end_define

begin_comment
comment|/* Rx Error threshold */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_TESTCTRLREG
value|0x22C
end_define

begin_comment
comment|/* Test Control reg */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_SERDESCTRLOVRDREG
value|0x230
end_define

begin_comment
comment|/* SERDES Control Override */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_TIMINGOVRDREG
value|0x234
end_define

begin_comment
comment|/* Timing param override */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_RXTXSMDIAGREG
value|0x238
end_define

begin_comment
comment|/* RXTX State Machine Diag */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_LTSSMDIAGREG
value|0x23C
end_define

begin_comment
comment|/* LTSSM State Machine Diag */
end_comment

begin_comment
comment|/* PCIE protocol DLLP diagnostic registers */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_LCREG
value|0x100
end_define

begin_comment
comment|/* Link Control */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_LCREG_PCIPM_EN
value|0x40
end_define

begin_comment
comment|/* Enable PCI-PM power management */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_LSREG
value|0x104
end_define

begin_comment
comment|/* Link Status */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_LAREG
value|0x108
end_define

begin_comment
comment|/* Link Attention */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_LAMASKREG
value|0x10C
end_define

begin_comment
comment|/* Link Attention Mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_NEXTTXSEQNUMREG
value|0x110
end_define

begin_comment
comment|/* Next Tx Seq Num */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_ACKEDTXSEQNUMREG
value|0x114
end_define

begin_comment
comment|/* Acked Tx Seq Num */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_PURGEDTXSEQNUMREG
value|0x118
end_define

begin_comment
comment|/* Purged Tx Seq Num */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_RXSEQNUMREG
value|0x11C
end_define

begin_comment
comment|/* Rx Sequence Number */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_LRREG
value|0x120
end_define

begin_comment
comment|/* Link Replay */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_LACKTOREG
value|0x124
end_define

begin_comment
comment|/* Link Ack Timeout */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_PMTHRESHREG
value|0x128
end_define

begin_comment
comment|/* Power Management Threshold */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_L0THRESHOLDTIME_MASK
value|0xFF00
end_define

begin_comment
comment|/* bits 0 - 7 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_L1THRESHOLDTIME_MASK
value|0xFF00
end_define

begin_comment
comment|/* bits 8 - 15 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_L1THRESHOLDTIME_SHIFT
value|8
end_define

begin_comment
comment|/* PCIE_L1THRESHOLDTIME_SHIFT */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_L1THRESHOLD_WARVAL
value|0x72
end_define

begin_comment
comment|/* WAR value */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_ASPMTIMER_EXTEND
value|0x1000000
end_define

begin_comment
comment|/*> rev7: enable extend ASPM timer */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_RTRYWPREG
value|0x12C
end_define

begin_comment
comment|/* Retry buffer write ptr */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_RTRYRPREG
value|0x130
end_define

begin_comment
comment|/* Retry buffer Read ptr */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_RTRYPPREG
value|0x134
end_define

begin_comment
comment|/* Retry buffer Purged ptr */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_RTRRWREG
value|0x138
end_define

begin_comment
comment|/* Retry buffer Read/Write */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_ECTHRESHREG
value|0x13C
end_define

begin_comment
comment|/* Error Count Threshold */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_TLPERRCTRREG
value|0x140
end_define

begin_comment
comment|/* TLP Error Counter */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_ERRCTRREG
value|0x144
end_define

begin_comment
comment|/* Error Counter */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_NAKRXCTRREG
value|0x148
end_define

begin_comment
comment|/* NAK Received Counter */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_TESTREG
value|0x14C
end_define

begin_comment
comment|/* Test */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_PKTBIST
value|0x150
end_define

begin_comment
comment|/* Packet BIST */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_PCIE11
value|0x154
end_define

begin_comment
comment|/* DLLP PCIE 1.1 reg */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_DLLP_LSREG_LINKUP
value|(1<< 16)
end_define

begin_comment
comment|/* PCIE protocol TLP diagnostic registers */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_CONFIGREG
value|0x000
end_define

begin_comment
comment|/* Configuration */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_WORKAROUNDSREG
value|0x004
end_define

begin_comment
comment|/* TLP Workarounds */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_WORKAROUND_URBIT
value|0x8
end_define

begin_comment
comment|/* If enabled, UR status bit is set  							 * on memory access of an unmatched 							 * address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_WRDMAUPPER
value|0x010
end_define

begin_comment
comment|/* Write DMA Upper Address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_WRDMALOWER
value|0x014
end_define

begin_comment
comment|/* Write DMA Lower Address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_WRDMAREQ_LBEREG
value|0x018
end_define

begin_comment
comment|/* Write DMA Len/ByteEn Req */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_RDDMAUPPER
value|0x01C
end_define

begin_comment
comment|/* Read DMA Upper Address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_RDDMALOWER
value|0x020
end_define

begin_comment
comment|/* Read DMA Lower Address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_RDDMALENREG
value|0x024
end_define

begin_comment
comment|/* Read DMA Len Req */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_MSIDMAUPPER
value|0x028
end_define

begin_comment
comment|/* MSI DMA Upper Address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_MSIDMALOWER
value|0x02C
end_define

begin_comment
comment|/* MSI DMA Lower Address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_MSIDMALENREG
value|0x030
end_define

begin_comment
comment|/* MSI DMA Len Req */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_SLVREQLENREG
value|0x034
end_define

begin_comment
comment|/* Slave Request Len */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_FCINPUTSREQ
value|0x038
end_define

begin_comment
comment|/* Flow Control Inputs */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_TXSMGRSREQ
value|0x03C
end_define

begin_comment
comment|/* Tx StateMachine and Gated Req */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_ADRACKCNTARBLEN
value|0x040
end_define

begin_comment
comment|/* Address Ack XferCnt and ARB Len */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_DMACPLHDR0
value|0x044
end_define

begin_comment
comment|/* DMA Completion Hdr 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_DMACPLHDR1
value|0x048
end_define

begin_comment
comment|/* DMA Completion Hdr 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_DMACPLHDR2
value|0x04C
end_define

begin_comment
comment|/* DMA Completion Hdr 2 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_DMACPLMISC0
value|0x050
end_define

begin_comment
comment|/* DMA Completion Misc0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_DMACPLMISC1
value|0x054
end_define

begin_comment
comment|/* DMA Completion Misc1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_DMACPLMISC2
value|0x058
end_define

begin_comment
comment|/* DMA Completion Misc2 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_SPTCTRLLEN
value|0x05C
end_define

begin_comment
comment|/* Split Controller Req len */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_SPTCTRLMSIC0
value|0x060
end_define

begin_comment
comment|/* Split Controller Misc 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_SPTCTRLMSIC1
value|0x064
end_define

begin_comment
comment|/* Split Controller Misc 1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_BUSDEVFUNC
value|0x068
end_define

begin_comment
comment|/* Bus/Device/Func */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_RESETCTR
value|0x06C
end_define

begin_comment
comment|/* Reset Counter */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_RTRYBUF
value|0x070
end_define

begin_comment
comment|/* Retry Buffer value */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_TGTDEBUG1
value|0x074
end_define

begin_comment
comment|/* Target Debug Reg1 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_TGTDEBUG2
value|0x078
end_define

begin_comment
comment|/* Target Debug Reg2 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_TGTDEBUG3
value|0x07C
end_define

begin_comment
comment|/* Target Debug Reg3 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_TLP_TGTDEBUG4
value|0x080
end_define

begin_comment
comment|/* Target Debug Reg4 */
end_comment

begin_comment
comment|/*  * PCIe-G1 SerDes MDIO Registers (>= rev10)  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PHYADDR_SD
value|0x0
end_define

begin_comment
comment|/* serdes PHY address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_ADDREXT
value|0x1F
end_define

begin_comment
comment|/* serdes address extension register */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_IEEE0
value|0x0000
end_define

begin_comment
comment|/* IEEE0 AN CTRL block */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_IEEE1
value|0x0010
end_define

begin_comment
comment|/* IEEE1 AN ADV block */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_BLK0
value|0x8000
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_BLK1
value|0x8010
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_BLK2
value|0x8020
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_BLK3
value|0x8030
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_BLK4
value|0x8040
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_PLL
value|0x8080
end_define

begin_comment
comment|/* (?) PLL register block */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_TX0
value|0x8200
end_define

begin_comment
comment|/* (?) Transmit 0 block */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_SERDESID
value|0x8310
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_REGS_RX0
value|0x8400
end_define

begin_comment
comment|/* (?) Receive 0 register block */
end_comment

begin_comment
comment|/* The interpretation of these registers and values are just guesses based on  * the limited available documentation from other (likely similar) Broadcom  * SerDes IP. */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER
value|0x17
end_define

begin_comment
comment|/* TX transmit driver register */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER_IFIR_MASK
value|0x000E
end_define

begin_comment
comment|/* unconfirmed */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER_IFIR_SHIFT
value|1
end_define

begin_comment
comment|/* unconfirmed */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER_IPRE_MASK
value|0x00F0
end_define

begin_comment
comment|/* unconfirmed */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER_IPRE_SHIFT
value|4
end_define

begin_comment
comment|/* unconfirmed */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER_IDRIVER_MASK
value|0x0F00
end_define

begin_comment
comment|/* unconfirmed */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER_IDRIVER_SHIFT
value|8
end_define

begin_comment
comment|/* unconfirmed */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER_P2_COEFF_SHIFT
value|12
end_define

begin_comment
comment|/* unconfirmed */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SD_TX_DRIVER_P2_COEFF_MASK
value|0xF000
end_define

begin_comment
comment|/* unconfirmed */
end_comment

begin_comment
comment|/* Constants used with host bridge quirk handling */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_APPLE_TX_P2_COEFF_MAX
value|0x7
end_define

begin_comment
comment|/* 9.6dB pre-emphassis coeff (???) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_APPLE_TX_IDRIVER_MAX
value|0xF
end_define

begin_comment
comment|/* 1400mV voltage range (???) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_APPLE_TX_P2_COEFF_700MV
value|0x7
end_define

begin_comment
comment|/* 2.3dB pre-emphassis coeff (???) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_APPLE_TX_IDRIVER_700MV
value|0x0
end_define

begin_comment
comment|/* 670mV voltage range (???) */
end_comment

begin_comment
comment|/*  * PCIe-G1 SerDes-R9 MDIO Registers (<= rev9)  *   * These register definitions appear to match those provided in the  * "PCI Express SerDes Registers" section of the BCM5761 Ethernet Controller   * Programmer's Reference Guide.  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PHY_SDR9_PLL
value|0x1C
end_define

begin_comment
comment|/* SerDes PLL PHY Address*/
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_PLL_CTRL
value|0x17
end_define

begin_comment
comment|/* PLL control reg */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_PLL_CTRL_FREQDET_EN
value|0x4000
end_define

begin_comment
comment|/* bit 14 is FREQDET on */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PHY_SDR9_TXRX
value|0x0F
end_define

begin_comment
comment|/* SerDes RX/TX PHY Address */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CTRL
value|0x11
end_define

begin_comment
comment|/* RX ctrl register */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CTRL_FORCE
value|0x80
end_define

begin_comment
comment|/* rxpolarity_force */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CTRL_POLARITY_INV
value|0x40
end_define

begin_comment
comment|/* rxpolarity_value (if set, inverse polarity) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDR
value|0x16
end_define

begin_comment
comment|/* RX CDR ctrl register */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDR_FREQ_OVR_EN
value|0x0100
end_define

begin_comment
comment|/* freq_override_en flag */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDR_FREQ_OVR_MASK
value|0x00FF
end_define

begin_comment
comment|/* freq_override_val */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDR_FREQ_OVR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW
value|0x17
end_define

begin_comment
comment|/* RX CDR bandwidth (PLL tuning) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW_INTGTRK_MASK
value|0x7000
end_define

begin_comment
comment|/* integral loop bandwidth (phase tracking mode) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW_INTGTRK_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW_INTGACQ_MASK
value|0x0700
end_define

begin_comment
comment|/* integral loop bandwidth (phase acquisition mode) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW_INTGACQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW_PROPTRK_MASK
value|0x0070
end_define

begin_comment
comment|/* proportional loop bandwidth (phase tracking mode) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW_PROPTRK_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW_PROPACQ_MASK
value|0x0007
end_define

begin_comment
comment|/* proportional loop bandwidth (phase acquisition mode) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_CDRBW_PROPACQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_TIMER1
value|0x12
end_define

begin_comment
comment|/* timer1 register */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_TIMER1_LKTRK_MASK
value|0xFF00
end_define

begin_comment
comment|/* phase tracking delay before asserting RX seq completion (in 16ns units) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_TIMER1_LKTRK_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_TIMER1_LKACQ_MASK
value|0x00FF
end_define

begin_comment
comment|/* phase acquisition mode time (in 1024ns units) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SDR9_RX_TIMER1_LKACQ_SHIFT
value|0
end_define

begin_comment
comment|/* SPROM offsets */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_PI_OFFSET
value|BHND_PCI_SRSH_PI_OFFSET
end_define

begin_comment
comment|/**< PCI core index in SROM shadow area */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_PI_MASK
value|BHND_PCI_SRSH_PI_MASK
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_PI_SHIFT
value|BHND_PCI_SRSH_PI_SHIFT
end_define

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_ASPM_OFFSET
value|8
end_define

begin_comment
comment|/* word 4 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_ASPM_ENB
value|0x18
end_define

begin_comment
comment|/* bit 3, 4 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_ASPM_L1_ENB
value|0x10
end_define

begin_comment
comment|/* bit 4 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_ASPM_L0s_ENB
value|0x8
end_define

begin_comment
comment|/* bit 3 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_PCIE_MISC_CONFIG
value|10
end_define

begin_comment
comment|/* word 5 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_L23READY_EXIT_NOPRST
value|0x8000
end_define

begin_comment
comment|/* bit 15 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_CLKREQ_OFFSET_R5
value|40
end_define

begin_comment
comment|/* word 20 for srom rev<= 5 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_CLKREQ_OFFSET_R8
value|104
end_define

begin_comment
comment|/* word 52 for srom rev 8 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_CLKREQ_ENB
value|0x0800
end_define

begin_comment
comment|/* bit 11 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_BD_OFFSET
value|12
end_define

begin_comment
comment|/* word 6 */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_SRSH_AUTOINIT_OFFSET
value|36
end_define

begin_comment
comment|/* auto initialization enable */
end_comment

begin_comment
comment|/* Status reg PCIE_PLP_STATUSREG */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE_PLP_POLARITY_INV
value|0x10
end_define

begin_comment
comment|/* lane polarity is inverted */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCI_BHND_PCIREG_H_ */
end_comment

end_unit

