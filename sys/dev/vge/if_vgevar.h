begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|VGE_FIXUP_RX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VGE_JUMBO_MTU
value|9000
end_define

begin_define
define|#
directive|define
name|VGE_IFQ_MAXLEN
value|64
end_define

begin_define
define|#
directive|define
name|VGE_TX_DESC_CNT
value|256
end_define

begin_define
define|#
directive|define
name|VGE_RX_DESC_CNT
value|256
end_define

begin_comment
comment|/* Must be a multiple of 4!! */
end_comment

begin_define
define|#
directive|define
name|VGE_RING_ALIGN
value|256
end_define

begin_define
define|#
directive|define
name|VGE_RX_LIST_SZ
value|(VGE_RX_DESC_CNT * sizeof(struct vge_rx_desc))
end_define

begin_define
define|#
directive|define
name|VGE_TX_LIST_SZ
value|(VGE_TX_DESC_CNT * sizeof(struct vge_tx_desc))
end_define

begin_define
define|#
directive|define
name|VGE_TX_DESC_INC
parameter_list|(
name|x
parameter_list|)
value|(x = (x + 1) % VGE_TX_DESC_CNT)
end_define

begin_define
define|#
directive|define
name|VGE_RX_DESC_INC
parameter_list|(
name|x
parameter_list|)
value|(x = (x + 1) % VGE_RX_DESC_CNT)
end_define

begin_define
define|#
directive|define
name|VGE_ADDR_LO
parameter_list|(
name|y
parameter_list|)
value|((u_int64_t) (y)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|VGE_ADDR_HI
parameter_list|(
name|y
parameter_list|)
value|((u_int64_t) (y)>> 32)
end_define

begin_define
define|#
directive|define
name|VGE_BUFLEN
parameter_list|(
name|y
parameter_list|)
value|((y)& 0x7FFF)
end_define

begin_define
define|#
directive|define
name|VGE_OWN
parameter_list|(
name|x
parameter_list|)
value|(le32toh((x)->vge_sts)& VGE_RDSTS_OWN)
end_define

begin_define
define|#
directive|define
name|VGE_RXBYTES
parameter_list|(
name|x
parameter_list|)
value|((le32toh((x)->vge_sts)& \ 				 VGE_RDSTS_BUFSIZ)>> 16)
end_define

begin_define
define|#
directive|define
name|VGE_MIN_FRAMELEN
value|60
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VGE_FIXUP_RX
end_ifdef

begin_define
define|#
directive|define
name|VGE_ETHER_ALIGN
value|sizeof(uint32_t)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VGE_ETHER_ALIGN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|vge_type
block|{
name|uint16_t
name|vge_vid
decl_stmt|;
name|uint16_t
name|vge_did
decl_stmt|;
name|char
modifier|*
name|vge_name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|vge_softc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|vge_dmaload_arg
block|{
name|struct
name|vge_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|vge_idx
decl_stmt|;
name|int
name|vge_maxsegs
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vge_m0
decl_stmt|;
name|u_int32_t
name|vge_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vge_list_data
block|{
name|struct
name|mbuf
modifier|*
name|vge_tx_mbuf
index|[
name|VGE_TX_DESC_CNT
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vge_rx_mbuf
index|[
name|VGE_RX_DESC_CNT
index|]
decl_stmt|;
name|int
name|vge_tx_prodidx
decl_stmt|;
name|int
name|vge_rx_prodidx
decl_stmt|;
name|int
name|vge_tx_considx
decl_stmt|;
name|int
name|vge_tx_free
decl_stmt|;
name|bus_dmamap_t
name|vge_tx_dmamap
index|[
name|VGE_TX_DESC_CNT
index|]
decl_stmt|;
name|bus_dmamap_t
name|vge_rx_dmamap
index|[
name|VGE_RX_DESC_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|vge_mtag
decl_stmt|;
comment|/* mbuf mapping tag */
name|bus_dma_tag_t
name|vge_rx_list_tag
decl_stmt|;
name|bus_dmamap_t
name|vge_rx_list_map
decl_stmt|;
name|struct
name|vge_rx_desc
modifier|*
name|vge_rx_list
decl_stmt|;
name|bus_addr_t
name|vge_rx_list_addr
decl_stmt|;
name|bus_dma_tag_t
name|vge_tx_list_tag
decl_stmt|;
name|bus_dmamap_t
name|vge_tx_list_map
decl_stmt|;
name|struct
name|vge_tx_desc
modifier|*
name|vge_tx_list
decl_stmt|;
name|bus_addr_t
name|vge_tx_list_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vge_softc
block|{
name|struct
name|ifnet
modifier|*
name|vge_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|vge_dev
decl_stmt|;
name|bus_space_handle_t
name|vge_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|vge_btag
decl_stmt|;
comment|/* bus space tag */
name|struct
name|resource
modifier|*
name|vge_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|vge_irq
decl_stmt|;
name|void
modifier|*
name|vge_intrhand
decl_stmt|;
name|device_t
name|vge_miibus
decl_stmt|;
name|bus_dma_tag_t
name|vge_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|vge_tag
decl_stmt|;
name|u_int8_t
name|vge_type
decl_stmt|;
name|int
name|vge_if_flags
decl_stmt|;
name|int
name|vge_rx_consumed
decl_stmt|;
name|int
name|vge_link
decl_stmt|;
name|int
name|vge_camidx
decl_stmt|;
name|struct
name|task
name|vge_txtask
decl_stmt|;
name|struct
name|mtx
name|vge_mtx
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vge_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|vge_tail
decl_stmt|;
name|struct
name|vge_list_data
name|vge_ldata
decl_stmt|;
name|int
name|suspended
decl_stmt|;
comment|/* 0 = normal  1 = suspended */
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|rxcycles
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->vge_mtx)
end_define

begin_define
define|#
directive|define
name|VGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->vge_mtx)
end_define

begin_define
define|#
directive|define
name|VGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->vge_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_STREAM_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_stream_4(sc->vge_btag, sc->vge_bhandle, reg, val)
end_define

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
value|bus_space_write_4(sc->vge_btag, sc->vge_bhandle, reg, val)
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
value|bus_space_write_2(sc->vge_btag, sc->vge_bhandle, reg, val)
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
value|bus_space_write_1(sc->vge_btag, sc->vge_bhandle, reg, val)
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
value|bus_space_read_4(sc->vge_btag, sc->vge_bhandle, reg)
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
value|bus_space_read_2(sc->vge_btag, sc->vge_bhandle, reg)
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
value|bus_space_read_1(sc->vge_btag, sc->vge_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_1(sc, reg, CSR_READ_1(sc, reg) | (x))
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_2(sc, reg, CSR_READ_2(sc, reg) | (x))
end_define

begin_define
define|#
directive|define
name|CSR_SETBIT_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, reg, CSR_READ_4(sc, reg) | (x))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_1(sc, reg, CSR_READ_1(sc, reg)& ~(x))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_2(sc, reg, CSR_READ_2(sc, reg)& ~(x))
end_define

begin_define
define|#
directive|define
name|CSR_CLRBIT_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
define|\
value|CSR_WRITE_4(sc, reg, CSR_READ_4(sc, reg)& ~(x))
end_define

begin_define
define|#
directive|define
name|VGE_TIMEOUT
value|10000
end_define

end_unit

