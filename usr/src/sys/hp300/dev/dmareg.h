begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dmareg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Hardware layout for the 98620[ABC]:  *	98620A (old 320s?):	byte/word DMA in up to 64K chunks  *	98620B (320s only):	98620A with programmable IPL  *	98620C (all others):	byte/word/longword DMA in up to 4Gb chunks  */
end_comment

begin_define
define|#
directive|define
name|v_char
value|volatile char
end_define

begin_define
define|#
directive|define
name|v_int
value|volatile int
end_define

begin_define
define|#
directive|define
name|vu_char
value|volatile u_char
end_define

begin_define
define|#
directive|define
name|vu_short
value|volatile u_short
end_define

begin_define
define|#
directive|define
name|vu_int
value|volatile u_int
end_define

begin_struct
struct|struct
name|dmaBdevice
block|{
name|v_char
modifier|*
name|dmaB_addr
decl_stmt|;
name|vu_short
name|dmaB_count
decl_stmt|;
name|vu_short
name|dmaB_cmd
decl_stmt|;
define|#
directive|define
name|dmaB_stat
value|dmaB_cmd
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dmadevice
block|{
name|v_char
modifier|*
name|dma_addr
decl_stmt|;
name|vu_int
name|dma_count
decl_stmt|;
name|vu_short
name|dma_cmd
decl_stmt|;
name|vu_short
name|dma_stat
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dmareg
block|{
name|struct
name|dmaBdevice
name|dma_Bchan0
decl_stmt|;
name|struct
name|dmaBdevice
name|dma_Bchan1
decl_stmt|;
comment|/* the rest are 98620C specific */
name|v_char
name|dma_id
index|[
literal|4
index|]
decl_stmt|;
name|vu_char
name|dma_cr
decl_stmt|;
name|char
name|dma_pad1
index|[
literal|0xEB
index|]
decl_stmt|;
name|struct
name|dmadevice
name|dma_chan0
decl_stmt|;
name|char
name|dma_pad2
index|[
literal|0xF4
index|]
decl_stmt|;
name|struct
name|dmadevice
name|dma_chan1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NDMA
value|2
end_define

begin_comment
comment|/* intr level must be>= level of any device using dma.  i.e., splbio */
end_comment

begin_define
define|#
directive|define
name|DMAINTLVL
value|5
end_define

begin_comment
comment|/* addresses */
end_comment

begin_define
define|#
directive|define
name|DMA_BASE
value|IOV(0x500000)
end_define

begin_comment
comment|/* command bits */
end_comment

begin_define
define|#
directive|define
name|DMA_ENAB
value|0x0001
end_define

begin_define
define|#
directive|define
name|DMA_WORD
value|0x0002
end_define

begin_define
define|#
directive|define
name|DMA_WRT
value|0x0004
end_define

begin_define
define|#
directive|define
name|DMA_PRI
value|0x0008
end_define

begin_define
define|#
directive|define
name|DMA_IPL
parameter_list|(
name|x
parameter_list|)
value|(((x) - 3)<< 4)
end_define

begin_define
define|#
directive|define
name|DMA_LWORD
value|0x0100
end_define

begin_define
define|#
directive|define
name|DMA_START
value|0x8000
end_define

begin_comment
comment|/* status bits */
end_comment

begin_define
define|#
directive|define
name|DMA_ARMED
value|0x01
end_define

begin_define
define|#
directive|define
name|DMA_INTR
value|0x02
end_define

begin_define
define|#
directive|define
name|DMA_ACC
value|0x04
end_define

begin_define
define|#
directive|define
name|DMA_HALT
value|0x08
end_define

begin_define
define|#
directive|define
name|DMA_BERR
value|0x10
end_define

begin_define
define|#
directive|define
name|DMA_ALIGN
value|0x20
end_define

begin_define
define|#
directive|define
name|DMA_WRAP
value|0x40
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Macros to attempt to hide the HW differences between the 98620B DMA  * board and the 1TQ4-0401 DMA chip (68020C "board").  The latter  * includes emulation registers for the former but you need to access  * the "native-mode" registers directly in order to do 32-bit DMA.  *  * DMA_CLEAR:	Clear interrupt on DMA board.  We just use the  *		emulation registers on the 98620C as that is easiest.  * DMA_STAT:	Read status register.  Again, we always read the  *		emulation register.  Someday we might want to  *		look at the 98620C status to get the extended bits.  * DMA_ARM:	Load address, count and kick-off DMA.  */
end_comment

begin_define
define|#
directive|define
name|DMA_CLEAR
parameter_list|(
name|dc
parameter_list|)
value|{ v_int dmaclr = (int)dc->sc_Bhwaddr->dmaB_addr; }
end_define

begin_define
define|#
directive|define
name|DMA_STAT
parameter_list|(
name|dc
parameter_list|)
value|dc->sc_Bhwaddr->dmaB_stat
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HP320
argument_list|)
end_if

begin_define
define|#
directive|define
name|DMA_ARM
parameter_list|(
name|dc
parameter_list|,
name|ix
parameter_list|)
define|\
value|if (dc->sc_type == DMA_B) { \ 		register struct dmaBdevice *dma = dc->sc_Bhwaddr; \ 		dma->dmaB_addr = dc->sc_addr[ix]; \ 		dma->dmaB_count = dc->sc_count[ix] - 1; \ 		dma->dmaB_cmd = dc->sc_cmd; \ 	} else { \ 		register struct dmadevice *dma = dc->sc_hwaddr; \ 		dma->dma_addr = dc->sc_addr[ix]; \ 		dma->dma_count = dc->sc_count[ix] - 1; \ 		dma->dma_cmd = dc->sc_cmd; \ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DMA_ARM
parameter_list|(
name|dc
parameter_list|,
name|ix
parameter_list|)
define|\
value|{ \ 		register struct dmadevice *dma = dc->sc_hwaddr; \ 		dma->dma_addr = dc->sc_addr[ix]; \ 		dma->dma_count = dc->sc_count[ix] - 1; \ 		dma->dma_cmd = dc->sc_cmd; \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

