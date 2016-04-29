begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Ethernet media access controller (EMAC)  * Chapter 17, Altera Cyclone V Device Handbook (CV-5V2 2014.07.22)  *  * EMAC is an instance of the Synopsys DesignWare 3504-0  * Universal 10/100/1000 Ethernet MAC (DWC_gmac).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_DWCVAR_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_DWCVAR_H__
end_define

begin_comment
comment|/*  * Driver data and defines.  */
end_comment

begin_define
define|#
directive|define
name|RX_MAX_PACKET
value|0x7ff
end_define

begin_define
define|#
directive|define
name|RX_DESC_COUNT
value|1024
end_define

begin_define
define|#
directive|define
name|RX_DESC_SIZE
value|(sizeof(struct dwc_hwdesc) * RX_DESC_COUNT)
end_define

begin_define
define|#
directive|define
name|TX_DESC_COUNT
value|1024
end_define

begin_define
define|#
directive|define
name|TX_DESC_SIZE
value|(sizeof(struct dwc_hwdesc) * TX_DESC_COUNT)
end_define

begin_struct
struct|struct
name|dwc_bufmap
block|{
name|bus_dmamap_t
name|map
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dwc_softc
block|{
name|struct
name|resource
modifier|*
name|res
index|[
literal|2
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|int
name|mactype
decl_stmt|;
name|int
name|mii_clk
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|mii_softc
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|void
modifier|*
name|intr_cookie
decl_stmt|;
name|struct
name|callout
name|dwc_callout
decl_stmt|;
name|boolean_t
name|link_is_up
decl_stmt|;
name|boolean_t
name|is_attached
decl_stmt|;
name|boolean_t
name|is_detaching
decl_stmt|;
name|int
name|tx_watchdog_count
decl_stmt|;
name|int
name|stats_harvest_count
decl_stmt|;
comment|/* RX */
name|bus_dma_tag_t
name|rxdesc_tag
decl_stmt|;
name|bus_dmamap_t
name|rxdesc_map
decl_stmt|;
name|struct
name|dwc_hwdesc
modifier|*
name|rxdesc_ring
decl_stmt|;
name|bus_addr_t
name|rxdesc_ring_paddr
decl_stmt|;
name|bus_dma_tag_t
name|rxbuf_tag
decl_stmt|;
name|struct
name|dwc_bufmap
name|rxbuf_map
index|[
name|RX_DESC_COUNT
index|]
decl_stmt|;
name|uint32_t
name|rx_idx
decl_stmt|;
comment|/* TX */
name|bus_dma_tag_t
name|txdesc_tag
decl_stmt|;
name|bus_dmamap_t
name|txdesc_map
decl_stmt|;
name|struct
name|dwc_hwdesc
modifier|*
name|txdesc_ring
decl_stmt|;
name|bus_addr_t
name|txdesc_ring_paddr
decl_stmt|;
name|bus_dma_tag_t
name|txbuf_tag
decl_stmt|;
name|struct
name|dwc_bufmap
name|txbuf_map
index|[
name|TX_DESC_COUNT
index|]
decl_stmt|;
name|uint32_t
name|tx_idx_head
decl_stmt|;
name|uint32_t
name|tx_idx_tail
decl_stmt|;
name|int
name|txcount
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_DWCVAR_H__ */
end_comment

end_unit

