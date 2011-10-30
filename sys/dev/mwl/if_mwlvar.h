begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2009 Sam Leffler, Errno Consulting  * Copyright (c) 2007-2009 Marvell Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for the Marvell 88W8363 Wireless LAN controller.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MWL_MVVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MWL_MVVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_radiotap.h>
end_include

begin_include
include|#
directive|include
file|<dev/mwl/mwlhal.h>
end_include

begin_include
include|#
directive|include
file|<dev/mwl/mwlreg.h>
end_include

begin_include
include|#
directive|include
file|<dev/mwl/if_mwlioctl.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MWL_TXBUF
end_ifndef

begin_define
define|#
directive|define
name|MWL_TXBUF
value|256
end_define

begin_comment
comment|/* number of TX descriptors/buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MWL_TXACKBUF
end_ifndef

begin_define
define|#
directive|define
name|MWL_TXACKBUF
value|(MWL_TXBUF/2)
end_define

begin_comment
comment|/* number of TX ACK desc's/buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MWL_RXDESC
end_ifndef

begin_define
define|#
directive|define
name|MWL_RXDESC
value|256
end_define

begin_comment
comment|/* number of RX descriptors */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MWL_RXBUF
end_ifndef

begin_define
define|#
directive|define
name|MWL_RXBUF
value|((5*MWL_RXDESC)/2)
end_define

begin_comment
comment|/* number of RX dma buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MWL_MAXBA
end_ifndef

begin_define
define|#
directive|define
name|MWL_MAXBA
value|2
end_define

begin_comment
comment|/* max BA streams/sta */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MWL_SGDMA_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|MWL_TXDESC
value|6
end_define

begin_comment
comment|/* max tx descriptors/segments */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MWL_TXDESC
value|1
end_define

begin_comment
comment|/* max tx descriptors/segments */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MWL_AGGR_SIZE
end_ifndef

begin_define
define|#
directive|define
name|MWL_AGGR_SIZE
value|3839
end_define

begin_comment
comment|/* max tx agregation size */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MWL_AGEINTERVAL
value|1
end_define

begin_comment
comment|/* poke f/w every sec to age q's */
end_comment

begin_define
define|#
directive|define
name|MWL_MAXSTAID
value|64
end_define

begin_comment
comment|/* max of 64 stations */
end_comment

begin_comment
comment|/*  * DMA state for tx/rx descriptors.  */
end_comment

begin_comment
comment|/*  * Software backed version of tx/rx descriptors.  We keep  * the software state out of the h/w descriptor structure  * so that may be allocated in uncached memory w/o paying  * performance hit.  */
end_comment

begin_struct
struct|struct
name|mwl_txbuf
block|{
name|STAILQ_ENTRY
argument_list|(
argument|mwl_txbuf
argument_list|)
name|bf_list
expr_stmt|;
name|void
modifier|*
name|bf_desc
decl_stmt|;
comment|/* h/w descriptor */
name|bus_addr_t
name|bf_daddr
decl_stmt|;
comment|/* physical addr of desc */
name|bus_dmamap_t
name|bf_dmamap
decl_stmt|;
comment|/* DMA map for descriptors */
name|int
name|bf_nseg
decl_stmt|;
name|bus_dma_segment_t
name|bf_segs
index|[
name|MWL_TXDESC
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|bf_m
decl_stmt|;
name|struct
name|ieee80211_node
modifier|*
name|bf_node
decl_stmt|;
name|struct
name|mwl_txq
modifier|*
name|bf_txq
decl_stmt|;
comment|/* backpointer to tx q/ring */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|mwl_txbuf
argument_list|)
name|mwl_txbufhead
expr_stmt|;
end_typedef

begin_comment
comment|/*  * Common "base class" for tx/rx descriptor resources  * allocated using the bus dma api.  */
end_comment

begin_struct
struct|struct
name|mwl_descdma
block|{
specifier|const
name|char
modifier|*
name|dd_name
decl_stmt|;
name|void
modifier|*
name|dd_desc
decl_stmt|;
comment|/* descriptors */
name|bus_addr_t
name|dd_desc_paddr
decl_stmt|;
comment|/* physical addr of dd_desc */
name|bus_size_t
name|dd_desc_len
decl_stmt|;
comment|/* size of dd_desc */
name|bus_dma_segment_t
name|dd_dseg
decl_stmt|;
name|int
name|dd_dnseg
decl_stmt|;
comment|/* number of segments */
name|bus_dma_tag_t
name|dd_dmat
decl_stmt|;
comment|/* bus DMA tag */
name|bus_dmamap_t
name|dd_dmamap
decl_stmt|;
comment|/* DMA map for descriptors */
name|void
modifier|*
name|dd_bufptr
decl_stmt|;
comment|/* associated buffers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * TX/RX ring definitions.  There are 4 tx rings, one  * per AC, and 1 rx ring.  Note carefully that transmit  * descriptors are treated as a contiguous chunk and the  * firmware pre-fetches descriptors.  This means that we  * must preserve order when moving descriptors between  * the active+free lists; otherwise we may stall transmit.  */
end_comment

begin_struct
struct|struct
name|mwl_txq
block|{
name|struct
name|mwl_descdma
name|dma
decl_stmt|;
comment|/* bus dma resources */
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/* tx q lock */
name|char
name|name
index|[
literal|12
index|]
decl_stmt|;
comment|/* e.g. "mwl0_txq4" */
name|int
name|qnum
decl_stmt|;
comment|/* f/w q number */
name|int
name|txpri
decl_stmt|;
comment|/* f/w tx priority */
name|int
name|nfree
decl_stmt|;
comment|/* # buffers on free list */
name|mwl_txbufhead
name|free
decl_stmt|;
comment|/* queue of free buffers */
name|mwl_txbufhead
name|active
decl_stmt|;
comment|/* queue of active buffers */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MWL_TXQ_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_tq
parameter_list|)
value|do { \ 	snprintf((_tq)->name, sizeof((_tq)->name), "%s_txq%u", \ 		device_get_nameunit((_sc)->sc_dev), (_tq)->qnum); \ 	mtx_init(&(_tq)->lock, (_tq)->name, NULL, MTX_DEF); \ } while (0)
end_define

begin_define
define|#
directive|define
name|MWL_TXQ_LOCK_DESTROY
parameter_list|(
name|_tq
parameter_list|)
value|mtx_destroy(&(_tq)->lock)
end_define

begin_define
define|#
directive|define
name|MWL_TXQ_LOCK
parameter_list|(
name|_tq
parameter_list|)
value|mtx_lock(&(_tq)->lock)
end_define

begin_define
define|#
directive|define
name|MWL_TXQ_UNLOCK
parameter_list|(
name|_tq
parameter_list|)
value|mtx_unlock(&(_tq)->lock)
end_define

begin_define
define|#
directive|define
name|MWL_TXQ_LOCK_ASSERT
parameter_list|(
name|_tq
parameter_list|)
value|mtx_assert(&(_tq)->lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|MWL_TXDESC_SYNC
parameter_list|(
name|txq
parameter_list|,
name|ds
parameter_list|,
name|how
parameter_list|)
value|do { \ 	bus_dmamap_sync((txq)->dma.dd_dmat, (txq)->dma.dd_dmamap, how); \ } while(0)
end_define

begin_comment
comment|/*  * RX dma buffers that are not in use are kept on a list.  */
end_comment

begin_struct
struct|struct
name|mwl_jumbo
block|{
name|SLIST_ENTRY
argument_list|(
argument|mwl_jumbo
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|mwl_jumbo
argument_list|)
name|mwl_jumbohead
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|MWL_JUMBO_DATA2BUF
parameter_list|(
name|_data
parameter_list|)
value|((struct mwl_jumbo *)(_data))
end_define

begin_define
define|#
directive|define
name|MWL_JUMBO_BUF2DATA
parameter_list|(
name|_buf
parameter_list|)
value|((uint8_t *)(_buf))
end_define

begin_define
define|#
directive|define
name|MWL_JUMBO_OFFSET
parameter_list|(
name|_sc
parameter_list|,
name|_data
parameter_list|)
define|\
value|(((const uint8_t *)(_data)) - (const uint8_t *)((_sc)->sc_rxmem))
end_define

begin_define
define|#
directive|define
name|MWL_JUMBO_DMA_ADDR
parameter_list|(
name|_sc
parameter_list|,
name|_data
parameter_list|)
define|\
value|((_sc)->sc_rxmem_paddr + MWL_JUMBO_OFFSET(_sc, _data))
end_define

begin_struct
struct|struct
name|mwl_rxbuf
block|{
name|STAILQ_ENTRY
argument_list|(
argument|mwl_rxbuf
argument_list|)
name|bf_list
expr_stmt|;
name|void
modifier|*
name|bf_desc
decl_stmt|;
comment|/* h/w descriptor */
name|bus_addr_t
name|bf_daddr
decl_stmt|;
comment|/* physical addr of desc */
name|uint8_t
modifier|*
name|bf_data
decl_stmt|;
comment|/* rx data area */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|mwl_rxbuf
argument_list|)
name|mwl_rxbufhead
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|MWL_RXDESC_SYNC
parameter_list|(
name|sc
parameter_list|,
name|ds
parameter_list|,
name|how
parameter_list|)
value|do { \ 	bus_dmamap_sync((sc)->sc_rxdma.dd_dmat, (sc)->sc_rxdma.dd_dmamap, how);\ } while (0)
end_define

begin_comment
comment|/*  * BA stream state.  One of these is setup for each stream  * allocated/created for use.  We pre-allocate the h/w stream  * before sending ADDBA request then complete the setup when  * get ADDBA response (success).  The completed state is setup  * to optimize the fast path in mwl_txstart--we precalculate  * the QoS control bits in the outbound frame and use those  * to identify which BA stream to use (assigning the h/w q to  * the TxPriority field of the descriptor).  *  * NB: Each station may have at most MWL_MAXBA streams at one time.    */
end_comment

begin_struct
struct|struct
name|mwl_bastate
block|{
name|uint16_t
name|qos
decl_stmt|;
comment|/* QoS ctl for BA stream */
name|uint8_t
name|txq
decl_stmt|;
comment|/* h/w q for BA stream */
specifier|const
name|MWL_HAL_BASTREAM
modifier|*
name|bastream
decl_stmt|;
comment|/* A-MPDU BA stream */
block|}
struct|;
end_struct

begin_function
specifier|static
name|__inline__
name|void
name|mwl_bastream_setup
parameter_list|(
name|struct
name|mwl_bastate
modifier|*
name|bas
parameter_list|,
name|int
name|ac
parameter_list|,
name|int
name|txq
parameter_list|)
block|{
name|bas
operator|->
name|txq
operator|=
name|txq
expr_stmt|;
name|bas
operator|->
name|qos
operator|=
name|htole16
argument_list|(
name|WME_AC_TO_TID
argument_list|(
name|ac
argument_list|)
operator||
name|IEEE80211_QOS_ACKPOLICY_BA
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|mwl_bastream_free
parameter_list|(
name|struct
name|mwl_bastate
modifier|*
name|bas
parameter_list|)
block|{
name|bas
operator|->
name|qos
operator|=
literal|0
expr_stmt|;
name|bas
operator|->
name|bastream
operator|=
name|NULL
expr_stmt|;
comment|/* NB: don't need to clear txq */
block|}
end_function

begin_comment
comment|/*  * Check the QoS control bits from an outbound frame against the  * value calculated when a BA stream is setup (above).  We need  * to match the TID and also the ACK policy so we only match AMPDU  * frames.  The bits from the frame are assumed in network byte  * order, hence the potential byte swap.  */
end_comment

begin_function
specifier|static
name|__inline__
name|int
name|mwl_bastream_match
parameter_list|(
specifier|const
name|struct
name|mwl_bastate
modifier|*
name|bas
parameter_list|,
name|uint16_t
name|qos
parameter_list|)
block|{
return|return
operator|(
name|qos
operator|&
name|htole16
argument_list|(
name|IEEE80211_QOS_TID
operator||
name|IEEE80211_QOS_ACKPOLICY
argument_list|)
operator|)
operator|==
name|bas
operator|->
name|qos
return|;
block|}
end_function

begin_comment
comment|/* driver-specific node state */
end_comment

begin_struct
struct|struct
name|mwl_node
block|{
name|struct
name|ieee80211_node
name|mn_node
decl_stmt|;
comment|/* base class */
name|struct
name|mwl_ant_info
name|mn_ai
decl_stmt|;
comment|/* antenna info */
name|uint32_t
name|mn_avgrssi
decl_stmt|;
comment|/* average rssi over all rx frames */
name|uint16_t
name|mn_staid
decl_stmt|;
comment|/* firmware station id */
name|struct
name|mwl_bastate
name|mn_ba
index|[
name|MWL_MAXBA
index|]
decl_stmt|;
name|struct
name|mwl_hal_vap
modifier|*
name|mn_hvap
decl_stmt|;
comment|/* hal vap handle */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MWL_NODE
parameter_list|(
name|ni
parameter_list|)
value|((struct mwl_node *)(ni))
end_define

begin_define
define|#
directive|define
name|MWL_NODE_CONST
parameter_list|(
name|ni
parameter_list|)
value|((const struct mwl_node *)(ni))
end_define

begin_comment
comment|/*  * Driver-specific vap state.  */
end_comment

begin_struct
struct|struct
name|mwl_vap
block|{
name|struct
name|ieee80211vap
name|mv_vap
decl_stmt|;
comment|/* base class */
name|struct
name|mwl_hal_vap
modifier|*
name|mv_hvap
decl_stmt|;
comment|/* hal vap handle */
name|struct
name|mwl_hal_vap
modifier|*
name|mv_ap_hvap
decl_stmt|;
comment|/* ap hal vap handle for wds */
name|uint16_t
name|mv_last_ps_sta
decl_stmt|;
comment|/* last count of ps sta's */
name|uint16_t
name|mv_eapolformat
decl_stmt|;
comment|/* fixed tx rate for EAPOL */
name|int
function_decl|(
modifier|*
name|mv_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|mv_set_tim
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MWL_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct mwl_vap *)(vap))
end_define

begin_define
define|#
directive|define
name|MWL_VAP_CONST
parameter_list|(
name|vap
parameter_list|)
value|((const struct mwl_vap *)(vap))
end_define

begin_struct
struct|struct
name|mwl_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
comment|/* interface common */
name|struct
name|mwl_stats
name|sc_stats
decl_stmt|;
comment|/* interface statistics */
name|int
name|sc_debug
decl_stmt|;
name|device_t
name|sc_dev
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* bus DMA tag */
name|bus_space_handle_t
name|sc_io0h
decl_stmt|;
comment|/* BAR 0 */
name|bus_space_tag_t
name|sc_io0t
decl_stmt|;
name|bus_space_handle_t
name|sc_io1h
decl_stmt|;
comment|/* BAR 1 */
name|bus_space_tag_t
name|sc_io1t
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* master lock (recursive) */
name|struct
name|taskqueue
modifier|*
name|sc_tq
decl_stmt|;
comment|/* private task queue */
name|struct
name|callout
name|sc_watchdog
decl_stmt|;
name|int
name|sc_tx_timer
decl_stmt|;
name|unsigned
name|int
name|sc_invalid
range|:
literal|1
decl_stmt|,
comment|/* disable hardware accesses */
name|sc_recvsetup
range|:
literal|1
decl_stmt|,
comment|/* recv setup */
name|sc_csapending
range|:
literal|1
decl_stmt|,
comment|/* 11h channel switch pending */
name|sc_radarena
range|:
literal|1
decl_stmt|,
comment|/* radar detection enabled */
name|sc_rxblocked
range|:
literal|1
decl_stmt|;
comment|/* rx waiting for dma buffers */
name|struct
name|mwl_hal
modifier|*
name|sc_mh
decl_stmt|;
comment|/* h/w access layer */
name|struct
name|mwl_hal_vap
modifier|*
name|sc_hvap
decl_stmt|;
comment|/* hal vap handle */
name|struct
name|mwl_hal_hwspec
name|sc_hwspecs
decl_stmt|;
comment|/* h/w capabilities */
name|uint32_t
name|sc_fwrelease
decl_stmt|;
comment|/* release # of loaded f/w */
name|struct
name|mwl_hal_txrxdma
name|sc_hwdma
decl_stmt|;
comment|/* h/w dma setup */
name|uint32_t
name|sc_imask
decl_stmt|;
comment|/* interrupt mask copy */
name|enum
name|ieee80211_phymode
name|sc_curmode
decl_stmt|;
name|u_int16_t
name|sc_curaid
decl_stmt|;
comment|/* current association id */
name|u_int8_t
name|sc_curbssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|MWL_HAL_CHANNEL
name|sc_curchan
decl_stmt|;
name|MWL_HAL_TXRATE_HANDLING
name|sc_txratehandling
decl_stmt|;
name|u_int16_t
name|sc_rxantenna
decl_stmt|;
comment|/* rx antenna */
name|u_int16_t
name|sc_txantenna
decl_stmt|;
comment|/* tx antenna */
name|uint8_t
name|sc_napvaps
decl_stmt|;
comment|/* # ap mode vaps */
name|uint8_t
name|sc_nwdsvaps
decl_stmt|;
comment|/* # wds mode vaps */
name|uint8_t
name|sc_nstavaps
decl_stmt|;
comment|/* # sta mode vaps */
name|uint8_t
name|sc_ndwdsvaps
decl_stmt|;
comment|/* # sta mode dwds vaps */
name|uint8_t
name|sc_nbssid0
decl_stmt|;
comment|/* # vap's using base mac */
name|uint32_t
name|sc_bssidmask
decl_stmt|;
comment|/* bssid mask */
name|void
function_decl|(
modifier|*
name|sc_recv_mgmt
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_newstate
function_decl|)
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|enum
name|ieee80211_state
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_node_cleanup
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_node_drain
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_recv_action
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_addba_request
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_tx_ampdu
modifier|*
parameter_list|,
name|int
name|dialogtoken
parameter_list|,
name|int
name|baparamset
parameter_list|,
name|int
name|batimeout
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sc_addba_response
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_tx_ampdu
modifier|*
parameter_list|,
name|int
name|status
parameter_list|,
name|int
name|baparamset
parameter_list|,
name|int
name|batimeout
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sc_addba_stop
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|ieee80211_tx_ampdu
modifier|*
parameter_list|)
function_decl|;
name|struct
name|mwl_descdma
name|sc_rxdma
decl_stmt|;
comment|/* rx bus dma resources */
name|mwl_rxbufhead
name|sc_rxbuf
decl_stmt|;
comment|/* rx buffers */
name|struct
name|mwl_rxbuf
modifier|*
name|sc_rxnext
decl_stmt|;
comment|/* next rx buffer to process */
name|struct
name|task
name|sc_rxtask
decl_stmt|;
comment|/* rx int processing */
name|void
modifier|*
name|sc_rxmem
decl_stmt|;
comment|/* rx dma buffer pool */
name|bus_dma_tag_t
name|sc_rxdmat
decl_stmt|;
comment|/* rx bus DMA tag */
name|bus_size_t
name|sc_rxmemsize
decl_stmt|;
comment|/* rx dma buffer pool size */
name|bus_dmamap_t
name|sc_rxmap
decl_stmt|;
comment|/* map for rx dma buffers */
name|bus_addr_t
name|sc_rxmem_paddr
decl_stmt|;
comment|/* physical addr of sc_rxmem */
name|mwl_jumbohead
name|sc_rxfree
decl_stmt|;
comment|/* list of free dma buffers */
name|int
name|sc_nrxfree
decl_stmt|;
comment|/* # buffers on rx free list */
name|struct
name|mtx
name|sc_rxlock
decl_stmt|;
comment|/* lock on sc_rxfree */
name|struct
name|mwl_txq
name|sc_txq
index|[
name|MWL_NUM_TX_QUEUES
index|]
decl_stmt|;
name|struct
name|mwl_txq
modifier|*
name|sc_ac2q
index|[
literal|5
index|]
decl_stmt|;
comment|/* WME AC -> h/w q map */
name|struct
name|mbuf
modifier|*
name|sc_aggrq
decl_stmt|;
comment|/* aggregation q */
name|struct
name|task
name|sc_txtask
decl_stmt|;
comment|/* tx int processing */
name|struct
name|task
name|sc_bawatchdogtask
decl_stmt|;
comment|/* BA watchdog processing */
name|struct
name|task
name|sc_radartask
decl_stmt|;
comment|/* radar detect processing */
name|struct
name|task
name|sc_chanswitchtask
decl_stmt|;
comment|/* chan switch processing */
name|uint8_t
name|sc_staid
index|[
name|MWL_MAXSTAID
operator|/
name|NBBY
index|]
decl_stmt|;
name|int
name|sc_ageinterval
decl_stmt|;
name|struct
name|callout
name|sc_timer
decl_stmt|;
comment|/* periodic work */
name|struct
name|mwl_tx_radiotap_header
name|sc_tx_th
decl_stmt|;
name|struct
name|mwl_rx_radiotap_header
name|sc_rx_th
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MWL_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&(_sc)->sc_mtx, device_get_nameunit((_sc)->sc_dev), \ 		 NULL, MTX_DEF | MTX_RECURSE)
end_define

begin_define
define|#
directive|define
name|MWL_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|MWL_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|MWL_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|MWL_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|MWL_RXFREE_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&(_sc)->sc_rxlock, device_get_nameunit((_sc)->sc_dev), \ 		 NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|MWL_RXFREE_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_rxlock)
end_define

begin_define
define|#
directive|define
name|MWL_RXFREE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_rxlock)
end_define

begin_define
define|#
directive|define
name|MWL_RXFREE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_rxlock)
end_define

begin_define
define|#
directive|define
name|MWL_RXFREE_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_rxlock, MA_OWNED)
end_define

begin_function_decl
name|int
name|mwl_attach
parameter_list|(
name|u_int16_t
parameter_list|,
name|struct
name|mwl_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mwl_detach
parameter_list|(
name|struct
name|mwl_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mwl_resume
parameter_list|(
name|struct
name|mwl_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mwl_suspend
parameter_list|(
name|struct
name|mwl_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mwl_shutdown
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mwl_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MWL_MVVAR_H */
end_comment

end_unit

