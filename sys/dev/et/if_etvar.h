begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007 Sepherosa Ziehau.  All rights reserved.  *  * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $DragonFly: src/sys/dev/netif/et/if_etvar.h,v 1.4 2007/10/23 14:28:42 sephe Exp $  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|ET_RING_ALIGN
value|4096
end_define

begin_define
define|#
directive|define
name|ET_STATUS_ALIGN
value|8
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
value|4
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
value|(ETHER_HDR_LEN + ETHER_VLAN_ENCAP_LEN +	\ 				 (mtu) + ETHER_CRC_LEN)
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
value|bus_write_4((sc)->sc_mem_res, (reg), (val))
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
value|bus_read_4((sc)->sc_mem_res, (reg))
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

begin_struct
struct|struct
name|et_txdesc
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
struct|;
end_struct

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

begin_define
define|#
directive|define
name|ET_TDCTRL2_CTRL_WORD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_HDX_BACKP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_XMIT_PAUSE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_FRAME_ERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_NO_CRC
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_MAC_OVRRD
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_PAD_PACKET
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_JUMBO_PACKET
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_INS_VLAN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_CSUM_IP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_CSUM_TCP
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ET_TDCTRL2_CSUM_UDP
value|0x00004000
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
struct|;
end_struct

begin_define
define|#
directive|define
name|ET_RXST_INFO1_HASH_PASS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_IPCSUM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_IPCSUM_OK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_TCPCSUM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_TCPCSUM_OK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_WOL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_RXMAC_ERR
value|0x00000040
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_DROP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_FRAME_TRUNC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_JUMBO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_VLAN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_PREV_FRMAE_DROP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_SHORT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_BAD_CARRIER
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_CODE_ERR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_CRC_ERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_LEN_MISMATCH
value|0x00200000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_TOO_LONG
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_OK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_MULTICAST
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_BROADCAST
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_DRIBBLE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_CTL_FRAME
value|0x08000000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_PAUSE_FRAME
value|0x10000000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_UNKWN_CTL_FRAME
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_VLAN_TAG
value|0x40000000
end_define

begin_define
define|#
directive|define
name|ET_RXST_INFO1_LONG_EVENT
value|0x80000000
end_define

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
name|int
function_decl|(
modifier|*
name|rbd_newbuf
function_decl|)
parameter_list|(
name|struct
name|et_rxbuf_data
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|rbd_discard
function_decl|)
parameter_list|(
name|struct
name|et_rxbuf_data
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|et_hw_stats
block|{
comment|/* RX/TX stats. */
name|uint64_t
name|pkts_64
decl_stmt|;
name|uint64_t
name|pkts_65
decl_stmt|;
name|uint64_t
name|pkts_128
decl_stmt|;
name|uint64_t
name|pkts_256
decl_stmt|;
name|uint64_t
name|pkts_512
decl_stmt|;
name|uint64_t
name|pkts_1024
decl_stmt|;
name|uint64_t
name|pkts_1519
decl_stmt|;
comment|/* RX stats. */
name|uint64_t
name|rx_bytes
decl_stmt|;
name|uint64_t
name|rx_frames
decl_stmt|;
name|uint32_t
name|rx_crcerrs
decl_stmt|;
name|uint64_t
name|rx_mcast
decl_stmt|;
name|uint64_t
name|rx_bcast
decl_stmt|;
name|uint32_t
name|rx_control
decl_stmt|;
name|uint32_t
name|rx_pause
decl_stmt|;
name|uint32_t
name|rx_unknown_control
decl_stmt|;
name|uint32_t
name|rx_alignerrs
decl_stmt|;
name|uint32_t
name|rx_lenerrs
decl_stmt|;
name|uint32_t
name|rx_codeerrs
decl_stmt|;
name|uint32_t
name|rx_cserrs
decl_stmt|;
name|uint32_t
name|rx_runts
decl_stmt|;
name|uint64_t
name|rx_oversize
decl_stmt|;
name|uint32_t
name|rx_fragments
decl_stmt|;
name|uint32_t
name|rx_jabbers
decl_stmt|;
name|uint32_t
name|rx_drop
decl_stmt|;
comment|/* TX stats. */
name|uint64_t
name|tx_bytes
decl_stmt|;
name|uint64_t
name|tx_frames
decl_stmt|;
name|uint64_t
name|tx_mcast
decl_stmt|;
name|uint64_t
name|tx_bcast
decl_stmt|;
name|uint32_t
name|tx_pause
decl_stmt|;
name|uint32_t
name|tx_deferred
decl_stmt|;
name|uint32_t
name|tx_excess_deferred
decl_stmt|;
name|uint32_t
name|tx_single_colls
decl_stmt|;
name|uint32_t
name|tx_multi_colls
decl_stmt|;
name|uint32_t
name|tx_late_colls
decl_stmt|;
name|uint32_t
name|tx_excess_colls
decl_stmt|;
name|uint32_t
name|tx_total_colls
decl_stmt|;
name|uint32_t
name|tx_pause_honored
decl_stmt|;
name|uint32_t
name|tx_drop
decl_stmt|;
name|uint32_t
name|tx_jabbers
decl_stmt|;
name|uint32_t
name|tx_crcerrs
decl_stmt|;
name|uint32_t
name|tx_control
decl_stmt|;
name|uint64_t
name|tx_oversize
decl_stmt|;
name|uint32_t
name|tx_undersize
decl_stmt|;
name|uint32_t
name|tx_fragments
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
name|bus_dma_tag_t
name|sc_rx_mini_tag
decl_stmt|;
name|bus_dmamap_t
name|sc_rx_mini_sparemap
decl_stmt|;
name|bus_dma_tag_t
name|sc_rx_tag
decl_stmt|;
name|bus_dmamap_t
name|sc_rx_sparemap
decl_stmt|;
name|bus_dma_tag_t
name|sc_tx_tag
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
name|struct
name|et_hw_stats
name|sc_stats
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
name|ET_FLAG_FASTETHER
value|0x0004
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

begin_define
define|#
directive|define
name|ET_FLAG_LINK
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_IF_ETVAR_H */
end_comment

end_unit

