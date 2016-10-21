begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015,2016 Annapurna Labs Ltd. and affiliates  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_ETH_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_ETH_H__
end_define

begin_include
include|#
directive|include
file|"al_init_eth_lm.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_eth.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_udma_iofic.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_udma_debug.h"
end_include

begin_include
include|#
directive|include
file|"al_serdes.h"
end_include

begin_enum
enum|enum
name|board_t
block|{
name|ALPINE_INTEGRATED
init|=
literal|0
block|,
name|ALPINE_NIC
init|=
literal|1
block|,
name|ALPINE_FPGA_NIC
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|AL_ETH_MAX_HW_QUEUES
value|4
end_define

begin_define
define|#
directive|define
name|AL_ETH_NUM_QUEUES
value|4
end_define

begin_define
define|#
directive|define
name|AL_ETH_MAX_MSIX_VEC
value|(1 + 2 * AL_ETH_MAX_HW_QUEUES)
end_define

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_TX_SW_DESCS
value|(512)
end_define

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_TX_HW_DESCS
value|(512)
end_define

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_RX_DESCS
value|(512)
end_define

begin_if
if|#
directive|if
operator|(
operator|(
name|AL_ETH_DEFAULT_TX_SW_DESCS
operator|/
literal|4
operator|)
operator|<
operator|(
name|AL_ETH_PKT_MAX_BUFS
operator|+
literal|2
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|AL_ETH_TX_WAKEUP_THRESH
value|(AL_ETH_DEFAULT_TX_SW_DESCS / 4)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AL_ETH_TX_WAKEUP_THRESH
value|(AL_ETH_PKT_MAX_BUFS + 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NET_IP_ALIGN
value|2
end_define

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_SMALL_PACKET_LEN
value|(128 - NET_IP_ALIGN)
end_define

begin_define
define|#
directive|define
name|AL_ETH_HEADER_COPY_SIZE
value|(128 - NET_IP_ALIGN)
end_define

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_MAX_RX_BUFF_ALLOC_SIZE
value|9216
end_define

begin_comment
comment|/*  * Minimum the buffer size to 600 to avoid situation the mtu will be changed  * from too little buffer to very big one and then the number of buffer per  * packet could reach the maximum AL_ETH_PKT_MAX_BUFS  */
end_comment

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_MIN_RX_BUFF_ALLOC_SIZE
value|600
end_define

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_FORCE_1000_BASEX
value|FALSE
end_define

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_LINK_POLL_INTERVAL
value|100
end_define

begin_define
define|#
directive|define
name|AL_ETH_FIRST_LINK_POLL_INTERVAL
value|1
end_define

begin_define
define|#
directive|define
name|AL_ETH_NAME_MAX_LEN
value|20
end_define

begin_define
define|#
directive|define
name|AL_ETH_IRQNAME_SIZE
value|40
end_define

begin_define
define|#
directive|define
name|AL_ETH_DEFAULT_MDIO_FREQ_KHZ
value|2500
end_define

begin_define
define|#
directive|define
name|AL_ETH_MDIO_FREQ_1000_KHZ
value|1000
end_define

begin_struct
struct|struct
name|al_eth_irq
block|{
name|driver_filter_t
modifier|*
name|handler
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
name|unsigned
name|int
name|vector
decl_stmt|;
name|uint8_t
name|requested
decl_stmt|;
name|char
name|name
index|[
name|AL_ETH_IRQNAME_SIZE
index|]
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|void
modifier|*
name|cookie
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_eth_tx_buffer
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|al_eth_pkt
name|hal_pkt
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|unsigned
name|int
name|tx_descs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_eth_rx_buffer
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|unsigned
name|int
name|data_size
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|struct
name|al_buf
name|al_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_eth_ring
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|al_eth_adapter
modifier|*
name|adapter
decl_stmt|;
comment|/* Used to get rx packets from hal */
name|struct
name|al_eth_pkt
name|hal_pkt
decl_stmt|;
comment|/* Udma queue handler */
name|struct
name|al_udma_q
modifier|*
name|dma_q
decl_stmt|;
name|uint32_t
name|ring_id
decl_stmt|;
name|uint16_t
name|next_to_use
decl_stmt|;
name|uint16_t
name|next_to_clean
decl_stmt|;
comment|/* The offset of the interrupt unmask register */
name|uint32_t
modifier|*
name|unmask_reg_offset
decl_stmt|;
comment|/*  	 * The value to write to the above register to 	 * unmask the interrupt of this ring 	 */
name|uint32_t
name|unmask_val
decl_stmt|;
name|struct
name|al_eth_meta_data
name|hal_meta
decl_stmt|;
comment|/* Contex of tx packet */
name|struct
name|al_eth_tx_buffer
modifier|*
name|tx_buffer_info
decl_stmt|;
comment|/* Contex of rx packet */
name|struct
name|al_eth_rx_buffer
modifier|*
name|rx_buffer_info
decl_stmt|;
comment|/* Number of tx/rx_buffer_info's entries */
name|int
name|sw_count
decl_stmt|;
comment|/* Number of hw descriptors */
name|int
name|hw_count
decl_stmt|;
comment|/* Size (in bytes) of hw descriptors */
name|size_t
name|descs_size
decl_stmt|;
comment|/* Size (in bytes) of hw completion descriptors, used for rx */
name|size_t
name|cdescs_size
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|netdev
decl_stmt|;
name|struct
name|al_udma_q_params
name|q_params
decl_stmt|;
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
name|struct
name|mtx
name|br_mtx
decl_stmt|;
name|struct
name|task
name|enqueue_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|enqueue_tq
decl_stmt|;
specifier|volatile
name|uint32_t
name|enqueue_is_running
decl_stmt|;
name|struct
name|task
name|cmpl_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|cmpl_tq
decl_stmt|;
specifier|volatile
name|uint32_t
name|cmpl_is_running
decl_stmt|;
name|uint32_t
name|lro_enabled
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|bus_dma_tag_t
name|dma_buf_tag
decl_stmt|;
specifier|volatile
name|uint32_t
name|stall
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AL_ETH_TX_RING_IDX_NEXT
parameter_list|(
name|tx_ring
parameter_list|,
name|idx
parameter_list|)
value|(((idx) + 1)& (AL_ETH_DEFAULT_TX_SW_DESCS - 1))
end_define

begin_define
define|#
directive|define
name|AL_ETH_RX_RING_IDX_NEXT
parameter_list|(
name|rx_ring
parameter_list|,
name|idx
parameter_list|)
value|(((idx) + 1)& (AL_ETH_DEFAULT_RX_DESCS - 1))
end_define

begin_define
define|#
directive|define
name|AL_ETH_RX_RING_IDX_ADD
parameter_list|(
name|rx_ring
parameter_list|,
name|idx
parameter_list|,
name|n
parameter_list|)
value|(((idx) + (n))& (AL_ETH_DEFAULT_RX_DESCS - 1))
end_define

begin_comment
comment|/* flow control configuration */
end_comment

begin_define
define|#
directive|define
name|AL_ETH_FLOW_CTRL_RX_FIFO_TH_HIGH
value|0x160
end_define

begin_define
define|#
directive|define
name|AL_ETH_FLOW_CTRL_RX_FIFO_TH_LOW
value|0x90
end_define

begin_define
define|#
directive|define
name|AL_ETH_FLOW_CTRL_QUANTA
value|0xffff
end_define

begin_define
define|#
directive|define
name|AL_ETH_FLOW_CTRL_QUANTA_TH
value|0x8000
end_define

begin_define
define|#
directive|define
name|AL_ETH_FLOW_CTRL_AUTONEG
value|1
end_define

begin_define
define|#
directive|define
name|AL_ETH_FLOW_CTRL_RX_PAUSE
value|2
end_define

begin_define
define|#
directive|define
name|AL_ETH_FLOW_CTRL_TX_PAUSE
value|4
end_define

begin_comment
comment|/* link configuration for 1G port */
end_comment

begin_struct
struct|struct
name|al_eth_link_config
block|{
name|int
name|old_link
decl_stmt|;
comment|/* Describes what we actually have. */
name|int
name|active_duplex
decl_stmt|;
name|int
name|active_speed
decl_stmt|;
comment|/* current flow control status */
name|uint8_t
name|flow_ctrl_active
decl_stmt|;
comment|/* supported configuration (can be changed from ethtool) */
name|uint8_t
name|flow_ctrl_supported
decl_stmt|;
comment|/* the following are not relevant to RGMII */
name|boolean_t
name|force_1000_base_x
decl_stmt|;
name|boolean_t
name|autoneg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SFP detection event */
end_comment

begin_enum
enum|enum
name|al_eth_sfp_detect_evt
block|{
comment|/* No change (no connect, disconnect, or new SFP module */
name|AL_ETH_SFP_DETECT_EVT_NO_CHANGE
block|,
comment|/* SFP module connected */
name|AL_ETH_SFP_DETECT_EVT_CONNECTED
block|,
comment|/* SFP module disconnected */
name|AL_ETH_SFP_DETECT_EVT_DISCONNECTED
block|,
comment|/* SFP module replaced */
name|AL_ETH_SFP_DETECT_EVT_CHANGED
block|, }
enum|;
end_enum

begin_comment
comment|/* SFP detection status */
end_comment

begin_struct
struct|struct
name|al_eth_sfp_detect_stat
block|{
comment|/* Status is valid (i.e. rest of fields are valid) */
name|boolean_t
name|valid
decl_stmt|;
name|boolean_t
name|connected
decl_stmt|;
name|uint8_t
name|sfp_10g
decl_stmt|;
name|uint8_t
name|sfp_1g
decl_stmt|;
name|uint8_t
name|sfp_cable_tech
decl_stmt|;
name|boolean_t
name|lt_en
decl_stmt|;
name|boolean_t
name|an_en
decl_stmt|;
name|enum
name|al_eth_mac_mode
name|mac_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|al_eth_retimer_params
block|{
name|boolean_t
name|exist
decl_stmt|;
name|uint8_t
name|bus_id
decl_stmt|;
name|uint8_t
name|i2c_addr
decl_stmt|;
name|enum
name|al_eth_retimer_channel
name|channel
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|msix_entry
block|{
name|int
name|entry
decl_stmt|;
name|int
name|vector
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* board specific private data structure */
end_comment

begin_struct
struct|struct
name|al_eth_adapter
block|{
name|enum
name|board_t
name|board_type
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|mii
decl_stmt|;
name|uint16_t
name|dev_id
decl_stmt|;
name|uint8_t
name|rev_id
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|netdev
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|struct
name|resource
modifier|*
name|udma_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|mac_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|ec_res
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|callout
name|wd_callout
decl_stmt|;
name|struct
name|mtx
name|wd_mtx
decl_stmt|;
name|struct
name|callout
name|stats_callout
decl_stmt|;
name|struct
name|mtx
name|stats_mtx
decl_stmt|;
comment|/* this is for intx mode */
name|void
modifier|*
name|irq_cookie
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/*  	 * Some features need tri-state capability, 	 * thus the additional *_CAPABLE flags. 	 */
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|AL_ETH_FLAG_MSIX_CAPABLE
value|(uint32_t)(1<< 1)
define|#
directive|define
name|AL_ETH_FLAG_MSIX_ENABLED
value|(uint32_t)(1<< 2)
define|#
directive|define
name|AL_ETH_FLAG_IN_NETPOLL
value|(uint32_t)(1<< 3)
define|#
directive|define
name|AL_ETH_FLAG_MQ_CAPABLE
value|(uint32_t)(1<< 4)
define|#
directive|define
name|AL_ETH_FLAG_SRIOV_CAPABLE
value|(uint32_t)(1<< 5)
define|#
directive|define
name|AL_ETH_FLAG_SRIOV_ENABLED
value|(uint32_t)(1<< 6)
define|#
directive|define
name|AL_ETH_FLAG_RESET_REQUESTED
value|(uint32_t)(1<< 7)
name|struct
name|al_hal_eth_adapter
name|hal_adapter
decl_stmt|;
comment|/* 	 * Rx packets that shorter that this len will be copied to the mbuf  	 */
name|unsigned
name|int
name|small_copy_len
decl_stmt|;
comment|/* Maximum size for rx buffer */
name|unsigned
name|int
name|max_rx_buff_alloc_size
decl_stmt|;
name|uint32_t
name|rx_mbuf_sz
decl_stmt|;
comment|/* Tx fast path data */
name|int
name|num_tx_queues
decl_stmt|;
comment|/* Rx fast path data */
name|int
name|num_rx_queues
decl_stmt|;
comment|/* TX */
name|struct
name|al_eth_ring
name|tx_ring
index|[
name|AL_ETH_NUM_QUEUES
index|]
decl_stmt|;
comment|/* RX */
name|struct
name|al_eth_ring
name|rx_ring
index|[
name|AL_ETH_NUM_QUEUES
index|]
decl_stmt|;
name|enum
name|al_iofic_mode
name|int_mode
decl_stmt|;
define|#
directive|define
name|AL_ETH_MGMT_IRQ_IDX
value|0
define|#
directive|define
name|AL_ETH_RXQ_IRQ_IDX
parameter_list|(
name|adapter
parameter_list|,
name|q
parameter_list|)
value|(1 + (q))
define|#
directive|define
name|AL_ETH_TXQ_IRQ_IDX
parameter_list|(
name|adapter
parameter_list|,
name|q
parameter_list|)
value|(1 + (adapter)->num_rx_queues + (q))
name|struct
name|al_eth_irq
name|irq_tbl
index|[
name|AL_ETH_MAX_MSIX_VEC
index|]
decl_stmt|;
name|struct
name|msix_entry
modifier|*
name|msix_entries
decl_stmt|;
name|int
name|msix_vecs
decl_stmt|;
name|int
name|irq_vecs
decl_stmt|;
name|unsigned
name|int
name|tx_usecs
decl_stmt|,
name|rx_usecs
decl_stmt|;
comment|/* interrupt coalescing */
name|unsigned
name|int
name|tx_ring_count
decl_stmt|;
name|unsigned
name|int
name|tx_descs_count
decl_stmt|;
name|unsigned
name|int
name|rx_ring_count
decl_stmt|;
name|unsigned
name|int
name|rx_descs_count
decl_stmt|;
comment|/* RSS */
name|uint32_t
name|toeplitz_hash_key
index|[
name|AL_ETH_RX_HASH_KEY_NUM
index|]
decl_stmt|;
define|#
directive|define
name|AL_ETH_RX_RSS_TABLE_SIZE
value|AL_ETH_RX_THASH_TABLE_SIZE
name|uint8_t
name|rss_ind_tbl
index|[
name|AL_ETH_RX_RSS_TABLE_SIZE
index|]
decl_stmt|;
name|uint32_t
name|msg_enable
decl_stmt|;
name|struct
name|al_eth_mac_stats
name|mac_stats
decl_stmt|;
name|enum
name|al_eth_mac_mode
name|mac_mode
decl_stmt|;
name|boolean_t
name|mac_mode_set
decl_stmt|;
comment|/* Relevant only when 'auto_speed' is set */
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* mdio and phy*/
name|boolean_t
name|phy_exist
decl_stmt|;
name|struct
name|mii_bus
modifier|*
name|mdio_bus
decl_stmt|;
name|struct
name|phy_device
modifier|*
name|phydev
decl_stmt|;
name|uint8_t
name|phy_addr
decl_stmt|;
name|struct
name|al_eth_link_config
name|link_config
decl_stmt|;
comment|/* HAL layer data */
name|int
name|id_number
decl_stmt|;
name|char
name|name
index|[
name|AL_ETH_NAME_MAX_LEN
index|]
decl_stmt|;
name|void
modifier|*
name|internal_pcie_base
decl_stmt|;
comment|/* use for ALPINE_NIC devices */
name|void
modifier|*
name|udma_base
decl_stmt|;
name|void
modifier|*
name|ec_base
decl_stmt|;
name|void
modifier|*
name|mac_base
decl_stmt|;
name|struct
name|al_eth_flow_control_params
name|flow_ctrl_params
decl_stmt|;
name|struct
name|al_eth_adapter_params
name|eth_hal_params
decl_stmt|;
name|struct
name|task
name|link_status_task
decl_stmt|;
name|uint32_t
name|link_poll_interval
decl_stmt|;
comment|/* task interval in mSec */
name|boolean_t
name|serdes_init
decl_stmt|;
name|struct
name|al_serdes_grp_obj
name|serdes_obj
decl_stmt|;
name|uint8_t
name|serdes_grp
decl_stmt|;
name|uint8_t
name|serdes_lane
decl_stmt|;
name|boolean_t
name|an_en
decl_stmt|;
comment|/* run kr auto-negotiation */
name|boolean_t
name|lt_en
decl_stmt|;
comment|/* run kr link-training */
name|boolean_t
name|sfp_detection_needed
decl_stmt|;
comment|/* true if need to run sfp detection */
name|boolean_t
name|auto_speed
decl_stmt|;
comment|/* true if allowed to change SerDes speed configuration */
name|uint8_t
name|i2c_adapter_id
decl_stmt|;
comment|/* identifier for the i2c adapter to use to access SFP+ module */
name|enum
name|al_eth_ref_clk_freq
name|ref_clk_freq
decl_stmt|;
comment|/* reference clock frequency */
name|unsigned
name|int
name|mdio_freq
decl_stmt|;
comment|/* MDIO frequency [Khz] */
name|boolean_t
name|up
decl_stmt|;
name|boolean_t
name|last_link
decl_stmt|;
name|boolean_t
name|last_establish_failed
decl_stmt|;
name|struct
name|al_eth_lm_context
name|lm_context
decl_stmt|;
name|boolean_t
name|use_lm
decl_stmt|;
name|boolean_t
name|dont_override_serdes
decl_stmt|;
comment|/* avoid overriding serdes parameters 								   to preset static values */
name|struct
name|mtx
name|serdes_config_lock
decl_stmt|;
name|struct
name|mtx
name|if_rx_lock
decl_stmt|;
name|uint32_t
name|wol
decl_stmt|;
name|struct
name|al_eth_retimer_params
name|retimer
decl_stmt|;
name|bool
name|phy_fixup_needed
decl_stmt|;
name|enum
name|al_eth_lm_max_speed
name|max_speed
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(AL_ETH_H) */
end_comment

end_unit

