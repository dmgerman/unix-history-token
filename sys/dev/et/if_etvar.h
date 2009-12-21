begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 The DragonFly Project.  All rights reserved.  *  * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $DragonFly: src/sys/dev/netif/et/if_etvar.h,v 1.4 2007/10/23 14:28:42 sephe Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ETVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_ETVAR_H
end_define

begin_comment
comment|/* DragonFly compatibility */
end_comment

begin_define
define|#
directive|define
name|EVL_ENCAPLEN
value|ETHER_VLAN_ENCAP_LEN
end_define

begin_comment
comment|/*  * Allocate the right type of mbuf for the desired total length.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
name|m_getl
argument_list|(
argument|int len
argument_list|,
argument|int how
argument_list|,
argument|int type
argument_list|,
argument|int flags
argument_list|,
argument|int *psize
argument_list|)
block|{ 	struct
name|mbuf
operator|*
name|m
block|;
name|int
name|size
block|;
if|if
condition|(
name|len
operator|>=
name|MINCLSIZE
condition|)
block|{
name|m
operator|=
name|m_getcl
argument_list|(
name|how
argument_list|,
name|type
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|size
operator|=
name|MCLBYTES
expr_stmt|;
block|}
end_expr_stmt

begin_elseif
elseif|else
if|if
condition|(
name|flags
operator|&
name|M_PKTHDR
condition|)
block|{
name|m
operator|=
name|m_gethdr
argument_list|(
name|how
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|size
operator|=
name|MHLEN
expr_stmt|;
block|}
end_elseif

begin_else
else|else
block|{
name|m
operator|=
name|m_get
argument_list|(
name|how
argument_list|,
name|type
argument_list|)
expr_stmt|;
name|size
operator|=
name|MLEN
expr_stmt|;
block|}
end_else

begin_if
if|if
condition|(
name|psize
operator|!=
name|NULL
condition|)
operator|*
name|psize
operator|=
name|size
expr_stmt|;
end_if

begin_return
return|return
operator|(
name|m
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|ET_ALIGN
value|0x1000
end_define

begin_define
define|#
directive|define
name|ET_NSEG_MAX
value|32
end_define

begin_comment
comment|/* XXX no limit actually */
end_comment

begin_define
define|#
directive|define
name|ET_NSEG_SPARE
value|8
end_define

begin_define
define|#
directive|define
name|ET_TX_NDESC
value|512
end_define

begin_define
define|#
directive|define
name|ET_RX_NDESC
value|512
end_define

begin_define
define|#
directive|define
name|ET_RX_NRING
value|2
end_define

begin_define
define|#
directive|define
name|ET_RX_NSTAT
value|(ET_RX_NRING * ET_RX_NDESC)
end_define

begin_define
define|#
directive|define
name|ET_TX_RING_SIZE
value|(ET_TX_NDESC * sizeof(struct et_txdesc))
end_define

begin_define
define|#
directive|define
name|ET_RX_RING_SIZE
value|(ET_RX_NDESC * sizeof(struct et_rxdesc))
end_define

begin_define
define|#
directive|define
name|ET_RXSTAT_RING_SIZE
value|(ET_RX_NSTAT * sizeof(struct et_rxstat))
end_define

begin_define
define|#
directive|define
name|ET_JUMBO_FRAMELEN
value|(ET_MEM_SIZE - ET_MEM_RXSIZE_MIN -	\ 				 ET_MEM_TXSIZE_EX)
end_define

begin_define
define|#
directive|define
name|ET_JUMBO_MTU
value|(ET_JUMBO_FRAMELEN - ETHER_HDR_LEN -	\ 				 EVL_ENCAPLEN - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|ET_FRAMELEN
parameter_list|(
name|mtu
parameter_list|)
value|(ETHER_HDR_LEN + EVL_ENCAPLEN + (mtu) +	\ 				 ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|ET_JSLOTS
value|(ET_RX_NDESC + 128)
end_define

begin_define
define|#
directive|define
name|ET_JLEN
value|(ET_JUMBO_FRAMELEN + ETHER_ALIGN)
end_define

begin_define
define|#
directive|define
name|ET_JUMBO_MEM_SIZE
value|(ET_JSLOTS * ET_JLEN)
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
value|bus_space_write_4((sc)->sc_mem_bt, (sc)->sc_mem_bh, (reg), (val))
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
value|bus_space_read_4((sc)->sc_mem_bt, (sc)->sc_mem_bh, (reg))
end_define

begin_define
define|#
directive|define
name|ET_ADDR_HI
parameter_list|(
name|addr
parameter_list|)
value|((uint64_t) (addr)>> 32)
end_define

begin_define
define|#
directive|define
name|ET_ADDR_LO
parameter_list|(
name|addr
parameter_list|)
value|((uint64_t) (addr)& 0xffffffff)
end_define

begin_macro
unit|struct
name|et_txdesc
end_macro

begin_block
block|{
name|uint32_t
name|td_addr_hi
decl_stmt|;
name|uint32_t
name|td_addr_lo
decl_stmt|;
name|uint32_t
name|td_ctrl1
decl_stmt|;
comment|/* ET_TDCTRL1_ */
name|uint32_t
name|td_ctrl2
decl_stmt|;
comment|/* ET_TDCTRL2_ */
block|}
end_block

begin_expr_stmt
name|__packed
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|ET_TDCTRL1_LEN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_LAST_FRAG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_FIRST_FRAG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_INTR
value|0x00000004
end_define

begin_struct
struct|struct
name|et_rxdesc
block|{
name|uint32_t
name|rd_addr_lo
decl_stmt|;
name|uint32_t
name|rd_addr_hi
decl_stmt|;
name|uint32_t
name|rd_ctrl
decl_stmt|;
comment|/* ET_RDCTRL_ */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ET_RDCTRL_BUFIDX_MASK
value|0x000003FF
end_define

begin_struct
struct|struct
name|et_rxstat
block|{
name|uint32_t
name|rxst_info1
decl_stmt|;
name|uint32_t
name|rxst_info2
decl_stmt|;
comment|/* ET_RXST_INFO2_ */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ET_RXST_INFO2_LEN_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO2_LEN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO2_BUFIDX_MASK
value|0x03FF0000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO2_BUFIDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO2_RINGIDX_MASK
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO2_RINGIDX_SHIFT
value|26
end_define

begin_struct
struct|struct
name|et_rxstatus
block|{
name|uint32_t
name|rxs_ring
decl_stmt|;
name|uint32_t
name|rxs_stat_ring
decl_stmt|;
comment|/* ET_RXS_STATRING_ */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ET_RXS_STATRING_INDEX_MASK
value|0x0FFF0000
end_define

begin_define
define|#
directive|define
name|ET_RXS_STATRING_INDEX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ET_RXS_STATRING_WRAP
value|0x10000000
end_define

begin_struct
struct|struct
name|et_dmamap_ctx
block|{
name|int
name|nsegs
decl_stmt|;
name|bus_dma_segment_t
modifier|*
name|segs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_txbuf
block|{
name|struct
name|mbuf
modifier|*
name|tb_mbuf
decl_stmt|;
name|bus_dmamap_t
name|tb_dmap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_rxbuf
block|{
name|struct
name|mbuf
modifier|*
name|rb_mbuf
decl_stmt|;
name|bus_dmamap_t
name|rb_dmap
decl_stmt|;
name|bus_addr_t
name|rb_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_txstatus_data
block|{
name|uint32_t
modifier|*
name|txsd_status
decl_stmt|;
name|bus_addr_t
name|txsd_paddr
decl_stmt|;
name|bus_dma_tag_t
name|txsd_dtag
decl_stmt|;
name|bus_dmamap_t
name|txsd_dmap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_rxstatus_data
block|{
name|struct
name|et_rxstatus
modifier|*
name|rxsd_status
decl_stmt|;
name|bus_addr_t
name|rxsd_paddr
decl_stmt|;
name|bus_dma_tag_t
name|rxsd_dtag
decl_stmt|;
name|bus_dmamap_t
name|rxsd_dmap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_rxstat_ring
block|{
name|struct
name|et_rxstat
modifier|*
name|rsr_stat
decl_stmt|;
name|bus_addr_t
name|rsr_paddr
decl_stmt|;
name|bus_dma_tag_t
name|rsr_dtag
decl_stmt|;
name|bus_dmamap_t
name|rsr_dmap
decl_stmt|;
name|int
name|rsr_index
decl_stmt|;
name|int
name|rsr_wrap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_txdesc_ring
block|{
name|struct
name|et_txdesc
modifier|*
name|tr_desc
decl_stmt|;
name|bus_addr_t
name|tr_paddr
decl_stmt|;
name|bus_dma_tag_t
name|tr_dtag
decl_stmt|;
name|bus_dmamap_t
name|tr_dmap
decl_stmt|;
name|int
name|tr_ready_index
decl_stmt|;
name|int
name|tr_ready_wrap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_rxdesc_ring
block|{
name|struct
name|et_rxdesc
modifier|*
name|rr_desc
decl_stmt|;
name|bus_addr_t
name|rr_paddr
decl_stmt|;
name|bus_dma_tag_t
name|rr_dtag
decl_stmt|;
name|bus_dmamap_t
name|rr_dmap
decl_stmt|;
name|uint32_t
name|rr_posreg
decl_stmt|;
name|int
name|rr_index
decl_stmt|;
name|int
name|rr_wrap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_txbuf_data
block|{
name|struct
name|et_txbuf
name|tbd_buf
index|[
name|ET_TX_NDESC
index|]
decl_stmt|;
name|int
name|tbd_start_index
decl_stmt|;
name|int
name|tbd_start_wrap
decl_stmt|;
name|int
name|tbd_used
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|et_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|et_rxbuf_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|et_newbuf_t
function_decl|)
parameter_list|(
name|struct
name|et_rxbuf_data
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|et_rxbuf_data
block|{
name|struct
name|et_rxbuf
name|rbd_buf
index|[
name|ET_RX_NDESC
index|]
decl_stmt|;
name|struct
name|et_softc
modifier|*
name|rbd_softc
decl_stmt|;
name|struct
name|et_rxdesc_ring
modifier|*
name|rbd_ring
decl_stmt|;
name|int
name|rbd_bufsize
decl_stmt|;
name|et_newbuf_t
name|rbd_newbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|device_t
name|sc_miibus
decl_stmt|;
name|bus_space_handle_t
name|sc_mem_bh
decl_stmt|;
name|bus_space_tag_t
name|sc_mem_bt
decl_stmt|;
name|void
modifier|*
name|sc_irq_handle
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
decl_stmt|;
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|int
name|sc_if_flags
decl_stmt|;
name|uint32_t
name|sc_flags
decl_stmt|;
comment|/* ET_FLAG_ */
name|int
name|sc_expcap
decl_stmt|;
name|int
name|sc_mem_rid
decl_stmt|;
name|int
name|sc_irq_rid
decl_stmt|;
name|struct
name|callout
name|sc_tick
decl_stmt|;
name|int
name|watchdog_timer
decl_stmt|;
name|bus_dma_tag_t
name|sc_dtag
decl_stmt|;
name|struct
name|et_rxdesc_ring
name|sc_rx_ring
index|[
name|ET_RX_NRING
index|]
decl_stmt|;
name|struct
name|et_rxstat_ring
name|sc_rxstat_ring
decl_stmt|;
name|struct
name|et_rxstatus_data
name|sc_rx_status
decl_stmt|;
name|struct
name|et_txdesc_ring
name|sc_tx_ring
decl_stmt|;
name|struct
name|et_txstatus_data
name|sc_tx_status
decl_stmt|;
name|bus_dma_tag_t
name|sc_mbuf_dtag
decl_stmt|;
name|bus_dmamap_t
name|sc_mbuf_tmp_dmap
decl_stmt|;
name|struct
name|et_rxbuf_data
name|sc_rx_data
index|[
name|ET_RX_NRING
index|]
decl_stmt|;
name|struct
name|et_txbuf_data
name|sc_tx_data
decl_stmt|;
name|uint32_t
name|sc_tx
decl_stmt|;
name|uint32_t
name|sc_tx_intr
decl_stmt|;
comment|/* 	 * Sysctl variables 	 */
name|int
name|sc_rx_intr_npkts
decl_stmt|;
name|int
name|sc_rx_intr_delay
decl_stmt|;
name|int
name|sc_tx_intr_nsegs
decl_stmt|;
name|uint32_t
name|sc_timer
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ET_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ET_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ET_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ET_FLAG_PCIE
value|0x0001
end_define

begin_define
define|#
directive|define
name|ET_FLAG_MSI
value|0x0002
end_define

begin_define
define|#
directive|define
name|ET_FLAG_TXRX_ENABLED
value|0x0100
end_define

begin_define
define|#
directive|define
name|ET_FLAG_JUMBO
value|0x0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_ETVAR_H */
end_comment

end_unit

