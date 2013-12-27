begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_VTEVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_VTEVAR_H
end_define

begin_define
define|#
directive|define
name|VTE_TX_RING_CNT
value|64
end_define

begin_define
define|#
directive|define
name|VTE_TX_RING_ALIGN
value|16
end_define

begin_comment
comment|/*  * The TX/RX descriptor format has no limitation for number of  * descriptors in TX/RX ring.  However, the maximum number of  * descriptors that could be set as RX descriptor ring residue  * counter is 255.  This effectively limits number of RX  * descriptors available to be less than or equal to 255.  */
end_comment

begin_define
define|#
directive|define
name|VTE_RX_RING_CNT
value|128
end_define

begin_define
define|#
directive|define
name|VTE_RX_RING_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|VTE_RX_BUF_ALIGN
value|4
end_define

begin_define
define|#
directive|define
name|VTE_DESC_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) = ((x) + 1) % (y))
end_define

begin_define
define|#
directive|define
name|VTE_TX_RING_SZ
define|\
value|(sizeof(struct vte_tx_desc) * VTE_TX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|VTE_RX_RING_SZ
define|\
value|(sizeof(struct vte_rx_desc) * VTE_RX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|VTE_RX_BUF_SIZE_MAX
value|(MCLBYTES - sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|VTE_MIN_FRAMELEN
value|(ETHER_MIN_LEN - ETHER_CRC_LEN)
end_define

begin_struct
struct|struct
name|vte_rxdesc
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
name|vte_rx_desc
modifier|*
name|rx_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vte_txdesc
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
name|vte_tx_desc
modifier|*
name|tx_desc
decl_stmt|;
name|int
name|tx_flags
decl_stmt|;
define|#
directive|define
name|VTE_TXMBUF
value|0x0001
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vte_chain_data
block|{
name|bus_dma_tag_t
name|vte_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|vte_buffer_tag
decl_stmt|;
name|bus_dma_tag_t
name|vte_tx_tag
decl_stmt|;
name|struct
name|vte_txdesc
name|vte_txdesc
index|[
name|VTE_TX_RING_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vte_txmbufs
index|[
name|VTE_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|vte_rx_tag
decl_stmt|;
name|struct
name|vte_rxdesc
name|vte_rxdesc
index|[
name|VTE_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|vte_tx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|vte_tx_ring_map
decl_stmt|;
name|bus_dma_tag_t
name|vte_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|vte_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|vte_rx_sparemap
decl_stmt|;
name|struct
name|vte_tx_desc
modifier|*
name|vte_tx_ring
decl_stmt|;
name|bus_addr_t
name|vte_tx_ring_paddr
decl_stmt|;
name|struct
name|vte_rx_desc
modifier|*
name|vte_rx_ring
decl_stmt|;
name|bus_addr_t
name|vte_rx_ring_paddr
decl_stmt|;
name|int
name|vte_tx_prod
decl_stmt|;
name|int
name|vte_tx_cons
decl_stmt|;
name|int
name|vte_tx_cnt
decl_stmt|;
name|int
name|vte_rx_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vte_hw_stats
block|{
comment|/* RX stats. */
name|uint32_t
name|rx_frames
decl_stmt|;
name|uint32_t
name|rx_bcast_frames
decl_stmt|;
name|uint32_t
name|rx_mcast_frames
decl_stmt|;
name|uint32_t
name|rx_runts
decl_stmt|;
name|uint32_t
name|rx_crcerrs
decl_stmt|;
name|uint32_t
name|rx_long_frames
decl_stmt|;
name|uint32_t
name|rx_fifo_full
decl_stmt|;
name|uint32_t
name|rx_desc_unavail
decl_stmt|;
name|uint32_t
name|rx_pause_frames
decl_stmt|;
comment|/* TX stats. */
name|uint32_t
name|tx_frames
decl_stmt|;
name|uint32_t
name|tx_underruns
decl_stmt|;
name|uint32_t
name|tx_late_colls
decl_stmt|;
name|uint32_t
name|tx_pause_frames
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vte_ident
block|{
name|uint16_t
name|vendorid
decl_stmt|;
name|uint16_t
name|deviceid
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Software state per device.  */
end_comment

begin_struct
struct|struct
name|vte_softc
block|{
name|struct
name|ifnet
modifier|*
name|vte_ifp
decl_stmt|;
name|device_t
name|vte_dev
decl_stmt|;
name|device_t
name|vte_miibus
decl_stmt|;
name|struct
name|resource
modifier|*
name|vte_res
decl_stmt|;
name|int
name|vte_res_id
decl_stmt|;
name|int
name|vte_res_type
decl_stmt|;
name|struct
name|resource
modifier|*
name|vte_irq
decl_stmt|;
name|void
modifier|*
name|vte_intrhand
decl_stmt|;
specifier|const
name|struct
name|vte_ident
modifier|*
name|vte_ident
decl_stmt|;
name|uint8_t
name|vte_eaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|int
name|vte_flags
decl_stmt|;
define|#
directive|define
name|VTE_FLAG_LINK
value|0x8000
name|struct
name|callout
name|vte_tick_ch
decl_stmt|;
name|struct
name|vte_hw_stats
name|vte_stats
decl_stmt|;
name|struct
name|vte_chain_data
name|vte_cdata
decl_stmt|;
name|int
name|vte_if_flags
decl_stmt|;
name|int
name|vte_watchdog_timer
decl_stmt|;
name|int
name|vte_int_rx_mod
decl_stmt|;
name|int
name|vte_int_tx_mod
decl_stmt|;
name|struct
name|mtx
name|vte_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Register access macros. */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_2((_sc)->vte_res, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_2((_sc)->vte_res, (reg))
end_define

begin_define
define|#
directive|define
name|VTE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->vte_mtx)
end_define

begin_define
define|#
directive|define
name|VTE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->vte_mtx)
end_define

begin_define
define|#
directive|define
name|VTE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->vte_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|VTE_TX_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|VTE_RESET_TIMEOUT
value|100
end_define

begin_define
define|#
directive|define
name|VTE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|VTE_PHY_TIMEOUT
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_VTEVAR_H */
end_comment

end_unit

