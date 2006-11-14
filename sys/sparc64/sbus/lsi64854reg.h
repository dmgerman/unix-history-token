begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lsi64854reg.h,v 1.5 2001/03/29 02:58:39 petrov Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_comment
comment|/*  * LSI 64854 DMA engine. Contains three independent channels  * designed to interface with (a) a NCR539X SCSI controller,  * (b) a AM7990 Ethernet controller, (c) Parallel port hardware..  */
end_comment

begin_comment
comment|/*  * Register offsets to bus handle.  */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_CSR
value|0
end_define

begin_comment
comment|/* Control bits */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_ADDR
value|4
end_define

begin_comment
comment|/* DMA Address */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_CNT
value|8
end_define

begin_comment
comment|/* DMA count */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_CNT_MASK
value|0x00ffffff
end_define

begin_comment
comment|/*   only 24 bits */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_ENBAR
value|12
end_define

begin_comment
comment|/* ENET Base register */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_TEST
value|12
end_define

begin_comment
comment|/* SCSI Test register */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_HCR
value|16
end_define

begin_comment
comment|/* PP Hardware Configuration */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_OCR
value|18
end_define

begin_comment
comment|/* PP Operation Configuration */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_DR
value|20
end_define

begin_comment
comment|/* PP Data register */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_TCR
value|21
end_define

begin_comment
comment|/* PP Transfer Control */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_OR
value|22
end_define

begin_comment
comment|/* PP Output register */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_IR
value|23
end_define

begin_comment
comment|/* PP Input register */
end_comment

begin_define
define|#
directive|define
name|L64854_REG_ICR
value|24
end_define

begin_comment
comment|/* PP Interrupt Control */
end_comment

begin_comment
comment|/*  * Control bits common to all three channels.  */
end_comment

begin_define
define|#
directive|define
name|L64854_INT_PEND
value|0x00000001
end_define

begin_comment
comment|/* Interrupt pending */
end_comment

begin_define
define|#
directive|define
name|L64854_ERR_PEND
value|0x00000002
end_define

begin_comment
comment|/* Error pending */
end_comment

begin_define
define|#
directive|define
name|L64854_DRAINING
value|0x0000000c
end_define

begin_comment
comment|/* FIFO draining */
end_comment

begin_define
define|#
directive|define
name|L64854_INT_EN
value|0x00000010
end_define

begin_comment
comment|/* Interrupt enable */
end_comment

begin_define
define|#
directive|define
name|L64854_INVALIDATE
value|0x00000020
end_define

begin_comment
comment|/* Invalidate FIFO */
end_comment

begin_define
define|#
directive|define
name|L64854_SLAVE_ERR
value|0x00000040
end_define

begin_comment
comment|/* Slave access size error */
end_comment

begin_define
define|#
directive|define
name|L64854_RESET
value|0x00000080
end_define

begin_comment
comment|/* Reset device */
end_comment

begin_define
define|#
directive|define
name|L64854_WRITE
value|0x00000100
end_define

begin_comment
comment|/* 1: xfer to memory */
end_comment

begin_define
define|#
directive|define
name|L64854_EN_DMA
value|0x00000200
end_define

begin_comment
comment|/* enable DMA transfers */
end_comment

begin_define
define|#
directive|define
name|L64854_BURST_SIZE
value|0x000c0000
end_define

begin_comment
comment|/* Read/write burst size */
end_comment

begin_define
define|#
directive|define
name|L64854_BURST_0
value|0x00080000
end_define

begin_comment
comment|/*   no bursts (SCSI-only) */
end_comment

begin_define
define|#
directive|define
name|L64854_BURST_16
value|0x00000000
end_define

begin_comment
comment|/*   16-byte bursts */
end_comment

begin_define
define|#
directive|define
name|L64854_BURST_32
value|0x00040000
end_define

begin_comment
comment|/*   32-byte bursts */
end_comment

begin_define
define|#
directive|define
name|L64854_BURST_64
value|0x000c0000
end_define

begin_comment
comment|/*   64-byte bursts (fas) */
end_comment

begin_define
define|#
directive|define
name|L64854_RST_FAS366
value|0x08000000
end_define

begin_comment
comment|/* FAS366 hardware reset */
end_comment

begin_define
define|#
directive|define
name|L64854_DEVID
value|0xf0000000
end_define

begin_comment
comment|/* device ID bits */
end_comment

begin_comment
comment|/*  * SCSI DMA control bits.  */
end_comment

begin_define
define|#
directive|define
name|D_INT_PEND
value|L64854_INT_PEND
end_define

begin_comment
comment|/* interrupt pending */
end_comment

begin_define
define|#
directive|define
name|D_ERR_PEND
value|L64854_ERR_PEND
end_define

begin_comment
comment|/* error pending */
end_comment

begin_define
define|#
directive|define
name|D_DRAINING
value|L64854_DRAINING
end_define

begin_comment
comment|/* fifo draining */
end_comment

begin_define
define|#
directive|define
name|D_INT_EN
value|L64854_INT_EN
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|D_INVALIDATE
value|L64854_INVALIDATE
end_define

begin_comment
comment|/* invalidate fifo */
end_comment

begin_define
define|#
directive|define
name|D_SLAVE_ERR
value|L64854_SLAVE_ERR
end_define

begin_comment
comment|/* slave access size error */
end_comment

begin_define
define|#
directive|define
name|D_RESET
value|L64854_RESET
end_define

begin_comment
comment|/* reset scsi */
end_comment

begin_define
define|#
directive|define
name|D_WRITE
value|L64854_WRITE
end_define

begin_comment
comment|/* 1 = dev -> mem */
end_comment

begin_define
define|#
directive|define
name|D_EN_DMA
value|L64854_EN_DMA
end_define

begin_comment
comment|/* enable DMA requests */
end_comment

begin_define
define|#
directive|define
name|D_EN_CNT
value|0x00002000
end_define

begin_comment
comment|/* enable byte counter */
end_comment

begin_define
define|#
directive|define
name|D_TC
value|0x00004000
end_define

begin_comment
comment|/* terminal count */
end_comment

begin_define
define|#
directive|define
name|D_WIDE_EN
value|0x00008000
end_define

begin_comment
comment|/* enable wide mode SBUS DMA (fas) */
end_comment

begin_define
define|#
directive|define
name|D_DSBL_CSR_DRN
value|0x00010000
end_define

begin_comment
comment|/* disable fifo drain on csr */
end_comment

begin_define
define|#
directive|define
name|D_DSBL_SCSI_DRN
value|0x00020000
end_define

begin_comment
comment|/* disable fifo drain on reg */
end_comment

begin_define
define|#
directive|define
name|D_DIAG
value|0x00100000
end_define

begin_comment
comment|/* disable fifo drain on addr */
end_comment

begin_define
define|#
directive|define
name|D_TWO_CYCLE
value|0x00200000
end_define

begin_comment
comment|/* 2 clocks per transfer */
end_comment

begin_define
define|#
directive|define
name|D_FASTER
value|0x00400000
end_define

begin_comment
comment|/* 3 clocks per transfer */
end_comment

begin_define
define|#
directive|define
name|D_TCI_DIS
value|0x00800000
end_define

begin_comment
comment|/* disable intr on D_TC */
end_comment

begin_define
define|#
directive|define
name|D_EN_NEXT
value|0x01000000
end_define

begin_comment
comment|/* enable auto next address */
end_comment

begin_define
define|#
directive|define
name|D_DMA_ON
value|0x02000000
end_define

begin_comment
comment|/* enable dma from scsi XXX */
end_comment

begin_define
define|#
directive|define
name|D_DSBL_PARITY_CHK
define|\
value|0x02000000
end_define

begin_comment
comment|/* disable checking for parity on bus (default 1:fas) */
end_comment

begin_define
define|#
directive|define
name|D_A_LOADED
value|0x04000000
end_define

begin_comment
comment|/* address loaded */
end_comment

begin_define
define|#
directive|define
name|D_NA_LOADED
value|0x08000000
end_define

begin_comment
comment|/* next address loaded */
end_comment

begin_define
define|#
directive|define
name|D_HW_RESET_FAS366
define|\
value|0x08000000
end_define

begin_comment
comment|/* hardware reset FAS366 (fas) */
end_comment

begin_define
define|#
directive|define
name|D_DEV_ID
value|L64854_DEVID
end_define

begin_comment
comment|/* device ID */
end_comment

begin_define
define|#
directive|define
name|DMAREV_0
value|0x00000000
end_define

begin_comment
comment|/* Sunray DMA */
end_comment

begin_define
define|#
directive|define
name|DMAREV_ESC
value|0x40000000
end_define

begin_comment
comment|/*  DMA ESC array */
end_comment

begin_define
define|#
directive|define
name|DMAREV_1
value|0x80000000
end_define

begin_comment
comment|/* 'DMA' */
end_comment

begin_define
define|#
directive|define
name|DMAREV_PLUS
value|0x90000000
end_define

begin_comment
comment|/* 'DMA+' */
end_comment

begin_define
define|#
directive|define
name|DMAREV_2
value|0xa0000000
end_define

begin_comment
comment|/* 'DMA2' */
end_comment

begin_define
define|#
directive|define
name|DMAREV_HME
value|0xb0000000
end_define

begin_comment
comment|/* 'HME'  */
end_comment

begin_comment
comment|/*  * revisions 0,1 and ESC have different bits.  */
end_comment

begin_define
define|#
directive|define
name|D_ESC_DRAIN
value|0x00000040
end_define

begin_comment
comment|/* rev0,1,esc: drain fifo */
end_comment

begin_define
define|#
directive|define
name|D_ESC_R_PEND
value|0x00000400
end_define

begin_comment
comment|/* rev0,1: request pending */
end_comment

begin_define
define|#
directive|define
name|D_ESC_BURST
value|0x00000800
end_define

begin_comment
comment|/* DMA ESC: 16 byte bursts */
end_comment

begin_define
define|#
directive|define
name|D_ESC_AUTODRAIN
value|0x00040000
end_define

begin_comment
comment|/* DMA ESC: Auto-drain */
end_comment

begin_define
define|#
directive|define
name|DDMACSR_BITS
value|"\177\020"				\ 	"b\00INT\0b\01ERR\0f\02\02DRAINING\0b\04IEN\0"		\ 	"b\06SLVERR\0b\07RST\0b\10WRITE\0b\11ENDMA\0"		\ 	"b\15ENCNT\0b\16TC\0\b\20DSBL_CSR_DRN\0"		\ 	"b\21DSBL_SCSI_DRN\0f\22\2BURST\0b\25TWOCYCLE\0"	\ 	"b\26FASTER\0b\27TCIDIS\0b\30ENNXT\0b\031DMAON\0"	\ 	"b\32ALOADED\0b\33NALOADED\0"
end_define

begin_comment
comment|/*  * ENET DMA control bits.  */
end_comment

begin_define
define|#
directive|define
name|E_INT_PEND
value|L64854_INT_PEND
end_define

begin_comment
comment|/* interrupt pending */
end_comment

begin_define
define|#
directive|define
name|E_ERR_PEND
value|L64854_ERR_PEND
end_define

begin_comment
comment|/* error pending */
end_comment

begin_define
define|#
directive|define
name|E_DRAINING
value|L64854_DRAINING
end_define

begin_comment
comment|/* fifo draining */
end_comment

begin_define
define|#
directive|define
name|E_INT_EN
value|L64854_INT_EN
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|E_INVALIDATE
value|L64854_INVALIDATE
end_define

begin_comment
comment|/* invalidate fifo */
end_comment

begin_define
define|#
directive|define
name|E_SLAVE_ERR
value|L64854_SLAVE_ERR
end_define

begin_comment
comment|/* slave access size error */
end_comment

begin_define
define|#
directive|define
name|E_RESET
value|L64854_RESET
end_define

begin_comment
comment|/* reset ENET */
end_comment

begin_define
define|#
directive|define
name|E_reserved1
value|0x00000300
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|E_DRAIN
value|0x00000400
end_define

begin_comment
comment|/* force Ecache drain */
end_comment

begin_define
define|#
directive|define
name|E_DSBL_WR_DRN
value|0x00000800
end_define

begin_comment
comment|/* disable Ecache drain on .. */
end_comment

begin_define
define|#
directive|define
name|E_DSBL_RD_DRN
value|0x00001000
end_define

begin_comment
comment|/* disable Ecache drain on .. */
end_comment

begin_define
define|#
directive|define
name|E_reserved2
value|0x00006000
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|E_ILACC
value|0x00008000
end_define

begin_comment
comment|/* ... */
end_comment

begin_define
define|#
directive|define
name|E_DSBL_BUF_WR
value|0x00010000
end_define

begin_comment
comment|/* no buffering of slave writes */
end_comment

begin_define
define|#
directive|define
name|E_DSBL_WR_INVAL
value|0x00020000
end_define

begin_comment
comment|/* no Ecache invalidate on slave writes */
end_comment

begin_define
define|#
directive|define
name|E_reserved3
value|0x00100000
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|E_LOOP_TEST
value|0x00200000
end_define

begin_comment
comment|/* loopback mode */
end_comment

begin_define
define|#
directive|define
name|E_TP_AUI
value|0x00400000
end_define

begin_comment
comment|/* 1 for TP, 0 for AUI */
end_comment

begin_define
define|#
directive|define
name|E_reserved4
value|0x0c800000
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|E_DEV_ID
value|L64854_DEVID
end_define

begin_comment
comment|/* ID bits */
end_comment

begin_define
define|#
directive|define
name|EDMACSR_BITS
value|"\177\020"				\ 	"b\00INT\0b\01ERR\0f\02\02DRAINING\0b\04IEN\0"		\ 	"b\06SLVERR\0b\07RST\0b\10WRITE\0b\12DRAIN\0"		\ 	"b\13DSBL_WR_DRN\0b\14DSBL_RD_DRN\0b\17ILACC\0"		\ 	"b\20DSBL_BUF_WR\0b\21DSBL_WR_INVAL\0"			\ 	"b\25LOOPTEST\0b\26TP\0"
end_define

begin_comment
comment|/*  * PP DMA control bits.  */
end_comment

begin_define
define|#
directive|define
name|P_INT_PEND
value|L64854_INT_PEND
end_define

begin_comment
comment|/* interrupt pending */
end_comment

begin_define
define|#
directive|define
name|P_ERR_PEND
value|L64854_ERR_PEND
end_define

begin_comment
comment|/* error pending */
end_comment

begin_define
define|#
directive|define
name|P_DRAINING
value|L64854_DRAINING
end_define

begin_comment
comment|/* fifo draining */
end_comment

begin_define
define|#
directive|define
name|P_INT_EN
value|L64854_INT_EN
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|P_INVALIDATE
value|L64854_INVALIDATE
end_define

begin_comment
comment|/* invalidate fifo */
end_comment

begin_define
define|#
directive|define
name|P_SLAVE_ERR
value|L64854_SLAVE_ERR
end_define

begin_comment
comment|/* slave access size error */
end_comment

begin_define
define|#
directive|define
name|P_RESET
value|L64854_RESET
end_define

begin_comment
comment|/* reset PP */
end_comment

begin_define
define|#
directive|define
name|P_WRITE
value|L64854_WRITE
end_define

begin_comment
comment|/* 1: xfer to memory */
end_comment

begin_define
define|#
directive|define
name|P_EN_DMA
value|L64854_EN_DMA
end_define

begin_comment
comment|/* enable DMA transfers */
end_comment

begin_define
define|#
directive|define
name|P_reserved1
value|0x00001c00
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P_EN_CNT
value|0x00002000
end_define

begin_comment
comment|/* enable counter */
end_comment

begin_define
define|#
directive|define
name|P_TC
value|0x00004000
end_define

begin_comment
comment|/* terminal count */
end_comment

begin_define
define|#
directive|define
name|P_reserved2
value|0x00038000
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P_DIAG
value|0x00100000
end_define

begin_comment
comment|/* ... */
end_comment

begin_define
define|#
directive|define
name|P_reserved3
value|0x00600000
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|P_TCI_DIS
value|0x00800000
end_define

begin_comment
comment|/* no interrupt on terminal count */
end_comment

begin_define
define|#
directive|define
name|P_EN_NEXT
value|0x01000000
end_define

begin_comment
comment|/* enable DMA chaining */
end_comment

begin_define
define|#
directive|define
name|P_DMA_ON
value|0x02000000
end_define

begin_comment
comment|/* DMA xfers enabled */
end_comment

begin_define
define|#
directive|define
name|P_A_LOADED
value|0x04000000
end_define

begin_comment
comment|/* addr and byte count valid */
end_comment

begin_define
define|#
directive|define
name|P_NA_LOADED
value|0x08000000
end_define

begin_comment
comment|/* next addr& count valid but not used */
end_comment

begin_define
define|#
directive|define
name|P_DEV_ID
value|L64854_DEVID
end_define

begin_comment
comment|/* ID bits */
end_comment

begin_define
define|#
directive|define
name|PDMACSR_BITS
value|"\177\020"				\ 	"b\00INT\0b\01ERR\0f\02\02DRAINING\0b\04IEN\0"		\ 	"b\06SLVERR\0b\07RST\0b\10WRITE\0b\11ENDMA\0"		\ 	"b\15ENCNT\0b\16TC\0\b\24DIAG\0b\27TCIDIS\0"		\ 	"b\30ENNXT\0b\031DMAON\0b\32ALOADED\0b\33NALOADED\0"
end_define

end_unit

