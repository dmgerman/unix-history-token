begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: lcareg.h,v 1.8 1997/09/05 02:14:31 thorpej Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Jeffrey Hsu, Jason R. Thorpe  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * 21066 chip registers  */
end_comment

begin_define
define|#
directive|define
name|REGVAL
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int32_t *)ALPHA_PHYS_TO_K0SEG(r))
end_define

begin_define
define|#
directive|define
name|REGVAL64
parameter_list|(
name|r
parameter_list|)
value|(*(volatile int64_t *)ALPHA_PHYS_TO_K0SEG(r))
end_define

begin_comment
comment|/*  * Base addresses  */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_BASE
value|0x180000000L
end_define

begin_comment
comment|/* LCA IOC Regs */
end_comment

begin_define
define|#
directive|define
name|LCA_PCI_SIO
value|0x1c0000000L
end_define

begin_comment
comment|/* PCI Sp. I/O Space */
end_comment

begin_define
define|#
directive|define
name|LCA_PCI_CONF
value|0x1e0000000L
end_define

begin_comment
comment|/* PCI Conf. Space */
end_comment

begin_define
define|#
directive|define
name|LCA_PCI_SPARSE
value|0x200000000L
end_define

begin_comment
comment|/* PCI Sparse Space */
end_comment

begin_define
define|#
directive|define
name|LCA_PCI_DENSE
value|0x300000000L
end_define

begin_comment
comment|/* PCI Dense Space */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_HAE
value|LCA_IOC_BASE
end_define

begin_comment
comment|/* Host Address Ext. (64) */
end_comment

begin_define
define|#
directive|define
name|IOC_HAE_ADDREXT
value|0x00000000f8000000UL
end_define

begin_define
define|#
directive|define
name|IOC_HAE_RSVSD
value|0xffffffff07ffffffUL
end_define

begin_define
define|#
directive|define
name|LCA_IOC_CONF
value|(LCA_IOC_BASE + 0x020)
end_define

begin_comment
comment|/* Configuration Cycle Type */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_STAT0
value|(LCA_IOC_BASE + 0x040)
end_define

begin_comment
comment|/* Status 0 */
end_comment

begin_define
define|#
directive|define
name|IOC_STAT0_CMD
value|0x000000000000000fUL
end_define

begin_comment
comment|/* PCI command mask */
end_comment

begin_define
define|#
directive|define
name|IOC_STAT0_ERR
value|0x0000000000000010UL
end_define

begin_comment
comment|/* IOC error indicator R/W1C */
end_comment

begin_define
define|#
directive|define
name|IOC_STAT0_LOST
value|0x0000000000000020UL
end_define

begin_comment
comment|/* IOC lose error info R/W1C */
end_comment

begin_define
define|#
directive|define
name|IOC_STAT0_THIT
value|0x0000000000000040UL
end_define

begin_comment
comment|/* test hit */
end_comment

begin_define
define|#
directive|define
name|IOC_STAT0_TREF
value|0x0000000000000080UL
end_define

begin_comment
comment|/* test reference */
end_comment

begin_define
define|#
directive|define
name|IOC_STAT0_CODE
value|0x0000000000000700UL
end_define

begin_comment
comment|/* code mask */
end_comment

begin_define
define|#
directive|define
name|IOC_STAT0_CODESHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IOC_STAT0_P_NBR
value|0x00000000ffffe000UL
end_define

begin_comment
comment|/* page number mask */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_STAT1
value|(LCA_IOC_BASE + 0x060)
end_define

begin_comment
comment|/* Status 1 */
end_comment

begin_define
define|#
directive|define
name|IOC_STAT1_ADDR
value|0x00000000ffffffffUL
end_define

begin_comment
comment|/* PCI address mask */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_TBIA
value|(LCA_IOC_BASE + 0x080)
end_define

begin_comment
comment|/* TLB Invalidate All */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_TB_ENA
value|(LCA_IOC_BASE + 0x0a0)
end_define

begin_comment
comment|/* TLB Enable */
end_comment

begin_define
define|#
directive|define
name|IOC_TB_ENA_TEN
value|0x0000000000000080UL
end_define

begin_define
define|#
directive|define
name|LCA_IOC_W_BASE0
value|(LCA_IOC_BASE + 0x100)
end_define

begin_comment
comment|/* Window Base */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_W_MASK0
value|(LCA_IOC_BASE + 0x140)
end_define

begin_comment
comment|/* Window Mask */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_W_T_BASE0
value|(LCA_IOC_BASE + 0x180)
end_define

begin_comment
comment|/* Translated Base */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_W_BASE1
value|(LCA_IOC_BASE + 0x120)
end_define

begin_comment
comment|/* Window Base */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_W_MASK1
value|(LCA_IOC_BASE + 0x160)
end_define

begin_comment
comment|/* Window Mask */
end_comment

begin_define
define|#
directive|define
name|LCA_IOC_W_T_BASE1
value|(LCA_IOC_BASE + 0x1a0)
end_define

begin_comment
comment|/* Translated Base */
end_comment

begin_define
define|#
directive|define
name|IOC_W_BASE_W_BASE
value|0x00000000fff00000UL
end_define

begin_comment
comment|/* Window base value */
end_comment

begin_define
define|#
directive|define
name|IOC_W_BASE_SG
value|0x0000000100000000UL
end_define

begin_comment
comment|/* Window uses SGMAPs */
end_comment

begin_define
define|#
directive|define
name|IOC_W_BASE_WEN
value|0x0000000200000000UL
end_define

begin_comment
comment|/* Window enable */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_1M
value|0x0000000000000000UL
end_define

begin_comment
comment|/* 1MB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_2M
value|0x0000000000100000UL
end_define

begin_comment
comment|/* 2MB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_4M
value|0x0000000000300000UL
end_define

begin_comment
comment|/* 4MB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_8M
value|0x0000000000700000UL
end_define

begin_comment
comment|/* 8MB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_16M
value|0x0000000000f00000UL
end_define

begin_comment
comment|/* 16MB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_32M
value|0x0000000001f00000UL
end_define

begin_comment
comment|/* 32MB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_64M
value|0x0000000003f00000UL
end_define

begin_comment
comment|/* 64MB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_128M
value|0x0000000007f00000UL
end_define

begin_comment
comment|/* 128M window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_256M
value|0x000000000ff00000UL
end_define

begin_comment
comment|/* 256M window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_512M
value|0x000000001ff00000UL
end_define

begin_comment
comment|/* 512M window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_1G
value|0x000000003ff00000UL
end_define

begin_comment
comment|/* 1GB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_2G
value|0x000000007ff00000UL
end_define

begin_comment
comment|/* 2GB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_MASK_4G
value|0x00000000fff00000UL
end_define

begin_comment
comment|/* 4GB window */
end_comment

begin_define
define|#
directive|define
name|IOC_W_T_BASE
value|0x00000000fffffc00UL
end_define

begin_comment
comment|/* page table base */
end_comment

end_unit

