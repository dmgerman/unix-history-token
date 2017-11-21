begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2015 Broadcom Corporation  * All rights reserved.  *  * This file is derived from the pcie_core.h and pcie2_core.h headers  * from Broadcom's Linux driver sources as distributed by dd-wrt.  *   * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_PCIE2_BHND_PCIE2_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_PCIE2_BHND_PCIE2_REG_H_
end_define

begin_comment
comment|/*  * PCIe-Gen2 DMA Constants  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA64_TRANSLATION
value|0x8000000000000000
end_define

begin_comment
comment|/**< PCIe-Gen2 DMA64 address translation */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA64_MASK
value|0xc000000000000000
end_define

begin_comment
comment|/**< PCIe-Gen2 DMA64 translation mask */
end_comment

begin_comment
comment|/*  * PCIe-Gen2 Core Registers  */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_CLK_CONTROL
value|0x000
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_RC_PM_CONTROL
value|0x004
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_RC_PM_STATUS
value|0x008
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_EP_PM_CONTROL
value|0x00C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_EP_PM_STATUS
value|0x010
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_EP_LTR_CONTROL
value|0x014
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_EP_LTR_STATUS
value|0x018
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_EP_OBFF_STATUS
value|0x01C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_PCIE_ERR_STATUS
value|0x020
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_RC_AXI_CONFIG
value|0x100
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_EP_AXI_CONFIG
value|0x104
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_RXDEBUG_STATUS0
value|0x108
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_RXDEBUG_CONTROL0
value|0x10C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_CONFIGINDADDR
value|0x120
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_CONFIGINDDATA
value|0x124
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_CFG_ADDR
value|0x1F8
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_CFG_DATA
value|0x1FC
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_PAGE
value|0x200
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_PAGE
value|0x204
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_INTREN
value|0x208
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_CTRL0
value|0x210
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_CTRL1
value|0x214
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_CTRL2
value|0x218
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_CTRL3
value|0x21C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_CTRL4
value|0x220
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_CTRL5
value|0x224
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_HEAD0
value|0x250
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_TAIL0
value|0x254
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_HEAD1
value|0x258
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_TAIL1
value|0x25C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_HEAD2
value|0x260
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_TAIL2
value|0x264
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_HEAD3
value|0x268
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_TAIL3
value|0x26C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_HEAD4
value|0x270
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_TAIL4
value|0x274
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_HEAD5
value|0x278
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EQ_TAIL5
value|0x27C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_RC_INTX_EN
value|0x330
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_RC_INTX_CSR
value|0x334
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_MSI_REQ
value|0x340
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_HOST_INTR_EN
value|0x344
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_HOST_INTR_CSR
value|0x348
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_HOST_INTR0
value|0x350
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_HOST_INTR1
value|0x354
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_HOST_INTR2
value|0x358
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_HOST_INTR3
value|0x35C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EP_INT_EN0
value|0x360
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EP_INT_EN1
value|0x364
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EP_INT_CSR0
value|0x370
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_SYS_EP_INT_CSR1
value|0x374
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIO_CTL
value|0x128
end_define

begin_comment
comment|/**< mdio control */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIO_WRDATA
value|0x12C
end_define

begin_comment
comment|/**< mdio data write */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIO_RDDATA
value|0x130
end_define

begin_comment
comment|/**< mdio data read */
end_comment

begin_comment
comment|/* DMA doorbell registers (>= rev5) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DB0_HOST2DEV0
value|0x140
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB0_HOST2DEV1
value|0x144
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB0_DEV2HOST0
value|0x148
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB0_DEV2HOST1
value|0x14C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB1_HOST2DEV0
value|0x150
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB1_HOST2DEV1
value|0x154
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB1_DEV2HOST0
value|0x158
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB1_DEV2HOST1
value|0x15C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB2_HOST2DEV0
value|0x160
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB2_HOST2DEV1
value|0x164
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB2_DEV2HOST0
value|0x168
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB2_DEV2HOST1
value|0x16C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB3_HOST2DEV0
value|0x170
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB3_HOST2DEV1
value|0x174
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB3_DEV2HOST0
value|0x178
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DB3_DEV2HOST1
value|0x17C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DATAINTF
value|0x180
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTRLAZY0_DEV2HOST
value|0x188
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTRLAZY0_HOST2DEV
value|0x18c
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTSTAT0_HOST2DEV
value|0x190
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTMASK0_HOST2DEV
value|0x194
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTSTAT0_DEV2HOST
value|0x198
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTMASK0_DEV2HOST
value|0x19c
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_LTR_STATE
value|0x1A0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_PWR_INT_STATUS
value|0x1A4
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_PWR_INT_MASK
value|0x1A8
end_define

begin_comment
comment|/* DMA channel registers */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA0_HOST2DEV_TX
value|0x200
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA0_HOST2DEV_RX
value|0x220
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA0_DEV2HOST_TX
value|0x240
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA0_DEV2HOST_RX
value|0x260
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA1_HOST2DEV_TX
value|0x280
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA1_HOST2DEV_RX
value|0x2A0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA1_DEV2HOST_TX
value|0x2C0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA1_DEV2HOST_RX
value|0x2E0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA2_HOST2DEV_TX
value|0x300
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA2_HOST2DEV_RX
value|0x320
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA2_DEV2HOST_TX
value|0x340
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA2_DEV2HOST_RX
value|0x360
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA3_HOST2DEV_TX
value|0x380
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA3_HOST2DEV_RX
value|0x3A0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA3_DEV2HOST_TX
value|0x3C0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA3_DEV2HOST_RX
value|0x3E0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_PCIE_FUNC0_CFG
value|0x400
end_define

begin_comment
comment|/**< PCIe function 0 config space */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_PCIE_FUNC1_CFG
value|0x500
end_define

begin_comment
comment|/**< PCIe function 1 config space */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_PCIE_FUNC2_CFG
value|0x600
end_define

begin_comment
comment|/**< PCIe function 2 config space */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_PCIE_FUNC3_CFG
value|0x700
end_define

begin_comment
comment|/**< PCIe function 3 config space */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_SPROM
value|0x800
end_define

begin_comment
comment|/**< SPROM shadow */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP0_0
value|0xC00
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP0_1
value|0xC04
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP0_2
value|0xC08
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP0_3
value|0xC0C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP0_4
value|0xC10
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP0_5
value|0xC14
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP0_6
value|0xC18
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP0_7
value|0xC1C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP0_0
value|0xC20
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP0_1
value|0xC24
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP0_2
value|0xC28
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP0_3
value|0xC2C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP0_4
value|0xC30
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP0_5
value|0xC34
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP0_6
value|0xC38
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP0_7
value|0xC3C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP1
value|0xC80
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP1
value|0xC88
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC0_IMAP2
value|0xCC0
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IMAP2
value|0xCC8
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_IARR0_LOWER
value|0xD00
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_IARR0_UPPER
value|0xD04
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_IARR1_LOWER
value|0xD08
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_IARR1_UPPER
value|0xD0C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_IARR2_LOWER
value|0xD10
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_IARR2_UPPER
value|0xD14
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OARR0
value|0xD20
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OARR1
value|0xD28
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OARR2
value|0xD30
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OMAP0_LOWER
value|0xD40
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OMAP0_UPPER
value|0xD44
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OMAP1_LOWER
value|0xD48
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OMAP1_UPPER
value|0xD4C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OMAP2_LOWER
value|0xD50
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_OMAP2_UPPER
value|0xD54
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IARR1_SIZE
value|0xD58
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_FUNC1_IARR2_SIZE
value|0xD5C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_MEM_CONTROL
value|0xF00
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_MEM_ECC_ERRLOG0
value|0xF04
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_MEM_ECC_ERRLOG1
value|0xF08
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_LINK_STATUS
value|0xF0C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_STRAP_STATUS
value|0xF10
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_RESET_STATUS
value|0xF14
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_RESETEN_IN_LINKDOWN
value|0xF18
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_MISC_INTR_EN
value|0xF1C
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_TX_DEBUG_CFG
value|0xF20
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_MISC_CONFIG
value|0xF24
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_MISC_STATUS
value|0xF28
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTR_EN
value|0xF30
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTR_CLEAR
value|0xF34
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_INTR_STATUS
value|0xF38
end_define

begin_comment
comment|/* BHND_PCIE2_MDIO_CTL */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIOCTL_DIVISOR_MASK
value|0x7f
end_define

begin_comment
comment|/* clock to be used on MDIO */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIOCTL_DIVISOR_VAL
value|0x2
end_define

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIOCTL_REGADDR_SHIFT
value|8
end_define

begin_comment
comment|/* Regaddr shift */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIOCTL_REGADDR_MASK
value|0x00FFFF00
end_define

begin_comment
comment|/* Regaddr Mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIOCTL_DEVADDR_SHIFT
value|24
end_define

begin_comment
comment|/* Physmedia devaddr shift */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIOCTL_DEVADDR_MASK
value|0x0f000000
end_define

begin_comment
comment|/* Physmedia devaddr Mask */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIOCTL_SLAVE_BYPASS
value|0x10000000
end_define

begin_comment
comment|/* IP slave bypass */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIOCTL_READ
value|0x20000000
end_define

begin_comment
comment|/* IP slave bypass */
end_comment

begin_comment
comment|/* BHND_PCIE2_MDIO_DATA */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIODATA_DONE
value|0x80000000
end_define

begin_comment
comment|/* rd/wr transaction done */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIODATA_MASK
value|0x7FFFFFFF
end_define

begin_comment
comment|/* rd/wr transaction data */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_MDIODATA_DEVADDR_SHIFT
value|4
end_define

begin_comment
comment|/* Physmedia devaddr shift */
end_comment

begin_comment
comment|/* BHND_PCIE2_DMA[0-4]_HOST2DEV_(TX|RX) per-channel register offsets */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA_CTRL
value|0x0
end_define

begin_comment
comment|/**< enable, et al */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA_PTR
value|0x4
end_define

begin_comment
comment|/**< last descriptor posted to chip */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA_ADDRL
value|0x8
end_define

begin_comment
comment|/**< descriptor ring base address low 32-bits (8K aligned) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA_ADDRH
value|0xC
end_define

begin_comment
comment|/**< descriptor ring base address bits 63:32 (8K aligned) */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA_STATUS0
value|0x10
end_define

begin_comment
comment|/**< current descriptor, xmt state */
end_comment

begin_define
define|#
directive|define
name|BHND_PCIE2_DMA_STATUS1
value|0x10
end_define

begin_comment
comment|/**< active descriptor, xmt error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_PCIE2_BHND_PCIE2_REG_H_ */
end_comment

end_unit

