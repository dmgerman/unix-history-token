begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University,  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)kn03.h	1.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	Definitions specific to the KN03GA processors and 3MAX+  *	DECstation 5000/240 mother board.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MIPS_KN03_H
end_ifndef

begin_define
define|#
directive|define
name|MIPS_KN03_H
value|1
end_define

begin_comment
comment|/*  * 3MAX+'s Physical address space  */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_MIN
value|0x00000000
end_define

begin_comment
comment|/* 512 Meg */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_MAX
value|0x1fffffff
end_define

begin_comment
comment|/*  * Memory map  */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_MEMORY_START
value|0x00000000
end_define

begin_define
define|#
directive|define
name|KN03_PHYS_MEMORY_END
value|0x1dffffff
end_define

begin_comment
comment|/* 480 Meg */
end_comment

begin_comment
comment|/*  * I/O map  */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_0_START
value|0x1e000000
end_define

begin_comment
comment|/* TURBOchannel, slot 0 */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_0_END
value|0x1e7fffff
end_define

begin_comment
comment|/*  8 Meg, option0 */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_1_START
value|0x1e800000
end_define

begin_comment
comment|/* TURBOchannel, slot 1 */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_1_END
value|0x1effffff
end_define

begin_comment
comment|/*  8 Meg, option1 */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_2_START
value|0x1f000000
end_define

begin_comment
comment|/* TURBOchannel, slot 2 */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_2_END
value|0x1f7fffff
end_define

begin_comment
comment|/*  8 Meg, option2 */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_3_START
value|0x1f800000
end_define

begin_comment
comment|/* TURBOchannel, slot 3 */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_3_END
value|0x1fffffff
end_define

begin_comment
comment|/*  8 Meg, system devices */
end_comment

begin_define
define|#
directive|define
name|KN03_PHYS_TC_START
value|KN03_PHYS_TC_0_START
end_define

begin_define
define|#
directive|define
name|KN03_PHYS_TC_END
value|KN03_PHYS_TC_3_END
end_define

begin_define
define|#
directive|define
name|KN03_TC_NSLOTS
value|4
end_define

begin_define
define|#
directive|define
name|KN03_TC_MIN
value|0
end_define

begin_define
define|#
directive|define
name|KN03_TC_MAX
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
name|KN03_SCSI_SLOT
value|3
end_define

begin_define
define|#
directive|define
name|KN03_LANCE_SLOT
value|4
end_define

begin_define
define|#
directive|define
name|KN03_SCC1_SLOT
value|5
end_define

begin_define
define|#
directive|define
name|KN03_SCC0_SLOT
value|6
end_define

begin_define
define|#
directive|define
name|KN03_ASIC_SLOT
value|7
end_define

begin_comment
comment|/*  * System module space (IO ASIC)  */
end_comment

begin_define
define|#
directive|define
name|KN03_SYS_ASIC
value|( KN03_PHYS_TC_3_START + 0x0000000 )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_ROM_START
value|( KN03_SYS_ASIC + ASIC_SLOT_0_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_ASIC_REGS
value|( KN03_SYS_ASIC + ASIC_SLOT_1_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_ETHER_ADDRESS
value|( KN03_SYS_ASIC + ASIC_SLOT_2_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_LANCE
value|( KN03_SYS_ASIC + ASIC_SLOT_3_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_SCC_0
value|( KN03_SYS_ASIC + ASIC_SLOT_4_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_SCC_1
value|( KN03_SYS_ASIC + ASIC_SLOT_6_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_CLOCK
value|( KN03_SYS_ASIC + ASIC_SLOT_8_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_ERRADR
value|( KN03_SYS_ASIC + ASIC_SLOT_9_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_ERRSYN
value|( KN03_SYS_ASIC + ASIC_SLOT_10_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_CSR
value|( KN03_SYS_ASIC + ASIC_SLOT_11_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_SCSI
value|( KN03_SYS_ASIC + ASIC_SLOT_12_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_SCSI_DMA
value|( KN03_SYS_ASIC + ASIC_SLOT_14_START )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_BOOT_ROM_START
value|( KN03_PHYS_TC_3_START + 0x400000 )
end_define

begin_define
define|#
directive|define
name|KN03_SYS_BOOT_ROM_END
value|( KN03_PHYS_TC_3_START + 0x43ffff )
end_define

begin_comment
comment|/*  * Interrupts  */
end_comment

begin_define
define|#
directive|define
name|KN03_INT_FPA
value|IP_LEV7
end_define

begin_comment
comment|/* Floating Point coproc */
end_comment

begin_define
define|#
directive|define
name|KN03_INT_HALTB
value|IP_LEV6
end_define

begin_comment
comment|/* Halt button */
end_comment

begin_define
define|#
directive|define
name|KN03_INT_MEM
value|IP_LEV5
end_define

begin_comment
comment|/* Memory Errors */
end_comment

begin_define
define|#
directive|define
name|KN03_INT_RTC
value|IP_LEV3
end_define

begin_comment
comment|/* RTC clock */
end_comment

begin_define
define|#
directive|define
name|KN03_INT_ASIC
value|IP_LEV2
end_define

begin_comment
comment|/* All turbochannel */
end_comment

begin_define
define|#
directive|define
name|KN03_REG_SCSI_DMAPTR
value|( KN03_SYS_ASIC + ASIC_SCSI_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCSI_DMANPTR
value|( KN03_SYS_ASIC + ASIC_SCSI_NEXTPTR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_LANCE_DMAPTR
value|( KN03_SYS_ASIC + ASIC_LANCE_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCC_T1_DMAPTR
value|( KN03_SYS_ASIC + ASIC_SCC_T1_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCC_R1_DMAPTR
value|( KN03_SYS_ASIC + ASIC_SCC_R1_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCC_T2_DMAPTR
value|( KN03_SYS_ASIC + ASIC_SCC_T2_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCC_R2_DMAPTR
value|( KN03_SYS_ASIC + ASIC_SCC_R2_DMAPTR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_CSR
value|( KN03_SYS_ASIC + ASIC_CSR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_INTR
value|( KN03_SYS_ASIC + ASIC_INTR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_IMSK
value|( KN03_SYS_ASIC + ASIC_IMSK )
end_define

begin_define
define|#
directive|define
name|KN03_REG_CURADDR
value|( KN03_SYS_ASIC + ASIC_CURADDR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_LANCE_DECODE
value|( KN03_SYS_ASIC + ASIC_LANCE_DECODE )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCSI_DECODE
value|( KN03_SYS_ASIC + ASIC_SCSI_DECODE )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCC0_DECODE
value|( KN03_SYS_ASIC + ASIC_SCC0_DECODE )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCC1_DECODE
value|( KN03_SYS_ASIC + ASIC_SCC1_DECODE )
end_define

begin_define
define|#
directive|define
name|KN03_LANCE_CONFIG
value|3
end_define

begin_define
define|#
directive|define
name|KN03_SCSI_CONFIG
value|14
end_define

begin_define
define|#
directive|define
name|KN03_SCC0_CONFIG
value|(0x10|4)
end_define

begin_define
define|#
directive|define
name|KN03_SCC1_CONFIG
value|(0x10|6)
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCSI_SCR
value|( KN03_SYS_ASIC + ASIC_SCSI_SCR )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCSI_SDR0
value|( KN03_SYS_ASIC + ASIC_SCSI_SDR0 )
end_define

begin_define
define|#
directive|define
name|KN03_REG_SCSI_SDR1
value|( KN03_SYS_ASIC + ASIC_SCSI_SDR1 )
end_define

begin_comment
comment|/* NOTES     Memory access priority is, from higher to lower: 	- DRAM refresh 	- IO DMA (IO Control ASIC) 	- Slot 2 DMA 	- Slot 1 DMA 	- Slot 0 DMA 	- Processor   */
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
name|KN03_CSR_DMAEN_T1
value|ASIC_CSR_DMAEN_T1
end_define

begin_define
define|#
directive|define
name|KN03_CSR_DMAEN_R1
value|ASIC_CSR_DMAEN_R1
end_define

begin_define
define|#
directive|define
name|KN03_CSR_DMAEN_T2
value|ASIC_CSR_DMAEN_T2
end_define

begin_define
define|#
directive|define
name|KN03_CSR_DMAEN_R2
value|ASIC_CSR_DMAEN_R2
end_define

begin_define
define|#
directive|define
name|KN03_CSR_SCSI_DIR
value|ASIC_CSR_SCSI_DIR
end_define

begin_define
define|#
directive|define
name|KN03_CSR_DMAEN_SCSI
value|ASIC_CSR_DMAEN_SCSI
end_define

begin_define
define|#
directive|define
name|KN03_CSR_DMAEN_LANCE
value|ASIC_CSR_DMAEN_LANCE
end_define

begin_define
define|#
directive|define
name|KN03_CSR_DIAGDN
value|0x00008000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KN03_CSR_TXDIS_2
value|0x00004000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KN03_CSR_TXDIS_1
value|0x00002000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KN03_CSR_SCC_ENABLE
value|0x00000800
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KN03_CSR_RTC_ENABLE
value|0x00000400
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KN03_CSR_SCSI_ENABLE
value|0x00000200
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KN03_CSR_LANCE_ENABLE
value|0x00000100
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|KN03_CSR_LEDS
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
name|KN03_INTR_T1_PAGE_END
value|ASIC_INTR_T1_PAGE_END
end_define

begin_define
define|#
directive|define
name|KN03_INTR_T1_READ_E
value|ASIC_INTR_T1_READ_E
end_define

begin_define
define|#
directive|define
name|KN03_INTR_R1_HALF_PAGE
value|ASIC_INTR_R1_HALF_PAGE
end_define

begin_define
define|#
directive|define
name|KN03_INTR_R1_DMA_OVRUN
value|ASIC_INTR_R1_DMA_OVRUN
end_define

begin_define
define|#
directive|define
name|KN03_INTR_T2_PAGE_END
value|ASIC_INTR_T2_PAGE_END
end_define

begin_define
define|#
directive|define
name|KN03_INTR_T2_READ_E
value|ASIC_INTR_T2_READ_E
end_define

begin_define
define|#
directive|define
name|KN03_INTR_R2_HALF_PAGE
value|ASIC_INTR_R2_HALF_PAGE
end_define

begin_define
define|#
directive|define
name|KN03_INTR_R2_DMA_OVRUN
value|ASIC_INTR_R2_DMA_OVRUN
end_define

begin_define
define|#
directive|define
name|KN03_INTR_SCSI_PTR_LOAD
value|ASIC_INTR_SCSI_PTR_LOAD
end_define

begin_define
define|#
directive|define
name|KN03_INTR_SCSI_OVRUN
value|ASIC_INTR_SCSI_OVRUN
end_define

begin_define
define|#
directive|define
name|KN03_INTR_SCSI_READ_E
value|ASIC_INTR_SCSI_READ_E
end_define

begin_define
define|#
directive|define
name|KN03_INTR_LANCE_READ_E
value|ASIC_INTR_LANCE_READ_E
end_define

begin_define
define|#
directive|define
name|KN03_INTR_NVR_JUMPER
value|0x00004000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_TC_2
value|0x00002000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_TC_1
value|0x00001000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_TC_0
value|0x00000800
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_NRMOD_JUMPER
value|0x00000400
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_SCSI
value|0x00000200
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_LANCE
value|0x00000100
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_SCC_1
value|0x00000080
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_SCC_0
value|0x00000040
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_CLOCK
value|0x00000020
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_PSWARN
value|0x00000010
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_SCSI_FIFO
value|0x00000004
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_PBNC
value|0x00000002
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_PBNO
value|0x00000001
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|KN03_INTR_ASIC
value|0xff0f0004
end_define

begin_define
define|#
directive|define
name|KN03_IM0
value|0xff0f3bf0
end_define

begin_comment
comment|/* all good ones enabled */
end_comment

begin_comment
comment|/*  * XXX I made a wild guess this register looks the same as for the KN02.  */
end_comment

begin_define
define|#
directive|define
name|KN03_ERR_ADDRESS
value|0x07ffffff
end_define

begin_comment
comment|/* phys address */
end_comment

begin_define
define|#
directive|define
name|KN03_ERR_RESERVED
value|0x08000000
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|KN03_ERR_ECCERR
value|0x10000000
end_define

begin_comment
comment|/* ECC error */
end_comment

begin_define
define|#
directive|define
name|KN03_ERR_WRITE
value|0x20000000
end_define

begin_comment
comment|/* read/write transaction */
end_comment

begin_define
define|#
directive|define
name|KN03_ERR_CPU
value|0x40000000
end_define

begin_comment
comment|/* CPU or device initiator */
end_comment

begin_define
define|#
directive|define
name|KN03_ERR_VALID
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
name|KN03_ECC_SYNLO
value|0x0000007f
end_define

begin_comment
comment|/* syndrome, even bank	*/
end_comment

begin_define
define|#
directive|define
name|KN03_ECC_SNGLO
value|0x00000080
end_define

begin_comment
comment|/* single bit err, " 	*/
end_comment

begin_define
define|#
directive|define
name|KN03_ECC_CHKLO
value|0x00007f00
end_define

begin_comment
comment|/* check bits,	"  "	*/
end_comment

begin_define
define|#
directive|define
name|KN03_ECC_VLDLO
value|0x00008000
end_define

begin_comment
comment|/* info valid for  "	*/
end_comment

begin_define
define|#
directive|define
name|KN03_ECC_SYNHI
value|0x007f0000
end_define

begin_comment
comment|/* syndrome, odd bank	*/
end_comment

begin_define
define|#
directive|define
name|KN03_ECC_SNGHI
value|0x00800000
end_define

begin_comment
comment|/* single bit err, "	*/
end_comment

begin_define
define|#
directive|define
name|KN03_ECC_CHKHI
value|0x7f000000
end_define

begin_comment
comment|/* check bits,  "  "	*/
end_comment

begin_define
define|#
directive|define
name|KN03_ECC_VLDHI
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
comment|/* MIPS_KN03_H */
end_comment

end_unit

