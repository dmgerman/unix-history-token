begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: ioasicreg.h,v 1.2 1997/04/06 22:30:28 cgd Exp $ */
end_comment

begin_comment
comment|/*   * Copyright (c) 1991,1990,1989,1994,1995 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University,  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)asic.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Slot definitions  */
end_comment

begin_define
define|#
directive|define
name|IOASIC_SLOT_0_START
value|0x000000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_1_START
value|0x040000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_2_START
value|0x080000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_3_START
value|0x0c0000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_4_START
value|0x100000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_5_START
value|0x140000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_6_START
value|0x180000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_7_START
value|0x1c0000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_8_START
value|0x200000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_9_START
value|0x240000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_10_START
value|0x280000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_11_START
value|0x2c0000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_12_START
value|0x300000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_13_START
value|0x340000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_14_START
value|0x380000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOT_15_START
value|0x3c0000
end_define

begin_define
define|#
directive|define
name|IOASIC_SLOTS_END
value|0x3fffff
end_define

begin_comment
comment|/*  *  Register offsets (slot 1)  */
end_comment

begin_define
define|#
directive|define
name|IOASIC_SCSI_DMAPTR
value|IOASIC_SLOT_1_START+0x000
end_define

begin_define
define|#
directive|define
name|IOASIC_SCSI_NEXTPTR
value|IOASIC_SLOT_1_START+0x010
end_define

begin_define
define|#
directive|define
name|IOASIC_LANCE_DMAPTR
value|IOASIC_SLOT_1_START+0x020
end_define

begin_define
define|#
directive|define
name|IOASIC_SCC_T1_DMAPTR
value|IOASIC_SLOT_1_START+0x030
end_define

begin_define
define|#
directive|define
name|IOASIC_SCC_R1_DMAPTR
value|IOASIC_SLOT_1_START+0x040
end_define

begin_define
define|#
directive|define
name|IOASIC_SCC_T2_DMAPTR
value|IOASIC_SLOT_1_START+0x050
end_define

begin_define
define|#
directive|define
name|IOASIC_SCC_R2_DMAPTR
value|IOASIC_SLOT_1_START+0x060
end_define

begin_define
define|#
directive|define
name|IOASIC_FLOPPY_DMAPTR
value|IOASIC_SLOT_1_START+0x070
end_define

begin_define
define|#
directive|define
name|IOASIC_ISDN_X_DMAPTR
value|IOASIC_SLOT_1_START+0x080
end_define

begin_define
define|#
directive|define
name|IOASIC_ISDN_X_NEXTPTR
value|IOASIC_SLOT_1_START+0x090
end_define

begin_define
define|#
directive|define
name|IOASIC_ISDN_R_DMAPTR
value|IOASIC_SLOT_1_START+0x0a0
end_define

begin_define
define|#
directive|define
name|IOASIC_ISDN_R_NEXTPTR
value|IOASIC_SLOT_1_START+0x0b0
end_define

begin_define
define|#
directive|define
name|IOASIC_BUFF0
value|IOASIC_SLOT_1_START+0x0c0
end_define

begin_define
define|#
directive|define
name|IOASIC_BUFF1
value|IOASIC_SLOT_1_START+0x0d0
end_define

begin_define
define|#
directive|define
name|IOASIC_BUFF2
value|IOASIC_SLOT_1_START+0x0e0
end_define

begin_define
define|#
directive|define
name|IOASIC_BUFF3
value|IOASIC_SLOT_1_START+0x0f0
end_define

begin_define
define|#
directive|define
name|IOASIC_CSR
value|IOASIC_SLOT_1_START+0x100
end_define

begin_define
define|#
directive|define
name|IOASIC_INTR
value|IOASIC_SLOT_1_START+0x110
end_define

begin_define
define|#
directive|define
name|IOASIC_IMSK
value|IOASIC_SLOT_1_START+0x120
end_define

begin_define
define|#
directive|define
name|IOASIC_CURADDR
value|IOASIC_SLOT_1_START+0x130
end_define

begin_define
define|#
directive|define
name|IOASIC_ISDN_X_DATA
value|IOASIC_SLOT_1_START+0x140
end_define

begin_define
define|#
directive|define
name|IOASIC_ISDN_R_DATA
value|IOASIC_SLOT_1_START+0x150
end_define

begin_define
define|#
directive|define
name|IOASIC_LANCE_DECODE
value|IOASIC_SLOT_1_START+0x160
end_define

begin_define
define|#
directive|define
name|IOASIC_SCSI_DECODE
value|IOASIC_SLOT_1_START+0x170
end_define

begin_define
define|#
directive|define
name|IOASIC_SCC0_DECODE
value|IOASIC_SLOT_1_START+0x180
end_define

begin_define
define|#
directive|define
name|IOASIC_SCC1_DECODE
value|IOASIC_SLOT_1_START+0x190
end_define

begin_define
define|#
directive|define
name|IOASIC_FLOPPY_DECODE
value|IOASIC_SLOT_1_START+0x1a0
end_define

begin_define
define|#
directive|define
name|IOASIC_SCSI_SCR
value|IOASIC_SLOT_1_START+0x1b0
end_define

begin_define
define|#
directive|define
name|IOASIC_SCSI_SDR0
value|IOASIC_SLOT_1_START+0x1c0
end_define

begin_define
define|#
directive|define
name|IOASIC_SCSI_SDR1
value|IOASIC_SLOT_1_START+0x1d0
end_define

begin_comment
comment|/* System Status and control Register (SSR). */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_T1
value|0x80000000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_R1
value|0x40000000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_T2
value|0x20000000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_R2
value|0x10000000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_FASTMODE
value|0x08000000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_xxx
value|0x07800000
end_define

begin_comment
comment|/* unused/reserved */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_FLOPPY_DIR
value|0x00400000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_FLOPPY
value|0x00200000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_ISDN_T
value|0x00100000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_ISDN_R
value|0x00080000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_SCSI_DIR
value|0x00040000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_SCSI
value|0x00020000
end_define

begin_comment
comment|/* rw */
end_comment

begin_define
define|#
directive|define
name|IOASIC_CSR_DMAEN_LANCE
value|0x00010000
end_define

begin_comment
comment|/* rw */
end_comment

begin_comment
comment|/* low 16 bits are rw gp outputs */
end_comment

begin_comment
comment|/* System Interrupt Register (and Interrupt Mask Register). */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_T1_PAGE_END
value|0x80000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_T1_READ_E
value|0x40000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_R1_HALF_PAGE
value|0x20000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_R1_DMA_OVRUN
value|0x10000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_T2_PAGE_END
value|0x08000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_T2_READ_E
value|0x04000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_R2_HALF_PAGE
value|0x02000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_R2_DMA_OVRUN
value|0x01000000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_FLOPPY_DMA_E
value|0x00800000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_ISDN_PTR_LOAD
value|0x00400000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_ISDN_OVRUN
value|0x00200000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_ISDN_READ_E
value|0x00100000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_SCSI_PTR_LOAD
value|0x00080000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_SCSI_OVRUN
value|0x00040000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_SCSI_READ_E
value|0x00020000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_LANCE_READ_E
value|0x00010000
end_define

begin_comment
comment|/* rz */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_ISDN
value|0x00002000
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_SEC_CON
value|0x00000200
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_LANCE
value|0x00000100
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_SCC_1
value|0x00000080
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_SCC_0
value|0x00000040
end_define

begin_comment
comment|/* ro */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_ALT_CON
value|0x00000008
end_define

begin_comment
comment|/* ro - 3000/500 */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_300_OPT1
value|IOASIC_INTR_ALT_CON
end_define

begin_comment
comment|/* ro - 3000/300 */
end_comment

begin_define
define|#
directive|define
name|IOASIC_INTR_300_OPT0
value|0x00000004
end_define

begin_comment
comment|/* ro - 3000/300 */
end_comment

begin_comment
comment|/* DMA pointer registers (SCSI, Comm, ...) */
end_comment

begin_define
define|#
directive|define
name|IOASIC_DMAPTR_MASK
value|0xffffffe0
end_define

begin_define
define|#
directive|define
name|IOASIC_DMAPTR_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|IOASIC_DMAPTR_SET
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(reg) = (((val)<<IOASIC_DMAPTR_SHIFT)&IOASIC_DMAPTR_MASK)
end_define

begin_define
define|#
directive|define
name|IOASIC_DMAPTR_GET
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|(val) = (((reg)&IOASIC_DMAPTR_MASK)>>IOASIC_DMAPTR_SHIFT)
end_define

begin_define
define|#
directive|define
name|IOASIC_DMA_ADDR
parameter_list|(
name|p
parameter_list|)
value|(((unsigned)p)<< (5-2))
end_define

begin_comment
comment|/* For the LANCE DMA pointer register initialization the above suffices */
end_comment

begin_comment
comment|/* More SCSI DMA registers */
end_comment

begin_define
define|#
directive|define
name|IOASIC_SCR_STATUS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IOASIC_SCR_WORD
value|0x00000003
end_define

begin_comment
comment|/* Various Decode registers */
end_comment

begin_define
define|#
directive|define
name|IOASIC_DECODE_HW_ADDRESS
value|0x000003f0
end_define

begin_define
define|#
directive|define
name|IOASIC_DECODE_CHIP_SELECT
value|0x0000000f
end_define

begin_comment
comment|/*  * Asic register addresses at offset from base.  */
end_comment

begin_define
define|#
directive|define
name|IOASIC_REG_SCSI_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCSI_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCSI_DMANPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCSI_NEXTPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_LANCE_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_LANCE_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCC_T1_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCC_T1_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCC_R1_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCC_R1_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCC_T2_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCC_T2_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCC_R2_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCC_R2_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_FLOPPY_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_FLOPPY_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_ISDN_X_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_ISDN_X_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_ISDN_X_NEXTPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_ISDN_X_NEXTPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_ISDN_R_DMAPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_ISDN_R_DMAPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_ISDN_R_NEXTPTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_ISDN_R_NEXTPTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_BUFF0
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_BUFF0)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_BUFF1
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_BUFF1)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_BUFF2
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_BUFF2)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_BUFF3
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_BUFF3)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_CSR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_CSR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_INTR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_INTR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_IMSK
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_IMSK)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_CURADDR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_CURADDR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_ISDN_X_DATA
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_ISDN_X_DATA)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_ISDN_R_DATA
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_ISDN_R_DATA)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_LANCE_DECODE
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_LANCE_DECODE)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCSI_DECODE
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCSI_DECODE)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCC0_DECODE
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCC0_DECODE)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCC1_DECODE
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCC1_DECODE)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_FLOPPY_DECODE
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_FLOPPY_DECODE)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCSI_SCR
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCSI_SCR)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCSI_SDR0
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCSI_SDR0)
end_define

begin_define
define|#
directive|define
name|IOASIC_REG_SCSI_SDR1
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SCSI_SDR1)
end_define

begin_comment
comment|/*  * And slot assignments.  */
end_comment

begin_define
define|#
directive|define
name|IOASIC_SYS_ETHER_ADDRESS
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SLOT_2_START)
end_define

begin_define
define|#
directive|define
name|IOASIC_SYS_LANCE
parameter_list|(
name|base
parameter_list|)
value|((base) + IOASIC_SLOT_3_START)
end_define

end_unit

