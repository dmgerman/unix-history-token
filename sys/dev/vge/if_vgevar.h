begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|VGE_JUMBO_MTU
value|9000
end_define

begin_define
define|#
directive|define
name|VGE_IFQ_MAXLEN
value|64
end_define

begin_define
define|#
directive|define
name|VGE_TX_DESC_CNT
value|256
end_define

begin_define
define|#
directive|define
name|VGE_RX_DESC_CNT
value|252
end_define

begin_comment
comment|/* Must be a multiple of 4!! */
end_comment

begin_define
define|#
directive|define
name|VGE_TX_RING_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|VGE_RX_RING_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|VGE_MAXTXSEGS
value|6
end_define

begin_define
define|#
directive|define
name|VGE_RX_BUF_ALIGN
value|sizeof(uint32_t)
end_define

begin_comment
comment|/*  * VIA Velocity allows 64bit DMA addressing but high 16bits  * of the DMA address should be the same for Tx/Rx buffers.  * Because this condition can't be guaranteed vge(4) limit  * DMA address space to 48bits.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|BUS_SPACE_MAXADDR
operator|<
literal|0xFFFFFFFFFF
operator|)
end_if

begin_define
define|#
directive|define
name|VGE_BUF_DMA_MAXADDR
value|BUS_SPACE_MAXADDR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VGE_BUF_DMA_MAXADDR
value|0xFFFFFFFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VGE_RX_LIST_SZ
value|(VGE_RX_DESC_CNT * sizeof(struct vge_rx_desc))
end_define

begin_define
define|#
directive|define
name|VGE_TX_LIST_SZ
value|(VGE_TX_DESC_CNT * sizeof(struct vge_tx_desc))
end_define

begin_define
define|#
directive|define
name|VGE_TX_DESC_INC
parameter_list|(
name|x
parameter_list|)
value|((x) = ((x) + 1) % VGE_TX_DESC_CNT)
end_define

begin_define
define|#
directive|define
name|VGE_TX_DESC_DEC
parameter_list|(
name|x
parameter_list|)
define|\
value|((x) = (((x) + VGE_TX_DESC_CNT - 1) % VGE_TX_DESC_CNT))
end_define

begin_define
define|#
directive|define
name|VGE_RX_DESC_INC
parameter_list|(
name|x
parameter_list|)
value|((x) = ((x) + 1) % VGE_RX_DESC_CNT)
end_define

begin_define
define|#
directive|define
name|VGE_ADDR_LO
parameter_list|(
name|y
parameter_list|)
value|((uint64_t) (y)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|VGE_ADDR_HI
parameter_list|(
name|y
parameter_list|)
value|((uint64_t) (y)>> 32)
end_define

begin_define
define|#
directive|define
name|VGE_BUFLEN
parameter_list|(
name|y
parameter_list|)
value|((y)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|VGE_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|(((x)& VGE_RDSTS_BUFSIZ)>> 16)
end_define

begin_define
define|#
directive|define
name|VGE_MIN_FRAMELEN
value|60
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VGE_FIXUP_RX
end_ifdef

begin_define
define|#
directive|define
name|VGE_ETHER_ALIGN
value|sizeof(uint32_t)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VGE_ETHER_ALIGN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vge_type
block|{
name|uint16_t
name|vge_vid
decl_stmt|;
name|uint16_t
name|vge_did
decl_stmt|;
name|char
modifier|*
name|vge_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vge_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
name|struct
name|vge_tx_desc
modifier|*
name|tx_desc
decl_stmt|;
name|struct
name|vge_txdesc
modifier|*
name|txd_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vge_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
name|struct
name|vge_rx_desc
modifier|*
name|rx_desc
decl_stmt|;
name|struct
name|vge_rxdesc
modifier|*
name|rxd_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vge_chain_data
block|{
name|bus_dma_tag_t
name|vge_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|vge_buffer_tag
decl_stmt|;
name|bus_dma_tag_t
name|vge_tx_tag
decl_stmt|;
name|struct
name|vge_txdesc
name|vge_txdesc
index|[
name|VGE_TX_DESC_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|vge_rx_tag
decl_stmt|;
name|struct
name|vge_rxdesc
name|vge_rxdesc
index|[
name|VGE_RX_DESC_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|vge_tx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|vge_tx_ring_map
decl_stmt|;
name|bus_dma_tag_t
name|vge_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|vge_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|vge_rx_sparemap
decl_stmt|;
name|int
name|vge_tx_prodidx
decl_stmt|;
name|int
name|vge_tx_considx
decl_stmt|;
name|int
name|vge_tx_cnt
decl_stmt|;
name|int
name|vge_rx_prodidx
decl_stmt|;
name|int
name|vge_rx_commit
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vge_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vge_tail
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGE_CHAIN_RESET
parameter_list|(
name|_sc
parameter_list|)
define|\
value|do {									\ 	if ((_sc)->vge_cdata.vge_head != NULL) {			\ 		m_freem((_sc)->vge_cdata.vge_head);			\ 		(_sc)->vge_cdata.vge_head = NULL;			\ 		(_sc)->vge_cdata.vge_tail = NULL;			\ 	}								\ } while (0);
end_define

begin_struct
struct|struct
name|vge_ring_data
block|{
name|struct
name|vge_tx_desc
modifier|*
name|vge_tx_ring
decl_stmt|;
name|bus_addr_t
name|vge_tx_ring_paddr
decl_stmt|;
name|struct
name|vge_rx_desc
modifier|*
name|vge_rx_ring
decl_stmt|;
name|bus_addr_t
name|vge_rx_ring_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vge_softc
block|{
name|struct
name|ifnet
modifier|*
name|vge_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|vge_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|vge_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|vge_irq
decl_stmt|;
name|void
modifier|*
name|vge_intrhand
decl_stmt|;
name|device_t
name|vge_miibus
decl_stmt|;
name|uint8_t
name|vge_type
decl_stmt|;
name|int
name|vge_if_flags
decl_stmt|;
name|int
name|vge_link
decl_stmt|;
name|int
name|vge_camidx
decl_stmt|;
name|struct
name|mtx
name|vge_mtx
decl_stmt|;
name|struct
name|callout
name|vge_watchdog
decl_stmt|;
name|int
name|vge_timer
decl_stmt|;
name|struct
name|vge_chain_data
name|vge_cdata
decl_stmt|;
name|struct
name|vge_ring_data
name|vge_rdata
decl_stmt|;
name|int
name|suspended
decl_stmt|;
comment|/* 0 = normal  1 = suspended */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->vge_mtx)
end_define

begin_define
define|#
directive|define
name|VGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->vge_mtx)
end_define

begin_define
define|#
directive|define
name|VGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->vge_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_STREAM_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_stream_4(sc->vge_res, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4(sc->vge_res, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_2(sc->vge_res, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1(sc->vge_res, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4(sc->vge_res, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_2(sc->vge_res, reg)
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_1(sc->vge_res, reg)
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_1(sc, reg, CSR_READ_1(sc, reg) | (x))
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_2(sc, reg, CSR_READ_2(sc, reg) | (x))
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, reg, CSR_READ_4(sc, reg) | (x))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_1(sc, reg, CSR_READ_1(sc, reg)& ~(x))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_2(sc, reg, CSR_READ_2(sc, reg)& ~(x))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, reg, CSR_READ_4(sc, reg)& ~(x))
end_define

begin_define
define|#
directive|define
name|VGE_RXCHUNK
value|4
end_define

begin_define
define|#
directive|define
name|VGE_TIMEOUT
value|10000
end_define

end_unit

