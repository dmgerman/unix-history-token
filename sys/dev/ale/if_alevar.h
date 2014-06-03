begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ALEVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_ALEVAR_H
end_define

begin_define
define|#
directive|define
name|ALE_TX_RING_CNT
value|256
end_define

begin_comment
comment|/* Should be multiple of 4. */
end_comment

begin_define
define|#
directive|define
name|ALE_TX_RING_CNT_MIN
value|32
end_define

begin_define
define|#
directive|define
name|ALE_TX_RING_CNT_MAX
value|1020
end_define

begin_define
define|#
directive|define
name|ALE_TX_RING_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|ALE_RX_PAGE_ALIGN
value|32
end_define

begin_define
define|#
directive|define
name|ALE_RX_PAGES
value|2
end_define

begin_define
define|#
directive|define
name|ALE_CMB_ALIGN
value|32
end_define

begin_define
define|#
directive|define
name|ALE_TSO_MAXSEGSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|ALE_TSO_MAXSIZE
value|(65535 + sizeof(struct ether_vlan_header))
end_define

begin_define
define|#
directive|define
name|ALE_MAXTXSEGS
value|35
end_define

begin_define
define|#
directive|define
name|ALE_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|ALE_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)>> 32)
end_define

begin_comment
comment|/* Water mark to kick reclaiming Tx buffers. */
end_comment

begin_define
define|#
directive|define
name|ALE_TX_DESC_HIWAT
value|(ALE_TX_RING_CNT - ((ALE_TX_RING_CNT * 4) / 10))
end_define

begin_define
define|#
directive|define
name|ALE_MSI_MESSAGES
value|1
end_define

begin_define
define|#
directive|define
name|ALE_MSIX_MESSAGES
value|1
end_define

begin_comment
comment|/*  * TODO : Should get real jumbo MTU size.  * The hardware seems to have trouble in dealing with large  * frame length. If you encounter unstability issue, use  * lower MTU size.  */
end_comment

begin_define
define|#
directive|define
name|ALE_JUMBO_FRAMELEN
value|8132
end_define

begin_define
define|#
directive|define
name|ALE_JUMBO_MTU
define|\
value|(ALE_JUMBO_FRAMELEN - sizeof(struct ether_vlan_header) - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|ALE_MAX_FRAMELEN
value|(ETHER_MAX_LEN + ETHER_VLAN_ENCAP_LEN)
end_define

begin_define
define|#
directive|define
name|ALE_DESC_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) = ((x) + 1) % (y))
end_define

begin_struct
struct|struct
name|ale_txdesc
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
name|ale_rx_page
block|{
name|bus_dma_tag_t
name|page_tag
decl_stmt|;
name|bus_dmamap_t
name|page_map
decl_stmt|;
name|uint8_t
modifier|*
name|page_addr
decl_stmt|;
name|bus_addr_t
name|page_paddr
decl_stmt|;
name|bus_dma_tag_t
name|cmb_tag
decl_stmt|;
name|bus_dmamap_t
name|cmb_map
decl_stmt|;
name|uint32_t
modifier|*
name|cmb_addr
decl_stmt|;
name|bus_addr_t
name|cmb_paddr
decl_stmt|;
name|uint32_t
name|cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ale_chain_data
block|{
name|bus_dma_tag_t
name|ale_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|ale_buffer_tag
decl_stmt|;
name|bus_dma_tag_t
name|ale_tx_tag
decl_stmt|;
name|struct
name|ale_txdesc
name|ale_txdesc
index|[
name|ALE_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|ale_tx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|ale_tx_ring_map
decl_stmt|;
name|bus_dma_tag_t
name|ale_rx_mblock_tag
index|[
name|ALE_RX_PAGES
index|]
decl_stmt|;
name|bus_dmamap_t
name|ale_rx_mblock_map
index|[
name|ALE_RX_PAGES
index|]
decl_stmt|;
name|struct
name|tx_desc
modifier|*
name|ale_tx_ring
decl_stmt|;
name|bus_addr_t
name|ale_tx_ring_paddr
decl_stmt|;
name|uint32_t
modifier|*
name|ale_tx_cmb
decl_stmt|;
name|bus_addr_t
name|ale_tx_cmb_paddr
decl_stmt|;
name|bus_dma_tag_t
name|ale_tx_cmb_tag
decl_stmt|;
name|bus_dmamap_t
name|ale_tx_cmb_map
decl_stmt|;
name|uint32_t
name|ale_tx_prod
decl_stmt|;
name|uint32_t
name|ale_tx_cons
decl_stmt|;
name|int
name|ale_tx_cnt
decl_stmt|;
name|struct
name|ale_rx_page
name|ale_rx_page
index|[
name|ALE_RX_PAGES
index|]
decl_stmt|;
name|int
name|ale_rx_curp
decl_stmt|;
name|uint16_t
name|ale_rx_seqno
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ALE_TX_RING_SZ
define|\
value|(sizeof(struct tx_desc) * ALE_TX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|ALE_RX_PAGE_SZ_MIN
value|(8 * 1024)
end_define

begin_define
define|#
directive|define
name|ALE_RX_PAGE_SZ_MAX
value|(1024 * 1024)
end_define

begin_define
define|#
directive|define
name|ALE_RX_FRAMES_PAGE
value|128
end_define

begin_define
define|#
directive|define
name|ALE_RX_PAGE_SZ
define|\
value|(roundup(ALE_MAX_FRAMELEN, ALE_RX_PAGE_ALIGN) * ALE_RX_FRAMES_PAGE)
end_define

begin_define
define|#
directive|define
name|ALE_TX_CMB_SZ
value|(sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|ALE_RX_CMB_SZ
value|(sizeof(uint32_t))
end_define

begin_define
define|#
directive|define
name|ALE_PROC_MIN
value|(ALE_RX_FRAMES_PAGE / 4)
end_define

begin_define
define|#
directive|define
name|ALE_PROC_MAX
define|\
value|((ALE_RX_PAGE_SZ * ALE_RX_PAGES) / ETHER_MAX_LEN)
end_define

begin_define
define|#
directive|define
name|ALE_PROC_DEFAULT
value|(ALE_PROC_MAX / 4)
end_define

begin_struct
struct|struct
name|ale_hw_stats
block|{
comment|/* Rx stats. */
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
name|rx_pause_frames
decl_stmt|;
name|uint32_t
name|rx_control_frames
decl_stmt|;
name|uint32_t
name|rx_crcerrs
decl_stmt|;
name|uint32_t
name|rx_lenerrs
decl_stmt|;
name|uint64_t
name|rx_bytes
decl_stmt|;
name|uint32_t
name|rx_runts
decl_stmt|;
name|uint32_t
name|rx_fragments
decl_stmt|;
name|uint32_t
name|rx_pkts_64
decl_stmt|;
name|uint32_t
name|rx_pkts_65_127
decl_stmt|;
name|uint32_t
name|rx_pkts_128_255
decl_stmt|;
name|uint32_t
name|rx_pkts_256_511
decl_stmt|;
name|uint32_t
name|rx_pkts_512_1023
decl_stmt|;
name|uint32_t
name|rx_pkts_1024_1518
decl_stmt|;
name|uint32_t
name|rx_pkts_1519_max
decl_stmt|;
name|uint32_t
name|rx_pkts_truncated
decl_stmt|;
name|uint32_t
name|rx_fifo_oflows
decl_stmt|;
name|uint32_t
name|rx_rrs_errs
decl_stmt|;
name|uint32_t
name|rx_alignerrs
decl_stmt|;
name|uint64_t
name|rx_bcast_bytes
decl_stmt|;
name|uint64_t
name|rx_mcast_bytes
decl_stmt|;
name|uint32_t
name|rx_pkts_filtered
decl_stmt|;
comment|/* Tx stats. */
name|uint32_t
name|tx_frames
decl_stmt|;
name|uint32_t
name|tx_bcast_frames
decl_stmt|;
name|uint32_t
name|tx_mcast_frames
decl_stmt|;
name|uint32_t
name|tx_pause_frames
decl_stmt|;
name|uint32_t
name|tx_excess_defer
decl_stmt|;
name|uint32_t
name|tx_control_frames
decl_stmt|;
name|uint32_t
name|tx_deferred
decl_stmt|;
name|uint64_t
name|tx_bytes
decl_stmt|;
name|uint32_t
name|tx_pkts_64
decl_stmt|;
name|uint32_t
name|tx_pkts_65_127
decl_stmt|;
name|uint32_t
name|tx_pkts_128_255
decl_stmt|;
name|uint32_t
name|tx_pkts_256_511
decl_stmt|;
name|uint32_t
name|tx_pkts_512_1023
decl_stmt|;
name|uint32_t
name|tx_pkts_1024_1518
decl_stmt|;
name|uint32_t
name|tx_pkts_1519_max
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
name|tx_abort
decl_stmt|;
name|uint32_t
name|tx_underrun
decl_stmt|;
name|uint32_t
name|tx_desc_underrun
decl_stmt|;
name|uint32_t
name|tx_lenerrs
decl_stmt|;
name|uint32_t
name|tx_pkts_truncated
decl_stmt|;
name|uint64_t
name|tx_bcast_bytes
decl_stmt|;
name|uint64_t
name|tx_mcast_bytes
decl_stmt|;
comment|/* Misc. */
name|uint32_t
name|reset_brk_seq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Software state per device.  */
end_comment

begin_struct
struct|struct
name|ale_softc
block|{
name|struct
name|ifnet
modifier|*
name|ale_ifp
decl_stmt|;
name|device_t
name|ale_dev
decl_stmt|;
name|device_t
name|ale_miibus
decl_stmt|;
name|struct
name|resource
modifier|*
name|ale_res
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|resource_spec
modifier|*
name|ale_res_spec
decl_stmt|;
name|struct
name|resource
modifier|*
name|ale_irq
index|[
name|ALE_MSI_MESSAGES
index|]
decl_stmt|;
name|struct
name|resource_spec
modifier|*
name|ale_irq_spec
decl_stmt|;
name|void
modifier|*
name|ale_intrhand
index|[
name|ALE_MSI_MESSAGES
index|]
decl_stmt|;
name|int
name|ale_rev
decl_stmt|;
name|int
name|ale_chip_rev
decl_stmt|;
name|int
name|ale_phyaddr
decl_stmt|;
name|uint8_t
name|ale_eaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|ale_dma_rd_burst
decl_stmt|;
name|uint32_t
name|ale_dma_wr_burst
decl_stmt|;
name|int
name|ale_flags
decl_stmt|;
define|#
directive|define
name|ALE_FLAG_PCIE
value|0x0001
define|#
directive|define
name|ALE_FLAG_PCIX
value|0x0002
define|#
directive|define
name|ALE_FLAG_MSI
value|0x0004
define|#
directive|define
name|ALE_FLAG_MSIX
value|0x0008
define|#
directive|define
name|ALE_FLAG_PMCAP
value|0x0010
define|#
directive|define
name|ALE_FLAG_FASTETHER
value|0x0020
define|#
directive|define
name|ALE_FLAG_JUMBO
value|0x0040
define|#
directive|define
name|ALE_FLAG_RXCSUM_BUG
value|0x0080
define|#
directive|define
name|ALE_FLAG_TXCSUM_BUG
value|0x0100
define|#
directive|define
name|ALE_FLAG_TXCMB_BUG
value|0x0200
define|#
directive|define
name|ALE_FLAG_LINK
value|0x8000
name|struct
name|callout
name|ale_tick_ch
decl_stmt|;
name|struct
name|ale_hw_stats
name|ale_stats
decl_stmt|;
name|struct
name|ale_chain_data
name|ale_cdata
decl_stmt|;
name|int
name|ale_if_flags
decl_stmt|;
name|int
name|ale_watchdog_timer
decl_stmt|;
name|int
name|ale_process_limit
decl_stmt|;
specifier|volatile
name|int
name|ale_morework
decl_stmt|;
name|int
name|ale_int_rx_mod
decl_stmt|;
name|int
name|ale_int_tx_mod
decl_stmt|;
name|int
name|ale_max_frame_size
decl_stmt|;
name|int
name|ale_pagesize
decl_stmt|;
name|struct
name|task
name|ale_int_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|ale_tq
decl_stmt|;
name|struct
name|mtx
name|ale_mtx
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
name|CSR_WRITE_4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((_sc)->ale_res[0], (reg), (val))
end_define

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
value|bus_write_2((_sc)->ale_res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1((_sc)->ale_res[0], (reg), (val))
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
value|bus_read_2((_sc)->ale_res[0], (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4((_sc)->ale_res[0], (reg))
end_define

begin_define
define|#
directive|define
name|ALE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->ale_mtx)
end_define

begin_define
define|#
directive|define
name|ALE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->ale_mtx)
end_define

begin_define
define|#
directive|define
name|ALE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->ale_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ALE_TX_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|ALE_RESET_TIMEOUT
value|100
end_define

begin_define
define|#
directive|define
name|ALE_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|ALE_PHY_TIMEOUT
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_ATEVAR_H */
end_comment

end_unit

