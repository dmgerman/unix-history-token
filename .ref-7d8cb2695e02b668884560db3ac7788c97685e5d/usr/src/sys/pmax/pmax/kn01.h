begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University,  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)kn01.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log:	kn01.h,v $  * Revision 2.5  91/05/14  17:23:14  mrt  * 	Correcting copyright  *   * Revision 2.4  91/02/05  17:41:54  mrt  * 	Added author notices  * 	[91/02/04  11:14:12  mrt]  *   * 	Changed to use new Mach copyright  * 	[91/02/02  12:12:45  mrt]  *   * Revision 2.3  90/12/05  23:31:50  af  * 	Cleanups.  * 	[90/12/04  16:38:21  af]  *   * 	Created, from the DEC specs:  * 	"DECstation 3100 Desktop Workstation Functional Specification"  * 	Workstation Systems Engineering, Palo Alto, CA. Aug 28, 1990.  * 	[90/09/03            af]  */
end_comment

begin_comment
comment|/*  *	File: kn01.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	9/90  *  *	Definitions specific to the KN01 processor (pmax)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_KN01_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_KN01_H
value|1
end_define

begin_comment
comment|/*  * KN01's Physical address space  */
end_comment

begin_define
define|#
directive|define
name|KN01_PHYS_MIN
value|0x00000000
end_define

begin_comment
comment|/* 512 Meg */
end_comment

begin_define
define|#
directive|define
name|KN01_PHYS_MAX
value|0x1fffffff
end_define

begin_comment
comment|/*  * Memory map  */
end_comment

begin_define
define|#
directive|define
name|KN01_PHYS_MEMORY_START
value|0x00000000
end_define

begin_define
define|#
directive|define
name|KN01_PHYS_MEMORY_END
value|0x01800000
end_define

begin_comment
comment|/* 24 Meg in 8 slots */
end_comment

begin_define
define|#
directive|define
name|KN01_PHYS_FBUF_START
value|0x0fc00000
end_define

begin_comment
comment|/* frame buffer memory */
end_comment

begin_define
define|#
directive|define
name|KN01_PHYS_FBUF_M_END
value|0x0fc20000
end_define

begin_comment
comment|/* mono */
end_comment

begin_define
define|#
directive|define
name|KN01_PHYS_FBUF_C_END
value|0x0fd00000
end_define

begin_comment
comment|/* color */
end_comment

begin_define
define|#
directive|define
name|KN01_PHYS_COLMASK_START
value|0x10000000
end_define

begin_comment
comment|/* Color Plane mask */
end_comment

begin_define
define|#
directive|define
name|KN01_PHYS_COLMASK_END
value|0x11000000
end_define

begin_comment
comment|/* Color Plane mask */
end_comment

begin_comment
comment|/*  * I/O map  */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_PCC
value|0x11000000
end_define

begin_comment
comment|/* Progr. Cursor Chip */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_VDAC
value|0x12000000
end_define

begin_comment
comment|/* Color map */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_ERRADR
value|0x17000000
end_define

begin_comment
comment|/* Write error address */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_LANCE
value|0x18000000
end_define

begin_comment
comment|/* Lance chip */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_LANCE_B_START
value|0x19000000
end_define

begin_comment
comment|/* 64 Kb Lance Buffer */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_LANCE_B_END
value|0x19010000
end_define

begin_define
define|#
directive|define
name|KN01_SYS_SII
value|0x1a000000
end_define

begin_comment
comment|/* scsi SII chip */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_SII_B_START
value|0x1b000000
end_define

begin_comment
comment|/* 128 Kb SCSI buffer */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_SII_B_END
value|0x1b020000
end_define

begin_define
define|#
directive|define
name|KN01_SYS_DZ
value|0x1c000000
end_define

begin_comment
comment|/* Serial lines (DZ) */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_CLOCK
value|0x1d000000
end_define

begin_comment
comment|/* rtc chip */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_CSR
value|0x1e000000
end_define

begin_comment
comment|/* System control register */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_ROM_START
value|0x1f000000
end_define

begin_comment
comment|/* System ROM */
end_comment

begin_define
define|#
directive|define
name|KN01_SYS_ROM_END
value|0x1f07ffff
end_define

begin_comment
comment|/*  * Interrupts  */
end_comment

begin_define
define|#
directive|define
name|KN01_INT_FPA
value|IP_LEV7
end_define

begin_comment
comment|/* Floating Point coproc */
end_comment

begin_define
define|#
directive|define
name|KN01_INT_MEM
value|IP_LEV6
end_define

begin_comment
comment|/* memory controller */
end_comment

begin_define
define|#
directive|define
name|KN01_INT_CLOCK
value|IP_LEV5
end_define

begin_comment
comment|/* rtc chip */
end_comment

begin_define
define|#
directive|define
name|KN01_INT_DZ
value|IP_LEV4
end_define

begin_comment
comment|/* serial line chip */
end_comment

begin_define
define|#
directive|define
name|KN01_INT_LANCE
value|IP_LEV3
end_define

begin_comment
comment|/* ether */
end_comment

begin_define
define|#
directive|define
name|KN01_INT_SII
value|IP_LEV2
end_define

begin_comment
comment|/* SCSI interface */
end_comment

begin_comment
comment|/*  * System board registers  */
end_comment

begin_comment
comment|/* system Status and Control register */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_LEDS_MASK
value|0x00ff
end_define

begin_comment
comment|/* wo */
end_comment

begin_comment
comment|/* Diagnostic leds mask */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_VRGTRB
value|0x0001
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Red VoltageLev> Blue */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_VRGTRG
value|0x0002
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Red VoltageLev> Green */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_VBGTRG
value|0x0004
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Blue VoltageLev> Green */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_TXDIS
value|0x0100
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Disable DZ xmit */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_VINT
value|0x0200
end_define

begin_comment
comment|/* rc */
end_comment

begin_comment
comment|/* Vertical retrace intr. */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_MERR
value|0x0400
end_define

begin_comment
comment|/* rc */
end_comment

begin_comment
comment|/* Memory write error intr */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_MONO
value|0x0800
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Mono Framebuf (or none) */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_CRSRTST
value|0x1000
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Cursor test output */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_PARDIS
value|0x2000
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Disable mem parity chks */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_SELFTEST
value|0x4000
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Self-test ok pinout */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_MNFMOD
value|0x8000
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Manifacturer MOD jumper */
end_comment

begin_define
define|#
directive|define
name|KN01_CSR_MBZ
value|0x9800
end_define

begin_comment
comment|/* Error address status register */
end_comment

begin_define
define|#
directive|define
name|KN01_ERR_ADDRESS
value|0x07ffffff
end_define

begin_comment
comment|/* phys address mask ? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS_KN01_H */
end_comment

end_unit

