begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: rpb.h,v 1.20 1998/04/15 00:47:33 mjacob Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995, 1996 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Keith Bostic, Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * From DEC 3000 300/400/500/600/700/800/900 System Programmer's Manual,  * EK-D3SYS-PM.B01.  */
end_comment

begin_comment
comment|/*  * HWRPB (Hardware Restart Parameter Block).  */
end_comment

begin_define
define|#
directive|define
name|HWRPB_ADDR
value|0x10000000
end_define

begin_comment
comment|/* virtual address, at boot */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASSEMBLER
end_ifndef

begin_struct
struct|struct
name|rpb
block|{
name|u_int64_t
name|rpb_phys
decl_stmt|;
comment|/*   0: HWRPB phys. address. */
name|char
name|rpb_magic
index|[
literal|8
index|]
decl_stmt|;
comment|/*   8: "HWRPB" (in ASCII) */
name|u_int64_t
name|rpb_version
decl_stmt|;
comment|/*  10 */
name|u_int64_t
name|rpb_size
decl_stmt|;
comment|/*  18: HWRPB size in bytes */
name|u_int64_t
name|rpb_primary_cpu_id
decl_stmt|;
comment|/*  20 */
name|u_int64_t
name|rpb_page_size
decl_stmt|;
comment|/*  28: (8192) */
name|u_int64_t
name|rpb_phys_addr_size
decl_stmt|;
comment|/*  30:   (34) */
name|u_int64_t
name|rpb_max_asn
decl_stmt|;
comment|/*  38:   (16) */
name|char
name|rpb_ssn
index|[
literal|16
index|]
decl_stmt|;
comment|/*  40: only first 10 valid */
define|#
directive|define
name|ST_ADU
value|1
comment|/* Alpha Demo. Unit (?) */
define|#
directive|define
name|ST_DEC_4000
value|2
comment|/* "Cobra" (?) */
define|#
directive|define
name|ST_DEC_7000
value|3
comment|/* "Ruby" (?) */
define|#
directive|define
name|ST_DEC_3000_500
value|4
comment|/* "Flamingo" family (TC) */
define|#
directive|define
name|ST_DEC_2000_300
value|6
comment|/* "Jensen" (EISA/ISA) */
define|#
directive|define
name|ST_DEC_3000_300
value|7
comment|/* "Pelican" (TC) */
define|#
directive|define
name|ST_AVALON_A12
value|8
comment|/* XXX Avalon Multicomputer */
define|#
directive|define
name|ST_DEC_2100_A500
value|9
comment|/* "Sable" (?) */
define|#
directive|define
name|ST_DEC_APXVME_64
value|10
comment|/* "AXPvme" (VME?) */
define|#
directive|define
name|ST_DEC_AXPPCI_33
value|11
comment|/* "NoName" (PCI/ISA) */
define|#
directive|define
name|ST_DEC_21000
value|12
comment|/* "TurboLaser" (PCI/EISA) */
define|#
directive|define
name|ST_DEC_2100_A50
value|13
comment|/* "Avanti" (PCI/ISA) */
define|#
directive|define
name|ST_DEC_MUSTANG
value|14
comment|/* "Mustang" (?) */
define|#
directive|define
name|ST_DEC_KN20AA
value|15
comment|/* kn20aa (PCI/EISA) */
define|#
directive|define
name|ST_DEC_1000
value|17
comment|/* "Mikasa" (PCI/ISA?) */
define|#
directive|define
name|ST_EB66
value|19
comment|/* EB66 (PCI/ISA?) */
define|#
directive|define
name|ST_EB64P
value|20
comment|/* EB64+ (PCI/ISA?) */
define|#
directive|define
name|ST_ALPHABOOK1
value|21
comment|/* Alphabook (?) */
define|#
directive|define
name|ST_DEC_4100
value|22
comment|/* "Rawhide" (PCI/EISA) */
define|#
directive|define
name|ST_DEC_EV45_PBP
value|23
comment|/* "Lego" (?) */
define|#
directive|define
name|ST_DEC_2100A_A500
value|24
comment|/* "Lynx" (?) */
define|#
directive|define
name|ST_EB164
value|26
comment|/* EB164 (PCI/ISA) */
define|#
directive|define
name|ST_DEC_1000A
value|27
comment|/* "Noritake" (?) */
define|#
directive|define
name|ST_DEC_ALPHAVME_224
value|28
comment|/* "Cortex" (?) */
define|#
directive|define
name|ST_DEC_550
value|30
comment|/* "Miata" (PCI/ISA) */
define|#
directive|define
name|ST_DEC_EV56_PBP
value|32
comment|/* "Takara" (?) */
define|#
directive|define
name|ST_DEC_ALPHAVME_320
value|33
comment|/* "Yukon" (VME?) */
define|#
directive|define
name|ST_DEC_6600
value|34
comment|/* "Monet/Goldrush" */
comment|/*  * System types for Alpha Processor Inc. machines  */
define|#
directive|define
name|API_ST_BASE
value|200
define|#
directive|define
name|ST_API_UP1000
value|201
comment|/* "Nautilus" */
name|u_int64_t
name|rpb_type
decl_stmt|;
comment|/*  50: */
define|#
directive|define
name|SV_MPCAP
value|0x00000001
comment|/* multiprocessor capable */
define|#
directive|define
name|SV_CONSOLE
value|0x0000001e
comment|/* console hardware mask */
define|#
directive|define
name|SV_CONSOLE_DETACHED
value|0x00000002
define|#
directive|define
name|SV_CONSOLE_EMBEDDED
value|0x00000004
define|#
directive|define
name|SV_POWERFAIL
value|0x000000e0
comment|/* powerfail mask */
define|#
directive|define
name|SV_PF_UNITED
value|0x00000020
define|#
directive|define
name|SV_PF_SEPARATE
value|0x00000040
define|#
directive|define
name|SV_PF_BBACKUP
value|0x00000060
define|#
directive|define
name|SV_PF_ACTION
value|0x00000100
comment|/* powerfail restart */
define|#
directive|define
name|SV_GRAPHICS
value|0x00000200
comment|/* graphic engine present */
define|#
directive|define
name|SV_ST_MASK
value|0x0000fc00
comment|/* system type mask */
define|#
directive|define
name|SV_ST_RESERVED
value|0x00000000
comment|/* RESERVED */
comment|/*  * System types for the DEC 3000/500 (Flamingo) Family  */
define|#
directive|define
name|SV_ST_SANDPIPER
value|0x00000400
comment|/* Sandpiper;	3000/400 */
define|#
directive|define
name|SV_ST_FLAMINGO
value|0x00000800
comment|/* Flamingo;	3000/500 */
define|#
directive|define
name|SV_ST_HOTPINK
value|0x00000c00
comment|/* "Hot Pink";	3000/500X */
define|#
directive|define
name|SV_ST_FLAMINGOPLUS
value|0x00001000
comment|/* Flamingo+;	3000/800 */
define|#
directive|define
name|SV_ST_ULTRA
value|0x00001400
comment|/* "Ultra", aka Flamingo+ */
define|#
directive|define
name|SV_ST_SANDPLUS
value|0x00001800
comment|/* Sandpiper+;	3000/600 */
define|#
directive|define
name|SV_ST_SANDPIPER45
value|0x00001c00
comment|/* Sandpiper45;	3000/700 */
define|#
directive|define
name|SV_ST_FLAMINGO45
value|0x00002000
comment|/* Flamingo45;	3000/900 */
comment|/*  * System types for ?  */
define|#
directive|define
name|SV_ST_SABLE
value|0x00000400
comment|/* Sable (?) */
comment|/*  * System types for the DEC 3000/300 (Pelican) Family  */
define|#
directive|define
name|SV_ST_PELICAN
value|0x00000000
comment|/* Pelican;	 3000/300 */
define|#
directive|define
name|SV_ST_PELICA
value|0x00000400
comment|/* Pelica;	 3000/300L */
define|#
directive|define
name|SV_ST_PELICANPLUS
value|0x00000800
comment|/* Pelican+;	 3000/300X */
define|#
directive|define
name|SV_ST_PELICAPLUS
value|0x00000c00
comment|/* Pelica+;	 3000/300LX */
comment|/*  * System types for the AlphaStation Family  */
define|#
directive|define
name|SV_ST_AVANTI
value|0x00000000
comment|/* Avanti;	400 4/233 */
define|#
directive|define
name|SV_ST_MUSTANG2_4_166
value|0x00000800
comment|/* Mustang II;	200 4/166 */
define|#
directive|define
name|SV_ST_MUSTANG2_4_233
value|0x00001000
comment|/* Mustang II;	200 4/233 */
define|#
directive|define
name|SV_ST_AVANTI_XXX
value|0x00001400
comment|/* also Avanti;	400 4/233 */
define|#
directive|define
name|SV_ST_AVANTI_4_266
value|0x00002000
define|#
directive|define
name|SV_ST_MUSTANG2_4_100
value|0x00002400
comment|/* Mustang II;	200 4/100 */
define|#
directive|define
name|SV_ST_AVANTI_4_233
value|0x0000a800
comment|/* AlphaStation 255/233 */
define|#
directive|define
name|SV_ST_KN20AA
value|0x00000400
comment|/* AlphaStation 500/600 */
comment|/*  * System types for the AXPvme Family  */
define|#
directive|define
name|SV_ST_AXPVME_64
value|0x00000000
comment|/* 21068, 64MHz */
define|#
directive|define
name|SV_ST_AXPVME_160
value|0x00000400
comment|/* 21066, 160MHz */
define|#
directive|define
name|SV_ST_AXPVME_100
value|0x00000c00
comment|/* 21066A, 99MHz */
define|#
directive|define
name|SV_ST_AXPVME_230
value|0x00001000
comment|/* 21066A, 231MHz */
define|#
directive|define
name|SV_ST_AXPVME_66
value|0x00001400
comment|/* 21066A, 66MHz */
define|#
directive|define
name|SV_ST_AXPVME_166
value|0x00001800
comment|/* 21066A, 165MHz */
define|#
directive|define
name|SV_ST_AXPVME_264
value|0x00001c00
comment|/* 21066A, 264MHz */
comment|/*  * System types for the EB164 Family  */
define|#
directive|define
name|SV_ST_EB164_266
value|0x00000400
comment|/* EB164, 266MHz */
define|#
directive|define
name|SV_ST_EB164_300
value|0x00000800
comment|/* EB164, 300MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164_366
value|0x00000c00
comment|/* AlphaPC164, 366MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164_400
value|0x00001000
comment|/* AlphaPC164, 400MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164_433
value|0x00001400
comment|/* AlphaPC164, 433MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164_466
value|0x00001800
comment|/* AlphaPC164, 466MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164_500
value|0x00001c00
comment|/* AlphaPC164, 500MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164LX_400
value|0x00002000
comment|/* AlphaPC164LX, 400MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164LX_466
value|0x00002400
comment|/* AlphaPC164LX, 466MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164LX_533
value|0x00002800
comment|/* AlphaPC164LX, 533MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164LX_600
value|0x00002c00
comment|/* AlphaPC164LX, 600MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164SX_400
value|0x00003000
comment|/* AlphaPC164SX, 400MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164SX_466
value|0x00003400
comment|/* AlphaPC164SX, 433MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164SX_533
value|0x00003800
comment|/* AlphaPC164SX, 533MHz */
define|#
directive|define
name|SV_ST_ALPHAPC164SX_600
value|0x00003c00
comment|/* AlphaPC164SX, 600MHz */
comment|/*  * System types for the Digital Personal Workstation (Miata) Family  * XXX These are not very complete!  */
define|#
directive|define
name|SV_ST_MIATA_1_5
value|0x00004c00
comment|/* Miata 1.5 */
name|u_int64_t
name|rpb_variation
decl_stmt|;
comment|/*  58 */
name|char
name|rpb_revision
index|[
literal|8
index|]
decl_stmt|;
comment|/*  60; only first 4 valid */
name|u_int64_t
name|rpb_intr_freq
decl_stmt|;
comment|/*  68; scaled by 4096 */
name|u_int64_t
name|rpb_cc_freq
decl_stmt|;
comment|/*  70: cycle cntr frequency */
name|vm_offset_t
name|rpb_vptb
decl_stmt|;
comment|/*  78: */
name|u_int64_t
name|rpb_reserved_arch
decl_stmt|;
comment|/*  80: */
name|vm_offset_t
name|rpb_tbhint_off
decl_stmt|;
comment|/*  88: */
name|u_int64_t
name|rpb_pcs_cnt
decl_stmt|;
comment|/*  90: */
name|u_int64_t
name|rpb_pcs_size
decl_stmt|;
comment|/*  98; pcs size in bytes */
name|vm_offset_t
name|rpb_pcs_off
decl_stmt|;
comment|/*  A0: offset to pcs info */
name|u_int64_t
name|rpb_ctb_cnt
decl_stmt|;
comment|/*  A8: console terminal */
name|u_int64_t
name|rpb_ctb_size
decl_stmt|;
comment|/*  B0: ctb size in bytes */
name|vm_offset_t
name|rpb_ctb_off
decl_stmt|;
comment|/*  B8: offset to ctb */
name|vm_offset_t
name|rpb_crb_off
decl_stmt|;
comment|/*  C0: offset to crb */
name|vm_offset_t
name|rpb_memdat_off
decl_stmt|;
comment|/*  C8: memory data offset */
name|vm_offset_t
name|rpb_condat_off
decl_stmt|;
comment|/*  D0: config data offset */
name|vm_offset_t
name|rpb_fru_off
decl_stmt|;
comment|/*  D8: FRU table offset */
name|u_int64_t
name|rpb_save_term
decl_stmt|;
comment|/*  E0: terminal save */
name|u_int64_t
name|rpb_save_term_val
decl_stmt|;
comment|/*  E8: */
name|u_int64_t
name|rpb_rest_term
decl_stmt|;
comment|/*  F0: terminal restore */
name|u_int64_t
name|rpb_rest_term_val
decl_stmt|;
comment|/*  F8: */
name|u_int64_t
name|rpb_restart
decl_stmt|;
comment|/* 100: restart */
name|u_int64_t
name|rpb_restart_val
decl_stmt|;
comment|/* 108: */
name|u_int64_t
name|rpb_reserve_os
decl_stmt|;
comment|/* 110: */
name|u_int64_t
name|rpb_reserve_hw
decl_stmt|;
comment|/* 118: */
name|u_int64_t
name|rpb_checksum
decl_stmt|;
comment|/* 120: HWRPB checksum */
name|u_int64_t
name|rpb_rxrdy
decl_stmt|;
comment|/* 128: receive ready */
name|u_int64_t
name|rpb_txrdy
decl_stmt|;
comment|/* 130: transmit ready */
name|vm_offset_t
name|rpb_dsrdb_off
decl_stmt|;
comment|/* 138: HWRPB + DSRDB offset */
name|u_int64_t
name|rpb_tbhint
index|[
literal|8
index|]
decl_stmt|;
comment|/* 149: TB hint block */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LOCATE_PCS
parameter_list|(
name|h
parameter_list|,
name|cpunumber
parameter_list|)
value|((struct pcs *)	\ 	((char *)(h) + (h)->rpb_pcs_off + ((cpunumber) * (h)->rpb_pcs_size)))
end_define

begin_comment
comment|/*  * PCS: Per-CPU information.  */
end_comment

begin_struct
struct|struct
name|pcs
block|{
name|u_int8_t
name|pcs_hwpcb
index|[
literal|128
index|]
decl_stmt|;
comment|/*   0: PAL dependent */
define|#
directive|define
name|PCS_BIP
value|0x000001
comment|/* boot in progress */
define|#
directive|define
name|PCS_RC
value|0x000002
comment|/* restart possible */
define|#
directive|define
name|PCS_PA
value|0x000004
comment|/* processor available */
define|#
directive|define
name|PCS_PP
value|0x000008
comment|/* processor present */
define|#
directive|define
name|PCS_OH
value|0x000010
comment|/* user halted */
define|#
directive|define
name|PCS_CV
value|0x000020
comment|/* context valid */
define|#
directive|define
name|PCS_PV
value|0x000040
comment|/* PALcode valid */
define|#
directive|define
name|PCS_PMV
value|0x000080
comment|/* PALcode memory valid */
define|#
directive|define
name|PCS_PL
value|0x000100
comment|/* PALcode loaded */
define|#
directive|define
name|PCS_HALT_REQ
value|0xff0000
comment|/* halt request mask */
define|#
directive|define
name|PCS_HALT_DEFAULT
value|0x000000
define|#
directive|define
name|PCS_HALT_SAVE_EXIT
value|0x010000
define|#
directive|define
name|PCS_HALT_COLD_BOOT
value|0x020000
define|#
directive|define
name|PCS_HALT_WARM_BOOT
value|0x030000
define|#
directive|define
name|PCS_HALT_STAY_HALTED
value|0x040000
define|#
directive|define
name|PCS_mbz
value|0xffffffffff000000
comment|/* 24:63 -- must be zero */
name|u_int64_t
name|pcs_flags
decl_stmt|;
comment|/*  80: */
name|u_int64_t
name|pcs_pal_memsize
decl_stmt|;
comment|/*  88: PAL memory size */
name|u_int64_t
name|pcs_pal_scrsize
decl_stmt|;
comment|/*  90: PAL scratch size */
name|vm_offset_t
name|pcs_pal_memaddr
decl_stmt|;
comment|/*  98: PAL memory addr */
name|vm_offset_t
name|pcs_pal_scraddr
decl_stmt|;
comment|/*  A0: PAL scratch addr */
struct|struct
block|{
name|u_int64_t
name|minorrev
range|:
literal|8
decl_stmt|,
comment|/* alphabetic char 'a' - 'z' */
name|majorrev
range|:
literal|8
decl_stmt|,
comment|/* alphabetic char 'a' - 'z' */
define|#
directive|define
name|PAL_TYPE_STANDARD
value|0
define|#
directive|define
name|PAL_TYPE_VMS
value|1
define|#
directive|define
name|PAL_TYPE_OSF1
value|2
name|pal_type
range|:
literal|8
decl_stmt|,
comment|/* PALcode type: 						 * 0 == standard 						 * 1 == OpenVMS 						 * 2 == OSF/1 						 * 3-127 DIGITAL reserv. 						 * 128-255 non-DIGITAL reserv. 						 */
name|sbz1
range|:
literal|8
decl_stmt|,
name|compatibility
range|:
literal|16
decl_stmt|,
comment|/* Compatibility revision */
name|proc_cnt
range|:
literal|16
decl_stmt|;
comment|/* Processor count */
block|}
name|pcs_pal_rev
struct|;
comment|/*  A8: */
define|#
directive|define
name|pcs_minorrev
value|pcs_pal_rev.minorrev
define|#
directive|define
name|pcs_majorrev
value|pcs_pal_rev.majorrev
define|#
directive|define
name|pcs_pal_type
value|pcs_pal_rev.pal_type
define|#
directive|define
name|pcs_compatibility
value|pcs_pal_rev.compatibility
define|#
directive|define
name|pcs_proc_cnt
value|pcs_pal_rev.proc_cnt
name|u_int64_t
name|pcs_proc_type
decl_stmt|;
comment|/*  B0: processor type */
define|#
directive|define
name|PCS_PROC_MAJOR
value|0x00000000ffffffff
define|#
directive|define
name|PCS_PROC_MAJORSHIFT
value|0
define|#
directive|define
name|PCS_PROC_EV3
value|1
comment|/* EV3 */
define|#
directive|define
name|PCS_PROC_EV4
value|2
comment|/* EV4: 21064 */
define|#
directive|define
name|PCS_PROC_SIMULATION
value|3
comment|/* Simulation */
define|#
directive|define
name|PCS_PROC_LCA4
value|4
comment|/* LCA4: 2106[68] */
define|#
directive|define
name|PCS_PROC_EV5
value|5
comment|/* EV5: 21164 */
define|#
directive|define
name|PCS_PROC_EV45
value|6
comment|/* EV45: 21064A */
define|#
directive|define
name|PCS_PROC_EV56
value|7
comment|/* EV56: 21164A */
define|#
directive|define
name|PCS_PROC_EV6
value|8
comment|/* EV6: 21264 */
define|#
directive|define
name|PCS_PROC_PCA56
value|9
comment|/* PCA256: 21164PC */
define|#
directive|define
name|PCS_PROC_MINOR
value|0xffffffff00000000
define|#
directive|define
name|PCS_PROC_MINORSHIFT
value|32
comment|/* Minor number interpretation is processor specific.  See cpu.c. */
name|u_int64_t
name|pcs_proc_var
decl_stmt|;
comment|/* B8: processor variation. */
define|#
directive|define
name|PCS_VAR_VAXFP
value|0x0000000000000001
comment|/* VAX FP support */
define|#
directive|define
name|PCS_VAR_IEEEFP
value|0x0000000000000002
comment|/* IEEE FP support */
define|#
directive|define
name|PCS_VAR_PE
value|0x0000000000000004
comment|/* Primary Eligible */
define|#
directive|define
name|PCS_VAR_RESERVED
value|0xfffffffffffffff8
comment|/* Reserved */
name|char
name|pcs_proc_revision
index|[
literal|8
index|]
decl_stmt|;
comment|/*  C0: only first 4 valid */
name|char
name|pcs_proc_sn
index|[
literal|16
index|]
decl_stmt|;
comment|/*  C8: only first 10 valid */
name|vm_offset_t
name|pcs_machcheck
decl_stmt|;
comment|/*  D8: mach chk phys addr. */
name|u_int64_t
name|pcs_machcheck_len
decl_stmt|;
comment|/*  E0: length in bytes */
name|vm_offset_t
name|pcs_halt_pcbb
decl_stmt|;
comment|/*  E8: phys addr of halt PCB */
name|vm_offset_t
name|pcs_halt_pc
decl_stmt|;
comment|/*  F0: halt PC */
name|u_int64_t
name|pcs_halt_ps
decl_stmt|;
comment|/*  F8: halt PS */
name|u_int64_t
name|pcs_halt_r25
decl_stmt|;
comment|/* 100: halt argument list */
name|u_int64_t
name|pcs_halt_r26
decl_stmt|;
comment|/* 108: halt return addr list */
name|u_int64_t
name|pcs_halt_r27
decl_stmt|;
comment|/* 110: halt procedure value */
define|#
directive|define
name|PCS_HALT_RESERVED
value|0
define|#
directive|define
name|PCS_HALT_POWERUP
value|1
define|#
directive|define
name|PCS_HALT_CONSOLE_HALT
value|2
define|#
directive|define
name|PCS_HALT_CONSOLE_CRASH
value|3
define|#
directive|define
name|PCS_HALT_KERNEL_MODE
value|4
define|#
directive|define
name|PCS_HALT_KERNEL_STACK_INVALID
value|5
define|#
directive|define
name|PCS_HALT_DOUBLE_ERROR_ABORT
value|6
define|#
directive|define
name|PCS_HALT_SCBB
value|7
define|#
directive|define
name|PCS_HALT_PTBR
value|8
comment|/* 9-FF: reserved */
name|u_int64_t
name|pcs_halt_reason
decl_stmt|;
comment|/* 118: */
name|u_int64_t
name|pcs_reserved_soft
decl_stmt|;
comment|/* 120: preserved software */
name|u_int64_t
name|pcs_buffer
index|[
literal|21
index|]
decl_stmt|;
comment|/* 128: console buffers */
define|#
directive|define
name|PALvar_reserved
value|0
define|#
directive|define
name|PALvar_OpenVMS
value|1
define|#
directive|define
name|PALvar_OSF1
value|2
name|u_int64_t
name|pcs_palrevisions
index|[
literal|16
index|]
decl_stmt|;
comment|/* 1D0: PALcode revisions */
name|u_int64_t
name|pcs_reserved_arch
index|[
literal|6
index|]
decl_stmt|;
comment|/* 250: reserved arch */
block|}
struct|;
end_struct

begin_comment
comment|/*  * CTB: Console Terminal Block  */
end_comment

begin_struct
struct|struct
name|ctb
block|{
name|u_int64_t
name|ctb_type
decl_stmt|;
comment|/*   0: always 4 */
name|u_int64_t
name|ctb_unit
decl_stmt|;
comment|/*   8: */
name|u_int64_t
name|ctb_reserved
decl_stmt|;
comment|/*  16: */
name|u_int64_t
name|ctb_len
decl_stmt|;
comment|/*  24: bytes of info */
name|u_int64_t
name|ctb_ipl
decl_stmt|;
comment|/*  32: console ipl level */
name|vm_offset_t
name|ctb_tintr_vec
decl_stmt|;
comment|/*  40: transmit vec (0x800) */
name|vm_offset_t
name|ctb_rintr_vec
decl_stmt|;
comment|/*  48: receive vec (0x800) */
define|#
directive|define
name|CTB_GRAPHICS
value|3
comment|/* graphics device */
define|#
directive|define
name|CTB_NETWORK
value|0xC0
comment|/* network device */
define|#
directive|define
name|CTB_PRINTERPORT
value|2
comment|/* printer port on the SCC */
name|u_int64_t
name|ctb_term_type
decl_stmt|;
comment|/*  56: terminal type */
name|u_int64_t
name|ctb_keybd_type
decl_stmt|;
comment|/*  64: keyboard nationality */
name|vm_offset_t
name|ctb_keybd_trans
decl_stmt|;
comment|/*  72: trans. table addr */
name|vm_offset_t
name|ctb_keybd_map
decl_stmt|;
comment|/*  80: map table addr */
name|u_int64_t
name|ctb_keybd_state
decl_stmt|;
comment|/*  88: keyboard flags */
name|u_int64_t
name|ctb_keybd_last
decl_stmt|;
comment|/*  96: last key entered */
name|vm_offset_t
name|ctb_font_us
decl_stmt|;
comment|/* 104: US font table addr */
name|vm_offset_t
name|ctb_font_mcs
decl_stmt|;
comment|/* 112: MCS font table addr */
name|u_int64_t
name|ctb_font_width
decl_stmt|;
comment|/* 120: font width, height */
name|u_int64_t
name|ctb_font_height
decl_stmt|;
comment|/* 128:		in pixels */
name|u_int64_t
name|ctb_mon_width
decl_stmt|;
comment|/* 136: monitor width, height */
name|u_int64_t
name|ctb_mon_height
decl_stmt|;
comment|/* 144:		in pixels */
name|u_int64_t
name|ctb_dpi
decl_stmt|;
comment|/* 152: monitor dots per inch */
name|u_int64_t
name|ctb_planes
decl_stmt|;
comment|/* 160: # of planes */
name|u_int64_t
name|ctb_cur_width
decl_stmt|;
comment|/* 168: cursor width, height */
name|u_int64_t
name|ctb_cur_height
decl_stmt|;
comment|/* 176:		in pixels */
name|u_int64_t
name|ctb_head_cnt
decl_stmt|;
comment|/* 184: # of heads */
name|u_int64_t
name|ctb_opwindow
decl_stmt|;
comment|/* 192: opwindow on screen */
name|vm_offset_t
name|ctb_head_offset
decl_stmt|;
comment|/* 200: offset to head info */
name|vm_offset_t
name|ctb_putchar
decl_stmt|;
comment|/* 208: output char to TURBO */
name|u_int64_t
name|ctb_io_state
decl_stmt|;
comment|/* 216: I/O flags */
name|u_int64_t
name|ctb_listen_state
decl_stmt|;
comment|/* 224: listener flags */
name|vm_offset_t
name|ctb_xaddr
decl_stmt|;
comment|/* 232: extended info addr */
name|u_int64_t
name|ctb_turboslot
decl_stmt|;
comment|/* 248: TURBOchannel slot # */
name|u_int64_t
name|ctb_server_off
decl_stmt|;
comment|/* 256: offset to server info */
name|u_int64_t
name|ctb_line_off
decl_stmt|;
comment|/* 264: line parameter offset */
name|u_int8_t
name|ctb_csd
decl_stmt|;
comment|/* 272: console specific data */
block|}
struct|;
end_struct

begin_comment
comment|/*   * CRD: Console Routine Descriptor  */
end_comment

begin_struct
struct|struct
name|crd
block|{
name|int64_t
name|descriptor
decl_stmt|;
name|u_int64_t
name|entry_va
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * CRB: Console Routine Block  */
end_comment

begin_struct
struct|struct
name|crb
block|{
name|struct
name|crd
modifier|*
name|crb_v_dispatch
decl_stmt|;
comment|/*   0: virtual dispatch addr */
name|vm_offset_t
name|crb_p_dispatch
decl_stmt|;
comment|/*   8: phys dispatch addr */
name|struct
name|crd
modifier|*
name|crb_v_fixup
decl_stmt|;
comment|/*  10: virtual fixup addr */
name|vm_offset_t
name|crb_p_fixup
decl_stmt|;
comment|/*  18: phys fixup addr */
name|u_int64_t
name|crb_map_cnt
decl_stmt|;
comment|/*  20: phys/virt map entries */
name|u_int64_t
name|crb_page_cnt
decl_stmt|;
comment|/*  28: pages to be mapped */
block|}
struct|;
end_struct

begin_comment
comment|/*  * MDDT: Memory Data Descriptor Table  */
end_comment

begin_struct
struct|struct
name|mddt
block|{
name|int64_t
name|mddt_cksum
decl_stmt|;
comment|/*   0: 7-N checksum */
name|vm_offset_t
name|mddt_physaddr
decl_stmt|;
comment|/*   8: bank config addr 						 * IMPLEMENTATION SPECIFIC 						 */
name|u_int64_t
name|mddt_cluster_cnt
decl_stmt|;
comment|/*  10: memory cluster count */
struct|struct
name|mddt_cluster
block|{
name|vm_offset_t
name|mddt_pfn
decl_stmt|;
comment|/*   0: starting PFN */
name|u_int64_t
name|mddt_pg_cnt
decl_stmt|;
comment|/*   8: 8KB page count */
name|u_int64_t
name|mddt_pg_test
decl_stmt|;
comment|/*  10: tested page count */
name|vm_offset_t
name|mddt_v_bitaddr
decl_stmt|;
comment|/*  18: bitmap virt addr */
name|vm_offset_t
name|mddt_p_bitaddr
decl_stmt|;
comment|/*  20: bitmap phys addr */
name|int64_t
name|mddt_bit_cksum
decl_stmt|;
comment|/*  28: bitmap checksum */
define|#
directive|define
name|MDDT_NONVOLATILE
value|0x10
comment|/* cluster is non-volatile */
define|#
directive|define
name|MDDT_PALCODE
value|0x01
comment|/* console and PAL only */
define|#
directive|define
name|MDDT_SYSTEM
value|0x00
comment|/* system software only */
define|#
directive|define
name|MDDT_mbz
value|0xfffffffffffffffc
comment|/* 2:63 -- must be zero */
name|int64_t
name|mddt_usage
decl_stmt|;
comment|/*  30: bitmap permissions */
block|}
name|mddt_clusters
index|[
literal|1
index|]
struct|;
comment|/* variable length array */
block|}
struct|;
end_struct

begin_comment
comment|/*  * DSR: Dynamic System Recognition.  We're interested in the sysname  * offset.  The data pointed to by sysname is:  *  *	[8 bytes: length of system name][N bytes: system name string]  *  * The system name string is NUL-terminated.  */
end_comment

begin_struct
struct|struct
name|dsrdb
block|{
name|int64_t
name|dsr_smm
decl_stmt|;
comment|/*  0: SMM number */
name|u_int64_t
name|dsr_lurt_off
decl_stmt|;
comment|/*  8: LURT table offset */
name|u_int64_t
name|dsr_sysname_off
decl_stmt|;
comment|/* 16: offset to sysname */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The DSR appeared in version 5 of the HWRPB.  */
end_comment

begin_define
define|#
directive|define
name|HWRPB_DSRDB_MINVERS
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASSEMBLER */
end_comment

end_unit

