begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Yohanes Nugroho<yohanes@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IFECEVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IFECEVAR_H
end_define

begin_define
define|#
directive|define
name|ECE_MAX_TX_BUFFERS
value|128
end_define

begin_define
define|#
directive|define
name|ECE_MAX_RX_BUFFERS
value|128
end_define

begin_define
define|#
directive|define
name|MAX_FRAGMENT
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* 1st 32Bits */
name|uint32_t
name|data_ptr
decl_stmt|;
comment|/* 2nd	32Bits*/
name|uint32_t
name|length
range|:
literal|16
decl_stmt|;
name|uint32_t
name|tco
range|:
literal|1
decl_stmt|;
comment|/*tcp checksum offload*/
name|uint32_t
name|uco
range|:
literal|1
decl_stmt|;
comment|/*udp checksum offload*/
name|uint32_t
name|ico
range|:
literal|1
decl_stmt|;
comment|/*ip checksum offload*/
comment|/* force_route_port_map*/
name|uint32_t
name|pmap
range|:
literal|3
decl_stmt|;
comment|/* force_route */
name|uint32_t
name|fr
range|:
literal|1
decl_stmt|;
comment|/* force_priority_value */
name|uint32_t
name|pri
range|:
literal|3
decl_stmt|;
comment|/* force_priority */
name|uint32_t
name|fp
range|:
literal|1
decl_stmt|;
comment|/*interrupt_bit*/
name|uint32_t
name|interrupt
range|:
literal|1
decl_stmt|;
comment|/*last_seg*/
name|uint32_t
name|ls
range|:
literal|1
decl_stmt|;
comment|/*first_seg*/
name|uint32_t
name|fs
range|:
literal|1
decl_stmt|;
comment|/* end_bit */
name|uint32_t
name|eor
range|:
literal|1
decl_stmt|;
comment|/* c_bit */
name|uint32_t
name|cown
range|:
literal|1
decl_stmt|;
comment|/* 3rd 32Bits*/
comment|/*vid_index*/
name|uint32_t
name|vid
range|:
literal|3
decl_stmt|;
comment|/*insert_vid_tag*/
name|uint32_t
name|insv
range|:
literal|1
decl_stmt|;
comment|/*pppoe_section_index*/
name|uint32_t
name|sid
range|:
literal|3
decl_stmt|;
comment|/*insert_pppoe_section*/
name|uint32_t
name|inss
range|:
literal|1
decl_stmt|;
name|uint32_t
name|unused
range|:
literal|24
decl_stmt|;
comment|/* 4th 32Bits*/
name|uint32_t
name|unused2
decl_stmt|;
block|}
name|eth_tx_desc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint32_t
name|data_ptr
decl_stmt|;
name|uint32_t
name|length
range|:
literal|16
decl_stmt|;
name|uint32_t
name|l4f
range|:
literal|1
decl_stmt|;
name|uint32_t
name|ipf
range|:
literal|1
decl_stmt|;
name|uint32_t
name|prot
range|:
literal|2
decl_stmt|;
name|uint32_t
name|hr
range|:
literal|6
decl_stmt|;
name|uint32_t
name|sp
range|:
literal|2
decl_stmt|;
name|uint32_t
name|ls
range|:
literal|1
decl_stmt|;
name|uint32_t
name|fs
range|:
literal|1
decl_stmt|;
name|uint32_t
name|eor
range|:
literal|1
decl_stmt|;
name|uint32_t
name|cown
range|:
literal|1
decl_stmt|;
name|uint32_t
name|unused
decl_stmt|;
name|uint32_t
name|unused2
decl_stmt|;
block|}
name|eth_rx_desc_t
typedef|;
end_typedef

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
name|eth_rx_desc_t
modifier|*
name|desc
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
name|eth_tx_desc_t
modifier|*
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ece_softc
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
name|struct
name|mtx
name|sc_mtx_tx
decl_stmt|;
comment|/* tx mutex */
name|struct
name|mtx
name|sc_mtx_rx
decl_stmt|;
comment|/* rx mutex */
name|struct
name|mtx
name|sc_mtx_cleanup
decl_stmt|;
comment|/* rx mutex */
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
name|irq_res_tx
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
name|sc_cleanup_task
decl_stmt|;
name|struct
name|task
name|sc_tx_task
decl_stmt|;
name|bus_dmamap_t
name|dmamap_ring_tx
decl_stmt|;
name|bus_dmamap_t
name|dmamap_ring_rx
decl_stmt|;
name|bus_dmamap_t
name|rx_sparemap
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
name|eth_tx_desc_t
modifier|*
name|desc_tx
decl_stmt|;
name|eth_rx_desc_t
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
name|uint32_t
name|last_rx
decl_stmt|;
name|struct
name|rx_desc_info
name|rx_desc
index|[
name|ECE_MAX_RX_BUFFERS
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
comment|/* tx ring index*/
name|uint32_t
name|desc_curr_tx
decl_stmt|;
name|struct
name|tx_desc_info
name|tx_desc
index|[
name|ECE_MAX_TX_BUFFERS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arl_table_entry_t
block|{
name|uint32_t
name|cmd_complete
range|:
literal|1
decl_stmt|;
name|uint32_t
name|table_end
range|:
literal|1
decl_stmt|;
name|uint32_t
name|search_match
range|:
literal|1
decl_stmt|;
name|uint32_t
name|filter
range|:
literal|1
decl_stmt|;
comment|/*if set, packet will be dropped */
name|uint32_t
name|vlan_mac
range|:
literal|1
decl_stmt|;
comment|/*indicates that this is the gateway mac address*/
name|uint32_t
name|vlan_gid
range|:
literal|3
decl_stmt|;
comment|/*vlan id*/
name|uint32_t
name|age_field
range|:
literal|3
decl_stmt|;
name|uint32_t
name|port_map
range|:
literal|3
decl_stmt|;
comment|/*48 bit mac address*/
name|uint8_t
name|mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_list
block|{
name|char
name|mac_addr
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|mac_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

