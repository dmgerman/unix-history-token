begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2014 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: qls_def.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLS_DEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLS_DEF_H_
end_define

begin_comment
comment|/*  * structure encapsulating a DMA buffer  */
end_comment

begin_struct
struct|struct
name|qla_dma
block|{
name|bus_size_t
name|alignment
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|void
modifier|*
name|dma_b
decl_stmt|;
name|bus_addr_t
name|dma_addr
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_dma
name|qla_dma_t
typedef|;
end_typedef

begin_comment
comment|/*  * structure encapsulating interrupt vectors  */
end_comment

begin_struct
struct|struct
name|qla_ivec
block|{
name|uint32_t
name|cq_idx
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
name|qla_ivec
name|qla_ivec_t
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit Related Definitions  */
end_comment

begin_define
define|#
directive|define
name|MAX_TX_RINGS
value|1
end_define

begin_define
define|#
directive|define
name|NUM_TX_DESCRIPTORS
value|1024
end_define

begin_define
define|#
directive|define
name|QLA_MAX_SEGMENTS
value|64
end_define

begin_comment
comment|/* maximum # of segs in a sg list */
end_comment

begin_define
define|#
directive|define
name|QLA_OAL_BLK_SIZE
value|(sizeof (q81_txb_desc_t) * QLA_MAX_SEGMENTS)
end_define

begin_define
define|#
directive|define
name|QLA_TX_OALB_TOTAL_SIZE
value|(NUM_TX_DESCRIPTORS * QLA_OAL_BLK_SIZE)
end_define

begin_define
define|#
directive|define
name|QLA_TX_PRIVATE_BSIZE
value|((QLA_TX_OALB_TOTAL_SIZE + \ 					PAGE_SIZE + \ 					(PAGE_SIZE - 1))& ~(PAGE_SIZE - 1))
end_define

begin_define
define|#
directive|define
name|QLA_MAX_MTU
value|9000
end_define

begin_define
define|#
directive|define
name|QLA_STD_FRAME_SIZE
value|1514
end_define

begin_define
define|#
directive|define
name|QLA_MAX_TSO_FRAME_SIZE
value|((64 * 1024 - 1) + 22)
end_define

begin_define
define|#
directive|define
name|QL_FRAME_HDR_SIZE
value|(ETHER_HDR_LEN + ETHER_VLAN_ENCAP_LEN +\                 sizeof (struct ip6_hdr) + sizeof (struct tcphdr) + 16)
end_define

begin_struct
struct|struct
name|qla_tx_buf
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* The number of entries in the OAL is determined by QLA_MAX_SEGMENTS */
name|bus_addr_t
name|oal_paddr
decl_stmt|;
name|void
modifier|*
name|oal_vaddr
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_tx_buf
name|qla_tx_buf_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_tx_ring
block|{
specifier|volatile
struct|struct
block|{
name|uint32_t
name|wq_dma
range|:
literal|1
decl_stmt|,
name|privb_dma
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
name|qla_dma_t
name|privb_dma
decl_stmt|;
name|qla_dma_t
name|wq_dma
decl_stmt|;
name|qla_tx_buf_t
name|tx_buf
index|[
name|NUM_TX_DESCRIPTORS
index|]
decl_stmt|;
name|uint64_t
name|count
decl_stmt|;
name|struct
name|resource
modifier|*
name|wq_db_addr
decl_stmt|;
name|uint32_t
name|wq_db_offset
decl_stmt|;
name|q81_tx_cmd_t
modifier|*
name|wq_vaddr
decl_stmt|;
name|bus_addr_t
name|wq_paddr
decl_stmt|;
name|void
modifier|*
name|wq_icb_vaddr
decl_stmt|;
name|bus_addr_t
name|wq_icb_paddr
decl_stmt|;
name|uint32_t
modifier|*
name|txr_cons_vaddr
decl_stmt|;
name|bus_addr_t
name|txr_cons_paddr
decl_stmt|;
specifier|volatile
name|uint32_t
name|txr_free
decl_stmt|;
comment|/* # of free entries in tx ring */
specifier|volatile
name|uint32_t
name|txr_next
decl_stmt|;
comment|/* # next available tx ring entry */
specifier|volatile
name|uint32_t
name|txr_done
decl_stmt|;
name|uint64_t
name|tx_frames
decl_stmt|;
name|uint64_t
name|tx_tso_frames
decl_stmt|;
name|uint64_t
name|tx_vlan_frames
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_tx_ring
name|qla_tx_ring_t
typedef|;
end_typedef

begin_comment
comment|/*  * Receive Related Definitions  */
end_comment

begin_define
define|#
directive|define
name|MAX_RX_RINGS
value|MAX_TX_RINGS
end_define

begin_define
define|#
directive|define
name|NUM_RX_DESCRIPTORS
value|1024
end_define

begin_define
define|#
directive|define
name|NUM_CQ_ENTRIES
value|NUM_RX_DESCRIPTORS
end_define

begin_define
define|#
directive|define
name|QLA_LGB_SIZE
value|(12 * 1024)
end_define

begin_define
define|#
directive|define
name|QLA_NUM_LGB_ENTRIES
value|32
end_define

begin_define
define|#
directive|define
name|QLA_LBQ_SIZE
value|(QLA_NUM_LGB_ENTRIES * sizeof(q81_bq_addr_e_t))
end_define

begin_define
define|#
directive|define
name|QLA_LGBQ_AND_TABLE_SIZE
define|\
value|((QLA_LBQ_SIZE + PAGE_SIZE + (PAGE_SIZE - 1))& ~(PAGE_SIZE - 1))
end_define

begin_comment
comment|/* Please note that Small Buffer size is determined by max mtu size */
end_comment

begin_define
define|#
directive|define
name|QLA_NUM_SMB_ENTRIES
value|NUM_RX_DESCRIPTORS
end_define

begin_define
define|#
directive|define
name|QLA_SBQ_SIZE
value|(QLA_NUM_SMB_ENTRIES * sizeof(q81_bq_addr_e_t))
end_define

begin_define
define|#
directive|define
name|QLA_SMBQ_AND_TABLE_SIZE
define|\
value|((QLA_SBQ_SIZE + PAGE_SIZE + (PAGE_SIZE - 1))& ~(PAGE_SIZE - 1))
end_define

begin_struct
struct|struct
name|qla_rx_buf
block|{
name|struct
name|mbuf
modifier|*
name|m_head
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_addr_t
name|paddr
decl_stmt|;
name|void
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_rx_buf
name|qla_rx_buf_t
typedef|;
end_typedef

begin_struct
struct|struct
name|qla_rx_ring
block|{
specifier|volatile
struct|struct
block|{
name|uint32_t
name|cq_dma
range|:
literal|1
decl_stmt|,
name|lbq_dma
range|:
literal|1
decl_stmt|,
name|sbq_dma
range|:
literal|1
decl_stmt|,
name|lb_dma
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
name|qla_dma_t
name|cq_dma
decl_stmt|;
name|qla_dma_t
name|lbq_dma
decl_stmt|;
name|qla_dma_t
name|sbq_dma
decl_stmt|;
name|qla_dma_t
name|lb_dma
decl_stmt|;
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|qla_rx_buf_t
name|rx_buf
index|[
name|NUM_RX_DESCRIPTORS
index|]
decl_stmt|;
name|qla_rx_buf_t
modifier|*
name|rxb_free
decl_stmt|;
name|uint32_t
name|rx_free
decl_stmt|;
name|uint32_t
name|rx_next
decl_stmt|;
name|uint32_t
name|cq_db_offset
decl_stmt|;
name|void
modifier|*
name|cq_icb_vaddr
decl_stmt|;
name|bus_addr_t
name|cq_icb_paddr
decl_stmt|;
name|uint32_t
modifier|*
name|cqi_vaddr
decl_stmt|;
name|bus_addr_t
name|cqi_paddr
decl_stmt|;
name|void
modifier|*
name|cq_base_vaddr
decl_stmt|;
name|bus_addr_t
name|cq_base_paddr
decl_stmt|;
name|uint32_t
name|cq_next
decl_stmt|;
comment|/* next cq entry to process */
name|void
modifier|*
name|lbq_addr_tbl_vaddr
decl_stmt|;
name|bus_addr_t
name|lbq_addr_tbl_paddr
decl_stmt|;
name|void
modifier|*
name|lbq_vaddr
decl_stmt|;
name|bus_addr_t
name|lbq_paddr
decl_stmt|;
name|uint32_t
name|lbq_next
decl_stmt|;
comment|/* next entry in LBQ to process */
name|uint32_t
name|lbq_free
decl_stmt|;
comment|/* # of entries in LBQ to arm */
name|uint32_t
name|lbq_in
decl_stmt|;
comment|/* next entry in LBQ to arm */
name|void
modifier|*
name|lb_vaddr
decl_stmt|;
name|bus_addr_t
name|lb_paddr
decl_stmt|;
name|void
modifier|*
name|sbq_addr_tbl_vaddr
decl_stmt|;
name|bus_addr_t
name|sbq_addr_tbl_paddr
decl_stmt|;
name|void
modifier|*
name|sbq_vaddr
decl_stmt|;
name|bus_addr_t
name|sbq_paddr
decl_stmt|;
name|uint32_t
name|sbq_next
decl_stmt|;
comment|/* next entry in SBQ to process */
name|uint32_t
name|sbq_free
decl_stmt|;
comment|/* # of entries in SBQ to arm */
name|uint32_t
name|sbq_in
decl_stmt|;
comment|/* next entry in SBQ to arm */
name|uint64_t
name|rx_int
decl_stmt|;
name|uint64_t
name|rss_int
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_rx_ring
name|qla_rx_ring_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QLA_WATCHDOG_CALLOUT_TICKS
value|1
end_define

begin_comment
comment|/*  * Multicast Definitions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_qla_mcast
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
name|qla_mcast_t
typedef|;
end_typedef

begin_comment
comment|/*  * Misc. definitions  */
end_comment

begin_define
define|#
directive|define
name|QLA_PAGE_SIZE
value|4096
end_define

begin_comment
comment|/*  * Adapter structure contains the hardware independent information of the  * pci function.  */
end_comment

begin_struct
struct|struct
name|qla_host
block|{
specifier|volatile
struct|struct
block|{
specifier|volatile
name|uint32_t
name|mpi_dma
range|:
literal|1
decl_stmt|,
name|rss_dma
range|:
literal|1
decl_stmt|,
name|intr_enable
range|:
literal|1
decl_stmt|,
name|qla_callout_init
range|:
literal|1
decl_stmt|,
name|qla_watchdog_active
range|:
literal|1
decl_stmt|,
name|qla_watchdog_exit
range|:
literal|1
decl_stmt|,
name|qla_watchdog_pause
range|:
literal|1
decl_stmt|,
name|lro_init
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
specifier|volatile
name|uint32_t
name|hw_init
decl_stmt|;
specifier|volatile
name|uint32_t
name|qla_watchdog_exited
decl_stmt|;
specifier|volatile
name|uint32_t
name|qla_watchdog_paused
decl_stmt|;
specifier|volatile
name|uint32_t
name|qla_initiate_recovery
decl_stmt|;
name|device_t
name|pci_dev
decl_stmt|;
name|uint8_t
name|pci_func
decl_stmt|;
name|uint16_t
name|watchdog_ticks
decl_stmt|;
name|uint8_t
name|resvd
decl_stmt|;
comment|/* ioctl related */
name|struct
name|cdev
modifier|*
name|ioctl_dev
decl_stmt|;
comment|/* register mapping */
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
name|pci_reg1
decl_stmt|;
name|int
name|reg_rid1
decl_stmt|;
name|int
name|msix_count
decl_stmt|;
name|qla_ivec_t
name|irq_vec
index|[
name|MAX_RX_RINGS
index|]
decl_stmt|;
comment|/* parent dma tag */
name|bus_dma_tag_t
name|parent_tag
decl_stmt|;
comment|/* interface to o.s */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|uint16_t
name|max_frame_size
decl_stmt|;
name|uint16_t
name|rsrvd0
decl_stmt|;
name|uint32_t
name|msize
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
comment|/* hardware access lock */
name|struct
name|mtx
name|hw_lock
decl_stmt|;
specifier|volatile
name|uint32_t
name|hw_lock_held
decl_stmt|;
name|uint32_t
name|vm_pgsize
decl_stmt|;
comment|/* transmit related */
name|uint32_t
name|num_tx_rings
decl_stmt|;
name|qla_tx_ring_t
name|tx_ring
index|[
name|MAX_TX_RINGS
index|]
decl_stmt|;
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
name|struct
name|task
name|tx_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tx_tq
decl_stmt|;
name|struct
name|callout
name|tx_callout
decl_stmt|;
name|struct
name|mtx
name|tx_lock
decl_stmt|;
comment|/* receive related */
name|uint32_t
name|num_rx_rings
decl_stmt|;
name|qla_rx_ring_t
name|rx_ring
index|[
name|MAX_RX_RINGS
index|]
decl_stmt|;
name|bus_dma_tag_t
name|rx_tag
decl_stmt|;
comment|/* stats */
name|uint32_t
name|err_m_getcl
decl_stmt|;
name|uint32_t
name|err_m_getjcl
decl_stmt|;
name|uint32_t
name|err_tx_dmamap_create
decl_stmt|;
name|uint32_t
name|err_tx_dmamap_load
decl_stmt|;
name|uint32_t
name|err_tx_defrag
decl_stmt|;
comment|/* mac address related */
name|uint8_t
name|mac_rcv_mode
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|nmcast
decl_stmt|;
name|qla_mcast_t
name|mcast
index|[
name|Q8_MAX_NUM_MULTICAST_ADDRS
index|]
decl_stmt|;
comment|/* Link Related */
name|uint8_t
name|link_up
decl_stmt|;
name|uint32_t
name|link_status
decl_stmt|;
name|uint32_t
name|link_down_info
decl_stmt|;
name|uint32_t
name|link_hw_info
decl_stmt|;
name|uint32_t
name|link_dcbx_counters
decl_stmt|;
name|uint32_t
name|link_change_counters
decl_stmt|;
comment|/* Flash Related */
name|q81_flash_t
name|flash
decl_stmt|;
comment|/* debug stuff */
specifier|volatile
specifier|const
name|char
modifier|*
name|qla_lock
decl_stmt|;
specifier|volatile
specifier|const
name|char
modifier|*
name|qla_unlock
decl_stmt|;
comment|/* Error Recovery Related */
name|uint32_t
name|err_inject
decl_stmt|;
name|struct
name|task
name|err_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|err_tq
decl_stmt|;
comment|/* Chip related */
name|uint32_t
name|rev_id
decl_stmt|;
comment|/* mailbox completions */
name|uint32_t
name|aen
index|[
name|Q81_NUM_AEN_REGISTERS
index|]
decl_stmt|;
name|uint32_t
name|mbox
index|[
name|Q81_NUM_MBX_REGISTERS
index|]
decl_stmt|;
specifier|volatile
name|uint32_t
name|mbx_done
decl_stmt|;
comment|/* mpi dump related */
name|qla_dma_t
name|mpi_dma
decl_stmt|;
name|qla_dma_t
name|rss_dma
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|qla_host
name|qla_host_t
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
value|(((size) + ((align) - 1))& (~((align) - 1)))
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

begin_comment
comment|/* Return 0, if identical, else 1 */
end_comment

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
value|((((*(uint32_t *) mac1) == (*(uint32_t *) mac2)&& \ 	(*(uint16_t *)(mac1 + 4)) == (*(uint16_t *)(mac2 + 4)))) ? 0 : 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLS_DEF_H_ */
end_comment

end_unit

