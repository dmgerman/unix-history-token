begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)dmareg.h	7.3 (Berkeley) %G%  *  * from: $Header: dmareg.h,v 1.5 92/11/26 02:28:08 torek Exp $ (LBL)  */
end_comment

begin_comment
comment|/*  * Sun-4c Sbus slot 0 DMA registers.  */
end_comment

begin_struct
struct|struct
name|dmareg
block|{
name|u_long
name|dma_csr
decl_stmt|;
comment|/* control/status register */
name|u_long
name|dma_addr
decl_stmt|;
comment|/* address (virtual: is fed to MMU) */
name|u_long
name|dma_bc
decl_stmt|;
comment|/* byte count (not used) */
name|u_long
name|dma_diag
decl_stmt|;
comment|/* diagnostic register (not used) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits in dma_csr.  *  * Notes in [brackets]:  *	1: not self-clearing, must be reset after being set.  *	2: `drain' is like Unibus `bdp purge', i.e., it tells  *	   the chip to finish up, because there is no more data  *	   going into the buffer register.  Needed only in rev  *	   1 dma chips.  Self-clearing (hence write-only).  *	3: only in rev 1 dma chips.  *	4: only in rev 2 dma chips.  *	5: also enables scsi interrupts.  */
end_comment

begin_define
define|#
directive|define
name|DMA_REV
parameter_list|(
name|csr
parameter_list|)
value|(((csr)>> 28)& 0xf)
end_define

begin_comment
comment|/* device id field */
end_comment

begin_define
define|#
directive|define
name|DMAREV_1
value|0x8
end_define

begin_comment
comment|/* device id = rev 1 DMA */
end_comment

begin_define
define|#
directive|define
name|DMAREV_2
value|0x9
end_define

begin_comment
comment|/* device id = rev 2 DMA */
end_comment

begin_define
define|#
directive|define
name|DMA_1ZERO
value|0x0fff0000
end_define

begin_comment
comment|/* unused; reads as zero [3] */
end_comment

begin_define
define|#
directive|define
name|DMA_NAL
value|0x08000000
end_define

begin_comment
comment|/* next address loaded [4] (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_AL
value|0x04000000
end_define

begin_comment
comment|/* address loaded [4] (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_ON
value|0x02000000
end_define

begin_comment
comment|/* working [4] (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_NAE
value|0x01000000
end_define

begin_comment
comment|/* next-address enable [4] (rw) */
end_comment

begin_define
define|#
directive|define
name|DMA_DTCI
value|0x00800000
end_define

begin_comment
comment|/* disable DMA_TC intr [4] (rw) */
end_comment

begin_define
define|#
directive|define
name|DMA_TURBO
value|0x00400000
end_define

begin_comment
comment|/* faster 53C90A mode [4] (rw) */
end_comment

begin_define
define|#
directive|define
name|DMA_LERR
value|0x00200000
end_define

begin_comment
comment|/* LANCE error [4] (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_ALE
value|0x00100000
end_define

begin_comment
comment|/* LANCE addr latch ena [4] (rw) */
end_comment

begin_define
define|#
directive|define
name|DMA_2ZERO
value|0x000f0000
end_define

begin_comment
comment|/* unused; reads as zero [4] */
end_comment

begin_define
define|#
directive|define
name|DMA_ILACC
value|0x00008000
end_define

begin_comment
comment|/* set for new AMD ethernet chip */
end_comment

begin_define
define|#
directive|define
name|DMA_TC
value|0x00004000
end_define

begin_comment
comment|/* terminal count: dma_bc ran out */
end_comment

begin_define
define|#
directive|define
name|DMA_BCE
value|0x00002000
end_define

begin_comment
comment|/* byte count enable (leave 0) */
end_comment

begin_define
define|#
directive|define
name|DMA_BO
value|0x00001800
end_define

begin_comment
comment|/* byte offset (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_RP
value|0x00000400
end_define

begin_comment
comment|/* request pending (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_ENA
value|0x00000200
end_define

begin_comment
comment|/* enable the dma chip */
end_comment

begin_define
define|#
directive|define
name|DMA_READ
value|0x00000100
end_define

begin_comment
comment|/* set for dev=>mem, i.e., read() */
end_comment

begin_define
define|#
directive|define
name|DMA_RESET
value|0x00000080
end_define

begin_comment
comment|/* reset dma chip [1] */
end_comment

begin_define
define|#
directive|define
name|DMA_DRAIN
value|0x00000040
end_define

begin_comment
comment|/* drain buffered data [2,3] (wo) */
end_comment

begin_define
define|#
directive|define
name|DMA_ERR
value|0x00000040
end_define

begin_comment
comment|/* slave error [4] (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_FLUSH
value|0x00000020
end_define

begin_comment
comment|/* clear PC, EP, and TC [4] (wo) */
end_comment

begin_define
define|#
directive|define
name|DMA_IE
value|0x00000010
end_define

begin_comment
comment|/* interrupt enable [4,5] */
end_comment

begin_define
define|#
directive|define
name|DMA_PC
value|0x0000000c
end_define

begin_comment
comment|/* bytes in pack reg (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_EP
value|0x00000002
end_define

begin_comment
comment|/* error pending (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_IP
value|0x00000001
end_define

begin_comment
comment|/* interrupt pending (ro) */
end_comment

begin_define
define|#
directive|define
name|DMA_BITS
define|\
value|"\20\34NAL\33AL\32ON\31NAE\30DTCI\27TURBO\26LERR\25ALE\ \20ILACC\17TC\16BCE\13RP\12ENA\11READ\10RESET\7DRAIN/ERR\6FLUSH\5IE\2EP\1IP"
end_define

begin_comment
comment|/* DMA_BYTE turns the DMA_BO field into a byte index */
end_comment

begin_define
define|#
directive|define
name|DMA_BYTE
parameter_list|(
name|csr
parameter_list|)
value|(((csr)>> 11)& 3)
end_define

begin_comment
comment|/* DMA_NPACK turns the DMA_PC field into a byte count */
end_comment

begin_define
define|#
directive|define
name|DMA_NPACK
parameter_list|(
name|csr
parameter_list|)
value|(((csr)>> 2)& 3)
end_define

begin_comment
comment|/* DMA_INTR is true if the DMA chip says an ESP or DMA interrupt is pending */
end_comment

begin_define
define|#
directive|define
name|DMA_INTR
parameter_list|(
name|csr
parameter_list|)
value|((csr)& (DMA_IP | DMA_EP))
end_define

end_unit

