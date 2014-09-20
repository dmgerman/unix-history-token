begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Defintions for the Atheros Wireless LAN controller driver.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_ATHVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_ATHVAR_H
end_define

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/ath_hal/ah_desc.h>
end_include

begin_include
include|#
directive|include
file|<net80211/ieee80211_radiotap.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_athioctl.h>
end_include

begin_include
include|#
directive|include
file|<dev/ath/if_athrate.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_DEBUG_ALQ
end_ifdef

begin_include
include|#
directive|include
file|<dev/ath/if_ath_alq.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATH_TIMEOUT
value|1000
end_define

begin_comment
comment|/*  * There is a separate TX ath_buf pool for management frames.  * This ensures that management frames such as probe responses  * and BAR frames can be transmitted during periods of high  * TX activity.  */
end_comment

begin_define
define|#
directive|define
name|ATH_MGMT_TXBUF
value|32
end_define

begin_comment
comment|/*  * 802.11n requires more TX and RX buffers to do AMPDU.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_ENABLE_11N
end_ifdef

begin_define
define|#
directive|define
name|ATH_TXBUF
value|512
end_define

begin_define
define|#
directive|define
name|ATH_RXBUF
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATH_RXBUF
end_ifndef

begin_define
define|#
directive|define
name|ATH_RXBUF
value|40
end_define

begin_comment
comment|/* number of RX buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ATH_TXBUF
end_ifndef

begin_define
define|#
directive|define
name|ATH_TXBUF
value|200
end_define

begin_comment
comment|/* number of TX buffers */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATH_BCBUF
value|4
end_define

begin_comment
comment|/* number of beacon buffers */
end_comment

begin_define
define|#
directive|define
name|ATH_TXDESC
value|10
end_define

begin_comment
comment|/* number of descriptors per buffer */
end_comment

begin_define
define|#
directive|define
name|ATH_TXMAXTRY
value|11
end_define

begin_comment
comment|/* max number of transmit attempts */
end_comment

begin_define
define|#
directive|define
name|ATH_TXMGTTRY
value|4
end_define

begin_comment
comment|/* xmit attempts for mgt/ctl frames */
end_comment

begin_define
define|#
directive|define
name|ATH_TXINTR_PERIOD
value|5
end_define

begin_comment
comment|/* max number of batched tx descriptors */
end_comment

begin_define
define|#
directive|define
name|ATH_BEACON_AIFS_DEFAULT
value|1
end_define

begin_comment
comment|/* default aifs for ap beacon q */
end_comment

begin_define
define|#
directive|define
name|ATH_BEACON_CWMIN_DEFAULT
value|0
end_define

begin_comment
comment|/* default cwmin for ap beacon q */
end_comment

begin_define
define|#
directive|define
name|ATH_BEACON_CWMAX_DEFAULT
value|0
end_define

begin_comment
comment|/* default cwmax for ap beacon q */
end_comment

begin_comment
comment|/*  * The key cache is used for h/w cipher state and also for  * tracking station state such as the current tx antenna.  * We also setup a mapping table between key cache slot indices  * and station state to short-circuit node lookups on rx.  * Different parts have different size key caches.  We handle  * up to ATH_KEYMAX entries (could dynamically allocate state).  */
end_comment

begin_define
define|#
directive|define
name|ATH_KEYMAX
value|128
end_define

begin_comment
comment|/* max key cache size we handle */
end_comment

begin_define
define|#
directive|define
name|ATH_KEYBYTES
value|(ATH_KEYMAX/NBBY)
end_define

begin_comment
comment|/* storage space in bytes */
end_comment

begin_struct_decl
struct_decl|struct
name|taskqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kthread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_buf
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|ATH_TID_MAX_BUFS
value|(2 * IEEE80211_AGGR_BAWMAX)
end_define

begin_comment
comment|/*  * Per-TID state  *  * Note that TID 16 (WME_NUM_TID+1) is for handling non-QoS frames.  */
end_comment

begin_struct
struct|struct
name|ath_tid
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ath_buf
argument_list|)
name|tid_q
expr_stmt|;
comment|/* pending buffers */
name|struct
name|ath_node
modifier|*
name|an
decl_stmt|;
comment|/* pointer to parent */
name|int
name|tid
decl_stmt|;
comment|/* tid */
name|int
name|ac
decl_stmt|;
comment|/* which AC gets this trafic */
name|int
name|hwq_depth
decl_stmt|;
comment|/* how many buffers are on HW */
name|u_int
name|axq_depth
decl_stmt|;
comment|/* SW queue depth */
struct|struct
block|{
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ath_buf
argument_list|)
name|tid_q
expr_stmt|;
comment|/* filtered queue */
name|u_int
name|axq_depth
decl_stmt|;
comment|/* SW queue depth */
block|}
name|filtq
struct|;
comment|/* 	 * Entry on the ath_txq; when there's traffic 	 * to send 	 */
name|TAILQ_ENTRY
argument_list|(
argument|ath_tid
argument_list|)
name|axq_qelem
expr_stmt|;
name|int
name|sched
decl_stmt|;
name|int
name|paused
decl_stmt|;
comment|/*>0 if the TID has been paused */
comment|/* 	 * These are flags - perhaps later collapse 	 * down to a single uint32_t ? 	 */
name|int
name|addba_tx_pending
decl_stmt|;
comment|/* TX ADDBA pending */
name|int
name|bar_wait
decl_stmt|;
comment|/* waiting for BAR */
name|int
name|bar_tx
decl_stmt|;
comment|/* BAR TXed */
name|int
name|isfiltered
decl_stmt|;
comment|/* is this node currently filtered */
comment|/* 	 * Is the TID being cleaned up after a transition 	 * from aggregation to non-aggregation? 	 * When this is set to 1, this TID will be paused 	 * and no further traffic will be queued until all 	 * the hardware packets pending for this TID have been 	 * TXed/completed; at which point (non-aggregation) 	 * traffic will resume being TXed. 	 */
name|int
name|cleanup_inprogress
decl_stmt|;
comment|/* 	 * How many hardware-queued packets are 	 * waiting to be cleaned up. 	 * This is only valid if cleanup_inprogress is 1. 	 */
name|int
name|incomp
decl_stmt|;
comment|/* 	 * The following implements a ring representing 	 * the frames in the current BAW. 	 * To avoid copying the array content each time 	 * the BAW is moved, the baw_head/baw_tail point 	 * to the current BAW begin/end; when the BAW is 	 * shifted the head/tail of the array are also 	 * appropriately shifted. 	 */
comment|/* active tx buffers, beginning at current BAW */
name|struct
name|ath_buf
modifier|*
name|tx_buf
index|[
name|ATH_TID_MAX_BUFS
index|]
decl_stmt|;
comment|/* where the baw head is in the array */
name|int
name|baw_head
decl_stmt|;
comment|/* where the BAW tail is in the array */
name|int
name|baw_tail
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* driver-specific node state */
end_comment

begin_struct
struct|struct
name|ath_node
block|{
name|struct
name|ieee80211_node
name|an_node
decl_stmt|;
comment|/* base class */
name|u_int8_t
name|an_mgmtrix
decl_stmt|;
comment|/* min h/w rate index */
name|u_int8_t
name|an_mcastrix
decl_stmt|;
comment|/* mcast h/w rate index */
name|uint32_t
name|an_is_powersave
decl_stmt|;
comment|/* node is sleeping */
name|uint32_t
name|an_stack_psq
decl_stmt|;
comment|/* net80211 psq isn't empty */
name|uint32_t
name|an_tim_set
decl_stmt|;
comment|/* TIM has been set */
name|struct
name|ath_buf
modifier|*
name|an_ff_buf
index|[
name|WME_NUM_AC
index|]
decl_stmt|;
comment|/* ff staging area */
name|struct
name|ath_tid
name|an_tid
index|[
name|IEEE80211_TID_SIZE
index|]
decl_stmt|;
comment|/* per-TID state */
name|char
name|an_name
index|[
literal|32
index|]
decl_stmt|;
comment|/* eg "wlan0_a1" */
name|struct
name|mtx
name|an_mtx
decl_stmt|;
comment|/* protecting the rate control state */
name|uint32_t
name|an_swq_depth
decl_stmt|;
comment|/* how many SWQ packets for this 					   node */
name|int
name|clrdmask
decl_stmt|;
comment|/* has clrdmask been set */
name|uint32_t
name|an_leak_count
decl_stmt|;
comment|/* How many frames to leak during pause */
comment|/* variable-length rate control state follows */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_NODE
parameter_list|(
name|ni
parameter_list|)
value|((struct ath_node *)(ni))
end_define

begin_define
define|#
directive|define
name|ATH_NODE_CONST
parameter_list|(
name|ni
parameter_list|)
value|((const struct ath_node *)(ni))
end_define

begin_define
define|#
directive|define
name|ATH_RSSI_LPF_LEN
value|10
end_define

begin_define
define|#
directive|define
name|ATH_RSSI_DUMMY_MARKER
value|0x127
end_define

begin_define
define|#
directive|define
name|ATH_EP_MUL
parameter_list|(
name|x
parameter_list|,
name|mul
parameter_list|)
value|((x) * (mul))
end_define

begin_define
define|#
directive|define
name|ATH_RSSI_IN
parameter_list|(
name|x
parameter_list|)
value|(ATH_EP_MUL((x), HAL_RSSI_EP_MULTIPLIER))
end_define

begin_define
define|#
directive|define
name|ATH_LPF_RSSI
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|len
parameter_list|)
define|\
value|((x != ATH_RSSI_DUMMY_MARKER) ? (((x) * ((len) - 1) + (y)) / (len)) : (y))
end_define

begin_define
define|#
directive|define
name|ATH_RSSI_LPF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do {						\     if ((y)>= -20)							\     	x = ATH_LPF_RSSI((x), ATH_RSSI_IN((y)), ATH_RSSI_LPF_LEN);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_EP_RND
parameter_list|(
name|x
parameter_list|,
name|mul
parameter_list|)
define|\
value|((((x)%(mul))>= ((mul)/2)) ? ((x) + ((mul) - 1)) / (mul) : (x)/(mul))
end_define

begin_define
define|#
directive|define
name|ATH_RSSI
parameter_list|(
name|x
parameter_list|)
value|ATH_EP_RND(x, HAL_RSSI_EP_MULTIPLIER)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|ATH_BUFTYPE_NORMAL
init|=
literal|0
block|,
name|ATH_BUFTYPE_MGMT
init|=
literal|1
block|, }
name|ath_buf_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|ath_buf
block|{
name|TAILQ_ENTRY
argument_list|(
argument|ath_buf
argument_list|)
name|bf_list
expr_stmt|;
name|struct
name|ath_buf
modifier|*
name|bf_next
decl_stmt|;
comment|/* next buffer in the aggregate */
name|int
name|bf_nseg
decl_stmt|;
name|HAL_STATUS
name|bf_rxstatus
decl_stmt|;
name|uint16_t
name|bf_flags
decl_stmt|;
comment|/* status flags (below) */
name|uint16_t
name|bf_descid
decl_stmt|;
comment|/* 16 bit descriptor ID */
name|struct
name|ath_desc
modifier|*
name|bf_desc
decl_stmt|;
comment|/* virtual addr of desc */
name|struct
name|ath_desc_status
name|bf_status
decl_stmt|;
comment|/* tx/rx status */
name|bus_addr_t
name|bf_daddr
decl_stmt|;
comment|/* physical addr of desc */
name|bus_dmamap_t
name|bf_dmamap
decl_stmt|;
comment|/* DMA map for mbuf chain */
name|struct
name|mbuf
modifier|*
name|bf_m
decl_stmt|;
comment|/* mbuf for buf */
name|struct
name|ieee80211_node
modifier|*
name|bf_node
decl_stmt|;
comment|/* pointer to the node */
name|struct
name|ath_desc
modifier|*
name|bf_lastds
decl_stmt|;
comment|/* last descriptor for comp status */
name|struct
name|ath_buf
modifier|*
name|bf_last
decl_stmt|;
comment|/* last buffer in aggregate, or self for non-aggregate */
name|bus_size_t
name|bf_mapsize
decl_stmt|;
define|#
directive|define
name|ATH_MAX_SCATTER
value|ATH_TXDESC
comment|/* max(tx,rx,beacon) desc's */
name|bus_dma_segment_t
name|bf_segs
index|[
name|ATH_MAX_SCATTER
index|]
decl_stmt|;
name|uint32_t
name|bf_nextfraglen
decl_stmt|;
comment|/* length of next fragment */
comment|/* Completion function to call on TX complete (fail or not) */
comment|/* 	 * "fail" here is set to 1 if the queue entries were removed 	 * through a call to ath_tx_draintxq(). 	 */
name|void
function_decl|(
modifier|*
name|bf_comp
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|,
name|int
name|fail
parameter_list|)
function_decl|;
comment|/* This state is kept to support software retries and aggregation */
struct|struct
block|{
name|uint16_t
name|bfs_seqno
decl_stmt|;
comment|/* sequence number of this packet */
name|uint16_t
name|bfs_ndelim
decl_stmt|;
comment|/* number of delims for padding */
name|uint8_t
name|bfs_retries
decl_stmt|;
comment|/* retry count */
name|uint8_t
name|bfs_tid
decl_stmt|;
comment|/* packet TID (or TID_MAX for no QoS) */
name|uint8_t
name|bfs_nframes
decl_stmt|;
comment|/* number of frames in aggregate */
name|uint8_t
name|bfs_pri
decl_stmt|;
comment|/* packet AC priority */
name|uint8_t
name|bfs_tx_queue
decl_stmt|;
comment|/* destination hardware TX queue */
name|u_int32_t
name|bfs_aggr
range|:
literal|1
decl_stmt|,
comment|/* part of aggregate? */
name|bfs_aggrburst
range|:
literal|1
decl_stmt|,
comment|/* part of aggregate burst? */
name|bfs_isretried
range|:
literal|1
decl_stmt|,
comment|/* retried frame? */
name|bfs_dobaw
range|:
literal|1
decl_stmt|,
comment|/* actually check against BAW? */
name|bfs_addedbaw
range|:
literal|1
decl_stmt|,
comment|/* has been added to the BAW */
name|bfs_shpream
range|:
literal|1
decl_stmt|,
comment|/* use short preamble */
name|bfs_istxfrag
range|:
literal|1
decl_stmt|,
comment|/* is fragmented */
name|bfs_ismrr
range|:
literal|1
decl_stmt|,
comment|/* do multi-rate TX retry */
name|bfs_doprot
range|:
literal|1
decl_stmt|,
comment|/* do RTS/CTS based protection */
name|bfs_doratelookup
range|:
literal|1
decl_stmt|;
comment|/* do rate lookup before each TX */
comment|/* 		 * These fields are passed into the 		 * descriptor setup functions. 		 */
comment|/* Make this an 8 bit value? */
name|HAL_PKT_TYPE
name|bfs_atype
decl_stmt|;
comment|/* packet type */
name|uint32_t
name|bfs_pktlen
decl_stmt|;
comment|/* length of this packet */
name|uint16_t
name|bfs_hdrlen
decl_stmt|;
comment|/* length of this packet header */
name|uint16_t
name|bfs_al
decl_stmt|;
comment|/* length of aggregate */
name|uint16_t
name|bfs_txflags
decl_stmt|;
comment|/* HAL (tx) descriptor flags */
name|uint8_t
name|bfs_txrate0
decl_stmt|;
comment|/* first TX rate */
name|uint8_t
name|bfs_try0
decl_stmt|;
comment|/* first try count */
name|uint16_t
name|bfs_txpower
decl_stmt|;
comment|/* tx power */
name|uint8_t
name|bfs_ctsrate0
decl_stmt|;
comment|/* Non-zero - use this as ctsrate */
name|uint8_t
name|bfs_ctsrate
decl_stmt|;
comment|/* CTS rate */
comment|/* 16 bit? */
name|int32_t
name|bfs_keyix
decl_stmt|;
comment|/* crypto key index */
name|int32_t
name|bfs_txantenna
decl_stmt|;
comment|/* TX antenna config */
comment|/* Make this an 8 bit value? */
name|enum
name|ieee80211_protmode
name|bfs_protmode
decl_stmt|;
comment|/* 16 bit? */
name|uint32_t
name|bfs_ctsduration
decl_stmt|;
comment|/* CTS duration (pre-11n NICs) */
name|struct
name|ath_rc_series
name|bfs_rc
index|[
name|ATH_RC_NUM
index|]
decl_stmt|;
comment|/* non-11n TX series */
block|}
name|bf_state
struct|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|ath_bufhead_s
argument_list|,
argument|ath_buf
argument_list|)
name|ath_bufhead
expr_stmt|;
end_typedef

begin_define
define|#
directive|define
name|ATH_BUF_MGMT
value|0x00000001
end_define

begin_comment
comment|/* (tx) desc is a mgmt desc */
end_comment

begin_define
define|#
directive|define
name|ATH_BUF_BUSY
value|0x00000002
end_define

begin_comment
comment|/* (tx) desc owned by h/w */
end_comment

begin_define
define|#
directive|define
name|ATH_BUF_FIFOEND
value|0x00000004
end_define

begin_define
define|#
directive|define
name|ATH_BUF_FIFOPTR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|ATH_BUF_FLAGS_CLONE
value|(ATH_BUF_MGMT)
end_define

begin_comment
comment|/*  * DMA state for tx/rx descriptors.  */
end_comment

begin_struct
struct|struct
name|ath_descdma
block|{
specifier|const
name|char
modifier|*
name|dd_name
decl_stmt|;
name|struct
name|ath_desc
modifier|*
name|dd_desc
decl_stmt|;
comment|/* descriptors */
name|int
name|dd_descsize
decl_stmt|;
comment|/* size of single descriptor */
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
name|bus_dma_tag_t
name|dd_dmat
decl_stmt|;
comment|/* bus DMA tag */
name|bus_dmamap_t
name|dd_dmamap
decl_stmt|;
comment|/* DMA map for descriptors */
name|struct
name|ath_buf
modifier|*
name|dd_bufptr
decl_stmt|;
comment|/* associated buffers */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Data transmit queue state.  One of these exists for each  * hardware transmit queue.  Packets sent to us from above  * are assigned to queues based on their priority.  Not all  * devices support a complete set of hardware transmit queues.  * For those devices the array sc_ac2q will map multiple  * priorities to fewer hardware queues (typically all to one  * hardware queue).  */
end_comment

begin_struct
struct|struct
name|ath_txq
block|{
name|struct
name|ath_softc
modifier|*
name|axq_softc
decl_stmt|;
comment|/* Needed for scheduling */
name|u_int
name|axq_qnum
decl_stmt|;
comment|/* hardware q number */
define|#
directive|define
name|ATH_TXQ_SWQ
value|(HAL_NUM_TX_QUEUES+1)
comment|/* qnum for s/w only queue */
name|u_int
name|axq_ac
decl_stmt|;
comment|/* WME AC */
name|u_int
name|axq_flags
decl_stmt|;
comment|//#define	ATH_TXQ_PUTPENDING	0x0001		/* ath_hal_puttxbuf pending */
define|#
directive|define
name|ATH_TXQ_PUTRUNNING
value|0x0002
comment|/* ath_hal_puttxbuf has been called */
name|u_int
name|axq_depth
decl_stmt|;
comment|/* queue depth (stat only) */
name|u_int
name|axq_aggr_depth
decl_stmt|;
comment|/* how many aggregates are queued */
name|u_int
name|axq_intrcnt
decl_stmt|;
comment|/* interrupt count */
name|u_int32_t
modifier|*
name|axq_link
decl_stmt|;
comment|/* link ptr in last TX desc */
name|TAILQ_HEAD
argument_list|(
argument|axq_q_s
argument_list|,
argument|ath_buf
argument_list|)
name|axq_q
expr_stmt|;
comment|/* transmit queue */
name|struct
name|mtx
name|axq_lock
decl_stmt|;
comment|/* lock on q and link */
comment|/* 	 * This is the FIFO staging buffer when doing EDMA. 	 * 	 * For legacy chips, we just push the head pointer to 	 * the hardware and we ignore this list. 	 * 	 * For EDMA, the staging buffer is treated as normal; 	 * when it's time to push a list of frames to the hardware 	 * we move that list here and we stamp buffers with 	 * flags to identify the beginning/end of that particular 	 * FIFO entry. 	 */
struct|struct
block|{
name|TAILQ_HEAD
argument_list|(
argument|axq_q_f_s
argument_list|,
argument|ath_buf
argument_list|)
name|axq_q
expr_stmt|;
name|u_int
name|axq_depth
decl_stmt|;
block|}
name|fifo
struct|;
name|u_int
name|axq_fifo_depth
decl_stmt|;
comment|/* depth of FIFO frames */
comment|/* 	 * XXX the holdingbf field is protected by the TXBUF lock 	 * for now, NOT the TXQ lock. 	 * 	 * Architecturally, it would likely be better to move 	 * the holdingbf field to a separate array in ath_softc 	 * just to highlight that it's not protected by the normal 	 * TX path lock. 	 */
name|struct
name|ath_buf
modifier|*
name|axq_holdingbf
decl_stmt|;
comment|/* holding TX buffer */
name|char
name|axq_name
index|[
literal|12
index|]
decl_stmt|;
comment|/* e.g. "ath0_txq4" */
comment|/* Per-TID traffic queue for software -> hardware TX */
comment|/* 	 * This is protected by the general TX path lock, not (for now) 	 * by the TXQ lock. 	 */
name|TAILQ_HEAD
argument_list|(
argument|axq_t_s
argument_list|,
argument|ath_tid
argument_list|)
name|axq_tidq
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_TXQ_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_tq
parameter_list|)
value|do { \ 	    snprintf((_tq)->axq_name, sizeof((_tq)->axq_name), "%s_txq%u", \ 	      device_get_nameunit((_sc)->sc_dev), (_tq)->axq_qnum); \ 	    mtx_init(&(_tq)->axq_lock, (_tq)->axq_name, NULL, MTX_DEF); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_LOCK_DESTROY
parameter_list|(
name|_tq
parameter_list|)
value|mtx_destroy(&(_tq)->axq_lock)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_LOCK
parameter_list|(
name|_tq
parameter_list|)
value|mtx_lock(&(_tq)->axq_lock)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_UNLOCK
parameter_list|(
name|_tq
parameter_list|)
value|mtx_unlock(&(_tq)->axq_lock)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_LOCK_ASSERT
parameter_list|(
name|_tq
parameter_list|)
value|mtx_assert(&(_tq)->axq_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_UNLOCK_ASSERT
parameter_list|(
name|_tq
parameter_list|)
value|mtx_assert(&(_tq)->axq_lock,	\ 					    MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|ATH_NODE_LOCK
parameter_list|(
name|_an
parameter_list|)
value|mtx_lock(&(_an)->an_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_NODE_UNLOCK
parameter_list|(
name|_an
parameter_list|)
value|mtx_unlock(&(_an)->an_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_NODE_LOCK_ASSERT
parameter_list|(
name|_an
parameter_list|)
value|mtx_assert(&(_an)->an_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ATH_NODE_UNLOCK_ASSERT
parameter_list|(
name|_an
parameter_list|)
value|mtx_assert(&(_an)->an_mtx,	\ 					    MA_NOTOWNED)
end_define

begin_comment
comment|/*  * These are for the hardware queue.  */
end_comment

begin_define
define|#
directive|define
name|ATH_TXQ_INSERT_HEAD
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_INSERT_HEAD(&(_tq)->axq_q, (_elm), _field); \ 	(_tq)->axq_depth++; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_INSERT_TAIL
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_INSERT_TAIL(&(_tq)->axq_q, (_elm), _field); \ 	(_tq)->axq_depth++; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_REMOVE
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_REMOVE(&(_tq)->axq_q, _elm, _field); \ 	(_tq)->axq_depth--; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_FIRST
parameter_list|(
name|_tq
parameter_list|)
value|TAILQ_FIRST(&(_tq)->axq_q)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_LAST
parameter_list|(
name|_tq
parameter_list|,
name|_field
parameter_list|)
value|TAILQ_LAST(&(_tq)->axq_q, _field)
end_define

begin_comment
comment|/*  * These are for the TID software queue.  */
end_comment

begin_define
define|#
directive|define
name|ATH_TID_INSERT_HEAD
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_INSERT_HEAD(&(_tq)->tid_q, (_elm), _field); \ 	(_tq)->axq_depth++; \ 	(_tq)->an->an_swq_depth++; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TID_INSERT_TAIL
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_INSERT_TAIL(&(_tq)->tid_q, (_elm), _field); \ 	(_tq)->axq_depth++; \ 	(_tq)->an->an_swq_depth++; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TID_REMOVE
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_REMOVE(&(_tq)->tid_q, _elm, _field); \ 	(_tq)->axq_depth--; \ 	(_tq)->an->an_swq_depth--; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TID_FIRST
parameter_list|(
name|_tq
parameter_list|)
value|TAILQ_FIRST(&(_tq)->tid_q)
end_define

begin_define
define|#
directive|define
name|ATH_TID_LAST
parameter_list|(
name|_tq
parameter_list|,
name|_field
parameter_list|)
value|TAILQ_LAST(&(_tq)->tid_q, _field)
end_define

begin_comment
comment|/*  * These are for the TID filtered frame queue  */
end_comment

begin_define
define|#
directive|define
name|ATH_TID_FILT_INSERT_HEAD
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_INSERT_HEAD(&(_tq)->filtq.tid_q, (_elm), _field); \ 	(_tq)->axq_depth++; \ 	(_tq)->an->an_swq_depth++; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TID_FILT_INSERT_TAIL
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_INSERT_TAIL(&(_tq)->filtq.tid_q, (_elm), _field); \ 	(_tq)->axq_depth++; \ 	(_tq)->an->an_swq_depth++; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TID_FILT_REMOVE
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	TAILQ_REMOVE(&(_tq)->filtq.tid_q, _elm, _field); \ 	(_tq)->axq_depth--; \ 	(_tq)->an->an_swq_depth--; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TID_FILT_FIRST
parameter_list|(
name|_tq
parameter_list|)
value|TAILQ_FIRST(&(_tq)->filtq.tid_q)
end_define

begin_define
define|#
directive|define
name|ATH_TID_FILT_LAST
parameter_list|(
name|_tq
parameter_list|,
name|_field
parameter_list|)
value|TAILQ_LAST(&(_tq)->filtq.tid_q,_field)
end_define

begin_struct
struct|struct
name|ath_vap
block|{
name|struct
name|ieee80211vap
name|av_vap
decl_stmt|;
comment|/* base class */
name|int
name|av_bslot
decl_stmt|;
comment|/* beacon slot index */
name|struct
name|ath_buf
modifier|*
name|av_bcbuf
decl_stmt|;
comment|/* beacon buffer */
name|struct
name|ieee80211_beacon_offsets
name|av_boff
decl_stmt|;
comment|/* dynamic update state */
name|struct
name|ath_txq
name|av_mcastq
decl_stmt|;
comment|/* buffered mcast s/w queue */
name|void
function_decl|(
modifier|*
name|av_recv_mgmt
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|av_newstate
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
name|void
function_decl|(
modifier|*
name|av_bmiss
function_decl|)
parameter_list|(
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|av_node_ps
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|av_set_tim
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|av_recv_pspoll
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_VAP
parameter_list|(
name|vap
parameter_list|)
value|((struct ath_vap *)(vap))
end_define

begin_struct_decl
struct_decl|struct
name|taskqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ath_tx99
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Whether to reset the TX/RX queue with or without  * a queue flush.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ATH_RESET_DEFAULT
init|=
literal|0
block|,
name|ATH_RESET_NOLOSS
init|=
literal|1
block|,
name|ATH_RESET_FULL
init|=
literal|2
block|, }
name|ATH_RESET_TYPE
typedef|;
end_typedef

begin_struct
struct|struct
name|ath_rx_methods
block|{
name|void
function_decl|(
modifier|*
name|recv_sched_queue
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|HAL_RX_QUEUE
name|q
parameter_list|,
name|int
name|dosched
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|recv_sched
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|int
name|dosched
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|recv_stop
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|int
name|dodelay
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|recv_start
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|recv_flush
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|recv_tasklet
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|npending
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|recv_rxbuf_init
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|recv_setup
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|recv_teardown
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Represent the current state of the RX FIFO.  */
end_comment

begin_struct
struct|struct
name|ath_rx_edma
block|{
name|struct
name|ath_buf
modifier|*
modifier|*
name|m_fifo
decl_stmt|;
name|int
name|m_fifolen
decl_stmt|;
name|int
name|m_fifo_head
decl_stmt|;
name|int
name|m_fifo_tail
decl_stmt|;
name|int
name|m_fifo_depth
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|m_rxpending
decl_stmt|;
name|struct
name|ath_buf
modifier|*
name|m_holdbf
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_tx_edma_fifo
block|{
name|struct
name|ath_buf
modifier|*
modifier|*
name|m_fifo
decl_stmt|;
name|int
name|m_fifolen
decl_stmt|;
name|int
name|m_fifo_head
decl_stmt|;
name|int
name|m_fifo_tail
decl_stmt|;
name|int
name|m_fifo_depth
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_tx_methods
block|{
name|int
function_decl|(
modifier|*
name|xmit_setup
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|xmit_teardown
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|xmit_attach_comp_func
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|xmit_dma_restart
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_txq
modifier|*
name|txq
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|xmit_handoff
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_txq
modifier|*
name|txq
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|xmit_drain
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|ATH_RESET_TYPE
name|reset_type
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ath_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
comment|/* interface common */
name|struct
name|ath_stats
name|sc_stats
decl_stmt|;
comment|/* interface statistics */
name|struct
name|ath_tx_aggr_stats
name|sc_aggr_stats
decl_stmt|;
name|struct
name|ath_intr_stats
name|sc_intr_stats
decl_stmt|;
name|uint64_t
name|sc_debug
decl_stmt|;
name|uint64_t
name|sc_ktrdebug
decl_stmt|;
name|int
name|sc_nvaps
decl_stmt|;
comment|/* # vaps */
name|int
name|sc_nstavaps
decl_stmt|;
comment|/* # station vaps */
name|int
name|sc_nmeshvaps
decl_stmt|;
comment|/* # mbss vaps */
name|u_int8_t
name|sc_hwbssidmask
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|sc_nbssid0
decl_stmt|;
comment|/* # vap's using base mac */
name|uint32_t
name|sc_bssidmask
decl_stmt|;
comment|/* bssid mask */
name|struct
name|ath_rx_methods
name|sc_rx
decl_stmt|;
name|struct
name|ath_rx_edma
name|sc_rxedma
index|[
name|HAL_NUM_RX_QUEUES
index|]
decl_stmt|;
comment|/* HP/LP queues */
name|ath_bufhead
name|sc_rx_rxlist
index|[
name|HAL_NUM_RX_QUEUES
index|]
decl_stmt|;
comment|/* deferred RX completion */
name|struct
name|ath_tx_methods
name|sc_tx
decl_stmt|;
name|struct
name|ath_tx_edma_fifo
name|sc_txedma
index|[
name|HAL_NUM_TX_QUEUES
index|]
decl_stmt|;
comment|/* 	 * This is (currently) protected by the TX queue lock; 	 * it should migrate to a separate lock later 	 * so as to minimise contention. 	 */
name|ath_bufhead
name|sc_txbuf_list
decl_stmt|;
name|int
name|sc_rx_statuslen
decl_stmt|;
name|int
name|sc_tx_desclen
decl_stmt|;
name|int
name|sc_tx_statuslen
decl_stmt|;
name|int
name|sc_tx_nmaps
decl_stmt|;
comment|/* Number of TX maps */
name|int
name|sc_edma_bufsize
decl_stmt|;
name|int
name|sc_rx_stopped
decl_stmt|;
comment|/* XXX only for EDMA */
name|int
name|sc_rx_resetted
decl_stmt|;
comment|/* XXX only for EDMA */
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
name|sc_node_free
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
parameter_list|)
function_decl|;
name|device_t
name|sc_dev
decl_stmt|;
name|HAL_BUS_TAG
name|sc_st
decl_stmt|;
comment|/* bus space tag */
name|HAL_BUS_HANDLE
name|sc_sh
decl_stmt|;
comment|/* bus space handle */
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* bus DMA tag */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
comment|/* master lock (recursive) */
name|struct
name|mtx
name|sc_pcu_mtx
decl_stmt|;
comment|/* PCU access mutex */
name|char
name|sc_pcu_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_rx_mtx
decl_stmt|;
comment|/* RX access mutex */
name|char
name|sc_rx_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_tx_mtx
decl_stmt|;
comment|/* TX handling/comp mutex */
name|char
name|sc_tx_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_tx_ic_mtx
decl_stmt|;
comment|/* TX queue mutex */
name|char
name|sc_tx_ic_mtx_name
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|sc_tq
decl_stmt|;
comment|/* private task queue */
name|struct
name|ath_hal
modifier|*
name|sc_ah
decl_stmt|;
comment|/* Atheros HAL */
name|struct
name|ath_ratectrl
modifier|*
name|sc_rc
decl_stmt|;
comment|/* tx rate control support */
name|struct
name|ath_tx99
modifier|*
name|sc_tx99
decl_stmt|;
comment|/* tx99 adjunct state */
name|void
function_decl|(
modifier|*
name|sc_setdefantenna
function_decl|)
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
comment|/* 	 * First set of flags. 	 */
name|uint32_t
name|sc_invalid
range|:
literal|1
decl_stmt|,
comment|/* disable hardware accesses */
name|sc_mrretry
range|:
literal|1
decl_stmt|,
comment|/* multi-rate retry support */
name|sc_mrrprot
range|:
literal|1
decl_stmt|,
comment|/* MRR + protection support */
name|sc_softled
range|:
literal|1
decl_stmt|,
comment|/* enable LED gpio status */
name|sc_hardled
range|:
literal|1
decl_stmt|,
comment|/* enable MAC LED status */
name|sc_splitmic
range|:
literal|1
decl_stmt|,
comment|/* split TKIP MIC keys */
name|sc_needmib
range|:
literal|1
decl_stmt|,
comment|/* enable MIB stats intr */
name|sc_diversity
range|:
literal|1
decl_stmt|,
comment|/* enable rx diversity */
name|sc_hasveol
range|:
literal|1
decl_stmt|,
comment|/* tx VEOL support */
name|sc_ledstate
range|:
literal|1
decl_stmt|,
comment|/* LED on/off state */
name|sc_blinking
range|:
literal|1
decl_stmt|,
comment|/* LED blink operation active */
name|sc_mcastkey
range|:
literal|1
decl_stmt|,
comment|/* mcast key cache search */
name|sc_scanning
range|:
literal|1
decl_stmt|,
comment|/* scanning active */
name|sc_syncbeacon
range|:
literal|1
decl_stmt|,
comment|/* sync/resync beacon timers */
name|sc_hasclrkey
range|:
literal|1
decl_stmt|,
comment|/* CLR key supported */
name|sc_xchanmode
range|:
literal|1
decl_stmt|,
comment|/* extended channel mode */
name|sc_outdoor
range|:
literal|1
decl_stmt|,
comment|/* outdoor operation */
name|sc_dturbo
range|:
literal|1
decl_stmt|,
comment|/* dynamic turbo in use */
name|sc_hasbmask
range|:
literal|1
decl_stmt|,
comment|/* bssid mask support */
name|sc_hasbmatch
range|:
literal|1
decl_stmt|,
comment|/* bssid match disable support*/
name|sc_hastsfadd
range|:
literal|1
decl_stmt|,
comment|/* tsf adjust support */
name|sc_beacons
range|:
literal|1
decl_stmt|,
comment|/* beacons running */
name|sc_swbmiss
range|:
literal|1
decl_stmt|,
comment|/* sta mode using sw bmiss */
name|sc_stagbeacons
range|:
literal|1
decl_stmt|,
comment|/* use staggered beacons */
name|sc_wmetkipmic
range|:
literal|1
decl_stmt|,
comment|/* can do WME+TKIP MIC */
name|sc_resume_up
range|:
literal|1
decl_stmt|,
comment|/* on resume, start all vaps */
name|sc_tdma
range|:
literal|1
decl_stmt|,
comment|/* TDMA in use */
name|sc_setcca
range|:
literal|1
decl_stmt|,
comment|/* set/clr CCA with TDMA */
name|sc_resetcal
range|:
literal|1
decl_stmt|,
comment|/* reset cal state next trip */
name|sc_rxslink
range|:
literal|1
decl_stmt|,
comment|/* do self-linked final descriptor */
name|sc_rxtsf32
range|:
literal|1
decl_stmt|,
comment|/* RX dec TSF is 32 bits */
name|sc_isedma
range|:
literal|1
decl_stmt|,
comment|/* supports EDMA */
name|sc_do_mybeacon
range|:
literal|1
decl_stmt|;
comment|/* supports mybeacon */
comment|/* 	 * Second set of flags. 	 */
name|u_int32_t
name|sc_use_ent
range|:
literal|1
decl_stmt|,
name|sc_rx_stbc
range|:
literal|1
decl_stmt|,
name|sc_tx_stbc
range|:
literal|1
decl_stmt|,
name|sc_hasenforcetxop
range|:
literal|1
decl_stmt|,
comment|/* support enforce TxOP */
name|sc_hasdivcomb
range|:
literal|1
decl_stmt|,
comment|/* RX diversity combining */
name|sc_rx_lnamixer
range|:
literal|1
decl_stmt|;
comment|/* RX using LNA mixing */
name|int
name|sc_cabq_enable
decl_stmt|;
comment|/* Enable cabq transmission */
comment|/* 	 * Enterprise mode configuration for AR9380 and later chipsets. 	 */
name|uint32_t
name|sc_ent_cfg
decl_stmt|;
name|uint32_t
name|sc_eerd
decl_stmt|;
comment|/* regdomain from EEPROM */
name|uint32_t
name|sc_eecc
decl_stmt|;
comment|/* country code from EEPROM */
comment|/* rate tables */
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|sc_rates
index|[
name|IEEE80211_MODE_MAX
index|]
decl_stmt|;
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|sc_currates
decl_stmt|;
comment|/* current rate table */
name|enum
name|ieee80211_phymode
name|sc_curmode
decl_stmt|;
comment|/* current phy mode */
name|HAL_OPMODE
name|sc_opmode
decl_stmt|;
comment|/* current operating mode */
name|u_int16_t
name|sc_curtxpow
decl_stmt|;
comment|/* current tx power limit */
name|u_int16_t
name|sc_curaid
decl_stmt|;
comment|/* current association id */
name|struct
name|ieee80211_channel
modifier|*
name|sc_curchan
decl_stmt|;
comment|/* current installed channel */
name|u_int8_t
name|sc_curbssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|sc_rixmap
index|[
literal|256
index|]
decl_stmt|;
comment|/* IEEE to h/w rate table ix */
struct|struct
block|{
name|u_int8_t
name|ieeerate
decl_stmt|;
comment|/* IEEE rate */
name|u_int8_t
name|rxflags
decl_stmt|;
comment|/* radiotap rx flags */
name|u_int8_t
name|txflags
decl_stmt|;
comment|/* radiotap tx flags */
name|u_int16_t
name|ledon
decl_stmt|;
comment|/* softled on time */
name|u_int16_t
name|ledoff
decl_stmt|;
comment|/* softled off time */
block|}
name|sc_hwmap
index|[
literal|32
index|]
struct|;
comment|/* h/w rate ix mappings */
name|u_int8_t
name|sc_protrix
decl_stmt|;
comment|/* protection rate index */
name|u_int8_t
name|sc_lastdatarix
decl_stmt|;
comment|/* last data frame rate index */
name|u_int
name|sc_mcastrate
decl_stmt|;
comment|/* ieee rate for mcastrateix */
name|u_int
name|sc_fftxqmin
decl_stmt|;
comment|/* min frames before staging */
name|u_int
name|sc_fftxqmax
decl_stmt|;
comment|/* max frames before drop */
name|u_int
name|sc_txantenna
decl_stmt|;
comment|/* tx antenna (fixed or auto) */
name|HAL_INT
name|sc_imask
decl_stmt|;
comment|/* interrupt mask copy */
comment|/* 	 * These are modified in the interrupt handler as well as 	 * the task queues and other contexts. Thus these must be 	 * protected by a mutex, or they could clash. 	 * 	 * For now, access to these is behind the ATH_LOCK, 	 * just to save time. 	 */
name|uint32_t
name|sc_txq_active
decl_stmt|;
comment|/* bitmap of active TXQs */
name|uint32_t
name|sc_kickpcu
decl_stmt|;
comment|/* whether to kick the PCU */
name|uint32_t
name|sc_rxproc_cnt
decl_stmt|;
comment|/* In RX processing */
name|uint32_t
name|sc_txproc_cnt
decl_stmt|;
comment|/* In TX processing */
name|uint32_t
name|sc_txstart_cnt
decl_stmt|;
comment|/* In TX output (raw/start) */
name|uint32_t
name|sc_inreset_cnt
decl_stmt|;
comment|/* In active reset/chanchange */
name|uint32_t
name|sc_txrx_cnt
decl_stmt|;
comment|/* refcount on stop/start'ing TX */
name|uint32_t
name|sc_intr_cnt
decl_stmt|;
comment|/* refcount on interrupt handling */
name|u_int
name|sc_keymax
decl_stmt|;
comment|/* size of key cache */
name|u_int8_t
name|sc_keymap
index|[
name|ATH_KEYBYTES
index|]
decl_stmt|;
comment|/* key use bit map */
comment|/* 	 * Software based LED blinking 	 */
name|u_int
name|sc_ledpin
decl_stmt|;
comment|/* GPIO pin for driving LED */
name|u_int
name|sc_ledon
decl_stmt|;
comment|/* pin setting for LED on */
name|u_int
name|sc_ledidle
decl_stmt|;
comment|/* idle polling interval */
name|int
name|sc_ledevent
decl_stmt|;
comment|/* time of last LED event */
name|u_int8_t
name|sc_txrix
decl_stmt|;
comment|/* current tx rate for LED */
name|u_int16_t
name|sc_ledoff
decl_stmt|;
comment|/* off time for current blink */
name|struct
name|callout
name|sc_ledtimer
decl_stmt|;
comment|/* led off timer */
comment|/* 	 * Hardware based LED blinking 	 */
name|int
name|sc_led_pwr_pin
decl_stmt|;
comment|/* MAC power LED GPIO pin */
name|int
name|sc_led_net_pin
decl_stmt|;
comment|/* MAC network LED GPIO pin */
name|u_int
name|sc_rfsilentpin
decl_stmt|;
comment|/* GPIO pin for rfkill int */
name|u_int
name|sc_rfsilentpol
decl_stmt|;
comment|/* pin setting for rfkill on */
name|struct
name|ath_descdma
name|sc_rxdma
decl_stmt|;
comment|/* RX descriptors */
name|ath_bufhead
name|sc_rxbuf
decl_stmt|;
comment|/* receive buffer */
name|u_int32_t
modifier|*
name|sc_rxlink
decl_stmt|;
comment|/* link ptr in last RX desc */
name|struct
name|task
name|sc_rxtask
decl_stmt|;
comment|/* rx int processing */
name|u_int8_t
name|sc_defant
decl_stmt|;
comment|/* current default antenna */
name|u_int8_t
name|sc_rxotherant
decl_stmt|;
comment|/* rx's on non-default antenna*/
name|u_int64_t
name|sc_lastrx
decl_stmt|;
comment|/* tsf at last rx'd frame */
name|struct
name|ath_rx_status
modifier|*
name|sc_lastrs
decl_stmt|;
comment|/* h/w status of last rx */
name|struct
name|ath_rx_radiotap_header
name|sc_rx_th
decl_stmt|;
name|int
name|sc_rx_th_len
decl_stmt|;
name|u_int
name|sc_monpass
decl_stmt|;
comment|/* frames to pass in mon.mode */
name|struct
name|ath_descdma
name|sc_txdma
decl_stmt|;
comment|/* TX descriptors */
name|uint16_t
name|sc_txbuf_descid
decl_stmt|;
name|ath_bufhead
name|sc_txbuf
decl_stmt|;
comment|/* transmit buffer */
name|int
name|sc_txbuf_cnt
decl_stmt|;
comment|/* how many buffers avail */
name|struct
name|ath_descdma
name|sc_txdma_mgmt
decl_stmt|;
comment|/* mgmt TX descriptors */
name|ath_bufhead
name|sc_txbuf_mgmt
decl_stmt|;
comment|/* mgmt transmit buffer */
name|struct
name|ath_descdma
name|sc_txsdma
decl_stmt|;
comment|/* EDMA TX status desc's */
name|struct
name|mtx
name|sc_txbuflock
decl_stmt|;
comment|/* txbuf lock */
name|char
name|sc_txname
index|[
literal|12
index|]
decl_stmt|;
comment|/* e.g. "ath0_buf" */
name|u_int
name|sc_txqsetup
decl_stmt|;
comment|/* h/w queues setup */
name|u_int
name|sc_txintrperiod
decl_stmt|;
comment|/* tx interrupt batching */
name|struct
name|ath_txq
name|sc_txq
index|[
name|HAL_NUM_TX_QUEUES
index|]
decl_stmt|;
name|struct
name|ath_txq
modifier|*
name|sc_ac2q
index|[
literal|5
index|]
decl_stmt|;
comment|/* WME AC -> h/w q map */
name|struct
name|task
name|sc_txtask
decl_stmt|;
comment|/* tx int processing */
name|struct
name|task
name|sc_txqtask
decl_stmt|;
comment|/* tx proc processing */
name|struct
name|ath_descdma
name|sc_txcompdma
decl_stmt|;
comment|/* TX EDMA completion */
name|struct
name|mtx
name|sc_txcomplock
decl_stmt|;
comment|/* TX EDMA completion lock */
name|char
name|sc_txcompname
index|[
literal|12
index|]
decl_stmt|;
comment|/* eg ath0_txcomp */
name|int
name|sc_wd_timer
decl_stmt|;
comment|/* count down for wd timer */
name|struct
name|callout
name|sc_wd_ch
decl_stmt|;
comment|/* tx watchdog timer */
name|struct
name|ath_tx_radiotap_header
name|sc_tx_th
decl_stmt|;
name|int
name|sc_tx_th_len
decl_stmt|;
name|struct
name|ath_descdma
name|sc_bdma
decl_stmt|;
comment|/* beacon descriptors */
name|ath_bufhead
name|sc_bbuf
decl_stmt|;
comment|/* beacon buffers */
name|u_int
name|sc_bhalq
decl_stmt|;
comment|/* HAL q for outgoing beacons */
name|u_int
name|sc_bmisscount
decl_stmt|;
comment|/* missed beacon transmits */
name|u_int32_t
name|sc_ant_tx
index|[
literal|8
index|]
decl_stmt|;
comment|/* recent tx frames/antenna */
name|struct
name|ath_txq
modifier|*
name|sc_cabq
decl_stmt|;
comment|/* tx q for cab frames */
name|struct
name|task
name|sc_bmisstask
decl_stmt|;
comment|/* bmiss int processing */
name|struct
name|task
name|sc_bstucktask
decl_stmt|;
comment|/* stuck beacon processing */
name|struct
name|task
name|sc_resettask
decl_stmt|;
comment|/* interface reset task */
name|struct
name|task
name|sc_fataltask
decl_stmt|;
comment|/* fatal task */
enum|enum
block|{
name|OK
block|,
comment|/* no change needed */
name|UPDATE
block|,
comment|/* update pending */
name|COMMIT
comment|/* beacon sent, commit change */
block|}
name|sc_updateslot
enum|;
comment|/* slot time update fsm */
name|int
name|sc_slotupdate
decl_stmt|;
comment|/* slot to advance fsm */
name|struct
name|ieee80211vap
modifier|*
name|sc_bslot
index|[
name|ATH_BCBUF
index|]
decl_stmt|;
name|int
name|sc_nbcnvaps
decl_stmt|;
comment|/* # vaps with beacons */
name|struct
name|callout
name|sc_cal_ch
decl_stmt|;
comment|/* callout handle for cals */
name|int
name|sc_lastlongcal
decl_stmt|;
comment|/* last long cal completed */
name|int
name|sc_lastcalreset
decl_stmt|;
comment|/* last cal reset done */
name|int
name|sc_lastani
decl_stmt|;
comment|/* last ANI poll */
name|int
name|sc_lastshortcal
decl_stmt|;
comment|/* last short calibration */
name|HAL_BOOL
name|sc_doresetcal
decl_stmt|;
comment|/* Yes, we're doing a reset cal atm */
name|HAL_NODE_STATS
name|sc_halstats
decl_stmt|;
comment|/* station-mode rssi stats */
name|u_int
name|sc_tdmadbaprep
decl_stmt|;
comment|/* TDMA DBA prep time */
name|u_int
name|sc_tdmaswbaprep
decl_stmt|;
comment|/* TDMA SWBA prep time */
name|u_int
name|sc_tdmaswba
decl_stmt|;
comment|/* TDMA SWBA counter */
name|u_int32_t
name|sc_tdmabintval
decl_stmt|;
comment|/* TDMA beacon interval (TU) */
name|u_int32_t
name|sc_tdmaguard
decl_stmt|;
comment|/* TDMA guard time (usec) */
name|u_int
name|sc_tdmaslotlen
decl_stmt|;
comment|/* TDMA slot length (usec) */
name|u_int32_t
name|sc_avgtsfdeltap
decl_stmt|;
comment|/* TDMA slot adjust (+) */
name|u_int32_t
name|sc_avgtsfdeltam
decl_stmt|;
comment|/* TDMA slot adjust (-) */
name|uint16_t
modifier|*
name|sc_eepromdata
decl_stmt|;
comment|/* Local eeprom data, if AR9100 */
name|uint32_t
name|sc_txchainmask
decl_stmt|;
comment|/* hardware TX chainmask */
name|uint32_t
name|sc_rxchainmask
decl_stmt|;
comment|/* hardware RX chainmask */
name|uint32_t
name|sc_cur_txchainmask
decl_stmt|;
comment|/* currently configured TX chainmask */
name|uint32_t
name|sc_cur_rxchainmask
decl_stmt|;
comment|/* currently configured RX chainmask */
name|uint32_t
name|sc_rts_aggr_limit
decl_stmt|;
comment|/* TX limit on RTS aggregates */
name|int
name|sc_aggr_limit
decl_stmt|;
comment|/* TX limit on all aggregates */
name|int
name|sc_delim_min_pad
decl_stmt|;
comment|/* Minimum delimiter count */
comment|/* Queue limits */
comment|/* 	 * To avoid queue starvation in congested conditions, 	 * these parameters tune the maximum number of frames 	 * queued to the data/mcastq before they're dropped. 	 * 	 * This is to prevent: 	 * + a single destination overwhelming everything, including 	 *   management/multicast frames; 	 * + multicast frames overwhelming everything (when the 	 *   air is sufficiently busy that cabq can't drain.) 	 * + A node in powersave shouldn't be allowed to exhaust 	 *   all available mbufs; 	 * 	 * These implement: 	 * + data_minfree is the maximum number of free buffers 	 *   overall to successfully allow a data frame. 	 * 	 * + mcastq_maxdepth is the maximum depth allowed of the cabq. 	 */
name|int
name|sc_txq_node_maxdepth
decl_stmt|;
name|int
name|sc_txq_data_minfree
decl_stmt|;
name|int
name|sc_txq_mcastq_maxdepth
decl_stmt|;
name|int
name|sc_txq_node_psq_maxdepth
decl_stmt|;
comment|/* 	 * Software queue twiddles 	 * 	 * hwq_limit_nonaggr: 	 *		when to begin limiting non-aggregate frames to the 	 *		hardware queue, regardless of the TID. 	 * hwq_limit_aggr: 	 *		when to begin limiting A-MPDU frames to the 	 *		hardware queue, regardless of the TID. 	 * tid_hwq_lo:	how low the per-TID hwq count has to be before the 	 *		TID will be scheduled again 	 * tid_hwq_hi:	how many frames to queue to the HWQ before the TID 	 *		stops being scheduled. 	 */
name|int
name|sc_hwq_limit_nonaggr
decl_stmt|;
name|int
name|sc_hwq_limit_aggr
decl_stmt|;
name|int
name|sc_tid_hwq_lo
decl_stmt|;
name|int
name|sc_tid_hwq_hi
decl_stmt|;
comment|/* DFS related state */
name|void
modifier|*
name|sc_dfs
decl_stmt|;
comment|/* Used by an optional DFS module */
name|int
name|sc_dodfs
decl_stmt|;
comment|/* Whether to enable DFS rx filter bits */
name|struct
name|task
name|sc_dfstask
decl_stmt|;
comment|/* DFS processing task */
comment|/* Spectral related state */
name|void
modifier|*
name|sc_spectral
decl_stmt|;
name|int
name|sc_dospectral
decl_stmt|;
comment|/* LNA diversity related state */
name|void
modifier|*
name|sc_lna_div
decl_stmt|;
name|int
name|sc_dolnadiv
decl_stmt|;
comment|/* ALQ */
ifdef|#
directive|ifdef
name|ATH_DEBUG_ALQ
name|struct
name|if_ath_alq
name|sc_alq
decl_stmt|;
endif|#
directive|endif
comment|/* TX AMPDU handling */
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
parameter_list|,
name|int
parameter_list|,
name|int
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
parameter_list|,
name|int
parameter_list|,
name|int
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
name|void
function_decl|(
modifier|*
name|sc_addba_response_timeout
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
name|void
function_decl|(
modifier|*
name|sc_bar_response
function_decl|)
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|struct
name|ieee80211_tx_ampdu
modifier|*
name|tap
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
comment|/* 	 * Powersave state tracking. 	 * 	 * target/cur powerstate is the chip power state. 	 * target selfgen state is the self-generated frames 	 *   state.  The chip can be awake but transmitted frames 	 *   can have the PWRMGT bit set to 1 so the destination 	 *   thinks the node is asleep. 	 */
name|HAL_POWER_MODE
name|sc_target_powerstate
decl_stmt|;
name|HAL_POWER_MODE
name|sc_target_selfgen_state
decl_stmt|;
name|HAL_POWER_MODE
name|sc_cur_powerstate
decl_stmt|;
name|int
name|sc_powersave_refcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATH_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&(_sc)->sc_mtx, device_get_nameunit((_sc)->sc_dev), \ 		 NULL, MTX_DEF | MTX_RECURSE)
end_define

begin_define
define|#
directive|define
name|ATH_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ATH_UNLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, MA_NOTOWNED)
end_define

begin_comment
comment|/*  * The TX lock is non-reentrant and serialises the TX frame send  * and completion operations.  */
end_comment

begin_define
define|#
directive|define
name|ATH_TX_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|do {\ 	snprintf((_sc)->sc_tx_mtx_name,				\ 	    sizeof((_sc)->sc_tx_mtx_name),				\ 	    "%s TX lock",						\ 	    device_get_nameunit((_sc)->sc_dev));			\ 	mtx_init(&(_sc)->sc_tx_mtx, (_sc)->sc_tx_mtx_name,		\ 		 NULL, MTX_DEF);					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_tx_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_TX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_tx_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_TX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_tx_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_TX_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_tx_mtx,	\ 		MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ATH_TX_UNLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_tx_mtx,	\ 		MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|ATH_TX_TRYLOCK
parameter_list|(
name|_sc
parameter_list|)
value|(mtx_owned(&(_sc)->sc_tx_mtx) != 0&&	\ 					mtx_trylock(&(_sc)->sc_tx_mtx))
end_define

begin_comment
comment|/*  * The IC TX lock is non-reentrant and serialises packet queuing from  * the upper layers.  */
end_comment

begin_define
define|#
directive|define
name|ATH_TX_IC_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|do {\ 	snprintf((_sc)->sc_tx_ic_mtx_name,				\ 	    sizeof((_sc)->sc_tx_ic_mtx_name),				\ 	    "%s IC TX lock",						\ 	    device_get_nameunit((_sc)->sc_dev));			\ 	mtx_init(&(_sc)->sc_tx_ic_mtx, (_sc)->sc_tx_ic_mtx_name,	\ 		 NULL, MTX_DEF);					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TX_IC_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_tx_ic_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_TX_IC_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_tx_ic_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_TX_IC_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_tx_ic_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_TX_IC_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_tx_ic_mtx,	\ 		MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ATH_TX_IC_UNLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_tx_ic_mtx,	\ 		MA_NOTOWNED)
end_define

begin_comment
comment|/*  * The PCU lock is non-recursive and should be treated as a spinlock.  * Although currently the interrupt code is run in netisr context and  * doesn't require this, this may change in the future.  * Please keep this in mind when protecting certain code paths  * with the PCU lock.  *  * The PCU lock is used to serialise access to the PCU so things such  * as TX, RX, state change (eg channel change), channel reset and updates  * from interrupt context (eg kickpcu, txqactive bits) do not clash.  *  * Although the current single-thread taskqueue mechanism protects the  * majority of these situations by simply serialising them, there are  * a few others which occur at the same time. These include the TX path  * (which only acquires ATH_LOCK when recycling buffers to the free list),  * ath_set_channel, the channel scanning API and perhaps quite a bit more.  */
end_comment

begin_define
define|#
directive|define
name|ATH_PCU_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|do {\ 	snprintf((_sc)->sc_pcu_mtx_name,				\ 	    sizeof((_sc)->sc_pcu_mtx_name),				\ 	    "%s PCU lock",						\ 	    device_get_nameunit((_sc)->sc_dev));			\ 	mtx_init(&(_sc)->sc_pcu_mtx, (_sc)->sc_pcu_mtx_name,		\ 		 NULL, MTX_DEF);					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ATH_PCU_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_pcu_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_PCU_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_pcu_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_PCU_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_pcu_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_PCU_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_pcu_mtx,	\ 		MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ATH_PCU_UNLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_pcu_mtx,	\ 		MA_NOTOWNED)
end_define

begin_comment
comment|/*  * The RX lock is primarily a(nother) workaround to ensure that the  * RX FIFO/list isn't modified by various execution paths.  * Even though RX occurs in a single context (the ath taskqueue), the  * RX path can be executed via various reset/channel change paths.  */
end_comment

begin_define
define|#
directive|define
name|ATH_RX_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|do {\ 	snprintf((_sc)->sc_rx_mtx_name,					\ 	    sizeof((_sc)->sc_rx_mtx_name),				\ 	    "%s RX lock",						\ 	    device_get_nameunit((_sc)->sc_dev));			\ 	mtx_init(&(_sc)->sc_rx_mtx, (_sc)->sc_rx_mtx_name,		\ 		 NULL, MTX_DEF);					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|ATH_RX_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_rx_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_RX_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_rx_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_RX_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_rx_mtx)
end_define

begin_define
define|#
directive|define
name|ATH_RX_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_rx_mtx,	\ 		MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ATH_RX_UNLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_rx_mtx,	\ 		MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_SETUP
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
value|((sc)->sc_txqsetup& (1<<i))
end_define

begin_define
define|#
directive|define
name|ATH_TXBUF_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|do { \ 	snprintf((_sc)->sc_txname, sizeof((_sc)->sc_txname), "%s_buf", \ 		device_get_nameunit((_sc)->sc_dev)); \ 	mtx_init(&(_sc)->sc_txbuflock, (_sc)->sc_txname, NULL, MTX_DEF); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TXBUF_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_txbuflock)
end_define

begin_define
define|#
directive|define
name|ATH_TXBUF_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_txbuflock)
end_define

begin_define
define|#
directive|define
name|ATH_TXBUF_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_txbuflock)
end_define

begin_define
define|#
directive|define
name|ATH_TXBUF_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_assert(&(_sc)->sc_txbuflock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ATH_TXBUF_UNLOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_assert(&(_sc)->sc_txbuflock, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|ATH_TXSTATUS_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
value|do { \ 	snprintf((_sc)->sc_txcompname, sizeof((_sc)->sc_txcompname), \ 		"%s_buf", \ 		device_get_nameunit((_sc)->sc_dev)); \ 	mtx_init(&(_sc)->sc_txcomplock, (_sc)->sc_txcompname, NULL, \ 		MTX_DEF); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TXSTATUS_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_txcomplock)
end_define

begin_define
define|#
directive|define
name|ATH_TXSTATUS_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_txcomplock)
end_define

begin_define
define|#
directive|define
name|ATH_TXSTATUS_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_txcomplock)
end_define

begin_define
define|#
directive|define
name|ATH_TXSTATUS_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_assert(&(_sc)->sc_txcomplock, MA_OWNED)
end_define

begin_function_decl
name|int
name|ath_attach
parameter_list|(
name|u_int16_t
parameter_list|,
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ath_detach
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_resume
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_suspend
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_shutdown
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ath_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * HAL definitions to comply with local coding convention.  */
end_comment

begin_define
define|#
directive|define
name|ath_hal_detach
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_detach)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_reset
parameter_list|(
name|_ah
parameter_list|,
name|_opmode
parameter_list|,
name|_chan
parameter_list|,
name|_outdoor
parameter_list|,
name|_pstatus
parameter_list|)
define|\
value|((*(_ah)->ah_reset)((_ah), (_opmode), (_chan), (_outdoor), (_pstatus)))
end_define

begin_define
define|#
directive|define
name|ath_hal_macversion
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(((_ah)->ah_macVersion<< 4) | ((_ah)->ah_macRev))
end_define

begin_define
define|#
directive|define
name|ath_hal_getratetable
parameter_list|(
name|_ah
parameter_list|,
name|_mode
parameter_list|)
define|\
value|((*(_ah)->ah_getRateTable)((_ah), (_mode)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getmac
parameter_list|(
name|_ah
parameter_list|,
name|_mac
parameter_list|)
define|\
value|((*(_ah)->ah_getMacAddress)((_ah), (_mac)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setmac
parameter_list|(
name|_ah
parameter_list|,
name|_mac
parameter_list|)
define|\
value|((*(_ah)->ah_setMacAddress)((_ah), (_mac)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getbssidmask
parameter_list|(
name|_ah
parameter_list|,
name|_mask
parameter_list|)
define|\
value|((*(_ah)->ah_getBssIdMask)((_ah), (_mask)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setbssidmask
parameter_list|(
name|_ah
parameter_list|,
name|_mask
parameter_list|)
define|\
value|((*(_ah)->ah_setBssIdMask)((_ah), (_mask)))
end_define

begin_define
define|#
directive|define
name|ath_hal_intrset
parameter_list|(
name|_ah
parameter_list|,
name|_mask
parameter_list|)
define|\
value|((*(_ah)->ah_setInterrupts)((_ah), (_mask)))
end_define

begin_define
define|#
directive|define
name|ath_hal_intrget
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getInterrupts)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_intrpend
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_isInterruptPending)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getisr
parameter_list|(
name|_ah
parameter_list|,
name|_pmask
parameter_list|)
define|\
value|((*(_ah)->ah_getPendingInterrupts)((_ah), (_pmask)))
end_define

begin_define
define|#
directive|define
name|ath_hal_updatetxtriglevel
parameter_list|(
name|_ah
parameter_list|,
name|_inc
parameter_list|)
define|\
value|((*(_ah)->ah_updateTxTrigLevel)((_ah), (_inc)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setpower
parameter_list|(
name|_ah
parameter_list|,
name|_mode
parameter_list|)
define|\
value|((*(_ah)->ah_setPowerMode)((_ah), (_mode), AH_TRUE))
end_define

begin_define
define|#
directive|define
name|ath_hal_setselfgenpower
parameter_list|(
name|_ah
parameter_list|,
name|_mode
parameter_list|)
define|\
value|((*(_ah)->ah_setPowerMode)((_ah), (_mode), AH_FALSE))
end_define

begin_define
define|#
directive|define
name|ath_hal_keycachesize
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getKeyCacheSize)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_keyreset
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|)
define|\
value|((*(_ah)->ah_resetKeyCacheEntry)((_ah), (_ix)))
end_define

begin_define
define|#
directive|define
name|ath_hal_keyset
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|,
name|_pk
parameter_list|,
name|_mac
parameter_list|)
define|\
value|((*(_ah)->ah_setKeyCacheEntry)((_ah), (_ix), (_pk), (_mac), AH_FALSE))
end_define

begin_define
define|#
directive|define
name|ath_hal_keyisvalid
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|)
define|\
value|(((*(_ah)->ah_isKeyCacheEntryValid)((_ah), (_ix))))
end_define

begin_define
define|#
directive|define
name|ath_hal_keysetmac
parameter_list|(
name|_ah
parameter_list|,
name|_ix
parameter_list|,
name|_mac
parameter_list|)
define|\
value|((*(_ah)->ah_setKeyCacheEntryMac)((_ah), (_ix), (_mac)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getrxfilter
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getRxFilter)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setrxfilter
parameter_list|(
name|_ah
parameter_list|,
name|_filter
parameter_list|)
define|\
value|((*(_ah)->ah_setRxFilter)((_ah), (_filter)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setmcastfilter
parameter_list|(
name|_ah
parameter_list|,
name|_mfilt0
parameter_list|,
name|_mfilt1
parameter_list|)
define|\
value|((*(_ah)->ah_setMulticastFilter)((_ah), (_mfilt0), (_mfilt1)))
end_define

begin_define
define|#
directive|define
name|ath_hal_waitforbeacon
parameter_list|(
name|_ah
parameter_list|,
name|_bf
parameter_list|)
define|\
value|((*(_ah)->ah_waitForBeaconDone)((_ah), (_bf)->bf_daddr))
end_define

begin_define
define|#
directive|define
name|ath_hal_putrxbuf
parameter_list|(
name|_ah
parameter_list|,
name|_bufaddr
parameter_list|,
name|_rxq
parameter_list|)
define|\
value|((*(_ah)->ah_setRxDP)((_ah), (_bufaddr), (_rxq)))
end_define

begin_comment
comment|/* NB: common across all chips */
end_comment

begin_define
define|#
directive|define
name|AR_TSF_L32
value|0x804c
end_define

begin_comment
comment|/* MAC local clock lower 32 bits */
end_comment

begin_define
define|#
directive|define
name|ath_hal_gettsf32
parameter_list|(
name|_ah
parameter_list|)
define|\
value|OS_REG_READ(_ah, AR_TSF_L32)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettsf64
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getTsf64)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_settsf64
parameter_list|(
name|_ah
parameter_list|,
name|_val
parameter_list|)
define|\
value|((*(_ah)->ah_setTsf64)((_ah), (_val)))
end_define

begin_define
define|#
directive|define
name|ath_hal_resettsf
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_resetTsf)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_rxena
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_enableReceive)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_puttxbuf
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|,
name|_bufaddr
parameter_list|)
define|\
value|((*(_ah)->ah_setTxDP)((_ah), (_q), (_bufaddr)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxbuf
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_getTxDP)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_numtxpending
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_numTxPending)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getrxbuf
parameter_list|(
name|_ah
parameter_list|,
name|_rxq
parameter_list|)
define|\
value|((*(_ah)->ah_getRxDP)((_ah), (_rxq)))
end_define

begin_define
define|#
directive|define
name|ath_hal_txstart
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_startTxDma)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setchannel
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|)
define|\
value|((*(_ah)->ah_setChannel)((_ah), (_chan)))
end_define

begin_define
define|#
directive|define
name|ath_hal_calibrate
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|,
name|_iqcal
parameter_list|)
define|\
value|((*(_ah)->ah_perCalibration)((_ah), (_chan), (_iqcal)))
end_define

begin_define
define|#
directive|define
name|ath_hal_calibrateN
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|,
name|_lcal
parameter_list|,
name|_isdone
parameter_list|)
define|\
value|((*(_ah)->ah_perCalibrationN)((_ah), (_chan), 0x1, (_lcal), (_isdone)))
end_define

begin_define
define|#
directive|define
name|ath_hal_calreset
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|)
define|\
value|((*(_ah)->ah_resetCalValid)((_ah), (_chan)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setledstate
parameter_list|(
name|_ah
parameter_list|,
name|_state
parameter_list|)
define|\
value|((*(_ah)->ah_setLedState)((_ah), (_state)))
end_define

begin_define
define|#
directive|define
name|ath_hal_beaconinit
parameter_list|(
name|_ah
parameter_list|,
name|_nextb
parameter_list|,
name|_bperiod
parameter_list|)
define|\
value|((*(_ah)->ah_beaconInit)((_ah), (_nextb), (_bperiod)))
end_define

begin_define
define|#
directive|define
name|ath_hal_beaconreset
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_resetStationBeaconTimers)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_beaconsettimers
parameter_list|(
name|_ah
parameter_list|,
name|_bt
parameter_list|)
define|\
value|((*(_ah)->ah_setBeaconTimers)((_ah), (_bt)))
end_define

begin_define
define|#
directive|define
name|ath_hal_beacontimers
parameter_list|(
name|_ah
parameter_list|,
name|_bs
parameter_list|)
define|\
value|((*(_ah)->ah_setStationBeaconTimers)((_ah), (_bs)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getnexttbtt
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getNextTBTT)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setassocid
parameter_list|(
name|_ah
parameter_list|,
name|_bss
parameter_list|,
name|_associd
parameter_list|)
define|\
value|((*(_ah)->ah_writeAssocid)((_ah), (_bss), (_associd)))
end_define

begin_define
define|#
directive|define
name|ath_hal_phydisable
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_phyDisable)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setopmode
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_setPCUConfig)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_stoptxdma
parameter_list|(
name|_ah
parameter_list|,
name|_qnum
parameter_list|)
define|\
value|((*(_ah)->ah_stopTxDma)((_ah), (_qnum)))
end_define

begin_define
define|#
directive|define
name|ath_hal_stoppcurecv
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_stopPcuReceive)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_startpcurecv
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_startPcuReceive)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_stopdmarecv
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_stopDmaReceive)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getdiagstate
parameter_list|(
name|_ah
parameter_list|,
name|_id
parameter_list|,
name|_indata
parameter_list|,
name|_insize
parameter_list|,
name|_outdata
parameter_list|,
name|_outsize
parameter_list|)
define|\
value|((*(_ah)->ah_getDiagState)((_ah), (_id), \ 		(_indata), (_insize), (_outdata), (_outsize)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getfatalstate
parameter_list|(
name|_ah
parameter_list|,
name|_outdata
parameter_list|,
name|_outsize
parameter_list|)
define|\
value|ath_hal_getdiagstate(_ah, 29, NULL, 0, (_outdata), _outsize)
end_define

begin_define
define|#
directive|define
name|ath_hal_setuptxqueue
parameter_list|(
name|_ah
parameter_list|,
name|_type
parameter_list|,
name|_irq
parameter_list|)
define|\
value|((*(_ah)->ah_setupTxQueue)((_ah), (_type), (_irq)))
end_define

begin_define
define|#
directive|define
name|ath_hal_resettxqueue
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_resetTxQueue)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_releasetxqueue
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|)
define|\
value|((*(_ah)->ah_releaseTxQueue)((_ah), (_q)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxqueueprops
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|,
name|_qi
parameter_list|)
define|\
value|((*(_ah)->ah_getTxQueueProps)((_ah), (_q), (_qi)))
end_define

begin_define
define|#
directive|define
name|ath_hal_settxqueueprops
parameter_list|(
name|_ah
parameter_list|,
name|_q
parameter_list|,
name|_qi
parameter_list|)
define|\
value|((*(_ah)->ah_setTxQueueProps)((_ah), (_q), (_qi)))
end_define

begin_comment
comment|/* NB: common across all chips */
end_comment

begin_define
define|#
directive|define
name|AR_Q_TXE
value|0x0840
end_define

begin_comment
comment|/* MAC Transmit Queue enable */
end_comment

begin_define
define|#
directive|define
name|ath_hal_txqenabled
parameter_list|(
name|_ah
parameter_list|,
name|_qnum
parameter_list|)
define|\
value|(OS_REG_READ(_ah, AR_Q_TXE)& (1<<(_qnum)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getrfgain
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getRfGain)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getdefantenna
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getDefAntenna)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setdefantenna
parameter_list|(
name|_ah
parameter_list|,
name|_ant
parameter_list|)
define|\
value|((*(_ah)->ah_setDefAntenna)((_ah), (_ant)))
end_define

begin_define
define|#
directive|define
name|ath_hal_rxmonitor
parameter_list|(
name|_ah
parameter_list|,
name|_arg
parameter_list|,
name|_chan
parameter_list|)
define|\
value|((*(_ah)->ah_rxMonitor)((_ah), (_arg), (_chan)))
end_define

begin_define
define|#
directive|define
name|ath_hal_ani_poll
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|)
define|\
value|((*(_ah)->ah_aniPoll)((_ah), (_chan)))
end_define

begin_define
define|#
directive|define
name|ath_hal_mibevent
parameter_list|(
name|_ah
parameter_list|,
name|_stats
parameter_list|)
define|\
value|((*(_ah)->ah_procMibEvent)((_ah), (_stats)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setslottime
parameter_list|(
name|_ah
parameter_list|,
name|_us
parameter_list|)
define|\
value|((*(_ah)->ah_setSlotTime)((_ah), (_us)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getslottime
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getSlotTime)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setacktimeout
parameter_list|(
name|_ah
parameter_list|,
name|_us
parameter_list|)
define|\
value|((*(_ah)->ah_setAckTimeout)((_ah), (_us)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getacktimeout
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getAckTimeout)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setctstimeout
parameter_list|(
name|_ah
parameter_list|,
name|_us
parameter_list|)
define|\
value|((*(_ah)->ah_setCTSTimeout)((_ah), (_us)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getctstimeout
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getCTSTimeout)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getcapability
parameter_list|(
name|_ah
parameter_list|,
name|_cap
parameter_list|,
name|_param
parameter_list|,
name|_result
parameter_list|)
define|\
value|((*(_ah)->ah_getCapability)((_ah), (_cap), (_param), (_result)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setcapability
parameter_list|(
name|_ah
parameter_list|,
name|_cap
parameter_list|,
name|_param
parameter_list|,
name|_v
parameter_list|,
name|_status
parameter_list|)
define|\
value|((*(_ah)->ah_setCapability)((_ah), (_cap), (_param), (_v), (_status)))
end_define

begin_define
define|#
directive|define
name|ath_hal_ciphersupported
parameter_list|(
name|_ah
parameter_list|,
name|_cipher
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_CIPHER, _cipher, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getregdomain
parameter_list|(
name|_ah
parameter_list|,
name|_prd
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_REG_DMN, 0, (_prd)) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setregdomain
parameter_list|(
name|_ah
parameter_list|,
name|_rd
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_REG_DMN, 0, _rd, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_getcountrycode
parameter_list|(
name|_ah
parameter_list|,
name|_pcc
parameter_list|)
define|\
value|(*(_pcc) = (_ah)->ah_countryCode)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettkipmic
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TKIP_MIC, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_settkipmic
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_TKIP_MIC, 1, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hastkipsplit
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TKIP_SPLIT, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettkipsplit
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TKIP_SPLIT, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_settkipsplit
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_TKIP_SPLIT, 1, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_haswmetkipmic
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_WME_TKIPMIC, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hwphycounters
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_PHYCOUNTERS, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasdiversity
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_DIVERSITY, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getdiversity
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_DIVERSITY, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setdiversity
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_DIVERSITY, 1, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_getantennaswitch
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getAntennaSwitch)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setantennaswitch
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|((*(_ah)->ah_setAntennaSwitch)((_ah), (_v)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getdiag
parameter_list|(
name|_ah
parameter_list|,
name|_pv
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_DIAG, 0, _pv) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setdiag
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_DIAG, 0, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_getnumtxqueues
parameter_list|(
name|_ah
parameter_list|,
name|_pv
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_NUM_TXQUEUES, 0, _pv) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasveol
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_VEOL, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hastxpowlimit
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TXPOW, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_settxpowlimit
parameter_list|(
name|_ah
parameter_list|,
name|_pow
parameter_list|)
define|\
value|((*(_ah)->ah_setTxPowerLimit)((_ah), (_pow)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxpowlimit
parameter_list|(
name|_ah
parameter_list|,
name|_ppow
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TXPOW, 1, _ppow) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getmaxtxpow
parameter_list|(
name|_ah
parameter_list|,
name|_ppow
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TXPOW, 2, _ppow) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettpscale
parameter_list|(
name|_ah
parameter_list|,
name|_scale
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TXPOW, 3, _scale) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_settpscale
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_TXPOW, 3, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hastpc
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TPC, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettpc
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TPC, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_settpc
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_TPC, 1, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasbursting
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_BURST, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setmcastkeysearch
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_MCAST_KEYSRCH, 0, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasmcastkeysearch
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_MCAST_KEYSRCH, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getmcastkeysearch
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_MCAST_KEYSRCH, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasfastframes
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_FASTFRAME, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasbssidmask
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_BSSIDMASK, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasbssidmatch
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_BSSIDMATCH, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hastsfadjust
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TSF_ADJUST, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettsfadjust
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TSF_ADJUST, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_settsfadjust
parameter_list|(
name|_ah
parameter_list|,
name|_onoff
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_TSF_ADJUST, 1, _onoff, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasrfsilent
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RFSILENT, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getrfkill
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RFSILENT, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setrfkill
parameter_list|(
name|_ah
parameter_list|,
name|_onoff
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_RFSILENT, 1, _onoff, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_getrfsilent
parameter_list|(
name|_ah
parameter_list|,
name|_prfsilent
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RFSILENT, 2, _prfsilent) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setrfsilent
parameter_list|(
name|_ah
parameter_list|,
name|_rfsilent
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_RFSILENT, 2, _rfsilent, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettpack
parameter_list|(
name|_ah
parameter_list|,
name|_ptpack
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TPC_ACK, 0, _ptpack) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_settpack
parameter_list|(
name|_ah
parameter_list|,
name|_tpack
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_TPC_ACK, 0, _tpack, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettpcts
parameter_list|(
name|_ah
parameter_list|,
name|_ptpcts
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TPC_CTS, 0, _ptpcts) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_settpcts
parameter_list|(
name|_ah
parameter_list|,
name|_tpcts
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_TPC_CTS, 0, _tpcts, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasintmit
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_INTMIT, \ 	HAL_CAP_INTMIT_PRESENT, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getintmit
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_INTMIT, \ 	HAL_CAP_INTMIT_ENABLE, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setintmit
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_INTMIT, \ 	HAL_CAP_INTMIT_ENABLE, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasmybeacon
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_DO_MYBEACON, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasenforcetxop
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_ENFORCE_TXOP, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getenforcetxop
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_ENFORCE_TXOP, 1, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setenforcetxop
parameter_list|(
name|_ah
parameter_list|,
name|_v
parameter_list|)
define|\
value|ath_hal_setcapability(_ah, HAL_CAP_ENFORCE_TXOP, 1, _v, NULL)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasrxlnamixer
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RX_LNA_MIXING, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_hasdivantcomb
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_ANT_DIV_COMB, 0, NULL) == HAL_OK)
end_define

begin_comment
comment|/* EDMA definitions */
end_comment

begin_define
define|#
directive|define
name|ath_hal_hasedma
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_ENHANCED_DMA_SUPPORT,	\ 	0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getrxfifodepth
parameter_list|(
name|_ah
parameter_list|,
name|_qtype
parameter_list|,
name|_req
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RXFIFODEPTH, _qtype, _req)	\ 	== HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getntxmaps
parameter_list|(
name|_ah
parameter_list|,
name|_req
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_NUM_TXMAPS, 0, _req)	\ 	== HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxdesclen
parameter_list|(
name|_ah
parameter_list|,
name|_req
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TXDESCLEN, 0, _req)		\ 	== HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxstatuslen
parameter_list|(
name|_ah
parameter_list|,
name|_req
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TXSTATUSLEN, 0, _req)	\ 	== HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getrxstatuslen
parameter_list|(
name|_ah
parameter_list|,
name|_req
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RXSTATUSLEN, 0, _req)	\ 	== HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setrxbufsize
parameter_list|(
name|_ah
parameter_list|,
name|_req
parameter_list|)
define|\
value|(ath_hal_setcapability(_ah, HAL_CAP_RXBUFSIZE, 0, _req, NULL)	\ 	== HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_getchannoise
parameter_list|(
name|_ah
parameter_list|,
name|_c
parameter_list|)
define|\
value|((*(_ah)->ah_getChanNoise)((_ah), (_c)))
end_define

begin_comment
comment|/* 802.11n HAL methods */
end_comment

begin_define
define|#
directive|define
name|ath_hal_getrxchainmask
parameter_list|(
name|_ah
parameter_list|,
name|_prxchainmask
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RX_CHAINMASK, 0, _prxchainmask))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxchainmask
parameter_list|(
name|_ah
parameter_list|,
name|_ptxchainmask
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_TX_CHAINMASK, 0, _ptxchainmask))
end_define

begin_define
define|#
directive|define
name|ath_hal_setrxchainmask
parameter_list|(
name|_ah
parameter_list|,
name|_rx
parameter_list|)
define|\
value|(ath_hal_setcapability(_ah, HAL_CAP_RX_CHAINMASK, 1, _rx, NULL))
end_define

begin_define
define|#
directive|define
name|ath_hal_settxchainmask
parameter_list|(
name|_ah
parameter_list|,
name|_tx
parameter_list|)
define|\
value|(ath_hal_setcapability(_ah, HAL_CAP_TX_CHAINMASK, 1, _tx, NULL))
end_define

begin_define
define|#
directive|define
name|ath_hal_split4ktrans
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_SPLIT_4KB_TRANS, \ 	0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_self_linked_final_rxdesc
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_RXDESC_SELFLINK, \ 	0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_gtxto_supported
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_GTXTO, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_has_long_rxdesc_tsf
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_LONG_RXDESC_TSF, \ 	0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_setuprxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_size
parameter_list|,
name|_intreq
parameter_list|)
define|\
value|((*(_ah)->ah_setupRxDesc)((_ah), (_ds), (_size), (_intreq)))
end_define

begin_define
define|#
directive|define
name|ath_hal_rxprocdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_dspa
parameter_list|,
name|_dsnext
parameter_list|,
name|_rs
parameter_list|)
define|\
value|((*(_ah)->ah_procRxDesc)((_ah), (_ds), (_dspa), (_dsnext), 0, (_rs)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setuptxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_plen
parameter_list|,
name|_hlen
parameter_list|,
name|_atype
parameter_list|,
name|_txpow
parameter_list|, \
name|_txr0
parameter_list|,
name|_txtr0
parameter_list|,
name|_keyix
parameter_list|,
name|_ant
parameter_list|,
name|_flags
parameter_list|, \
name|_rtsrate
parameter_list|,
name|_rtsdura
parameter_list|)
define|\
value|((*(_ah)->ah_setupTxDesc)((_ah), (_ds), (_plen), (_hlen), (_atype), \ 		(_txpow), (_txr0), (_txtr0), (_keyix), (_ant), \ 		(_flags), (_rtsrate), (_rtsdura), 0, 0, 0))
end_define

begin_define
define|#
directive|define
name|ath_hal_setupxtxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|, \
name|_txr1
parameter_list|,
name|_txtr1
parameter_list|,
name|_txr2
parameter_list|,
name|_txtr2
parameter_list|,
name|_txr3
parameter_list|,
name|_txtr3
parameter_list|)
define|\
value|((*(_ah)->ah_setupXTxDesc)((_ah), (_ds), \ 		(_txr1), (_txtr1), (_txr2), (_txtr2), (_txr3), (_txtr3)))
end_define

begin_define
define|#
directive|define
name|ath_hal_filltxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_b
parameter_list|,
name|_l
parameter_list|,
name|_did
parameter_list|,
name|_qid
parameter_list|,
name|_first
parameter_list|,
name|_last
parameter_list|,
name|_ds0
parameter_list|)
define|\
value|((*(_ah)->ah_fillTxDesc)((_ah), (_ds), (_b), (_l), (_did), (_qid), \ 		(_first), (_last), (_ds0)))
end_define

begin_define
define|#
directive|define
name|ath_hal_txprocdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_ts
parameter_list|)
define|\
value|((*(_ah)->ah_procTxDesc)((_ah), (_ds), (_ts)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxintrtxqs
parameter_list|(
name|_ah
parameter_list|,
name|_txqs
parameter_list|)
define|\
value|((*(_ah)->ah_getTxIntrQueue)((_ah), (_txqs)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxcompletionrates
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_rates
parameter_list|,
name|_tries
parameter_list|)
define|\
value|((*(_ah)->ah_getTxCompletionRates)((_ah), (_ds), (_rates), (_tries)))
end_define

begin_define
define|#
directive|define
name|ath_hal_settxdesclink
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_link
parameter_list|)
define|\
value|((*(_ah)->ah_setTxDescLink)((_ah), (_ds), (_link)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxdesclink
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_link
parameter_list|)
define|\
value|((*(_ah)->ah_getTxDescLink)((_ah), (_ds), (_link)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxdesclinkptr
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_linkptr
parameter_list|)
define|\
value|((*(_ah)->ah_getTxDescLinkPtr)((_ah), (_ds), (_linkptr)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setuptxstatusring
parameter_list|(
name|_ah
parameter_list|,
name|_tsstart
parameter_list|,
name|_tspstart
parameter_list|,
name|_size
parameter_list|)
define|\
value|((*(_ah)->ah_setupTxStatusRing)((_ah), (_tsstart), (_tspstart), \ 		(_size)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettxrawtxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_txstatus
parameter_list|)
define|\
value|((*(_ah)->ah_getTxRawTxDesc)((_ah), (_txstatus)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setupfirsttxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_aggrlen
parameter_list|,
name|_flags
parameter_list|,
name|_txpower
parameter_list|, \
name|_txr0
parameter_list|,
name|_txtr0
parameter_list|,
name|_antm
parameter_list|,
name|_rcr
parameter_list|,
name|_rcd
parameter_list|)
define|\
value|((*(_ah)->ah_setupFirstTxDesc)((_ah), (_ds), (_aggrlen), (_flags), \ 	(_txpower), (_txr0), (_txtr0), (_antm), (_rcr), (_rcd)))
end_define

begin_define
define|#
directive|define
name|ath_hal_chaintxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_bl
parameter_list|,
name|_sl
parameter_list|,
name|_pktlen
parameter_list|,
name|_hdrlen
parameter_list|,
name|_type
parameter_list|, \
name|_keyix
parameter_list|,
name|_cipher
parameter_list|,
name|_delims
parameter_list|,
name|_first
parameter_list|,
name|_last
parameter_list|,
name|_lastaggr
parameter_list|)
define|\
value|((*(_ah)->ah_chainTxDesc)((_ah), (_ds), (_bl), (_sl), \ 	(_pktlen), (_hdrlen), (_type), (_keyix), (_cipher), (_delims), \ 	(_first), (_last), (_lastaggr)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setuplasttxdesc
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_ds0
parameter_list|)
define|\
value|((*(_ah)->ah_setupLastTxDesc)((_ah), (_ds), (_ds0)))
end_define

begin_define
define|#
directive|define
name|ath_hal_set11nratescenario
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_dur
parameter_list|,
name|_rt
parameter_list|,
name|_series
parameter_list|,
name|_ns
parameter_list|,
name|_flags
parameter_list|)
define|\
value|((*(_ah)->ah_set11nRateScenario)((_ah), (_ds), (_dur), (_rt), \ 	(_series), (_ns), (_flags)))
end_define

begin_define
define|#
directive|define
name|ath_hal_set11n_aggr_first
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_len
parameter_list|,
name|_num
parameter_list|)
define|\
value|((*(_ah)->ah_set11nAggrFirst)((_ah), (_ds), (_len), (_num)))
end_define

begin_define
define|#
directive|define
name|ath_hal_set11n_aggr_middle
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_num
parameter_list|)
define|\
value|((*(_ah)->ah_set11nAggrMiddle)((_ah), (_ds), (_num)))
end_define

begin_define
define|#
directive|define
name|ath_hal_set11n_aggr_last
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|)
define|\
value|((*(_ah)->ah_set11nAggrLast)((_ah), (_ds)))
end_define

begin_define
define|#
directive|define
name|ath_hal_set11nburstduration
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_dur
parameter_list|)
define|\
value|((*(_ah)->ah_set11nBurstDuration)((_ah), (_ds), (_dur)))
end_define

begin_define
define|#
directive|define
name|ath_hal_clr11n_aggr
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|)
define|\
value|((*(_ah)->ah_clr11nAggr)((_ah), (_ds)))
end_define

begin_define
define|#
directive|define
name|ath_hal_set11n_virtmorefrag
parameter_list|(
name|_ah
parameter_list|,
name|_ds
parameter_list|,
name|_v
parameter_list|)
define|\
value|((*(_ah)->ah_set11nVirtMoreFrag)((_ah), (_ds), (_v)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gpioCfgOutput
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|,
name|_type
parameter_list|)
define|\
value|((*(_ah)->ah_gpioCfgOutput)((_ah), (_gpio), (_type)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gpioset
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|,
name|_b
parameter_list|)
define|\
value|((*(_ah)->ah_gpioSet)((_ah), (_gpio), (_b)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gpioget
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|)
define|\
value|((*(_ah)->ah_gpioGet)((_ah), (_gpio)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gpiosetintr
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|,
name|_b
parameter_list|)
define|\
value|((*(_ah)->ah_gpioSetIntr)((_ah), (_gpio), (_b)))
end_define

begin_comment
comment|/*  * PCIe suspend/resume/poweron/poweroff related macros  */
end_comment

begin_define
define|#
directive|define
name|ath_hal_enablepcie
parameter_list|(
name|_ah
parameter_list|,
name|_restore
parameter_list|,
name|_poweroff
parameter_list|)
define|\
value|((*(_ah)->ah_configPCIE)((_ah), (_restore), (_poweroff)))
end_define

begin_define
define|#
directive|define
name|ath_hal_disablepcie
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_disablePCIE)((_ah)))
end_define

begin_comment
comment|/*  * This is badly-named; you need to set the correct parameters  * to begin to receive useful radar events; and even then  * it doesn't "enable" DFS. See the ath_dfs/null/ module for  * more information.  */
end_comment

begin_define
define|#
directive|define
name|ath_hal_enabledfs
parameter_list|(
name|_ah
parameter_list|,
name|_param
parameter_list|)
define|\
value|((*(_ah)->ah_enableDfs)((_ah), (_param)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getdfsthresh
parameter_list|(
name|_ah
parameter_list|,
name|_param
parameter_list|)
define|\
value|((*(_ah)->ah_getDfsThresh)((_ah), (_param)))
end_define

begin_define
define|#
directive|define
name|ath_hal_getdfsdefaultthresh
parameter_list|(
name|_ah
parameter_list|,
name|_param
parameter_list|)
define|\
value|((*(_ah)->ah_getDfsDefaultThresh)((_ah), (_param)))
end_define

begin_define
define|#
directive|define
name|ath_hal_procradarevent
parameter_list|(
name|_ah
parameter_list|,
name|_rxs
parameter_list|,
name|_fulltsf
parameter_list|,
name|_buf
parameter_list|,
name|_event
parameter_list|)
define|\
value|((*(_ah)->ah_procRadarEvent)((_ah), (_rxs), (_fulltsf), \ 	(_buf), (_event)))
end_define

begin_define
define|#
directive|define
name|ath_hal_is_fast_clock_enabled
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_isFastClockEnabled)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_radar_wait
parameter_list|(
name|_ah
parameter_list|,
name|_chan
parameter_list|)
define|\
value|((*(_ah)->ah_radarWait)((_ah), (_chan)))
end_define

begin_define
define|#
directive|define
name|ath_hal_get_mib_cycle_counts
parameter_list|(
name|_ah
parameter_list|,
name|_sample
parameter_list|)
define|\
value|((*(_ah)->ah_getMibCycleCounts)((_ah), (_sample)))
end_define

begin_define
define|#
directive|define
name|ath_hal_get_chan_ext_busy
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_get11nExtBusy)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_setchainmasks
parameter_list|(
name|_ah
parameter_list|,
name|_txchainmask
parameter_list|,
name|_rxchainmask
parameter_list|)
define|\
value|((*(_ah)->ah_setChainMasks)((_ah), (_txchainmask), (_rxchainmask)))
end_define

begin_define
define|#
directive|define
name|ath_hal_spectral_supported
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_SPECTRAL_SCAN, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_spectral_get_config
parameter_list|(
name|_ah
parameter_list|,
name|_p
parameter_list|)
define|\
value|((*(_ah)->ah_spectralGetConfig)((_ah), (_p)))
end_define

begin_define
define|#
directive|define
name|ath_hal_spectral_configure
parameter_list|(
name|_ah
parameter_list|,
name|_p
parameter_list|)
define|\
value|((*(_ah)->ah_spectralConfigure)((_ah), (_p)))
end_define

begin_define
define|#
directive|define
name|ath_hal_spectral_start
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_spectralStart)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_spectral_stop
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_spectralStop)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_supported
parameter_list|(
name|_ah
parameter_list|)
define|\
value|(ath_hal_getcapability(_ah, HAL_CAP_BT_COEX, 0, NULL) == HAL_OK)
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_set_info
parameter_list|(
name|_ah
parameter_list|,
name|_info
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexSetInfo)((_ah), (_info)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_set_config
parameter_list|(
name|_ah
parameter_list|,
name|_cfg
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexSetConfig)((_ah), (_cfg)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_set_qcu_thresh
parameter_list|(
name|_ah
parameter_list|,
name|_qcuid
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexSetQcuThresh)((_ah), (_qcuid)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_set_weights
parameter_list|(
name|_ah
parameter_list|,
name|_weight
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexSetWeights)((_ah), (_weight)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_set_weights
parameter_list|(
name|_ah
parameter_list|,
name|_weight
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexSetWeights)((_ah), (_weight)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_set_bmiss_thresh
parameter_list|(
name|_ah
parameter_list|,
name|_thr
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexSetBmissThresh)((_ah), (_thr)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_set_parameter
parameter_list|(
name|_ah
parameter_list|,
name|_attrib
parameter_list|,
name|_val
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexSetParameter)((_ah), (_attrib), (_val)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_enable
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexEnable)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_btcoex_disable
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_btCoexDisable)((_ah)))
end_define

begin_define
define|#
directive|define
name|ath_hal_div_comb_conf_get
parameter_list|(
name|_ah
parameter_list|,
name|_conf
parameter_list|)
define|\
value|((*(_ah)->ah_divLnaConfGet)((_ah), (_conf)))
end_define

begin_define
define|#
directive|define
name|ath_hal_div_comb_conf_set
parameter_list|(
name|_ah
parameter_list|,
name|_conf
parameter_list|)
define|\
value|((*(_ah)->ah_divLnaConfSet)((_ah), (_conf)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_ATHVAR_H */
end_comment

end_unit

