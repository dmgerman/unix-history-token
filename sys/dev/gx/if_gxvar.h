begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000,2001 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_define
define|#
directive|define
name|GX_LOCK
parameter_list|(
name|gx
parameter_list|)
end_define

begin_define
define|#
directive|define
name|GX_UNLOCK
parameter_list|(
name|gx
parameter_list|)
end_define

begin_define
define|#
directive|define
name|mtx_init
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_define
define|#
directive|define
name|mtx_destroy
parameter_list|(
name|a
parameter_list|)
end_define

begin_struct
struct|struct
name|mtx
block|{
name|int
name|filler
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GX_LOCK
parameter_list|(
name|gx
parameter_list|)
value|mtx_lock(&(gx)->gx_mtx)
end_define

begin_define
define|#
directive|define
name|GX_UNLOCK
parameter_list|(
name|gx
parameter_list|)
value|mtx_unlock(&(gx)->gx_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_undef
undef|#
directive|undef
name|vtophys
end_undef

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|alpha_XXX_dmamap((vm_offset_t)va)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCIM_CMD_MWIEN
end_ifndef

begin_define
define|#
directive|define
name|PCIM_CMD_MWIEN
value|0x0010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_comment
comment|/* CSR_WRITE_8 assumes the register is in low/high order */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_8
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|do { \ 	bus_space_write_4(gx->gx_btag, gx->gx_bhandle, reg, val& 0xffffffff); \ 	bus_space_write_4(gx->gx_btag, gx->gx_bhandle, reg + 4, val>> 32); \ } while (0)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(gx->gx_btag, gx->gx_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2(gx->gx_btag, gx->gx_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1(gx->gx_btag, gx->gx_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(gx->gx_btag, gx->gx_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2(gx->gx_btag, gx->gx_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1(gx->gx_btag, gx->gx_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|GX_SETBIT
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(gx, reg, (CSR_READ_4(gx, reg) | (x)))
end_define

begin_define
define|#
directive|define
name|GX_CLRBIT
parameter_list|(
name|gx
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(gx, reg, (CSR_READ_4(gx, reg)& ~(x)))
end_define

begin_comment
comment|/*  * In theory, these can go up to 64K each, but due to chip bugs,   * they are limited to 256 max.  Descriptor counts should be a   * multiple of 8.  */
end_comment

begin_define
define|#
directive|define
name|GX_TX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|GX_RX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|GX_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_define
define|#
directive|define
name|GX_PREV
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x == 0 ? y - 1 : x - 1)
end_define

begin_define
define|#
directive|define
name|GX_MAX_MTU
value|(16 * 1024)
end_define

begin_struct
struct|struct
name|gx_ring_data
block|{
name|struct
name|gx_rx_desc
name|gx_rx_ring
index|[
name|GX_RX_RING_CNT
index|]
decl_stmt|;
name|struct
name|gx_tx_desc
name|gx_tx_ring
index|[
name|GX_TX_RING_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gx_chain_data
block|{
name|struct
name|mbuf
modifier|*
name|gx_rx_chain
index|[
name|GX_RX_RING_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|gx_tx_chain
index|[
name|GX_TX_RING_CNT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gx_regs
block|{
name|int
name|r_rx_base
decl_stmt|;
name|int
name|r_rx_length
decl_stmt|;
name|int
name|r_rx_head
decl_stmt|;
name|int
name|r_rx_tail
decl_stmt|;
name|int
name|r_rx_delay
decl_stmt|;
name|int
name|r_rx_dma_ctrl
decl_stmt|;
name|int
name|r_tx_base
decl_stmt|;
name|int
name|r_tx_length
decl_stmt|;
name|int
name|r_tx_head
decl_stmt|;
name|int
name|r_tx_tail
decl_stmt|;
name|int
name|r_tx_delay
decl_stmt|;
name|int
name|r_tx_dma_ctrl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gx_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* interface info */
name|struct
name|ifmedia
name|gx_media
decl_stmt|;
comment|/* media info */
name|bus_space_handle_t
name|gx_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|gx_btag
decl_stmt|;
comment|/* bus space tag */
name|void
modifier|*
name|gx_intrhand
decl_stmt|;
comment|/* irq handler handle */
name|struct
name|resource
modifier|*
name|gx_irq
decl_stmt|;
comment|/* IRQ resource handle */
name|struct
name|resource
modifier|*
name|gx_res
decl_stmt|;
comment|/* I/O or shared mem handle */
name|device_t
name|gx_dev
decl_stmt|;
name|device_t
name|gx_miibus
decl_stmt|;
name|u_int8_t
name|gx_unit
decl_stmt|;
comment|/* controller number */
name|u_int8_t
name|gx_tbimode
decl_stmt|;
comment|/* transceiver flag */
name|int
name|gx_vflags
decl_stmt|;
comment|/* version-specific flags */
name|u_int32_t
name|gx_ipg
decl_stmt|;
comment|/* version-specific IPG */
name|struct
name|gx_ring_data
modifier|*
name|gx_rdata
decl_stmt|;
name|struct
name|gx_chain_data
name|gx_cdata
decl_stmt|;
name|int
name|gx_if_flags
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|gx_pkthdr
decl_stmt|;
name|struct
name|mbuf
modifier|*
modifier|*
name|gx_pktnextp
decl_stmt|;
name|int
name|gx_rx_tail_idx
decl_stmt|;
comment|/* receive ring tail index */
name|int
name|gx_tx_tail_idx
decl_stmt|;
comment|/* transmit ring tail index */
name|int
name|gx_tx_head_idx
decl_stmt|;
comment|/* transmit ring tail index */
name|int
name|gx_txcnt
decl_stmt|;
name|int
name|gx_txcontext
decl_stmt|;
comment|/* current TX context */
name|struct
name|gx_regs
name|gx_reg
decl_stmt|;
name|struct
name|mtx
name|gx_mtx
decl_stmt|;
comment|/* tunables */
name|int
name|gx_tx_intr_delay
decl_stmt|;
name|int
name|gx_rx_intr_delay
decl_stmt|;
comment|/* statistics */
name|int
name|gx_tx_interrupts
decl_stmt|;
name|int
name|gx_rx_interrupts
decl_stmt|;
name|int
name|gx_interrupts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * flags to compensate for differing chip variants  */
end_comment

begin_define
define|#
directive|define
name|GXF_FORCE_TBI
value|0x0001
end_define

begin_comment
comment|/* force TBI mode on */
end_comment

begin_define
define|#
directive|define
name|GXF_DMA
value|0x0002
end_define

begin_comment
comment|/* has DMA control registers */
end_comment

begin_define
define|#
directive|define
name|GXF_ENABLE_MWI
value|0x0004
end_define

begin_comment
comment|/* supports MWI burst mode */
end_comment

begin_define
define|#
directive|define
name|GXF_OLD_REGS
value|0x0008
end_define

begin_comment
comment|/* use old register mapping */
end_comment

begin_define
define|#
directive|define
name|GXF_CSUM
value|0x0010
end_define

begin_comment
comment|/* hardware checksum offload */
end_comment

begin_comment
comment|/*  * TX Context definitions.  */
end_comment

begin_define
define|#
directive|define
name|GX_TXCONTEXT_NONE
value|0
end_define

begin_define
define|#
directive|define
name|GX_TXCONTEXT_TCPIP
value|1
end_define

begin_define
define|#
directive|define
name|GX_TXCONTEXT_UDPIP
value|2
end_define

end_unit

