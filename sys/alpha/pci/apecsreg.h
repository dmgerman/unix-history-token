begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: apecsreg.h,v 1.7 1997/06/06 23:54:24 thorpej Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * APECS Chipset registers and constants.  *  * Taken from ``DECchip 21071 and DECchip 21072 Core Logic Chipsets Data  * Sheet'' (DEC order number EC-QAEMA-TE), pages 4-1 - 4-27, 10-21 - 10-38.  */
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

begin_comment
comment|/*  * Base addresses  */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_BASE
value|0x180000000L
end_define

begin_comment
comment|/* 21071-CA Regs */
end_comment

begin_define
define|#
directive|define
name|EPIC_BASE
value|0x1a0000000L
end_define

begin_comment
comment|/* 21071-DA Regs */
end_comment

begin_define
define|#
directive|define
name|APECS_PCI_IACK
value|0x1b0000000L
end_define

begin_comment
comment|/* PCI Int. Ack. */
end_comment

begin_define
define|#
directive|define
name|APECS_PCI_SIO
value|0x1c0000000L
end_define

begin_comment
comment|/* PCI Sp. I/O Space */
end_comment

begin_define
define|#
directive|define
name|APECS_PCI_CONF
value|0x1e0000000L
end_define

begin_comment
comment|/* PCI Conf. Space */
end_comment

begin_define
define|#
directive|define
name|APECS_PCI_SPARSE
value|0x200000000L
end_define

begin_comment
comment|/* PCI Sparse Space */
end_comment

begin_define
define|#
directive|define
name|APECS_PCI_DENSE
value|0x300000000L
end_define

begin_comment
comment|/* PCI Dense Space */
end_comment

begin_comment
comment|/*  * 21071-CA Registers  */
end_comment

begin_comment
comment|/*  * 21071-CA General Registers  */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_GCR
value|(COMANCHE_BASE + 0x0000)
end_define

begin_comment
comment|/* General Control */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_GCR_RSVD
value|0xc009
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_SYSARB
value|0x0006
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_WIDEMEM
value|0x0010
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_EN
value|0x0020
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_NOALLOC
value|0x0040
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_LONGWR
value|0x0080
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_IGNTAG
value|0x0100
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_FRCTAG
value|0x0200
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_FRCD
value|0x0400
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_FRCV
value|0x0800
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_FRCP
value|0x1000
end_define

begin_define
define|#
directive|define
name|COMANCHE_GCR_BC_BADAP
value|0x2000
end_define

begin_define
define|#
directive|define
name|COMANCHE_RSVD
value|(COMANCHE_BASE + 0x0020)
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_ED
value|(COMANCHE_BASE + 0x0040)
end_define

begin_comment
comment|/* Err& Diag Status */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_ED_LOSTERR
value|0x0001
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_BC_TAPERR
value|0x0002
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_BC_TCPERR
value|0x0004
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_NXMERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_DMACAUSE
value|0x0010
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_VICCAUSE
value|0x0020
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_CREQCAUSE
value|0x01c0
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_RSVD
value|0x1e00
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_PASS2
value|0x2000
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_IDXLLOCK
value|0x4000
end_define

begin_define
define|#
directive|define
name|COMANCHE_ED_WRPEND
value|0x8000
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB
value|(COMANCHE_BASE + 0x0060)
end_define

begin_comment
comment|/* Tag Enable */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_RSVD
value|0x0001
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_4G
value|0x0000
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_2G
value|0x8000
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_1G
value|0xc000
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_512M
value|0xe000
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_256M
value|0xf000
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_128M
value|0xf800
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_64M
value|0xfc00
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_32M
value|0xfe00
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_16M
value|0xff00
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_8M
value|0xff80
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_4M
value|0xffc0
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_2M
value|0xffe0
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_1M
value|0xfff0
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_512K
value|0xfff8
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_256K
value|0xfffc
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_C_128K
value|0xfffe
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_4G
value|0xffff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_2G
value|0x7fff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_1G
value|0x3fff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_512M
value|0x1fff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_256M
value|0x0fff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_128M
value|0x07ff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_64M
value|0x03ff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_32M
value|0x01ff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_16M
value|0x00ff
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_8M
value|0x007f
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_4M
value|0x003f
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_2M
value|0x001f
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_1M
value|0x000e
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_512K
value|0x0006
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_256K
value|0x0002
end_define

begin_define
define|#
directive|define
name|COMANCHE_TAGENB_M_128K
value|0x0000
end_define

begin_define
define|#
directive|define
name|COMANCHE_ERR_LO
value|(COMANCHE_BASE + 0x0080)
end_define

begin_comment
comment|/* Error Low Address */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_ERR_HI
value|(COMANCHE_BASE + 0x00a0)
end_define

begin_comment
comment|/* Error High Address */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_ERR_HI_RSVD
value|0xe000
end_define

begin_define
define|#
directive|define
name|COMANCHE_LCK_LO
value|(COMANCHE_BASE + 0x00c0)
end_define

begin_comment
comment|/* LDx_L Low Address */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_LCK_HI
value|(COMANCHE_BASE + 0x00e0)
end_define

begin_comment
comment|/* LDx_L High Address */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_LOCK_HI_RSVD
value|0xe000
end_define

begin_comment
comment|/*  * 21071-CA Memory Registers  */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_GTIM
value|(COMANCHE_BASE + 0x0200)
end_define

begin_comment
comment|/* Global Timing */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_LOCK_HI_RSVD
value|0xe000
end_define

begin_define
define|#
directive|define
name|COMANCHE_RTIM
value|(COMANCHE_BASE + 0x0220)
end_define

begin_comment
comment|/* Refresh Timing */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_VFP
value|(COMANCHE_BASE + 0x0240)
end_define

begin_comment
comment|/* Video Frame Ptr. */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_VFP_COL
value|0x001f
end_define

begin_define
define|#
directive|define
name|COMANCHE_VFP_ROW
value|0x3fe0
end_define

begin_define
define|#
directive|define
name|COMANCHE_VFP_SUBBANK
value|0x4000
end_define

begin_define
define|#
directive|define
name|COMANCHE_VFP_RSVD
value|0x8000
end_define

begin_define
define|#
directive|define
name|COMANCHE_PD_LO
value|(COMANCHE_BASE + 0x0260)
end_define

begin_comment
comment|/* Pres Detect Low */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_PD_HI
value|(COMANCHE_BASE + 0x0280)
end_define

begin_comment
comment|/* Pres Detect High */
end_comment

begin_comment
comment|/*  * 21071-CA Memory banks' Base Address Register format  */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B0_BAR
value|(COMANCHE_BASE + 0x0800)
end_define

begin_comment
comment|/* Bank 0 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B1_BAR
value|(COMANCHE_BASE + 0x0820)
end_define

begin_comment
comment|/* Bank 1 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B2_BAR
value|(COMANCHE_BASE + 0x0840)
end_define

begin_comment
comment|/* Bank 2 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B3_BAR
value|(COMANCHE_BASE + 0x0860)
end_define

begin_comment
comment|/* Bank 3 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B4_BAR
value|(COMANCHE_BASE + 0x0880)
end_define

begin_comment
comment|/* Bank 4 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B5_BAR
value|(COMANCHE_BASE + 0x08a0)
end_define

begin_comment
comment|/* Bank 5 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B6_BAR
value|(COMANCHE_BASE + 0x08c0)
end_define

begin_comment
comment|/* Bank 6 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B7_BAR
value|(COMANCHE_BASE + 0x08e0)
end_define

begin_comment
comment|/* Bank 7 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B8_BAR
value|(COMANCHE_BASE + 0x0900)
end_define

begin_comment
comment|/* Bank 8 BA */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_BAR_RSVD
value|0x001f
end_define

begin_comment
comment|/*  * 21071-CA Memory banks' Configuration Register format  */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B0_CR
value|(COMANCHE_BASE + 0x0a00)
end_define

begin_comment
comment|/* Bank 0 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B1_CR
value|(COMANCHE_BASE + 0x0a20)
end_define

begin_comment
comment|/* Bank 1 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B2_CR
value|(COMANCHE_BASE + 0x0a40)
end_define

begin_comment
comment|/* Bank 2 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B3_CR
value|(COMANCHE_BASE + 0x0a60)
end_define

begin_comment
comment|/* Bank 3 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B4_CR
value|(COMANCHE_BASE + 0x0a80)
end_define

begin_comment
comment|/* Bank 4 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B5_CR
value|(COMANCHE_BASE + 0x0aa0)
end_define

begin_comment
comment|/* Bank 5 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B6_CR
value|(COMANCHE_BASE + 0x0ac0)
end_define

begin_comment
comment|/* Bank 6 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B7_CR
value|(COMANCHE_BASE + 0x0ae0)
end_define

begin_comment
comment|/* Bank 7 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B8_CR
value|(COMANCHE_BASE + 0x0b00)
end_define

begin_comment
comment|/* Bank 8 Config */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_CR_VALID
value|0x0001
end_define

begin_define
define|#
directive|define
name|COMANCHE_CR_SIZE
value|0x001e
end_define

begin_define
define|#
directive|define
name|COMANCHE_CR_SUBENA
value|0x0020
end_define

begin_define
define|#
directive|define
name|COMANCHE_CR_COLSEL
value|0x01c0
end_define

begin_define
define|#
directive|define
name|COMANCHE_CR_S0_RSVD
value|0xfe00
end_define

begin_define
define|#
directive|define
name|COMANCHE_CR_S8_CHECK
value|0x0200
end_define

begin_define
define|#
directive|define
name|COMANCHE_CR_S8_RSVD
value|0xfc00
end_define

begin_comment
comment|/*  * 21071-CA Memory banks' Timing Register A format  */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B0_TRA
value|(COMANCHE_BASE + 0x0c00)
end_define

begin_comment
comment|/* Bank 0 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B1_TRA
value|(COMANCHE_BASE + 0x0c20)
end_define

begin_comment
comment|/* Bank 1 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B2_TRA
value|(COMANCHE_BASE + 0x0c40)
end_define

begin_comment
comment|/* Bank 2 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B3_TRA
value|(COMANCHE_BASE + 0x0c60)
end_define

begin_comment
comment|/* Bank 3 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B4_TRA
value|(COMANCHE_BASE + 0x0c80)
end_define

begin_comment
comment|/* Bank 4 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B5_TRA
value|(COMANCHE_BASE + 0x0ca0)
end_define

begin_comment
comment|/* Bank 5 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B6_TRA
value|(COMANCHE_BASE + 0x0cc0)
end_define

begin_comment
comment|/* Bank 6 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B7_TRA
value|(COMANCHE_BASE + 0x0ce0)
end_define

begin_comment
comment|/* Bank 7 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B8_TRA
value|(COMANCHE_BASE + 0x0d00)
end_define

begin_comment
comment|/* Bank 8 Timing A */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_TRA_ROWSETUP
value|0x0003
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRA_ROWHOLD
value|0x000c
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRA_COLSETUP
value|0x0070
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRA_COLHOLD
value|0x0180
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRA_RDLYROW
value|0x0e00
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRA_RDLYCOL
value|0x7000
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRA_RSVD
value|0x8000
end_define

begin_comment
comment|/*  * 21071-CA Memory banks' Timing Register B format  */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B0_TRB
value|(COMANCHE_BASE + 0x0e00)
end_define

begin_comment
comment|/* Bank 0 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B1_TRB
value|(COMANCHE_BASE + 0x0e20)
end_define

begin_comment
comment|/* Bank 1 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B2_TRB
value|(COMANCHE_BASE + 0x0e40)
end_define

begin_comment
comment|/* Bank 2 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B3_TRB
value|(COMANCHE_BASE + 0x0e60)
end_define

begin_comment
comment|/* Bank 3 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B4_TRB
value|(COMANCHE_BASE + 0x0e80)
end_define

begin_comment
comment|/* Bank 4 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B5_TRB
value|(COMANCHE_BASE + 0x0ea0)
end_define

begin_comment
comment|/* Bank 5 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B6_TRB
value|(COMANCHE_BASE + 0x0ec0)
end_define

begin_comment
comment|/* Bank 6 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B7_TRB
value|(COMANCHE_BASE + 0x0ee0)
end_define

begin_comment
comment|/* Bank 7 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_B8_TRB
value|(COMANCHE_BASE + 0x0f00)
end_define

begin_comment
comment|/* Bank 8 Timing B */
end_comment

begin_define
define|#
directive|define
name|COMANCHE_TRB_RTCAS
value|0x0007
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRB_WTCAS
value|0x0038
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRB_TCP
value|0x00c0
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRB_WHOLD0ROW
value|0x0700
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRB_WHOLD0COL
value|0x3800
end_define

begin_define
define|#
directive|define
name|COMANCHE_TRB_RSVD
value|0xc000
end_define

begin_comment
comment|/*  * 21071-DA Registers  */
end_comment

begin_define
define|#
directive|define
name|EPIC_DCSR
value|(EPIC_BASE + 0x0000)
end_define

begin_comment
comment|/* Diagnostic CSR */
end_comment

begin_define
define|#
directive|define
name|EPIC_DCSR_TENB
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_RSVD
value|0x7fc00082
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_PENB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_DCEI
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_DPEC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_IORT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_LOST
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_DDPE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_IOPE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_TABT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_NDEV
value|0x00000800
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_CMRD
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_UMRD
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_IPTL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_MERR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_DBYP
value|0x00030000
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_PCMD
value|0x003c0000
end_define

begin_define
define|#
directive|define
name|EPIC_DCSR_PASS2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EPIC_PEAR
value|(EPIC_BASE + 0x0020)
end_define

begin_comment
comment|/* PCI Err Addr. */
end_comment

begin_define
define|#
directive|define
name|EPIC_SEAR
value|(EPIC_BASE + 0x0040)
end_define

begin_comment
comment|/* sysBus Err Addr. */
end_comment

begin_define
define|#
directive|define
name|EPIC_SEAR_RSVD
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|EPIC_SEAR_SYS_ERR
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|EPIC_DUMMY_1
value|(EPIC_BASE + 0x0060)
end_define

begin_comment
comment|/* Dummy 1 */
end_comment

begin_define
define|#
directive|define
name|EPIC_DUMMY_2
value|(EPIC_BASE + 0x0080)
end_define

begin_comment
comment|/* Dummy 2 */
end_comment

begin_define
define|#
directive|define
name|EPIC_DUMMY_3
value|(EPIC_BASE + 0x00a0)
end_define

begin_comment
comment|/* Dummy 3 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TBASE_1
value|(EPIC_BASE + 0x00c0)
end_define

begin_comment
comment|/* Trans. Base 1 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TBASE_2
value|(EPIC_BASE + 0x00e0)
end_define

begin_comment
comment|/* Trans. Base 2 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TBASE_RSVD
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|EPIC_TBASE_T_BASE
value|0xfffffe00
end_define

begin_define
define|#
directive|define
name|EPIC_TBASE_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_BASE_1
value|(EPIC_BASE + 0x0100)
end_define

begin_comment
comment|/* PCI Base 1 */
end_comment

begin_define
define|#
directive|define
name|EPIC_PCI_BASE_2
value|(EPIC_BASE + 0x0120)
end_define

begin_comment
comment|/* PCI Base 2 */
end_comment

begin_define
define|#
directive|define
name|EPIC_PCI_BASE_RSVD
value|0x0003ffff
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_BASE_SGEN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_BASE_WENB
value|0x00080000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_BASE_PCI_BASE
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_1
value|(EPIC_BASE + 0x0140)
end_define

begin_comment
comment|/* PCI Mask 1 */
end_comment

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_2
value|(EPIC_BASE + 0x0160)
end_define

begin_comment
comment|/* PCI Mask 2 */
end_comment

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_RSVD
value|0x000fffff
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_PCI_MASK
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_1M
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_2M
value|0x00100000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_4M
value|0x00300000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_8M
value|0x00700000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_16M
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_32M
value|0x01f00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_64M
value|0x03f00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_128M
value|0x07f00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_256M
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_512M
value|0x1ff00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_1G
value|0x3ff00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_2G
value|0x7ff00000
end_define

begin_define
define|#
directive|define
name|EPIC_PCI_MASK_4G
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|EPIC_HAXR0
value|(EPIC_BASE + 0x0180)
end_define

begin_comment
comment|/* Host Addr Extn 0 */
end_comment

begin_define
define|#
directive|define
name|EPIC_HAXR1
value|(EPIC_BASE + 0x01a0)
end_define

begin_comment
comment|/* Host Addr Extn 1 */
end_comment

begin_define
define|#
directive|define
name|EPIC_HAXR1_RSVD
value|0x07ffffff
end_define

begin_define
define|#
directive|define
name|EPIC_HAXR1_EADDR
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|EPIC_HAXR2
value|(EPIC_BASE + 0x01c0)
end_define

begin_comment
comment|/* Host Addr Extn 2 */
end_comment

begin_define
define|#
directive|define
name|EPIC_HAXR2_CONF_TYPE
value|0x00000003
end_define

begin_define
define|#
directive|define
name|EPIC_HAXR2_CONF_TYPO0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EPIC_HAXR2_CONF_TYPE1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EPIC_HAXR2_RSVD
value|0x00fffffc
end_define

begin_define
define|#
directive|define
name|EPIC_HAXR2_EADDR
value|0xff000000
end_define

begin_define
define|#
directive|define
name|EPIC_PMLT
value|(EPIC_BASE + 0x01e0)
end_define

begin_comment
comment|/* PCI Mstr Lat Tmr */
end_comment

begin_define
define|#
directive|define
name|EPIC_PMLT_PMLC
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|EPIC_PMLT_RSVD
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_0
value|(EPIC_BASE + 0x0200)
end_define

begin_comment
comment|/* TLB Tag 0 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_1
value|(EPIC_BASE + 0x0220)
end_define

begin_comment
comment|/* TLB Tag 1 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_2
value|(EPIC_BASE + 0x0240)
end_define

begin_comment
comment|/* TLB Tag 2 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_3
value|(EPIC_BASE + 0x0260)
end_define

begin_comment
comment|/* TLB Tag 3 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_4
value|(EPIC_BASE + 0x0280)
end_define

begin_comment
comment|/* TLB Tag 4 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_5
value|(EPIC_BASE + 0x02a0)
end_define

begin_comment
comment|/* TLB Tag 5 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_6
value|(EPIC_BASE + 0x02c0)
end_define

begin_comment
comment|/* TLB Tag 6 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_7
value|(EPIC_BASE + 0x02e0)
end_define

begin_comment
comment|/* TLB Tag 7 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_RSVD
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_EVAL
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EPIC_TLB_TAG_PCI_PAGE
value|0xffffe000
end_define

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_0
value|(EPIC_BASE + 0x0300)
end_define

begin_comment
comment|/* TLB Data 0 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_1
value|(EPIC_BASE + 0x0320)
end_define

begin_comment
comment|/* TLB Data 1 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_2
value|(EPIC_BASE + 0x0340)
end_define

begin_comment
comment|/* TLB Data 2 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_3
value|(EPIC_BASE + 0x0360)
end_define

begin_comment
comment|/* TLB Data 3 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_4
value|(EPIC_BASE + 0x0380)
end_define

begin_comment
comment|/* TLB Data 4 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_5
value|(EPIC_BASE + 0x03a0)
end_define

begin_comment
comment|/* TLB Data 5 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_6
value|(EPIC_BASE + 0x03c0)
end_define

begin_comment
comment|/* TLB Data 6 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_7
value|(EPIC_BASE + 0x03e0)
end_define

begin_comment
comment|/* TLB Data 7 */
end_comment

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_RSVD
value|0xffe00001
end_define

begin_define
define|#
directive|define
name|EPIC_TLB_DATA_CPU_PAGE
value|0x001ffffe
end_define

begin_define
define|#
directive|define
name|EPIC_TBIA
value|(EPIC_BASE + 0x0400)
end_define

begin_comment
comment|/* TLB Invl All */
end_comment

begin_comment
comment|/*  * EPIC Scatter-Gather Map Entries  */
end_comment

begin_struct
struct|struct
name|sgmapent
block|{
name|u_int64_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SGMAPENT_EVAL
value|0x0000000000000001L
end_define

begin_define
define|#
directive|define
name|SGMAPENT_PFN
value|0x00000000001ffffeL
end_define

begin_define
define|#
directive|define
name|SGMAPENT_RSVD
value|0xffffffffffe00000L
end_define

begin_define
define|#
directive|define
name|SGMAP_MAKEENTRY
parameter_list|(
name|pfn
parameter_list|)
value|(SGMAPENT_EVAL | ((pfn)<< 1))
end_define

end_unit

