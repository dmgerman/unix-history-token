begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2010 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_PS3_IF_GLCREG_H
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_PS3_IF_GLCREG_H
end_define

begin_define
define|#
directive|define
name|GLC_MAX_TX_PACKETS
value|128
end_define

begin_define
define|#
directive|define
name|GLC_MAX_RX_PACKETS
value|128
end_define

begin_struct_decl
struct_decl|struct
name|glc_dmadesc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * software state for transmit job mbufs (may be elements of mbuf chains)  */
end_comment

begin_struct
struct|struct
name|glc_txsoft
block|{
name|struct
name|mbuf
modifier|*
name|txs_mbuf
decl_stmt|;
comment|/* head of our mbuf chain */
name|bus_dmamap_t
name|txs_dmamap
decl_stmt|;
comment|/* our DMA map */
name|int
name|txs_firstdesc
decl_stmt|;
comment|/* first descriptor in packet */
name|int
name|txs_lastdesc
decl_stmt|;
comment|/* last descriptor in packet */
name|int
name|txs_ndescs
decl_stmt|;
comment|/* number of descriptors */
name|STAILQ_ENTRY
argument_list|(
argument|glc_txsoft
argument_list|)
name|txs_q
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|glc_txsq
argument_list|,
name|glc_txsoft
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * software state for receive jobs  */
end_comment

begin_struct
struct|struct
name|glc_rxsoft
block|{
name|struct
name|mbuf
modifier|*
name|rxs_mbuf
decl_stmt|;
comment|/* head of our mbuf chain */
name|bus_dmamap_t
name|rxs_dmamap
decl_stmt|;
comment|/* our DMA map */
name|int
name|rxs_desc_slot
decl_stmt|;
comment|/* DMA descriptor for this packet */
name|bus_addr_t
name|rxs_desc
decl_stmt|;
name|bus_dma_segment_t
name|segment
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|glc_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|device_t
name|sc_self
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|u_char
name|sc_enaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|int
name|sc_tx_vlan
decl_stmt|,
name|sc_rx_vlan
decl_stmt|;
name|int
name|sc_ifpflags
decl_stmt|;
name|uint64_t
name|sc_dma_base
index|[
literal|5
index|]
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmadesc_tag
decl_stmt|;
name|int
name|sc_irqid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
name|void
modifier|*
name|sc_irqctx
decl_stmt|;
name|uint64_t
modifier|*
name|sc_hwirq_status
decl_stmt|;
specifier|volatile
name|uint64_t
name|sc_interrupt_status
decl_stmt|;
name|struct
name|ifmedia
name|sc_media
decl_stmt|;
comment|/* Transmission */
name|bus_dma_tag_t
name|sc_txdma_tag
decl_stmt|;
name|struct
name|glc_txsoft
name|sc_txsoft
index|[
name|GLC_MAX_TX_PACKETS
index|]
decl_stmt|;
name|struct
name|glc_dmadesc
modifier|*
name|sc_txdmadesc
decl_stmt|;
name|int
name|next_txdma_slot
decl_stmt|,
name|first_used_txdma_slot
decl_stmt|,
name|bsy_txdma_slots
decl_stmt|;
name|bus_dmamap_t
name|sc_txdmadesc_map
decl_stmt|;
name|bus_addr_t
name|sc_txdmadesc_phys
decl_stmt|;
name|struct
name|glc_txsq
name|sc_txfreeq
decl_stmt|;
name|struct
name|glc_txsq
name|sc_txdirtyq
decl_stmt|;
comment|/* Reception */
name|bus_dma_tag_t
name|sc_rxdma_tag
decl_stmt|;
name|struct
name|glc_rxsoft
name|sc_rxsoft
index|[
name|GLC_MAX_RX_PACKETS
index|]
decl_stmt|;
name|struct
name|glc_dmadesc
modifier|*
name|sc_rxdmadesc
decl_stmt|;
name|int
name|sc_next_rxdma_slot
decl_stmt|;
name|bus_dmamap_t
name|sc_rxdmadesc_map
decl_stmt|;
name|bus_addr_t
name|sc_rxdmadesc_phys
decl_stmt|;
name|int
name|sc_bus
decl_stmt|,
name|sc_dev
decl_stmt|;
name|int
name|sc_wdog_timer
decl_stmt|;
name|struct
name|callout
name|sc_tick_ch
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GELIC_GET_MAC_ADDRESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|GELIC_GET_LINK_STATUS
value|0x0002
end_define

begin_define
define|#
directive|define
name|GELIC_SET_LINK_MODE
value|0x0003
end_define

begin_define
define|#
directive|define
name|GELIC_LINK_UP
value|0x0001
end_define

begin_define
define|#
directive|define
name|GELIC_FULL_DUPLEX
value|0x0002
end_define

begin_define
define|#
directive|define
name|GELIC_AUTO_NEG
value|0x0004
end_define

begin_define
define|#
directive|define
name|GELIC_SPEED_10
value|0x0010
end_define

begin_define
define|#
directive|define
name|GELIC_SPEED_100
value|0x0020
end_define

begin_define
define|#
directive|define
name|GELIC_SPEED_1000
value|0x0040
end_define

begin_define
define|#
directive|define
name|GELIC_GET_VLAN_ID
value|0x0004
end_define

begin_define
define|#
directive|define
name|GELIC_VLAN_TX_ETHERNET
value|0x0002
end_define

begin_define
define|#
directive|define
name|GELIC_VLAN_RX_ETHERNET
value|0x0012
end_define

begin_define
define|#
directive|define
name|GELIC_VLAN_TX_WIRELESS
value|0x0003
end_define

begin_define
define|#
directive|define
name|GELIC_VLAN_RX_WIRELESS
value|0x0013
end_define

begin_comment
comment|/* Command status code */
end_comment

begin_define
define|#
directive|define
name|GELIC_DESCR_OWNED
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|GELIC_CMDSTAT_DMA_DONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GELIC_CMDSTAT_CHAIN_END
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GELIC_CMDSTAT_CSUM_TCP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|GELIC_CMDSTAT_CSUM_UDP
value|0x00030000
end_define

begin_define
define|#
directive|define
name|GELIC_CMDSTAT_NOIPSEC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|GELIC_CMDSTAT_LAST
value|0x00040000
end_define

begin_define
define|#
directive|define
name|GELIC_RXERRORS
value|0x7def8000
end_define

begin_comment
comment|/* RX Data Status codes */
end_comment

begin_define
define|#
directive|define
name|GELIC_RX_IPCSUM
value|0x20000000
end_define

begin_define
define|#
directive|define
name|GELIC_RX_TCPUDPCSUM
value|0x10000000
end_define

begin_comment
comment|/* Interrupt options */
end_comment

begin_define
define|#
directive|define
name|GELIC_INT_RXDONE
value|0x0000000000004000UL
end_define

begin_define
define|#
directive|define
name|GELIC_INT_RXFRAME
value|0x1000000000000000UL
end_define

begin_define
define|#
directive|define
name|GELIC_INT_TXDONE
value|0x0080000000000000UL
end_define

begin_define
define|#
directive|define
name|GELIC_INT_TX_CHAIN_END
value|0x0100000000000000UL
end_define

begin_define
define|#
directive|define
name|GELIC_INT_PHY
value|0x0000000020000000UL
end_define

begin_comment
comment|/* Hardware DMA descriptor. Must be 32-byte aligned */
end_comment

begin_struct
struct|struct
name|glc_dmadesc
block|{
name|uint32_t
name|paddr
decl_stmt|;
comment|/* Must be 128 byte aligned for receive */
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
name|next
decl_stmt|;
name|uint32_t
name|cmd_stat
decl_stmt|;
name|uint32_t
name|result_size
decl_stmt|;
name|uint32_t
name|valid_size
decl_stmt|;
name|uint32_t
name|data_stat
decl_stmt|;
name|uint32_t
name|rxerror
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_PS3_IF_GLCREG_H */
end_comment

end_unit

