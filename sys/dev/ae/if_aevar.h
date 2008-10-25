begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Stanislav Sedov<stas@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IF_AEVAR_H
end_ifndef

begin_define
define|#
directive|define
name|IF_AEVAR_H
end_define

begin_comment
comment|/*  * Supported chips identifiers. */
end_comment

begin_define
define|#
directive|define
name|VENDORID_ATTANSIC
value|0x1969
end_define

begin_define
define|#
directive|define
name|DEVICEID_ATTANSIC_L2
value|0x2048
end_define

begin_comment
comment|/* How much to wait for reset to complete (10 microsecond units). */
end_comment

begin_define
define|#
directive|define
name|AE_RESET_TIMEOUT
value|100
end_define

begin_comment
comment|/* How much to wait for device to enter idle state (100 microsecond units). */
end_comment

begin_define
define|#
directive|define
name|AE_IDLE_TIMEOUT
value|100
end_define

begin_comment
comment|/* How much to wait for MDIO to do the work (2 microsecond units). */
end_comment

begin_define
define|#
directive|define
name|AE_MDIO_TIMEOUT
value|10
end_define

begin_comment
comment|/* How much to wait for VPD reading operation to complete (2 ms units). */
end_comment

begin_define
define|#
directive|define
name|AE_VPD_TIMEOUT
value|10
end_define

begin_comment
comment|/* How much to wait for send operation to complete (HZ units). */
end_comment

begin_define
define|#
directive|define
name|AE_TX_TIMEOUT
value|5
end_define

begin_comment
comment|/* Default PHY address. */
end_comment

begin_define
define|#
directive|define
name|AE_PHYADDR_DEFAULT
value|0
end_define

begin_comment
comment|/* Tx packet descriptor header format. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ae_txd
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|vlan
decl_stmt|;
block|}
name|__packed
name|ae_txd_t
typedef|;
end_typedef

begin_comment
comment|/* Tx status descriptor format. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ae_txs
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
block|}
name|__packed
name|ae_txs_t
typedef|;
end_typedef

begin_comment
comment|/* Rx packet descriptor format. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ae_rxd
block|{
name|uint16_t
name|len
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint16_t
name|vlan
decl_stmt|;
name|uint16_t
name|__pad
decl_stmt|;
name|uint8_t
name|data
index|[
literal|1528
index|]
decl_stmt|;
block|}
name|__packed
name|ae_rxd_t
typedef|;
end_typedef

begin_comment
comment|/* Statistics. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ae_stats
block|{
name|uint32_t
name|rx_bcast
decl_stmt|;
name|uint32_t
name|rx_mcast
decl_stmt|;
name|uint32_t
name|rx_pause
decl_stmt|;
name|uint32_t
name|rx_ctrl
decl_stmt|;
name|uint32_t
name|rx_crcerr
decl_stmt|;
name|uint32_t
name|rx_codeerr
decl_stmt|;
name|uint32_t
name|rx_runt
decl_stmt|;
name|uint32_t
name|rx_frag
decl_stmt|;
name|uint32_t
name|rx_trunc
decl_stmt|;
name|uint32_t
name|rx_align
decl_stmt|;
name|uint32_t
name|tx_bcast
decl_stmt|;
name|uint32_t
name|tx_mcast
decl_stmt|;
name|uint32_t
name|tx_pause
decl_stmt|;
name|uint32_t
name|tx_ctrl
decl_stmt|;
name|uint32_t
name|tx_defer
decl_stmt|;
name|uint32_t
name|tx_excdefer
decl_stmt|;
name|uint32_t
name|tx_singlecol
decl_stmt|;
name|uint32_t
name|tx_multicol
decl_stmt|;
name|uint32_t
name|tx_latecol
decl_stmt|;
name|uint32_t
name|tx_abortcol
decl_stmt|;
name|uint32_t
name|tx_underrun
decl_stmt|;
block|}
name|ae_stats_t
typedef|;
end_typedef

begin_comment
comment|/* Software state structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ae_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|resource_spec
modifier|*
name|spec_mem
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|resource_spec
modifier|*
name|spec_irq
decl_stmt|;
name|void
modifier|*
name|intrhand
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|int
name|phyaddr
decl_stmt|;
name|uint8_t
name|eaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|callout
name|tick_ch
decl_stmt|;
comment|/* Tasks. */
name|struct
name|task
name|int_task
decl_stmt|;
name|struct
name|task
name|tx_task
decl_stmt|;
name|struct
name|task
name|link_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
comment|/* DMA tags. */
name|bus_dma_tag_t
name|dma_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|dma_rxd_tag
decl_stmt|;
name|bus_dma_tag_t
name|dma_txd_tag
decl_stmt|;
name|bus_dma_tag_t
name|dma_txs_tag
decl_stmt|;
name|bus_dmamap_t
name|dma_rxd_map
decl_stmt|;
name|bus_dmamap_t
name|dma_txd_map
decl_stmt|;
name|bus_dmamap_t
name|dma_txs_map
decl_stmt|;
name|bus_addr_t
name|dma_rxd_busaddr
decl_stmt|;
name|bus_addr_t
name|dma_txd_busaddr
decl_stmt|;
name|bus_addr_t
name|dma_txs_busaddr
decl_stmt|;
name|char
modifier|*
name|rxd_base_dma
decl_stmt|;
comment|/* Start of allocated area. */
name|ae_rxd_t
modifier|*
name|rxd_base
decl_stmt|;
comment|/* Start of RxD ring. */
name|char
modifier|*
name|txd_base
decl_stmt|;
comment|/* Start of TxD ring. */
name|ae_txs_t
modifier|*
name|txs_base
decl_stmt|;
comment|/* Start of TxS ring. */
comment|/* Ring pointers. */
name|unsigned
name|int
name|rxd_cur
decl_stmt|;
name|unsigned
name|int
name|txd_cur
decl_stmt|;
name|unsigned
name|int
name|txs_cur
decl_stmt|;
name|unsigned
name|int
name|txs_ack
decl_stmt|;
name|unsigned
name|int
name|txd_ack
decl_stmt|;
name|int
name|tx_inproc
decl_stmt|;
comment|/* Active Tx frames in ring. */
name|int
name|wd_timer
decl_stmt|;
name|ae_stats_t
name|stats
decl_stmt|;
block|}
name|ae_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|AE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->mtx)
end_define

begin_define
define|#
directive|define
name|AE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|BUS_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|BUS_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)>> 32)
end_define

begin_define
define|#
directive|define
name|AE_FLAG_LINK
value|0x01
end_define

begin_comment
comment|/* Has link. */
end_comment

begin_define
define|#
directive|define
name|AE_FLAG_DETACH
value|0x02
end_define

begin_comment
comment|/* Is detaching. */
end_comment

begin_define
define|#
directive|define
name|AE_FLAG_TXAVAIL
value|0x04
end_define

begin_comment
comment|/* Tx'es available. */
end_comment

begin_define
define|#
directive|define
name|AE_FLAG_MSI
value|0x08
end_define

begin_comment
comment|/* Using MSI. */
end_comment

begin_define
define|#
directive|define
name|AE_FLAG_PMG
value|0x10
end_define

begin_comment
comment|/* Supports PCI power management. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_AEVAR_H */
end_comment

end_unit

