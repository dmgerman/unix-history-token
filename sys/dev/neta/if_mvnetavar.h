begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017 Stormshield.  * Copyright (c) 2017 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_MVNETAVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_MVNETAVAR_H_
end_define

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_define
define|#
directive|define
name|MVNETA_HWHEADER_SIZE
value|2
end_define

begin_comment
comment|/* Marvell Header */
end_comment

begin_define
define|#
directive|define
name|MVNETA_ETHER_SIZE
value|22
end_define

begin_comment
comment|/* Maximum ether size */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MAX_CSUM_MTU
value|1600
end_define

begin_comment
comment|/* Port1,2 hw limit */
end_comment

begin_comment
comment|/*  * Limit support for frame up to hw csum limit  * until jumbo frame support is added.  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_MAX_FRAME
value|(MVNETA_MAX_CSUM_MTU + MVNETA_ETHER_SIZE)
end_define

begin_comment
comment|/*  * Default limit of queue length  *  * queue 0 is lowest priority and queue 7 is highest priority.  * IP packet is received on queue 7 by default.  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_RING_CNT
value|512
end_define

begin_define
define|#
directive|define
name|MVNETA_RX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|MVNETA_BUFRING_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|MVNETA_PACKET_OFFSET
value|64
end_define

begin_define
define|#
directive|define
name|MVNETA_PACKET_SIZE
value|MCLBYTES
end_define

begin_define
define|#
directive|define
name|MVNETA_RXTH_COUNT
value|128
end_define

begin_define
define|#
directive|define
name|MVNETA_RX_REFILL_COUNT
value|8
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_RECLAIM_COUNT
value|32
end_define

begin_comment
comment|/*  * Device Register access  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4((sc)->res[0], (reg))
end_define

begin_define
define|#
directive|define
name|MVNETA_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((sc)->res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|MVNETA_READ_REGION
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_read_region_4((sc)->res[0], (reg), (val), (c))
end_define

begin_define
define|#
directive|define
name|MVNETA_WRITE_REGION
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|,
name|c
parameter_list|)
define|\
value|bus_write_region_4((sc)->res[0], (reg), (val), (c))
end_define

begin_define
define|#
directive|define
name|MVNETA_READ_MIB_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4((sc)->res[0], MVNETA_PORTMIB_BASE + (reg))
end_define

begin_define
define|#
directive|define
name|MVNETA_READ_MIB_8
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_8((sc)->res[0], MVNETA_PORTMIB_BASE + (reg))
end_define

begin_define
define|#
directive|define
name|MVNETA_IS_LINKUP
parameter_list|(
name|sc
parameter_list|)
define|\
value|(MVNETA_READ((sc), MVNETA_PSR)& MVNETA_PSR_LINKUP)
end_define

begin_define
define|#
directive|define
name|MVNETA_IS_QUEUE_SET
parameter_list|(
name|queues
parameter_list|,
name|q
parameter_list|)
define|\
value|((((queues)>> (q))& 0x1))
end_define

begin_comment
comment|/*  * EEE: Lower Power Idle config  * Default timer is duration of MTU sized frame transmission.  * The timer can be negotiated by LLDP protocol, but we have no  * support.  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPI_TS
value|(ETHERMTU * 8 / 1000)
end_define

begin_comment
comment|/* [us] */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPI_TW
value|(ETHERMTU * 8 / 1000)
end_define

begin_comment
comment|/* [us] */
end_comment

begin_define
define|#
directive|define
name|MVNETA_LPI_LI
value|(ETHERMTU * 8 / 1000)
end_define

begin_comment
comment|/* [us] */
end_comment

begin_comment
comment|/*  * DMA Descriptor  *  * the ethernet device has 8 rx/tx DMA queues. each of queue has its own  * decriptor list. descriptors are simply index by counter inside the device.  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_TX_SEGLIMIT
value|32
end_define

begin_define
define|#
directive|define
name|MVNETA_QUEUE_IDLE
value|1
end_define

begin_define
define|#
directive|define
name|MVNETA_QUEUE_WORKING
value|2
end_define

begin_define
define|#
directive|define
name|MVNETA_QUEUE_DISABLED
value|3
end_define

begin_struct
struct|struct
name|mvneta_buf
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* pointer to related mbuf */
name|bus_dmamap_t
name|dmap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mvneta_rx_ring
block|{
name|int
name|queue_status
decl_stmt|;
comment|/* Real descriptors array. shared by RxDMA */
name|struct
name|mvneta_rx_desc
modifier|*
name|desc
decl_stmt|;
name|bus_dmamap_t
name|desc_map
decl_stmt|;
name|bus_addr_t
name|desc_pa
decl_stmt|;
comment|/* Managment entries for each of descritors */
name|struct
name|mvneta_buf
name|rxbuf
index|[
name|MVNETA_RX_RING_CNT
index|]
decl_stmt|;
comment|/* locks */
name|struct
name|mtx
name|ring_mtx
decl_stmt|;
comment|/* Index */
name|int
name|dma
decl_stmt|;
name|int
name|cpu
decl_stmt|;
comment|/* Limit */
name|int
name|queue_th_received
decl_stmt|;
name|int
name|queue_th_time
decl_stmt|;
comment|/* [Tclk] */
comment|/* LRO */
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
name|boolean_t
name|lro_enabled
decl_stmt|;
comment|/* Is this queue out of mbuf */
name|boolean_t
name|needs_refill
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|mvneta_tx_ring
block|{
comment|/* Index of this queue */
name|int
name|qidx
decl_stmt|;
comment|/* IFNET pointer */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* Ring buffer for IFNET */
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* Real descriptors array. shared by TxDMA */
name|struct
name|mvneta_tx_desc
modifier|*
name|desc
decl_stmt|;
name|bus_dmamap_t
name|desc_map
decl_stmt|;
name|bus_addr_t
name|desc_pa
decl_stmt|;
comment|/* Managment entries for each of descritors */
name|struct
name|mvneta_buf
name|txbuf
index|[
name|MVNETA_TX_RING_CNT
index|]
decl_stmt|;
comment|/* locks */
name|struct
name|mtx
name|ring_mtx
decl_stmt|;
comment|/* Index */
name|int
name|used
decl_stmt|;
name|int
name|dma
decl_stmt|;
name|int
name|cpu
decl_stmt|;
comment|/* watchdog */
define|#
directive|define
name|MVNETA_WATCHDOG_TXCOMP
value|(hz / 10)
comment|/* 100ms */
define|#
directive|define
name|MVNETA_WATCHDOG
value|(10 * hz)
comment|/* 10s */
name|int
name|watchdog_time
decl_stmt|;
name|int
name|queue_status
decl_stmt|;
name|boolean_t
name|queue_hung
decl_stmt|;
comment|/* Task */
name|struct
name|task
name|task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|taskq
decl_stmt|;
comment|/* Stats */
name|uint32_t
name|drv_error
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_function
specifier|static
name|__inline
name|int
name|tx_counter_adv
parameter_list|(
name|int
name|ctr
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|ctr
operator|+=
name|n
expr_stmt|;
while|while
condition|(
name|__predict_false
argument_list|(
name|ctr
operator|>=
name|MVNETA_TX_RING_CNT
argument_list|)
condition|)
name|ctr
operator|-=
name|MVNETA_TX_RING_CNT
expr_stmt|;
return|return
operator|(
name|ctr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|rx_counter_adv
parameter_list|(
name|int
name|ctr
parameter_list|,
name|int
name|n
parameter_list|)
block|{
name|ctr
operator|+=
name|n
expr_stmt|;
while|while
condition|(
name|__predict_false
argument_list|(
name|ctr
operator|>=
name|MVNETA_RX_RING_CNT
argument_list|)
condition|)
name|ctr
operator|-=
name|MVNETA_RX_RING_CNT
expr_stmt|;
return|return
operator|(
name|ctr
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Timeout control  */
end_comment

begin_define
define|#
directive|define
name|MVNETA_PHY_TIMEOUT
value|10000
end_define

begin_comment
comment|/* msec */
end_comment

begin_define
define|#
directive|define
name|RX_DISABLE_TIMEOUT
value|0x1000000
end_define

begin_comment
comment|/* times */
end_comment

begin_define
define|#
directive|define
name|TX_DISABLE_TIMEOUT
value|0x1000000
end_define

begin_comment
comment|/* times */
end_comment

begin_define
define|#
directive|define
name|TX_FIFO_EMPTY_TIMEOUT
value|0x1000000
end_define

begin_comment
comment|/* times */
end_comment

begin_comment
comment|/*  * Debug  */
end_comment

begin_define
define|#
directive|define
name|KASSERT_SC_MTX
parameter_list|(
name|sc
parameter_list|)
define|\
value|KASSERT(mtx_owned(&(sc)->mtx), ("SC mutex not owned"))
end_define

begin_define
define|#
directive|define
name|KASSERT_BM_MTX
parameter_list|(
name|sc
parameter_list|)
define|\
value|KASSERT(mtx_owned(&(sc)->bm.bm_mtx), ("BM mutex not owned"))
end_define

begin_define
define|#
directive|define
name|KASSERT_RX_MTX
parameter_list|(
name|sc
parameter_list|,
name|q
parameter_list|)
define|\
value|KASSERT(mtx_owned(&(sc)->rx_ring[(q)].ring_mtx),\         ("RX mutex not owned"))
end_define

begin_define
define|#
directive|define
name|KASSERT_TX_MTX
parameter_list|(
name|sc
parameter_list|,
name|q
parameter_list|)
define|\
value|KASSERT(mtx_owned(&(sc)->tx_ring[(q)].ring_mtx),\         ("TX mutex not owned"))
end_define

begin_comment
comment|/*  * sysctl(9) parameters  */
end_comment

begin_struct
struct|struct
name|mvneta_sysctl_queue
block|{
name|struct
name|mvneta_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|rxtx
decl_stmt|;
name|int
name|queue
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MVNETA_SYSCTL_RX
value|0
end_define

begin_define
define|#
directive|define
name|MVNETA_SYSCTL_TX
value|1
end_define

begin_struct
struct|struct
name|mvneta_sysctl_mib
block|{
name|struct
name|mvneta_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|index
decl_stmt|;
name|uint64_t
name|counter
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mvneta_phy_mode
block|{
name|MVNETA_PHY_QSGMII
block|,
name|MVNETA_PHY_SGMII
block|,
name|MVNETA_PHY_RGMII
block|,
name|MVNETA_PHY_RGMII_ID
block|}
enum|;
end_enum

begin_comment
comment|/*  * Ethernet Device main context  */
end_comment

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|mvneta_driver
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|mvneta_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|uint32_t
name|version
decl_stmt|;
comment|/* 	 * mtx must be held by interface functions to/from 	 * other frameworks. interrupt hander, sysctl hander, 	 * ioctl hander, and so on. 	 */
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
index|[
literal|2
index|]
decl_stmt|;
name|void
modifier|*
name|ih_cookie
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|uint32_t
name|mvneta_if_flags
decl_stmt|;
name|uint32_t
name|mvneta_media
decl_stmt|;
name|int
name|phy_attached
decl_stmt|;
name|enum
name|mvneta_phy_mode
name|phy_mode
decl_stmt|;
name|int
name|phy_addr
decl_stmt|;
name|int
name|phy_speed
decl_stmt|;
comment|/* PHY speed */
name|boolean_t
name|phy_fdx
decl_stmt|;
comment|/* Full duplex mode */
name|boolean_t
name|autoneg
decl_stmt|;
comment|/* Autonegotiation status */
name|boolean_t
name|use_inband_status
decl_stmt|;
comment|/* In-band link status */
comment|/* 	 * Link State control 	 */
name|boolean_t
name|linkup
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|mii
decl_stmt|;
name|uint8_t
name|enaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|struct
name|ifmedia
name|mvneta_ifmedia
decl_stmt|;
name|bus_dma_tag_t
name|rx_dtag
decl_stmt|;
name|bus_dma_tag_t
name|rxbuf_dtag
decl_stmt|;
name|bus_dma_tag_t
name|tx_dtag
decl_stmt|;
name|bus_dma_tag_t
name|txmbuf_dtag
decl_stmt|;
name|struct
name|mvneta_rx_ring
name|rx_ring
index|[
name|MVNETA_RX_QNUM_MAX
index|]
decl_stmt|;
name|struct
name|mvneta_tx_ring
name|tx_ring
index|[
name|MVNETA_TX_QNUM_MAX
index|]
decl_stmt|;
comment|/* 	 * Maintance clock 	 */
name|struct
name|callout
name|tick_ch
decl_stmt|;
name|int
name|cf_lpi
decl_stmt|;
name|int
name|cf_fc
decl_stmt|;
name|int
name|debug
decl_stmt|;
comment|/* 	 * Sysctl interfaces 	 */
name|struct
name|mvneta_sysctl_queue
name|sysctl_rx_queue
index|[
name|MVNETA_RX_QNUM_MAX
index|]
decl_stmt|;
name|struct
name|mvneta_sysctl_queue
name|sysctl_tx_queue
index|[
name|MVNETA_TX_QNUM_MAX
index|]
decl_stmt|;
comment|/* 	 * MIB counter 	 */
name|struct
name|mvneta_sysctl_mib
name|sysctl_mib
index|[
name|MVNETA_PORTMIB_NOCOUNTER
index|]
decl_stmt|;
name|uint64_t
name|counter_pdfc
decl_stmt|;
name|uint64_t
name|counter_pofc
decl_stmt|;
name|uint32_t
name|counter_watchdog
decl_stmt|;
comment|/* manual reset when clearing mib */
name|uint32_t
name|counter_watchdog_mib
decl_stmt|;
comment|/* reset after each mib update */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MVNETA_RX_RING
parameter_list|(
name|sc
parameter_list|,
name|q
parameter_list|)
define|\
value|(&(sc)->rx_ring[(q)])
end_define

begin_define
define|#
directive|define
name|MVNETA_TX_RING
parameter_list|(
name|sc
parameter_list|,
name|q
parameter_list|)
define|\
value|(&(sc)->tx_ring[(q)])
end_define

begin_function_decl
name|int
name|mvneta_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FDT
end_ifdef

begin_function_decl
name|int
name|mvneta_fdt_mac_address
parameter_list|(
name|struct
name|mvneta_softc
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_MVNETAVAR_H_ */
end_comment

end_unit

