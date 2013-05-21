begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ATH_TX_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ATH_TX_H__
end_define

begin_comment
comment|/*  * some general macros  */
end_comment

begin_define
define|#
directive|define
name|INCR
parameter_list|(
name|_l
parameter_list|,
name|_sz
parameter_list|)
value|(_l) ++; (_l)&= ((_sz) - 1)
end_define

begin_comment
comment|/*  * return block-ack bitmap index given sequence and starting sequence  */
end_comment

begin_define
define|#
directive|define
name|ATH_BA_INDEX
parameter_list|(
name|_st
parameter_list|,
name|_seq
parameter_list|)
value|(((_seq) - (_st))& (IEEE80211_SEQ_RANGE - 1))
end_define

begin_define
define|#
directive|define
name|WME_BA_BMP_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|WME_MAX_BA
value|WME_BA_BMP_SIZE
end_define

begin_comment
comment|/*  * How 'busy' to try and keep the hardware txq  */
end_comment

begin_define
define|#
directive|define
name|ATH_AGGR_MIN_QDEPTH
value|2
end_define

begin_define
define|#
directive|define
name|ATH_NONAGGR_MIN_QDEPTH
value|32
end_define

begin_comment
comment|/*  * Watermark for scheduling TIDs in order to maximise aggregation.  *  * If hwq_depth is greater than this, don't schedule the TID  * for packet scheduling - the hardware is already busy servicing  * this TID.  *  * If hwq_depth is less than this, schedule the TID for packet  * scheduling in the completion handler.  */
end_comment

begin_define
define|#
directive|define
name|ATH_AGGR_SCHED_HIGH
value|4
end_define

begin_define
define|#
directive|define
name|ATH_AGGR_SCHED_LOW
value|2
end_define

begin_comment
comment|/*  * return whether a bit at index _n in bitmap _bm is set  * _sz is the size of the bitmap  */
end_comment

begin_define
define|#
directive|define
name|ATH_BA_ISSET
parameter_list|(
name|_bm
parameter_list|,
name|_n
parameter_list|)
value|(((_n)< (WME_BA_BMP_SIZE))&&		\ 	    ((_bm)[(_n)>> 5]& (1<< ((_n)& 31))))
end_define

begin_comment
comment|/* extracting the seqno from buffer seqno */
end_comment

begin_define
define|#
directive|define
name|SEQNO
parameter_list|(
name|_a
parameter_list|)
value|((_a)>> IEEE80211_SEQ_SEQ_SHIFT)
end_define

begin_comment
comment|/*  * Whether the current sequence number is within the  * BAW.  */
end_comment

begin_define
define|#
directive|define
name|BAW_WITHIN
parameter_list|(
name|_start
parameter_list|,
name|_bawsz
parameter_list|,
name|_seqno
parameter_list|)
define|\
value|((((_seqno) - (_start))& 4095)< (_bawsz))
end_define

begin_comment
comment|/*  * Maximum aggregate size  */
end_comment

begin_define
define|#
directive|define
name|ATH_AGGR_MAXSIZE
value|65530
end_define

begin_function_decl
specifier|extern
name|void
name|ath_freetx
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_node_flush
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_txq_drain
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
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_txfrag_cleanup
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|ath_bufhead
modifier|*
name|frags
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_txfrag_setup
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|ath_bufhead
modifier|*
name|frags
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_tx_start
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_raw_xmit
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
specifier|const
name|struct
name|ieee80211_bpf_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* software queue stuff */
end_comment

begin_function_decl
specifier|extern
name|void
name|ath_tx_swq
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|struct
name|ath_txq
modifier|*
name|txq
parameter_list|,
name|int
name|queue_to_head
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_tid_init
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_tid_hw_queue_aggr
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|,
name|struct
name|ath_tid
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_tid_hw_queue_norm
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|,
name|struct
name|ath_tid
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_txq_sched
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
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_normal_comp
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
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_aggr_comp
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
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_addto_baw
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|,
name|struct
name|ath_tid
modifier|*
name|tid
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ieee80211_tx_ampdu
modifier|*
name|ath_tx_get_tx_tid
parameter_list|(
name|struct
name|ath_node
modifier|*
name|an
parameter_list|,
name|int
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_tid_sched
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_tid
modifier|*
name|tid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TX addba handling */
end_comment

begin_function_decl
specifier|extern
name|int
name|ath_addba_request
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
name|dialogtoken
parameter_list|,
name|int
name|baparamset
parameter_list|,
name|int
name|batimeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_addba_response
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
name|dialogtoken
parameter_list|,
name|int
name|code
parameter_list|,
name|int
name|batimeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_addba_stop
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_bar_response
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
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_addba_response_timeout
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * AP mode power save handling (of stations)  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ath_tx_node_sleep
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_node_wakeup
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_tx_node_is_asleep
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_tx_node_reassoc
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_node
modifier|*
name|an
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Hardware queue stuff  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ath_tx_push_pending
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
end_function_decl

begin_comment
comment|/*  * Misc debugging stuff  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_DEBUG_ALQ
end_ifdef

begin_function_decl
specifier|extern
name|void
name|ath_tx_alq_post
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf_first
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATH_DEBUG_ALQ */
end_comment

begin_comment
comment|/*  * Setup path  */
end_comment

begin_define
define|#
directive|define
name|ath_txdma_setup
parameter_list|(
name|_sc
parameter_list|)
define|\
value|(_sc)->sc_tx.xmit_setup(_sc)
end_define

begin_define
define|#
directive|define
name|ath_txdma_teardown
parameter_list|(
name|_sc
parameter_list|)
define|\
value|(_sc)->sc_tx.xmit_teardown(_sc)
end_define

begin_define
define|#
directive|define
name|ath_txq_restart_dma
parameter_list|(
name|_sc
parameter_list|,
name|_txq
parameter_list|)
define|\
value|(_sc)->sc_tx.xmit_dma_restart((_sc), (_txq))
end_define

begin_define
define|#
directive|define
name|ath_tx_handoff
parameter_list|(
name|_sc
parameter_list|,
name|_txq
parameter_list|,
name|_bf
parameter_list|)
define|\
value|(_sc)->sc_tx.xmit_handoff((_sc), (_txq), (_bf))
end_define

begin_define
define|#
directive|define
name|ath_draintxq
parameter_list|(
name|_sc
parameter_list|,
name|_rtype
parameter_list|)
define|\
value|(_sc)->sc_tx.xmit_drain((_sc), (_rtype))
end_define

begin_function_decl
specifier|extern
name|void
name|ath_xmit_setup_legacy
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

