begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University,  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)kn02.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log:	kn02.h,v $  * Revision 2.5  91/05/14  17:23:30  mrt  * 	Correcting copyright  *   * Revision 2.4  91/02/05  17:42:03  mrt  * 	Added author notices  * 	[91/02/04  11:14:23  mrt]  *   * 	Changed to use new Mach copyright  * 	[91/02/02  12:12:58  mrt]  *   * Revision 2.3  90/12/05  23:32:04  af  *   *   * Revision 2.1.1.2  90/11/01  02:48:10  af  * 	Reworked a bit, made reentrant.  *   * Revision 2.1.1.1  90/10/03  11:48:22  af  * 	Created, from the DEC specs:  * 	"DECstation 5000/200 KN02 System Module Functional Specification"  * 	Workstation Systems Engineering, Palo Alto, CA. Aug 27, 1990.  * 	[90/09/03            af]  */
end_comment

begin_comment
comment|/*  *	File: kn02.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	9/90  *  *	Definitions specific to the KN02 processor (3max)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_KN02_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_KN02_H
value|1
end_define

begin_comment
comment|/*  * KN02's Physical address space  */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_MIN
value|0x00000000
end_define

begin_comment
comment|/* 512 Meg */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_MAX
value|0x1fffffff
end_define

begin_comment
comment|/*  * Memory map  */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_MEMORY_START
value|0x00000000
end_define

begin_define
define|#
directive|define
name|KN02_PHYS_MEMORY_END
value|0x1dffffff
end_define

begin_comment
comment|/* 480 Meg in 15 slots */
end_comment

begin_comment
comment|/*  * I/O map  */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_0_START
value|0x1e000000
end_define

begin_comment
comment|/* TURBOchannel, slot 0 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_0_END
value|0x1e3fffff
end_define

begin_comment
comment|/*   4 Meg, option0 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_1_START
value|0x1e400000
end_define

begin_comment
comment|/* TURBOchannel, slot 1 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_1_END
value|0x1e7fffff
end_define

begin_comment
comment|/*   4 Meg, option1 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_2_START
value|0x1e800000
end_define

begin_comment
comment|/* TURBOchannel, slot 2 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_2_END
value|0x1ebfffff
end_define

begin_comment
comment|/*   4 Meg, option2 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_3_START
value|0x1ec00000
end_define

begin_comment
comment|/* TURBOchannel, slot 3 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_3_END
value|0x1effffff
end_define

begin_comment
comment|/*   4 Meg, reserved*/
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_4_START
value|0x1f000000
end_define

begin_comment
comment|/* TURBOchannel, slot 4 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_4_END
value|0x1f3fffff
end_define

begin_comment
comment|/*   4 Meg, reserved*/
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_5_START
value|0x1f400000
end_define

begin_comment
comment|/* TURBOchannel, slot 5 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_5_END
value|0x1f7fffff
end_define

begin_comment
comment|/*   4 Meg, SCSI */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_6_START
value|0x1f800000
end_define

begin_comment
comment|/* TURBOchannel, slot 6 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_6_END
value|0x1fbfffff
end_define

begin_comment
comment|/*   4 Meg, ether */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_7_START
value|0x1fc00000
end_define

begin_comment
comment|/* TURBOchannel, slot 7 */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_7_END
value|0x1fffffff
end_define

begin_comment
comment|/*   4 Meg, system devices */
end_comment

begin_define
define|#
directive|define
name|KN02_PHYS_TC_START
value|KN02_PHYS_TC_0_START
end_define

begin_define
define|#
directive|define
name|KN02_PHYS_TC_END
value|KN02_PHYS_TC_7_END
end_define

begin_comment
comment|/* 32 Meg */
end_comment

begin_define
define|#
directive|define
name|KN02_TC_NSLOTS
value|8
end_define

begin_define
define|#
directive|define
name|KN02_TC_MIN
value|0
end_define

begin_define
define|#
directive|define
name|KN02_TC_MAX
value|6
end_define

begin_comment
comment|/* don't look at system slot */
end_comment

begin_comment
comment|/*  * System devices  */
end_comment

begin_define
define|#
directive|define
name|KN02_SYS_ROM_START
value|KN02_PHYS_TC_7_START+0x000000
end_define

begin_define
define|#
directive|define
name|KN02_SYS_ROM_END
value|KN02_PHYS_TC_7_START+0x07ffff
end_define

begin_define
define|#
directive|define
name|KN02_SYS_RESERVED
value|KN02_PHYS_TC_7_START+0x080000
end_define

begin_define
define|#
directive|define
name|KN02_SYS_CHKSYN
value|KN02_PHYS_TC_7_START+0x100000
end_define

begin_define
define|#
directive|define
name|KN02_SYS_ERRADR
value|KN02_PHYS_TC_7_START+0x180000
end_define

begin_define
define|#
directive|define
name|KN02_SYS_DZ
value|KN02_PHYS_TC_7_START+0x200000
end_define

begin_define
define|#
directive|define
name|KN02_SYS_CLOCK
value|KN02_PHYS_TC_7_START+0x280000
end_define

begin_define
define|#
directive|define
name|KN02_SYS_CSR
value|KN02_PHYS_TC_7_START+0x300000
end_define

begin_define
define|#
directive|define
name|KN02_SYS_ROM1_START
value|KN02_PHYS_TC_7_START+0x380000
end_define

begin_define
define|#
directive|define
name|KN02_SYS_ROM1_END
value|KN02_PHYS_TC_7_START+0x3fffff
end_define

begin_comment
comment|/*  * Interrupts  */
end_comment

begin_define
define|#
directive|define
name|KN02_INT_FPA
value|IP_LEV7
end_define

begin_comment
comment|/* Floating Point coproc */
end_comment

begin_define
define|#
directive|define
name|KN02_INT_RES1
value|IP_LEV6
end_define

begin_comment
comment|/* reserved, unused */
end_comment

begin_define
define|#
directive|define
name|KN02_INT_MEM
value|IP_LEV5
end_define

begin_comment
comment|/* memory controller */
end_comment

begin_define
define|#
directive|define
name|KN02_INT_RES2
value|IP_LEV4
end_define

begin_comment
comment|/* reserved, unused */
end_comment

begin_define
define|#
directive|define
name|KN02_INT_CLOCK
value|IP_LEV3
end_define

begin_comment
comment|/* rtc chip */
end_comment

begin_define
define|#
directive|define
name|KN02_INT_IO
value|IP_LEV2
end_define

begin_comment
comment|/* I/O slots */
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
name|KN02_CSR_IOINT
value|0x000000ff
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Interrupt pending */
end_comment

begin_define
define|#
directive|define
name|KN02_IP_DZ
value|0x00000080
end_define

begin_comment
comment|/* serial lines */
end_comment

begin_define
define|#
directive|define
name|KN02_IP_LANCE
value|0x00000040
end_define

begin_comment
comment|/* thin ethernet */
end_comment

begin_define
define|#
directive|define
name|KN02_IP_SCSI
value|0x00000020
end_define

begin_comment
comment|/* ASC scsi controller */
end_comment

begin_define
define|#
directive|define
name|KN02_IP_XXXX
value|0x00000018
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|KN02_IP_SLOT2
value|0x00000004
end_define

begin_comment
comment|/* option slot 2 */
end_comment

begin_define
define|#
directive|define
name|KN02_IP_SLOT1
value|0x00000002
end_define

begin_comment
comment|/* option slot 1 */
end_comment

begin_define
define|#
directive|define
name|KN02_IP_SLOT0
value|0x00000001
end_define

begin_comment
comment|/* option slot 0 */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_BAUD38
value|0x00000100
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Max DZ baud rate */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_DIAGDN
value|0x00000200
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Diag jumper */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_BNK32M
value|0x00000400
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Memory bank stride */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_TXDIS
value|0x00000800
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
name|KN02_CSR_LEDIAG
value|0x00001000
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* Latch ECC */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_CORRECT
value|0x00002000
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* ECC corrects single bit */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_ECCMD
value|0x0000c000
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* ECC logic mode */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_IOINTEN
value|0x00ff0000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_IOINTEN_SHIFT
value|16
end_define

begin_comment
comment|/* Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_NRMMOD
value|0x01000000
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Diag jumper state */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_REFEVEN
value|0x02000000
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Refreshing even mem bank */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_PRSVNVR
value|0x04000000
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* Preserve NVR jumper */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_PSWARN
value|0x08000000
end_define

begin_comment
comment|/* ro */
end_comment

begin_comment
comment|/* PS overheating */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_RRESERVED
value|0xf0000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_LEDS
value|0x000000ff
end_define

begin_comment
comment|/* wo */
end_comment

begin_comment
comment|/* Diag LEDs */
end_comment

begin_define
define|#
directive|define
name|KN02_CSR_WRESERVED
value|0xff000000
end_define

begin_comment
comment|/* wz */
end_comment

begin_comment
comment|/* Error address status register */
end_comment

begin_define
define|#
directive|define
name|KN02_ERR_ADDRESS
value|0x07ffffff
end_define

begin_comment
comment|/* phys address */
end_comment

begin_define
define|#
directive|define
name|KN02_ERR_RESERVED
value|0x08000000
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|KN02_ERR_ECCERR
value|0x10000000
end_define

begin_comment
comment|/* ECC error */
end_comment

begin_define
define|#
directive|define
name|KN02_ERR_WRITE
value|0x20000000
end_define

begin_comment
comment|/* read/write transaction */
end_comment

begin_define
define|#
directive|define
name|KN02_ERR_CPU
value|0x40000000
end_define

begin_comment
comment|/* CPU or device initiator */
end_comment

begin_define
define|#
directive|define
name|KN02_ERR_VALID
value|0x80000000
end_define

begin_comment
comment|/* Info is valid */
end_comment

begin_comment
comment|/* ECC check/syndrome status register */
end_comment

begin_define
define|#
directive|define
name|KN02_ECC_SYNLO
value|0x0000007f
end_define

begin_comment
comment|/* syndrome, even bank	*/
end_comment

begin_define
define|#
directive|define
name|KN02_ECC_SNGLO
value|0x00000080
end_define

begin_comment
comment|/* single bit err, " 	*/
end_comment

begin_define
define|#
directive|define
name|KN02_ECC_CHKLO
value|0x00007f00
end_define

begin_comment
comment|/* check bits,	"  "	*/
end_comment

begin_define
define|#
directive|define
name|KN02_ECC_VLDLO
value|0x00008000
end_define

begin_comment
comment|/* info valid for  "	*/
end_comment

begin_define
define|#
directive|define
name|KN02_ECC_SYNHI
value|0x007f0000
end_define

begin_comment
comment|/* syndrome, odd bank	*/
end_comment

begin_define
define|#
directive|define
name|KN02_ECC_SNGHI
value|0x00800000
end_define

begin_comment
comment|/* single bit err, "	*/
end_comment

begin_define
define|#
directive|define
name|KN02_ECC_CHKHI
value|0x7f000000
end_define

begin_comment
comment|/* check bits,  "  "	*/
end_comment

begin_define
define|#
directive|define
name|KN02_ECC_VLDHI
value|0x80000000
end_define

begin_comment
comment|/* info valid for  "	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS_KN02_H */
end_comment

end_unit

