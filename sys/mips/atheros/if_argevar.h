begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009, Oleksandr Tymoshenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ARGEVAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ARGEVAR_H__
end_define

begin_define
define|#
directive|define
name|ARGE_TX_RING_COUNT
value|128
end_define

begin_define
define|#
directive|define
name|ARGE_RX_RING_COUNT
value|128
end_define

begin_define
define|#
directive|define
name|ARGE_RX_DMA_SIZE
value|ARGE_RX_RING_COUNT * sizeof(struct arge_desc)
end_define

begin_define
define|#
directive|define
name|ARGE_TX_DMA_SIZE
value|ARGE_TX_RING_COUNT * sizeof(struct arge_desc)
end_define

begin_define
define|#
directive|define
name|ARGE_MAXFRAGS
value|8
end_define

begin_define
define|#
directive|define
name|ARGE_RING_ALIGN
value|sizeof(struct arge_desc)
end_define

begin_define
define|#
directive|define
name|ARGE_RX_ALIGN
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|ARGE_MAXFRAGS
value|8
end_define

begin_define
define|#
directive|define
name|ARGE_TX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->arge_rdata.arge_tx_ring_paddr + sizeof(struct arge_desc) * (i))
end_define

begin_define
define|#
directive|define
name|ARGE_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->arge_rdata.arge_rx_ring_paddr + sizeof(struct arge_desc) * (i))
end_define

begin_define
define|#
directive|define
name|ARGE_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (((x) + 1) % y)
end_define

begin_define
define|#
directive|define
name|ARGE_MII_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ARGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->arge_mtx)
end_define

begin_define
define|#
directive|define
name|ARGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->arge_mtx)
end_define

begin_define
define|#
directive|define
name|ARGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->arge_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|ARGE_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|do {	\ 		bus_write_4(sc->arge_res, (reg), (val)); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ARGE_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4(sc->arge_res, (reg))
end_define

begin_define
define|#
directive|define
name|ARGE_SET_BITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|ARGE_WRITE(sc, reg, ARGE_READ(sc, (reg)) | (bits))
end_define

begin_define
define|#
directive|define
name|ARGE_CLEAR_BITS
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|ARGE_WRITE(sc, reg, ARGE_READ(sc, (reg))& ~(bits))
end_define

begin_comment
comment|/*  * MII registers access macros  */
end_comment

begin_define
define|#
directive|define
name|ARGE_MII_READ
parameter_list|(
name|reg
parameter_list|)
define|\
value|*((volatile uint32_t *)MIPS_PHYS_TO_KSEG1((AR71XX_MII_BASE + reg)))
end_define

begin_define
define|#
directive|define
name|ARGE_MII_WRITE
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|*((volatile uint32_t *)MIPS_PHYS_TO_KSEG1((AR71XX_MII_BASE + reg))) = (val)
end_define

begin_define
define|#
directive|define
name|ARGE_DESC_EMPTY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|ARGE_DESC_MORE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|ARGE_DESC_SIZE_MASK
value|((1<< 12) - 1)
end_define

begin_define
define|#
directive|define
name|ARGE_DMASIZE
parameter_list|(
name|len
parameter_list|)
value|((len)& ARGE_DESC_SIZE_MASK)
end_define

begin_struct
struct|struct
name|arge_desc
block|{
name|uint32_t
name|packet_addr
decl_stmt|;
name|uint32_t
name|packet_ctrl
decl_stmt|;
name|uint32_t
name|next_desc
decl_stmt|;
name|uint32_t
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arge_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arge_rxdesc
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
name|arge_desc
modifier|*
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arge_chain_data
block|{
name|bus_dma_tag_t
name|arge_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|arge_tx_tag
decl_stmt|;
name|struct
name|arge_txdesc
name|arge_txdesc
index|[
name|ARGE_TX_RING_COUNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|arge_rx_tag
decl_stmt|;
name|struct
name|arge_rxdesc
name|arge_rxdesc
index|[
name|ARGE_RX_RING_COUNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|arge_tx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|arge_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|arge_tx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|arge_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|arge_rx_sparemap
decl_stmt|;
name|int
name|arge_tx_pkts
decl_stmt|;
name|int
name|arge_tx_prod
decl_stmt|;
name|int
name|arge_tx_cons
decl_stmt|;
name|int
name|arge_tx_cnt
decl_stmt|;
name|int
name|arge_rx_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arge_ring_data
block|{
name|struct
name|arge_desc
modifier|*
name|arge_rx_ring
decl_stmt|;
name|struct
name|arge_desc
modifier|*
name|arge_tx_ring
decl_stmt|;
name|bus_addr_t
name|arge_rx_ring_paddr
decl_stmt|;
name|bus_addr_t
name|arge_tx_ring_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arge_softc
block|{
name|struct
name|ifnet
modifier|*
name|arge_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|arge_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|arge_res
decl_stmt|;
name|int
name|arge_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|arge_irq
decl_stmt|;
name|void
modifier|*
name|arge_intrhand
decl_stmt|;
name|device_t
name|arge_miibus
decl_stmt|;
name|bus_dma_tag_t
name|arge_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|arge_tag
decl_stmt|;
name|struct
name|mtx
name|arge_mtx
decl_stmt|;
name|struct
name|callout
name|arge_stat_callout
decl_stmt|;
name|struct
name|task
name|arge_link_task
decl_stmt|;
name|struct
name|arge_chain_data
name|arge_cdata
decl_stmt|;
name|struct
name|arge_ring_data
name|arge_rdata
decl_stmt|;
name|int
name|arge_link_status
decl_stmt|;
name|int
name|arge_detach
decl_stmt|;
name|uint32_t
name|arge_intr_status
decl_stmt|;
name|int
name|arge_mac_unit
decl_stmt|;
name|int
name|arge_phy_num
decl_stmt|;
name|uint32_t
name|arge_ddr_flush_reg
decl_stmt|;
name|uint32_t
name|arge_pll_reg
decl_stmt|;
name|uint32_t
name|arge_pll_reg_shift
decl_stmt|;
name|int
name|arge_if_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_ARGEVAR_H__ */
end_comment

end_unit

