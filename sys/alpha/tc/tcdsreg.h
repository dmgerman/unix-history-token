begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: tcdsreg.h,v 1.1 1995/12/20 00:40:36 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Carnegie-Mellon University.  * All rights reserved.  *  * Authors: Keith Bostic, Chris G. Demetriou  *   * Permission to use, copy, modify and distribute this software and  * its documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"   * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND   * FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Offsets to the SCSI chips  */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI0_OFFSET
value|0x080000
end_define

begin_define
define|#
directive|define
name|TCDS_SCSI1_OFFSET
value|0x080100
end_define

begin_comment
comment|/*  * TCDS register offsets, bit masks.  */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR
value|0x040000
end_define

begin_comment
comment|/* CIR offset */
end_comment

begin_comment
comment|/*  * TCDS CIR control bits.  */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_GPO_0
value|0x00000001
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_GPO_1
value|0x00000002
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_GPO_2
value|0x00000004
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_STD
value|0x00000008
end_define

begin_comment
comment|/* Serial transmit disable */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_GPI_0
value|0x00000010
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_GPI_1
value|0x00000020
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_GPI_2
value|0x00000040
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_GPI_3
value|0x00000080
end_define

begin_comment
comment|/* Not used */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_DMAENA
value|0x00000100
end_define

begin_comment
comment|/* SCSI 0 DMA enable */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_DMAENA
value|0x00000200
end_define

begin_comment
comment|/* SCSI 1 DMA enable */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_RESET
value|0x00000400
end_define

begin_comment
comment|/* SCSI 0 reset */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_RESET
value|0x00000800
end_define

begin_comment
comment|/* SCSI 1 reset */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_DMA_TEST
value|0x00001000
end_define

begin_comment
comment|/* SCSI 0 DMA buf parity test */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_DMA_TEST
value|0x00002000
end_define

begin_comment
comment|/* SCSI 1 DMA buf parity test */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_DB_PAR
value|0x00004000
end_define

begin_comment
comment|/* DB parity test mode */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_TC_PAR
value|0x00008000
end_define

begin_comment
comment|/* TC parity test mode */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_ALLCONTROL
value|0x0000ffff
end_define

begin_comment
comment|/* all control bits */
end_comment

begin_comment
comment|/* TCDS CIR interrupt bits. */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_DREQ
value|0x00010000
end_define

begin_comment
comment|/* SCSI 0 DREQ */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_DREQ
value|0x00020000
end_define

begin_comment
comment|/* SCSI 1 DREQ */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_INT
value|0x00040000
end_define

begin_comment
comment|/* SCSI 0 interrupt */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_INT
value|0x00080000
end_define

begin_comment
comment|/* SCSI 1 interrupt */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_PREFETCH
value|0x00100000
end_define

begin_comment
comment|/* SCSI 0 prefetch */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_PREFETCH
value|0x00200000
end_define

begin_comment
comment|/* SCSI 1 prefetch */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_DMA
value|0x00400000
end_define

begin_comment
comment|/* SCSI 0 DMA error */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_DMA
value|0x00800000
end_define

begin_comment
comment|/* SCSI 1 DMA error */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_DB
value|0x01000000
end_define

begin_comment
comment|/* SCSI 0 DB parity */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_DB
value|0x02000000
end_define

begin_comment
comment|/* SCSI 1 DB parity */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_DMAB_PAR
value|0x04000000
end_define

begin_comment
comment|/* SCSI 0 DMA buffer parity */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_DMAB_PAR
value|0x08000000
end_define

begin_comment
comment|/* SCSI 1 DMA buffer parity */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI0_DMAR_PAR
value|0x10000000
end_define

begin_comment
comment|/* SCSI 0 DMA read parity */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_SCSI1_DMAR_PAR
value|0x20000000
end_define

begin_comment
comment|/* SCSI 1 DMA read parity */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_TCIOW_PAR
value|0x40000000
end_define

begin_comment
comment|/* TC I/O write parity */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_TCIOA_PAR
value|0x80000000
end_define

begin_comment
comment|/* TC I/O address parity */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_ALLINTR
value|0xffff0000
end_define

begin_comment
comment|/* all interrupt bits */
end_comment

begin_define
define|#
directive|define
name|TCDS_CIR_CLR
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
value|c = ((c | TCDS_CIR_ALLINTR)& ~b)
end_define

begin_define
define|#
directive|define
name|TCDS_CIR_SET
parameter_list|(
name|c
parameter_list|,
name|b
parameter_list|)
value|c = ((c | TCDS_CIR_ALLINTR) | b)
end_define

begin_comment
comment|/* TCDS IMER masks and enables, for interrupts in the CIR. */
end_comment

begin_define
define|#
directive|define
name|TCDS_IMER_SCSI0_MASK
value|0x04
end_define

begin_comment
comment|/* SCSI 0 intr/enable mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_IMER_SCSI1_MASK
value|0x08
end_define

begin_comment
comment|/* SCSI 1 intr/enable mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_IMER_SCSI0_ENB
value|(TCDS_IMER_SCSI0_MASK<< 16)
end_define

begin_define
define|#
directive|define
name|TCDS_IMER_SCSI1_ENB
value|(TCDS_IMER_SCSI1_MASK<< 16)
end_define

begin_define
define|#
directive|define
name|TCDS_IMER
value|0x040004
end_define

begin_comment
comment|/* IMER offset */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI0_DMA_ADDR
value|0x041000
end_define

begin_comment
comment|/* DMA address */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI0_DMA_INTR
value|0x041004
end_define

begin_comment
comment|/* DMA interrupt control */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI0_DMA_DUD0
value|0x041008
end_define

begin_comment
comment|/* DMA unaligned data[0] */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI0_DMA_DUD1
value|0x04100c
end_define

begin_comment
comment|/* DMA unaligned data[1] */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI1_DMA_ADDR
value|0x041100
end_define

begin_comment
comment|/* DMA address */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI1_DMA_INTR
value|0x041104
end_define

begin_comment
comment|/* DMA interrupt control */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI1_DMA_DUD0
value|0x041108
end_define

begin_comment
comment|/* DMA unaligned data[0] */
end_comment

begin_define
define|#
directive|define
name|TCDS_SCSI1_DMA_DUD1
value|0x04110c
end_define

begin_comment
comment|/* DMA unaligned data[1] */
end_comment

begin_define
define|#
directive|define
name|TCDS_DIC_ADDRMASK
value|0x03
end_define

begin_comment
comment|/* DMA address bits<1:0> */
end_comment

begin_define
define|#
directive|define
name|TCDS_DIC_READ_PREFETCH
value|0x40
end_define

begin_comment
comment|/* DMA read prefetch enable */
end_comment

begin_define
define|#
directive|define
name|TCDS_DIC_WRITE
value|0x80
end_define

begin_comment
comment|/* DMA write */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD0_VALID00
value|0x00000001
end_define

begin_comment
comment|/* byte 00 valid mask (zero) */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD0_VALID01
value|0x00000002
end_define

begin_comment
comment|/* byte 01 valid mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD0_VALID10
value|0x00000004
end_define

begin_comment
comment|/* byte 10 valid mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD0_VALID11
value|0x00000008
end_define

begin_comment
comment|/* byte 11 valid mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD0_VALIDBITS
value|0x0000000f
end_define

begin_comment
comment|/* bits that show valid bytes */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD1_VALID00
value|0x01000000
end_define

begin_comment
comment|/* byte 00 valid mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD1_VALID01
value|0x02000000
end_define

begin_comment
comment|/* byte 01 valid mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD1_VALID10
value|0x04000000
end_define

begin_comment
comment|/* byte 10 valid mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD1_VALID11
value|0x08000000
end_define

begin_comment
comment|/* byte 11 valid mask (zero) */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD1_VALIDBITS
value|0x0f000000
end_define

begin_comment
comment|/* bits that show valid bytes */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD_BYTE00
value|0x000000ff
end_define

begin_comment
comment|/* byte 00 mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD_BYTE01
value|0x0000ff00
end_define

begin_comment
comment|/* byte 01 mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD_BYTE10
value|0x00ff0000
end_define

begin_comment
comment|/* byte 10 mask */
end_comment

begin_define
define|#
directive|define
name|TCDS_DUD_BYTE11
value|0xff000000
end_define

begin_comment
comment|/* byte 11 mask */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|int  tcds_scsi_iserr(struct dma_softc *); int  tcds_scsi_isintr(int, int); void tcds_dma_disable(int); void tcds_dma_enable(int); void tcds_dma_init(struct dma_softc *, int); void tcds_scsi_disable(int); void tcds_scsi_enable(int); void tcds_scsi_reset(int);
comment|/*  * XXX  * Start of MACH #defines, minimal changes to port to NetBSD.  *   * The following register is the SCSI control interrupt register.  It  * starts, stops and resets scsi DMA.  It takes over the SCSI funtions  * that were handled by the ASIC on the 3min.  */
end_comment

begin_define
define|#
directive|define
name|KN15AA_SYS_SCSI
value|0x1d0000000
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_CIR
value|(KN15AA_SYS_SCSI + 0x80000)
end_define

begin_define
define|#
directive|define
name|SCSI_CIR_AIOPAR
value|0x80000000
end_define

begin_comment
comment|/* TC IO Address parity error */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_WDIOPAR
value|0x40000000
end_define

begin_comment
comment|/* TC IO  write data parity error */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DMARPAR1
value|0x20000000
end_define

begin_comment
comment|/* SCSI[1] TC DMA read data parity */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DMARPAR0
value|0x10000000
end_define

begin_comment
comment|/* SCSI[0] TC DMA read data parity */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DMABUFPAR1
value|0x08000000
end_define

begin_comment
comment|/* SCSI[1] DMA buffer parity error */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DMABUFPAR0
value|0x04000000
end_define

begin_comment
comment|/* SCSI[0] DMA buffer parity error */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DBPAR1
value|0x02000000
end_define

begin_comment
comment|/* SCSI[1] DB parity error */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DBPAR0
value|0x01000000
end_define

begin_comment
comment|/* SCSI[0] DB parity error */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DMAERR1
value|0x00800000
end_define

begin_comment
comment|/* SCSI[1] DMA error */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DMAERR0
value|0x00400000
end_define

begin_comment
comment|/* SCSI[0] DMA error */
end_comment

begin_if
if|#
directive|if
name|fmm50
end_if

begin_define
define|#
directive|define
name|SCSI_CIR_xxx0
value|0x00200000
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_xxx1
value|0x00100000
end_define

begin_comment
comment|/* RESERVED */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SCSI_CIR_PREF1
value|0x00200000
end_define

begin_comment
comment|/* 53C94 prefetch interupt */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_PREF0
value|0x00100000
end_define

begin_comment
comment|/* 53C94 prefetch interupt */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCSI_CIR_53C94_INT1
value|0x00080000
end_define

begin_comment
comment|/* SCSI[1] 53C94 Interupt */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_53C94_INT0
value|0x00040000
end_define

begin_comment
comment|/* SCSI[0] 53C94 Interupt */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_53C94_DREQ1
value|0x00020000
end_define

begin_comment
comment|/* SCSI[1] 53C94 DREQ */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_53C94_DREQ0
value|0x00010000
end_define

begin_comment
comment|/* SCSI[0] 53C94 DREQ */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_TC_PAR_TEST
value|0x00008000
end_define

begin_comment
comment|/* TC parity test mode */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DB_PAR_TEST
value|0x00004000
end_define

begin_comment
comment|/* DB parity test mode */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DBUF_PAR_TEST1
value|0x00002000
end_define

begin_comment
comment|/* SCSI[1] DMA buffer parity test */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DBUF_PAR_TEST0
value|0x00001000
end_define

begin_comment
comment|/* SCSI[0] DMA buffer parity test */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_RESET1
value|0x00000800
end_define

begin_comment
comment|/* SCSI[1] ~Reset,enable(0)/disable(1) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_RESET0
value|0x00000400
end_define

begin_comment
comment|/* SCSI[0] ~Reset,enable(0)/disable(1) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DMAENA1
value|0x00000200
end_define

begin_comment
comment|/* SCSI[1] DMA enable */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_DMAENA0
value|0x00000100
end_define

begin_comment
comment|/* SCSI[1] DMA enable */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_GPI3
value|0x00000080
end_define

begin_comment
comment|/* General purpose input<3> */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_GPI2
value|0x00000040
end_define

begin_comment
comment|/* General purpose input<2> */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_GPI1
value|0x00000020
end_define

begin_comment
comment|/* General purpose input<1> */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_GPI0
value|0x00000010
end_define

begin_comment
comment|/* General purpose input<0> */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_TXDIS
value|0x00000008
end_define

begin_comment
comment|/* TXDIS- serial transmit disable */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_GPO2
value|0x00000004
end_define

begin_comment
comment|/* General purpose output<2> */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_GPO1
value|0x00000002
end_define

begin_comment
comment|/* General purpose output<1> */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_GPO0
value|0x00000001
end_define

begin_comment
comment|/* General purpose output<0> */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR_ERROR
value|(SCSI_CIR_AIOPAR | SCSI_CIR_WDIOPAR | SCSI_CIR_DMARPAR1 | SCSI_CIR_DMARPAR0 | SCSI_CIR_DMABUFPAR1 | SCSI_CIR_DMABUFPAR0 | SCSI_CIR_DBPAR1 |SCSI_CIR_DBPAR0 | SCSI_CIR_DMAERR1 | SCSI_CIR_DMAERR0 )
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_DMAPTR0
value|(KN15AA_SYS_SCSI + 0x82000)
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_DMAPTR1
value|(KN15AA_SYS_SCSI + 0x82200)
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_DIC0
value|(KN15AA_SYS_SCSI + 0x82008)
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_DIC1
value|(KN15AA_SYS_SCSI + 0x82208)
end_define

begin_define
define|#
directive|define
name|SCSI_DIC_DMADIR
value|0x00000080
end_define

begin_comment
comment|/* DMA direction read(0)/write(1) */
end_comment

begin_define
define|#
directive|define
name|SCSI_DIC_PREFENA
value|0x00000040
end_define

begin_comment
comment|/* DMA read prefetch dis(0)/ena(1) */
end_comment

begin_define
define|#
directive|define
name|SCSI_DIC_DMAADDR1
value|0x00000002
end_define

begin_comment
comment|/* DMA address<1> */
end_comment

begin_define
define|#
directive|define
name|SCSI_DIC_DMAADDR0
value|0x00000001
end_define

begin_comment
comment|/* DMA address<0> */
end_comment

begin_define
define|#
directive|define
name|SCSI_DIC_ADDR_MASK
value|(SCSI_DIC_DMAADDR0 |SCSI_DIC_DMAADDR1)
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_94REG0
value|(KN15AA_SYS_SCSI + 0x100000)
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_94REG1
value|(KN15AA_SYS_SCSI + 0x100200)
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_IMER
value|(KN15AA_SYS_SCSI + 0x80008)
end_define

begin_comment
comment|/* these are the bits that were unalligned at the beginning of the dma */
end_comment

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_DUDB0
value|(KN15AA_SYS_SCSI + 0x82010)
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_DUDB1
value|(KN15AA_SYS_SCSI + 0x82210)
end_define

begin_define
define|#
directive|define
name|SCSI_DUDB_MASK01
value|0x00000001
end_define

begin_comment
comment|/* Mask bit for byte[01] */
end_comment

begin_define
define|#
directive|define
name|SCSI_DUDB_MASK10
value|0x00000002
end_define

begin_comment
comment|/* Mask bit for byte[10] */
end_comment

begin_define
define|#
directive|define
name|SCSI_DUDB_MASK11
value|0x00000004
end_define

begin_comment
comment|/* Mask bit for byte[11] */
end_comment

begin_comment
comment|/* these are the bits that were unalligned at the end of the dma */
end_comment

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_DUDE0
value|(KN15AA_SYS_SCSI + 0x82018)
end_define

begin_define
define|#
directive|define
name|KN15AA_REG_SCSI_DUDE1
value|(KN15AA_SYS_SCSI + 0x82218)
end_define

begin_define
define|#
directive|define
name|SCSI_DUDE_MASK00
value|0x1000000
end_define

begin_comment
comment|/* Mask bit for byte[00] */
end_comment

begin_define
define|#
directive|define
name|SCSI_DUDE_MASK01
value|0x2000000
end_define

begin_comment
comment|/* Mask bit for byte[01] */
end_comment

begin_define
define|#
directive|define
name|SCSI_DUDE_MASK10
value|0x4000000
end_define

begin_comment
comment|/* Mask bit for byte[10] */
end_comment

begin_define
define|#
directive|define
name|SCSI_CIR
value|phystok0seg(KN15AA_REG_SCSI_CIR)
end_define

begin_define
define|#
directive|define
name|SCSI_IMER
value|phystok0seg(KN15AA_REG_SCSI_IMER)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

