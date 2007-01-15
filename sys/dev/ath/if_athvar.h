begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2006 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
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
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/ath/ah.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/ath/ah_desc.h>
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

begin_define
define|#
directive|define
name|ATH_TIMEOUT
value|1000
end_define

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
value|100
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
value|0
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
name|u_int32_t
name|an_avgrssi
decl_stmt|;
comment|/* average rssi over all rx frames */
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

begin_struct
struct|struct
name|ath_buf
block|{
name|STAILQ_ENTRY
argument_list|(
argument|ath_buf
argument_list|)
name|bf_list
expr_stmt|;
name|int
name|bf_nseg
decl_stmt|;
name|int
name|bf_flags
decl_stmt|;
comment|/* tx descriptor flags */
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
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ath_buf
argument_list|)
name|ath_bufhead
expr_stmt|;
end_typedef

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
name|u_int
name|axq_qnum
decl_stmt|;
comment|/* hardware q number */
name|u_int
name|axq_depth
decl_stmt|;
comment|/* queue depth (stat only) */
name|u_int
name|axq_intrcnt
decl_stmt|;
comment|/* interrupt count */
name|u_int32_t
modifier|*
name|axq_link
decl_stmt|;
comment|/* link ptr in last TX desc */
name|STAILQ_HEAD
argument_list|(
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
name|char
name|axq_name
index|[
literal|12
index|]
decl_stmt|;
comment|/* e.g. "ath0_txq4" */
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
value|do { \ 	snprintf((_tq)->axq_name, sizeof((_tq)->axq_name), "%s_txq%u", \ 		device_get_nameunit((_sc)->sc_dev), (_tq)->axq_qnum); \ 	mtx_init(&(_tq)->axq_lock, (_tq)->axq_name, "ath_txq", MTX_DEF); \ } while (0)
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
name|ATH_TXQ_INSERT_TAIL
parameter_list|(
name|_tq
parameter_list|,
name|_elm
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	STAILQ_INSERT_TAIL(&(_tq)->axq_q, (_elm), _field); \ 	(_tq)->axq_depth++; \ } while (0)
end_define

begin_define
define|#
directive|define
name|ATH_TXQ_REMOVE_HEAD
parameter_list|(
name|_tq
parameter_list|,
name|_field
parameter_list|)
value|do { \ 	STAILQ_REMOVE_HEAD(&(_tq)->axq_q, _field); \ 	(_tq)->axq_depth--; \ } while (0)
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
name|ieee80211com
name|sc_ic
decl_stmt|;
comment|/* IEEE 802.11 common */
name|int
name|sc_debug
decl_stmt|;
name|u_int32_t
name|sc_countrycode
decl_stmt|;
name|u_int32_t
name|sc_regdomain
decl_stmt|;
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
name|unsigned
name|int
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
name|sc_softled
range|:
literal|1
decl_stmt|,
comment|/* enable LED gpio status */
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
decl_stmt|;
comment|/* outdoor operation */
comment|/* rate tables */
define|#
directive|define
name|IEEE80211_MODE_HALF
value|(IEEE80211_MODE_MAX+0)
define|#
directive|define
name|IEEE80211_MODE_QUARTER
value|(IEEE80211_MODE_MAX+1)
specifier|const
name|HAL_RATE_TABLE
modifier|*
name|sc_rates
index|[
name|IEEE80211_MODE_MAX
operator|+
literal|2
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
name|HAL_CHANNEL
name|sc_curchan
decl_stmt|;
comment|/* current h/w channel */
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
name|sc_minrateix
decl_stmt|;
comment|/* min h/w rate index */
name|u_int8_t
name|sc_mcastrix
decl_stmt|;
comment|/* mcast h/w rate index */
name|u_int8_t
name|sc_protrix
decl_stmt|;
comment|/* protection rate index */
name|u_int
name|sc_mcastrate
decl_stmt|;
comment|/* ieee rate for mcastrateix */
name|u_int
name|sc_txantenna
decl_stmt|;
comment|/* tx antenna (fixed or auto) */
name|HAL_INT
name|sc_imask
decl_stmt|;
comment|/* interrupt mask copy */
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
name|sc_rxrate
decl_stmt|;
comment|/* current rx rate for LED */
name|u_int8_t
name|sc_txrate
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
name|u_int
name|sc_rfsilentpin
decl_stmt|;
comment|/* GPIO pin for rfkill int */
name|u_int
name|sc_rfsilentpol
decl_stmt|;
comment|/* pin setting for rfkill on */
name|struct
name|bpf_if
modifier|*
name|sc_drvbpf
decl_stmt|;
union|union
block|{
name|struct
name|ath_tx_radiotap_header
name|th
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|64
index|]
decl_stmt|;
block|}
name|u_tx_rt
union|;
name|int
name|sc_tx_th_len
decl_stmt|;
union|union
block|{
name|struct
name|ath_rx_radiotap_header
name|th
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|64
index|]
decl_stmt|;
block|}
name|u_rx_rt
union|;
name|int
name|sc_rx_th_len
decl_stmt|;
name|u_int
name|sc_monpass
decl_stmt|;
comment|/* frames to pass in mon.mode */
name|struct
name|ath_descdma
name|sc_rxdma
decl_stmt|;
comment|/* RX descriptos */
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
name|struct
name|task
name|sc_rxorntask
decl_stmt|;
comment|/* rxorn int processing */
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
name|ath_descdma
name|sc_txdma
decl_stmt|;
comment|/* TX descriptors */
name|ath_bufhead
name|sc_txbuf
decl_stmt|;
comment|/* transmit buffer */
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
name|int
name|sc_tx_timer
decl_stmt|;
comment|/* transmit timeout */
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
name|ieee80211_beacon_offsets
name|sc_boff
decl_stmt|;
comment|/* dynamic update state */
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
name|struct
name|ath_txq
name|sc_mcastq
decl_stmt|;
comment|/* mcast xmits w/ ps sta's */
name|struct
name|callout
name|sc_cal_ch
decl_stmt|;
comment|/* callout handle for cals */
name|int
name|sc_calinterval
decl_stmt|;
comment|/* current polling interval */
name|int
name|sc_caltries
decl_stmt|;
comment|/* cals at current interval */
name|HAL_NODE_STATS
name|sc_halstats
decl_stmt|;
comment|/* station-mode rssi stats */
name|struct
name|callout
name|sc_scan_ch
decl_stmt|;
comment|/* callout handle for scan */
name|struct
name|callout
name|sc_dfs_ch
decl_stmt|;
comment|/* callout handle for dfs */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sc_tx_th
value|u_tx_rt.th
end_define

begin_define
define|#
directive|define
name|sc_rx_th
value|u_rx_rt.th
end_define

begin_define
define|#
directive|define
name|ATH_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|)
define|\
value|mtx_init(&(_sc)->sc_mtx, device_get_nameunit((_sc)->sc_dev), \ 		 MTX_NETWORK_LOCK, MTX_DEF | MTX_RECURSE)
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
value|do { \ 	snprintf((_sc)->sc_txname, sizeof((_sc)->sc_txname), "%s_buf", \ 		device_get_nameunit((_sc)->sc_dev)); \ 	mtx_init(&(_sc)->sc_txbuflock, (_sc)->sc_txname, "ath_buf", MTX_DEF); \ } while (0)
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
parameter_list|)
define|\
value|((*(_ah)->ah_setRxDP)((_ah), (_bufaddr)))
end_define

begin_define
define|#
directive|define
name|ath_hal_gettsf32
parameter_list|(
name|_ah
parameter_list|)
define|\
value|((*(_ah)->ah_getTsf32)((_ah)))
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
parameter_list|)
define|\
value|((*(_ah)->ah_getRxDP)((_ah)))
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
value|ath_hal_getdiagstate(_ah, 29, NULL, 0, (void **)(_outdata), _outsize)
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
value|((*(_ah)->ah_setRegulatoryDomain)((_ah), (_rd), NULL))
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

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ath_hal_getmcastkeysearch
parameter_list|(
name|_ah
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|HAL_ABI_VERSION
operator|<
literal|0x05120700
end_if

begin_define
define|#
directive|define
name|ath_hal_process_noisefloor
parameter_list|(
name|_ah
parameter_list|)
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
value|(-96)
end_define

begin_define
define|#
directive|define
name|HAL_CAP_TPC_ACK
value|100
end_define

begin_define
define|#
directive|define
name|HAL_CAP_TPC_CTS
value|101
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAL_ABI_VERSION
operator|<
literal|0x05122200
end_if

begin_define
define|#
directive|define
name|HAL_TXQ_TXOKINT_ENABLE
value|TXQ_FLAG_TXOKINT_ENABLE
end_define

begin_define
define|#
directive|define
name|HAL_TXQ_TXERRINT_ENABLE
value|TXQ_FLAG_TXERRINT_ENABLE
end_define

begin_define
define|#
directive|define
name|HAL_TXQ_TXDESCINT_ENABLE
value|TXQ_FLAG_TXDESCINT_ENABLE
end_define

begin_define
define|#
directive|define
name|HAL_TXQ_TXEOLINT_ENABLE
value|TXQ_FLAG_TXEOLINT_ENABLE
end_define

begin_define
define|#
directive|define
name|HAL_TXQ_TXURNINT_ENABLE
value|TXQ_FLAG_TXURNINT_ENABLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAL_ABI_VERSION
operator|<
literal|0x06102501
end_if

begin_define
define|#
directive|define
name|ath_hal_ispublicsafetysku
parameter_list|(
name|ah
parameter_list|)
define|\
value|(((ah)->ah_regdomain == 0&& (ah)->ah_countryCode == 842) || \ 	 (ah)->ah_regdomain == 0x12)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|_l
parameter_list|,
name|_first
parameter_list|,
name|_last
parameter_list|,
name|_ds0
parameter_list|)
define|\
value|((*(_ah)->ah_fillTxDesc)((_ah), (_ds), (_l), (_first), (_last), (_ds0)))
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
name|ath_hal_gpioCfgOutput
parameter_list|(
name|_ah
parameter_list|,
name|_gpio
parameter_list|)
define|\
value|((*(_ah)->ah_gpioCfgOutput)((_ah), (_gpio)))
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_ATHVAR_H */
end_comment

end_unit

