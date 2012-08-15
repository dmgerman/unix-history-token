begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Damjan Marion<dmarion@Freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_CPSWVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_CPSWVAR_H
end_define

begin_define
define|#
directive|define
name|CPSW_INTR_COUNT
value|4
end_define

begin_comment
comment|/* MII BUS  */
end_comment

begin_define
define|#
directive|define
name|CPSW_MIIBUS_RETRIES
value|5
end_define

begin_define
define|#
directive|define
name|CPSW_MIIBUS_DELAY
value|1000
end_define

begin_define
define|#
directive|define
name|CPSW_MAX_TX_BUFFERS
value|128
end_define

begin_define
define|#
directive|define
name|CPSW_MAX_RX_BUFFERS
value|128
end_define

begin_define
define|#
directive|define
name|CPSW_MAX_ALE_ENTRIES
value|1024
end_define

begin_struct
struct|struct
name|cpsw_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|phandle_t
name|node
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|uint8_t
name|mac_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|mii
decl_stmt|;
name|struct
name|mtx
name|tx_lock
decl_stmt|;
comment|/* transmitter lock */
name|struct
name|mtx
name|rx_lock
decl_stmt|;
comment|/* receiver lock */
name|struct
name|resource
modifier|*
name|res
index|[
literal|1
operator|+
name|CPSW_INTR_COUNT
index|]
decl_stmt|;
comment|/* resources */
name|void
modifier|*
name|ih_cookie
index|[
name|CPSW_INTR_COUNT
index|]
decl_stmt|;
comment|/* interrupt handlers cookies */
name|uint32_t
name|cpsw_if_flags
decl_stmt|;
name|int
name|cpsw_media_status
decl_stmt|;
name|struct
name|callout
name|wd_callout
decl_stmt|;
name|int
name|wd_timer
decl_stmt|;
comment|/* buffers */
name|bus_dma_tag_t
name|mbuf_dtag
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
index|[
name|CPSW_MAX_TX_BUFFERS
index|]
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
index|[
name|CPSW_MAX_RX_BUFFERS
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tx_mbuf
index|[
name|CPSW_MAX_TX_BUFFERS
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rx_mbuf
index|[
name|CPSW_MAX_RX_BUFFERS
index|]
decl_stmt|;
name|int
name|txbd_head
decl_stmt|;
name|int
name|txbd_queue_size
decl_stmt|;
name|int
name|rxbd_head
decl_stmt|;
name|int
name|rxbd_tail
decl_stmt|;
name|int
name|tmp
decl_stmt|;
name|int
name|eoq
decl_stmt|;
name|int
name|tc
index|[
name|CPSW_MAX_TX_BUFFERS
index|]
decl_stmt|;
name|int
name|tc_unload
index|[
name|CPSW_MAX_TX_BUFFERS
index|]
decl_stmt|;
name|struct
name|cpsw_softc
modifier|*
name|phy_sc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CPDMA_BD_SOP
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_EOP
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_OWNER
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_EOQ
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|CPDMA_BD_PKT_ERR_MASK
value|(3<< 4)
end_define

begin_struct
struct|struct
name|cpsw_cpdma_bd
block|{
specifier|volatile
name|uint32_t
name|next
decl_stmt|;
specifier|volatile
name|uint32_t
name|bufptr
decl_stmt|;
specifier|volatile
name|uint16_t
name|buflen
decl_stmt|;
specifier|volatile
name|uint16_t
name|bufoff
decl_stmt|;
specifier|volatile
name|uint16_t
name|pktlen
decl_stmt|;
specifier|volatile
name|uint16_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Read/Write macros */
end_comment

begin_define
define|#
directive|define
name|cpsw_read_4
parameter_list|(
name|reg
parameter_list|)
value|bus_read_4(sc->res[0], reg)
end_define

begin_define
define|#
directive|define
name|cpsw_write_4
parameter_list|(
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_4(sc->res[0], reg, val)
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_txbd_offset
parameter_list|(
name|i
parameter_list|)
define|\
value|(CPSW_CPPI_RAM_OFFSET + ((i)*16))
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_txbd_paddr
parameter_list|(
name|i
parameter_list|)
value|(cpsw_cpdma_txbd_offset(i) + \ 	vtophys(rman_get_start(sc->res[0])))
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_read_txbd
parameter_list|(
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_read_region_4(sc->res[0], cpsw_cpdma_txbd_offset(i), (uint32_t *) val, 4)
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_write_txbd
parameter_list|(
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_region_4(sc->res[0], cpsw_cpdma_txbd_offset(i), (uint32_t *) val, 4)
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_write_txbd_next
parameter_list|(
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4(sc->res[0], cpsw_cpdma_txbd_offset(i), val)
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_read_txbd_flags
parameter_list|(
name|i
parameter_list|)
define|\
value|bus_read_2(sc->res[0], cpsw_cpdma_txbd_offset(i)+14)
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_rxbd_offset
parameter_list|(
name|i
parameter_list|)
define|\
value|(CPSW_CPPI_RAM_OFFSET + ((CPSW_MAX_TX_BUFFERS + (i))*16))
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_rxbd_paddr
parameter_list|(
name|i
parameter_list|)
value|(cpsw_cpdma_rxbd_offset(i) + \ 	vtophys(rman_get_start(sc->res[0])))
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_read_rxbd
parameter_list|(
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_read_region_4(sc->res[0], cpsw_cpdma_rxbd_offset(i), (uint32_t *) val, 4)
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_write_rxbd
parameter_list|(
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_region_4(sc->res[0], cpsw_cpdma_rxbd_offset(i), (uint32_t *) val, 4)
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_write_rxbd_next
parameter_list|(
name|i
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4(sc->res[0], cpsw_cpdma_rxbd_offset(i), val)
end_define

begin_define
define|#
directive|define
name|cpsw_cpdma_read_rxbd_flags
parameter_list|(
name|i
parameter_list|)
define|\
value|bus_read_2(sc->res[0], cpsw_cpdma_rxbd_offset(i)+14)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_IF_CPSWVAR_H */
end_comment

end_unit

