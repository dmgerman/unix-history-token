begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University,  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)maxine.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log:	maxine.h,v $  * Revision 2.3  92/04/01  15:14:52  rpd  * 	Defined pseudo slot for mappable timer.  * 	[92/03/11  02:37:41  af]  *   * Revision 2.2  92/03/02  18:34:28  rpd  * 	Created, from the DEC specs:  * 	"MAXine System Module Functional Specification"  Revision 1.2  * 	Workstation Systems Engineering, Palo Alto, CA. July 15, 1991.  * 	[92/01/17            af]  *   */
end_comment

begin_comment
comment|/*  *	File: maxine.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	1/92  *  *	Definitions specific to the MAXine system module (54-21325-01)  *	and compatible processors (KN02BA).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_XINE_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_XINE_H
value|1
end_define

begin_comment
comment|/*  * MAXine's Physical address space  */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_MIN
value|0x00000000
end_define

begin_comment
comment|/* 512 Meg */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_MAX
value|0x1fffffff
end_define

begin_comment
comment|/*  * Memory map  */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_MEMORY_START
value|0x00000000
end_define

begin_define
define|#
directive|define
name|XINE_PHYS_MEMORY_END
value|0x027fffff
end_define

begin_comment
comment|/* 40 Meg in 2 slots 						   and baseboard */
end_comment

begin_comment
comment|/*  * I/O map  */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_CFB_START
value|0x08000000
end_define

begin_comment
comment|/* Color Frame Buffer */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_CFB_END
value|0x0bffffff
end_define

begin_comment
comment|/*  64 Meg */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_MREGS_START
value|0x0c000000
end_define

begin_comment
comment|/* Memory control registers */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_MREGS_END
value|0x0dffffff
end_define

begin_comment
comment|/*  32 Meg */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_CREGS_START
value|0x0e000000
end_define

begin_comment
comment|/* CPU ASIC control regs */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_CREGS_END
value|0x0fffffff
end_define

begin_comment
comment|/*  32 Meg */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_TC_0_START
value|0x10000000
end_define

begin_comment
comment|/* TURBOchannel, slot 0 */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_TC_0_END
value|0x13ffffff
end_define

begin_comment
comment|/*  64 Meg, option0 */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_TC_1_START
value|0x14000000
end_define

begin_comment
comment|/* TURBOchannel, slot 1 */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_TC_1_END
value|0x17ffffff
end_define

begin_comment
comment|/*  64 Meg, option1 */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_TC_RESERVED
value|0x18000000
end_define

begin_comment
comment|/* Unused slot 2 */
end_comment

begin_comment
comment|/*  64 Meg */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_TC_3_START
value|0x1c000000
end_define

begin_comment
comment|/* TURBOchannel, slot 3 */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_TC_3_END
value|0x1fffffff
end_define

begin_comment
comment|/*  64 Meg, system devices */
end_comment

begin_define
define|#
directive|define
name|XINE_PHYS_TC_START
value|XINE_PHYS_TC_0_START
end_define

begin_define
define|#
directive|define
name|XINE_PHYS_TC_END
value|XINE_PHYS_TC_3_END
end_define

begin_comment
comment|/* 256 Meg */
end_comment

begin_define
define|#
directive|define
name|XINE_TC_NSLOTS
value|4
end_define

begin_define
define|#
directive|define
name|XINE_TC_MIN
value|0
end_define

begin_define
define|#
directive|define
name|XINE_TC_MAX
value|1
end_define

begin_comment
comment|/* only option slots */
end_comment

begin_comment
comment|/* Pseudo-TCslots */
end_comment

begin_define
define|#
directive|define
name|XINE_FLOPPY_SLOT
value|2
end_define

begin_define
define|#
directive|define
name|XINE_SCSI_SLOT
value|3
end_define

begin_define
define|#
directive|define
name|XINE_LANCE_SLOT
value|4
end_define

begin_define
define|#
directive|define
name|XINE_SCC0_SLOT
value|5
end_define

begin_define
define|#
directive|define
name|XINE_DTOP_SLOT
value|6
end_define

begin_define
define|#
directive|define
name|XINE_ISDN_SLOT
value|7
end_define

begin_define
define|#
directive|define
name|XINE_CFB_SLOT
value|8
end_define

begin_define
define|#
directive|define
name|XINE_ASIC_SLOT
value|9
end_define

begin_define
define|#
directive|define
name|XINE_FRC_SLOT
value|10
end_define

begin_comment
comment|/*  * System module space  */
end_comment

begin_define
define|#
directive|define
name|XINE_SYS_ASIC
value|(XINE_PHYS_TC_3_START + 0x0000000)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_ROM_START
value|(XINE_SYS_ASIC + ASIC_SLOT_0_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_ASIC_REGS
value|(XINE_SYS_ASIC + ASIC_SLOT_1_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_ETHER_ADDRESS
value|(XINE_SYS_ASIC + ASIC_SLOT_2_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_LANCE
value|(XINE_SYS_ASIC + ASIC_SLOT_3_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_SCC_0
value|(XINE_SYS_ASIC + ASIC_SLOT_4_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_VDAC_HI
value|(XINE_SYS_ASIC + ASIC_SLOT_5_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_VDAC_LO
value|(XINE_SYS_ASIC + ASIC_SLOT_7_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_CLOCK
value|(XINE_SYS_ASIC + ASIC_SLOT_8_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_ISDN
value|(XINE_SYS_ASIC + ASIC_SLOT_9_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_DTOP
value|(XINE_SYS_ASIC + ASIC_SLOT_10_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_FLOPPY
value|(XINE_SYS_ASIC + ASIC_SLOT_11_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_SCSI
value|(XINE_SYS_ASIC + ASIC_SLOT_12_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_FLOPPY_DMA
value|(XINE_SYS_ASIC + ASIC_SLOT_13_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_SCSI_DMA
value|(XINE_SYS_ASIC + ASIC_SLOT_14_START)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_BOOT_ROM_START
value|(XINE_PHYS_TC_3_START + 0x3c00000)
end_define

begin_define
define|#
directive|define
name|XINE_SYS_BOOT_ROM_END
value|(XINE_PHYS_TC_3_START + 0x3c40000)
end_define

begin_comment
comment|/*  * Interrupts  */
end_comment

begin_define
define|#
directive|define
name|XINE_INT_FPA
value|IP_LEV7
end_define

begin_comment
comment|/* Floating Point coproc */
end_comment

begin_define
define|#
directive|define
name|XINE_INT_HALTB
value|IP_LEV6
end_define

begin_comment
comment|/* Halt keycode (DTOP) */
end_comment

begin_define
define|#
directive|define
name|XINE_INT_TC3
value|IP_LEV5
end_define

begin_comment
comment|/* TC slot 3, system */
end_comment

begin_define
define|#
directive|define
name|XINE_INT_TIMEOUT
value|IP_LEV4
end_define

begin_comment
comment|/* Timeout on I/O write */
end_comment

begin_define
define|#
directive|define
name|XINE_INT_TOY
value|IP_LEV3
end_define

begin_comment
comment|/* Clock chip */
end_comment

begin_define
define|#
directive|define
name|XINE_INT_1_10_MS
value|IP_LEV2
end_define

begin_comment
comment|/* Periodic interrupt */
end_comment

begin_comment
comment|/*  *  System registers addresses (MREG and CREG space, and IO Control ASIC)  */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_CMR
value|0x0c000000
end_define

begin_comment
comment|/* Color mask register */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_MER
value|0x0c400000
end_define

begin_comment
comment|/* Memory error register */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_MSR
value|0x0c800000
end_define

begin_comment
comment|/* Memory size register */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_FCTR
value|0x0ca00000
end_define

begin_comment
comment|/* 1us free running counter */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_FI
value|0x0cc00000
end_define

begin_comment
comment|/* FI signal polarity (1!) */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_CNFG
value|0x0e000000
end_define

begin_comment
comment|/* Config mem timeouts */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_AER
value|0x0e000004
end_define

begin_comment
comment|/* Address error register */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_TIMEOUT
value|0x0e00000c
end_define

begin_comment
comment|/* I/O write timeout reg */
end_comment

begin_define
define|#
directive|define
name|XINE_REG_SCSI_DMAPTR
value|( XINE_SYS_ASIC + ASIC_SCSI_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_SCSI_DMANPTR
value|( XINE_SYS_ASIC + ASIC_SCSI_NEXTPTR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_LANCE_DMAPTR
value|( XINE_SYS_ASIC + ASIC_LANCE_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_SCC_T1_DMAPTR
value|( XINE_SYS_ASIC + ASIC_SCC_T1_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_SCC_R1_DMAPTR
value|( XINE_SYS_ASIC + ASIC_SCC_R1_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_DTOP_T_DMAPTR
value|( XINE_SYS_ASIC + ASIC_SCC_T2_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_DTOP_R_DMAPTR
value|( XINE_SYS_ASIC + ASIC_SCC_R2_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_FLOPPY_DMAPTR
value|( XINE_SYS_ASIC + ASIC_FLOPPY_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_ISDN_X_DMAPTR
value|( XINE_SYS_ASIC + ASIC_ISDN_X_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_ISDN_X_NEXTPTR
value|( XINE_SYS_ASIC + ASIC_ISDN_X_NEXTPTR )
end_define

begin_define
define|#
directive|define
name|XINE_ISDN_R_DMAPTR
value|( XINE_SYS_ASIC + ASIC_ISDN_R_DMAPTR )
end_define

begin_define
define|#
directive|define
name|XINE_ISDN_R_NEXTPTR
value|( XINE_SYS_ASIC + ASIC_ISDN_R_NEXTPTR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_CSR
value|( XINE_SYS_ASIC + ASIC_CSR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_INTR
value|( XINE_SYS_ASIC + ASIC_INTR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_IMSK
value|( XINE_SYS_ASIC + ASIC_IMSK )
end_define

begin_define
define|#
directive|define
name|XINE_REG_CURADDR
value|( XINE_SYS_ASIC + ASIC_CURADDR )
end_define

begin_define
define|#
directive|define
name|XINE_ISDN_X_DATA
value|( XINE_SYS_ASIC + ASIC_ISDN_X_DATA )
end_define

begin_define
define|#
directive|define
name|XINE_ISDN_R_DATA
value|( XINE_SYS_ASIC + ASIC_ISDN_R_DATA )
end_define

begin_define
define|#
directive|define
name|XINE_REG_LANCE_DECODE
value|( XINE_SYS_ASIC + ASIC_LANCE_DECODE )
end_define

begin_define
define|#
directive|define
name|XINE_REG_SCSI_DECODE
value|( XINE_SYS_ASIC + ASIC_SCSI_DECODE )
end_define

begin_define
define|#
directive|define
name|XINE_REG_SCC0_DECODE
value|( XINE_SYS_ASIC + ASIC_SCC0_DECODE )
end_define

begin_define
define|#
directive|define
name|XINE_REG_DTOP_DECODE
value|( XINE_SYS_ASIC + ASIC_SCC1_DECODE )
end_define

begin_define
define|#
directive|define
name|XINE_REG_FLOPPY_DECODE
value|( XINE_SYS_ASIC + ASIC_FLOPPY_DECODE )
end_define

begin_define
define|#
directive|define
name|XINE_LANCE_CONFIG
value|3
end_define

begin_define
define|#
directive|define
name|XINE_SCSI_CONFIG
value|14
end_define

begin_define
define|#
directive|define
name|XINE_SCC0_CONFIG
value|(0x10|4)
end_define

begin_define
define|#
directive|define
name|XINE_DTOP_CONFIG
value|10
end_define

begin_define
define|#
directive|define
name|XINE_FLOPPY_CONFIG
value|13
end_define

begin_define
define|#
directive|define
name|XINE_REG_SCSI_SCR
value|( XINE_SYS_ASIC + ASIC_SCSI_SCR )
end_define

begin_define
define|#
directive|define
name|XINE_REG_SCSI_SDR0
value|( XINE_SYS_ASIC + ASIC_SCSI_SDR0 )
end_define

begin_define
define|#
directive|define
name|XINE_REG_SCSI_SDR1
value|( XINE_SYS_ASIC + ASIC_SCSI_SDR1 )
end_define

begin_comment
comment|/*  *  System registers defines (MREG and CREG)  */
end_comment

begin_comment
comment|/* Memory error register */
end_comment

begin_define
define|#
directive|define
name|XINE_MER_xxx
value|0xf7fe30ff
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|XINE_MER_10_1_MS_IP
value|0x08000000
end_define

begin_comment
comment|/* rw: Periodic interrupt */
end_comment

begin_define
define|#
directive|define
name|XINE_MER_PAGE_BRY
value|0x00010000
end_define

begin_comment
comment|/* rw: Page boundary error */
end_comment

begin_define
define|#
directive|define
name|XINE_MER_TLEN
value|0x00008000
end_define

begin_comment
comment|/* rw: Xfer length error */
end_comment

begin_define
define|#
directive|define
name|XINE_MER_PARDIS
value|0x00004000
end_define

begin_comment
comment|/* rw: Dis parity err intr */
end_comment

begin_define
define|#
directive|define
name|XINE_MER_LASTBYTE
value|0x00000f00
end_define

begin_comment
comment|/* rz: Last byte in error: */
end_comment

begin_define
define|#
directive|define
name|XINE_LASTB31
value|0x00000800
end_define

begin_comment
comment|/* upper byte of word */
end_comment

begin_define
define|#
directive|define
name|XINE_LASTB23
value|0x00000400
end_define

begin_comment
comment|/* .. through .. */
end_comment

begin_define
define|#
directive|define
name|XINE_LASTB15
value|0x00000200
end_define

begin_comment
comment|/* .. the .. */
end_comment

begin_define
define|#
directive|define
name|XINE_LASTB07
value|0x00000100
end_define

begin_comment
comment|/* .. lower byte */
end_comment

begin_comment
comment|/* Memory size register */
end_comment

begin_define
define|#
directive|define
name|XINE_MSR_xxx
value|0xffffdfff
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|XINE_MSR_10_1_MS_EN
value|0x04000000
end_define

begin_comment
comment|/* rw: enable periodic intr */
end_comment

begin_define
define|#
directive|define
name|XINE_MSR_10_1_MS
value|0x02000000
end_define

begin_comment
comment|/* rw: intr. freq. (0->1ms) */
end_comment

begin_define
define|#
directive|define
name|XINE_MSR_PFORCE
value|0x01e00000
end_define

begin_comment
comment|/* rw: force parity errors */
end_comment

begin_define
define|#
directive|define
name|XINE_MSR_MABEN
value|0x00100000
end_define

begin_comment
comment|/* rw: VRAM ignores SIZE */
end_comment

begin_define
define|#
directive|define
name|XINE_MSR_LAST_BANK
value|0x000e0000
end_define

begin_comment
comment|/* rw: map baseboard mem */
end_comment

begin_define
define|#
directive|define
name|XINE_BANK_0
value|0x00020000
end_define

begin_comment
comment|/* .. at bank 0, .. */
end_comment

begin_define
define|#
directive|define
name|XINE_BANK_1
value|0x00040000
end_define

begin_comment
comment|/* .. at bank 1, .. */
end_comment

begin_define
define|#
directive|define
name|XINE_BANK_2
value|0x00080000
end_define

begin_comment
comment|/* .. or at bank 2  */
end_comment

begin_define
define|#
directive|define
name|XINE_MSR_SIZE_16Mb
value|0x00002000
end_define

begin_comment
comment|/* rw: using 16Mb mem banks */
end_comment

begin_comment
comment|/* FI register */
end_comment

begin_define
define|#
directive|define
name|XINE_FI_VALUE
value|0x00001000
end_define

begin_comment
comment|/* NOTES     Memory access priority is, from higher to lower: 	- VRAM/DRAM refresh 	- IO DMA (IO Control ASIC) 	- Slot 0 DMA 	- Processor 	- Slot 1 DMA     Memory performance is (with 80ns mem cycles) 	- single word read	 5 cyc		10.0 Mb/s 	- word write		 3 cyc		16.7 Mb/s 	- single byte write	 3 cyc		 4.2 Mb/s 	- 64w DMA read		68 cyc		47.1 Mb/s 	- 64w DMA write		66 cyc		48.5 Mb/s 	- Refresh		 5 cyc		N/A  */
end_comment

begin_comment
comment|/* Timeout config register */
end_comment

begin_define
define|#
directive|define
name|XINE_CNFG_VALUE
value|121
end_define

begin_comment
comment|/* Address error register */
end_comment

begin_define
define|#
directive|define
name|XINE_AER_ADDR_MASK
value|0x1ffffffc
end_define

begin_comment
comment|/* ro: phys addr in error */
end_comment

begin_comment
comment|/* Memory access timeout interrupt register */
end_comment

begin_define
define|#
directive|define
name|XINE_TIMEO_INTR
value|0x00000001
end_define

begin_comment
comment|/* rc: intr pending */
end_comment

begin_comment
comment|/*  * More system registers defines (IO Control ASIC)  */
end_comment

begin_comment
comment|/* (re)defines for the system Status and Control register (SSR) */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_T1
value|ASIC_CSR_DMAEN_T1
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_R1
value|ASIC_CSR_DMAEN_R1
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_DTOP_T
value|ASIC_CSR_DMAEN_T2
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_DTOP_R
value|ASIC_CSR_DMAEN_R2
end_define

begin_define
define|#
directive|define
name|XINE_CSR_FLOPPY_DIR
value|ASIC_CSR_FLOPPY_DIR
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_FLOPPY
value|ASIC_CSR_DMAEN_FLOPPY
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_ISDN_T
value|ASIC_CSR_DMAEN_ISDN_T
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_ISDN_R
value|ASIC_CSR_DMAEN_ISDN_R
end_define

begin_define
define|#
directive|define
name|XINE_CSR_SCSI_DIR
value|ASIC_CSR_SCSI_DIR
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_SCSI
value|ASIC_CSR_DMAEN_SCSI
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DMAEN_LANCE
value|ASIC_CSR_DMAEN_LANCE
end_define

begin_define
define|#
directive|define
name|XINE_CSR_DIAGDN
value|0x00008000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_ISDN_ENABLE
value|0x00001000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_SCC_ENABLE
value|0x00000800
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_RTC_ENABLE
value|0x00000400
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_SCSI_ENABLE
value|0x00000200
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_LANCE_ENABLE
value|0x00000100
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_FLOPPY_ENABLE
value|0x00000080
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_VDAC_ENABLE
value|0x00000040
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_DTOP_ENABLE
value|0x00000020
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|XINE_CSR_LED
value|0x00000001
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* (re)defines for the System Interrupt and Mask Registers */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_T1_PAGE_END
value|ASIC_INTR_T1_PAGE_END
end_define

begin_define
define|#
directive|define
name|XINE_INTR_T1_READ_E
value|ASIC_INTR_T1_READ_E
end_define

begin_define
define|#
directive|define
name|XINE_INTR_R1_HALF_PAGE
value|ASIC_INTR_R1_HALF_PAGE
end_define

begin_define
define|#
directive|define
name|XINE_INTR_R1_DMA_OVRUN
value|ASIC_INTR_R1_DMA_OVRUN
end_define

begin_define
define|#
directive|define
name|XINE_INTR_DT_PAGE_END
value|ASIC_INTR_T2_PAGE_END
end_define

begin_define
define|#
directive|define
name|XINE_INTR_DT_READ_E
value|ASIC_INTR_T2_READ_E
end_define

begin_define
define|#
directive|define
name|XINE_INTR_DT_HALF_PAGE
value|ASIC_INTR_R2_HALF_PAGE
end_define

begin_define
define|#
directive|define
name|XINE_INTR_DT_DMA_OVRUN
value|ASIC_INTR_R2_DMA_OVRUN
end_define

begin_define
define|#
directive|define
name|XINE_INTR_FLOPPY_DMA_E
value|ASIC_INTR_FLOPPY_DMA_E
end_define

begin_define
define|#
directive|define
name|XINE_INTR_ISDN_PTR_LOAD
value|ASIC_INTR_ISDN_PTR_LOAD
end_define

begin_define
define|#
directive|define
name|XINE_INTR_ISDN_OVRUN
value|ASIC_INTR_ISDN_OVRUN
end_define

begin_define
define|#
directive|define
name|XINE_INTR_ISDN_READ_E
value|ASIC_INTR_ISDN_READ_E
end_define

begin_define
define|#
directive|define
name|XINE_INTR_SCSI_PTR_LOAD
value|ASIC_INTR_SCSI_PTR_LOAD
end_define

begin_define
define|#
directive|define
name|XINE_INTR_SCSI_OVRUN
value|ASIC_INTR_SCSI_OVRUN
end_define

begin_define
define|#
directive|define
name|XINE_INTR_SCSI_READ_E
value|ASIC_INTR_SCSI_READ_E
end_define

begin_define
define|#
directive|define
name|XINE_INTR_LANCE_READ_E
value|ASIC_INTR_LANCE_READ_E
end_define

begin_define
define|#
directive|define
name|XINE_INTR_xxxx
value|0x00002808
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_FLOPPY
value|0x00008000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_NVR_JUMPER
value|0x00004000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_POWERUP
value|0x00002000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_TC_0
value|0x00001000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_ISDN
value|0x00000800
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_NRMOD_JUMPER
value|0x00000400
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_SCSI
value|0x00000200
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_LANCE
value|0x00000100
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_FLOPPY_HDS
value|0x00000080
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_SCC_0
value|0x00000040
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_TC_1
value|0x00000020
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_FLOPPY_XDS
value|0x00000010
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_VINT
value|0x00000008
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_N_VINT
value|0x00000004
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_DTOP_TX
value|0x00000002
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_DTOP_RX
value|0x00000001
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|XINE_INTR_ASIC
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|XINE_INTR_DTOP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|XINE_IM0
value|0xffff9b6b
end_define

begin_comment
comment|/* all good ones enabled */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS_XINE_H */
end_comment

end_unit

