begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Semen Ustimenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Configuration  */
end_comment

begin_comment
comment|/*#define	EPIC_DIAG	1*/
end_comment

begin_comment
comment|/*#define	EPIC_USEIOSPACE	1*/
end_comment

begin_comment
comment|/*#define	EPIC_EARLY_RX	1*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETHER_MAX_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETHER_MAX_LEN
value|1518
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHER_MIN_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETHER_MIN_LEN
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHER_CRC_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETHER_CRC_LEN
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TX_RING_SIZE
value|16
end_define

begin_comment
comment|/* Leave this a power of 2 */
end_comment

begin_define
define|#
directive|define
name|RX_RING_SIZE
value|16
end_define

begin_comment
comment|/* And this too, to do not */
end_comment

begin_comment
comment|/* confuse RX(TX)_RING_MASK */
end_comment

begin_define
define|#
directive|define
name|TX_RING_MASK
value|(TX_RING_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|RX_RING_MASK
value|(RX_RING_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|ETHER_MAX_FRAME_LEN
value|(ETHER_MAX_LEN + ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|ETHER_ALIGN
value|2
end_define

begin_comment
comment|/* This is driver's structure to define EPIC descriptors */
end_comment

begin_struct
struct|struct
name|epic_rx_buffer
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* mbuf receiving packet */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* DMA map */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|epic_tx_buffer
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* mbuf contained packet */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* DMA map */
block|}
struct|;
end_struct

begin_comment
comment|/* PHY, known by tx driver */
end_comment

begin_define
define|#
directive|define
name|EPIC_UNKN_PHY
value|0x0000
end_define

begin_define
define|#
directive|define
name|EPIC_QS6612_PHY
value|0x0001
end_define

begin_define
define|#
directive|define
name|EPIC_AC101_PHY
value|0x0002
end_define

begin_define
define|#
directive|define
name|EPIC_LXT970_PHY
value|0x0003
end_define

begin_define
define|#
directive|define
name|EPIC_SERIAL
value|0x0004
end_define

begin_comment
comment|/* Driver status structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|callout_handle
name|stat_ch
decl_stmt|;
name|u_int32_t
name|unit
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
name|bus_dma_tag_t
name|mtag
decl_stmt|;
name|bus_dma_tag_t
name|rtag
decl_stmt|;
name|bus_dmamap_t
name|rmap
decl_stmt|;
name|bus_dma_tag_t
name|ttag
decl_stmt|;
name|bus_dmamap_t
name|tmap
decl_stmt|;
name|bus_dma_tag_t
name|ftag
decl_stmt|;
name|bus_dmamap_t
name|fmap
decl_stmt|;
name|bus_dmamap_t
name|sparemap
decl_stmt|;
name|struct
name|epic_rx_buffer
name|rx_buffer
index|[
name|RX_RING_SIZE
index|]
decl_stmt|;
name|struct
name|epic_tx_buffer
name|tx_buffer
index|[
name|TX_RING_SIZE
index|]
decl_stmt|;
comment|/* Each element of array MUST be aligned on dword  */
comment|/* and bounded on PAGE_SIZE 			   */
name|struct
name|epic_rx_desc
modifier|*
name|rx_desc
decl_stmt|;
name|struct
name|epic_tx_desc
modifier|*
name|tx_desc
decl_stmt|;
name|struct
name|epic_frag_list
modifier|*
name|tx_flist
decl_stmt|;
name|u_int32_t
name|rx_addr
decl_stmt|;
name|u_int32_t
name|tx_addr
decl_stmt|;
name|u_int32_t
name|frag_addr
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|u_int32_t
name|tx_threshold
decl_stmt|;
name|u_int32_t
name|txcon
decl_stmt|;
name|u_int32_t
name|miicfg
decl_stmt|;
name|u_int32_t
name|cur_tx
decl_stmt|;
name|u_int32_t
name|cur_rx
decl_stmt|;
name|u_int32_t
name|dirty_tx
decl_stmt|;
name|u_int32_t
name|pending_txs
decl_stmt|;
name|u_int16_t
name|cardvend
decl_stmt|;
name|u_int16_t
name|cardid
decl_stmt|;
name|struct
name|mii_softc
modifier|*
name|physc
decl_stmt|;
name|u_int32_t
name|phyid
decl_stmt|;
name|int
name|serinst
decl_stmt|;
name|void
modifier|*
name|pool
decl_stmt|;
block|}
name|epic_softc_t
typedef|;
end_typedef

begin_struct
struct|struct
name|epic_type
block|{
name|u_int16_t
name|ven_id
decl_stmt|;
name|u_int16_t
name|dev_id
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1((sc)->sc_st, (sc)->sc_sh, (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1((sc)->sc_st, (sc)->sc_sh, (reg))
end_define

begin_define
define|#
directive|define
name|PHY_READ_2
parameter_list|(
name|sc
parameter_list|,
name|phy
parameter_list|,
name|reg
parameter_list|)
define|\
value|epic_read_phy_reg((sc), (phy), (reg))
end_define

begin_define
define|#
directive|define
name|PHY_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|phy
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|epic_write_phy_reg((sc), (phy), (reg), (val))
end_define

end_unit

