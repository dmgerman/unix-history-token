begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University,  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)kmin.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * HISTORY  * $Log:	kmin.h,v $  * Revision 2.3  92/03/02  18:33:43  rpd  * 	Split out the ASIC defns into separate file, which is  * 	in common with MAXine.  Added some nitwits defines.  * 	[92/03/02  02:28:27  af]  *   * Revision 2.2  91/08/24  12:21:08  af  * 	Documented new SCSI registers, which were missing in the 3min prototype.  * 	[91/08/22  11:14:57  af]  *   * 	Created, from the DEC specs:  * 	"3MIN System Module Functional Specification"  Revision 1.7  * 	Workstation Systems Engineering, Palo Alto, CA. Sept 14, 1990.  * 	"KN02BA Daughter Card Functional Specification" Revision 1.0  * 	Workstation Systems Engineering, Palo Alto, CA. Aug  14, 1990.  * 	[91/06/21            af]  *   */
end_comment

begin_comment
comment|/*  *	File: kmin.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	6/91  *  *	Definitions specific to the KN02BA/KN02DA processors and 3MIN  *	system module (54-20604-01)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_KMIN_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_KMIN_H
value|1
end_define

begin_comment
comment|/*  * 3MIN's Physical address space  */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_MIN
value|0x00000000
end_define

begin_comment
comment|/* 512 Meg */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_MAX
value|0x1fffffff
end_define

begin_comment
comment|/*  * Memory map  */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_MEMORY_START
value|0x00000000
end_define

begin_define
define|#
directive|define
name|KMIN_PHYS_MEMORY_END
value|0x07ffffff
end_define

begin_comment
comment|/* 128 Meg in 8 slots */
end_comment

begin_comment
comment|/*  * I/O map  */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_RESERVED
value|0x08000000
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_comment
comment|/*  64 Meg */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_MREGS_START
value|0x0c000000
end_define

begin_comment
comment|/* Memory control registers */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_MREGS_END
value|0x0dffffff
end_define

begin_comment
comment|/*  32 Meg */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_CREGS_START
value|0x0e000000
end_define

begin_comment
comment|/* CPU ASIC control regs */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_CREGS_END
value|0x0fffffff
end_define

begin_comment
comment|/*  32 Meg */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_0_START
value|0x10000000
end_define

begin_comment
comment|/* TURBOchannel, slot 0 */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_0_END
value|0x13ffffff
end_define

begin_comment
comment|/*  64 Meg, option0 */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_1_START
value|0x14000000
end_define

begin_comment
comment|/* TURBOchannel, slot 1 */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_1_END
value|0x17ffffff
end_define

begin_comment
comment|/*  64 Meg, option1 */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_2_START
value|0x18000000
end_define

begin_comment
comment|/* TURBOchannel, slot 2 */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_2_END
value|0x1bffffff
end_define

begin_comment
comment|/*  64 Meg, option2 */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_3_START
value|0x1c000000
end_define

begin_comment
comment|/* TURBOchannel, slot 3 */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_3_END
value|0x1fffffff
end_define

begin_comment
comment|/*  64 Meg, system devices */
end_comment

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_START
value|KMIN_PHYS_TC_0_START
end_define

begin_define
define|#
directive|define
name|KMIN_PHYS_TC_END
value|KMIN_PHYS_TC_3_END
end_define

begin_comment
comment|/* 256 Meg */
end_comment

begin_define
define|#
directive|define
name|KMIN_TC_NSLOTS
value|4
end_define

begin_define
define|#
directive|define
name|KMIN_TC_MIN
value|0
end_define

begin_define
define|#
directive|define
name|KMIN_TC_MAX
value|2
end_define

begin_comment
comment|/* don't look at system slot */
end_comment

begin_comment
comment|/* Pseudo-TCslots */
end_comment

begin_define
define|#
directive|define
name|KMIN_SCSI_SLOT
value|3
end_define

begin_define
define|#
directive|define
name|KMIN_LANCE_SLOT
value|4
end_define

begin_define
define|#
directive|define
name|KMIN_SCC1_SLOT
value|5
end_define

begin_define
define|#
directive|define
name|KMIN_SCC0_SLOT
value|6
end_define

begin_define
define|#
directive|define
name|KMIN_ASIC_SLOT
value|7
end_define

begin_comment
comment|/*  * System module space (IO ASIC)  */
end_comment

begin_define
define|#
directive|define
name|KMIN_SYS_ASIC
value|( KMIN_PHYS_TC_3_START + 0x0000000 )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_ROM_START
value|( KMIN_SYS_ASIC + ASIC_SLOT_0_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_ASIC_REGS
value|( KMIN_SYS_ASIC + ASIC_SLOT_1_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_ETHER_ADDRESS
value|( KMIN_SYS_ASIC + ASIC_SLOT_2_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_LANCE
value|( KMIN_SYS_ASIC + ASIC_SLOT_3_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_SCC_0
value|( KMIN_SYS_ASIC + ASIC_SLOT_4_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_SCC_1
value|( KMIN_SYS_ASIC + ASIC_SLOT_6_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_CLOCK
value|( KMIN_SYS_ASIC + ASIC_SLOT_8_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_SCSI
value|( KMIN_SYS_ASIC + ASIC_SLOT_12_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_SCSI_DMA
value|( KMIN_SYS_ASIC + ASIC_SLOT_14_START )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_BOOT_ROM_START
value|( KMIN_PHYS_TC_3_START + 0x3c00000 )
end_define

begin_define
define|#
directive|define
name|KMIN_SYS_BOOT_ROM_END
value|( KMIN_PHYS_TC_3_START + 0x3c40000 )
end_define

begin_comment
comment|/*  * Interrupts  */
end_comment

begin_define
define|#
directive|define
name|KMIN_INT_FPA
value|IP_LEV7
end_define

begin_comment
comment|/* Floating Point coproc */
end_comment

begin_define
define|#
directive|define
name|KMIN_INT_HALTB
value|IP_LEV6
end_define

begin_comment
comment|/* Halt button */
end_comment

begin_define
define|#
directive|define
name|KMIN_INT_TC3
value|IP_LEV5
end_define

begin_comment
comment|/* TC slot 3, system */
end_comment

begin_define
define|#
directive|define
name|KMIN_INT_TC2
value|IP_LEV4
end_define

begin_comment
comment|/* TC option slot 2 */
end_comment

begin_define
define|#
directive|define
name|KMIN_INT_TC1
value|IP_LEV3
end_define

begin_comment
comment|/* TC option slot 1 */
end_comment

begin_define
define|#
directive|define
name|KMIN_INT_TC0
value|IP_LEV2
end_define

begin_comment
comment|/* TC option slot 0 */
end_comment

begin_comment
comment|/*  *  System registers addresses (MREG and CREG space, and IO Control ASIC)  */
end_comment

begin_define
define|#
directive|define
name|KMIN_REG_MER
value|0x0c400000
end_define

begin_comment
comment|/* Memory error register */
end_comment

begin_define
define|#
directive|define
name|KMIN_REG_MSR
value|0x0c800000
end_define

begin_comment
comment|/* Memory size register */
end_comment

begin_define
define|#
directive|define
name|KMIN_REG_CNFG
value|0x0e000000
end_define

begin_comment
comment|/* Config mem timeouts */
end_comment

begin_define
define|#
directive|define
name|KMIN_REG_AER
value|0x0e000004
end_define

begin_comment
comment|/* Address error register */
end_comment

begin_define
define|#
directive|define
name|KMIN_REG_BOOT
value|0x0e000008
end_define

begin_comment
comment|/* Boot 0 register */
end_comment

begin_define
define|#
directive|define
name|KMIN_REG_TIMEOUT
value|0x0e00000c
end_define

begin_comment
comment|/* Mem access timeout reg */
end_comment

begin_define
define|#
directive|define
name|KMIN_REG_SCSI_DMAPTR
value|( KMIN_SYS_ASIC + ASIC_SCSI_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCSI_DMANPTR
value|( KMIN_SYS_ASIC + ASIC_SCSI_NEXTPTR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_LANCE_DMAPTR
value|( KMIN_SYS_ASIC + ASIC_LANCE_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCC_T1_DMAPTR
value|( KMIN_SYS_ASIC + ASIC_SCC_T1_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCC_R1_DMAPTR
value|( KMIN_SYS_ASIC + ASIC_SCC_R1_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCC_T2_DMAPTR
value|( KMIN_SYS_ASIC + ASIC_SCC_T2_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCC_R2_DMAPTR
value|( KMIN_SYS_ASIC + ASIC_SCC_R2_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_CSR
value|( KMIN_SYS_ASIC + ASIC_CSR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_INTR
value|( KMIN_SYS_ASIC + ASIC_INTR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_IMSK
value|( KMIN_SYS_ASIC + ASIC_IMSK )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_CURADDR
value|( KMIN_SYS_ASIC + ASIC_CURADDR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_LANCE_DECODE
value|( KMIN_SYS_ASIC + ASIC_LANCE_DECODE )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCSI_DECODE
value|( KMIN_SYS_ASIC + ASIC_SCSI_DECODE )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCC0_DECODE
value|( KMIN_SYS_ASIC + ASIC_SCC0_DECODE )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCC1_DECODE
value|( KMIN_SYS_ASIC + ASIC_SCC1_DECODE )
end_define

begin_define
define|#
directive|define
name|KMIN_LANCE_CONFIG
value|3
end_define

begin_define
define|#
directive|define
name|KMIN_SCSI_CONFIG
value|14
end_define

begin_define
define|#
directive|define
name|KMIN_SCC0_CONFIG
value|(0x10|4)
end_define

begin_define
define|#
directive|define
name|KMIN_SCC1_CONFIG
value|(0x10|6)
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCSI_SCR
value|( KMIN_SYS_ASIC + ASIC_SCSI_SCR )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCSI_SDR0
value|( KMIN_SYS_ASIC + ASIC_SCSI_SDR0 )
end_define

begin_define
define|#
directive|define
name|KMIN_REG_SCSI_SDR1
value|( KMIN_SYS_ASIC + ASIC_SCSI_SDR1 )
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
name|KMIN_MER_xxx
value|0xfffe30ff
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|KMIN_MER_PAGE_BRY
value|0x00010000
end_define

begin_comment
comment|/* rw: Page boundary error */
end_comment

begin_define
define|#
directive|define
name|KMIN_MER_TLEN
value|0x00008000
end_define

begin_comment
comment|/* rw: Xfer length error */
end_comment

begin_define
define|#
directive|define
name|KMIN_MER_PARDIS
value|0x00004000
end_define

begin_comment
comment|/* rw: Dis parity err intr */
end_comment

begin_define
define|#
directive|define
name|KMIN_MER_LASTBYTE
value|0x00000f00
end_define

begin_comment
comment|/* rz: Last byte in error: */
end_comment

begin_define
define|#
directive|define
name|KMIN_LASTB31
value|0x00000800
end_define

begin_comment
comment|/* upper byte of word */
end_comment

begin_define
define|#
directive|define
name|KMIN_LASTB23
value|0x00000400
end_define

begin_comment
comment|/* .. through .. */
end_comment

begin_define
define|#
directive|define
name|KMIN_LASTB15
value|0x00000200
end_define

begin_comment
comment|/* .. the .. */
end_comment

begin_define
define|#
directive|define
name|KMIN_LASTB07
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
name|KMIN_MSR_SIZE_16Mb
value|0x00002000
end_define

begin_comment
comment|/* rw: using 16Mb mem banks */
end_comment

begin_define
define|#
directive|define
name|KMIN_MSR_xxx
value|0xffffdfff
end_define

begin_comment
comment|/* undefined */
end_comment

begin_comment
comment|/* NOTES     Memory access priority is, from higher to lower: 	- DRAM refresh 	- IO DMA (IO Control ASIC) 	- Processor 	- Slot 2 DMA 	- Slot 1 DMA 	- Slot 0 DMA     Memory performance is (with 80ns mem cycles) 	- single word read	 5 cyc		10.0 Mb/s 	- word write		 3 cyc		16.7 Mb/s 	- single byte write	 3 cyc		 4.2 Mb/s 	- 64w DMA read		68 cyc		47.1 Mb/s 	- 64w DMA write		66 cyc		48.5 Mb/s 	- Refresh		 5 cyc		N/A  */
end_comment

begin_comment
comment|/* Timeout config register */
end_comment

begin_define
define|#
directive|define
name|KMIN_CNFG_VALUE_12Mhz
value|127
end_define

begin_define
define|#
directive|define
name|KMIN_CNFG_VALUE_25Mhz
value|0
end_define

begin_comment
comment|/* Address error register */
end_comment

begin_define
define|#
directive|define
name|KMIN_AER_ADDR_MASK
value|0x1ffffffc
end_define

begin_comment
comment|/* ro: phys addr in error */
end_comment

begin_comment
comment|/* Boot 0 register */
end_comment

begin_define
define|#
directive|define
name|KMIN_BOOT_FROM_SLOT0
value|0x00000001
end_define

begin_comment
comment|/* rw: diag board boot */
end_comment

begin_comment
comment|/* Memory access timeout interrupt register */
end_comment

begin_define
define|#
directive|define
name|KMIN_TIMEO_INTR
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
name|KMIN_CSR_DMAEN_T1
value|ASIC_CSR_DMAEN_T1
end_define

begin_define
define|#
directive|define
name|KMIN_CSR_DMAEN_R1
value|ASIC_CSR_DMAEN_R1
end_define

begin_define
define|#
directive|define
name|KMIN_CSR_DMAEN_T2
value|ASIC_CSR_DMAEN_T2
end_define

begin_define
define|#
directive|define
name|KMIN_CSR_DMAEN_R2
value|ASIC_CSR_DMAEN_R2
end_define

begin_define
define|#
directive|define
name|KMIN_CSR_SCSI_DIR
value|ASIC_CSR_SCSI_DIR
end_define

begin_define
define|#
directive|define
name|KMIN_CSR_DMAEN_SCSI
value|ASIC_CSR_DMAEN_SCSI
end_define

begin_define
define|#
directive|define
name|KMIN_CSR_DMAEN_LANCE
value|ASIC_CSR_DMAEN_LANCE
end_define

begin_define
define|#
directive|define
name|KMIN_CSR_DIAGDN
value|0x00008000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KMIN_CSR_TXDIS_2
value|0x00004000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KMIN_CSR_TXDIS_1
value|0x00002000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KMIN_CSR_SCC_ENABLE
value|0x00000800
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KMIN_CSR_RTC_ENABLE
value|0x00000400
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KMIN_CSR_SCSI_ENABLE
value|0x00000200
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KMIN_CSR_LANCE_ENABLE
value|0x00000100
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KMIN_CSR_LEDS
value|0x000000ff
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
name|KMIN_INTR_T1_PAGE_END
value|ASIC_INTR_T1_PAGE_END
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_T1_READ_E
value|ASIC_INTR_T1_READ_E
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_R1_HALF_PAGE
value|ASIC_INTR_R1_HALF_PAGE
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_R1_DMA_OVRUN
value|ASIC_INTR_R1_DMA_OVRUN
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_T2_PAGE_END
value|ASIC_INTR_T2_PAGE_END
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_T2_READ_E
value|ASIC_INTR_T2_READ_E
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_R2_HALF_PAGE
value|ASIC_INTR_R2_HALF_PAGE
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_R2_DMA_OVRUN
value|ASIC_INTR_R2_DMA_OVRUN
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_SCSI_PTR_LOAD
value|ASIC_INTR_SCSI_PTR_LOAD
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_SCSI_OVRUN
value|ASIC_INTR_SCSI_OVRUN
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_SCSI_READ_E
value|ASIC_INTR_SCSI_READ_E
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_LANCE_READ_E
value|ASIC_INTR_LANCE_READ_E
end_define

begin_define
define|#
directive|define
name|KMIN_INTR_NVR_JUMPER
value|0x00004000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_TIMEOUT
value|0x00001000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_NRMOD_JUMPER
value|0x00000400
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_SCSI
value|0x00000200
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_LANCE
value|0x00000100
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_SCC_1
value|0x00000080
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_SCC_0
value|0x00000040
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_CLOCK
value|0x00000020
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_PSWARN
value|0x00000010
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_SCSI_FIFO
value|0x00000004
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_PBNC
value|0x00000002
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_PBNO
value|0x00000001
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KMIN_INTR_ASIC
value|0xff0f0004
end_define

begin_define
define|#
directive|define
name|KMIN_IM0
value|0xff0f13f0
end_define

begin_comment
comment|/* all good ones enabled */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS_KMIN_H */
end_comment

end_unit

