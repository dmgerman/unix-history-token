begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Nathan Whitehorn  * Copyright (c) 2003 Peter Grehan  * All rights reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Number of transmit/receive DBDMA descriptors.  * XXX allow override with a tuneable ?  */
end_comment

begin_define
define|#
directive|define
name|BM_MAX_DMA_COMMANDS
value|256
end_define

begin_define
define|#
directive|define
name|BM_NTXSEGS
value|16
end_define

begin_define
define|#
directive|define
name|BM_MAX_TX_PACKETS
value|100
end_define

begin_define
define|#
directive|define
name|BM_MAX_RX_PACKETS
value|100
end_define

begin_comment
comment|/*  * Mutex macros  */
end_comment

begin_define
define|#
directive|define
name|BM_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|BM_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_comment
comment|/*  * software state for transmit job mbufs (may be elements of mbuf chains)  */
end_comment

begin_struct
struct|struct
name|bm_txsoft
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
name|txs_stopdesc
decl_stmt|;
comment|/* the location of the closing STOP */
name|int
name|txs_ndescs
decl_stmt|;
comment|/* number of descriptors */
name|STAILQ_ENTRY
argument_list|(
argument|bm_txsoft
argument_list|)
name|txs_q
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|bm_txsq
argument_list|,
name|bm_txsoft
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * software state for receive jobs  */
end_comment

begin_struct
struct|struct
name|bm_rxsoft
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
name|dbdma_slot
decl_stmt|;
name|bus_dma_segment_t
name|segment
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bm_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
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
name|sc_streaming
decl_stmt|;
name|int
name|sc_ifpflags
decl_stmt|;
name|int
name|sc_duplex
decl_stmt|;
name|int
name|sc_wdog_timer
decl_stmt|;
name|struct
name|callout
name|sc_tick_ch
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
comment|/* back ptr to dev */
name|struct
name|resource
modifier|*
name|sc_memr
decl_stmt|;
comment|/* macio bus mem resource */
name|int
name|sc_memrid
decl_stmt|;
name|device_t
name|sc_miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|sc_mii
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_txdmar
decl_stmt|,
modifier|*
name|sc_rxdmar
decl_stmt|;
name|int
name|sc_txdmarid
decl_stmt|,
name|sc_rxdmarid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_txdmairq
decl_stmt|,
modifier|*
name|sc_rxdmairq
decl_stmt|;
name|void
modifier|*
name|sc_txihtx
decl_stmt|,
modifier|*
name|sc_rxih
decl_stmt|;
name|int
name|sc_txdmairqid
decl_stmt|,
name|sc_rxdmairqid
decl_stmt|;
name|bus_dma_tag_t
name|sc_pdma_tag
decl_stmt|;
name|bus_dma_tag_t
name|sc_tdma_tag
decl_stmt|;
name|struct
name|bm_txsoft
name|sc_txsoft
index|[
name|BM_MAX_TX_PACKETS
index|]
decl_stmt|;
name|int
name|first_used_txdma_slot
decl_stmt|,
name|next_txdma_slot
decl_stmt|;
name|struct
name|bm_txsq
name|sc_txfreeq
decl_stmt|;
name|struct
name|bm_txsq
name|sc_txdirtyq
decl_stmt|;
name|bus_dma_tag_t
name|sc_rdma_tag
decl_stmt|;
name|struct
name|bm_rxsoft
name|sc_rxsoft
index|[
name|BM_MAX_TX_PACKETS
index|]
decl_stmt|;
name|int
name|next_rxdma_slot
decl_stmt|,
name|rxdma_loop_slot
decl_stmt|;
name|dbdma_channel_t
modifier|*
name|sc_txdma
decl_stmt|,
modifier|*
name|sc_rxdma
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bm_mii_frame
block|{
name|u_int8_t
name|mii_stdelim
decl_stmt|;
name|u_int8_t
name|mii_opcode
decl_stmt|;
name|u_int8_t
name|mii_phyaddr
decl_stmt|;
name|u_int8_t
name|mii_regaddr
decl_stmt|;
name|u_int8_t
name|mii_turnaround
decl_stmt|;
name|u_int16_t
name|mii_data
decl_stmt|;
block|}
struct|;
end_struct

end_unit

