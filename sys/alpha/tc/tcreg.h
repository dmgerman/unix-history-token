begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: tcreg.h,v 1.1 1995/12/20 00:48:36 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Author: Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEV_TC_TCREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEV_TC_TCREG_H__
end_define

begin_comment
comment|/*  * TurboChannel bus and register definitions.  */
end_comment

begin_define
define|#
directive|define
name|TC_ROM_LLEN
value|8
end_define

begin_define
define|#
directive|define
name|TC_ROM_SLEN
value|4
end_define

begin_define
define|#
directive|define
name|TC_ROM_TEST_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|TC_SLOT_ROM
value|0x000003e0
end_define

begin_define
define|#
directive|define
name|TC_SLOT_PROTOROM
value|0x003c03e0
end_define

begin_typedef
typedef|typedef
struct|struct
name|tc_padchar
block|{
name|u_int8_t
name|v
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|tc_padchar_t
typedef|;
end_typedef

begin_struct
struct|struct
name|tc_rommap
block|{
name|tc_padchar_t
name|tcr_width
decl_stmt|;
name|tc_padchar_t
name|tcr_stride
decl_stmt|;
name|tc_padchar_t
name|tcr_rsize
decl_stmt|;
name|tc_padchar_t
name|tcr_ssize
decl_stmt|;
name|u_int8_t
name|tcr_test
index|[
name|TC_ROM_TEST_SIZE
index|]
decl_stmt|;
name|tc_padchar_t
name|tcr_rev
index|[
name|TC_ROM_LLEN
index|]
decl_stmt|;
name|tc_padchar_t
name|tcr_vendname
index|[
name|TC_ROM_LLEN
index|]
decl_stmt|;
name|tc_padchar_t
name|tcr_modname
index|[
name|TC_ROM_LLEN
index|]
decl_stmt|;
name|tc_padchar_t
name|tcr_firmtype
index|[
name|TC_ROM_SLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TurboChannel-specific functions and structures for 3000_300.  */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR
value|KV(0x00000001e0000000)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_CSR
value|KV(0x00000001e0000008)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_MCR
value|KV(0x00000001e0000010)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_LED
value|KV(0x00000001e0000018)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_comment
comment|/* Interrupt bits. */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR_CXTURBO
value|0x00000004
end_define

begin_comment
comment|/* TC CXTURBO */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR_TCDS
value|0x00000008
end_define

begin_comment
comment|/* TC Dual SCSI */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR_IOASIC
value|0x00000010
end_define

begin_comment
comment|/* TC IOASIC */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR_BCTAGPARITY
value|0x08000000
end_define

begin_comment
comment|/* BC tag par. err. */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR_TCOVERRUN
value|0x10000000
end_define

begin_comment
comment|/* TC overrun */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR_TCTIMEOUT
value|0x20000000
end_define

begin_comment
comment|/* TC timeout on I/O */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR_BCACHEPARITY
value|0x40000000
end_define

begin_comment
comment|/* Bcache par. err. */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_IR_MEMPARITY
value|0x80000000
end_define

begin_comment
comment|/* Memory par. err. */
end_comment

begin_comment
comment|/* Device number "cookies." */
end_comment

begin_define
define|#
directive|define
name|TC_3000_300_DEV_OPT0
value|0
end_define

begin_define
define|#
directive|define
name|TC_3000_300_DEV_OPT1
value|1
end_define

begin_define
define|#
directive|define
name|TC_3000_300_DEV_TCDS
value|2
end_define

begin_define
define|#
directive|define
name|TC_3000_300_DEV_IOASIC
value|3
end_define

begin_define
define|#
directive|define
name|TC_3000_300_DEV_CXTURBO
value|4
end_define

begin_define
define|#
directive|define
name|TC_3000_300_DEV_BOGUS
value|-1
end_define

begin_define
define|#
directive|define
name|TC_3000_300_NCOOKIES
value|5
end_define

begin_define
define|#
directive|define
name|TC_3000_500_IOSLOT
value|KV(0x00000001c2000000)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_TCCONFIG
value|KV(0x00000001c2000008)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_FADR
value|KV(0x00000001c2000010)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_TCEREG
value|KV(0x00000001c2000018)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_MEMCONF
value|KV(0x00000001c2200000)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IMR_READ
value|KV(0x00000001c2400000)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IMR_WRITE
value|KV(0x00000001c281fffc)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_TCRESET
value|KV(0x00000001c2a00000)
end_define

begin_comment
comment|/* Dense */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR
value|KV(0x00000001d4800000)
end_define

begin_comment
comment|/* Sparse */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_CLEAR
value|KV(0x00000001d4c00000)
end_define

begin_comment
comment|/* Sparse */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_SCMAP
value|KV(0x00000001d5000000)
end_define

begin_comment
comment|/* Sparse */
end_comment

begin_comment
comment|/* Interrupt bits. */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_OPT0
value|0x00000001
end_define

begin_comment
comment|/* TC Option 0 */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_OPT1
value|0x00000002
end_define

begin_comment
comment|/* TC Option 1 */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_OPT2
value|0x00000004
end_define

begin_comment
comment|/* TC Option 2 */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_OPT3
value|0x00000008
end_define

begin_comment
comment|/* TC Option 3 */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_OPT4
value|0x00000010
end_define

begin_comment
comment|/* TC Option 4 */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_OPT5
value|0x00000020
end_define

begin_comment
comment|/* TC Option 5 */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_TCDS
value|0x00000040
end_define

begin_comment
comment|/* TC Dual SCSI */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_IOASIC
value|0x00000080
end_define

begin_comment
comment|/* TC IOASIC */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_CXTURBO
value|0x00000100
end_define

begin_comment
comment|/* TC CXTURBO */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_ERR2
value|0x00080000
end_define

begin_comment
comment|/* Second error */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_DMABE
value|0x00100000
end_define

begin_comment
comment|/* DMA buffer error */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_DMA2K
value|0x00200000
end_define

begin_comment
comment|/* DMA 2K boundary */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_TCRESET
value|0x00400000
end_define

begin_comment
comment|/* TC reset in prog. */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_TCPAR
value|0x00800000
end_define

begin_comment
comment|/* TC parity error */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_DMATAG
value|0x01000000
end_define

begin_comment
comment|/* DMA tag error */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_DMASBE
value|0x02000000
end_define

begin_comment
comment|/* Single-bit error */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_DMADBE
value|0x04000000
end_define

begin_comment
comment|/* Double-bit error */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_TCTIMEOUT
value|0x08000000
end_define

begin_comment
comment|/* TC timeout on I/O */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_DMABLOCK
value|0x10000000
end_define

begin_comment
comment|/* DMA block too long */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_IOADDR
value|0x20000000
end_define

begin_comment
comment|/* Invalid I/O addr */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_DMASG
value|0x40000000
end_define

begin_comment
comment|/* SG invalid */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_IR_SGPAR
value|0x80000000
end_define

begin_comment
comment|/* SG parity error */
end_comment

begin_comment
comment|/* I/O Slot Configuration (IOSLOT) bits. */
end_comment

begin_define
define|#
directive|define
name|IOSLOT_P
value|0x04
end_define

begin_comment
comment|/* Parity enable. */
end_comment

begin_define
define|#
directive|define
name|IOSLOT_B
value|0x02
end_define

begin_comment
comment|/* Block-mode write. */
end_comment

begin_define
define|#
directive|define
name|IOSLOT_S
value|0x01
end_define

begin_comment
comment|/* DMA scatter/gather mode. */
end_comment

begin_comment
comment|/* I/O Slot Configuration (IOSLOT) offsets. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_OPT0
value|0
end_define

begin_comment
comment|/* Option 0 PBS offset. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_OPT1
value|1
end_define

begin_comment
comment|/* Option 1 PBS offset. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_OPT2
value|2
end_define

begin_comment
comment|/* Option 2 PBS offset. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_OPT3
value|3
end_define

begin_comment
comment|/* Option 3 PBS offset. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_OPT4
value|4
end_define

begin_comment
comment|/* Option 4 PBS offset. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_OPT5
value|5
end_define

begin_comment
comment|/* Option 5 PBS offset. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_SCSI
value|6
end_define

begin_comment
comment|/* Option SCSI PBS offset. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_IOASIC
value|7
end_define

begin_comment
comment|/* Option IOASIC PBS offset. */
end_comment

begin_define
define|#
directive|define
name|TC_IOSLOT_CXTURBO
value|8
end_define

begin_comment
comment|/* Option CXTURBO PBS offset. */
end_comment

begin_comment
comment|/* Device number "cookies." */
end_comment

begin_define
define|#
directive|define
name|TC_3000_500_DEV_OPT0
value|0
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_OPT1
value|1
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_OPT2
value|2
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_OPT3
value|3
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_OPT4
value|4
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_OPT5
value|5
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_TCDS
value|6
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_IOASIC
value|7
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_CXTURBO
value|8
end_define

begin_define
define|#
directive|define
name|TC_3000_500_DEV_BOGUS
value|-1
end_define

begin_define
define|#
directive|define
name|TC_3000_500_NCOOKIES
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DEV_TC_TCREG_H__ */
end_comment

end_unit

