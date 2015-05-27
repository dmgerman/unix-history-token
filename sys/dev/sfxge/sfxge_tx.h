begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Solarflare Communications, Inc.  * All rights reserved.  *  * This software was developed in part by Philip Paeps under contract for  * Solarflare Communications, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SFXGE_TX_H
end_ifndef

begin_define
define|#
directive|define
name|_SFXGE_TX_H
end_define

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_comment
comment|/* Maximum size of TSO packet */
end_comment

begin_define
define|#
directive|define
name|SFXGE_TSO_MAX_SIZE
value|(65535)
end_define

begin_comment
comment|/*  * Maximum number of segments to be created for a TSO packet.  * Allow for a reasonable minimum MSS of 512.  */
end_comment

begin_define
define|#
directive|define
name|SFXGE_TSO_MAX_SEGS
value|howmany(SFXGE_TSO_MAX_SIZE, 512)
end_define

begin_comment
comment|/* Maximum number of DMA segments needed to map an mbuf chain.  With  * TSO, the mbuf length may be just over 64K, divided into 2K mbuf  * clusters.  (The chain could be longer than this initially, but can  * be shortened with m_collapse().)  */
end_comment

begin_define
define|#
directive|define
name|SFXGE_TX_MAPPING_MAX_SEG
define|\
value|(1 + howmany(SFXGE_TSO_MAX_SIZE, MCLBYTES))
end_define

begin_comment
comment|/*  * Buffer mapping flags.  *  * Buffers and DMA mappings must be freed when the last descriptor  * referring to them is completed.  Set the TX_BUF_UNMAP and  * TX_BUF_MBUF flags on the last descriptor generated for an mbuf  * chain.  Set only the TX_BUF_UNMAP flag on a descriptor referring to  * a heap buffer.  */
end_comment

begin_enum
enum|enum
name|sfxge_tx_buf_flags
block|{
name|TX_BUF_UNMAP
init|=
literal|1
block|,
name|TX_BUF_MBUF
init|=
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Buffer mapping information for descriptors in flight.  */
end_comment

begin_struct
struct|struct
name|sfxge_tx_mapping
block|{
union|union
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
name|caddr_t
name|heap_buf
decl_stmt|;
block|}
name|u
union|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|enum
name|sfxge_tx_buf_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SFXGE_TX_DPL_GET_PKT_LIMIT_DEFAULT
value|(64 * 1024)
end_define

begin_define
define|#
directive|define
name|SFXGE_TX_DPL_GET_NON_TCP_PKT_LIMIT_DEFAULT
value|1024
end_define

begin_define
define|#
directive|define
name|SFXGE_TX_DPL_PUT_PKT_LIMIT_DEFAULT
value|1024
end_define

begin_comment
comment|/*  * Deferred packet list.  */
end_comment

begin_struct
struct|struct
name|sfxge_tx_dpl
block|{
name|unsigned
name|int
name|std_get_max
decl_stmt|;
comment|/* Maximum number  of packets 						 * in get list */
name|unsigned
name|int
name|std_get_non_tcp_max
decl_stmt|;
comment|/* Maximum number 						 * of non-TCP packets 						 * in get list */
name|unsigned
name|int
name|std_put_max
decl_stmt|;
comment|/* Maximum number of packets 						 * in put list */
name|uintptr_t
name|std_put
decl_stmt|;
comment|/* Head of put list. */
name|struct
name|mbuf
modifier|*
name|std_get
decl_stmt|;
comment|/* Head of get list. */
name|struct
name|mbuf
modifier|*
modifier|*
name|std_getp
decl_stmt|;
comment|/* Tail of get list. */
name|unsigned
name|int
name|std_get_count
decl_stmt|;
comment|/* Packets in get list. */
name|unsigned
name|int
name|std_get_non_tcp_count
decl_stmt|;
comment|/* Non-TCP packets 						 * in get list */
name|unsigned
name|int
name|std_get_hiwat
decl_stmt|;
comment|/* Packets in get list 						 * high watermark */
name|unsigned
name|int
name|std_put_hiwat
decl_stmt|;
comment|/* Packets in put list 						 * high watermark */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SFXGE_TX_BUFFER_SIZE
value|0x400
end_define

begin_define
define|#
directive|define
name|SFXGE_TX_HEADER_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|SFXGE_TX_COPY_THRESHOLD
value|0x200
end_define

begin_enum
enum|enum
name|sfxge_txq_state
block|{
name|SFXGE_TXQ_UNINITIALIZED
init|=
literal|0
block|,
name|SFXGE_TXQ_INITIALIZED
block|,
name|SFXGE_TXQ_STARTED
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sfxge_txq_type
block|{
name|SFXGE_TXQ_NON_CKSUM
init|=
literal|0
block|,
name|SFXGE_TXQ_IP_CKSUM
block|,
name|SFXGE_TXQ_IP_TCP_UDP_CKSUM
block|,
name|SFXGE_TXQ_NTYPES
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SFXGE_TXQ_UNBLOCK_LEVEL
parameter_list|(
name|_entries
parameter_list|)
value|(EFX_TXQ_LIMIT(_entries) / 4)
end_define

begin_define
define|#
directive|define
name|SFXGE_TX_BATCH
value|64
end_define

begin_define
define|#
directive|define
name|SFXGE_TXQ_LOCK_INIT
parameter_list|(
name|_txq
parameter_list|,
name|_ifname
parameter_list|,
name|_txq_index
parameter_list|)
define|\
value|do {								\ 		struct sfxge_txq  *__txq = (_txq);			\ 									\ 		snprintf((__txq)->lock_name,				\ 			 sizeof((__txq)->lock_name),			\ 			 "%s:txq%u", (_ifname), (_txq_index));		\ 		mtx_init(&(__txq)->lock, (__txq)->lock_name,		\ 			 NULL, MTX_DEF);				\ 	} while (B_FALSE)
end_define

begin_define
define|#
directive|define
name|SFXGE_TXQ_LOCK_DESTROY
parameter_list|(
name|_txq
parameter_list|)
define|\
value|mtx_destroy(&(_txq)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_TXQ_LOCK
parameter_list|(
name|_txq
parameter_list|)
define|\
value|mtx_lock(&(_txq)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_TXQ_TRYLOCK
parameter_list|(
name|_txq
parameter_list|)
define|\
value|mtx_trylock(&(_txq)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_TXQ_UNLOCK
parameter_list|(
name|_txq
parameter_list|)
define|\
value|mtx_unlock(&(_txq)->lock)
end_define

begin_define
define|#
directive|define
name|SFXGE_TXQ_LOCK_ASSERT_OWNED
parameter_list|(
name|_txq
parameter_list|)
define|\
value|mtx_assert(&(_txq)->lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|SFXGE_TXQ_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|_txq
parameter_list|)
define|\
value|mtx_assert(&(_txq)->lock, MA_NOTOWNED)
end_define

begin_struct
struct|struct
name|sfxge_txq
block|{
comment|/* The following fields should be written very rarely */
name|struct
name|sfxge_softc
modifier|*
name|sc
decl_stmt|;
name|enum
name|sfxge_txq_state
name|init_state
decl_stmt|;
name|enum
name|sfxge_flush_state
name|flush_state
decl_stmt|;
name|enum
name|sfxge_txq_type
name|type
decl_stmt|;
name|unsigned
name|int
name|txq_index
decl_stmt|;
name|unsigned
name|int
name|evq_index
decl_stmt|;
name|efsys_mem_t
name|mem
decl_stmt|;
name|unsigned
name|int
name|buf_base_id
decl_stmt|;
name|unsigned
name|int
name|entries
decl_stmt|;
name|unsigned
name|int
name|ptr_mask
decl_stmt|;
name|struct
name|sfxge_tx_mapping
modifier|*
name|stmp
decl_stmt|;
comment|/* Packets in flight. */
name|bus_dma_tag_t
name|packet_dma_tag
decl_stmt|;
name|efx_buffer_t
modifier|*
name|pend_desc
decl_stmt|;
name|efx_txq_t
modifier|*
name|common
decl_stmt|;
name|efsys_mem_t
modifier|*
name|tsoh_buffer
decl_stmt|;
name|char
name|lock_name
index|[
name|SFXGE_LOCK_NAME_MAX
index|]
decl_stmt|;
comment|/* This field changes more often and is read regularly on both 	 * the initiation and completion paths 	 */
name|int
name|blocked
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
comment|/* The following fields change more often, and are used mostly 	 * on the initiation path 	 */
name|struct
name|mtx
name|lock
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
name|struct
name|sfxge_tx_dpl
name|dpl
decl_stmt|;
comment|/* Deferred packet list. */
name|unsigned
name|int
name|n_pend_desc
decl_stmt|;
name|unsigned
name|int
name|added
decl_stmt|;
name|unsigned
name|int
name|reaped
decl_stmt|;
comment|/* Statistics */
name|unsigned
name|long
name|tso_bursts
decl_stmt|;
name|unsigned
name|long
name|tso_packets
decl_stmt|;
name|unsigned
name|long
name|tso_long_headers
decl_stmt|;
name|unsigned
name|long
name|collapses
decl_stmt|;
name|unsigned
name|long
name|drops
decl_stmt|;
name|unsigned
name|long
name|get_overflow
decl_stmt|;
name|unsigned
name|long
name|get_non_tcp_overflow
decl_stmt|;
name|unsigned
name|long
name|put_overflow
decl_stmt|;
name|unsigned
name|long
name|netdown_drops
decl_stmt|;
name|unsigned
name|long
name|tso_pdrop_too_many
decl_stmt|;
name|unsigned
name|long
name|tso_pdrop_no_rsrc
decl_stmt|;
comment|/* The following fields change more often, and are used mostly 	 * on the completion path 	 */
name|unsigned
name|int
name|pending
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
name|unsigned
name|int
name|completed
decl_stmt|;
name|struct
name|sfxge_txq
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|sfxge_evq
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_tx_packet_add
parameter_list|(
name|struct
name|sfxge_txq
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|sfxge_tx_get_drops
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_tx_init
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_tx_fini
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_tx_start
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_tx_stop
parameter_list|(
name|struct
name|sfxge_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_tx_qcomplete
parameter_list|(
name|struct
name|sfxge_txq
modifier|*
name|txq
parameter_list|,
name|struct
name|sfxge_evq
modifier|*
name|evq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_tx_qflush_done
parameter_list|(
name|struct
name|sfxge_txq
modifier|*
name|txq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sfxge_if_qflush
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sfxge_if_transmit
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

