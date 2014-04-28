begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_MACB_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_MACB_H
end_define

begin_define
define|#
directive|define
name|MACB_MAX_TX_BUFFERS
value|64
end_define

begin_define
define|#
directive|define
name|MACB_MAX_RX_BUFFERS
value|256
end_define

begin_define
define|#
directive|define
name|MAX_FRAGMENT
value|20
end_define

begin_define
define|#
directive|define
name|DATA_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|MACB_DESC_INC
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
name|MACB_TIMEOUT
value|1000
end_define

begin_struct
struct|struct
name|eth_tx_desc
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|TD_OWN
value|(1U<< 31)
define|#
directive|define
name|TD_LAST
value|(1<< 15)
define|#
directive|define
name|TD_WRAP_MASK
value|(1<< 30)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|eth_rx_desc
block|{
name|uint32_t
name|addr
decl_stmt|;
define|#
directive|define
name|RD_LEN_MASK
value|0x7ff
define|#
directive|define
name|RD_WRAP_MASK
value|0x00000002
define|#
directive|define
name|RD_OWN
value|0x00000001
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|RD_BROADCAST
value|(1U<< 31)
define|#
directive|define
name|RD_MULTICAST
value|(1<< 30)
define|#
directive|define
name|RD_UNICAST
value|(1<< 29)
define|#
directive|define
name|RD_EXTERNAL
value|(1<< 28)
define|#
directive|define
name|RD_TYPE_ID
value|(1<< 22)
define|#
directive|define
name|RD_PRIORITY
value|(1<< 20)
define|#
directive|define
name|RD_VLAN
value|(1<< 21)
define|#
directive|define
name|RD_CONCAT
value|(1<< 16)
define|#
directive|define
name|RD_EOF
value|(1<< 15)
define|#
directive|define
name|RD_SOF
value|(1<< 14)
define|#
directive|define
name|RD_OFFSET_MASK
value|(1<< 13)|(1<< 12)
define|#
directive|define
name|RD_LENGTH_MASK
value|(0x00000FFF)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rx_desc_info
block|{
name|struct
name|mbuf
modifier|*
name|buff
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tx_desc_info
block|{
name|struct
name|mbuf
modifier|*
name|buff
decl_stmt|;
name|bus_dmamap_t
name|dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|macb_chain_data
block|{
name|struct
name|mbuf
modifier|*
name|rxhead
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rxtail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|macb_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* ifnet pointer */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* global mutex */
name|bus_dma_tag_t
name|sc_parent_tag
decl_stmt|;
comment|/* parent bus DMA tag */
name|device_t
name|dev
decl_stmt|;
comment|/* Myself */
name|device_t
name|miibus
decl_stmt|;
comment|/* My child miibus */
name|void
modifier|*
name|intrhand
decl_stmt|;
comment|/* Interrupt handle */
name|void
modifier|*
name|intrhand_qf
decl_stmt|;
comment|/* queue full */
name|void
modifier|*
name|intrhand_tx
decl_stmt|;
comment|/* tx complete */
name|void
modifier|*
name|intrhand_status
decl_stmt|;
comment|/* error status */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
comment|/* transmit */
name|struct
name|resource
modifier|*
name|irq_res_rec
decl_stmt|;
comment|/* receive */
name|struct
name|resource
modifier|*
name|irq_res_qf
decl_stmt|;
comment|/* queue full */
name|struct
name|resource
modifier|*
name|irq_res_status
decl_stmt|;
comment|/* status */
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
comment|/* Memory resource */
name|struct
name|callout
name|tick_ch
decl_stmt|;
comment|/* Tick callout */
name|struct
name|taskqueue
modifier|*
name|sc_tq
decl_stmt|;
name|struct
name|task
name|sc_intr_task
decl_stmt|;
name|struct
name|task
name|sc_tx_task
decl_stmt|;
name|struct
name|task
name|sc_link_task
decl_stmt|;
name|bus_dmamap_t
name|dmamap_ring_tx
decl_stmt|;
name|bus_dmamap_t
name|dmamap_ring_rx
decl_stmt|;
comment|/*dma tag for ring*/
name|bus_dma_tag_t
name|dmatag_ring_tx
decl_stmt|;
name|bus_dma_tag_t
name|dmatag_ring_rx
decl_stmt|;
comment|/*dma tag for data*/
name|bus_dma_tag_t
name|dmatag_data_tx
decl_stmt|;
name|bus_dma_tag_t
name|dmatag_data_rx
decl_stmt|;
comment|/*the ring*/
name|struct
name|eth_tx_desc
modifier|*
name|desc_tx
decl_stmt|;
name|struct
name|eth_rx_desc
modifier|*
name|desc_rx
decl_stmt|;
comment|/*ring physical address*/
name|bus_addr_t
name|ring_paddr_tx
decl_stmt|;
name|bus_addr_t
name|ring_paddr_rx
decl_stmt|;
comment|/*index of last received descriptor*/
name|int
name|rx_cons
decl_stmt|;
name|struct
name|rx_desc_info
name|rx_desc
index|[
name|MACB_MAX_RX_BUFFERS
index|]
decl_stmt|;
comment|/* tx producer index */
name|uint32_t
name|tx_prod
decl_stmt|;
comment|/* tx consumer index */
name|uint32_t
name|tx_cons
decl_stmt|;
name|int
name|tx_cnt
decl_stmt|;
name|struct
name|tx_desc_info
name|tx_desc
index|[
name|MACB_MAX_TX_BUFFERS
index|]
decl_stmt|;
name|int
name|macb_watchdog_timer
decl_stmt|;
define|#
directive|define
name|MACB_FLAG_LINK
value|0x0001
name|int
name|flags
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|at91_pmc_clock
modifier|*
name|clk
decl_stmt|;
name|struct
name|macb_chain_data
name|macb_cdata
decl_stmt|;
name|int
name|clock
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

