begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * File: qlnx_def.h  * Author : David C Somayajulu, Cavium Inc., San Jose, CA 95131.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLNX_DEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLNX_DEF_H_
end_define

begin_define
define|#
directive|define
name|VER_SIZE
value|16
end_define

begin_struct
struct|struct
name|qlnx_ivec
block|{
name|uint32_t
name|rss_idx
decl_stmt|;
name|void
modifier|*
name|ha
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_ivec
name|qlnx_ivec_t
typedef|;
end_typedef

begin_comment
comment|//#define QLNX_MAX_RSS	30
end_comment

begin_define
define|#
directive|define
name|QLNX_MAX_RSS
value|16
end_define

begin_define
define|#
directive|define
name|QLNX_MAX_TC
value|1
end_define

begin_enum
enum|enum
name|QLNX_STATE
block|{
name|QLNX_STATE_CLOSED
block|,
name|QLNX_STATE_OPEN
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|HILO_U64
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
value|((((u64)(hi))<< 32) + (lo))
end_define

begin_define
define|#
directive|define
name|MAX_NUM_TC
value|8
end_define

begin_define
define|#
directive|define
name|MAX_NUM_PRI
value|8
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BITS_PER_BYTE
end_ifndef

begin_define
define|#
directive|define
name|BITS_PER_BYTE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef BITS_PER_BYTE */
end_comment

begin_comment
comment|/*   * RX ring buffer contains pointer to kmalloc() data only,  */
end_comment

begin_struct
struct|struct
name|sw_rx_data
block|{
name|void
modifier|*
name|data
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|dma_addr_t
name|dma_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|qlnx_agg_state
block|{
name|QLNX_AGG_STATE_NONE
init|=
literal|0
block|,
name|QLNX_AGG_STATE_START
init|=
literal|1
block|,
name|QLNX_AGG_STATE_ERROR
init|=
literal|2
block|}
enum|;
end_enum

begin_struct
struct|struct
name|qlnx_agg_info
block|{
comment|/* rx_buf is a data buffer that can be placed /consumed from rx bd          * chain. It has two purposes: We will preallocate the data buffer          * for each aggregation when we open the interface and will place this          * buffer on the rx-bd-ring when we receive TPA_START. We don't want          * to be in a state where allocation fails, as we can't reuse the          * consumer buffer in the rx-chain since FW may still be writing to it          * (since header needs to be modified for TPA.          * The second purpose is to keep a pointer to the bd buffer during          * aggregation.          */
name|struct
name|sw_rx_data
name|rx_buf
decl_stmt|;
name|enum
name|qlnx_agg_state
name|agg_state
decl_stmt|;
name|uint16_t
name|placement_offset
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mpf
decl_stmt|;
comment|/* first mbuf in chain */
name|struct
name|mbuf
modifier|*
name|mpl
decl_stmt|;
comment|/* last mbuf in chain */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RX_RING_SIZE_POW
value|13
end_define

begin_define
define|#
directive|define
name|RX_RING_SIZE
value|(1<< RX_RING_SIZE_POW)
end_define

begin_define
define|#
directive|define
name|TX_RING_SIZE_POW
value|14
end_define

begin_define
define|#
directive|define
name|TX_RING_SIZE
value|(1<< TX_RING_SIZE_POW)
end_define

begin_struct
struct|struct
name|qlnx_rx_queue
block|{
specifier|volatile
name|__le16
modifier|*
name|hw_cons_ptr
decl_stmt|;
name|struct
name|sw_rx_data
name|sw_rx_ring
index|[
name|RX_RING_SIZE
index|]
decl_stmt|;
name|uint16_t
name|sw_rx_cons
decl_stmt|;
name|uint16_t
name|sw_rx_prod
decl_stmt|;
name|struct
name|ecore_chain
name|rx_bd_ring
decl_stmt|;
name|struct
name|ecore_chain
name|rx_comp_ring
decl_stmt|;
name|void
name|__iomem
modifier|*
name|hw_rxq_prod_addr
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
comment|/* LRO */
name|struct
name|qlnx_agg_info
name|tpa_info
index|[
name|ETH_TPA_MAX_AGGS_NUM
index|]
decl_stmt|;
name|uint32_t
name|rx_buf_size
decl_stmt|;
name|uint16_t
name|num_rx_buffers
decl_stmt|;
name|uint16_t
name|rxq_id
decl_stmt|;
ifdef|#
directive|ifdef
name|QLNX_SOFT_LRO
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_union
union|union
name|db_prod
block|{
name|struct
name|eth_db_data
name|data
decl_stmt|;
name|uint32_t
name|raw
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|sw_tx_bd
block|{
name|struct
name|mbuf
modifier|*
name|mp
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|int
name|nsegs
decl_stmt|;
comment|/* Set on the first BD descriptor when there is a split BD */
define|#
directive|define
name|QLNX_TSO_SPLIT_BD
value|(1<<0)
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|QLNX_MAX_SEGMENTS
value|255
end_define

begin_struct
struct|struct
name|qlnx_tx_queue
block|{
name|int
name|index
decl_stmt|;
comment|/* Queue index */
specifier|volatile
name|__le16
modifier|*
name|hw_cons_ptr
decl_stmt|;
name|struct
name|sw_tx_bd
name|sw_tx_ring
index|[
name|TX_RING_SIZE
index|]
decl_stmt|;
name|uint16_t
name|sw_tx_cons
decl_stmt|;
name|uint16_t
name|sw_tx_prod
decl_stmt|;
name|struct
name|ecore_chain
name|tx_pbl
decl_stmt|;
name|void
name|__iomem
modifier|*
name|doorbell_addr
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|union
name|db_prod
name|tx_db
decl_stmt|;
name|bus_dma_segment_t
name|segs
index|[
name|QLNX_MAX_SEGMENTS
index|]
decl_stmt|;
name|uint16_t
name|num_tx_buffers
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BD_UNMAP_ADDR
parameter_list|(
name|bd
parameter_list|)
value|HILO_U64(le32toh((bd)->addr.hi), \ 					le32toh((bd)->addr.lo))
end_define

begin_define
define|#
directive|define
name|BD_UNMAP_LEN
parameter_list|(
name|bd
parameter_list|)
value|(le16toh((bd)->nbytes))
end_define

begin_define
define|#
directive|define
name|BD_SET_UNMAP_ADDR_LEN
parameter_list|(
name|bd
parameter_list|,
name|maddr
parameter_list|,
name|len
parameter_list|)
define|\
value|do { \                 (bd)->addr.hi = htole32(U64_HI(maddr)); \                 (bd)->addr.lo = htole32(U64_LO(maddr)); \                 (bd)->nbytes = htole16(len); \         } while (0);
end_define

begin_define
define|#
directive|define
name|QLNX_FP_MAX_SEGS
value|24
end_define

begin_struct
struct|struct
name|qlnx_fastpath
block|{
name|void
modifier|*
name|edev
decl_stmt|;
name|uint8_t
name|rss_id
decl_stmt|;
name|struct
name|ecore_sb_info
modifier|*
name|sb_info
decl_stmt|;
name|struct
name|qlnx_rx_queue
modifier|*
name|rxq
decl_stmt|;
name|struct
name|qlnx_tx_queue
modifier|*
name|txq
index|[
name|MAX_NUM_TC
index|]
decl_stmt|;
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|mtx
name|tx_mtx
decl_stmt|;
name|char
name|tx_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|tx_br
decl_stmt|;
name|struct
name|task
name|fp_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|fp_taskqueue
decl_stmt|;
comment|/* transmit statistics */
name|uint64_t
name|tx_pkts_processed
decl_stmt|;
name|uint64_t
name|tx_pkts_freed
decl_stmt|;
name|uint64_t
name|tx_pkts_transmitted
decl_stmt|;
name|uint64_t
name|tx_pkts_completed
decl_stmt|;
name|uint64_t
name|tx_lso_wnd_min_len
decl_stmt|;
name|uint64_t
name|tx_defrag
decl_stmt|;
name|uint64_t
name|tx_nsegs_gt_elem_left
decl_stmt|;
name|uint32_t
name|tx_tso_max_nsegs
decl_stmt|;
name|uint32_t
name|tx_tso_min_nsegs
decl_stmt|;
name|uint32_t
name|tx_tso_max_pkt_len
decl_stmt|;
name|uint32_t
name|tx_tso_min_pkt_len
decl_stmt|;
name|uint64_t
name|tx_pkts
index|[
name|QLNX_FP_MAX_SEGS
index|]
decl_stmt|;
name|uint64_t
name|err_tx_nsegs_gt_elem_left
decl_stmt|;
name|uint64_t
name|err_tx_dmamap_create
decl_stmt|;
name|uint64_t
name|err_tx_defrag_dmamap_load
decl_stmt|;
name|uint64_t
name|err_tx_non_tso_max_seg
decl_stmt|;
name|uint64_t
name|err_tx_dmamap_load
decl_stmt|;
name|uint64_t
name|err_tx_defrag
decl_stmt|;
name|uint64_t
name|err_tx_free_pkt_null
decl_stmt|;
name|uint64_t
name|err_tx_cons_idx_conflict
decl_stmt|;
name|uint64_t
name|lro_cnt_64
decl_stmt|;
name|uint64_t
name|lro_cnt_128
decl_stmt|;
name|uint64_t
name|lro_cnt_256
decl_stmt|;
name|uint64_t
name|lro_cnt_512
decl_stmt|;
name|uint64_t
name|lro_cnt_1024
decl_stmt|;
comment|/* receive statistics */
name|uint64_t
name|rx_pkts
decl_stmt|;
name|uint64_t
name|tpa_start
decl_stmt|;
name|uint64_t
name|tpa_cont
decl_stmt|;
name|uint64_t
name|tpa_end
decl_stmt|;
name|uint64_t
name|err_m_getcl
decl_stmt|;
name|uint64_t
name|err_m_getjcl
decl_stmt|;
name|uint64_t
name|err_rx_hw_errors
decl_stmt|;
name|uint64_t
name|err_rx_alloc_errors
decl_stmt|;
name|uint64_t
name|err_rx_jumbo_chain_pkts
decl_stmt|;
name|uint64_t
name|err_rx_mp_null
decl_stmt|;
name|uint64_t
name|err_rx_tpa_invalid_agg_num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|qlnx_update_vport_params
block|{
name|uint8_t
name|vport_id
decl_stmt|;
name|uint8_t
name|update_vport_active_rx_flg
decl_stmt|;
name|uint8_t
name|vport_active_rx_flg
decl_stmt|;
name|uint8_t
name|update_vport_active_tx_flg
decl_stmt|;
name|uint8_t
name|vport_active_tx_flg
decl_stmt|;
name|uint8_t
name|update_inner_vlan_removal_flg
decl_stmt|;
name|uint8_t
name|inner_vlan_removal_flg
decl_stmt|;
name|struct
name|ecore_rss_params
modifier|*
name|rss_params
decl_stmt|;
name|struct
name|ecore_sge_tpa_params
modifier|*
name|sge_tpa_params
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * link related  */
end_comment

begin_struct
struct|struct
name|qlnx_link_output
block|{
name|bool
name|link_up
decl_stmt|;
name|uint32_t
name|supported_caps
decl_stmt|;
name|uint32_t
name|advertised_caps
decl_stmt|;
name|uint32_t
name|link_partner_caps
decl_stmt|;
name|uint32_t
name|speed
decl_stmt|;
comment|/* In Mb/s */
name|bool
name|autoneg
decl_stmt|;
name|uint32_t
name|media_type
decl_stmt|;
name|uint32_t
name|duplex
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_link_output
name|qlnx_link_output_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QLNX_LINK_DUPLEX
value|0x0001
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_FIBRE
value|0x0001
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_Autoneg
value|0x0002
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_Pause
value|0x0004
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_Asym_Pause
value|0x0008
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_1000baseT_Half
value|0x0010
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_1000baseT_Full
value|0x0020
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_10000baseKR_Full
value|0x0040
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_25000baseKR_Full
value|0x0080
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_40000baseLR4_Full
value|0x0100
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_50000baseKR2_Full
value|0x0200
end_define

begin_define
define|#
directive|define
name|QLNX_LINK_CAP_100000baseKR4_Full
value|0x0400
end_define

begin_comment
comment|/* Functions definition */
end_comment

begin_define
define|#
directive|define
name|XMIT_PLAIN
value|0
end_define

begin_define
define|#
directive|define
name|XMIT_L4_CSUM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|XMIT_LSO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|CQE_FLAGS_ERR
value|(PARSING_AND_ERR_FLAGS_IPHDRERROR_MASK<<       \                          PARSING_AND_ERR_FLAGS_IPHDRERROR_SHIFT |       \                          PARSING_AND_ERR_FLAGS_L4CHKSMERROR_MASK<<     \                          PARSING_AND_ERR_FLAGS_L4CHKSMERROR_SHIFT |     \                          PARSING_AND_ERR_FLAGS_TUNNELIPHDRERROR_MASK<< \                          PARSING_AND_ERR_FLAGS_TUNNELIPHDRERROR_SHIFT | \                          PARSING_AND_ERR_FLAGS_TUNNELL4CHKSMERROR_MASK<< \                          PARSING_AND_ERR_FLAGS_TUNNELL4CHKSMERROR_SHIFT)
end_define

begin_define
define|#
directive|define
name|RX_COPY_THRESH
value|92
end_define

begin_define
define|#
directive|define
name|ETH_MAX_PACKET_SIZE
value|1500
end_define

begin_define
define|#
directive|define
name|QLNX_MFW_VERSION_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|QLNX_STORMFW_VERSION_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|QLNX_TX_ELEM_RESERVE
value|2
end_define

begin_define
define|#
directive|define
name|QLNX_TPA_MAX_AGG_BUFFERS
value|(20)
end_define

begin_define
define|#
directive|define
name|QLNX_MAX_NUM_MULTICAST_ADDRS
value|ECORE_MAX_MC_ADDRS
end_define

begin_typedef
typedef|typedef
struct|struct
name|_qlnx_mcast
block|{
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint8_t
name|addr
index|[
literal|6
index|]
decl_stmt|;
block|}
name|__packed
name|qlnx_mcast_t
typedef|;
end_typedef

begin_comment
comment|/*  * Adapter structure contains the hardware independent information of the  * pci function.  */
end_comment

begin_struct
struct|struct
name|qlnx_host
block|{
comment|/* interface to ecore */
name|struct
name|ecore_dev
name|cdev
decl_stmt|;
name|uint32_t
name|state
decl_stmt|;
comment|/* some flags */
specifier|volatile
struct|struct
block|{
specifier|volatile
name|uint32_t
name|callout_init
range|:
literal|1
decl_stmt|,
name|slowpath_start
range|:
literal|1
decl_stmt|,
name|parent_tag
range|:
literal|1
decl_stmt|,
name|lock_init
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
comment|/* interface to o.s */
name|device_t
name|pci_dev
decl_stmt|;
name|uint8_t
name|pci_func
decl_stmt|;
name|uint8_t
name|dev_unit
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
specifier|volatile
name|int
name|link_up
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
name|struct
name|cdev
modifier|*
name|ioctl_dev
decl_stmt|;
comment|/* resources */
name|struct
name|resource
modifier|*
name|pci_reg
decl_stmt|;
name|int
name|reg_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|pci_dbells
decl_stmt|;
name|int
name|dbells_rid
decl_stmt|;
name|uint64_t
name|dbells_phys_addr
decl_stmt|;
name|uint32_t
name|dbells_size
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix_bar
decl_stmt|;
name|int
name|msix_rid
decl_stmt|;
name|int
name|msix_count
decl_stmt|;
name|struct
name|mtx
name|hw_lock
decl_stmt|;
comment|/* debug */
name|uint32_t
name|dbg_level
decl_stmt|;
name|uint32_t
name|dp_level
decl_stmt|;
name|uint32_t
name|dp_module
decl_stmt|;
comment|/* misc */
name|uint8_t
name|mfw_ver
index|[
name|QLNX_MFW_VERSION_LENGTH
index|]
decl_stmt|;
name|uint8_t
name|stormfw_ver
index|[
name|QLNX_STORMFW_VERSION_LENGTH
index|]
decl_stmt|;
name|uint32_t
name|flash_size
decl_stmt|;
comment|/* dma related */
name|bus_dma_tag_t
name|parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
name|bus_dma_tag_t
name|rx_tag
decl_stmt|;
name|struct
name|ecore_sb_info
name|sb_array
index|[
name|QLNX_MAX_RSS
index|]
decl_stmt|;
name|struct
name|qlnx_rx_queue
name|rxq_array
index|[
name|QLNX_MAX_RSS
index|]
decl_stmt|;
name|struct
name|qlnx_tx_queue
name|txq_array
index|[
operator|(
name|QLNX_MAX_RSS
operator|*
name|MAX_NUM_TC
operator|)
index|]
decl_stmt|;
name|struct
name|qlnx_fastpath
name|fp_array
index|[
name|QLNX_MAX_RSS
index|]
decl_stmt|;
comment|/* tx related */
name|struct
name|callout
name|tx_callout
decl_stmt|;
name|struct
name|mtx
name|tx_lock
decl_stmt|;
name|uint32_t
name|txr_idx
decl_stmt|;
comment|/* rx related */
name|uint32_t
name|rx_pkt_threshold
decl_stmt|;
name|uint32_t
name|rx_jumbo_buf_eq_mtu
decl_stmt|;
comment|/* slow path related */
name|struct
name|resource
modifier|*
name|sp_irq
index|[
name|MAX_HWFNS_PER_DEVICE
index|]
decl_stmt|;
name|void
modifier|*
name|sp_handle
index|[
name|MAX_HWFNS_PER_DEVICE
index|]
decl_stmt|;
name|int
name|sp_irq_rid
index|[
name|MAX_HWFNS_PER_DEVICE
index|]
decl_stmt|;
name|struct
name|task
name|sp_task
index|[
name|MAX_HWFNS_PER_DEVICE
index|]
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|sp_taskqueue
index|[
name|MAX_HWFNS_PER_DEVICE
index|]
decl_stmt|;
name|struct
name|callout
name|qlnx_callout
decl_stmt|;
comment|/* fast path related */
name|int
name|num_rss
decl_stmt|;
name|int
name|num_tc
decl_stmt|;
define|#
directive|define
name|QLNX_MAX_TSS_CNT
parameter_list|(
name|ha
parameter_list|)
value|((ha->num_rss) * (ha->num_tc))
name|qlnx_ivec_t
name|irq_vec
index|[
name|QLNX_MAX_RSS
index|]
decl_stmt|;
name|uint8_t
name|filter
decl_stmt|;
name|uint32_t
name|nmcast
decl_stmt|;
name|qlnx_mcast_t
name|mcast
index|[
name|QLNX_MAX_NUM_MULTICAST_ADDRS
index|]
decl_stmt|;
name|struct
name|ecore_filter_mcast
name|ecore_mcast
decl_stmt|;
name|uint8_t
name|primary_mac
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|uint8_t
name|prio_to_tc
index|[
name|MAX_NUM_PRI
index|]
decl_stmt|;
name|struct
name|ecore_eth_stats
name|hw_stats
decl_stmt|;
name|struct
name|ecore_rss_params
name|rss_params
decl_stmt|;
name|uint32_t
name|rx_buf_size
decl_stmt|;
name|bool
name|rx_csum_offload
decl_stmt|;
name|uint32_t
name|rx_coalesce_usecs
decl_stmt|;
name|uint32_t
name|tx_coalesce_usecs
decl_stmt|;
comment|/* link related */
name|qlnx_link_output_t
name|if_link
decl_stmt|;
comment|/* global counters */
name|uint64_t
name|sp_interrupts
decl_stmt|;
name|uint64_t
name|err_illegal_intr
decl_stmt|;
name|uint64_t
name|err_fp_null
decl_stmt|;
name|uint64_t
name|err_get_proto_invalid_type
decl_stmt|;
comment|/* grcdump related */
name|uint32_t
name|err_inject
decl_stmt|;
name|uint32_t
name|grcdump_taken
decl_stmt|;
name|uint32_t
name|grcdump_dwords
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|uint32_t
name|grcdump_size
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|void
modifier|*
name|grcdump
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|uint32_t
name|idle_chk_taken
decl_stmt|;
name|uint32_t
name|idle_chk_dwords
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|uint32_t
name|idle_chk_size
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
name|void
modifier|*
name|idle_chk
index|[
name|QLNX_MAX_HW_FUNCS
index|]
decl_stmt|;
comment|/* storm stats related */
define|#
directive|define
name|QLNX_STORM_STATS_TOTAL
define|\
value|(QLNX_MAX_HW_FUNCS * QLNX_STORM_STATS_SAMPLES_PER_HWFN)
name|qlnx_storm_stats_t
name|storm_stats
index|[
name|QLNX_STORM_STATS_TOTAL
index|]
decl_stmt|;
name|uint32_t
name|storm_stats_index
decl_stmt|;
name|uint32_t
name|storm_stats_enable
decl_stmt|;
name|uint32_t
name|personality
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qlnx_host
name|qlnx_host_t
typedef|;
end_typedef

begin_comment
comment|/* note that align has to be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|QL_ALIGN
parameter_list|(
name|size
parameter_list|,
name|align
parameter_list|)
value|(size + (align - 1))& ~(align - 1);
end_define

begin_define
define|#
directive|define
name|QL_MIN
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x< y) ? x : y)
end_define

begin_define
define|#
directive|define
name|QL_RUNNING
parameter_list|(
name|ifp
parameter_list|)
define|\
value|((ifp->if_drv_flags& (IFF_DRV_RUNNING | IFF_DRV_OACTIVE)) == \ 			IFF_DRV_RUNNING)
end_define

begin_define
define|#
directive|define
name|QLNX_MAX_MTU
value|9000
end_define

begin_define
define|#
directive|define
name|QLNX_MAX_SEGMENTS_NON_TSO
value|(ETH_TX_MAX_BDS_PER_NON_LSO_PACKET - 1)
end_define

begin_define
define|#
directive|define
name|QLNX_MAX_TSO_FRAME_SIZE
value|((64 * 1024 - 1) + 22)
end_define

begin_define
define|#
directive|define
name|QL_MAC_CMP
parameter_list|(
name|mac1
parameter_list|,
name|mac2
parameter_list|)
define|\
value|((((*(uint32_t *) mac1) == (*(uint32_t *) mac2)&& \         (*(uint16_t *)(mac1 + 4)) == (*(uint16_t *)(mac2 + 4)))) ? 0 : 1)
end_define

begin_define
define|#
directive|define
name|for_each_rss
parameter_list|(
name|i
parameter_list|)
value|for (i = 0; i< ha->num_rss; i++)
end_define

begin_comment
comment|/*  * Debug Related  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|QLNX_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|QL_DPRINT1
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0001) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT2
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0002) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT3
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0004) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT4
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0008) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT5
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0010) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT6
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0020) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT7
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0040) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT8
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0080) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT9
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0100) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT11
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0400) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT12
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x0800) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT13
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x1000) device_printf x
end_define

begin_define
define|#
directive|define
name|QL_DPRINT14
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
value|if (ha->dbg_level& 0x2000) device_printf x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QL_DPRINT1
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT2
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT3
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT4
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT5
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT6
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT7
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT8
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT9
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT11
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT12
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT13
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|QL_DPRINT14
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef QLNX_DEBUG */
end_comment

begin_define
define|#
directive|define
name|QL_ASSERT
parameter_list|(
name|ha
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|if (!x) panic y
end_define

begin_define
define|#
directive|define
name|QL_ERR_INJECT
parameter_list|(
name|ha
parameter_list|,
name|val
parameter_list|)
value|(ha->err_inject == val)
end_define

begin_define
define|#
directive|define
name|QL_RESET_ERR_INJECT
parameter_list|(
name|ha
parameter_list|,
name|val
parameter_list|)
value|{if (ha->err_inject == val) ha->err_inject = 0;}
end_define

begin_define
define|#
directive|define
name|QL_ERR_INJCT_TX_INT_DIFF
value|0x0001
end_define

begin_define
define|#
directive|define
name|QL_ERR_INJCT_TX_INT_MBUF_NULL
value|0x0002
end_define

begin_comment
comment|/*  * exported functions  */
end_comment

begin_function_decl
specifier|extern
name|int
name|qlnx_make_cdev
parameter_list|(
name|qlnx_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_del_cdev
parameter_list|(
name|qlnx_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qlnx_grc_dump
parameter_list|(
name|qlnx_host_t
modifier|*
name|ha
parameter_list|,
name|uint32_t
modifier|*
name|num_dumped_dwords
parameter_list|,
name|int
name|hwfn_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|qlnx_idle_chk
parameter_list|(
name|qlnx_host_t
modifier|*
name|ha
parameter_list|,
name|uint32_t
modifier|*
name|num_dumped_dwords
parameter_list|,
name|int
name|hwfn_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
modifier|*
name|qlnx_get_mac_addr
parameter_list|(
name|qlnx_host_t
modifier|*
name|ha
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|qlnx_fill_link
parameter_list|(
name|struct
name|ecore_hwfn
modifier|*
name|hwfn
parameter_list|,
name|struct
name|qlnx_link_output
modifier|*
name|if_link
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Some OS specific stuff  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
name|IFM_100G_SR4
operator|)
end_if

begin_define
define|#
directive|define
name|QLNX_IFM_100G_SR4
value|IFM_100G_SR4
end_define

begin_define
define|#
directive|define
name|QLNX_IFM_100G_LR4
value|IFM_100G_LR4
end_define

begin_define
define|#
directive|define
name|QLNX_IFM_100G_CR4
value|IFM_100G_CR4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QLNX_IFM_100G_SR4
value|IFM_UNKNOWN
end_define

begin_define
define|#
directive|define
name|QLNX_IFM_100G_LR4
value|IFM_UNKNOWN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
name|IFM_25G_SR
operator|)
end_if

begin_define
define|#
directive|define
name|QLNX_IFM_25G_SR
value|IFM_25G_SR
end_define

begin_define
define|#
directive|define
name|QLNX_IFM_25G_CR
value|IFM_25G_CR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QLNX_IFM_25G_SR
value|IFM_UNKNOWN
end_define

begin_define
define|#
directive|define
name|QLNX_IFM_25G_CR
value|IFM_UNKNOWN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|1100000
end_if

begin_define
define|#
directive|define
name|QLNX_INC_IERRORS
parameter_list|(
name|ifp
parameter_list|)
value|ifp->if_ierrors++
end_define

begin_define
define|#
directive|define
name|QLNX_INC_IQDROPS
parameter_list|(
name|ifp
parameter_list|)
value|ifp->if_iqdrops++
end_define

begin_define
define|#
directive|define
name|QLNX_INC_IPACKETS
parameter_list|(
name|ifp
parameter_list|)
value|ifp->if_ipackets++
end_define

begin_define
define|#
directive|define
name|QLNX_INC_OPACKETS
parameter_list|(
name|ifp
parameter_list|)
value|ifp->if_opackets++
end_define

begin_define
define|#
directive|define
name|QLNX_INC_OBYTES
parameter_list|(
name|ifp
parameter_list|,
name|len
parameter_list|)
value|ifp->if_obytes += len
end_define

begin_define
define|#
directive|define
name|QLNX_INC_IBYTES
parameter_list|(
name|ifp
parameter_list|,
name|len
parameter_list|)
value|ifp->if_ibytes += len
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|QLNX_INC_IERRORS
parameter_list|(
name|ifp
parameter_list|)
value|if_inc_counter(ifp, IFCOUNTER_IERRORS, 1)
end_define

begin_define
define|#
directive|define
name|QLNX_INC_IQDROPS
parameter_list|(
name|ifp
parameter_list|)
value|if_inc_counter(ifp, IFCOUNTER_IQDROPS, 1)
end_define

begin_define
define|#
directive|define
name|QLNX_INC_IPACKETS
parameter_list|(
name|ifp
parameter_list|)
value|if_inc_counter(ifp, IFCOUNTER_IPACKETS, 1)
end_define

begin_define
define|#
directive|define
name|QLNX_INC_OPACKETS
parameter_list|(
name|ifp
parameter_list|)
value|if_inc_counter(ifp, IFCOUNTER_OPACKETS, 1)
end_define

begin_define
define|#
directive|define
name|QLNX_INC_OBYTES
parameter_list|(
name|ifp
parameter_list|,
name|len
parameter_list|)
define|\
value|if_inc_counter(ifp, IFCOUNTER_OBYTES, len)
end_define

begin_define
define|#
directive|define
name|QLNX_INC_IBYTES
parameter_list|(
name|ifp
parameter_list|,
name|len
parameter_list|)
define|\
value|if_inc_counter(ha->ifp, IFCOUNTER_IBYTES, len)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #if __FreeBSD_version< 1100000 */
end_comment

begin_define
define|#
directive|define
name|CQE_L3_PACKET
parameter_list|(
name|flags
parameter_list|)
define|\
value|((((flags)& PARSING_AND_ERR_FLAGS_L3TYPE_MASK) == e_l3Type_ipv4) || \         (((flags)& PARSING_AND_ERR_FLAGS_L3TYPE_MASK) == e_l3Type_ipv6))
end_define

begin_define
define|#
directive|define
name|CQE_IP_HDR_ERR
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags)& (PARSING_AND_ERR_FLAGS_IPHDRERROR_MASK \<< PARSING_AND_ERR_FLAGS_IPHDRERROR_SHIFT))
end_define

begin_define
define|#
directive|define
name|CQE_L4_HAS_CSUM
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags)& (PARSING_AND_ERR_FLAGS_L4CHKSMWASCALCULATED_MASK \<< PARSING_AND_ERR_FLAGS_L4CHKSMWASCALCULATED_SHIFT))
end_define

begin_define
define|#
directive|define
name|CQE_HAS_VLAN
parameter_list|(
name|flags
parameter_list|)
define|\
value|((flags)& (PARSING_AND_ERR_FLAGS_TAG8021QEXIST_MASK \<< PARSING_AND_ERR_FLAGS_TAG8021QEXIST_SHIFT))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLNX_DEF_H_ */
end_comment

end_unit

