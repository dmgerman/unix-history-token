begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  *   * Portions of this file were derived from the bcmdevs.h header contributed by  * Broadcom to Android's bcmdhd driver module, and the pcicfg.h header  * distributed with Broadcom's initial brcm80211 Linux driver release.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHNDB_PCIREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHNDB_PCIREG_H_
end_define

begin_comment
comment|/*  * Common PCI/PCIE Bridge Configuration Registers.  *   * = MAJOR CORE REVISIONS =  *   * There have been four revisions to the BAR0 memory mappings used  * in BHND PCI/PCIE bridge cores:  *   * == PCI_V0 ==  * Applies to:  * -  PCI (cid=0x804, revision<= 12)  * BAR0 size: 8KB  * Address Map:  *	[offset+  size]	type	description  * 	[0x0000+0x1000]	dynamic mapped backplane address space (window 0).  * 	[0x1000+0x0800]	fixed	SPROM shadow  * 	[0x1800+0x0800]	fixed	pci core registers  *   * == PCI_V1 ==  * Applies to:  * -  PCI (cid=0x804, revision>= 13)  * -  PCIE (cid=0x820) with ChipCommon (revision<= 31)  * BAR0 size: 16KB  * Address Map:  *	[offset+  size]	type	description  *	[0x0000+0x1000]	dynamic	mapped backplane address space (window 0).  *	[0x1000+0x1000]	fixed	SPROM shadow  *	[0x2000+0x1000]	fixed	pci/pcie core registers  *	[0x3000+0x1000]	fixed	chipcommon core registers  *  * == PCI_V2 ==  * Applies to:  * - PCIE (cid=0x820) with ChipCommon (revision>= 32)  * BAR0 size: 16KB  * Address Map:  *	[offset+  size]	type	description  *	[0x0000+0x1000]	dynamic	mapped backplane address space (window 0).  *	[0x1000+0x1000]	dynamic	mapped backplane address space (window 1).  *	[0x2000+0x1000]	fixed	pci/pcie core registers  *	[0x3000+0x1000]	fixed	chipcommon core registers  *  * == PCI_V3 ==  * Applies to:  * - PCIE Gen 2 (cid=0x83c)  * BAR0 size: 32KB  * Address Map:  *	[offset+  size]	type	description  *	[0x0000+0x1000]	dynamic	mapped backplane address space (window 0).  *	[0x1000+0x1000]	dynamic	mapped backplane address space (window 1).  *	[0x2000+0x1000]	fixed	pci/pcie core registers  *	[0x3000+0x1000]	fixed	chipcommon core registers  *	[???]  * BAR1 size: varies  * Address Map:  *	[offset+  size]	type	description  *	[0x0000+0x????]	fixed	ARM tightly-coupled memory (TCM).  *				While fullmac chipsets provided a fixed  *				4KB mapping, newer devices will vary.  *   * = MINOR CORE REVISIONS =  *   * == PCI Cores Revision>= 3 ==  * - Mapped GPIO CSRs into the PCI config space. Refer to  *   BHND_PCI_GPIO_*.  *   * == PCI/PCIE Cores Revision>= 14 ==  * - Mapped the clock CSR into the PCI config space. Refer to  *   BHND_PCI_CLK_CTL_ST  */
end_comment

begin_comment
comment|/* Common PCI/PCIE Config Registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_CONTROL
value|0x88
end_define

begin_comment
comment|/* sprom property control */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_BAR1_CONTROL
value|0x8c
end_define

begin_comment
comment|/* BAR1 region prefetch/burst control */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_INT_STATUS
value|0x90
end_define

begin_comment
comment|/* PCI and other cores interrupts */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_INT_MASK
value|0x94
end_define

begin_comment
comment|/* mask of PCI and other cores interrupts */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_TO_SB_MB
value|0x98
end_define

begin_comment
comment|/* signal backplane interrupts */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_BACKPLANE_ADDR
value|0xa0
end_define

begin_comment
comment|/* address an arbitrary location on the system backplane */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_BACKPLANE_DATA
value|0xa4
end_define

begin_comment
comment|/* data at the location specified by above address */
end_comment

begin_comment
comment|/* PCI (non-PCIe) GPIO/Clock Config Registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_CLK_CTL
value|0xa8
end_define

begin_comment
comment|/* clock control/status (pci>=rev14) */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_GPIO_IN
value|0xb0
end_define

begin_comment
comment|/* gpio input (pci>=rev3) */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_GPIO_OUT
value|0xb4
end_define

begin_comment
comment|/* gpio output (pci>=rev3) */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_GPIO_OUTEN
value|0xb8
end_define

begin_comment
comment|/* gpio output enable (pci>=rev3) */
end_comment

begin_comment
comment|/* Hardware revisions used to determine PCI revision */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_MAX_PCI_HWREV
value|12
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_MIN_PCI_HWREV
value|13
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_MAX_CHIPC_HWREV
value|31
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_MIN_CHIPC_HWREV
value|32
end_define

begin_comment
comment|/**  * Number of times to retry writing to a PCI window address register.  *   * On siba(4) devices, it's possible that writing a PCI window register may  * not succeed; it's necessary to immediately read the configuration register  * and retry if not set to the desired value.  */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_BARCTRL_WRITE_RETRY
value|50
end_define

begin_comment
comment|/* PCI_V0  */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR0_WIN0_CONTROL
value|0x80
end_define

begin_comment
comment|/* backplane address space accessed by BAR0/WIN0 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR1_WIN0_CONTROL
value|0x84
end_define

begin_comment
comment|/* backplane address space accessed by BAR1/WIN0. */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR0_SIZE
value|0x2000
end_define

begin_comment
comment|/* 8KB BAR0 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR0_WIN0_OFFSET
value|0x0
end_define

begin_comment
comment|/* bar0 + 0x0 accesses configurable 4K region of backplane address space */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR0_WIN0_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR0_SPROM_OFFSET
value|0x1000
end_define

begin_comment
comment|/* bar0 + 4K accesses sprom shadow (in pci core) */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR0_SPROM_SIZE
value|0x0800
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR0_PCIREG_OFFSET
value|0x1800
end_define

begin_comment
comment|/* bar0 + 6K accesses pci core registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V0_BAR0_PCIREG_SIZE
value|0x0800
end_define

begin_comment
comment|/* PCI_V1 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_WIN0_CONTROL
value|0x80
end_define

begin_comment
comment|/* backplane address space accessed by BAR0/WIN0 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR1_WIN0_CONTROL
value|0x84
end_define

begin_comment
comment|/* backplane address space accessed by BAR1/WIN0. */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_SIZE
value|0x4000
end_define

begin_comment
comment|/* 16KB BAR0 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_WIN0_OFFSET
value|0x0
end_define

begin_comment
comment|/* bar0 + 0x0 accesses configurable 4K region of backplane address space */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_WIN0_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_SPROM_OFFSET
value|0x1000
end_define

begin_comment
comment|/* bar0 + 4K accesses sprom shadow (in pci core) */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_SPROM_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_PCIREG_OFFSET
value|0x2000
end_define

begin_comment
comment|/* bar0 + 8K accesses pci/pcie core registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_PCIREG_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_CCREGS_OFFSET
value|0x3000
end_define

begin_comment
comment|/* bar0 + 12K accesses chipc core registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V1_BAR0_CCREGS_SIZE
value|0x1000
end_define

begin_comment
comment|/* PCI_V2 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_WIN0_CONTROL
value|0x80
end_define

begin_comment
comment|/* backplane address space accessed by BAR0/WIN0 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR1_WIN0_CONTROL
value|0x84
end_define

begin_comment
comment|/* backplane address space accessed by BAR1/WIN0. */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_WIN1_CONTROL
value|0xAC
end_define

begin_comment
comment|/* backplane address space accessed by BAR0/WIN1 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_SIZE
value|0x4000
end_define

begin_comment
comment|/* 16KB BAR0 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_WIN0_OFFSET
value|0x0
end_define

begin_comment
comment|/* bar0 + 0x0 accesses configurable 4K region of backplane address space */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_WIN0_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_WIN1_OFFSET
value|0x1000
end_define

begin_comment
comment|/* bar0 + 4K accesses second 4K window */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_WIN1_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_PCIREG_OFFSET
value|0x2000
end_define

begin_comment
comment|/* bar0 + 8K accesses pci/pcie core registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_PCIREG_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_CCREGS_OFFSET
value|0x3000
end_define

begin_comment
comment|/* bar0 + 12K accesses chipc core registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V2_BAR0_CCREGS_SIZE
value|0x1000
end_define

begin_comment
comment|/* PCI_V3 (PCIe-G2) */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_WIN0_CONTROL
value|0x80
end_define

begin_comment
comment|/* backplane address space accessed by BAR0/WIN0 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_WIN1_CONTROL
value|0x70
end_define

begin_comment
comment|/* backplane address space accessed by BAR0/WIN1 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_SIZE
value|0x8000
end_define

begin_comment
comment|/* 32KB BAR0 */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_WIN0_OFFSET
value|0x0
end_define

begin_comment
comment|/* bar0 + 0x0 accesses configurable 4K region of backplane address space */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_WIN0_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_WIN1_OFFSET
value|0x1000
end_define

begin_comment
comment|/* bar0 + 4K accesses second 4K window */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_WIN1_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_PCIREG_OFFSET
value|0x2000
end_define

begin_comment
comment|/* bar0 + 8K accesses pci/pcie core registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_PCIREG_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_CCREGS_OFFSET
value|0x3000
end_define

begin_comment
comment|/* bar0 + 12K accesses chipc core registers */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_V3_BAR0_CCREGS_SIZE
value|0x1000
end_define

begin_comment
comment|/* BHNDB_PCI_INT_STATUS */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SBIM_STATUS_SERR
value|0x4
end_define

begin_comment
comment|/* backplane SBErr interrupt status */
end_comment

begin_comment
comment|/* BHNDB_PCI_INT_MASK */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SBIM_SHIFT
value|8
end_define

begin_comment
comment|/* backplane core interrupt mask bits offset */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SBIM_COREIDX_MAX
value|15
end_define

begin_comment
comment|/**< maximum representible core index (in 16 bit field) */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SBIM_MASK
value|0xff00
end_define

begin_comment
comment|/* backplane core interrupt mask */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SBIM_MASK_SERR
value|0x4
end_define

begin_comment
comment|/* backplane SBErr interrupt mask */
end_comment

begin_comment
comment|/* BHNDB_PCI_SPROM_CONTROL */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_SZ_MASK
value|0x03
end_define

begin_comment
comment|/**< sprom size mask */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_SZ_1KB
value|0x00
end_define

begin_comment
comment|/**< 1KB sprom size */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_SZ_4KB
value|0x01
end_define

begin_comment
comment|/**< 4KB sprom size */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_SZ_16KB
value|0x02
end_define

begin_comment
comment|/**< 16KB sprom size */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_SZ_RESERVED
value|0x03
end_define

begin_comment
comment|/**< unsupported sprom size */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_LOCKED
value|0x08
end_define

begin_comment
comment|/**< sprom locked */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_BLANK
value|0x04
end_define

begin_comment
comment|/**< sprom blank */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_WRITEEN
value|0x10
end_define

begin_comment
comment|/**< sprom write enable */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_BOOTROM_WE
value|0x20
end_define

begin_comment
comment|/**< external bootrom write enable */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_BACKPLANE_EN
value|0x40
end_define

begin_comment
comment|/**< enable indirect backplane access (BHNDB_PCI_BACKPLANE_*) */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_SPROM_OTPIN_USE
value|0x80
end_define

begin_comment
comment|/**< device OTP in use */
end_comment

begin_comment
comment|/* PCI (non-PCIe) BHNDB_PCI_GPIO_OUTEN  */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_GPIO_SCS
value|0x10
end_define

begin_comment
comment|/* PCI config space bit 4 for 4306c0 slow clock source */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_GPIO_HWRAD_OFF
value|0x20
end_define

begin_comment
comment|/* PCI config space GPIO 13 for hw radio disable */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_GPIO_XTAL_ON
value|0x40
end_define

begin_comment
comment|/* PCI config space GPIO 14 for Xtal power-up */
end_comment

begin_define
define|#
directive|define
name|BHNDB_PCI_GPIO_PLL_OFF
value|0x80
end_define

begin_comment
comment|/* PCI config space GPIO 15 for PLL power-down */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHNDB_PCIREG_H_ */
end_comment

end_unit

